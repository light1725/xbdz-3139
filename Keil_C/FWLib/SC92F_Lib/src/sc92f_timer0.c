/**
 ******************************************************************************
 * @file    sc92f_tiemr0.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   TIM0 function module
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
#include "sc92f_timer0.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup TIM
 * @brief TIM driver modules
 * @{
 */

/** @defgroup TIM_Functions
 * @{
 */
 
/** @defgroup TIM_Group1 Configuration of the TIM computation unit functions
 *  @brief   Configuration of the TIM computation unit functions
 *
 
@verbatim
 ===============================================================================
                     ##### TIM configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */
  
/**
 * @brief  TIMER0相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void TIM0_DeInit(void)
{
  TMOD &= 0XF0;
  TCON &= 0XCD;
  TMCON &= 0XFE;
  TH0 = 0X00;
  TL0 = 0X00;
  ET0 = 0;
  IPT0 = 0;
}

/**
 * @brief  TIMER0基本设置配置函数
 * @param  TIM0_PrescalerSelection[in]:预分频选择
 *          - TIM0_PRESSEL_FSYS_D12:TIMER0计数源来自系统时钟12分频
 *          - TIM0_PRESSEL_FSYS_D1:TIMER0计数源来自系统时钟
 * @param  TIM0_CountMode[in]:计数/定时模式选择
 *          - TIM0_MODE_TIMER:TIMER0做定时器
 *          - TIM0_MODE_COUNTER:TIMER0做计数器
 * @retval None
 */ 
void TIM0_TimeBaseInit(TIM0_PresSel_TypeDef
                       TIM0_PrescalerSelection,
                       TIM0_CountMode_TypeDef TIM0_CountMode)
{
  if(TIM0_PrescalerSelection ==
      TIM0_PRESSEL_FSYS_D12)
  {
    TMCON &= 0XFE;
  }
  else if(TIM0_PrescalerSelection ==
			TIM0_PRESSEL_FSYS_D1)
	{
		TMCON |= 0X01;
	}

  if(TIM0_CountMode == TIM0_MODE_TIMER)
  {
    TMOD &= 0xFB;
  }
  else if(TIM0_CountMode == TIM0_MODE_COUNTER)
	{
		TMOD |= 0x04;
	}
}

/**
 * @brief  TIMER0工作模式0配置函数
 * @param  TIM0_SetCounter[in]:配置计数初值
 * @retval None
 */ 
void TIM0_WorkMode0Config(uint16_t
                          TIM0_SetCounter)
{
  TMOD &= 0XFC;
  TL0 = (uint8_t)TIM0_SetCounter;
  TH0 = (TIM0_SetCounter >> 5);
}

/**
 * @brief  TIMER0工作模式1配置函数
 * @param  TIM0_SetCounter[in]:配置计数初值
 * @retval None
 */ 
void TIM0_WorkMode1Config(uint16_t
                          TIM0_SetCounter)
{
  TMOD &= 0XFC;
  TMOD |= 0X01;
  TL0 = TIM0_SetCounter % 256;
  TH0 = TIM0_SetCounter / 256;
}

/**
 * @brief  TIMER0工作模式2配置函数
 * @param  TIM0_SetCounter[in]:配置计数初值
 * @retval None
 */ 
void TIM0_WorkMode2Config(uint8_t TIM0_SetCounter)
{
  TMOD &= 0XFC;
  TMOD |= 0X02;
  TL0 = TIM0_SetCounter;
  TH0 = TIM0_SetCounter;
}

/**
 * @brief  TIMER0工作模式配置函数
 * @param  TIM0_WorkMode[in]:TIMER0工作模式选择
 *          - TIM0_WORK_MODE0:TIMER0选择工作模式0
 *          - TIM0_WORK_MODE1:TIMER0选择工作模式1
 *          - TIM0_WORK_MODE2:TIMER0选择工作模式2
 *          - TIM0_WORK_MODE3:TIMER0选择工作模式3
 * @param  TIM0_SetCounter1[in]:TIMER0计数初值配置1
 * @param  TIM0_SetCounter2[in]:TIMER0计数初值配置2
 * @retval None
 */ 
void TIM0_WorkModeConfig(TIM0_WorkMode_TypeDef
                         TIM0_WorkMode, uint16_t TIM0_SetCounter1,
                         uint16_t TIM0_SetCounter2)
{
  switch (TIM0_WorkMode)
  {
    case TIM0_WORK_MODE0:
      TIM0_WorkMode0Config(TIM0_SetCounter1);
      break;

    case TIM0_WORK_MODE1:
      TIM0_WorkMode1Config(TIM0_SetCounter1);
      break;

    case TIM0_WORK_MODE2:
      TIM0_WorkMode2Config(TIM0_SetCounter1);
      break;

    case TIM0_WORK_MODE3:
      TIM0_WorkMode3Config(TIM0_SetCounter1,
                           TIM0_SetCounter2);
      break;
    default:
      break;
  }
}

/**
 * @brief  TIMER0工作模式3配置函数
 * @param  TIM0_SetCounter[in]:配置TIMER0_TL0计数初值
 * @param  TIM1_SetCounter[in]:配置TIMER0_TH0计数初值
 * @retval None
 */
void TIM0_WorkMode3Config(uint8_t TIM0_SetCounter,
                          uint8_t TIM1_SetCounter)
{
  TMOD |= 0X03;
  TL0 = TIM0_SetCounter;
  TH0 = TIM1_SetCounter;
}
/**
 * @}
 */
/* End of TIM_Group1.	*/

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