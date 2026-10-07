/**
 ******************************************************************************
 * @file    sc92f_ddic.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of DDIC module.
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
#ifndef _sc92f_DDIC_H_
#define	_sc92f_DDIC_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
 /** @addtogroup DDIC
 * @{
 */

 /* Exported enumerations ------------------------------------------------------------*/
/** @defgroup DDIC_Exported_Enumerations ADC Exported Enumerations
 * @{
 */
 
 /** @brief DDIC_Pin_TypeDef DDIC Function
 * @{
 */
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
		|| defined(SC92F859x) || defined(SC92F759x) || defined (SC92L853x) || defined (SC92L753x) || defined (SC92R511x) ||defined(SC92F6x1x) \
		|| defined(SC92F5x1x) || defined(SC92R436)|| defined(SC92R438) || defined(SC92R439) || defined(SC92R422A) || defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)\
		|| defined (SC92F531x) || defined (SC92F663x) || defined(SC92F563x)
		
#if !defined(SC92F6x1x) && !defined(SC92F5x1x) && !defined(SC92R436) && !defined(SC92R438)&& !defined(SC92R439)&& !defined(SC92R422A)\
		&& !defined(SC92F531x)
#if !defined(SC92F652x) && !defined(SC92R51x_R52x) && !defined(SC92F552x) && !defined(SC92F663x) && !defined(SC92F563x)
typedef enum
{
  DDIC_PIN_X0    = ((uint8_t)0x01),	/*!< Px0口打开显示驱动功能 */
  DDIC_PIN_X1    = ((uint8_t)0x02),	/*!< Px1口打开显示驱动功能 */
  DDIC_PIN_X2    = ((uint8_t)0x04),	/*!< Px2口打开显示驱动功能 */
  DDIC_PIN_X3    = ((uint8_t)0x08),	/*!< Px3口打开显示驱动功能 */
  DDIC_PIN_X4    = ((uint8_t)0x10), /*!< Px4口打开显示驱动功能 */
  DDIC_PIN_X5    = ((uint8_t)0x20), /*!< Px5口打开显示驱动功能 */
  DDIC_PIN_X6    = ((uint8_t)0x40), /*!< Px6口打开显示驱动功能 */
  DDIC_PIN_X7    = ((uint8_t)0x80), /*!< Px8口打开显示驱动功能 */
} DDIC_Pin_TypeDef;
#endif
/**
 * @}
 */

 /** @brief DDIC_DutyCycle_TypeDef DDIC DutyCycle
 * @{
 */
typedef enum
{
  DDIC_DUTYCYCLE_D8 = (uint8_t)0x00, /*!< 1/8 duty cycle */
  DDIC_DUTYCYCLE_D6 = (uint8_t)0x10, /*!< 1/6 duty cycle */
  DDIC_DUTYCYCLE_D5 =	(uint8_t)0x20, /*!< 1/5 duty cycle */
  DDIC_DUTYCYCLE_D4 =	(uint8_t)0x30  /*!< 1/4 duty cycle */
} DDIC_DutyCycle_TypeDef;
/**
 * @}
 */

 /** @brief DDIC_ResSel_Typedef DDIC Internal voltage divider resistor
 * @{
 */
#if defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x) || defined (SC92F563x)
typedef enum
{
  DDIC_ResSel_11K	= (uint8_t)0X00,     /*!< 设定内部分压电阻为11k */
  DDIC_ResSel_100K	= (uint8_t)0X04,   /*!< 设定内部分压电阻为100k */
  DDIC_ResSel_300K	= (uint8_t)0X08,   /*!< 设定内部分压电阻为300k */
  DDIC_ResSel_800K	= (uint8_t)0X0C	   /*!< 设定内部分压电阻为800k */
} DDIC_ResSel_Typedef;
#else
typedef enum
{
  DDIC_ResSel_100K	= (uint8_t)0X00,   /*!< 设定内部分压电阻为100k */
  DDIC_ResSel_200K	= (uint8_t)0X04,   /*!< 设定内部分压电阻为200k */
  DDIC_ResSel_400K	= (uint8_t)0X08,   /*!< 设定内部分压电阻为400k */
  DDIC_ResSel_800K	= (uint8_t)0X0C	   /*!< 设定内部分压电阻为800k */
} DDIC_ResSel_Typedef;
#endif
/**
 * @}
 */

 /** @brief DDIC_BiasVoltage_Typedef DDIC BiasVoltage
 * @{
 */
typedef enum
{
  DDIC_BIAS_D3 = 0X01,	 /*!< LCD偏置电压为1/3 */
  DDIC_BIAS_D4 = 0X00	   /*!< LCD偏置电压为1/4 */
} DDIC_BiasVoltage_Typedef;
/**
 * @}
 */

 /** @brief DDIC_OutputPin_TypeDef DDIC OutputPin
 * @{
 */
