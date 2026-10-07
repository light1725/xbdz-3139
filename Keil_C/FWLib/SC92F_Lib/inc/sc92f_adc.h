/**
 ******************************************************************************
 * @file    sc92f_adc.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of ADC module.
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
#ifndef _sc92f_ADC_H_
#define _sc92f_ADC_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"
/* note:the ADC reference voltage source enum is in sc92f_option.h. Make sure to include this file when using ADC */
#include "sc92f_option.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
 /** @addtogroup ADC
 * @{
 */
 
 /* Exported enumerations ------------------------------------------------------------*/
/** @defgroup ADC_Exported_Enumerations ADC Exported Enumerations
 * @{
 */
 
 /** @brief ADC_Prescaler ADC Prescaler
 * @{
 */
#if !defined(SC92F827X) && !defined(SC92F837X) && !defined(SC92F637x)
/* ADC sampling clock division conversion */
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2) || defined(SC92FWxx)
typedef enum
{
  ADC_PRESSEL_FOSC_D6  = (uint8_t)0x02, /*!< prescaler fADC = fHRC/6  */
  ADC_PRESSEL_FOSC_D12 = (uint8_t)0x01  /*!< prescaler fADC = fHRC/12 */
} ADC_PresSel_TypeDef;
#elif defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB)|| defined (SC92F83Ax) || defined (SC92F73Ax)\
	|| defined (SC92F84Ax) || defined (SC92F74Ax) || defined (SC92F7003) || defined (SC92F8003) || defined(SC92F8003B) || defined (SC92F740x) || defined (SC92R342) \
	|| defined (SC92F841x) || defined (SC92F741x) || defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92L840x)|| defined (SC92Fx41xB)|| defined (SC92R445)
typedef enum
{
  ADC_PRESSEL_FHRC_D32 = (uint8_t)0x00,    /*!< prescaler fADC = fHRC/32 */
  ADC_PRESSEL_FHRC_D24 = (uint8_t)0x01,  /*!< prescaler fADC = fHRC/24 */
  ADC_PRESSEL_FHRC_D16 = (uint8_t)0x02, /*!< prescaler fADC = fHRC/16 */
  ADC_PRESSEL_FHRC_D12 = (uint8_t)0x03, /*!< prescaler fADC = fHRC/12 */
  ADC_PRESSEL_FHRC_D8 = (uint8_t)0x04,  /*!< prescaler fADC = fHRC/8 */
  ADC_PRESSEL_FHRC_D6 = (uint8_t)0x05,  /*!< prescaler fADC = fHRC/6 */
  ADC_PRESSEL_FHRC_D4 = (uint8_t)0x06,  /*!< prescaler fADC = fHRC/4 */
  ADC_PRESSEL_FHRC_D3 = (uint8_t)0x07   /*!< prescaler fADC = fHRC/3 */
} ADC_PresSel_TypeDef;
#elif defined (SC92F742x) || defined (SC92F730x) || defined (SC92F725X) || defined (SC92F735X) || defined (SC92F732X) || defined (SC92F7490)\
	|| defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x) || defined(SC92F730x_2) || defined(SC92F720x) || defined (SC92F7308B)
typedef enum
{ 
  ADC_PRESSEL_2_MHz = (uint8_t)0x00,    /*!< prescaler fADC = 2MHz */
  ADC_PRESSEL_333_kHz = (uint8_t)0x20   /*!< prescaler fADC = 333Khz */
} ADC_PresSel_TypeDef;
#elif defined(SC92F848x) || defined(SC92F748x)
typedef enum
{
  ADC_PRESSEL_FSYS_D16 = (uint8_t)0x00, /*!< prescaler fADC = fHRC/16 */
  ADC_PRESSEL_FSYS_D12 = (uint8_t)0x01, /*!< prescaler fADC = fHRC/12 */
  ADC_PRESSEL_FSYS_D8 = (uint8_t)0x02,  /*!< prescaler fADC = fHRC/8 */
  ADC_PRESSEL_FSYS_D6 = (uint8_t)0x03,  /*!< prescaler fADC = fHRC/6 */
  ADC_PRESSEL_FSYS_D4 = (uint8_t)0x04,  /*!< prescaler fADC = fHRC/4 */
  ADC_PRESSEL_FSYS_D3 = (uint8_t)0x05,  /*!< prescaler fADC = fHRC/3 */
  ADC_PRESSEL_FSYS_D2 = (uint8_t)0x06,  /*!< prescaler fADC = fHRC/2 */
  ADC_PRESSEL_FSYS_D1 = (uint8_t)0x07   /*!< prescaler fADC = fHRC/1 */
} ADC_PresSel_TypeDef;
#elif defined(SC92F859x) || defined(SC92F759x) || defined (SC92R511x) || defined (SC92F6x1x) || defined (SC92F5x1x) || defined(SC92R436)\
  || defined(SC92R438) || defined(SC92R439) || defined(SC92R422A) || defined(SC92F652x)|| defined(SC92F5x5x)
typedef enum
{
  ADC_PRESSEL_FSYS_D16 = (uint8_t)0x00, /*!< prescaler fADC = fSYS/16 */
  ADC_PRESSEL_FSYS_D12 = (uint8_t)0x01, /*!< prescaler fADC = fSYS/12 */
  ADC_PRESSEL_FSYS_D6 = (uint8_t)0x02,  /*!< prescaler fADC = fSYS/6 */
  ADC_PRESSEL_FSYS_D4 = (uint8_t)0x03,  /*!< prescaler fADC = fSYS/4 */
} ADC_PresSel_TypeDef;
#elif defined (SC92L853x) || defined (SC92L753x)
typedef enum
{
  ADC_PRESSEL_3CLOCK = (uint8_t)0x10,  /*!< Sampling time is 3 system clocks  */
  ADC_PRESSEL_6CLOCK = (uint8_t)0x14,  /*!< Sampling time is 6 system clocks  */
  ADC_PRESSEL_16CLOCK = (uint8_t)0x18, /*!< Sampling time is 16 system clocks  */
  ADC_PRESSEL_32CLOCK = (uint8_t)0x1c  /*!< Sampling time is 32 system clocks  */
} ADC_PresSel_TypeDef;
#elif defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F531x) || defined(SC92R51x_R52x) || defined (SC92F552x)\
 || defined(SC92F663x) || defined(SC92F563x)
typedef enum
{
  ADC_PRESSEL_Null = (uint8_t)0x00,
} ADC_PresSel_TypeDef;
#endif
/**
 * @}
 */

/** @brief ADC_Cycle ADC Cycle
 * @{
 */
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
		|| defined(SC92FWxx) || defined(SC92F859x)  || defined (SC92F759x) || defined (SC92R511x)
typedef enum
{
  ADC_Cycle_6Cycle = (uint8_t)0x00,  /*!< ADC sampling time is 6 ADC clock cycles  */
  ADC_Cycle_36Cycle = (uint8_t)0x04  /*!< ADC sampling time is 36 ADC clock cycles  */
} ADC_Cycle_TypeDef;
#elif defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB) || defined (SC92F83Ax) || defined (SC92F73Ax)\
	|| defined (SC92F84Ax) || defined (SC92F74Ax) || defined (SC92F7003) || defined(SC92F8003) || defined(SC92F8003B) || defined (SC92F740x)\
	|| defined (SC92F848x) || defined (SC92F748x) || defined (SC92R342) || defined (SC92F841x) || defined (SC92F741x)\
  || defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92L840x) || defined (SC92Fx41xB)|| defined (SC92R445)
