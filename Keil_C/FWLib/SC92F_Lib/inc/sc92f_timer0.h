/**
 ******************************************************************************
 * @file    sc92f_tiemr0.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of TIMER0 module.
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
 
/* Define to prevent recursive inclusion -----------------------------------*/
#ifndef _sc92f_TIMER0_H_
#define	_sc92f_TIMER0_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @addtogroup TIMER0
 * @{
 */
 
/** @defgroup TIMER0_Enumerations
 * @{
 */
 
/** @brief TIM0_PresSel_TypeDef TIM0 Prescaler
 * @{
 */
typedef enum
{
  TIM0_PRESSEL_FSYS_D12 = ((uint8_t)0x00),   /*!< TIMER0计数源来自系统时钟12分频 */
  TIM0_PRESSEL_FSYS_D1  = ((uint8_t)0x01)    /*!< TIMER0计数源来自系统时钟 */
} TIM0_PresSel_TypeDef;
/**
 * @}
 */

/** @brief TIM0_CountMode_TypeDef TIM Count Mode
 * @{
 */
typedef enum
{
  TIM0_MODE_TIMER   = ((uint8_t)0x01), /*!< TIMER0做定时器 */
  TIM0_MODE_COUNTER = ((uint8_t)0x02)  /*!< TIMER0做计数器 */
} TIM0_CountMode_TypeDef;
/**
 * @}
 */

/** @brief TIM_WorkMode TIM WorkMode
 * @{
 */
typedef enum
{
  TIM0_WORK_MODE0   = ((uint8_t)0x00),		/*!< TIMER0选择工作模式0 */
  TIM0_WORK_MODE1   = ((uint8_t)0x01),		/*!< TIMER0选择工作模式1 */
  TIM0_WORK_MODE2   = ((uint8_t)0x02),		/*!< TIMER0选择工作模式2 */
  TIM0_WORK_MODE3   = ((uint8_t)0x03)		/*!< TIMER0选择工作模式3 */
} TIM0_WorkMode_TypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup TIM0_Functions TIM0 Functions
 * @{
 */

/*macro function********************************************************/

/**
 * @brief  TIMER0工作模式0初值重载函数
 * @param  TIM0_SetCounter[in]:配置TIMER0重载值
 * @retval None
 */ 
#define TIM0_Mode0SetReloadCounter(TIM0_SetCounter)									\
				do{  																												\
					TL0 = (uint8_t)TIM0_SetCounter;														\
					TH0 = (TIM0_SetCounter >> 5);															\
				}while(0)

/**
 * @brief  TIMER0工作模式1初值重载函数
 * @param  TIM0_SetCounter[in]:配置TIMER0重载值
 * @retval None
 */ 
#define TIM0_Mode1SetReloadCounter(TIM0_SetCounter)									\
				do{  																												\
					TL0 = (uint8_t)TIM0_SetCounter;														\
					TH0 = (TIM0_SetCounter >> 8);															\
				}while(0)

/**
 * @brief  TIMER0 TH0赋值函数
 * @param  TIM0_SetCounter[in]:配置TH0
 * @retval None
 */ 
#define TIM0_SetTH0Counter(TIM0_SetCounter) (TH0 = TIM0_SetCounter)

/**
 * @brief  TIMER0 TL0赋值函数
 * @param  TIM0_SetCounter[in]:配置TL0
 * @retval None
 */                
#define TIM0_SetTL0Counter(TIM0_SetCounter) (TL0 = TIM0_SetCounter)

/**
 * @brief  TIMER0功能开关函数
 * @param  NewState[in]:功能启动/关闭选择
 *                  - DISABLE:关闭
 *                  - ENABLE:使能
 * @retval None
 */                
#define TIM0_Cmd(NewState)	(TR0 = (bit)NewState)

/**
 * @brief  获得TIMER0中断标志状态
 * @param  None
 * @retval TIMER0中断标志状态
 *                  - RESET:置零
 *                  - SET:置起
 */ 
#define TIM0_GetFlagStatus() (TF0)

/**
 * @brief  TIMER0中断初始化
 * @param  NewState[in]: 断使能/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @param  Priority[in]: 中断优先级选择
 *              - LOW:低
 *              - HIGH:高
 * @retval None
 */
#define 	TIM0_ITConfig(NewState,Priority)										\
					do{  																								\
							ET0 = (bit)NewState;														\
							IPT0 = (bit)Priority;														\
					}while(0)
                    
/**
 * @brief  清除TIMER0中断标志状态
 * @param  None
 * @retval None
 */
#define TIM0_ClearFlag() (TF0 = 0)

/* Time Base functions ********************************************************/
void TIM0_DeInit(void);
void TIM0_TimeBaseInit(TIM0_PresSel_TypeDef
                       TIM0_PrescalerSelection,
                       TIM0_CountMode_TypeDef TIM0_CountMode);
void TIM0_WorkMode0Config(uint16_t
                          TIM0_SetCounter);
void TIM0_WorkMode1Config(uint16_t
                          TIM0_SetCounter);
void TIM0_WorkMode2Config(uint8_t
                          TIM0_SetCounter);
void TIM0_WorkMode3Config(uint8_t TIM0_SetCounter,
                          uint8_t TIM1_SetCounter);
void TIM0_WorkModeConfig(TIM0_WorkMode_TypeDef
                         TIM0_WorkMode, uint16_t TIM0_SetCounter1,
                         uint16_t TIM0_SetCounter2);
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