#if defined (SC92L853x) || defined (SC92L753x) 
typedef enum
{
  SEG0_27COM4_7 = (uint8_t)0x01,   /*!< 1/4占空比时，S0-S27为segment，C4-C7为common */
  SEG4_27COM0_3 = (uint8_t)0x00	   /*!< 1/4占空比时，S4-S27为segment，C0-C3为common */
} DDIC_OutputPin_TypeDef;
#elif defined (SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)
typedef enum
{
  SEG4_15COM0_7 = (uint8_t)0x00,   /*!< S4-S11为segment，C0-C7为common */
  SEG2_15COM2_7 = (uint8_t)0x10,   /*!< S2-S11为segment，C2-C7为common */
  SEG1_15COM3_7 = (uint8_t)0x20,   /*!< S1-S11为segment，C3-C7为common */
  SEG0_15COM4_7 = (uint8_t)0x30	   /*!< S0-S11为segment，C4-C7为common */
} DDIC_OutputPin_TypeDef;
#elif defined (SC92F663x)
typedef enum
{
  SEG0_15COM0_7 = (uint8_t)0x00,   /*!< S0-S15为segment，C0-C7为common */
  SEG0_15COM2_7 = (uint8_t)0x10,   /*!< S0-S15为segment，C2-C7为common */
  SEG0_15COM3_7 = (uint8_t)0x20,   /*!< S0-S15为segment，C3-C7为common */
  SEG0_15COM4_7 = (uint8_t)0x30	   /*!< S0-S15为segment，C4-C7为common */
} DDIC_OutputPin_TypeDef;
#elif defined (SC92F563x)
typedef enum
{
  SEG0_23COM0_7 = (uint8_t)0x00,   /*!< S0-S23为segment，C0-C7为common */
  SEG0_25COM0_5 = (uint8_t)0x10,   /*!< S0-S25为segment，C0-C5为common */
  SEG0_26COM0_4 = (uint8_t)0x20,   /*!< S0-S26为segment，C0-C4为common */
  SEG0_27COM0_3 = (uint8_t)0x30	   /*!< S0-S27为segment，C0-C3为common */
} DDIC_OutputPin_TypeDef;
#else
typedef enum
{
  SEG0_27COM4_7 = (uint8_t)0x00,   /*!< 1/4占空比时，S0-S27为segment，C4-C7为common */
  SEG4_27COM0_3 = (uint8_t)0x01	   /*!< 1/4占空比时，S4-S27为segment，C0-C3为common */
} DDIC_OutputPin_TypeDef;

#endif
/**
 * @}
 */

 /** @brief DDIC_DMOD_TypeDef DDIC MODE
 * @{
 */
#if !defined(SC92F663x)
#if defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x) || defined (SC92F563x)
typedef enum
{
  DMOD_LED = (uint8_t)0x00,	    /*!< LED模式 */
  DMOD_LCD = (uint8_t)0x40     	/*!< LCD模式 */
} DDIC_LMOD_TypeDef;
#else
typedef enum
{
  DMOD_LCD = (uint8_t)0x00,	    /*!< LCD模式 */
  DMOD_LED = (uint8_t)0x01   	  /*!< LED模式 */
} DDIC_DMOD_TypeDef;
#endif
#endif
/**
 * @}
 */

/** @brief DDIC_DMOD_TypeDef DDIC MODE
 * @{
 */
#if defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x) || defined (SC92F663x) || defined (SC92F563x)
typedef enum
{
  DMOD_Normal = (uint8_t)0x00,	    /*!< Normal模式 */
  DMOD_ForBack = (uint8_t)0x40   	/*!< 正反推模式 */
} DDIC_DMOD_TypeDef;
#endif
/**
 * @}
 */

 /** @brief DDIC_Control_SEG_TypeDef DDIC Segment
 * @{
 */
#if defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F663x)
typedef enum
{
  DDIC_SEG0 = ((uint16_t)0x0001),  /*!< SEG0 */
  DDIC_SEG1 = ((uint16_t)0x0002),  /*!< SEG1 */
  DDIC_SEG2 = ((uint16_t)0x0004),  /*!< SEG2 */
  DDIC_SEG3 = ((uint16_t)0x0008),  /*!< SEG3 */
  DDIC_SEG4 = ((uint16_t)0x0010),  /*!< SEG4 */
  DDIC_SEG5 = ((uint16_t)0x0020),  /*!< SEG5 */
  DDIC_SEG6 = ((uint16_t)0x0040),  /*!< SEG6 */
  DDIC_SEG7 = ((uint16_t)0x0080),  /*!< SEG7 */
  DDIC_SEG8 = ((uint16_t)0x0100),  /*!< SEG8 */
  DDIC_SEG9 = ((uint16_t)0x0200),  /*!< SEG9 */
  DDIC_SEG10 = ((uint16_t)0x0400), /*!< SEG10 */
  DDIC_SEG11 = ((uint16_t)0x0800), /*!< SEG11 */
  DDIC_SEG12 = ((uint16_t)0x1000), /*!< SEG12 */
  DDIC_SEG13 = ((uint16_t)0x2000), /*!< SEG13 */
  DDIC_SEG14 = ((uint16_t)0x4000), /*!< SEG14 */
  DDIC_SEG15 = ((uint16_t)0x8000), /*!< SEG15 */
} DDIC_Control_SEG_TypeDef;
#else
typedef enum
{
  DDIC_SEG0 = (uint8_t)0,  /*!< SEG0 */
  DDIC_SEG1 = (uint8_t)1,  /*!< SEG1 */
  DDIC_SEG2 = (uint8_t)2,  /*!< SEG2 */
  DDIC_SEG3 = (uint8_t)3,  /*!< SEG3 */
  DDIC_SEG4 = (uint8_t)4,  /*!< SEG4 */
  DDIC_SEG5 = (uint8_t)5,  /*!< SEG5 */
  DDIC_SEG6 = (uint8_t)6,  /*!< SEG6 */
  DDIC_SEG7 = (uint8_t)7,  /*!< SEG7 */
  DDIC_SEG8 = (uint8_t)8,  /*!< SEG8 */
  DDIC_SEG9 = (uint8_t)9,  /*!< SEG9 */
  DDIC_SEG10 = (uint8_t)10, /*!< SEG10 */
  DDIC_SEG11 = (uint8_t)11, /*!< SEG11 */
  DDIC_SEG12 = (uint8_t)12, /*!< SEG12 */
  DDIC_SEG13 = (uint8_t)13, /*!< SEG13 */
  DDIC_SEG14 = (uint8_t)14, /*!< SEG14 */
  DDIC_SEG15 = (uint8_t)15, /*!< SEG15 */
  DDIC_SEG16 = (uint8_t)16, /*!< SEG16 */
  DDIC_SEG17 = (uint8_t)17, /*!< SEG17 */
  DDIC_SEG18 = (uint8_t)18, /*!< SEG18 */
  DDIC_SEG19 = (uint8_t)19, /*!< SEG19 */
  DDIC_SEG20 = (uint8_t)20, /*!< SEG20 */
  DDIC_SEG21 = (uint8_t)21, /*!< SEG21 */
  DDIC_SEG22 = (uint8_t)22, /*!< SEG22 */
  DDIC_SEG23 = (uint8_t)23, /*!< SEG23 */
  DDIC_SEG24 = (uint8_t)24, /*!< SEG24 */
  DDIC_SEG25 = (uint8_t)25, /*!< SEG25 */
  DDIC_SEG26 = (uint8_t)26, /*!< SEG26 */
  DDIC_SEG27 = (uint8_t)27, /*!< SEG27 */
} DDIC_Control_SEG_TypeDef;
#endif
/**
 * @}
 */

 /** @brief DDIC_Control_COM_TypeDef DDIC Common
 * @{
 */