typedef enum
{
  ADC_Cycle_6Cycle = (uint8_t)0x00, /*!< ADC sampling time is 6 ADC clock cycles  */
  ADC_Cycle_36Cycle = (uint8_t)0x08 /*!< ADC sampling time is 36 ADC clock cycles  */
} ADC_Cycle_TypeDef;
#elif defined (SC92F742x) || defined (SC92F730x) || defined (SC92F725X) || defined (SC92F735X) || defined (SC92F732X)\
|| defined (SC92F7490) || defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x) || defined (SC92L853x) || defined (SC92L753x)\
|| defined(SC92F730x_2) || defined(SC92F720x) || defined (SC92F7308B)
typedef enum
{
  ADC_Cycle_Null = (uint8_t)0x00,
} ADC_Cycle_TypeDef;
#elif defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)\
|| defined(SC92F531x) || defined(SC92F663x) || defined(SC92F563x)  
typedef enum
{
	ADC_Cycle_3Cycle = (uint8_t)0x10, /*!< ADC sampling time is 3 ADC clock cycles  */
	ADC_Cycle_6Cycle = (uint8_t)0x14, /*!< ADC sampling time is 6 ADC clock cycles  */
	ADC_Cycle_16Cycle = (uint8_t)0x18, /*!< ADC sampling time is 16 ADC clock cycles  */
	ADC_Cycle_32Cycle = (uint8_t)0x1C, /*!< ADC sampling time is 32 ADC clock cycles  */
} ADC_Cycle_TypeDef;
#elif defined (SC92F6x1x) || defined (SC92F5x1x) || defined(SC92R436) || defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A) || defined(SC92F5x5x)
typedef enum
{
	ADC_Cycle1_20Cycle = (uint8_t)0x00,  /*!< ADC sampling time is 20 ADC clock cycles  */
	ADC_Cycle1_50Cycle = (uint8_t)0x04,  /*!< ADC sampling time is 50 ADC clock cycles  */
	ADC_Cycle2_20Cycle = (uint8_t)0x08, /*!< ADC sampling time is 20 ADC clock cycles  */
	ADC_Cycle2_50Cycle = (uint8_t)0x0C, /*!< ADC sampling time is 50 ADC clock cycles  */
} ADC_Cycle_TypeDef;
#endif
/**
 * @}
 */

/** @brief ADC_ChannelTypedef ADC input channel
 * @{
 */
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
		|| defined(SC92FWxx) || defined(SC92F859x) || defined(SC92F759x) || defined (SC92R511x)
typedef enum
{
  ADC_CHANNEL_0 = (uint8_t)0x00,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_1 = (uint8_t)0x01,     /*!< Select AIN1 as the AD input port  */
  ADC_CHANNEL_2 = (uint8_t)0x02,     /*!< Select AIN2 as the AD input port  */
  ADC_CHANNEL_3 = (uint8_t)0x03,     /*!< Select AIN3 as the AD input port  */
  ADC_CHANNEL_4 = (uint8_t)0x04,     /*!< Select AIN4 as the AD input port  */
  ADC_CHANNEL_5 = (uint8_t)0x05,     /*!< Select AIN5 as the AD input port  */
  ADC_CHANNEL_6 = (uint8_t)0x06,     /*!< Select AIN6 as the AD input port  */
  ADC_CHANNEL_7 = (uint8_t)0x07,     /*!< Select AIN7 as the AD input port  */
  ADC_CHANNEL_8 = (uint8_t)0x08,     /*!< Select AIN8 as the AD input port  */
  ADC_CHANNEL_9 = (uint8_t)0x09,     /*!< Select AIN9 as the AD input port  */
  ADC_CHANNEL_10 = (uint8_t)0x0A,    /*!< Select AIN10 as the AD input port  */
  ADC_CHANNEL_11 = (uint8_t)0x0B,    /*!< Select AIN11 as the AD input port  */
  ADC_CHANNEL_12 = (uint8_t)0x0C,    /*!< Select AIN12 as the AD input port  */
  ADC_CHANNEL_13 = (uint8_t)0x0D,    /*!< Select AIN13 as the AD input port  */
  ADC_CHANNEL_14 = (uint8_t)0x0E,    /*!< Select AIN14 as the AD input port  */
  ADC_CHANNEL_15 = (uint8_t)0x0F,    /*!< Select AIN15 as the AD input port  */
  ADC_CHANNEL_VDD_D4 = (uint8_t)0x1f /*!< Select  1/4 VDD as the AD input port  */
} ADC_Channel_TypeDef;
#elif defined(SC92F84Hx) || defined(SC92F83Hx)
typedef enum
{
  ADC_CHANNEL_0 = (uint8_t)0x00,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_1 = (uint8_t)0x01,     /*!< Select AIN1 as the AD input port  */
  ADC_CHANNEL_2 = (uint8_t)0x02,     /*!< Select AIN2 as the AD input port  */
  ADC_CHANNEL_3 = (uint8_t)0x03,     /*!< Select AIN3 as the AD input port  */
  ADC_CHANNEL_4 = (uint8_t)0x04,     /*!< Select AIN4 as the AD input port  */
  ADC_CHANNEL_5 = (uint8_t)0x05,     /*!< Select AIN5 as the AD input port  */
  ADC_CHANNEL_6 = (uint8_t)0x06,     /*!< Select AIN6 as the AD input port  */
  ADC_CHANNEL_7 = (uint8_t)0x07,     /*!< Select AIN7 as the AD input port  */
  ADC_CHANNEL_8 = (uint8_t)0x08,     /*!< Select AIN8 as the AD input port  */
  ADC_CHANNEL_9 = (uint8_t)0x09,     /*!< Select AIN9 as the AD input port  */
  ADC_CHANNEL_10 = (uint8_t)0x0A,    /*!< Select AIN10 as the AD input port  */
  ADC_CHANNEL_11 = (uint8_t)0x0B,    /*!< Select AIN11 as the AD input port  */
  ADC_CHANNEL_12 = (uint8_t)0x0C,    /*!< Select AIN12 as the AD input port  */
  ADC_CHANNEL_13 = (uint8_t)0x0D,    /*!< Select AIN13 as the AD input port  */
  ADC_CHANNEL_14 = (uint8_t)0x0E,    /*!< Select AIN14 as the AD input port  */
  ADC_CHANNEL_15 = (uint8_t)0x0F,    /*!< Select AIN15 as the AD input port  */
	ADC_CHANNEL_16 = (uint8_t)0x10,  /*!< Select AIN16 as the AD input port  */
	ADC_CHANNEL_17 = (uint8_t)0x11,  /*!< Select AIN17 as the AD input port  */
	ADC_CHANNEL_18 = (uint8_t)0x12,  /*!< Select AIN18 as the AD input port  */
	ADC_CHANNEL_19 = (uint8_t)0x13,  /*!< Select AIN19 as the AD input port  */
  ADC_CHANNEL_VDD_D4 = (uint8_t)0x1f /*!< Select  1/4 VDD as the AD input port  */
} ADC_Channel_TypeDef;
#elif defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)
typedef enum
{
  ADC_CHANNEL_0 = (uint8_t)0x00,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_1 = (uint8_t)0x01,     /*!< Select AIN1 as the AD input port  */
  ADC_CHANNEL_2 = (uint8_t)0x02,     /*!< Select AIN2 as the AD input port  */
  ADC_CHANNEL_3 = (uint8_t)0x03,     /*!< Select AIN3 as the AD input port  */
  ADC_CHANNEL_4 = (uint8_t)0x04,     /*!< Select AIN4 as the AD input port  */
  ADC_CHANNEL_5 = (uint8_t)0x05,     /*!< Select AIN5 as the AD input port  */
  ADC_CHANNEL_6 = (uint8_t)0x06,     /*!< Select AIN6 as the AD input port  */
  ADC_CHANNEL_7 = (uint8_t)0x07,     /*!< Select AIN7 as the AD input port  */
  ADC_CHANNEL_8 = (uint8_t)0x08,     /*!< Select AIN8 as the AD input port  */
  ADC_CHANNEL_9 = (uint8_t)0x09,     /*!< Select AIN9 as the AD input port  */
  ADC_CHANNEL_10 = (uint8_t)0x0A,    /*!< Select AIN10 as the AD input port  */
  ADC_CHANNEL_11 = (uint8_t)0x0B,    /*!< Select AIN11 as the AD input port  */
  ADC_CHANNEL_VDD_D4 = (uint8_t)0x1f /*!< Select  1/4 VDD as the AD input port  */
} ADC_Channel_TypeDef;
#elif defined(SC92F7003) || defined(SC92F8003) || defined(SC92F8003B) || defined(SC92F740x)
typedef enum
{
  ADC_CHANNEL_0 = (uint8_t)0x00,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_1 = (uint8_t)0x01,     /*!< Select AIN1 as the AD input port  */
  ADC_CHANNEL_2 = (uint8_t)0x02,     /*!< Select AIN2 as the AD input port  */
  ADC_CHANNEL_3 = (uint8_t)0x03,     /*!< Select AIN3 as the AD input port  */
  ADC_CHANNEL_4 = (uint8_t)0x04,     /*!< Select AIN4 as the AD input port  */
  ADC_CHANNEL_5 = (uint8_t)0x05,     /*!< Select AIN5 as the AD input port  */
  ADC_CHANNEL_6 = (uint8_t)0x06,     /*!< Select AIN6 as the AD input port  */
  ADC_CHANNEL_VDD_D4 = (uint8_t)0x1f /*!< Select  1/4 VDD as the AD input port  */
} ADC_Channel_TypeDef;
#elif defined(SC92F846xB) || defined(SC92F746xB) || defined(SC92F836xB) || defined(SC92F736xB) || defined(SC92F83Ax)\
		|| defined(SC92F73Ax) || defined(SC92F84Ax) || defined(SC92F74Ax) || defined(SC92F742x) || defined(SC92F725X)\
		|| defined(SC92F735X) || defined(SC92F732X) || defined(SC92F848x) || defined(SC92F748x) || defined (SC92L853x) || defined (SC92L753x)\
		|| defined (SC92R342) || defined (SC92F841x) || defined (SC92F741x) ||defined (SC92L840x)|| defined (SC92Fx41xB)|| defined (SC92R445)
