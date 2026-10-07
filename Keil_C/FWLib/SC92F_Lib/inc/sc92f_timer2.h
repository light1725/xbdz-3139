/**
 ******************************************************************************
 * @file    sc92f_timer2.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of TIMER2 module.
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
#ifndef _sc92f_TIMER2_H_
#define	_sc92f_TIMER2_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @addtogroup TIMER2
 * @{
 */
 
/** @defgroup TIMER2_Enumerations
 * @{
 */
 
 /** @brief TIM2_PresSel_TypeDef TIM2 Prescaler
 * @{
 */
typedef enum
{
  TIM2_PRESSEL_FSYS_D12  = ((uint8_t)0x00), /*!< TIMER2计数源来自系统时钟12分频 */
  TIM2_PRESSEL_FSYS_D1   = ((uint8_t)0x01)  /*!< TIMER2计数源来自系统时钟 */
} TIM2_PresSel_TypeDef;
/**
 * @}
 */

#if defined (SC92F730x) || defined (SC92F827X) || defined (SC92F837X) || defined (SC92F725X) || defined(SC92F735X) || defined(SC92F730x_2) || defined(SC92F720x) \
|| defined (SC92F7308B)
/** @brief TIM2_CountMode_TypeDef TIM2 Count Mode
 * @{
 */
typedef enum
{
  TIM2_MODE_TIMER   = ((uint8_t)0x01), /*!< TIMER2做定时器 */
} TIM2_CountMode_TypeDef;
/**
 * @}
 */

/** @brief TIM2_CountDirection_TypeDef TIM CountDirection
 * @{
 */
typedef enum
{
  TIM2_COUNTDIRECTION_UP       = ((uint8_t)0x00),  /*!< 向上计数模式 */
} TIM2_CountDirection_TypeDef;
/**
 * @}
 */

/** @brief TIM2_Flag_TypeDef TIM2 Flag
 * @{
 */
typedef enum
{
  TIM2_FLAG_TF2   = (uint8_t)0x80, 	   /*!< 中断标志位TF2，计数溢出 */
} TIM2_Flag_TypeDef;
/**
 * @}
 */

/** @brief TIM2_WorkMode_TypeDef TIM2 WorkMode
 * @{
 */
typedef enum
{
  TIM2_WORK_MODE1   = ((uint8_t)0x00),		/*!< TIMER2选择工作模式1 */
} TIM2_WorkMode_TypeDef;
/**
 * @}
 */
#else
/** @brief TIM2_CountMode_TypeDef TIM2 Count Mode
 * @{
 */
#if !defined (SC92F5x5x)
typedef enum
{
  TIM2_MODE_TIMER   = ((uint8_t)0x01), /*!< TIMER2做定时器 */
  TIM2_MODE_COUNTER = ((uint8_t)0x02)  /*!< TIMER2做计数器 */
} TIM2_CountMode_TypeDef;
#else
typedef enum
{
  TIM2_MODE_TIMER   = ((uint8_t)0x01), /*!< TIMER2做定时器 */
} TIM2_CountMode_TypeDef;
#endif
/**
 * @}
 */

/** @brief TIM_WorkMode TIM WorkMode
 * @{
 */
typedef enum
{
  TIM2_COUNTDIRECTION_UP  		 = ((uint8_t)0x00),  /*!< 向上计数模式 */
  TIM2_COUNTDIRECTION_DOWN_UP  = ((uint8_t)0x10)    /*!< 向上/向下计数模式 */
} TIM2_CountDirection_TypeDef;
/**
 * @}
 */

/** @brief TIM2_Flag_TypeDef TIM2 Flag
 * @{
 */
typedef enum
{
  TIM2_FLAG_TF2   = (uint8_t)0x80, 	   /*!< 中断标志位TF2，计数溢出 */
  TIM2_FLAG_EXF2  = (uint8_t)0x40 	   /*!< 中断标志位EXF2，外部触发 */
} TIM2_Flag_TypeDef;
/**
 * @}
 */

/** @brief TIM2_WorkMode_TypeDef TIM2 WorkMode
 * @{
 */
typedef enum
{
  TIM2_WORK_MODE0   = ((uint8_t)0x00),		/*!< TIMER2选择工作模式0 */
  TIM2_WORK_MODE1   = ((uint8_t)0x01),		/*!< TIMER2选择工作模式1 */
#if !defined (SC92F5x5x)
  TIM2_WORK_MODE3   = ((uint8_t)0x03),		/*!< TIMER2选择工作模式3 */
#endif
} TIM2_WorkMode_TypeDef;
/**
 * @}
 */