#if defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F663x) || defined(SC92F563x)
typedef enum
{
  DDIC_COM0 = (uint8_t)0,	    /*!< COM0 */
  DDIC_COM1 = (uint8_t)1,   	/*!< COM1 */
  DDIC_COM2 = (uint8_t)2,   	/*!< COM2 */
  DDIC_COM3 = (uint8_t)3,   	/*!< COM3 */
  DDIC_COM4 = (uint8_t)4,   	/*!< COM4 */
  DDIC_COM5 = (uint8_t)5,   	/*!< COM5 */
  DDIC_COM6 = (uint8_t)6,   	/*!< COM6 */
  DDIC_COM7 = (uint8_t)7     	/*!< COM7 */
} DDIC_Control_COM_TypeDef;
#else
typedef enum
{
  DDIC_COM0 = (uint8_t)0x01,	/*!< COM0 */
  DDIC_COM1 = (uint8_t)0x02,   	/*!< COM1 */
  DDIC_COM2 = (uint8_t)0x04,   	/*!< COM2 */
  DDIC_COM3 = (uint8_t)0x08,   	/*!< COM3 */
  DDIC_COM4 = (uint8_t)0x10,   	/*!< COM4 */
  DDIC_COM5 = (uint8_t)0x20,   	/*!< COM5 */
  DDIC_COM6 = (uint8_t)0x40,   	/*!< COM6 */
  DDIC_COM7 = (uint8_t)0x80   	/*!< COM7 */
} DDIC_Control_COM_TypeDef;
#endif
/**
 * @}
 */

 /** @brief DDIC_Control_Status DDIC Control Status
 * @{
 */
typedef enum
{
  DDIC_Control_ON  = (uint8_t)0x01, /*!< 点亮 */
  DDIC_Control_OFF = (uint8_t)0x00	/*!< 熄灭 */
} DDIC_Control_Status;
/**
 * @}
 */

 /** @brief DDIC_CK_TypeDef DDIC LED and LCD Clock division
 * @{
 */
#if defined (SC92F563x)
typedef enum
{
  Fsys_8182_or_16 = (uint8_t)0x00,	    /*!< Fsys/8182*/
  Fsys_16384_or_32 = (uint8_t)0x01,   	/*!< Fsys/16384*/
  Fsys_32768_or_64 = (uint8_t)0x02,	    /*!< Fsys/32768*/
  Fsys_65536_or_128 = (uint8_t)0x03,  	    /*!< Fsys/65536*/
} DDIC_CK_TypeDef;
#else
typedef enum
{
  Fsys_4096_or_16 = (uint8_t)0x00,	    /*!< Fsys/4096*/
  Fsys_8192_or_32 = (uint8_t)0x01,   	/*!< Fsys/8192*/
  Fsys_16384_or_64 = (uint8_t)0x02,	    /*!< Fsys/16384*/
  Fsys_32768_or_128 = (uint8_t)0x03,  	    /*!< Fsys/32768*/
} DDIC_CK_TypeDef;
#endif
/**
 * @}
 */

 /** @brief DDIC_CK_TypeDef DDIC LED and LCD Clock division
 * @{
 */
#if defined(SC92F663x)
typedef enum
{
  Source_Fsys = (uint8_t)0x00,	    /*!< Fsys*/
} DDIC_ClockSource_TypeDef;
#else
typedef enum
{
  Source_Fsys = (uint8_t)0x00,	    /*!< Fsys*/
  Source_32K = (uint8_t)0x80,   	  /*!< Internal 32K or external 32.768K*/
} DDIC_ClockSource_TypeDef;
#endif
/**
 * @}
 */