typedef enum
{
  ADC_CHANNEL_0 = (uint8_t)0x00,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_1 = (uint8_t)0x01,     /*!< Select AIN1 as the AD input port  */
  ADC_CHANNEL_2 = (uint8_t)0x02,     /*!< Select AIN2 as the AD input port  */
  ADC_CHANNEL_3 = (uint8_t)0x03,     /*!< Select AIN3 as the AD input port  */
  ADC_CHANNEL_4 = (uint8_t)0x04,     /*!< Select AIN4 as the AD input port  */
  ADC_CHANNEL_5 = (uint8_t)0x05,     /*!< Select AIN5 as the AD input port  */
  ADC_CHANNEL_6 = (uint8_t)0x06,     /*!< Select AIN6 as the AD input port  */
  ADC_CHANNEL_7 = (uint8_t)0x07,     /*!< Select AIN7 as the AD input port  */
  ADC_CHANNEL_8 = (uint8_t)0x08,     /*!< Select AIN8 as the AD input port  */
  ADC_CHANNEL_9 = (uint8_t)0x09,     /*!< Select AIN9 as the AD input port  */
  ADC_CHANNEL_VDD_D4 = (uint8_t)0x1f /*!< Select  1/4 VDD as the AD input port  */
} ADC_Channel_TypeDef;
#elif defined(SC92F730x) || defined (SC92F7308B)
typedef enum
{
  ADC_CHANNEL_0 = (uint8_t)0x00,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_1 = (uint8_t)0x01,     /*!< Select AIN1 as the AD input port  */
  ADC_CHANNEL_6 = (uint8_t)0x06,     /*!< Select AIN6 as the AD input port  */
  ADC_CHANNEL_7 = (uint8_t)0x07,     /*!< Select AIN7 as the AD input port  */
  ADC_CHANNEL_VDD_D4 = (uint8_t)0x1f /*!< Select  1/4 VDD as the AD input port  */
} ADC_Channel_TypeDef;
#elif defined(SC92F730x_2) || defined(SC92F720x)
typedef enum
{
  ADC_CHANNEL_0 = (uint8_t)0x00,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_1 = (uint8_t)0x01,     /*!< Select AIN1 as the AD input port  */
	ADC_CHANNEL_4 = (uint8_t)0x04,   /*!< Select AIN4 as the AD input port  */
  ADC_CHANNEL_5 = (uint8_t)0x05,     /*!< Select AIN5 as the AD input port  */
  ADC_CHANNEL_6 = (uint8_t)0x06,     /*!< Select AIN6 as the AD input port  */
  ADC_CHANNEL_7 = (uint8_t)0x07,     /*!< Select AIN7 as the AD input port  */
	ADC_CHANNEL_8 = (uint8_t)0x08,   /*!< Select AIN8 as the AD input port  */
  ADC_CHANNEL_9 = (uint8_t)0x09,     /*!< Select AIN9 as the AD input port  */
  ADC_CHANNEL_VDD_D4 = (uint8_t)0x1f /*!< Select  1/4 VDD as the AD input port  */
} ADC_Channel_TypeDef;
#elif defined(SC92F7490)
typedef enum
{
  ADC_CHANNEL_0 = (uint8_t)0x00,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_1 = (uint8_t)0x01,     /*!< Select AIN1 as the AD input port  */
  ADC_CHANNEL_VDD_D4 = (uint8_t)0x1f /*!< Select  1/4 VDD as the AD input port  */
} ADC_Channel_TypeDef;
#elif defined(SC93F833x) || defined(SC93F843x) || defined(SC93F743x)
typedef enum
{
  ADC_CHANNEL_0 = (uint8_t)0x00,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_1 = (uint8_t)0x01,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_2 = (uint8_t)0x02,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_3 = (uint8_t)0x03,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_4 = (uint8_t)0x04,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_5 = (uint8_t)0x05,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_6 = (uint8_t)0x06,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_7 = (uint8_t)0x07,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_8 = (uint8_t)0x08,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_9 = (uint8_t)0x09,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_9_PGA = (uint8_t)0x19, /*!< Select AIN9 as the PGA input port  */
  ADC_CHANNEL_Temp = (uint8_t)0x0e,  /*!< Select the internal temperature senso as the PGA input port  */
  ADC_CHANNEL_VDD_D4 = (uint8_t)0x0f /*!< Select  1/4 VDD as the AD input port  */
} ADC_Channel_TypeDef;
#elif defined (SC92F6x1x) || defined (SC92F5x1x) || defined(SC92R436)|| defined(SC92R438) || defined(SC92R439) || defined(SC92R422A)
typedef enum
{
  ADC_CHANNEL_0 = (uint8_t)0x00,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_1 = (uint8_t)0x01,     /*!< Select AIN1 as the AD input port  */
  ADC_CHANNEL_2 = (uint8_t)0x02,     /*!< Select AIN2 as the AD input port  */
  ADC_CHANNEL_3 = (uint8_t)0x03,     /*!< Select AIN3 as the AD input port  */
  ADC_CHANNEL_4 = (uint8_t)0x04,     /*!< Select AIN4 as the AD input port  */
  ADC_CHANNEL_5 = (uint8_t)0x05,     /*!< Select AIN5 as the AD input port  */
  ADC_CHANNEL_6 = (uint8_t)0x06,     /*!< Select AIN6 as the AD input port  */
  ADC_CHANNEL_7 = (uint8_t)0x07,     /*!< Select AIN7 as the AD input port  */
  ADC_CHANNEL_8 = (uint8_t)0x08,     /*!< Select AIN8 as the AD input port  */
  ADC_CHANNEL_9 = (uint8_t)0x09,     /*!< Select AIN9 as the AD input port  */
  ADC_CHANNEL_10 = (uint8_t)0x0A,    /*!< Select AIN10 as the AD input port  */
  ADC_CHANNEL_11 = (uint8_t)0x0B,    /*!< Select AIN11 as the AD input port  */
  ADC_CHANNEL_12 = (uint8_t)0x0C,    /*!< Select AIN12 as the AD input port  */
  ADC_CHANNEL_13 = (uint8_t)0x0D,    /*!< Select AIN13 as the AD input port  */
  ADC_CHANNEL_14 = (uint8_t)0x0E,    /*!< Select AIN14 as the AD input port  */
  ADC_CHANNEL_15 = (uint8_t)0x0F,    /*!< Select AIN15 as the AD input port  */
	ADC_CHANNEL_16 = (uint8_t)0x10,  /*!< Select AIN16 as the AD input port  */
	ADC_CHANNEL_17 = (uint8_t)0x11,  /*!< Select AIN17 as the AD input port  */
	ADC_CHANNEL_18 = (uint8_t)0x12,  /*!< Select AIN18 as the AD input port  */
	ADC_CHANNEL_19 = (uint8_t)0x13,  /*!< Select AIN19 as the AD input port  */
	ADC_CHANNEL_20 = (uint8_t)0x14,  /*!< Select AIN20 as the AD input port  */
	ADC_CHANNEL_21 = (uint8_t)0x15,  /*!< Select AIN21 as the AD input port  */
	ADC_CHANNEL_22 = (uint8_t)0x16,  /*!< Select AIN22 as the AD input port  */
	ADC_CHANNEL_23 = (uint8_t)0x17,  /*!< Select AIN23 as the AD input port  */
	ADC_CHANNEL_24 = (uint8_t)0x18,  /*!< Select AIN24 as the AD input port  */
	ADC_CHANNEL_25 = (uint8_t)0x19,  /*!< Select AIN25 as the AD input port  */
  ADC_CHANNEL_VDD_D4 = (uint8_t)0x1f /*!< Select  1/4 VDD as the AD input port  */
} ADC_Channel_TypeDef;
#elif defined (SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)
typedef enum
{
  ADC_CHANNEL_0 = (uint8_t)0x00,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_1 = (uint8_t)0x01,     /*!< Select AIN1 as the AD input port  */
  ADC_CHANNEL_2 = (uint8_t)0x02,     /*!< Select AIN2 as the AD input port  */
  ADC_CHANNEL_3 = (uint8_t)0x03,     /*!< Select AIN3 as the AD input port  */
  ADC_CHANNEL_4 = (uint8_t)0x04,     /*!< Select AIN4 as the AD input port  */
  ADC_CHANNEL_5 = (uint8_t)0x05,     /*!< Select AIN5 as the AD input port  */
  ADC_CHANNEL_6 = (uint8_t)0x06,     /*!< Select AIN6 as the AD input port  */
  ADC_CHANNEL_7 = (uint8_t)0x07,     /*!< Select AIN7 as the AD input port  */
  ADC_CHANNEL_8 = (uint8_t)0x08,     /*!< Select AIN8 as the AD input port  */
  ADC_CHANNEL_9 = (uint8_t)0x09,     /*!< Select AIN9 as the AD input port  */
  ADC_CHANNEL_10 = (uint8_t)0x0A,    /*!< Select AIN10 as the AD input port  */
  ADC_CHANNEL_11 = (uint8_t)0x0B,    /*!< Select AIN11 as the AD input port  */
  ADC_CHANNEL_12 = (uint8_t)0x0C,    /*!< Select AIN12 as the AD input port  */
  ADC_CHANNEL_13 = (uint8_t)0x0D,    /*!< Select AIN13 as the AD input port  */
  ADC_CHANNEL_14 = (uint8_t)0x0E,    /*!< Select AIN14 as the AD input port  */
  ADC_CHANNEL_15 = (uint8_t)0x0F,    /*!< Select AIN15 as the AD input port  */
	ADC_CHANNEL_16 = (uint8_t)0x10,  /*!< Select AIN16 as the AD input port  */
	ADC_CHANNEL_17 = (uint8_t)0x11,  /*!< Select AIN17 as the AD input port  */
	ADC_CHANNEL_18 = (uint8_t)0x12,  /*!< Select AIN18 as the AD input port  */
	ADC_CHANNEL_19 = (uint8_t)0x13,  /*!< Select AIN19 as the AD input port  */
	ADC_CHANNEL_20 = (uint8_t)0x14,  /*!< Select AIN20 as the AD input port  */
	ADC_CHANNEL_21 = (uint8_t)0x15,  /*!< Select AIN21 as the AD input port  */
	ADC_CHANNEL_22 = (uint8_t)0x16,  /*!< Select AIN22 as the AD input port  */
	ADC_CHANNEL_23 = (uint8_t)0x17,  /*!< Select AIN23 as the AD input port  */
	ADC_CHANNEL_24 = (uint8_t)0x18,  /*!< Select AIN24 as the AD input port  */
	ADC_CHANNEL_25 = (uint8_t)0x19,  /*!< Select AIN25 as the AD input port  */
	ADC_CHANNEL_26 = (uint8_t)0x1A,  /*!< Select AIN26 as the AD input port  */
	ADC_CHANNEL_27 = (uint8_t)0x1B,  /*!< Select AIN27 as the AD input port  */
	ADC_CHANNEL_28 = (uint8_t)0x1C,  /*!< Select AIN28 as the AD input port  */
	ADC_CHANNEL_29 = (uint8_t)0x1D,  /*!< Select AIN29 as the AD input port  */
	ADC_CHANNEL_30 = (uint8_t)0x1E,  /*!< Select AIN30 as the AD input port  */
  ADC_CHANNEL_VDD_D4 = (uint8_t)0x1f /*!< Select  1/4 VDD as the AD input port  */
} ADC_Channel_TypeDef;
#elif defined (SC92F5x5x)
typedef enum
{
  ADC_CHANNEL_0 = (uint8_t)0x00,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_1 = (uint8_t)0x01,     /*!< Select AIN1 as the AD input port  */
  ADC_CHANNEL_5 = (uint8_t)0x05,     /*!< Select AIN5 as the AD input port  */
  ADC_CHANNEL_8 = (uint8_t)0x08,     /*!< Select AIN8 as the AD input port  */
	ADC_CHANNEL_9 = (uint8_t)0x09,     /*!< Select AIN9 as the AD input port  */
  ADC_CHANNEL_10 = (uint8_t)0x0A,    /*!< Select AIN10 as the AD input port  */
  ADC_CHANNEL_11 = (uint8_t)0x0B,    /*!< Select AIN11 as the AD input port  */
  ADC_CHANNEL_12 = (uint8_t)0x0C,    /*!< Select AIN12 as the AD input port  */
  ADC_CHANNEL_13 = (uint8_t)0x0D,    /*!< Select AIN13 as the AD input port  */
  ADC_CHANNEL_14 = (uint8_t)0x0E,    /*!< Select AIN14 as the AD input port  */
	ADC_CHANNEL_18 = (uint8_t)0x12,  /*!< Select AIN18 as the AD input port  */
	ADC_CHANNEL_19 = (uint8_t)0x13,  /*!< Select AIN19 as the AD input port  */
	ADC_CHANNEL_20 = (uint8_t)0x14,  /*!< Select AIN20 as the AD input port  */
	ADC_CHANNEL_21 = (uint8_t)0x15,  /*!< Select AIN21 as the AD input port  */
  ADC_CHANNEL_VDD_D4 = (uint8_t)0x1f /*!< Select  1/4 VDD as the AD input port  */
} ADC_Channel_TypeDef;
#elif defined (SC92F531x)
typedef enum
{
  ADC_CHANNEL_0 = (uint8_t)0x00,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_1 = (uint8_t)0x01,     /*!< Select AIN1 as the AD input port  */
  ADC_CHANNEL_2 = (uint8_t)0x02,     /*!< Select AIN2 as the AD input port  */
  ADC_CHANNEL_3 = (uint8_t)0x03,     /*!< Select AIN3 as the AD input port  */
  ADC_CHANNEL_4 = (uint8_t)0x04,     /*!< Select AIN4 as the AD input port  */
  ADC_CHANNEL_5 = (uint8_t)0x05,     /*!< Select AIN5 as the AD input port  */
  ADC_CHANNEL_6 = (uint8_t)0x06,     /*!< Select AIN6 as the AD input port  */
  ADC_CHANNEL_7 = (uint8_t)0x07,     /*!< Select AIN7 as the AD input port  */
  ADC_CHANNEL_8 = (uint8_t)0x08,     /*!< Select AIN8 as the AD input port  */
  ADC_CHANNEL_9 = (uint8_t)0x09,     /*!< Select AIN9 as the AD input port  */
  ADC_CHANNEL_10 = (uint8_t)0x0A,    /*!< Select AIN10 as the AD input port  */
  ADC_CHANNEL_11 = (uint8_t)0x0B,    /*!< Select AIN11 as the AD input port  */
  ADC_CHANNEL_12 = (uint8_t)0x0C,    /*!< Select AIN12 as the AD input port  */
  ADC_CHANNEL_13 = (uint8_t)0x0D,    /*!< Select AIN13 as the AD input port  */
  ADC_CHANNEL_14 = (uint8_t)0x0E,    /*!< Select AIN14 as the AD input port  */
  ADC_CHANNEL_15 = (uint8_t)0x0F,    /*!< Select AIN15 as the AD input port  */
	ADC_CHANNEL_16 = (uint8_t)0x10,  /*!< Select AIN16 as the AD input port  */
	ADC_CHANNEL_17 = (uint8_t)0x11,  /*!< Select AIN17 as the AD input port  */
	ADC_CHANNEL_18 = (uint8_t)0x12,  /*!< Select AIN18 as the AD input port  */
	ADC_CHANNEL_19 = (uint8_t)0x13,  /*!< Select AIN19 as the AD input port  */
	ADC_CHANNEL_20 = (uint8_t)0x14,  /*!< Select AIN20 as the AD input port  */
	ADC_CHANNEL_21 = (uint8_t)0x15,  /*!< Select AIN21 as the AD input port  */
	ADC_CHANNEL_OP = (uint8_t)0x1E,  /*!< Select OPout as the AD input port  */
  ADC_CHANNEL_VDD_D4 = (uint8_t)0x1f /*!< Select  1/4 VDD as the AD input port  */
} ADC_Channel_TypeDef;
#elif defined (SC92F663x)
typedef enum
{
  ADC_CHANNEL_0 = (uint8_t)0x00,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_1 = (uint8_t)0x01,     /*!< Select AIN1 as the AD input port  */
  ADC_CHANNEL_2 = (uint8_t)0x02,     /*!< Select AIN2 as the AD input port  */
  ADC_CHANNEL_3 = (uint8_t)0x03,     /*!< Select AIN3 as the AD input port  */
  ADC_CHANNEL_4 = (uint8_t)0x04,     /*!< Select AIN4 as the AD input port  */
  ADC_CHANNEL_5 = (uint8_t)0x05,     /*!< Select AIN5 as the AD input port  */
  ADC_CHANNEL_6 = (uint8_t)0x06,     /*!< Select AIN6 as the AD input port  */
  ADC_CHANNEL_7 = (uint8_t)0x07,     /*!< Select AIN7 as the AD input port  */
  ADC_CHANNEL_8 = (uint8_t)0x08,     /*!< Select AIN8 as the AD input port  */
  ADC_CHANNEL_VDD_D4 = (uint8_t)0x1f /*!< Select  1/4 VDD as the AD input port  */
} ADC_Channel_TypeDef;
#elif defined (SC92F563x)
typedef enum
{
  ADC_CHANNEL_0 = (uint8_t)0x00,     /*!< Select AIN0 as the AD input port  */
  ADC_CHANNEL_1 = (uint8_t)0x01,     /*!< Select AIN1 as the AD input port  */
  ADC_CHANNEL_2 = (uint8_t)0x02,     /*!< Select AIN2 as the AD input port  */
  ADC_CHANNEL_3 = (uint8_t)0x03,     /*!< Select AIN3 as the AD input port  */
  ADC_CHANNEL_4 = (uint8_t)0x04,     /*!< Select AIN4 as the AD input port  */
  ADC_CHANNEL_5 = (uint8_t)0x05,     /*!< Select AIN5 as the AD input port  */
  ADC_CHANNEL_6 = (uint8_t)0x06,     /*!< Select AIN6 as the AD input port  */
  ADC_CHANNEL_7 = (uint8_t)0x07,     /*!< Select AIN7 as the AD input port  */
  ADC_CHANNEL_8 = (uint8_t)0x08,     /*!< Select AIN8 as the AD input port  */
	ADC_CHANNEL_9 = (uint8_t)0x09,     /*!< Select AIN9 as the AD input port  */
  ADC_CHANNEL_10 = (uint8_t)0x0A,    /*!< Select AIN10 as the AD input port  */
  ADC_CHANNEL_11 = (uint8_t)0x0B,    /*!< Select AIN11 as the AD input port  */
  ADC_CHANNEL_12 = (uint8_t)0x0C,    /*!< Select AIN12 as the AD input port  */
  ADC_CHANNEL_13 = (uint8_t)0x0D,    /*!< Select AIN13 as the AD input port  */
  ADC_CHANNEL_14 = (uint8_t)0x0E,    /*!< Select AIN14 as the AD input port  */
  ADC_CHANNEL_15 = (uint8_t)0x0F,    /*!< Select AIN15 as the AD input port  */
	ADC_CHANNEL_16 = (uint8_t)0x10,    /*!< Select AIN16 as the AD input port  */
	ADC_CHANNEL_17 = (uint8_t)0x11,    /*!< Select AIN17 as the AD input port  */
	ADC_CHANNEL_18 = (uint8_t)0x12,    /*!< Select AIN18 as the AD input port  */
	ADC_CHANNEL_19 = (uint8_t)0x14,    /*!< Select AIN19 as the AD input port  */
	ADC_CHANNEL_20 = (uint8_t)0x15,    /*!< Select AIN20 as the AD input port  */
  ADC_CHANNEL_VDD_D4 = (uint8_t)0x1f /*!< Select  1/4 VDD as the AD input port  */
} ADC_Channel_TypeDef;
#endif
/**
 * @}
 */

