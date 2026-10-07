/**
 ******************************************************************************
 * @file    sc92f_timer4.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of TIMER4 module.
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
#ifndef _sc92f_TIMER4_H_
#define _sc92f_TIMER4_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @addtogroup TIMER4
 * @{
 */
 
/** @defgroup TIMER4_Enumerations
 * @{
 */
 
 /** @brief TIM4_PresSel_TypeDef TIM4 Prescaler
 * @{
 */
typedef enum
{
  TIM4_PRESSEL_FSYS_D12 = ((uint8_t)0x00), /*!< TIMER4计数源来自系统时钟12分频 */
  TIM4_PRESSEL_FSYS_D1 = ((uint8_t)0x01)   /*!< TIMER4计数源来自系统时钟 */
} TIM4_PresSel_TypeDef;
/**
 * @}
 */

/** @brief TIM3_CountMode_TypeDef TIM3 Count Mode
 * @{
 */
typedef enum
{
  TIM4_MODE_TIMER = ((uint8_t)0x01),  /*!< TIMER2做定时器 */
  TIM4_MODE_COUNTER = ((uint8_t)0x02) /*!< TIMER2做计数器 */
} TIM4_CountMode_TypeDef;
/**
 * @}
 */

/** @brief TIM4_CountDirection_TypeDef TIM4 CountDirection
 * @{
 */
typedef enum
{
  TIM4_COUNTDIRECTION_UP = ((uint8_t)0x00),     /*!< 向上计数模式 */
  TIM4_COUNTDIRECTION_DOWN_UP = ((uint8_t)0x10) /*!< 向上/向下计数模式 */
} TIM4_CountDirection_TypeDef;
/**
 * @}
 */

/** @brief TIM4_Flag_TypeDef TIM4 Flag
 * @{
 */
typedef enum
{
  TIM4_FLAG_TF4 = (uint8_t)0x80, /*!< 中断标志位TF4 */
  TIM4_FLAG_EXF4 = (uint8_t)0x40 /*!< 中断标志位EXF4 */
} TIM4_Flag_TypeDef;
/**
 * @}
 */

typedef enum
{
  TIM4_WORK_MODE0 = ((uint8_t)0x00), /*!< TIMER4选择工作模式0 */
  TIM4_WORK_MODE1 = ((uint8_t)0x01), /*!< TIMER4选择工作模式1 */
  TIM4_WORK_MODE3 = ((uint8_t)0x03), /*!< TIMER4选择工作模式3 */
} TIM4_WorkMode_TypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup TIM4_Functions TIM4 Functions
 * @{
 */
/* Initialization and Configuration functions ***********************************************/
void TIM4_DeInit();
void TIM4_PrescalerSelection(TIM4_PresSel_TypeDef TIM4_PrescalerSelection);
void TIM4_WorkMode1Config(uint16_t TIM4_SetCounter);
void TIM4_Cmd(FunctionalState NewState);
void TIM4_ITConfig(FunctionalState NewState, PriorityStatus Priority);
FlagStatus TIM4_GetFlagStatus(TIM4_Flag_TypeDef TIM4_Flag);
void TIM4_ClearFlag(TIM4_Flag_TypeDef TIM4_Flag);

void TIM4_TimeBaseInit(TIM4_PresSel_TypeDef TIM4_PrescalerSelection,TIM4_CountMode_TypeDef TIM4_CountMode,
                       TIM4_CountDirection_TypeDef TIM4_CountDirection);
void TIM4_WorkMode0Config(uint16_t TIM4_SetCounter);
void TIM4_WorkMode3Config(uint16_t TIM4_SetCounter);
void TIM4_WorkModeConfig(TIM4_WorkMode_TypeDef TIM4_WorkMode, uint16_t TIM4_SetCounter);
void TIM4_SetEXEN4(FunctionalState NewState);
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
/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/