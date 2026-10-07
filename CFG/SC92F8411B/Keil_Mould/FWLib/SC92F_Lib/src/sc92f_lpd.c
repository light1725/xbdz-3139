/**
 ******************************************************************************
 * @file    sc92F_LPD.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   LPD function module
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
#include "sc92f_lpd.h"

#if defined (SC92L853x) || defined (SC92L753x) || defined (SC92L840x) || defined (SC92F663x) || defined (SC92F563x)
/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
/** @defgroup LPD
 * @brief LPD driver modules
 * @{
 */

/** @defgroup LPD_Functions
 * @{
 */
 
/** @defgroup LPD_Group1 Initialization and Configuration functions
 *  @brief Initialization and Configuration functions
 *
 
@verbatim
 ===============================================================================
                     ##### Initialization and Configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */
  
/**
 * @brief  LPD相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void LPD_DeInit(void)
{
	/* 配置相关寄存器复位 */
	LPDCFG = 0x00;
	/* 中断相关寄存器复位 */
	IE2 &= 0x7F;
	IP2 &= 0x7F;
}

/**
 * @brief  设置LPD门限电压阈值
 * @param  LPD_Vtrip[in]: LPD门限电压阈值
 *            SC92L853x,SC92L753x,SC92L840x,
 *              - LPD_VTRIP_1_85V:LPD门限电压阈值为1.85V
 *              - LPD_VTRIP_2_05V:LPD门限电压阈值为2.05V
 *              - LPD_VTRIP_2_25V:LPD门限电压阈值为2.25V
 *              - LPD_VTRIP_2_45V:LPD门限电压阈值为2.45V
 *              - LPD_VTRIP_2_65V:LPD门限电压阈值为2.65V
 *              - LPD_VTRIP_2_85V:LPD门限电压阈值为2.85V
 *              - LPD_VTRIP_3_05V:LPD门限电压阈值为3.05V
 *              - LPD_VTRIP_3_45V:LPD门限电压阈值为3.45V
 *              - LPD_VTRIP_3_85V:LPD门限电压阈值为3.85V
 *              - LPD_VTRIP_4_45V:LPD门限电压阈值为4.45V
 *            SC92F663x,SC92F563x,
 *              - LPD_VTRIP_2_40V:LPD门限电压阈值为2.40V
 *              - LPD_VTRIP_2_55V:LPD门限电压阈值为2.55V
 *              - LPD_VTRIP_2_70V:LPD门限电压阈值为2.70V
 *              - LPD_VTRIP_2_85V:LPD门限电压阈值为2.85V
 *              - LPD_VTRIP_3_00V:LPD门限电压阈值为3.00V
 *              - LPD_VTRIP_3_15V:LPD门限电压阈值为3.15V
 *              - LPD_VTRIP_3_30V:LPD门限电压阈值为3.30V
 *              - LPD_VTRIP_3_45V:LPD门限电压阈值为3.45V
 *              - LPD_VTRIP_3_60V:LPD门限电压阈值为3.60V
 *              - LPD_VTRIP_3_75V:LPD门限电压阈值为3.75V
 *              - LPD_VTRIP_3_90V:LPD门限电压阈值为3.90V
 *              - LPD_VTRIP_4_05V:LPD门限电压阈值为4.05V
 *              - LPD_VTRIP_4_20V:LPD门限电压阈值为4.20V
 *              - LPD_VTRIP_4_35V:LPD门限电压阈值为4.35V
 *              - LPD_VTRIP_4_50V:LPD门限电压阈值为4.50V
 *              - LPD_VTRIP_4_65V:LPD门限电压阈值为4.65V
 * @retval None
 */ 
#if defined (SC92L853x) || defined (SC92L753x) || defined (SC92L840x)
void LPD_VtripConfig(LPD_Vtrip_TypeDef LPD_Vtrip)
{
	LPDCFG &= 0xF1;	/*复位门限电压阈值寄存器*/
	LPDCFG = LPD_Vtrip << 1;	/*设置门限电压阈值寄存器*/
}
#else
void LPD_VtripConfig(LPD_Vtrip_TypeDef LPD_Vtrip)
{
	LPDCFG &= 0xE1;	/*复位门限电压阈值寄存器*/
	LPDCFG |= LPD_Vtrip << 1;	/*设置门限电压阈值寄存器*/
}
#endif

/**
 * @brief  使能LPD功能
 * @param  NewState[in]: 断使能/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */ 
void LPD_Cmd(FunctionalState NewState)
{
	if(NewState == ENABLE)
	{
		LPDCFG |= 0x01;
		
	}
	else
	{
		LPDCFG &= 0xFE;
	}
}
/**
 * @}
 */
/* End of LPD_Group1.	*/


/** @defgroup LPD_Group2 Interrupts management functions
 *  @brief   Interrupts management functions
 *
@verbatim
 ===============================================================================
                     ##### Interrupts management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  LPD中断初始化
 * @param  NewState[in]: 断使能/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @param  Priority[in]: 中断优先级选择
 *              - LOW:低
 *              - HIGH:高
 * @retval None
 */ 
void LPD_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{

	/* 中断开关 */
  if (NewState != DISABLE)
  {
    IE2 |= 0x80;
  }
  else
  {
    IE2 &= 0x7F;
  }


	/* 中断开关 */
  if (Priority != LOW)
  {
    IP2 |= 0x80;
  }
  else
  {
    IP2 &= 0x7F;
  }

}

/**
 * @}
 */
/* End of LPD_Group2.	*/

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */
#endif
/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/