#if defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x) || defined (SC92F663x) || defined(SC92F563x)
 /** @brief DDIC_DRIV_TypeDef DDIC Constant current source size
 * @{
 */
#if !defined(SC92F563x)
typedef enum
{
  LED_DRIV0 = (uint8_t)0x00,	/*!< 1级亮度 */
  LED_DRIV1 = (uint8_t)0x01,   	/*!< 2级亮度 */
  LED_DRIV2 = (uint8_t)0x02,	/*!< 3级亮度 */
  LED_DRIV3 = (uint8_t)0x03,  	/*!< 4级亮度 */
  LED_DRIV4 = (uint8_t)0x04,	/*!< 5级亮度 */
  LED_DRIV5 = (uint8_t)0x05,   	/*!< 6级亮度 */
  LED_DRIV6 = (uint8_t)0x06,	/*!< 7级亮度 */
  LED_DRIV7 = (uint8_t)0x07,  	/*!< 8级亮度 */
  LED_DRIV8 = (uint8_t)0x08,	/*!< 9级亮度 */
  LED_DRIV9 = (uint8_t)0x09,   	/*!< 10级亮度 */
  LED_DRIV10 = (uint8_t)0x0A,	/*!< 11级亮度 */
  LED_DRIV11 = (uint8_t)0x0B,  	/*!< 12级亮度 */
  LED_DRIV12 = (uint8_t)0x0C,	/*!< 13级亮度 */
  LED_DRIV13 = (uint8_t)0x0D,   /*!< 14级亮度 */
  LED_DRIV14 = (uint8_t)0x0E,	/*!< 15级亮度 */
  LED_DRIV15 = (uint8_t)0x0F  	/*!< 16级亮度 */
} DDIC_DRIV_TypeDef;
#endif
/**
 * @}
 */

 /** @brief DDIC_Control_Status DDIC Control Status
 * @{
 */
typedef uint32_t DDIC_Pin_TypeDef;

#define DDIC_LED0    ((DDIC_Pin_TypeDef)0x00000001UL)  /*!< LED0口打开显示驱动功能 */
#define DDIC_LED1    ((DDIC_Pin_TypeDef)0x00000002UL)  /*!< LED1口打开显示驱动功能 */
#define DDIC_LED2    ((DDIC_Pin_TypeDef)0x00000004UL)  /*!< LED2口打开显示驱动功能 */
#define DDIC_LED3    ((DDIC_Pin_TypeDef)0x00000008UL)  /*!< LED3口打开显示驱动功能 */
#define DDIC_LED4    ((DDIC_Pin_TypeDef)0x00000010UL)  /*!< LED4口打开显示驱动功能 */
#define DDIC_LED5    ((DDIC_Pin_TypeDef)0x00000020UL)  /*!< LED5口打开显示驱动功能 */
#define DDIC_LED6    ((DDIC_Pin_TypeDef)0x00000040UL)  /*!< LED6口打开显示驱动功能 */
#define DDIC_LED7    ((DDIC_Pin_TypeDef)0x00000080UL)  /*!< LED7口打开显示驱动功能 */
#define DDIC_LED8    ((DDIC_Pin_TypeDef)0x00000100UL)  /*!< LED8口打开显示驱动功能 */
#define DDIC_LED9    ((DDIC_Pin_TypeDef)0x00000200UL)  /*!< LED9口打开显示驱动功能 */
#define DDIC_LED10   ((DDIC_Pin_TypeDef)0x00000400UL)  /*!< LED10口打开显示驱动功能 */
#define DDIC_LED11   ((DDIC_Pin_TypeDef)0x00000800UL)  /*!< LED11口打开显示驱动功能 */
#define DDIC_LED12   ((DDIC_Pin_TypeDef)0x00001000UL)  /*!< LED12口打开显示驱动功能 */
#define DDIC_LED13   ((DDIC_Pin_TypeDef)0x00002000UL)  /*!< LED13口打开显示驱动功能 */
#define DDIC_LED14   ((DDIC_Pin_TypeDef)0x00004000UL)  /*!< LED14口打开显示驱动功能 */
#define DDIC_LED15   ((DDIC_Pin_TypeDef)0x00008000UL)  /*!< LED15口打开显示驱动功能 */
#define DDIC_LED16   ((DDIC_Pin_TypeDef)0x00010000UL)  /*!< LED16口打开显示驱动功能 */
#define DDIC_LED17   ((DDIC_Pin_TypeDef)0x00020000UL)  /*!< LED17口打开显示驱动功能 */
#define DDIC_LED18   ((DDIC_Pin_TypeDef)0x00040000UL)  /*!< LED18口打开显示驱动功能 */
#define DDIC_LED19   ((DDIC_Pin_TypeDef)0x00080000UL)  /*!< LED19口打开显示驱动功能 */
#if defined(SC92F663x)
#define DDIC_LED20   ((DDIC_Pin_TypeDef)0x00100000UL)  /*!< LED20口打开显示驱动功能 */
#define DDIC_LED21   ((DDIC_Pin_TypeDef)0x00200000UL)  /*!< LED21口打开显示驱动功能 */
#define DDIC_LED22   ((DDIC_Pin_TypeDef)0x00400000UL)  /*!< LED22口打开显示驱动功能 */
#define DDIC_LED23   ((DDIC_Pin_TypeDef)0x00800000UL)  /*!< LED23口打开显示驱动功能 */
#elif defined(SC92F563x)
#define DDIC_LED20   ((DDIC_Pin_TypeDef)0x00100000UL)  /*!< LED20口打开显示驱动功能 */
#define DDIC_LED21   ((DDIC_Pin_TypeDef)0x00200000UL)  /*!< LED21口打开显示驱动功能 */
#define DDIC_LED22   ((DDIC_Pin_TypeDef)0x00400000UL)  /*!< LED22口打开显示驱动功能 */
#define DDIC_LED23   ((DDIC_Pin_TypeDef)0x00800000UL)  /*!< LED23口打开显示驱动功能 */
#define DDIC_LED24   ((DDIC_Pin_TypeDef)0x01000000UL)  /*!< LED24口打开显示驱动功能 */
#define DDIC_LED25   ((DDIC_Pin_TypeDef)0x02000000UL)  /*!< LED25口打开显示驱动功能 */
#define DDIC_LED26   ((DDIC_Pin_TypeDef)0x04000000UL)  /*!< LED26口打开显示驱动功能 */
#define DDIC_LED27   ((DDIC_Pin_TypeDef)0x08000000UL)  /*!< LED27口打开显示驱动功能 */
#endif
/**
 * @}
 */

 /** @brief DDIC_LEDXT_TypeDef LED specific scanning port time
 * @{
 */