/** @brief ADC_EAIN ADC Enable Input
 * @{
 */
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
		|| defined(SC92FWxx) || defined(SC92F859x) || defined(SC92F759x) || defined (SC92R511x)
typedef enum
{
  ADC_EAIN_0 = (uint16_t)0x0001,  /*!< Select AIN0  */
  ADC_EAIN_1 = (uint16_t)0x0002,  /*!< Select AIN1  */
  ADC_EAIN_2 = (uint16_t)0x0004,  /*!< Select AIN2  */
  ADC_EAIN_3 = (uint16_t)0x0008,  /*!< Select AIN3  */
  ADC_EAIN_4 = (uint16_t)0x0010,  /*!< Select AIN4  */
  ADC_EAIN_5 = (uint16_t)0x0020,  /*!< Select AIN5  */
  ADC_EAIN_6 = (uint16_t)0x0040,  /*!< Select AIN6  */
  ADC_EAIN_7 = (uint16_t)0x0080,  /*!< Select AIN7  */
  ADC_EAIN_8 = (uint16_t)0x0100,  /*!< Select AIN8  */
  ADC_EAIN_9 = (uint16_t)0x0200,  /*!< Select AIN9  */
  ADC_EAIN_10 = (uint16_t)0x0400, /*!< Select AIN10  */
  ADC_EAIN_11 = (uint16_t)0x0800, /*!< Select AIN11 */
  ADC_EAIN_12 = (uint16_t)0x1000, /*!< Select AIN12  */
  ADC_EAIN_13 = (uint16_t)0x2000, /*!< Select AIN13  */
  ADC_EAIN_14 = (uint16_t)0x4000, /*!< Select AIN14  */
  ADC_EAIN_15 = (uint16_t)0x8000  /*!< Select AIN15  */
} ADC_EAIN_TypeDef;
#elif defined (SC92F6x1x) || defined (SC92F5x1x) || defined(SC92R436) || defined(SC92R438)|| defined(SC92R439) || defined(SC92R422A) 
#define ADC_EAIN_0 0x00000001   /*!< Select AIN0  */
#define ADC_EAIN_1 0x00000002   /*!< Select AIN1  */
#define ADC_EAIN_2 0x00000004   /*!< Select AIN2  */
#define ADC_EAIN_3 0x00000008   /*!< Select AIN3  */
#define ADC_EAIN_4 0x00000010   /*!< Select AIN4  */
#define ADC_EAIN_5 0x00000020   /*!< Select AIN5  */
#define ADC_EAIN_6 0x00000040   /*!< Select AIN6  */
#define ADC_EAIN_7 0x00000080   /*!< Select AIN7  */
#define ADC_EAIN_8 0x00000100   /*!< Select AIN8  */
#define ADC_EAIN_9 0x00000200   /*!< Select AIN9  */
#define ADC_EAIN_10 0x00000400  /*!< Select AIN10  */
#define ADC_EAIN_11 0x00000800  /*!< Select AIN11  */
#define ADC_EAIN_12 0x00001000  /*!< Select AIN12  */
#define ADC_EAIN_13 0x00002000  /*!< Select AIN13  */
#define ADC_EAIN_14 0x00004000  /*!< Select AIN14  */
#define ADC_EAIN_15 0x00008000  /*!< Select AIN15  */
#define ADC_EAIN_16 0x00010000  /*!< Select AIN16  */
#define ADC_EAIN_17 0x00020000  /*!< Select AIN17  */
#define ADC_EAIN_18 0x00040000  /*!< Select AIN18  */
#define ADC_EAIN_19 0x00080000  /*!< Select AIN19  */
#define ADC_EAIN_20 0x00100000 /*!< Select AIN20  */
#define ADC_EAIN_21 0x00200000 /*!< Select AIN21  */
#define ADC_EAIN_22 0x00400000 /*!< Select AIN22  */
#define ADC_EAIN_23 0x00800000 /*!< Select AIN23  */
#define ADC_EAIN_24 0x01000000 /*!< Select AIN24  */
#define ADC_EAIN_25 0x02000000  /*!< Select AIN25  */