#if defined (SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)
/** @brief T2EX_PortMappingPin_TypeDef T2EX Port Mapping Pins
 * @{
 */
typedef enum
{
  T2EXMapped_to_P50 = (uint8_t)0x00, /*!< T2EX映射到P50 */
  T2EXMapped_to_P51 = (uint8_t)0x01, /*!< T2EX映射到P51 */
  T2EXMapped_to_P52 = (uint8_t)0x02, /*!< T2EX映射到P52 */
  T2EXMapped_to_P53 = (uint8_t)0x03, /*!< T2EX映射到P53 */
	T2EXMapped_to_P54 = (uint8_t)0x04, /*!< T2EX映射到P54 */
	T2EXMapped_to_P56 = (uint8_t)0x06, /*!< T2EX映射到P56 */
  T2EXMapped_to_P57 = (uint8_t)0x07, /*!< T2EX映射到P57 */
  T2EXMapped_to_P10 = (uint8_t)0x08, /*!< T2EX映射到P10 */
  T2EXMapped_to_P11 = (uint8_t)0x09, /*!< T2EX映射到P11 */
	T2EXMapped_to_P12 = (uint8_t)0x0A, /*!< T2EX映射到P12 */
	T2EXMapped_to_P13 = (uint8_t)0x0B, /*!< T2EX映射到P13 */
  T2EXMapped_to_P14 = (uint8_t)0x0C, /*!< T2EX映射到P14 */
  T2EXMapped_to_P15 = (uint8_t)0x0D, /*!< T2EX映射到P15 */
  T2EXMapped_to_P16 = (uint8_t)0x0E, /*!< T2EX映射到P16 */
	T2EXMapped_to_P17 = (uint8_t)0x0F, /*!< T2EX映射到P17 */
	T2EXMapped_to_P27 = (uint8_t)0x10, /*!< T2EX映射到P27 */
  T2EXMapped_to_P26 = (uint8_t)0x11, /*!< T2EX映射到P26 */
  T2EXMapped_to_P25 = (uint8_t)0x12, /*!< T2EX映射到P25 */
  T2EXMapped_to_P24 = (uint8_t)0x13, /*!< T2EX映射到P24 */
	T2EXMapped_to_P23 = (uint8_t)0x14, /*!< T2EX映射到P23 */
	T2EXMapped_to_P22 = (uint8_t)0x15, /*!< T2EX映射到P22 */
  T2EXMapped_to_P21 = (uint8_t)0x16, /*!< T2EX映射到P21 */
  T2EXMapped_to_P20 = (uint8_t)0x17, /*!< T2EX映射到P20 */
  T2EXMapped_to_P07 = (uint8_t)0x18, /*!< T2EX映射到P07 */
	T2EXMapped_to_P06 = (uint8_t)0x19, /*!< T2EX映射到P06 */
	T2EXMapped_to_P05 = (uint8_t)0x1A, /*!< T2EX映射到P05 */
  T2EXMapped_to_P04 = (uint8_t)0x1B, /*!< T2EX映射到P04 */
  T2EXMapped_to_P03 = (uint8_t)0x1C, /*!< T2EX映射到P03 */
  T2EXMapped_to_P02 = (uint8_t)0x1D, /*!< T2EX映射到P02 */
	T2EXMapped_to_P01 = (uint8_t)0x1E, /*!< T2EX映射到P01 */
	T2EXMapped_to_P00 = (uint8_t)0x1F, /*!< T2EX映射到P00 */
} T2EX_PortMappingPin_TypeDef;
/**
 * @}
 */
#elif defined (SC92F5x5x)
/** @brief T2EX_PortMappingPin_TypeDef T2EX Port Mapping Pins
 * @{
 */
