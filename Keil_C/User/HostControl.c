/*****************************************************************************************************
 * @file    HostControl.c
 * @brief   0010903139 - 0010903029 (MCU: SC92F8461B)
 * @details DAT = P0.0, L2 = P1.3, L4 = P1.5, Fsys = 12MHz
 *****************************************************************************************************/
#include <intrins.h>
#include "HostControl.h"
#include "BSP.h"

/* Simulation variable */
volatile bit g_p00_out = 1;

#define SET_DAT_HIGH()      do { P00 = 1; g_p00_out = 1; } while(0)
#define SET_DAT_LOW()       do { P00 = 0; g_p00_out = 0; } while(0)
#define SET_P14_HIGH()      SET_DAT_HIGH()
#define SET_P14_LOW()       SET_DAT_LOW()

/* Global states */
volatile uint8_t g_k1_state = 0; /* Light state (0: off, 1: on) */
volatile uint8_t g_k2_state = 0; /* Power state (0: off, 1: on) */
volatile uint8_t g_k3_state = 0;
volatile uint8_t g_k4_state = 0;
volatile uint8_t g_delay_mode = 0;
volatile uint8_t g_delay_timeout_flag = 0;
volatile uint8_t g_standby_timeout_flag = 0;

static volatile uint16_t s_delay_frame_counter = 0;
static volatile uint16_t s_standby_frame_counter = 0;
static volatile uint8_t  s_current_fan_gear = 0;

/* Frame buffers */
volatile uint8_t g_tx_frame[4] = {0x00, 0x00, 0x00, 0x00};
static volatile uint8_t s_next_frame[4] = {0x00, 0x00, 0x00, 0x00};

/* ================== Timer1 OneWire TX Engine Definitions ================== */
/* Timing ticks (Fsys = 12MHz, 1us = 12 ticks) */
#define TICKS_LEADER_LOW_HALF   54600  /* 4.55ms -> 54600 (总前导低电平 9.1ms，两段) */
#define TICKS_LEADER_HIGH       53760  /* 4.48ms -> 53760 */
#define TICKS_BIT_LOW           9600   /* 0.8ms  -> 9600 */
#define TICKS_BIT_0_HIGH        8400   /* 0.7ms  -> 8400 */
#define TICKS_BIT_1_HIGH        44400  /* 3.7ms  -> 44400 */
#define TICKS_STOP_LOW          9600   /* 0.8ms  -> 9600 */
#define TICKS_GAP_CHUNK         60000  /* 5ms    -> 60000 */
#define GAP_CHUNKS_COUNT        68     /* 68 * 5ms = 340ms 稳态空闲等待 */

#define RELOAD_TIMER1(cnt) do { \
    TL1 = (uint8_t)(65536 - (cnt)); \
    TH1 = (uint8_t)((65536 - (cnt)) >> 8); \
} while(0)

typedef enum {
    TX_STATE_IDLE = 0,
    TX_STATE_LEADER_LOW_1,
    TX_STATE_LEADER_LOW_2,
    TX_STATE_LEADER_HIGH,
    TX_STATE_BIT_LOW,
    TX_STATE_BIT_HIGH,
    TX_STATE_STOP_LOW,
    TX_STATE_GAP_HIGH
} TxState_t;

static volatile TxState_t s_tx_state = TX_STATE_GAP_HIGH;
static volatile uint8_t s_byte_idx = 0;
static volatile uint8_t s_bit_idx = 0;
static volatile uint8_t s_gap_cnt = 0;
static volatile bit     s_need_early_send = 0;
static volatile uint8_t s_burst_count     = 0;

void OneWire_ResetStandbyTimer(void)
{
    s_standby_frame_counter = 0;
    g_standby_timeout_flag = 0;
}

uint8_t OneWire_GetByte1(uint8_t fan_gear, uint8_t light_on)
{
    if (fan_gear || light_on)
    {
        if (light_on) return KEY_PWM_3139_LIGHT_B1;
    }
    return KEY_PWM_LIGHT_B1_OFF;
}