typedef enum
{
  LED_0_5T = (uint8_t)0x00,	    /*!< 0.5T */
  LED_1T = (uint8_t)0x10,   	  /*!< 1T */
  LED_1_5T = (uint8_t)0x20,	    /*!< 1.5T */
  LED_2T = (uint8_t)0x30,  	    /*!< 2T */
} DDIC_LEDXT_TypeDef;
/**
 * @}
 */

 /** @brief DDIC_LEDEL_TypeDef DDIC LED special port
 * @{
 */
#if defined(SC92F663x) || defined (SC92F563x)
typedef enum
{
  LED0 = (uint8_t)0x00,	    /*!< LED0*/
  LED1 = (uint8_t)0x04,   	/*!< LED1*/
  LED2 = (uint8_t)0x08,	    /*!< LED2*/
  LED3 = (uint8_t)0x0C,  	  /*!< LED3*/
} DDIC_LEDEL_TypeDef;
#else
typedef enum
{
  LED0 = (uint8_t)0x00,	    /*!< LED0*/
  LED1 = (uint8_t)0x04,   	/*!< LED1*/
  LED8 = (uint8_t)0x08,	    /*!< LED8*/
  LED9 = (uint8_t)0x0C,  	  /*!< LED9*/
} DDIC_LEDEL_TypeDef;
#endif
/**
 * @}
 */

 /** @brief DDIC_LEDCK_TypeDef DDIC LED Clock division
 * @{
 */
typedef enum
{
  LED_Fsys_8182 = (uint8_t)0x00,	    /*!< Fsys/8182*/
  LED_Fsys_16384 = (uint8_t)0x01,   	/*!< Fsys/16384*/
  LED_Fsys_32768 = (uint8_t)0x02,	    /*!< Fsys/32768*/
  LED_Fsys_65536 = (uint8_t)0x03,  	  /*!< Fsys/65536*/
} DDIC_LEDCK_TypeDef;
/**
 * @}
 */

/** @brief DDIC_Flag_TypeDef DDIC Flag
 * @{
 */
typedef enum
{
  LED_Flag_AUIF = (uint8_t)0x80,	    /*!< AUIF */
	
} DDIC_Flag_TypeDef;
/**
 * @}
 */
#endif

#else

 /** @brief DDIC_Control_Status DDIC Control Status
 * @{
 */
typedef enum
{
  DDIC_LED0    = ((uint16_t)0x0001),	/*!< LED0口打开显示驱动功能 */
  DDIC_LED1    = ((uint16_t)0x0002),	/*!< LED1口打开显示驱动功能 */
  DDIC_LED2    = ((uint16_t)0x0004),	/*!< LED2口打开显示驱动功能 */
  DDIC_LED3    = ((uint16_t)0x0008),	/*!< LED3口打开显示驱动功能 */
  DDIC_LED4    = ((uint16_t)0x0010), 	/*!< LED4口打开显示驱动功能 */
  DDIC_LED5    = ((uint16_t)0x0020), 	/*!< LED5口打开显示驱动功能 */
  DDIC_LED6    = ((uint16_t)0x0040), 	/*!< LED6口打开显示驱动功能 */
  DDIC_LED7    = ((uint16_t)0x0080), 	/*!< LED7口打开显示驱动功能 */
#if !defined (SC92F531x)
  DDIC_LED8    = ((uint16_t)0x0100),	/*!< LED8口打开显示驱动功能 */
  DDIC_LED9    = ((uint16_t)0x0200),	/*!< LED9口打开显示驱动功能 */
  DDIC_LED10    = ((uint16_t)0x0400),	/*!< LED10口打开显示驱动功能 */
  DDIC_LED11    = ((uint16_t)0x0800),	/*!< LED11口打开显示驱动功能 */
  DDIC_LED12    = ((uint16_t)0x1000), 	/*!< LED12口打开显示驱动功能 */
  DDIC_LED13    = ((uint16_t)0x2000), 	/*!< LED13口打开显示驱动功能 */
  DDIC_LED14    = ((uint16_t)0x4000), 	/*!< LED14口打开显示驱动功能 */
  DDIC_LED15    = ((uint16_t)0x8000), 	/*!< LED15口打开显示驱动功能 */
#endif
} DDIC_Pin_TypeDef;
/**
 * @}
 */

 /** @brief DDIC_Control_Status DDIC Control Status
 * @{
 */