typedef enum
{
  T2EXMapped_to_P00 = (uint8_t)0x00, /*!< T2EX映射到P00 */
  T2EXMapped_to_P01 = (uint8_t)0x01, /*!< T2EX映射到P01 */
  T2EXMapped_to_P05 = (uint8_t)0x05, /*!< T2EX映射到P05 */
  T2EXMapped_to_P20 = (uint8_t)0x08, /*!< T2EX映射到P20 */
	T2EXMapped_to_P21 = (uint8_t)0x09, /*!< T2EX映射到P21 */
	T2EXMapped_to_P22 = (uint8_t)0x0A, /*!< T2EX映射到P22 */
  T2EXMapped_to_P23 = (uint8_t)0x0B, /*!< T2EX映射到P23 */
  T2EXMapped_to_P24 = (uint8_t)0x0C, /*!< T2EX映射到P24 */
  T2EXMapped_to_P25 = (uint8_t)0x0D, /*!< T2EX映射到P25 */
	T2EXMapped_to_P26 = (uint8_t)0x0E, /*!< T2EX映射到P26 */
	T2EXMapped_to_P13 = (uint8_t)0x14, /*!< T2EX映射到P13 */
	T2EXMapped_to_P12 = (uint8_t)0x15, /*!< T2EX映射到P12 */
  T2EXMapped_to_P11 = (uint8_t)0x16, /*!< T2EX映射到P11 */
  T2EXMapped_to_P10 = (uint8_t)0x19, /*!< T2EX映射到P10 */
} T2EX_PortMappingPin_TypeDef;
/**
 * @}
 */
#elif defined (SC92F531x)
/** @brief T2EX_PortMappingPin_TypeDef T2EX Port Mapping Pins
 * @{
 */
typedef enum
{
  T2EXMapped_to_P00 = (uint8_t)0x00, /*!< T2EX映射到P00 */
  T2EXMapped_to_P01 = (uint8_t)0x01, /*!< T2EX映射到P01 */
  T2EXMapped_to_P02 = (uint8_t)0x02, /*!< T2EX映射到P02 */
  T2EXMapped_to_P03 = (uint8_t)0x03, /*!< T2EX映射到P03 */
	T2EXMapped_to_P04 = (uint8_t)0x04, /*!< T2EX映射到P04 */
	T2EXMapped_to_P05 = (uint8_t)0x05, /*!< T2EX映射到P05 */
	T2EXMapped_to_P06 = (uint8_t)0x06, /*!< T2EX映射到P06 */
  T2EXMapped_to_P07 = (uint8_t)0x07, /*!< T2EX映射到P07 */
  T2EXMapped_to_P20 = (uint8_t)0x08, /*!< T2EX映射到P20 */
  T2EXMapped_to_P21 = (uint8_t)0x09, /*!< T2EX映射到P21 */
	T2EXMapped_to_P22 = (uint8_t)0x0A, /*!< T2EX映射到P22 */
	T2EXMapped_to_P23 = (uint8_t)0x0B, /*!< T2EX映射到P23 */
  T2EXMapped_to_P24 = (uint8_t)0x0C, /*!< T2EX映射到P24 */
  T2EXMapped_to_P25 = (uint8_t)0x0D, /*!< T2EX映射到P25 */
  T2EXMapped_to_P26 = (uint8_t)0x0E, /*!< T2EX映射到P26 */
	T2EXMapped_to_P27 = (uint8_t)0x0F, /*!< T2EX映射到P27 */
	T2EXMapped_to_P15 = (uint8_t)0x12, /*!< T2EX映射到P15 */
  T2EXMapped_to_P14 = (uint8_t)0x13, /*!< T2EX映射到P14 */
  T2EXMapped_to_P13 = (uint8_t)0x14, /*!< T2EX映射到P13 */
  T2EXMapped_to_P12 = (uint8_t)0x15, /*!< T2EX映射到P12 */
	T2EXMapped_to_P11 = (uint8_t)0x16, /*!< T2EX映射到P11 */
	T2EXMapped_to_P10 = (uint8_t)0x19, /*!< T2EX映射到P10 */
} T2EX_PortMappingPin_TypeDef;
/**
 * @}
 */
#elif defined (SC92F663x)
/** @brief T2EX_PortMappingPin_TypeDef T2EX Port Mapping Pins
 * @{
 */
typedef enum
{
  T2Mapped_to_P51 = (uint8_t)0x00, /*!< T2映射到P51 */
  T2Mapped_to_P44 = (uint8_t)0x01, /*!< T2映射到P44 */
  T2Mapped_to_P43 = (uint8_t)0x02, /*!< T2映射到P43 */
  T2Mapped_to_P42 = (uint8_t)0x03, /*!< T2映射到P42 */
	T2Mapped_to_P41 = (uint8_t)0x04, /*!< T2映射到P41 */
	T2Mapped_to_P40 = (uint8_t)0x05, /*!< T2映射到P40 */
  T2Mapped_to_P37 = (uint8_t)0x06, /*!< T2映射到P37 */
  T2Mapped_to_P36 = (uint8_t)0x07, /*!< T2映射到P36 */
} T2_PortMappingPin_TypeDef;
/**
 * @}
 */