void OneWire_SetCurrentFrame(uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3)
{
    bit et1_bak = ET1;
    ET1 = 0; /* 临时关闭 Timer1 中断，原子写入发送缓冲区 */
    s_next_frame[0] = b0;
    s_next_frame[1] = b1;
    s_next_frame[2] = b2;
    s_next_frame[3] = b3;
    s_need_early_send = 1;
    s_burst_count = 1; /* 第1帧发蜂鸣器码，第2帧隔20ms紧随发稳态清洁码，彻底消除延迟 */

    /* 关键机制：用户按下按键时，若当前总线正处于空闲高电平等待期且已满足最小 20ms 保护间隔
     * 立即截断 340ms 心跳等待，装载新帧瞬间启动新帧引导码低电平发射！ */
    if (s_tx_state == TX_STATE_GAP_HIGH)
    {
        if (s_gap_cnt >= 4) /* 空闲已保持 >= 20ms (4 * 5ms) */
        {
            g_tx_frame[0] = s_next_frame[0];
            g_tx_frame[1] = s_next_frame[1];
            g_tx_frame[2] = s_next_frame[2];
            g_tx_frame[3] = s_next_frame[3];
            s_need_early_send = 0;
            s_gap_cnt = 0;

            /* 硬件安全保护：先停止 Timer1 并清除待处理中断标志，装入初值后再启动，确保引导码低电平首段绝对足额 4.55ms */
            TR1 = 0;
            TF1 = 0;
            TL1 = (uint8_t)(65536 - TICKS_LEADER_LOW_HALF);
            TH1 = (uint8_t)((65536 - TICKS_LEADER_LOW_HALF) >> 8);
            TR1 = 1;
            SET_DAT_LOW();
            s_tx_state = TX_STATE_LEADER_LOW_2;
        }
    }
    ET1 = et1_bak;
}

void OneWire_UpdateState(uint8_t fan_gear, uint8_t light_on)
{
    uint8_t b0, b1, b2, b3;

    s_current_fan_gear = fan_gear;
    g_k1_state = (light_on != 0);

    /* 1. Byte 0 & Byte 1: 3139 照明控制码与扩展码 (按键动作时叠加蜂鸣器位 0x01) */
    if (light_on)
    {
        b0 = KEY_PWM_3139_LIGHT_B0 | KEY_PWM_BUZZER_BIT; /* 0x08 | 0x01 = 0x09 */
        b1 = KEY_PWM_3139_LIGHT_B1;                       /* 0x28 */
    }
    else
    {
        b0 = KEY_PWM_LIGHT_OFF | KEY_PWM_BUZZER_BIT;     /* 0x00 | 0x01 = 0x01 */
        b1 = KEY_PWM_LIGHT_B1_OFF;                       /* 0x00 */
    }

    /* 2. Byte 2: 档位/电源码 (关机: 0x00, 1档: 0x02, 2档: 0x03, 3档: 0x04) */
    switch (fan_gear)
    {
        case 1:
            b2 = KEY_PWM_FAN_LOW;   /* 0x02 */
            g_k2_state = 1;
            break;
        case 2:
            b2 = KEY_PWM_FAN_MED;   /* 0x03 */
            g_k2_state = 1;
            break;
        case 3:
            b2 = KEY_PWM_FAN_HIGH;  /* 0x04 */
            g_k2_state = 1;
            break;
        default:
            b2 = KEY_PWM_FAN_OFF;   /* 0x00 */
            g_k2_state = 0;
            break;
    }

    /* 3. Checksum: Byte 3 = (Byte 0 + Byte 1 + Byte 2) & 0xFF */
    b3 = (uint8_t)(b0 + b1 + b2);

    OneWire_SetCurrentFrame(b0, b1, b2, b3);
}

void OneWire_SendPowerOnSelfTest(void)
{
    s_current_fan_gear = 0;
    s_standby_frame_counter = 0;

    /* 3139 上电自检帧: 关机状态下携带蜂鸣器触发位 0x01，通知 3029 电脑板响“滴”一声完成上电自检 */
    s_next_frame[0] = KEY_PWM_LIGHT_OFF | KEY_PWM_BUZZER_BIT; /* 0x01 */
    s_next_frame[1] = 0x00;
    s_next_frame[2] = 0x00;
    s_next_frame[3] = (uint8_t)(s_next_frame[0] + s_next_frame[1] + s_next_frame[2]); /* 0x01 */

    g_tx_frame[0] = s_next_frame[0];
    g_tx_frame[1] = s_next_frame[1];
    g_tx_frame[2] = s_next_frame[2];
    g_tx_frame[3] = s_next_frame[3];

    s_need_early_send = 0;
    s_burst_count = 1; /* 第1帧发蜂鸣器自检码，第2帧隔20ms紧随发清洁关机稳态码 [00 00 00 00] */
}