#if defined (SC92F531x)
typedef enum
{
  DDIC_Control_ON  = (uint8_t)0x01, /*!< 点亮 */
  DDIC_Control_OFF = (uint8_t)0x00	/*!< 熄灭 */
} DDIC_Control_Status;
#endif
/**
 * @}
 */

 /** @brief DDIC_OutputPin_TypeDef DDIC OutputPin
 * @{
 */
#if defined (SC92F531x)
typedef enum
{
  None = (uint8_t)0xFF	   /*!< 无设置 */
} DDIC_OutputPin_TypeDef;
#else
typedef enum
{
  SEG4_11COM0_7 = (uint8_t)0x00,   /*!< S4-S11为segment，C0-C7为common */
  SEG2_11COM2_7 = (uint8_t)0x10,   /*!< S2-S11为segment，C2-C7为common */
  SEG1_11COM3_7 = (uint8_t)0x20,   /*!< S1-S11为segment，C3-C7为common */
  SEG0_11COM4_7 = (uint8_t)0x30	   /*!< S0-S11为segment，C4-C7为common */
} DDIC_OutputPin_TypeDef;
#endif
/**
 * @}
 */

 /** @brief DDIC_DMOD_TypeDef DDIC Mode
 * @{
 */
#if !defined (SC92F531x)
typedef enum
{
  DMOD_Normal = (uint8_t)0x00,	    /*!< Normal模式 */
  DMOD_ForBack = (uint8_t)0x40   	/*!< 正反推模式 */
} DDIC_DMOD_TypeDef;
#endif
/**
 * @}
 */

 /** @brief DDIC_DRIV_TypeDef DDIC Constant current source size
 * @{
 */
typedef enum
{
  LED_DRIV0 = (uint8_t)0x00,	/*!< 1级亮度 */
  LED_DRIV1 = (uint8_t)0x01,   	/*!< 2级亮度 */
  LED_DRIV2 = (uint8_t)0x02,	/*!< 3级亮度 */
  LED_DRIV3 = (uint8_t)0x03,  	/*!< 4级亮度 */
  LED_DRIV4 = (uint8_t)0x04,	/*!< 5级亮度 */
  LED_DRIV5 = (uint8_t)0x05,   	/*!< 6级亮度 */
  LED_DRIV6 = (uint8_t)0x06,	/*!< 7级亮度 */
  LED_DRIV7 = (uint8_t)0x07,  	/*!< 8级亮度 */
  LED_DRIV8 = (uint8_t)0x08,	/*!< 9级亮度 */
  LED_DRIV9 = (uint8_t)0x09,   	/*!< 10级亮度 */
  LED_DRIV10 = (uint8_t)0x0A,	/*!< 11级亮度 */
  LED_DRIV11 = (uint8_t)0x0B,  	/*!< 12级亮度 */
  LED_DRIV12 = (uint8_t)0x0C,	/*!< 13级亮度 */
  LED_DRIV13 = (uint8_t)0x0D,   /*!< 14级亮度 */
  LED_DRIV14 = (uint8_t)0x0E,	/*!< 15级亮度 */
  LED_DRIV15 = (uint8_t)0x0F  	/*!< 16级亮度 */
} DDIC_DRIV_TypeDef;
/**
 * @}
 */

 /** @brief DDIC_LEDXT_TypeDef LED specific scanning port time
 * @{
 */
typedef enum
{
  LED_0_5T = (uint8_t)0x00,	    /*!< 0.5T */
  LED_1T = (uint8_t)0x10,   	  /*!< 1T */
  LED_1_5T = (uint8_t)0x20,	    /*!< 1.5T */
  LED_2T = (uint8_t)0x30,  	    /*!< 2T */
} DDIC_LEDXT_TypeDef;
/**
 * @}
 */

 /** @brief DDIC_LEDEL_TypeDef DDIC LED special port
 * @{
 */
#if defined (SC92F531x)
typedef enum
{
  LED0 = (uint8_t)0x00,	    /*!< LED0*/
  LED1 = (uint8_t)0x04,   	/*!< LED1*/
  LED6 = (uint8_t)0x08,	    /*!< LED6*/
  LED7 = (uint8_t)0x0C,  	  /*!< LED7*/
} DDIC_LEDEL_TypeDef;
#else
typedef enum
{
  LED0 = (uint8_t)0x00,	    /*!< LED0*/
  LED1 = (uint8_t)0x04,   	/*!< LED1*/
  LED8 = (uint8_t)0x08,	    /*!< LED8*/
  LED9 = (uint8_t)0x0C,  	/*!< LED9*/
} DDIC_LEDEL_TypeDef;
#endif
/**
 * @}
 */

 /** @brief DDIC_LEDCK_TypeDef DDIC LED Clock division
 * @{
 */