#elif defined (SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)
#define ADC_EAIN_0 0x00000001   /*!< Select AIN0  */
#define ADC_EAIN_1 0x00000002   /*!< Select AIN1  */
#define ADC_EAIN_2 0x00000004   /*!< Select AIN2  */
#define ADC_EAIN_3 0x00000008   /*!< Select AIN3  */
#define ADC_EAIN_4 0x00000010   /*!< Select AIN4  */
#define ADC_EAIN_5 0x00000020   /*!< Select AIN5  */
#define ADC_EAIN_6 0x00000040   /*!< Select AIN6  */
#define ADC_EAIN_7 0x00000080   /*!< Select AIN7  */
#define ADC_EAIN_8 0x00000100   /*!< Select AIN8  */
#define ADC_EAIN_9 0x00000200   /*!< Select AIN9  */
#define ADC_EAIN_10 0x00000400  /*!< Select AIN10  */
#define ADC_EAIN_11 0x00000800  /*!< Select AIN11  */
#define ADC_EAIN_12 0x00001000  /*!< Select AIN12  */
#define ADC_EAIN_13 0x00002000  /*!< Select AIN13  */
#define ADC_EAIN_14 0x00004000  /*!< Select AIN14  */
#define ADC_EAIN_15 0x00008000  /*!< Select AIN15  */
#define ADC_EAIN_16 0x00010000  /*!< Select AIN16  */
#define ADC_EAIN_17 0x00020000  /*!< Select AIN17  */
#define ADC_EAIN_18 0x00040000  /*!< Select AIN18  */
#define ADC_EAIN_19 0x00080000  /*!< Select AIN19  */
#define ADC_EAIN_20 0x00100000 /*!< Select AIN20  */
#define ADC_EAIN_21 0x00200000 /*!< Select AIN21  */
#define ADC_EAIN_22 0x00400000 /*!< Select AIN22  */
#define ADC_EAIN_23 0x00800000 /*!< Select AIN23  */
#define ADC_EAIN_24 0x01000000 /*!< Select AIN24  */
#define ADC_EAIN_25 0x02000000  /*!< Select AIN25  */
#define ADC_EAIN_26 0x04000000 /*!< Select AIN26  */
#define ADC_EAIN_27 0x08000000 /*!< Select AIN27  */
#define ADC_EAIN_28 0x10000000 /*!< Select AIN28  */
#define ADC_EAIN_29 0x20000000 /*!< Select AIN29  */
#define ADC_EAIN_30 0x40000000  /*!< Select AIN30  */