void OneWire_SendInitial(void)
{
    OneWire_SendPowerOnSelfTest();
}

/* ================== Timer2 LED Refresh (1000Hz) ================== */
void LED_Timer2_Init(void)
{
    T2MOD |= 0x80; /* Timer2 1T mode: clock = Fsys = 12MHz */
    T2CON = 0x00;  /* 16-bit auto-reload */

    /* 1ms reload: 65536 - 12000 = 53536 = 0xD120 */
    RCAP2L = 0x20;
    RCAP2H = 0xD1;
    TL2 = 0x20;
    TH2 = 0xD1;

    TF2 = 0;
    IPT2 = 1; /* High priority */
    ET2 = 1;  /* Enable Timer2 interrupt */
    TR2 = 1;  /* Start Timer2 */
    EA = 1;
}

void LED_Refresh_Scan(void)
{
    static uint16_t s_blink_cnt = 0;
    static uint8_t  s_blink_flag = 0;

    /* 500ms toggle clock */
    s_blink_cnt++;
    if (s_blink_cnt >= 500)
    {
        s_blink_cnt = 0;
        s_blink_flag = !s_blink_flag;
    }

    /* 1. L2 Light LED (Pin 7: P1.3 / KEY2_LED, active low) -> K2 照明按键 */
    if (g_k1_state)
    {
        P13_l; /* 照明开启: L2 点亮 */
    }
    else
    {
        P13_h; /* 照明关闭: L2 熄灭 */
    }

    /* 2. L4 Fan/Delay LED (Pin 8: P1.5 / KEY4_LED, active low) -> K4 风速+延时按键 */
    if (g_delay_mode)
    {
        /* 延时模式: 500ms 周期闪烁 */
        if (s_blink_flag)
        {
            P15_l;
        }
        else
        {
            P15_h;
        }
    }
    else if (s_current_fan_gear > 0)
    {
        P15_l; /* 风机运行: L4 常亮 */
    }
    else
    {
        P15_h; /* 风机停止: L4 熄灭 */
    }
}

/* ================== Timer1 OneWire TX Engine ================== */
void OneWire_Timer1_Init(void)
{
    TMOD &= 0x0F;
    TMOD |= 0x10;  /* Timer1 Mode 1: 16-bit */
    TMCON |= 0x02; /* Timer1 1T mode */

    s_byte_idx = 0;
    s_bit_idx = 0;
    s_gap_cnt = 0;

    /* 上电瞬间立即拉低 DAT 发射第1帧上电自检蜂鸣器帧 [01 00 00 01] */
    SET_DAT_LOW();
    RELOAD_TIMER1(TICKS_LEADER_LOW_HALF);
    s_tx_state = TX_STATE_LEADER_LOW_2;

    TF1 = 0;
    ET1 = 1;
    TR1 = 1;
    IPT1 = 1; /* High priority */
    EA = 1;
}