#if defined (SC92F531x)
typedef enum
{
  LED_Fsys_4096_or_16 = (uint8_t)0x00,	    /*!< Fsys/4096*/
  LED_Fsys_8192_or_32 = (uint8_t)0x01,   	/*!< Fsys/8192*/
  LED_Fsys_16384_or_64 = (uint8_t)0x02,	    /*!< Fsys/16384*/
  LED_Fsys_32768_or_128 = (uint8_t)0x03,  	    /*!< Fsys/32768*/
} DDIC_LEDCK_TypeDef;
#else
typedef enum
{
  LED_Fsys_8182 = (uint8_t)0x00,	    /*!< Fsys/8182*/
  LED_Fsys_16384 = (uint8_t)0x01,   	/*!< Fsys/16384*/
  LED_Fsys_32768 = (uint8_t)0x02,	    /*!< Fsys/32768*/
  LED_Fsys_65536 = (uint8_t)0x03,  	    /*!< Fsys/65536*/
} DDIC_LEDCK_TypeDef;
#endif
/**
 * @}
 */

 /** @brief DDIC_CK_TypeDef DDIC LED and LCD Clock division
 * @{
 */
typedef enum
{
  Fsys_4096_or_16 = (uint8_t)0x00,	    /*!< Fsys/4096*/
  Fsys_8192_or_32 = (uint8_t)0x01,   	/*!< Fsys/8192*/
  Fsys_16384_or_64 = (uint8_t)0x02,	    /*!< Fsys/16384*/
  Fsys_32768_or_128 = (uint8_t)0x03,  	    /*!< Fsys/32768*/
} DDIC_CK_TypeDef;
/**
 * @}
 */

 /** @brief DDIC_CK_TypeDef DDIC LED and LCD Clock division
 * @{
 */
typedef enum
{
  Source_Fsys = (uint8_t)0x00,	    /*!< Fsys*/
  Source_32K = (uint8_t)0x80,   	  /*!< Internal 32K or external 32.768K*/
} DDIC_ClockSource_TypeDef;
/**
 * @}
 */

 /** @brief DDIC_Flag_TypeDef DDIC Flag
 * @{
 */
typedef enum
{
  LED_Flag_AUIF = (uint8_t)0x80,	    /*!< AUIF */
	
} DDIC_Flag_TypeDef;
/**
 * @}
 */
#endif

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

#if defined (SC92L853x) || defined (SC92L753x)
extern uint8_t xdata LCDRAM[30] ;
#elif defined(SC92F6x1x) || defined(SC92F5x1x)|| defined(SC92R436)|| defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)
extern uint8_t xdata LEDRAM[24] ;
#elif defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)
extern uint8_t xdata LED_LCDRAM[24] ;
#elif defined(SC92F531x)
extern uint8_t xdata LEDRAM[8];
#elif defined(SC92F663x)
extern uint8_t xdata LEDRAM[16];
#elif defined(SC92F563x)
extern uint8_t xdata LED_LCDRAM[32];
#else
extern uint8_t xdata LCDRAM[30] ;
#endif

/** @addtogroup GPIO_Exported_Functions
 * @{
 */
 /* Initialization and de-initialization functions *****************************/
void DDIC_DeInit(void);

#if !defined(SC92F6x1x) && !defined(SC92F5x1x)&& !defined(SC92R436)&& !defined(SC92R438)&& !defined(SC92R439)&& !defined(SC92R422A)
#if defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F663x)
void DDIC_Init(DDIC_DutyCycle_TypeDef DDIC_DutyCylce,
               uint8_t P0OutputPin, uint8_t P1OutputPin,
               uint8_t P2OutputPin);
#elif defined(SC92F531x)
void DDIC_Init(uint8_t P0OutputPin);
#else
void DDIC_Init(DDIC_DutyCycle_TypeDef DDIC_DutyCylce,
               uint8_t P0OutputPin, uint8_t P1OutputPin,
               uint8_t P2OutputPin, uint8_t P3OutputPin);
#endif
/* DDIC operation functions *****************************************************/
#if !defined(SC92F531x) && !defined(SC92F663x)
void DDIC_LEDDrivingModeConfig(void);
void DDIC_LCDConfig(uint8_t LCDVoltage,
                    DDIC_ResSel_Typedef DDIC_ResSel,
                    DDIC_BiasVoltage_Typedef DDIC_BiasVoltage);
#endif
#if defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F563x)
void DDIC_LCDClockConfig(DDIC_ClockSource_TypeDef Clock_Source,
                         DDIC_CK_TypeDef Clock_Division);
#endif
#if defined(SC92F531x)
void DDIC_LEDClockConfig(DDIC_ClockSource_TypeDef Clock_Source);
#endif
#if defined(SC92F663x)
void DDIC_LEDClockConfig(DDIC_ClockSource_TypeDef Clock_Source,
                         DDIC_CK_TypeDef Clock_Division);
#endif
#if !defined(SC92F531x) && !defined(SC92F663x)
void DDIC_DMOD_Selcet(DDIC_DMOD_TypeDef DDIC_DMOD);
#endif
#if !defined(SC92F652x)&& !defined(SC92R51x_R52x) && !defined(SC92F552x)&& !defined(SC92F531x) && !defined(SC92F663x) && !defined(SC92F563x)
void DDIC_OutputPinOfDutycycleD4(DDIC_OutputPin_TypeDef DDIC_OutputPin);
#endif
#if defined(SC92F531x)
void DDIC_Control(uint8_t OutputPin,
                  DDIC_Control_Status DDIC_Contr);
#else
void DDIC_Control(DDIC_Control_SEG_TypeDef DDIC_Seg, 
									uint8_t DDIC_Com,
                  DDIC_Control_Status DDIC_Contr);
#endif
#endif

