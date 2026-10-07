/**
 ******************************************************************************
 * @file    sc92f_acmp.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of ACMP module.
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
#ifndef _sc92f_ACMP_H_
#define _sc92f_ACMP_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
 /** @addtogroup ACMP
 * @{
 */
 
 /* Exported enumerations ------------------------------------------------------------*/
/** @defgroup ACMP_Enumerations ACMP Enumerations
 * @{
 */
 
 /** @brief CMP_Negative CMP Negative
 * @{
 */
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
		|| defined(SC92FWxx) || defined(SC92F859x) || defined(SC92F759x) || defined (SC92R511x) || defined (SC92F563x)
typedef enum
{
  ACMP_VREF_EXTERNAL = (uint8_t)0X00,  /*!< Select CMPR port for ACMP reference voltage   */
  ACMP_VREF_1D16VDD = (uint8_t)0X01,   /*!< Select 1/16 VDD as the comparison voltage for ACMP  */
  ACMP_VREF_2D16VDD = (uint8_t)0X02,   /*!< Select 2/16 VDD as the comparison voltage for ACMP  */
  ACMP_VREF_3D16VDD = (uint8_t)0X03,   /*!< Select 3/16 VDD as the comparison voltage for ACMP   */
  ACMP_VREF_4D16VDD = (uint8_t)0X04,   /*!< Select 4/16 VDD as the comparison voltage for ACMP   */
  ACMP_VREF_5D16VDD = (uint8_t)0X05,   /*!< Select 5/16 VDD as the comparison voltage for ACMP  */
  ACMP_VREF_6D16VDD = (uint8_t)0X06,   /*!< Select 6/16 VDD as the comparison voltage for ACMP   */
  ACMP_VREF_7D16VDD = (uint8_t)0X07,   /*!< Select 7/16 VDD as the comparison voltage for ACMP  */
  ACMP_VREF_8D16VDD = (uint8_t)0X08,   /*!< Select 8/16 VDD as the comparison voltage for ACMP   */
  ACMP_VREF_9D16VDD = (uint8_t)0X09,   /*!< Select 9/16 VDD as the comparison voltage for ACMP   */
  ACMP_VREF_10D16VDD = (uint8_t)0X0A,  /*!< Select 10/16 VDD as the comparison voltage for ACMP   */
  ACMP_VREF_11D16VDD = (uint8_t)0X0B,  /*!< Select 11/16 VDD as the comparison voltage for ACMP   */
  ACMP_VREF_12D16VDD = (uint8_t)0X0C,  /*!< Select 12/16 VDD as the comparison voltage for ACMP   */
  ACMP_VREF_13D16VDD = (uint8_t)0X0D,  /*!< Select 13/16 VDD as the comparison voltage for ACMP   */
  ACMP_VREF_14D16VDD = (uint8_t)0X0E,  /*!< Select 14/16 VDD as the comparison voltage for ACMP   */
  ACMP_VREF_15D16VDD = (uint8_t)0X0F   /*!< Select 15/16 VDD as the comparison voltage for ACMP   */
} ACMP_Vref_Typedef;
/**
 * @}
 */

/** @brief CMP_Positive CMP Positive
 * @{
 */
typedef enum
{
  ACMP_CHANNEL_0 = (uint8_t)0x00, /*!< Select CMP0 as the ACMP input    */
  ACMP_CHANNEL_1 = (uint8_t)0x01, /*!< Select CMP1 as the ACMP input    */
  ACMP_CHANNEL_2 = (uint8_t)0x02, /*!< Select CMP2 as the ACMP input    */
  ACMP_CHANNEL_3 = (uint8_t)0x03, /*!< Select CMP3 as the ACMP input    */
	#if defined(SC92F859x) || defined (SC92F759x) || defined (SC92R511x)
	ACMP_CHANNEL_P = (uint8_t)0x10, /*!< Select CMPP as the ACMP input, with CMPP set to a baseline voltage of 1.5V    */
	#elif defined(SC92F563x)
	ACMP_CHANNEL_P = (uint8_t)0x10, /*!< Select CMPP as the ACMP input, with CMPP set to a baseline voltage of 1.6V    */
	#endif 
} ACMP_Channel_TypeDef;
/**
 * @}
 */

/** @brief ACMP_TriggerMode ACMP TriggerMode
 * @{
 */
typedef enum
{
  ACMP_TRIGGER_NO = (uint8_t)0x00,         /*!< No interruptions    */
  ACMP_TRIGGER_RISE_ONLY = (uint8_t)0x04,  /*!< Select simulation comparator trigger mode as rising edge   */
  ACMP_TRIGGER_FALL_ONLY = (uint8_t)0x08,  /*!< Select simulation comparator trigger mode as falling edge   */
  ACMP_TRIGGER_RISE_FALL = (uint8_t)0x0C   /*!< Select simulation comparator trigger mode as rising edge and falling edge   */
} ACMP_TriggerMode_Typedef;
/**
 * @}
 */

/** @brief CMP_FLAG CMP Flag
 * @{
 */
typedef enum
{
  ACMP_FLAG_CMPIF = (uint8_t)0x40, /*!< ACMP interrupt flag    */
  ACMP_FLAG_CMPSTA = (uint8_t)0x20  /*!< ACMP output status    */
} ACMP_Flag_TypeDef;
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

/** @defgroup ACMP_Exported_Struct ACMP Exported Struct
 * @{
 */

/**
 * @}
 */
/* End of Struct -----------------------------------------------------*/

/** @addtogroup ACMP_Functions ACMP Functions
 * @{
 */
/* ACMP Base functions ********************************************************/
void ACMP_DeInit(void);
void ACMP_Init(ACMP_Vref_Typedef ACMP_Vref,
               ACMP_Channel_TypeDef ACMP_Channel);
void ACMP_SetTriggerMode(ACMP_TriggerMode_Typedef
                         ACMP_TriggerMode);
void ACMP_Cmd(FunctionalState NewState);
/* Interrupts and flags management functions  **********************************************/
void ACMP_ITConfig(FunctionalState NewState,
                   PriorityStatus Priority);
FlagStatus ACMP_GetFlagStatus(ACMP_Flag_TypeDef
                              ACMP_Flag);
void ACMP_ClearFlag(void);
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