#elif defined(SC92F84Hx) || defined(SC92F83Hx)
#define ADC_EAIN_0 0x00000001   /*!< Select AIN0  */
#define ADC_EAIN_1 0x00000002   /*!< Select AIN1  */
#define ADC_EAIN_2 0x00000004   /*!< Select AIN2  */
#define ADC_EAIN_3 0x00000008   /*!< Select AIN3  */
#define ADC_EAIN_4 0x00000010   /*!< Select AIN4  */
#define ADC_EAIN_5 0x00000020   /*!< Select AIN5  */
#define ADC_EAIN_6 0x00000040   /*!< Select AIN6  */
#define ADC_EAIN_7 0x00000080   /*!< Select AIN7  */
#define ADC_EAIN_8 0x00000100   /*!< Select AIN8  */
#define ADC_EAIN_9 0x00000200   /*!< Select AIN9  */
#define ADC_EAIN_10 0x00000400  /*!< Select AIN10  */
#define ADC_EAIN_11 0x00000800  /*!< Select AIN11 */
#define ADC_EAIN_12 0x00001000  /*!< Select AIN12  */
#define ADC_EAIN_13 0x00002000  /*!< Select AIN13  */
#define ADC_EAIN_14 0x00004000  /*!< Select AIN14  */
#define ADC_EAIN_15 0x00008000  /*!< Select AIN15  */
#define ADC_EAIN_16 0x00010000  /*!< Select AIN16  */
#define ADC_EAIN_17 0x00020000  /*!< Select AIN17  */
#define ADC_EAIN_18 0x00040000  /*!< Select AIN18  */
#define ADC_EAIN_19 0x00080000  /*!< Select AIN19  */

