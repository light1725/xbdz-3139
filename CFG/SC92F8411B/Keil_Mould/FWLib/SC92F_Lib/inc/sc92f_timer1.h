/**
 ******************************************************************************
 * @file    sc92f_timer1.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of TIMER1 module.
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
#ifndef _sc92f_TIMER1_H_
#define	_sc92f_TIMER1_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @addtogroup TIMER1
 * @{
 */
 
/** @defgroup TIMER1_Enumerations
 * @{
 */
 
 /** @brief TIM1_PresSel_TypeDef TIM1 Prescaler
 * @{
 */
typedef enum
{
  TIM1_PRESSEL_FSYS_D12 = ((uint8_t)0x00),   /*!< TIMER1计数源来自系统时钟12分频 */
  TIM1_PRESSEL_FSYS_D1  = ((uint8_t)0x01)    /*!< TIMER1计数源来自系统时钟 */
} TIM1_PresSel_TypeDef;
/**
 * @}
 */

/** @brief TIM1_CountMode_TypeDef TIM1 Count Mode
 * @{
 */
typedef enum
{
  TIM1_MODE_TIMER   = ((uint8_t)0x01), /*!< TIMER1做定时器 */
  TIM1_MODE_COUNTER = ((uint8_t)0x02)  /*!< TIMER1做计数器 */
} TIM1_CountMode_TypeDef;
/**
 * @}
 */

/** @brief TIM_WorkMode TIM WorkMode
 * @{
 */
typedef enum
{
  TIM1_WORK_MODE0   = ((uint8_t)0x00),		/*!< TIMER1选择工作模式0 */
  TIM1_WORK_MODE1   = ((uint8_t)0x01),		/*!< TIMER1选择工作模式1 */
  TIM1_WORK_MODE2   = ((uint8_t)0x02),		/*!< TIMER1选择工作模式2 */
} TIM1_WorkMode_TypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup TIM1_Functions TIM1 Functions
 * @{
 */

/*macro function********************************************************/

/**
 * @brief  TIMER1工作模式0初值重载函数
 * @param  TIM1_SetCounter[in]:配置TIMER1重载值
 * @retval None
 */ 
#define TIM1_Mode0SetReloadCounter(TIM1_SetCounter)									\
				do{  																												\
					TL1 = (uint8_t)TIM1_SetCounter;														\
					TH1 = (TIM1_SetCounter >> 5);															\
				}while(0)

/**
 * @brief  TIMER1工作模式1初值重载函数
 * @param  TIM1_SetCounter[in]:配置TIMER1重载值
 * @retval None
 */ 
#define TIM1_Mode1SetReloadCounter(TIM1_SetCounter)									\
				do{  																												\
					TL1 = (uint8_t)TIM1_SetCounter;														\
					TH1 = (TIM1_SetCounter >> 8);															\
				}while(0)

/**
 * @brief  TIMER1功能开关函数
 * @param  NewState[in]:功能启动/关闭选择
 *                  - DISABLE:关闭
 *                  - ENABLE:使能
 * @retval None
 */ 
#define TIM1_Cmd(NewState)	(TR1 = (bit)NewState)

/**
 * @brief  TIMER1中断初始化
 * @param  NewState[in]: 断使能/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @param  Priority[in]: 中断优先级选择
 *              - LOW:低
 *              - HIGH:高
 * @retval None
 */
#define 	TIM1_ITConfig(NewState,Priority)										\
					do{  																								\
							ET1 = (bit)NewState;														\
							IPT1 = (bit)Priority;														\
					}while(0)

/**
 * @brief  获得TIMER1中断标志状态
 * @param  None
 * @retval TIMER1中断标志状态
 *                  - RESET:置零
 *                  - SET:置起
 */ 
#define TIM1_GetFlagStatus() (TF1)

/**
 * @brief  清除TIMER1中断标志状态
 * @param  None
 * @retval None
 */
#define TIM1_ClearFlag() (TF1 = 0)

/* Time Base functions ********************************************************/
void TIM1_DeInit(void);
void TIM1_TimeBaseInit(TIM1_PresSel_TypeDef
                       TIM1_PrescalerSelection,
                       TIM1_CountMode_TypeDef TIM1_CountMode);
void TIM1_WorkMode0Config(uint16_t TIM1_SetCounter);
void TIM1_WorkMode1Config(uint16_t TIM1_SetCounter);
void TIM1_WorkMode2Config(uint8_t TIM1_SetCounter);
void TIM1_WorkModeConfig(TIM1_WorkMode_TypeDef TIM1_WorkMode,
                         uint16_t TIM1_SetCounter);

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