void OneWire_Timer1_ISR(void)
{
    TF1 = 0;

    switch (s_tx_state)
    {
        case TX_STATE_LEADER_LOW_1:
            SET_DAT_LOW();
            RELOAD_TIMER1(TICKS_LEADER_LOW_HALF);
            s_tx_state = TX_STATE_LEADER_LOW_2;
            break;

        case TX_STATE_LEADER_LOW_2:
            SET_DAT_LOW();
            RELOAD_TIMER1(TICKS_LEADER_LOW_HALF);
            s_tx_state = TX_STATE_LEADER_HIGH;
            break;

        case TX_STATE_LEADER_HIGH:
            SET_DAT_HIGH();
            RELOAD_TIMER1(TICKS_LEADER_HIGH);
            s_byte_idx = 0;
            s_bit_idx = 0;
            s_tx_state = TX_STATE_BIT_LOW;
            break;

        case TX_STATE_BIT_LOW:
            SET_DAT_LOW();
            RELOAD_TIMER1(TICKS_BIT_LOW);
            s_tx_state = TX_STATE_BIT_HIGH;
            break;

        case TX_STATE_BIT_HIGH:
            SET_DAT_HIGH();
            if (g_tx_frame[s_byte_idx] & (0x80 >> s_bit_idx))
            {
                RELOAD_TIMER1(TICKS_BIT_1_HIGH); /* Bit 1: 3.7ms */
            }
            else
            {
                RELOAD_TIMER1(TICKS_BIT_0_HIGH); /* Bit 0: 0.7ms */
            }

            s_bit_idx++;
            if (s_bit_idx >= 8)
            {
                s_bit_idx = 0;
                s_byte_idx++;
                if (s_byte_idx >= 4)
                {
                    s_tx_state = TX_STATE_STOP_LOW;
                    break;
                }
            }
            s_tx_state = TX_STATE_BIT_LOW;
            break;

        case TX_STATE_STOP_LOW:
            SET_DAT_LOW();
            RELOAD_TIMER1(TICKS_STOP_LOW);
            s_tx_state = TX_STATE_GAP_HIGH;
            break;

        case TX_STATE_GAP_HIGH:
            SET_DAT_HIGH();
            RELOAD_TIMER1(TICKS_GAP_CHUNK);
            s_gap_cnt++;

#if (KEY_PWM_BUZZER_BIT != 0)
            /* 若刚才发送的是按键蜂鸣器触发帧 (Bit 0 为 1)，首帧发出后在进入空闲隙时自动清除 Bit 0，
             * 恢复干净稳态码，避免电脑板连续蜂鸣或后续心跳误鸣 */
            if (s_need_early_send == 0)
            {
                if (s_next_frame[0] & KEY_PWM_BUZZER_BIT)
                {
                    s_next_frame[0] &= ~KEY_PWM_BUZZER_BIT;
                    s_next_frame[3] = (uint8_t)(s_next_frame[0] + s_next_frame[1] + s_next_frame[2]);
                    g_tx_frame[0] = s_next_frame[0];
                    g_tx_frame[3] = s_next_frame[3];
                }
            }
#endif

            /* Burst send on keypress */
            if ((s_need_early_send && (s_gap_cnt >= 4)) || 
                ((s_burst_count > 0) && (s_gap_cnt >= 4)))
            {
                if (s_burst_count > 0 && !s_need_early_send)
                {
                    s_burst_count--;
                }
                s_need_early_send = 0;
                s_gap_cnt = 0;

                g_tx_frame[0] = s_next_frame[0];
                g_tx_frame[1] = s_next_frame[1];
                g_tx_frame[2] = s_next_frame[2];
                g_tx_frame[3] = s_next_frame[3];

                SET_DAT_LOW();
                RELOAD_TIMER1(TICKS_LEADER_LOW_HALF);
                s_tx_state = TX_STATE_LEADER_LOW_2;
                break;
            }

            /* Regular heartbeat (402ms frame period) */
            if (s_gap_cnt >= GAP_CHUNKS_COUNT)
            {
                s_gap_cnt = 0;
                s_need_early_send = 0;
                s_burst_count = 0;

                /* 15 min delay countdown */
                if (g_delay_mode)
                {
                    s_delay_frame_counter++;
                    if (s_delay_frame_counter >= DELAY_TIMEOUT_FRAMES)
                    {
                        s_delay_frame_counter = 0;
                        g_delay_timeout_flag = 1;
                    }
                }
                else
                {
                    s_delay_frame_counter = 0;
                }

                /* 10 min standby auto-off */
                if (g_k2_state && (s_current_fan_gear == 0))
                {
                    s_standby_frame_counter++;
                    if (s_standby_frame_counter >= STANDBY_AUTO_OFF_FRAMES)
                    {
                        s_standby_frame_counter = 0;
                        g_standby_timeout_flag = 1;
                    }
                }
                else
                {
                    s_standby_frame_counter = 0;
                }

                /* Sync latest frame */
                g_tx_frame[0] = s_next_frame[0];
                g_tx_frame[1] = s_next_frame[1];
                g_tx_frame[2] = s_next_frame[2];
                g_tx_frame[3] = s_next_frame[3];

                SET_DAT_LOW();
                RELOAD_TIMER1(TICKS_LEADER_LOW_HALF);
                s_tx_state = TX_STATE_LEADER_LOW_2;
            }
            break;

        default:
            SET_DAT_HIGH();
            s_tx_state = TX_STATE_GAP_HIGH;
            s_gap_cnt = 0;
            RELOAD_TIMER1(TICKS_GAP_CHUNK);
            break;
    }
}