#elif defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)
typedef enum
{
  ADC_EAIN_0 = (uint16_t)0x0001,  /*!< Select AIN0  */
  ADC_EAIN_1 = (uint16_t)0x0002,  /*!< Select AIN1  */
  ADC_EAIN_2 = (uint16_t)0x0004,  /*!< Select AIN2  */
  ADC_EAIN_3 = (uint16_t)0x0008,  /*!< Select AIN3  */
  ADC_EAIN_4 = (uint16_t)0x0010,  /*!< Select AIN4  */
  ADC_EAIN_5 = (uint16_t)0x0020,  /*!< Select AIN5  */
  ADC_EAIN_6 = (uint16_t)0x0040,  /*!< Select AIN6  */
  ADC_EAIN_7 = (uint16_t)0x0080,  /*!< Select AIN7  */
  ADC_EAIN_8 = (uint16_t)0x0100,  /*!< Select AIN8  */
  ADC_EAIN_9 = (uint16_t)0x0200,  /*!< Select AIN9  */
  ADC_EAIN_10 = (uint16_t)0x0400, /*!< Select AIN10  */
  ADC_EAIN_11 = (uint16_t)0x0800, /*!< Select AIN11  */
} ADC_EAIN_TypeDef;
#elif defined(SC92F7003) || defined(SC92F8003) || defined(SC92F8003B) || defined(SC92F740x)
typedef enum
{
  ADC_EAIN_0 = (uint16_t)0x0001, /*!< Select AIN0  */  
  ADC_EAIN_1 = (uint16_t)0x0002, /*!< Select AIN1  */
  ADC_EAIN_2 = (uint16_t)0x0004, /*!< Select AIN2  */
  ADC_EAIN_3 = (uint16_t)0x0008, /*!< Select AIN3  */
  ADC_EAIN_4 = (uint16_t)0x0010, /*!< Select AIN4  */
  ADC_EAIN_5 = (uint16_t)0x0020, /*!< Select AIN5  */
  ADC_EAIN_6 = (uint16_t)0x0040  /*!< Select AIN6  */
} ADC_EAIN_TypeDef;
#elif defined(SC92F846xB) || defined(SC92F746xB) || defined(SC92F836xB) || defined(SC92F736xB) || defined(SC92F83Ax)\
		|| defined(SC92F73Ax) || defined(SC92F84Ax) || defined(SC92F74Ax) || defined(SC92F742x) || defined(SC92F725X)\
		|| defined(SC92F735X) || defined(SC92F732X) || defined(SC93F833x) || defined(SC93F843x) || defined(SC93F743x)\
		|| defined(SC92F848x) || defined(SC92F748x) || defined (SC92L853x) || defined (SC92L753x) || defined (SC92R342)\
		|| defined (SC92F841x) || defined (SC92F741x) || defined (SC92L840x)|| defined (SC92Fx41xB)|| defined (SC92R445)
typedef enum
{
  ADC_EAIN_0 = (uint16_t)0x0001, /*!< Select AIN0  */
  ADC_EAIN_1 = (uint16_t)0x0002, /*!< Select AIN1  */
  ADC_EAIN_2 = (uint16_t)0x0004, /*!< Select AIN2  */
  ADC_EAIN_3 = (uint16_t)0x0008, /*!< Select AIN3  */
  ADC_EAIN_4 = (uint16_t)0x0010, /*!< Select AIN4  */
  ADC_EAIN_5 = (uint16_t)0x0020, /*!< Select AIN5  */
  ADC_EAIN_6 = (uint16_t)0x0040, /*!< Select AIN6  */
  ADC_EAIN_7 = (uint16_t)0x0080, /*!< Select AIN7  */
  ADC_EAIN_8 = (uint16_t)0x0100, /*!< Select AIN8  */
  ADC_EAIN_9 = (uint16_t)0x0200, /*!< Select AIN9  */
} ADC_EAIN_TypeDef;
#elif defined(SC92F730x) || defined (SC92F7308B)
typedef enum
{
  ADC_EAIN_0 = (uint16_t)0x0001, /*!< Select AIN0  */
  ADC_EAIN_1 = (uint16_t)0x0002, /*!< Select AIN1  */
  ADC_EAIN_6 = (uint16_t)0x0040, /*!< Select AIN6  */
  ADC_EAIN_7 = (uint16_t)0x0080, /*!< Select AIN7  */
} ADC_EAIN_TypeDef;
#elif defined(SC92F730x_2) || defined(SC92F720x)
typedef enum
{
  ADC_EAIN_0 = (uint16_t)0x0001, /*!< Select AIN0  */
  ADC_EAIN_1 = (uint16_t)0x0002, /*!< Select AIN1  */
  ADC_EAIN_4 = (uint16_t)0x0010, /*!< Select AIN4  */
  ADC_EAIN_5 = (uint16_t)0x0020, /*!< Select AIN5  */
  ADC_EAIN_6 = (uint16_t)0x0040, /*!< Select AIN6  */
  ADC_EAIN_7 = (uint16_t)0x0080, /*!< Select AIN7  */
  ADC_EAIN_8 = (uint16_t)0x0100, /*!< Select AIN8  */
  ADC_EAIN_9 = (uint16_t)0x0200, /*!< Select AIN9  */
} ADC_EAIN_TypeDef;
#elif defined(SC92F7490)
typedef enum
{
  ADC_EAIN_0 = (uint16_t)0x0001, /*!< Select AIN0  */
  ADC_EAIN_1 = (uint16_t)0x0002, /*!< Select AIN1  */
} ADC_EAIN_TypeDef;
#elif defined (SC92F5x5x)
#define ADC_EAIN_0 0x00000001   /*!< Select AIN0  */
#define ADC_EAIN_1 0x00000002   /*!< Select AIN1  */
#define ADC_EAIN_5 0x00000020   /*!< Select AIN5  */
#define ADC_EAIN_8 0x00000100   /*!< Select AIN8  */
#define ADC_EAIN_9 0x00000200   /*!< Select AIN9  */
#define ADC_EAIN_10 0x00000400  /*!< Select AIN10  */
#define ADC_EAIN_11 0x00000800  /*!< Select AIN11  */
#define ADC_EAIN_12 0x00001000  /*!< Select AIN12  */
#define ADC_EAIN_13 0x00002000  /*!< Select AIN13  */
#define ADC_EAIN_14 0x00004000  /*!< Select AIN14  */
#define ADC_EAIN_18 0x00040000  /*!< Select AIN18  */
#define ADC_EAIN_19 0x00080000  /*!< Select AIN19  */
#define ADC_EAIN_20 0x00100000 /*!< Select AIN20  */
#define ADC_EAIN_21 0x00200000 /*!< Select AIN21  */
#elif defined (SC92F531x)
#define ADC_EAIN_0 0x00000001   /*!< Select AIN0  */
#define ADC_EAIN_1 0x00000002   /*!< Select AIN1  */
#define ADC_EAIN_2 0x00000004   /*!< Select AIN2  */
#define ADC_EAIN_3 0x00000008   /*!< Select AIN3  */
#define ADC_EAIN_4 0x00000010   /*!< Select AIN4  */
#define ADC_EAIN_5 0x00000020   /*!< Select AIN5  */
#define ADC_EAIN_6 0x00000040   /*!< Select AIN6  */
#define ADC_EAIN_7 0x00000080   /*!< Select AIN7  */
#define ADC_EAIN_8 0x00000100   /*!< Select AIN8  */
#define ADC_EAIN_9 0x00000200   /*!< Select AIN9  */
#define ADC_EAIN_10 0x00000400  /*!< Select AIN10  */
#define ADC_EAIN_11 0x00000800  /*!< Select AIN11  */
#define ADC_EAIN_12 0x00001000  /*!< Select AIN12  */
#define ADC_EAIN_13 0x00002000  /*!< Select AIN13  */
#define ADC_EAIN_14 0x00004000  /*!< Select AIN14  */
#define ADC_EAIN_15 0x00008000  /*!< Select AIN15  */
#define ADC_EAIN_16 0x00010000  /*!< Select AIN16  */
#define ADC_EAIN_17 0x00020000  /*!< Select AIN17  */
#define ADC_EAIN_18 0x00040000  /*!< Select AIN18  */
#define ADC_EAIN_19 0x00080000  /*!< Select AIN19  */
#define ADC_EAIN_20 0x00100000 /*!< Select AIN20  */
#define ADC_EAIN_21 0x00200000 /*!< Select AIN21  */

