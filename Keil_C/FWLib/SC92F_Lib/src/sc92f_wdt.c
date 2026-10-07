/**
 ******************************************************************************
 * @file    sc92f_wdt.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   WDT function module
 ******************************************************************************
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
#include "sc92f_wdt.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup wdt
 * @brief wdt driver modules
 * @{
 */

/** @defgroup wdt_Exported_Functions
 * @{
 */
 
 /** @defgroup wdt_Exported_Functions_Group1 Configuration of the wdt computation unit functions
 *  @brief   Configuration of the wdt computation unit functions
 *
 
@verbatim
 ===============================================================================
                     ##### wdt base functions #####
 ===============================================================================
@endverbatim
  * @{
  */
 /**
 * @brief  The WDT-related register is reset to the default value
 * @param  None         
 * @retval None
 */
void WDT_DeInit(void)
{
  WDTCON = 0X00;
}

/**************************************************
*函数名称:void WDT_Init(WDT_OverflowTime_TypeDef OverflowTime)
*函数功能:WDT初始化配置函数
*入口参数:
WDT_OverflowTime_TypeDef:OverflowTime:WDT溢出时间选择
*出口参数:void
**************************************************/
 /**
 * @brief  WDT initialization configuration function
 * @param   OverflowTime:WDT overflow time selection
 *          - WDT_OverflowTime_500MS: Settings  500MS
 *          - WDT_OverflowTime_250MS: Settings 250MS
 *          - WDT_OverflowTime_125MS: Settings 125MS
 *          - WDT_OverflowTime_62_5MS:Settings 62.5MS
 *          - WDT_OverflowTime_31_5MS:Settings 31.5MS
 *          - WDT_OverflowTime_15_75MS:Settings 15.75MS
 *          - WDT_OverflowTime_7_88MS:Settings 7.88MS
 *          - WDT_OverflowTime_3_94MS:Settings 3.94MS
 * @retval None
 */
void WDT_Init(WDT_OverflowTime_TypeDef
              OverflowTime)
{
  WDTCON = (WDTCON & 0XF8) | OverflowTime;
}


/**
 * @brief  WDT function switch function
 * @param  NewState[in]:Function Enable/disable selection   
 *              - DISABLE: disable    
 *              - ENABLE:Enable    
 * @retval None
 */
void WDT_Cmd(FunctionalState NewState)
{
  OPINX = 0XC1;

  if(NewState == DISABLE)
  {
    OPREG &= 0X7F;
  }
  else
  {
    OPREG |= 0X80;
  }
}
/**
 * @}
 */
/* End of wdt_Group1.	*/
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