/** @brief T2EX_PortMappingPin_TypeDef T2EX Port Mapping Pins
 * @{
 */
typedef enum
{
  T2EXMapped_to_P45 = (uint8_t)0x00, /*!< T2EX映射到P45 */
  T2EXMapped_to_P44 = (uint8_t)0x01, /*!< T2EX映射到P44 */
  T2EXMapped_to_P42 = (uint8_t)0x02, /*!< T2EX映射到P42 */
  T2EXMapped_to_P41 = (uint8_t)0x03, /*!< T2EX映射到P41 */
	T2EXMapped_to_P37 = (uint8_t)0x04, /*!< T2EX映射到P37 */
	T2EXMapped_to_P36 = (uint8_t)0x05, /*!< T2EX映射到P36 */
  T2EXMapped_to_P35 = (uint8_t)0x06, /*!< T2EX映射到P35 */
  T2EXMapped_to_P34 = (uint8_t)0x07, /*!< T2EX映射到P34 */
  T2EXMapped_to_P33 = (uint8_t)0x08, /*!< T2EX映射到P33 */
	T2EXMapped_to_P32 = (uint8_t)0x09, /*!< T2EX映射到P32 */
	T2EXMapped_to_P31 = (uint8_t)0x0A, /*!< T2EX映射到P31 */
  T2EXMapped_to_P30 = (uint8_t)0x0B, /*!< T2EX映射到P30 */
} T2EX_PortMappingPin_TypeDef;
/**
 * @}
 */
#endif

#endif

#if defined(SC92F84Hx) || defined(SC92F83Hx)
/** @brief TIM2_PinSelection_TypeDef TIM2 PinSelection
 * @{
 */
typedef enum
{
  TIM2_PinRemap_Default = (uint8_t)0x00, /*!< TIM2引脚为默认引脚 */
  TIM2_PinRemap_A = (uint8_t)0x04,       /*!< TIM2引脚为A组引脚 */
} TIM2_PinSelection_TypeDef;
/**
 * @}
 */
void TIM2_PinSelection(TIM2_PinSelection_TypeDef PinSeletion);
#endif
/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup TIM2_Functions TIM2 Functions
 * @{
 */
/* Initialization and Configuration functions ***********************************************/
void TIM2_DeInit();
void TIM2_PrescalerSelection(TIM2_PresSel_TypeDef TIM2_PrescalerSelection);
void TIM2_TimeBaseInit(TIM2_PresSel_TypeDef TIM2_PrescalerSelection,
                       TIM2_CountMode_TypeDef TIM2_CountMode,
                       TIM2_CountDirection_TypeDef TIM2_CountDirection);
void TIM2_WorkMode0Config(uint16_t TIM2_SetCounter);
void TIM2_WorkMode1Config(uint16_t TIM2_SetCounter);
void TIM2_WorkMode3Config(uint16_t TIM2_SetCounter);
void TIM2_WorkModeConfig(TIM2_WorkMode_TypeDef TIM2_WorkMode, uint16_t TIM2_SetCounter);
/* Time Base functions ********************************************************/
void TIM2_SetEXEN2(FunctionalState NewState);
void TIM2_Cmd(FunctionalState NewState);
/* Interrupt Handler functions  ***********************************************/
void TIM2_ITConfig(FunctionalState NewState, PriorityStatus Priority);
FlagStatus TIM2_GetFlagStatus(TIM2_Flag_TypeDef TIM2_Flag);
void TIM2_ClearFlag(TIM2_Flag_TypeDef TIM2_Flag);
#if defined (SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)|| defined (SC92F5x5x) || defined (SC92F531x)
void T2EX_PortMapping(T2EX_PortMappingPin_TypeDef T2EX_MappingPin);
#endif
#if defined (SC92F663x)
void T2_PortMapping(T2_PortMappingPin_TypeDef T2_MappingPin);
void T2EX_PortMapping(T2EX_PortMappingPin_TypeDef T2EX_MappingPin);
#endif
/**
 * @}
 */
/* End of exported functions --------------------------------------------------*/
#endif
/**
 * @}
 */

/**
 * @}
 */
/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/