#elif defined(SC92F663x)
typedef enum
{
  ADC_EAIN_0 = (uint16_t)0x0001, /*!< Select AIN0  */
  ADC_EAIN_1 = (uint16_t)0x0002, /*!< Select AIN1  */
  ADC_EAIN_2 = (uint16_t)0x0004, /*!< Select AIN2  */
  ADC_EAIN_3 = (uint16_t)0x0008, /*!< Select AIN3  */
  ADC_EAIN_4 = (uint16_t)0x0010, /*!< Select AIN4  */
  ADC_EAIN_5 = (uint16_t)0x0020, /*!< Select AIN5  */
  ADC_EAIN_6 = (uint16_t)0x0040, /*!< Select AIN6  */
  ADC_EAIN_7 = (uint16_t)0x0080, /*!< Select AIN7  */
  ADC_EAIN_8 = (uint16_t)0x0100, /*!< Select AIN8  */
} ADC_EAIN_TypeDef;

#elif defined (SC92F563x)
#define ADC_EAIN_0 0x00000001   /*!< Select AIN0  */
#define ADC_EAIN_1 0x00000002   /*!< Select AIN1  */
#define ADC_EAIN_2 0x00000004   /*!< Select AIN2  */
#define ADC_EAIN_3 0x00000008   /*!< Select AIN3  */
#define ADC_EAIN_4 0x00000010   /*!< Select AIN4  */
#define ADC_EAIN_5 0x00000020   /*!< Select AIN5  */
#define ADC_EAIN_6 0x00000040   /*!< Select AIN6  */
#define ADC_EAIN_7 0x00000080   /*!< Select AIN7  */
#define ADC_EAIN_8 0x00000100   /*!< Select AIN8  */
#define ADC_EAIN_9 0x00000200   /*!< Select AIN9  */
#define ADC_EAIN_10 0x00000400  /*!< Select AIN10  */
#define ADC_EAIN_11 0x00000800  /*!< Select AIN11  */
#define ADC_EAIN_12 0x00001000  /*!< Select AIN12  */
#define ADC_EAIN_13 0x00002000  /*!< Select AIN13  */
#define ADC_EAIN_14 0x00004000  /*!< Select AIN14  */
#define ADC_EAIN_15 0x00008000  /*!< Select AIN15  */
#define ADC_EAIN_16 0x00010000  /*!< Select AIN16  */
#define ADC_EAIN_17 0x00020000  /*!< Select AIN17  */
#define ADC_EAIN_18 0x00040000  /*!< Select AIN18  */
#define ADC_EAIN_19 0x00080000  /*!< Select AIN19  */
#define ADC_EAIN_20 0x00100000  /*!< Select AIN20  */
#endif

/**
 * @}
 */


/** @brief ADC_PGACOM_TypeDef PGA common-mode voltage
 * @{
 */
#if defined(SC93F833x) || defined(SC93F843x) || defined(SC93F743x)
typedef enum
{
  ADC_PGACOM_0V = 0x00,    /*!< The common mode voltage is 0V  */
  ADC_PGACOM_1_2V = 0x40,  /*!< The common mode voltage is 1.2V  */
} ADC_PGACOM_TypeDef;
/**
 * @}
 */

/** @brief ADC_PGAGAN_TypeDef PGA in-phase gain
 * @{
 */
typedef enum
{
  ADC_PGAGAN_NonInvert20 = 0x00,    /*!< The gain in-phase is 20, and the gain out-of-phase is 19 */
  ADC_PGAGAN_NonInvert100 = 0x20,   /*!< The gain in-phase is 100, and the gain out-of-phase is 99*/
} ADC_PGAGAN_TypeDef;
/**
 * @}
 */

/** @brief ADC_PGAIPT_TypeDef PGA phase
 * @{
 */
typedef enum
{
  ADC_PGAIPT_NonInvert = 0x00, /*!< in-phase input */
  ADC_PGAIPT_Invert = 0x10,   /*!< out-of-phase input */
} ADC_PGAIPT_TypeDef;
/**
 * @}
 */
#endif

/** @brief ADC_SamplesNum_TypeDef Average number of ADC conversion samples
 * @{
 */
typedef enum
{
	ADC_SamplesNum_FourTimes = 0x04,		     /*!< Sampling frequency is 4 times */
	ADC_SamplesNum_SixTimes = 0x06,				/*!< Sampling frequency is 6 times */
	ADC_SamplesNum_EightTimes = 0x08,			/*!< Sampling frequency is 8 times */
	ADC_SamplesNum_TenTimes = 0x0A,				/*!< Sampling frequency is 10 times */
} ADC_SamplesNum_TypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup ADC_Exported_Functions ADC Exported Functions
 * @{
 */

/*macro function********************************************************/
/**
 * @brief  ADC interrupt initialization.
 * @param  NewState[in]:Enable/Disable ADC Interrupt.
 *                     - DISABLE:Disable ADC interrupt.
 *                     - ENABLE:Enable ADC interrupt.
 * @param  Priority[in]:Select interrupt priority.
 *                     - LOW:low priority.
 *                     - HIGH:high priority.
 */
#define ADC_ITConfig(NewState,Priority)										\
					do{  																						\
							EADC = (bit)NewState;												\
							IPADC = (bit)Priority;											\
					}while(0)

 /**
 * @brief  Start an AD conversion.
 * @param  None
 * @retval None
 */                  
#define ADC_StartConversion() SET_BIT(ADCCON,0X40)

#if defined(SC93F833x) || defined(SC93F843x) || defined(SC93F743x)
/* temperature senor functions********************************************************/
void ADC_TSCmd(FunctionalState NewState);
void ADC_CHOPConfig(PriorityStatus NewState);
uint16_t ADC_Get_TS_StandardData(void);
float ADC_GetTSValue(void);
/* PGA-related functions ********************************************************/
void ADC_PGAConfig(ADC_PGACOM_TypeDef ADC_PGACOM, ADC_PGAGAN_TypeDef ADC_PGAGAN, ADC_PGAIPT_TypeDef ADC_PGAIPT);
void ADC_PGACmd(PriorityStatus NewState);
#endif

/* ADC Base functions ********************************************************/
void ADC_DeInit(void);
void ADC_Init(ADC_PresSel_TypeDef ADC_PrescalerSelection, ADC_Cycle_TypeDef ADC_Cycle);
void ADC_ChannelConfig(ADC_Channel_TypeDef ADC_Channel, FunctionalState NewState);
void ADC_Cmd(FunctionalState NewState);
unsigned int ADC_GetConversionValue(void);
uint16_t ADC_GetConversionAverageValue(ADC_SamplesNum_TypeDef ADC_SamplesNum);
FlagStatus ADC_GetFlagStatus(void);
void ADC_ClearFlag(void);
void ADC_EAINConfig(uint32_t ADC_EAIN_Select,
                    FunctionalState NewState);
void ADC_VrefConfig(ADC_Vref_TypeDef ADC_Vref);

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