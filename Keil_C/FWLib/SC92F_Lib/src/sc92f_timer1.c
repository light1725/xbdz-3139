/**
 ******************************************************************************
 * @file    sc92f_timer1.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   TIM1 function module
 *******************************************************************************
 * @attention
 *
 *1.This software is supplied by SinOne Microelectronics Co.,Ltd. and is only 
 *intended for use with SinOne products. No other uses are authorized. This 
 *software is owned by SinOne Microelectronics Co.,Ltd. and is protected under 
 *all applicable laws, including copyright laws. 
 *2.The software which is for guidance only aims at providing customers with 
 *coding information regarding their products in order for them to save time. 
 *As a result, SinOne shall not be held liable for any direct, indirect or 
 *consequential damages with respect to any claims arising from the content of 
 *such software and/or the use made by customers of the coding information 
 *contained herein in connection with their products.
 *
 *  COPYRIGHT 2026 SinOne Microelectronics
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "sc92f_timer1.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup TIM1
 * @brief TIM1 driver modules
 * @{
 */

/** @defgroup TIM1_Functions
 * @{
 */
 
/** @defgroup TIM1_Group1 Configuration of the TIM1 computation unit functions
 *  @brief   Configuration of the TIM1 computation unit functions
 *
 
@verbatim
 ===============================================================================
                     ##### TIM1 configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  TIMER1相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void TIM1_DeInit(void)
{
  TMOD &= 0X0F;
  TCON &= 0X37;
  TMCON &= 0XFD;
  TH1 = 0X00;
  TL1 = 0X00;
  ET1 = 0;
  IPT1 = 0;
}

/**
 * @brief  TIMER0基本设置配置函数
 * @param  TIM1_PrescalerSelection[in]:预分频选择
 *          - TIM1_PRESSEL_FSYS_D12:TIMER1计数源来自系统时钟12分频
 *          - TIM1_PRESSEL_FSYS_D1:TIMER1计数源来自系统时钟
 * @param  TIM1_CountMode[in]:计数/定时模式选择
 *          - TIM1_MODE_TIMER:TIMER1做定时器
 *          - TIM1_MODE_COUNTER:TIMER1做计数器
 * @retval None
 */
void TIM1_TimeBaseInit(TIM1_PresSel_TypeDef TIM1_PrescalerSelection,
                       TIM1_CountMode_TypeDef TIM1_CountMode)
{
	//判断是否需要进行分频
  if(TIM1_PrescalerSelection == TIM1_PRESSEL_FSYS_D12)
  {
    TMCON &= 0xFD;
  }
  else if(TIM1_PrescalerSelection == TIM1_PRESSEL_FSYS_D1)
  {
    TMCON |= 0x02;
  }

	//TIM1工作模式
  if(TIM1_CountMode == TIM1_MODE_TIMER)
  {
    TMOD &= 0xBF;
  }
  else if(TIM1_CountMode == TIM1_MODE_COUNTER)
  {
    TMOD |= 0x40;
  }
}

/**
 * @brief  TIMER1工作模式0配置函数
 * @param  TIM1_SetCounter[in]:配置计数初值
 * @retval None
 */ 
void TIM1_WorkMode0Config(uint16_t
                          TIM1_SetCounter)
{
  TMOD &= 0XCF;
  TL1 = (uint8_t)TIM1_SetCounter;
  TH1 = (TIM1_SetCounter >> 5);
}

/**
 * @brief  TIMER1工作模式1配置函数
 * @param  TIM1_SetCounter[in]:配置计数初值
 * @retval None
 */ 
void TIM1_WorkMode1Config(uint16_t
                          TIM1_SetCounter)
{
  TMOD &= 0XCF;
  TMOD |= 0X10;
  TL1 = TIM1_SetCounter % 256;
  TH1 = TIM1_SetCounter / 256;
}

/**
 * @brief  TIMER1工作模式2配置函数
 * @param  TIM1_SetCounter[in]:配置计数初值
 * @retval None
 */ 
void TIM1_WorkMode2Config(uint8_t TIM1_SetCounter)
{
  TMOD &= 0XCF;
  TMOD |= 0X20;
  TL1 = TIM1_SetCounter;
  TH1 = TIM1_SetCounter;
}

/**
 * @brief  TIMER1工作模式配置函数
 * @param  TIM1_WorkMode[in]:TIMER1工作模式选择
 *          - TIM1_WORK_MODE0:TIMER1选择工作模式0
 *          - TIM1_WORK_MODE1:TIMER1选择工作模式1
 *          - TIM1_WORK_MODE2:TIMER1选择工作模式2
 * @param  TIM1_SetCounter1[in]:TIMER1计数初值配置1
 * @param  TIM1_SetCounter2[in]:TIMER1计数初值配置2
 * @retval None
 */ 
void TIM1_WorkModeConfig(TIM1_WorkMode_TypeDef
                         TIM1_WorkMode, uint16_t TIM1_SetCounter)
{
  switch(TIM1_WorkMode)
  {
    case TIM1_WORK_MODE0:
      TIM1_WorkMode0Config(TIM1_SetCounter);
      break;

    case TIM1_WORK_MODE1:
      TIM1_WorkMode1Config(TIM1_SetCounter);
      break;

    case TIM1_WORK_MODE2:
      TIM1_WorkMode2Config(TIM1_SetCounter);
      break;

    default:
      break;
  }
}
/**
 * @}
 */
/* End of TIM1_Group1.	*/

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */


/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/