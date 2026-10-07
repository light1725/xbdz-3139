/**
 ******************************************************************************
 * @file    sc92f_gpio.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of GPIO module.
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
#ifndef _sc92f_GPIO_H_
#define	_sc92f_GPIO_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/* Sbit ------------------------------------------------------------------*/
sbit IO00 = P0^0;
sbit IO01 = P0^1;
sbit IO02 = P0^2;
sbit IO03 = P0^3;
sbit IO04 = P0^4;
sbit IO05 = P0^5;
sbit IO06 = P0^6;
sbit IO07 = P0^7;

sbit IO10 = P1^0;
sbit IO11 = P1^1;
sbit IO12 = P1^2;
sbit IO13 = P1^3;
sbit IO14 = P1^4;
sbit IO15 = P1^5;
sbit IO16 = P1^6;
sbit IO17 = P1^7;

sbit IO20 = P2^0;
sbit IO21 = P2^1;
sbit IO22 = P2^2;
sbit IO23 = P2^3;
sbit IO24 = P2^4;
sbit IO25 = P2^5;
sbit IO26 = P2^6;
sbit IO27 = P2^7;
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
	|| defined(SC92FWxx) || defined(SC92F859x) || defined(SC92F759x) || defined (SC92R511x) || defined(SC92F663x) || defined(SC92F563x)
sbit IO30 = P3^0;
sbit IO31 = P3^1;
sbit IO32 = P3^2;
sbit IO33 = P3^3;
sbit IO34 = P3^4;
sbit IO35 = P3^5;
sbit IO36 = P3^6;
sbit IO37 = P3^7;

sbit IO40 = P4^0;
sbit IO41 = P4^1;
sbit IO42 = P4^2;
sbit IO43 = P4^3;
sbit IO44 = P4^4;
sbit IO45 = P4^5;
sbit IO46 = P4^6;
sbit IO47 = P4^7;
#endif
#if !defined(SC92F730x) && !defined(SC92F725X) && !defined(SC92F735X) && !defined(SC92F8003) && !defined(SC92F8003B) && !defined(SC92F7003) && !defined(SC92F740x)\
		&& !defined(SC92F730x_2) && !defined(SC92F720x) && !defined(SC92F827X) && !defined(SC92F837X)&& !defined(SC92F7308B)&& !defined(SC92F5x5x)&& !defined(SC92F531x)\
		&& !defined(SC92F637x)
