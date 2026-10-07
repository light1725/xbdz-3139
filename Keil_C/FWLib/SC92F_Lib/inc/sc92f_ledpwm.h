/**
 ******************************************************************************
 * @file    sc92f_ledpwm.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   LEDPWM function module
 ******************************************************************************
 * @attention
 *
 * 1. This software is supplied by SinOne Microelectronics Co.,Ltd. and is only 
 * intended for use with SinOne products. No other uses are authorized. This 
 * software is owned by SinOne Microelectronics Co.,Ltd. and is protected under 
 * all applicable laws, including copyright laws. 
 * 2. The software which is for guidance only aims at providing customers with 
 * coding information regarding their products in order for them to save time. 
 * As a result, SinOne shall not be held liable for any direct, indirect or 
 * consequential damages with respect to any claims arising from the content of 
 * such software and/or the use made by customers of the coding information 
 * contained herein in connection with their products.
 *
 * COPYRIGHT 2026 SinOne Microelectronics
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SC92F_LEDPWM_H
#define __SC92F_LEDPWM_H

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
 /** @addtogroup LEDPWM
 * @{
 */
 
 #if defined(SC92F663x)
 
 /* Exported enumerations ------------------------------------------------------------*/
/** @defgroup LEDPWM_Enumerations LEDPWM Enumerations
 * @{
 */
 
 /** @brief LEDPWM_ClockSource_Typedef LEDPWM ClockSource
 * @{
 */
typedef enum
{
  LEDPWM_CLK_DIV1   = 0x00, /*!< fSYS/1   */
  LEDPWM_CLK_DIV2   = 0x01, /*!< fSYS/2   */
  LEDPWM_CLK_DIV4   = 0x02, /*!< fSYS/4   */
  LEDPWM_CLK_DIV8   = 0x03, /*!< fSYS/8   */
  LEDPWM_CLK_DIV16  = 0x04, /*!< fSYS/16  */
  LEDPWM_CLK_DIV32  = 0x05, /*!< fSYS/32  */
  LEDPWM_CLK_DIV64  = 0x06, /*!< fSYS/64  */
  LEDPWM_CLK_DIV128 = 0x07, /*!< fSYS/128 */
  LEDPWM_CLK_DIV256 = 0x08  /*!< fSYS/256 */
} LEDPWM_ClockSource_Typedef;
/**
 * @}
 */

/** @brief LEDPWM_Channel_TypeDef LEDPWM Channel
 * @{
 */
typedef enum
{
  LEDPWM_CHANNEL_0  = 0x00,
  LEDPWM_CHANNEL_1  = 0x01,
  LEDPWM_CHANNEL_2  = 0x02,
  LEDPWM_CHANNEL_3  = 0x03,
  LEDPWM_CHANNEL_4  = 0x04,
  LEDPWM_CHANNEL_5  = 0x05,
  LEDPWM_CHANNEL_6  = 0x06,
  LEDPWM_CHANNEL_7  = 0x07,
  LEDPWM_CHANNEL_8  = 0x08,
  LEDPWM_CHANNEL_9  = 0x09,
  LEDPWM_CHANNEL_10 = 0x0A,
  LEDPWM_CHANNEL_11 = 0x0B,
  LEDPWM_CHANNEL_12 = 0x0C,
  LEDPWM_CHANNEL_13 = 0x0D,
  LEDPWM_CHANNEL_14 = 0x0E,
  LEDPWM_CHANNEL_15 = 0x0F
} LEDPWM_Channel_TypeDef;
/**
 * @}
 */

/** @brief LEDPWM_InvertChannelMask_Typedef LEDPWM TriggerMode
 * @{
 */
typedef enum
{
  LEDPWM_CHANNELMASK_CH0  = 0x0001, /*!< Channel 0 mask */
  LEDPWM_CHANNELMASK_CH1  = 0x0002, /*!< Channel 1 mask */
  LEDPWM_CHANNELMASK_CH2  = 0x0004, /*!< Channel 2 mask */
  LEDPWM_CHANNELMASK_CH3  = 0x0008, /*!< Channel 3 mask */
  LEDPWM_CHANNELMASK_CH4  = 0x0010, /*!< Channel 4 mask */
  LEDPWM_CHANNELMASK_CH5  = 0x0020, /*!< Channel 5 mask */
  LEDPWM_CHANNELMASK_CH6  = 0x0040, /*!< Channel 6 mask */
  LEDPWM_CHANNELMASK_CH7  = 0x0080, /*!< Channel 7 mask */
  LEDPWM_CHANNELMASK_CH8  = 0x0100, /*!< Channel 8 mask */
  LEDPWM_CHANNELMASK_CH9  = 0x0200, /*!< Channel 9 mask */
  LEDPWM_CHANNELMASK_CH10 = 0x0400, /*!< Channel 10 mask */
  LEDPWM_CHANNELMASK_CH11 = 0x0800, /*!< Channel 11 mask */
  LEDPWM_CHANNELMASK_CH12 = 0x1000, /*!< Channel 12 mask */
  LEDPWM_CHANNELMASK_CH13 = 0x2000, /*!< Channel 13 mask */
  LEDPWM_CHANNELMASK_CH14 = 0x4000, /*!< Channel 14 mask */
  LEDPWM_CHANNELMASK_CH15 = 0x8000  /*!< Channel 15 mask */
} LEDPWM_ChannelMask_Typedef;
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/**
 * @}
 */
/* End of constants -----------------------------------------------------*/

/** @defgroup LEDPWM_Exported_Struct LEDPWM Exported Struct
 * @{
 */

/**
 * @}
 */
/* End of Struct -----------------------------------------------------*/

/** @addtogroup LEDPWM_Functions LEDPWM Functions
 * @{
 */
/* LEDPWM Base functions ********************************************************/
void LEDPWM_DeInit(void);
void LEDPWM_Init(LEDPWM_ClockSource_Typedef ClkSrc, uint8_t PeriodVal);
void LEDPWM_ChannelConfig(uint16_t ChannelMask, FunctionalState NewState);
void LEDPWM_InvertConfig(uint16_t ChannelMask, FunctionalState NewState);
void LEDPWM_SetPeriod(uint8_t period);
void LEDPWM_SetDuty(LEDPWM_Channel_TypeDef Channel, uint8_t DutyVal);
void LEDPWM_Cmd(FunctionalState NewState);
/* Interrupts and flags management functions  **********************************************/
void LEDPWM_ITConfig(FunctionalState NewState, PriorityStatus Priority);
FlagStatus LEDPWM_GetFlagStatus(void);
void LEDPWM_ClearFlag(void);
/**
 * @}
 */
/* End of functions --------------------------------------------------*/

#endif

#endif

/**
 * @}
 */

/**
 * @}
 */
/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/