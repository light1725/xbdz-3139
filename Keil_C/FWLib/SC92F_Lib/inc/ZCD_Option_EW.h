//************************************************************
//  Copyright (c) 深圳市赛元微电子股份有限公司
//	文件名称	  : ZCD_Option_EW.h
//	作者		  :
//	模块功能	  : ZCD固件库函数头文件
//	局部函数列表:
//  最后更正日期: 2025/9/12
// 	版本		   : V1.0
//  说明       :该文件适用于SC92F531x系列芯片
//*************************************************************
#ifndef _ZCD_OPTION_EW_H_
#define	_ZCD_OPTION_EW_H_

typedef enum
{
    STATE_CALC_FREQ         = ( unsigned char ) 0x00, /*!< In frequency calculation process */
    STATE_CALC_FREQ_DONE    = ( unsigned char ) 0x01, /*!< Frequency calculation completed */
    STATE_FIRST_ZERO_CROSS  = ( unsigned char ) 0x03, /*!< In first zero-crossing detection */
		STATE_PHASE_LOCK        = ( unsigned char ) 0x07, /*!< In phase-locking process */
		STATE_ZCD_LOCK          = ( unsigned char ) 0x0F, /*!< ZCD in LOCK state */
		STATE_UNKNOWN                                     // Unknown state (for error handling)
} ZCD_STAFLAG_TypeDef;

typedef enum 
{
		Filter75Time_5us = 0x00,   // Filter time: 5μs
    Filter75Time_10us = 0x10,  // Filter time: 10μs
    Filter75Time_20us = 0x20,  // Filter time: 20μs
    Filter75Time_40us = 0x30,  // Filter time: 40μs 
} ZCD_Filter75Time_TypeDef;

typedef enum 
{
    FilterTime_0us = 0x00,    // No filtering (0μs delay)
    FilterTime_100us = 0x01,  // Filter time: 100μs
    FilterTime_200us = 0x02,  // Filter time: 200μs
    FilterTime_400us = 0x03,  // Filter time: 400μs
    FilterTime_800us = 0x04,  // Filter time: 800μs
    FilterTime_1600us = 0x05, // Filter time: 1.6ms
    FilterTime_3200us = 0x06, // Filter time: 3.2ms
    FilterTime_6400us = 0x07, // Filter time: 6.4ms	
} ZCD_FilterTime_TypeDef;

/**************************************************
*函数名称：void ZCD_DelayedTrigOption(unsigned char DelayedTime)
*函数功能：设置延迟触发时间系数，相对于校准后的波形上升沿的延后触发时间为：50μs * DelayedTime 
*入口参数：DelayedTime ：设置的时间系数（取值范围0x00~0xFF）
*出口参数：void
**************************************************/
void ZCD_DelayedTrigOption(unsigned char DelayedTime);

/**************************************************
*函数名称：ZCD_STAFLAG_TypeDef ZCD_GetSTAFlagStatus(void)
*函数功能：获取ZCD状态
*入口参数：void
*出口参数：ZCD_STAFLAG_TypeDef：ZCD的状态
*						- STATE_CALC_FREQ：处于计算频率过程
*						- STATE_CALC_FREQ_DONE：频率计算过程完成
*						- STATE_FIRST_ZERO_CROSS：处于第一过零点判断
*						- STATE_PHASE_LOCK：处于锁相过程
*						- STATE_ZCD_LOCK：ZCD处于LOCK状态
**************************************************/
ZCD_STAFLAG_TypeDef ZCD_GetSTAFlagStatus(void);

/**************************************************
*函数名称：FlagStatus ZCD_GetInputFreq(void) 
*函数功能：获取输入信号频率。可以识别两种输入信号频率
*入口参数：void
*出口参数：ZCD_InputFreq_TypeDef：ZCD输入信号的频率。返回值为0时即50Hz，为1时即60Hz
**************************************************/
FlagStatus ZCD_GetInputFreq(void);

/**************************************************
*函数名称：unsigned int ZCD_GetHardwareCycle(void) 
*函数功能：获取ZCD硬件周期，即输入信号的周期
*入口参数：void
*出口参数：unsigned int: 所获取ZCD硬件周期值（范围0x00~0x7FFF，周期值单位 μs）
**************************************************/
unsigned int ZCD_GetHardwareCycle(void);

/**************************************************
*函数名称：void ZCD_SetFilter75Time(ZCD_Filter75Time_TypeDef Filter75_Time) 
*函数功能：设置7-5滤波时间，滤波作用于ZCD内部运放的输出端
*入口参数：75_Time：设置的滤波时间
*						- Filter75Time_5us：滤波5μs
*						- Filter75Time_10us：滤波10μs
*						- Filter75Time_20us：滤波20μs
*						- Filter75Time_40us：滤波40μs
*出口参数：void
**************************************************/
void ZCD_SetFilter75Time(ZCD_Filter75Time_TypeDef Filter75_Time);

/**************************************************
*函数名称：void ZCD_SetFilterTime(ZCD_FilterTime_TypeDef Time) 
*函数功能：设置滤波时间，滤波作用于ZCD内部运放的输出端
*入口参数：Time：设置的滤波时间
*						- FilterTime_0us：滤波0μs
*						- FilterTime_100us：滤波100μs
*						- FilterTime_200us：滤波200μs
*						- FilterTime_400us：滤波400μs
*						- FilterTime_800us：滤波800μs
*						- FilterTime_1600us：滤波1600μs
*						- FilterTime_3200us：滤波3200μs
*						- FilterTime_6400us：滤波6400μs
*出口参数：void
**************************************************/
void ZCD_SetFilterTime(ZCD_FilterTime_TypeDef Time);

/**************************************************
*函数名称：void ZCD_CLAMP_Cmd(FunctionalState NewState)  
*函数功能：钳位功能使能
*入口参数：NewState：使能设置
*出口参数：void
**************************************************/
void ZCD_CLAMP_Cmd(FunctionalState NewState);

#endif