sbit IO50 = P5^0;
sbit IO51 = P5^1;
sbit IO52 = P5^2;
sbit IO53 = P5^3;
sbit IO54 = P5^4;
sbit IO55 = P5^5;
#endif

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @addtogroup GPIO
 * @{
 */

/** @defgroup GPIO_Enumerations GPIO Enumerations
 * @{
 */


/** @brief GPIO port enumeration
 * @{
 */
#if defined (SC92F854x) || defined (SC92F754x) ||defined  (SC92F844xB) || defined (SC92F744xB) || defined  (SC92F84Ax_2) || defined (SC92F74Ax_2)\
		|| defined(SC92FWxx)|| defined(SC92F859x) || defined(SC92F759x) || defined (SC92R511x) || defined(SC92F663x) || defined(SC92F563x)
typedef enum
{
  GPIO0 = (uint8_t)0x00,	   /*!< P0 selected    */
  GPIO1 = (uint8_t)0x01,	   /*!< P1 selected    */
  GPIO2 = (uint8_t)0x02,	   /*!< P2 selected    */
  GPIO3 = (uint8_t)0x03,	   /*!< P3 selected    */
  GPIO4 = (uint8_t)0x04,	   /*!< P4 selected    */
  GPIO5 = (uint8_t)0x05	       /*!< P5 selected    */
}GPIO_TypeDef;
#elif defined (SC92F730x ) || defined (SC92F725X) || defined (SC92F735X) || defined (SC92F8003) || defined(SC92F8003B) || defined (SC92F740x) || defined (SC92F827X) || defined (SC92F837X) || defined (SC92F7003)\
  || defined(SC92F730x_2) || defined(SC92F720x) || defined (SC92F7308B) || defined (SC92F5x5x) || defined (SC92F531x) || defined(SC92F637x)
typedef enum
{
  GPIO0 = (uint8_t)0x00,	   /*!< P0 selected    */
  GPIO1 = (uint8_t)0x01,	   /*!< P1 selected    */
  GPIO2 = (uint8_t)0x02,	   /*!< P2 selected    */
}GPIO_TypeDef;
#else
typedef enum
{
  GPIO0 = (uint8_t)0x00,		/*!< P0 selected    */
  GPIO1 = (uint8_t)0x01,		/*!< P1 selected    */
  GPIO2 = (uint8_t)0x02,		/*!< P2 selected    */
  GPIO5 = (uint8_t)0x05			/*!< P5 selected    */
}GPIO_TypeDef;
#endif
/**
 * @}
 */

/** @brief GPIO_Mode GPIO Mode
 * @{
 */
typedef enum
{
  GPIO_MODE_IN_HI  = (uint8_t)0x00, /*!< GPIO High-resistance Input Mode   */
  GPIO_MODE_IN_PU  = (uint8_t)0x01, /*!< GPIO Pull-up Input Mode  */
  GPIO_MODE_OUT_PP = (uint8_t)0x02  /*!< GPIO Strong push-pull Output Mode   */
} GPIO_Mode_TypeDef;
/**
 * @}
 */

/** @brief GPIO_DriveLevel GPIO DriveLevel
 * @{
 */
typedef enum
{
  IOH_Grade_0    = ((uint8_t)0x00),  /*!< I/O output Drive: Level 0(Max) */
  IOH_Grade_1    = ((uint8_t)0x01),  /*!< I/O output Drive: Level 1 */
  IOH_Grade_2    = ((uint8_t)0x02),  /*!< I/O output Drive: Level 2 */
  IOH_Grade_3    = ((uint8_t)0x03),  /*!< I/O output Drive: Level 3 */
} GPIO_IOH_Grade_TypeDef;
/**
 * @}
 */


/** @brief GPIO_Pin GPIO Pins enumeration
 * @{
 */
typedef enum
{
  GPIO_PIN_0    = ((uint8_t)0x01),  /*!< Pin 0 selected    */
  GPIO_PIN_1    = ((uint8_t)0x02),  /*!< Pin 1 selected    */
  GPIO_PIN_2    = ((uint8_t)0x04),  /*!< Pin 2 selected    */
  GPIO_PIN_3    = ((uint8_t)0x08),  /*!< Pin 3 selected    */
  GPIO_PIN_4    = ((uint8_t)0x10),  /*!< Pin 4 selected    */
  GPIO_PIN_5    = ((uint8_t)0x20),  /*!< Pin 5 selected    */
  GPIO_PIN_6    = ((uint8_t)0x40),  /*!< Pin 6 selected    */
  GPIO_PIN_7    = ((uint8_t)0x80),  /*!< Pin 7 selected    */
  GPIO_PIN_LNIB = ((uint8_t)0x0F),  /*!< Pin 0~3 selected  */
  GPIO_PIN_HNIB = ((uint8_t)0xF0),  /*!< Pin 4~7 selected  */
  GPIO_PIN_ALL  = ((uint8_t)0xFF)   /*!< Pin 0~7 selected  */
} GPIO_Pin_TypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of Enumerations --------------------------------------------------*/

/** @addtogroup GPIO_Exported_Functions
 * @{
 */
/* Initialization and de-initialization functions *****************************/
#if !defined(SC92F7003) && !defined(SC92F8003)  && !defined(SC92F8003B) && !defined(SC92F740x)&& !defined (SC92F6x1x) && !defined (SC92F5x1x)&& !defined(SC92R436)\
    && !defined(SC92L840x) && !defined(SC92R439) && !defined(SC92R422A) && !defined(SC92F652x) && !defined(SC92R51x_R52x) && !defined(SC92F552x)&& !defined(SC92F5x5x) && !defined(SC92F531x)\
		&& !defined(SC92F637x) && !defined(SC92F663x) && !defined(SC92F563x)
void GPIO_IOH_Config(GPIO_TypeDef GPIOx, GPIO_Pin_TypeDef PortPins,GPIO_IOH_Grade_TypeDef GPIO_IOH_Grade);
#endif
void GPIO_DeInit(void);
void GPIO_Init(GPIO_TypeDef GPIOx,uint8_t PortPins, GPIO_Mode_TypeDef GPIO_Mode);
/* IO operation functions *****************************************************/
void GPIO_Write(GPIO_TypeDef GPIOx,uint8_t PortVal);
void GPIO_WriteHigh(GPIO_TypeDef GPIOx,uint8_t PortPins);
void GPIO_WriteLow(GPIO_TypeDef GPIOx,uint8_t PortPins);
uint8_t GPIO_ReadPort(GPIO_TypeDef GPIOx);
BitStatus GPIO_ReadPin(GPIO_TypeDef GPIOx,uint8_t PortPins);
void GPIO_TogglePin(GPIO_TypeDef GPIOx, uint8_t PortPins);
#endif
/**
 * @}
 */
/* End of functions --------------------------------------------------*/

/**
 * @}
 */

/**
 * @}
 */

/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/
