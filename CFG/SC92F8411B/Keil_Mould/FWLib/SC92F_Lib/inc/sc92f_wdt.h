/**
 ******************************************************************************
 * @file    sc92f_wdt.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of WDT module.
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
 
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _sc92f_WDT_H_
#define	_sc92f_WDT_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
 /** @addtogroup WDT
 * @{
 */
 
 /** @defgroup WDT_Enumerations WDT Enumerations
 * @{
 */
typedef enum
{
  WDT_OverflowTime_500MS   = (uint8_t)0x00, 	   /*!< 看门狗溢出时间为500MS */
  WDT_OverflowTime_250MS   = (uint8_t)0x01, 	   /*!< 看门狗溢出时间为250MS */
  WDT_OverflowTime_125MS   = (uint8_t)0x02, 	   /*!< 看门狗溢出时间为125MS */
  WDT_OverflowTime_62_5MS  = (uint8_t)0x03, 	   /*!< 看门狗溢出时间为62.5MS */
  WDT_OverflowTime_31_5MS  = (uint8_t)0x04, 	   /*!< 看门狗溢出时间为31.5MS */
  WDT_OverflowTime_15_75MS = (uint8_t)0x05, 	   /*!< 看门狗溢出时间为15.75MS */
  WDT_OverflowTime_7_88MS  = (uint8_t)0x06, 	   /*!< 看门狗溢出时间为7.88MS */
  WDT_OverflowTime_3_94MS  = (uint8_t)0x07  	   /*!< 看门狗溢出时间为3.94MS */
} WDT_OverflowTime_TypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup WDT_Exported_Functions WDT Exported Functions
 * @{
 */

/*macro function********************************************************/

/**
 * @brief  WDT喂狗
 * @param  None
 * @retval None
 */
#define WDT_SetReload() SET_BIT(WDTCON,0x10)
/* WDT Base functions ********************************************************/
void WDT_DeInit(void);
void WDT_Init(WDT_OverflowTime_TypeDef
              OverflowTime);
void WDT_Cmd(FunctionalState NewState);
#endif
/**
 * @}
 */
/* End of WDT Functions.	*/

/**
 * @}
 */

/**
 * @}
 */
/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/