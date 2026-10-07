/**
 ******************************************************************************
 * @file    sc92f_lpd.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of LPD module.
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
#ifndef _sc92f_LPD_H_
#define _sc92f_LPD_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
 /** @addtogroup LPD
 * @{
 */
 
/* Exported enumerations ------------------------------------------------------------*/
/** @defgroup LPD_Exported_Enumerations LPD Exported Enumerations
 * @{
 */
 
/** @brief LPD_Vtrip_TypeDef LPD threshold voltage
 * @{
 */
#if defined (SC92L853x) || defined (SC92L753x) || defined (SC92L840x) || defined (SC92F663x) || defined (SC92F563x)
 
typedef enum
{
#if defined(SC92L853x) || defined(SC92L753x)
  LPD_VTRIP_1_85V = (uint8_t)0x00,  /*!< LPD门限电压阈值为1.85V  */
  LPD_VTRIP_2_05V = (uint8_t)0x01,  /*!< LPD门限电压阈值为2.05V  */
  LPD_VTRIP_2_25V = (uint8_t)0x02,  /*!< LPD门限电压阈值为2.25V  */
  LPD_VTRIP_2_45V = (uint8_t)0x03,  /*!< LPD门限电压阈值为2.45V  */
  LPD_VTRIP_2_85V = (uint8_t)0x04,  /*!< LPD门限电压阈值为2.85V  */
  LPD_VTRIP_3_45V = (uint8_t)0x05,  /*!< LPD门限电压阈值为3.45V  */
  LPD_VTRIP_3_85V = (uint8_t)0x06,  /*!< LPD门限电压阈值为3.85V  */
  LPD_VTRIP_4_45V = (uint8_t)0x07,  /*!< LPD门限电压阈值为4.45V  */
#elif defined(SC92L840x)
  LPD_VTRIP_1_85V = (uint8_t)0x00,  /*!< LPD门限电压阈值为1.85V  */
  LPD_VTRIP_2_05V = (uint8_t)0x01,  /*!< LPD门限电压阈值为2.05V  */
  LPD_VTRIP_2_25V = (uint8_t)0x02,  /*!< LPD门限电压阈值为2.25V  */
  LPD_VTRIP_2_45V = (uint8_t)0x03,  /*!< LPD门限电压阈值为2.45V  */
  LPD_VTRIP_2_65V = (uint8_t)0x04,  /*!< LPD门限电压阈值为2.85V  */
  LPD_VTRIP_2_85V = (uint8_t)0x05,  /*!< LPD门限电压阈值为3.45V  */
  LPD_VTRIP_3_05V = (uint8_t)0x06,  /*!< LPD门限电压阈值为3.85V  */
  LPD_VTRIP_3_25V = (uint8_t)0x07,  /*!< LPD门限电压阈值为4.45V  */	
#elif defined(SC92F663x) || defined(SC92F563x)
	LPD_VTRIP_2_40V = (uint8_t)0x00,  /*!< LPD门限电压阈值为2.40V  */
	LPD_VTRIP_2_55V = (uint8_t)0x01,  /*!< LPD门限电压阈值为2.55V  */
	LPD_VTRIP_2_70V = (uint8_t)0x02,  /*!< LPD门限电压阈值为2.70V  */
	LPD_VTRIP_2_85V = (uint8_t)0x03,  /*!< LPD门限电压阈值为2.85V  */
	LPD_VTRIP_3_00V = (uint8_t)0x04,  /*!< LPD门限电压阈值为3.00V  */
	LPD_VTRIP_3_15V = (uint8_t)0x05,  /*!< LPD门限电压阈值为3.15V  */
	LPD_VTRIP_3_30V = (uint8_t)0x06,  /*!< LPD门限电压阈值为3.30V  */
	LPD_VTRIP_3_45V = (uint8_t)0x07,  /*!< LPD门限电压阈值为3.45V  */
	LPD_VTRIP_3_60V = (uint8_t)0x08,  /*!< LPD门限电压阈值为3.60V  */
	LPD_VTRIP_3_75V = (uint8_t)0x09,  /*!< LPD门限电压阈值为3.75V  */
	LPD_VTRIP_3_90V = (uint8_t)0x0A,  /*!< LPD门限电压阈值为3.90V  */
	LPD_VTRIP_4_05V = (uint8_t)0x0B,  /*!< LPD门限电压阈值为4.05V  */
	LPD_VTRIP_4_20V = (uint8_t)0x0C,  /*!< LPD门限电压阈值为4.20V  */
	LPD_VTRIP_4_35V = (uint8_t)0x0D,  /*!< LPD门限电压阈值为4.35V  */
	LPD_VTRIP_4_50V = (uint8_t)0x0E,  /*!< LPD门限电压阈值为4.50V  */
	LPD_VTRIP_4_65V = (uint8_t)0x0F,  /*!< LPD门限电压阈值为4.65V  */
#endif
} LPD_Vtrip_TypeDef;
/**
 * @}
 */

/** @brief LPD_Flag_TypeDef LPD Flag
 * @{
 */
typedef enum
{
  LPD_FLAG_LPDIF = (uint8_t)0x40,  /*!< LPD中断请求标志  */
  LPD_FLAG_LPDOF = (uint8_t)0x80,  /*!< LPD状态标志位  */
} LPD_Flag_TypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup ADC_macro_Functions ADC macro Functions
 * @{
 */
/*macro function********************************************************/

/**
 * @brief  获得LPD中断标志状态
 * @param  LPD_Flag[in]:中断标志位选择
 *          -LPD_FLAG_LPDIF：
 *          -LPD_FLAG_LPDOF
 * @retval FlagStatus:LPD中断标志位置起状态
 */
#define LPD_GetFlagStatus(LPD_Flag) ((READ_BIT(LPDCFG,LPD_Flag)) ? (SET):(RESET))

/**
 * @brief  清除LPD中断标志状态
 * @retval None
 */
#define LPD_ClearFlag() CLEAR_BIT(LPDCFG,LPD_FLAG_LPDIF)
/**
 * @}
 */
/* End of macro Functions -----------------------------------------------------*/

/** @addtogroup ADC_Exported_Functions ADC Exported Functions
 * @{
 */
void LPD_DeInit(void);
void LPD_VtripConfig(LPD_Vtrip_TypeDef LPD_Vtrip);
void LPD_ITConfig(FunctionalState NewState, PriorityStatus Priority);
void LPD_Cmd(FunctionalState NewState);
/**
 * @}
 */
/* End of exported functions --------------------------------------------------*/

/**
 * @}
 */

/**
 * @}
 */
#endif

#endif
/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/