#if defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436) || defined(SC92R438) || defined(SC92R439) || defined(SC92R422A)\
      || defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)|| defined(SC92F531x)|| defined(SC92F663x) || defined(SC92F563x)
 /* Initialization and de-initialization functions *****************************/
#if defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F663x) || defined(SC92F563x)
void DDIC_LEDInit(DDIC_OutputPin_TypeDef DDIC_DutyCylce,uint32_t OutputPin);
#else
void DDIC_LEDInit(DDIC_OutputPin_TypeDef DDIC_DutyCylce,uint16_t OutputPin);
#endif

/* DDIC operation functions *****************************************************/
#if defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F663x) || defined(SC92F563x)
void DDIC_LEDOutputPinOfDuty(uint32_t OutputPin);
#else
void DDIC_LEDOutputPinOfDuty(uint16_t OutputPin);
#endif
#if !defined(SC92F663x) && !defined(SC92F563x)
void DDIC_LEDDRIVSelect(DDIC_DRIV_TypeDef LEDVoltage);
#endif
void DDIC_LEDConfig(DDIC_LEDXT_TypeDef DDIC_LEDXT,
                    DDIC_LEDEL_TypeDef DDIC_LEDEL,
                    DDIC_LEDCK_TypeDef DDIC_LEDCK);
#if !defined(SC92F531x)
void DDIC_LEDDMOD_Selcet(DDIC_DMOD_TypeDef DDIC_DMOD);
#endif
#if !defined(SC92F663x) && !defined(SC92F563x)
void DDIC_LEDCMCmd(FunctionalState NewState);
#endif
void DDIC_ClearFlag(DDIC_Flag_TypeDef DDIC_FLAG);
#endif
void DDIC_Cmd(FunctionalState NewState);

#endif
/**
 * @}
 */
/* End of functions --------------------------------------------------*/
#if defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB)|| defined (SC92F83Ax) || defined (SC92F73Ax)\
		|| defined (SC92F84Ax) || defined (SC92F74Ax) || defined (SC92F742x) || defined (SC92F730x) || defined (SC92F725X) || defined (SC92F735X)\
		|| defined (SC92F732X) || defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x) || defined (SC92F848x) || defined (SC92F748x)\
		|| defined (SC92R342) || defined (SC92F841x) || defined (SC92F741x) || defined(SC92F730x_2) || defined(SC92F720x)  || defined (SC92F7308B)\
    || defined (SC92Fx41xB) || defined (SC92R445)
#if defined (SC92F730x) || defined (SC92F7308B)
/** @defgroup GPIO_Enumerations GPIO Enumerations
 * @{
 */
 
 /** @brief LCD port enumeration
 * @{
 */
typedef enum
{
  DDIC_PIN_00    = ((uint8_t)0x01),	/*!< P0x0口输出LCD*/
  DDIC_PIN_01    = ((uint8_t)0x02),	/*!< P0x1口输出LCD*/
  DDIC_PIN_02    = ((uint8_t)0x04),	/*!< P0x2口输出LCD*/
  DDIC_PIN_03    = ((uint8_t)0x08),	/*!< P0x3口输出LCD*/
} DDIC_Pin_TypeDef;
#else
typedef enum
{
  DDIC_PIN_00    = ((uint8_t)0x01),	/*!< P0x0口输出LCD*/
  DDIC_PIN_01    = ((uint8_t)0x02),	/*!< P0x1口输出LCD*/
  DDIC_PIN_02    = ((uint8_t)0x04),	/*!< P0x2口输出LCD*/
  DDIC_PIN_03    = ((uint8_t)0x08),	/*!< P0x3口输出LCD*/
  DDIC_PIN_04    = ((uint8_t)0x10), /*!< P0x4口输出LCD*/
} DDIC_Pin_TypeDef;
#endif
/**
 * @}
 */

#if defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x) 
 /** @brief DDIC Resistor enumeration
 * @{
 */
typedef enum
{
  DDIC_ResSel_0K		= (uint8_t)0X00,	//关闭内部分压电阻
  DDIC_ResSel_25K	= (uint8_t)0X04,	//设定内部分压电阻为12.5k
  DDIC_ResSel_50K	= (uint8_t)0X08,	//设定内部分压电阻为37.5k
  DDIC_ResSel_100K	= (uint8_t)0X0c		//设定内部分压电阻为87.5k
} DDIC_ResSel_Typedef;
#else
typedef enum
{
  DDIC_ResSel_0K		= (uint8_t)0X00,	//关闭内部分压电阻
  DDIC_ResSel_12_5K	= (uint8_t)0X04,	//设定内部分压电阻为12.5k
  DDIC_ResSel_37_5K	= (uint8_t)0X08,	//设定内部分压电阻为37.5k
  DDIC_ResSel_87_5K	= (uint8_t)0X0c		//设定内部分压电阻为87.5k
} DDIC_ResSel_Typedef;
/**
 * @}
 */
#endif
/**
 * @}
 */
/* End of Enumerations --------------------------------------------------*/

/** @addtogroup GPIO_Exported_Functions
 * @{
 */
/* Initialization and de-initialization functions *****************************/
void DDIC_DeInit();
void DDIC_Init(uint8_t P0OutputPin);
/* DDIC operation functions *****************************************************/
void DDIC_LCDConfig(DDIC_ResSel_Typedef
                    DDIC_ResSel);
void DDIC_Config_Init(uint8_t P0OutputPin,
                      DDIC_ResSel_Typedef DDIC_ResSel);
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