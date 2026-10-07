/*****************************************************************************************************
  * @copyright	(c) Shenzhen Saiyuan Microelectronics Co., Ltd
  * @file	main.c
  * @brief	0010903139 触控板主程序 (MCU: SC92F8461B SOP16)
  * @details 集成赛元 TK8 (K2 照明按键) 与 TK13 (K4 风速+延时按键)，对接 3029 电源板
  ***************************************************************************************************/ 

#include "SC_Init.h"
#include "SC_it.h"
#include "..\Drivers\SCDriver_list.h"
#include "HeadFiles\SysFunVarDefine.h"
#include "BSP.h"
#include "HostControl.h"

typedef enum {
    SYS_STATE_POWER_ON = 0,
    SYS_STATE_POWER_OFF
} SysState_t;

SysState_t g_sys_state = SYS_STATE_POWER_OFF;

unsigned long int exKeyValueFlag = 0;

static uint8_t s_wind_gear = 0;       // 风机档位: 0 - 关/停风, 1 - 1档, 2 - 2档, 3 - 3档
static unsigned long int s_last_key_flag = 0; // 边沿检测历史状态

// 3139 原理图物理按键与触控通道映射:
// K2 KEY: Pin 13 (P2.0), 对应触控通道 TK8
// K4 KEY: Pin 10 (P2.5), 对应触控通道 TK13
#define KEY_LIGHT_MASK          (1UL << 8)   // K2 照明键掩码 (TK8)
#define KEY_FAN_MASK            (1UL << 13)  // K4 风速+延时键掩码 (TK13)

// 长按 2 秒进入延时模式门限 (触控扫描周期约 12~15ms，约 140 次为 2 秒)
#define K4_LONG_PRESS_TICKS     140

static uint16_t s_k4_press_cnt = 0;
static bit      s_k4_long_triggered = 0;

/**
  * @brief 3139 触控按键业务处理逻辑
  */
void KEYCode(void)
{
    unsigned long int key_down = exKeyValueFlag & (~s_last_key_flag); // 上升沿 (按下瞬间)
    unsigned long int key_up   = (~exKeyValueFlag) & s_last_key_flag; // 下降沿 (松开瞬间)
    s_last_key_flag = exKeyValueFlag;

    // ================= 1. K2 照明按键处理 (Pin 13: P2.0 / TK8) =================
    // 独立控制照明开/关，不受风机和关机状态影响
    if (key_down & KEY_LIGHT_MASK)
    {
        OneWire_ResetStandbyTimer();
        g_k1_state = !g_k1_state;   // 翻转照明状态
        OneWire_UpdateState(s_wind_gear, g_k1_state);
    }

    // ================= 2. K4 风速 + 延时按键处理 (Pin 10: P2.5 / TK13) =================
    // (1) 持续按下检测：长按 2 秒进入 15 分钟延时模式
    if (exKeyValueFlag & KEY_FAN_MASK)
    {
        OneWire_ResetStandbyTimer();
        if (!s_k4_long_triggered)
        {
            s_k4_press_cnt++;
            if (s_k4_press_cnt >= K4_LONG_PRESS_TICKS)
            {
                s_k4_long_triggered = 1; // 标记长按已生效，防止松手误触发短按切档
                
                // 规格书要求：在任意风速运行状态下，长按风速键 2 秒进入延时 15 分钟
                if (s_wind_gear > 0 && (g_delay_mode == 0))
                {
                    g_delay_mode = 1; // 启动延时模式倒计时 (L2 指示灯开始 500ms 周期闪烁)
                    OneWire_UpdateState(s_wind_gear, g_k1_state);
                }
            }
        }
    }

    // (2) 松开按键检测：未达 2 秒释放则判定为有效短按，风速循环切换
    if (key_up & KEY_FAN_MASK)
    {
        if (!s_k4_long_triggered)
        {
            // 规格书核心要求：风速顺序：高(3) -> 中(2) -> 低(1) -> 关(0) -> 高(3)... (循环)
            switch (s_wind_gear)
            {
                case 0:
                    s_wind_gear = 3;  // 关机状态下短按 -> 3档高速
                    g_k2_state = 1;
                    break;
                case 3:
                    s_wind_gear = 2;  // 3档短按 -> 2档中速
                    break;
                case 2:
                    s_wind_gear = 1;  // 2档短按 -> 1档低速
                    break;
                case 1:
                    s_wind_gear = 0;  // 1档短按 -> 关机 (0档)
                    g_delay_mode = 0; // 关机自动退出延时模式
                    g_k2_state = 0;
                    g_sys_state = SYS_STATE_POWER_OFF;
                    break;
                default:
                    s_wind_gear = 3;
                    g_k2_state = 1;
                    break;
            }
            
            // 规格书明确要求：“在延时状态下，切换风速延时继续保持开启状态”
            // 若在 3档、2档、1档 之间切换，g_delay_mode 继续保持为 1，不重置倒计时！
            OneWire_UpdateState(s_wind_gear, g_k1_state);
        }
        
        // 松手复位长按计数器与触发标志
        s_k4_press_cnt = 0;
        s_k4_long_triggered = 0;
    }
}

/**
  * @brief 主函数
  */
void main(void)
{	
    // 1. MCU 基础硬件资源初始化 (Option, GPIO)
    SC_Init();
    
    // 2. BSP 板级外设初始化 (P0.0 DAT, P1.3 L2, P1.5 L4, Timer0 延时基准)
    BSP_GPIO_Init();
    BSP_Timer0_Init();
    
    // 3. 赛元触控驱动初始化 (使能 TK8 与 TK13)
    TouchKeyInit();

    // 4. 装载上电自检蜂鸣器帧 [01 00 00 01]，启动 Timer1 立即向 3029 电脑板发射 (通知电脑板响“滴”一声完成上电自检)
    OneWire_SendPowerOnSelfTest();
    OneWire_Timer1_Init();

    // 5. 上电自检指示：插头上电，蜂鸣器提示音滴一声，所有按键光 (白光 L2 和 L4) 亮约 1 秒后熄灭，提示进入关机状态
    P13 = 0; P15 = 0; // 全部点亮 (低电平有效)
    Delay_ms(1000);
    P13 = 1; P15 = 1; // 全部熄灭
    Delay_ms(300);    // 留出时间让触控库自动校准基线

    // 6. 启动 Timer2 独立 1000Hz 硬件等周期刷新引擎 (彻底解耦通信波形，杜绝任何频闪与抖动)
    LED_Timer2_Init();

    /***** 主循环：全速检测触控按键 *****/
    while(1)
    {
        // 1. 延时模式 15 分钟倒计时到期 或 待机 10 分钟无操作超时：自动关机
        if (g_delay_timeout_flag || g_standby_timeout_flag)
        {
            g_delay_timeout_flag = 0;
            g_standby_timeout_flag = 0;
            g_delay_mode = 0;
            g_sys_state = SYS_STATE_POWER_OFF;
            g_k2_state = 0;
            s_wind_gear = 0; // 风机档位归零
            OneWire_UpdateState(0, g_k1_state); // 发送关机帧 (保留照明状态，更新校验和)
        }

        // 2. 触摸按键实时检测处理
        if (SOCAPI_TouchKeyStatus & 0x80)
        {
            SOCAPI_TouchKeyStatus &= 0x7F; // 清除扫描完成标志位
            
            exKeyValueFlag = TouchKeyScan(); // 读取触控按键键值掩码
            KEYCode();                       // 执行按键业务逻辑
            
            TouchKeyRestart();               // 启动下一次触摸扫描转换
        }
    }
}