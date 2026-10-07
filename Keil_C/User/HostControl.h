/*****************************************************************************************************
 * @file    HostControl.h
 * @brief   0010903139 触控板对接 0010903029 电源板单线通信协议头文件 (SC92F8461B)
 * @details 4字节数据帧定义、时序参数、Timer1 发送状态机与 Timer2 LED 刷新引擎声明
 *****************************************************************************************************/
#ifndef _HOST_CONTROL_H_
#define _HOST_CONTROL_H_

#include "sc92f.h"
#include "BSP.h"

/*******************************************************************************
 * 1. 0010903139 油烟机通信协议特征码定义 (对接 3029 主控板，实测波形确认)
 * 帧结构: 4 字节 [Byte 0: 照明控制] [Byte 1: 照明联动扩展] [Byte 2: 档位/电源] [Byte 3: 累加和校验]
 *******************************************************************************/
#define KEY_PWM_LIGHT_OFF           0x00    // 照明关闭 Byte 0 特征码
#define KEY_PWM_3139_LIGHT_B0       0x08    // 3139 开照明 Byte 0 特征码 (实测 0x08)
#define KEY_PWM_3139_LIGHT_B1       0x28    // 3139 开照明 Byte 1 联动特征码 (实测 0x28)
#define KEY_PWM_LIGHT_B1_OFF        0x00    // 照明关闭 Byte 1 特征码 (实测 0x00)
#define KEY_PWM_BUZZER_BIT          0x01    // 3139 按键动作蜂鸣器触发位 (Byte 0 Bit 0 置 1，通知 3029 电脑板响一声)

#define KEY_PWM_FAN_OFF             0x00    // 关机 / 风机停转 (Byte 2)
#define KEY_PWM_FAN_STANDBY         0x00    // 待机与关机 Byte 2 均为 0x00
#define KEY_PWM_FAN_LOW             0x02    // 1档低速 (Byte 2, 实测 0x02)
#define KEY_PWM_FAN_MED             0x03    // 2档中速 (Byte 2, 实测 0x03)
#define KEY_PWM_FAN_HIGH            0x04    // 3档高速 (Byte 2, 实测 0x04)

// 兼容别名
#define KEY_PWM_3157_LIGHT_CODE     KEY_PWM_3139_LIGHT_B0
#define ONEWIRE_USER_CODE           0x00
#define CMD_POWER_ON                KEY_PWM_FAN_STANDBY
#define CMD_POWER_OFF               KEY_PWM_FAN_OFF

/*******************************************************************************
 * 2. 红外遥控器协议定义 (NEC 协议，备用)
 *******************************************************************************/
#define IR_USER_CODE            0x02
#define IR_CMD_POWER            0x04
#define IR_CMD_LIGHT            0x06
#define IR_CMD_WIND3            0x08
#define IR_CMD_WIND1            0x0A
#define IR_CMD_DELAY            0x0C
#define IR_CMD_WIND2            0x0E

/*******************************************************************************
 * 3. 函数声明与外部变量
 *******************************************************************************/
extern volatile bit g_p00_out;
#define g_p14_out g_p00_out     // 兼容别名

uint8_t OneWire_GetByte1(uint8_t fan_gear, uint8_t light_on);
void OneWire_UpdateState(uint8_t fan_gear, uint8_t light_on);
void OneWire_SendInitial(void);
void OneWire_SendPowerOnSelfTest(void);
void OneWire_ResetStandbyTimer(void);
void OneWire_Timer1_Init(void);
void OneWire_Timer1_ISR(void);

void LED_Timer2_Init(void);
void LED_Refresh_Scan(void);

// 延时关机时长配置 (15分钟 = 15 * 60 = 900秒)
#define DELAY_SHUTDOWN_SECONDS      900
#define DELAY_FRAME_PERIOD_MS       400
#define DELAY_TIMEOUT_FRAMES        ((uint16_t)(((uint32_t)DELAY_SHUTDOWN_SECONDS * 1000) / DELAY_FRAME_PERIOD_MS))

// 待机 10 分钟无操作自动关机
#define STANDBY_AUTO_OFF_SECONDS    600
#define STANDBY_AUTO_OFF_FRAMES     ((uint16_t)(((uint32_t)STANDBY_AUTO_OFF_SECONDS * 1000) / DELAY_FRAME_PERIOD_MS))

// 全局业务状态
extern volatile uint8_t g_k1_state; // 照明状态 (0: 关, 1: 开)
extern volatile uint8_t g_k2_state; // 开机状态 (0: 关, 1: 开)
extern volatile uint8_t g_k3_state;
extern volatile uint8_t g_k4_state;
extern volatile uint8_t g_delay_mode;          // 延时模式 (0: 正常, 1: 15分钟延时中)
extern volatile uint8_t g_delay_timeout_flag;  // 延时到期标志
extern volatile uint8_t g_standby_timeout_flag;// 待机超时标志
extern volatile uint8_t g_tx_frame[4];

#endif /* _HOST_CONTROL_H_ */