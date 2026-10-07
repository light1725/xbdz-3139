/**
 ******************************************************************************
 * @file    sc92f_pwm.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of PWM module.
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
#ifndef _sc92f_PWM_H_
#define	_sc92f_PWM_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @addtogroup PWM
 * @{
 */

/** @defgroup PWM_Enumerations PWM Enumerations
 * @{
 */
#if !defined (SC92F7490)
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
		|| defined(SC92F859x) || defined(SC92F759x) || defined (SC92R511x)
/** @brief PWM_Prescaler PWM Prescaler
 * @{
 */
typedef enum
{
  PWM_PRESSEL_FHRC_D1  = (uint8_t)0x00,	   /*!< PWM预分频为Fhrc/1 */
  PWM_PRESSEL_FHRC_D2  = (uint8_t)0x10,	   /*!< PWM预分频为Fhrc/2 */
  PWM_PRESSEL_FHRC_D4  = (uint8_t)0x20,	   /*!< PWM预分频为Fhrc/4 */
  PWM_PRESSEL_FHRC_D8  = (uint8_t)0x30	   /*!< PWM预分频为Fhrc/8 */
} PWM_PresSel_TypeDef;
/**
 * @}
 */

/** @brief PWM_OutputPin_TypeDef PWM Output Pin
 * @{
 */
typedef enum
{
  PWM40 = (uint8_t)0x01,   /*!< PWM输出通道选择:PWM40 */
  PWM41 = (uint8_t)0x02,   /*!< PWM输出通道选择:PWM41 */
  PWM42 = (uint8_t)0x04,   /*!< PWM输出通道选择:PWM42 */
  PWM43 = (uint8_t)0x08,   /*!< PWM输出通道选择:PWM43 */
  PWM50 = (uint8_t)0x10,   /*!< PWM输出通道选择:PWM50 */
  PWM51 = (uint8_t)0x20,   /*!< PWM输出通道选择:PWM51 */
  PWM52 = (uint8_t)0x40,   /*!< PWM输出通道选择:PWM52 */
  PWM53 = (uint8_t)0x80	   /*!< PWM输出通道选择:PWM53 */
} PWM_OutputPin_TypeDef;
/**
 * @}
 */

#elif defined (SC92F742x) || defined (SC92F730x) || defined (SC92F827X) || defined (SC92F837X)  || defined (SC92F725X) || defined(SC92F735X) || defined(SC92F730x_2) || defined(SC92F720x)\
 ||defined (SC92F7308B)
/** @brief PWM_Prescaler PWM Prescaler
 * @{
 */
typedef enum
{
  PWM_PRESSEL_FSYS_D1  = (uint8_t)0x00,	    /*!< PWM预分频为Fsys/1 */
  PWM_PRESSEL_FSYS_D2  = (uint8_t)0x01,		/*!< PWM预分频为Fsys/2 */
  PWM_PRESSEL_FSYS_D4  = (uint8_t)0x02,		/*!< PWM预分频为Fsys/4 */
  PWM_PRESSEL_FSYS_D8  = (uint8_t)0x03,		/*!< PWM预分频为Fsys/8 */
  PWM_PRESSEL_FSYS_D32 = (uint8_t)0x04,		/*!< PWM预分频为Fsys/32 */
  PWM_PRESSEL_FSYS_D64 = (uint8_t)0x05,		/*!< PWM预分频为Fsys/64 */
  PWM_PRESSEL_FSYS_D128 = (uint8_t)0x06,	/*!< PWM预分频为Fsys/128 */
  PWM_PRESSEL_FSYS_D256 = (uint8_t)0x07		/*!< PWM预分频为Fsys/256 */
} PWM_PresSel_TypeDef;
/**
 * @}
 */

#if defined (SC92F827X)
/** @brief PWM_OutputPin_TypeDef PWM Output Pin
 * @{
 */
typedef enum
{
  PWM0 = (uint8_t)0x01,					    /*!< PWM输出通道选择:PWM0 */
  PWM1 = (uint8_t)0x02,						/*!< PWM输出通道选择:PWM1 */
} PWM_OutputPin_TypeDef;
#elif defined (SC92F837X)
typedef enum
{
  PWM0 = (uint8_t)0x01,						/*!< PWM输出通道选择:PWM0 */
  PWM1 = (uint8_t)0x02,						/*!< PWM输出通道选择:PWM1 */
  PWM2 = (uint8_t)0x04,						/*!< PWM输出通道选择:PWM2 */
  PWM3 = (uint8_t)0x08,						/*!< PWM输出通道选择:PWM3 */
} PWM_OutputPin_TypeDef;
#elif defined (SC92F730x)|| defined (SC92F7308B)
typedef enum
{
  PWM0 = (uint8_t)0x01,						/*!< PWM输出通道选择:PWM0 */
  PWM1 = (uint8_t)0x02,						/*!< PWM输出通道选择:PWM1 */
  PWM2 = (uint8_t)0x04,						/*!< PWM输出通道选择:PWM2 */
  PWM4 = (uint8_t)0x10,						/*!< PWM输出通道选择:PWM4 */
  PWM5 = (uint8_t)0x20						/*!< PWM输出通道选择:PWM5 */
} PWM_OutputPin_TypeDef;
#else
typedef enum
{
  PWM0 = (uint8_t)0x01,						/*!< PWM输出通道选择:PWM0 */
  PWM1 = (uint8_t)0x02,						/*!< PWM输出通道选择:PWM1 */
  PWM2 = (uint8_t)0x04,						/*!< PWM输出通道选择:PWM2 */
  PWM3 = (uint8_t)0x08,						/*!< PWM输出通道选择:PWM3 */
  PWM4 = (uint8_t)0x10,						/*!< PWM输出通道选择:PWM4 */
  PWM5 = (uint8_t)0x20						/*!< PWM输出通道选择:PWM5 */
} PWM_OutputPin_TypeDef;
/**
 * @}
 */
#endif

#elif defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB) || defined (SC92F83Ax) || defined (SC92F73Ax)\
		|| defined (SC92F84Ax) || defined (SC92F74Ax) || defined (SC92F848x) || defined (SC92F748x) || defined (SC92R342) || defined (SC92F841x)\
    || defined (SC92F741x) || defined (SC92Fx41xB)|| defined (SC92R445) 
/** @brief PWM_PresSel_TypeDef PWM Prescaler
 * @{
 */
typedef enum
{
  PWM_PRESSEL_FOSC_D1  = (uint8_t)0x00,		/*!< PWM预分频为Fsys/1 */
  PWM_PRESSEL_FOSC_D2  = (uint8_t)0x01,		/*!< PWM预分频为Fsys/2 */
  PWM_PRESSEL_FOSC_D8  = (uint8_t)0x02,		/*!< PWM预分频为Fsys/8 */
  PWM_PRESSEL_FOSC_D32 = (uint8_t)0x03		/*!< PWM预分频为Fsys/32 */
} PWM_PresSel_TypeDef;
/**
 * @}
 */

/** @brief PWM_OutputPin_TypeDef PWM Output Pin
 * @{
 */
typedef enum
{
  PWM0 = (uint8_t)0x01,						/*!< PWM输出通道选择:PWM0 */
  PWM1 = (uint8_t)0x02,						/*!< PWM输出通道选择:PWM1 */
  PWM2 = (uint8_t)0x04,						/*!< PWM输出通道选择:PWM2 */
  PWM3 = (uint8_t)0x08,						/*!< PWM输出通道选择:PWM3 */
  PWM4 = (uint8_t)0x10,						/*!< PWM输出通道选择:PWM4 */
  PWM5 = (uint8_t)0x20,						/*!< PWM输出通道选择:PWM5 */
} PWM_OutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM_ComplementaryOutputPin_TypeDef PWM Complementary OutputPin
 * @{
 */
typedef enum
{
  PWM0PWM3 = (uint8_t)0x00,					/*!< PWM互补模式通道选择:PWM0、PWM3 */
  PWM1PWM4 = (uint8_t)0x01,					/*!< PWM互补模式通道选择:PWM1、PWM4 */
  PWM2PWM5 = (uint8_t)0x02					/*!< PWM互补模式通道选择:PWM2、PWM5 */
} PWM_ComplementaryOutputPin_TypeDef;
/**
 * @}
 */

#elif defined (SC92F7003) || defined (SC92F8003) || defined(SC92F8003B) || defined (SC92F740x)
/** @brief PWM_PresSel_TypeDef PWM Prescaler
 * @{
 */
typedef enum
{
  PWM_PRESSEL_FOSC_D1  = (uint8_t)0x00,		/*!< PWM预分频为Fosc/1 */
  PWM_PRESSEL_FOSC_D2  = (uint8_t)0x10,		/*!< PWM预分频为Fosc/2 */
  PWM_PRESSEL_FOSC_D8  = (uint8_t)0x20,		/*!< PWM预分频为Fosc/8 */
  PWM_PRESSEL_FOSC_D32 = (uint8_t)0x30		/*!< PWM预分频为Fosc/32 */
} PWM_PresSel_TypeDef;
/**
 * @}
 */

/** @brief PWM2_OutputPin_TypeDef PWM2 Output Pin
 * @{
 */
typedef enum
{
  PWM2_OutputPin_P26       = ((uint8_t)0x00),	    /*!< PWM2输出口选择P26 */
  PWM2_OutputPin_P14       = ((uint8_t)0x04)		/*!< PWM2输出口选择P14 */
} PWM2_OutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM5_OutputPin_TypeDef PWM2 Output Pin
 * @{
 */
typedef enum
{
  PWM5_OutputPin_P12       = ((uint8_t)0x00),		/*!< PWM2输出口选择P12 */
  PWM5_OutputPin_P21       = ((uint8_t)0x08)		/*!< PWM2输出口选择P21 */
} PWM5_OutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM_OutputPin_TypeDef PWM Output Pin
 * @{
 */
typedef enum
{
  PWM0 = (uint8_t)0x01,						/*!< PWM输出通道选择:PWM0 */
  PWM1 = (uint8_t)0x02,						/*!< PWM输出通道选择:PWM1 */
  PWM2 = (uint8_t)0x04,						/*!< PWM输出通道选择:PWM2 */
  PWM3 = (uint8_t)0x08,						/*!< PWM输出通道选择:PWM3 */
  PWM4 = (uint8_t)0x10,						/*!< PWM输出通道选择:PWM4 */
  PWM5 = (uint8_t)0x20,						/*!< PWM输出通道选择:PWM5 */
  PWM6 = (uint8_t)0x40,						/*!< PWM输出通道选择:PWM6 */
} PWM_OutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM_ComplementaryOutputPin_TypeDef PWM Complementary OutputPin
 * @{
 */
typedef enum
{
  PWM0PWM3 = (uint8_t)0x00,					/*!< PWM互补模式通道选择:PWM0、PWM3 */
  PWM1PWM4 = (uint8_t)0x01,					/*!< PWM互补模式通道选择:PWM1、PWM4 */
  PWM2PWM5 = (uint8_t)0x02					/*!< PWM互补模式通道选择:PWM2、PWM5 */
} PWM_ComplementaryOutputPin_TypeDef;
/**
 * @}
 */
#elif defined (SC92F732X) || defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x)
/** @brief PWM_PresSel_TypeDef PWM Prescaler
 * @{
 */
typedef enum
{
  PWM_PRESSEL_FSYS_D1  = (uint8_t)0x00,		/*!< PWM预分频为Fosc/1 */
  PWM_PRESSEL_FSYS_D2  = (uint8_t)0x01,		/*!< PWM预分频为Fosc/2 */
  PWM_PRESSEL_FSYS_D4  = (uint8_t)0x02,		/*!< PWM预分频为Fosc/4 */
  PWM_PRESSEL_FSYS_D8  = (uint8_t)0x03,		/*!< PWM预分频为Fosc/8 */
  PWM_PRESSEL_FSYS_D32 = (uint8_t)0x04,		/*!< PWM预分频为Fosc/32 */
  PWM_PRESSEL_FSYS_D64 = (uint8_t)0x05,		/*!< PWM预分频为Fosc/64 */
  PWM_PRESSEL_FSYS_D128 = (uint8_t)0x06,	/*!< PWM预分频为Fosc/128 */
  PWM_PRESSEL_FSYS_D256 = (uint8_t)0x07		/*!< PWM预分频为Fosc/256 */
} PWM_PresSel_TypeDef;
/**
 * @}
 */

/** @brief PWM_OutputPin_TypeDef PWM Output Pin
 * @{
 */
typedef enum
{
  PWM0 = (uint8_t)0x01,						/*!< PWM输出通道选择:PWM0 */
  PWM1 = (uint8_t)0x02,						/*!< PWM输出通道选择:PWM1 */
  PWM2 = (uint8_t)0x04,						/*!< PWM输出通道选择:PWM2 */
} PWM_OutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM2_OutputPin_TypeDef PWM2 Output Pin
 * @{
 */
typedef enum
{
  PWM0_OutputPin_P00       = ((uint8_t)0x00),		/*!< PWM0输出口选择P00 */
  PWM0_OutputPin_P25       = ((uint8_t)0x01)		/*!< PWM0输出口选择P25 */
} PWM0_OutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM1_OutputPin_TypeDef PWM1 Output Pin
 * @{
 */
typedef enum
{
  PWM1_OutputPin_P01       = ((uint8_t)0x00),		/*!< PWM1输出口选择P01 */
  PWM1_OutputPin_P26      = ((uint8_t)0x02)		    /*!< PWM1输出口选择P26 */
} PWM1_OutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM2_OutputPin_TypeDef PWM2 Output Pin
 * @{
 */
typedef enum
{
  PWM2_OutputPin_P02       = ((uint8_t)0x00),		/*!< PWM2输出口选择P02 */
  PWM2_OutputPin_P27       = ((uint8_t)0x04)		/*!< PWM2输出口选择P27 */
} PWM2_OutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM_DutyMode_TypeDef PWM Duty
 * @{
 */
typedef enum
{
  PWM_DutyMode0      = ((uint8_t)0x00),		/*!< 00:四个PWM2输出的duty均为PDT2设定值；(D、D、D、D) */
  PWM_DutyMode1      = ((uint8_t)0x01),	    /*!< 01:第一个PWM2输出的duty为PDT2设定值加1，其余三个PWM2输出的duty均为PDT2设定值；(D+1、D、D、D) */
  PWM_DutyMode2      = ((uint8_t)0x02),     /*!< 10:第一和第二个PWM2输出的duty为PDT2设定值加1，其余二个PWM2输出的duty均为PDT2设定值；(D+1、D+1、D、D) */
  PWM_DutyMode3      = ((uint8_t)0x03),	    /*!< 11:第一、第二和第三个PWM2输出的duty为PDT2设定值加1，第四个PWM2输出的Duty为PDT2设定值； (D+1、D+1、D+1、D) */
} PWM_DutyMode_TypeDef;
/**
 * @}
 */

#elif defined (SC92FWxx)
/** @brief PWM_PresSel_TypeDef PWM Prescaler
 * @{
 */
typedef enum
{
  PWM0_PRESSEL_FHRC_D1  = (uint8_t)0x00,	  /*!< PWM0预分频为Fosc/1 */
  PWM0_PRESSEL_FHRC_D2  = (uint8_t)0x10,	  /*!< PWM0预分频为Fosc/2 */
  PWM0_PRESSEL_FHRC_D4  = (uint8_t)0x20,	  /*!< PWM0预分频为Fosc/4 */
  PWM0_PRESSEL_FHRC_D8  = (uint8_t)0x30,	  /*!< PWM0预分频为Fosc/8 */
  PWM1_PRESSEL_FHRC_D1  = (uint8_t)0x01,      /*!< PWM1预分频为Fosc/1 */
  PWM1_PRESSEL_FHRC_D2  = (uint8_t)0x11,      /*!< PWM1预分频为Fosc/2 */
  PWM1_PRESSEL_FHRC_D4  = (uint8_t)0x21,      /*!< PWM1预分频为Fosc/4 */
  PWM1_PRESSEL_FHRC_D8  = (uint8_t)0x31,      /*!< PWM1预分频为Fosc/8 */
} PWM_PresSel_TypeDef;
/**
 * @}
 */

/** @brief PWM1_OutputPin_TypeDef PWM2 Output Pin
 * @{
 */
typedef enum
{
  PWM000 = (uint8_t)0x00,   /*!< PWM输出通道选择: PWM000  */
  PWM001 = (uint8_t)0x02,   /*!< PWM输出通道选择: PWM001  */
  PWM002 = (uint8_t)0x04,   /*!< PWM输出通道选择: PWM002  */
  PWM003 = (uint8_t)0x06,   /*!< PWM输出通道选择: PWM003  */
  PWM004 = (uint8_t)0x08,   /*!< PWM输出通道选择: PWM004  */
  PWM005 = (uint8_t)0x0A,   /*!< PWM输出通道选择: PWM005  */
  PWM006 = (uint8_t)0x0C,   /*!< PWM输出通道选择: PWM006  */
  PWM007 = (uint8_t)0x0E,   /*!< PWM输出通道选择: PWM007  */
  PWM010 = (uint8_t)0x10,   /*!< PWM输出通道选择: PWM010  */
  PWM011 = (uint8_t)0x12,   /*!< PWM输出通道选择: PWM011  */
  PWM012 = (uint8_t)0x14,   /*!< PWM输出通道选择: PWM012  */
  PWM013 = (uint8_t)0x16,   /*!< PWM输出通道选择: PWM013  */
  PWM014 = (uint8_t)0x18,   /*!< PWM输出通道选择: PWM014  */
  PWM015 = (uint8_t)0x1A,   /*!< PWM输出通道选择: PWM015  */
  PWM016 = (uint8_t)0x1C,   /*!< PWM输出通道选择: PWM016  */
  PWM017 = (uint8_t)0x1E,   /*!< PWM输出通道选择: PWM017  */
  PWM020 = (uint8_t)0x20,   /*!< PWM输出通道选择: PWM020  */
  PWM021 = (uint8_t)0x22,   /*!< PWM输出通道选择: PWM021  */
  PWM022 = (uint8_t)0x24,   /*!< PWM输出通道选择: PWM022  */
  PWM023 = (uint8_t)0x26,   /*!< PWM输出通道选择: PWM023  */
  PWM024 = (uint8_t)0x28,   /*!< PWM输出通道选择: PWM024  */
  PWM025 = (uint8_t)0x2A,   /*!< PWM输出通道选择: PWM025  */
  PWM026 = (uint8_t)0x2C,   /*!< PWM输出通道选择: PWM026  */
  PWM027 = (uint8_t)0x2E,   /*!< PWM输出通道选择: PWM027  */
  PWM030 = (uint8_t)0x30,   /*!< PWM输出通道选择: PWM030  */
  PWM031 = (uint8_t)0x32,   /*!< PWM输出通道选择: PWM031  */
  PWM032 = (uint8_t)0x34,   /*!< PWM输出通道选择: PWM032  */
  PWM033 = (uint8_t)0x36,   /*!< PWM输出通道选择: PWM033  */
  PWM034 = (uint8_t)0x38,   /*!< PWM输出通道选择: PWM034  */
  PWM035 = (uint8_t)0x3A,   /*!< PWM输出通道选择: PWM035  */
  PWM036 = (uint8_t)0x3C,   /*!< PWM输出通道选择: PWM036  */
  PWM037 = (uint8_t)0x3E,   /*!< PWM输出通道选择: PWM037  */
  PWM140 = (uint8_t)0x40,   /*!< PWM输出通道选择: PWM140  */
  PWM141 = (uint8_t)0x42,   /*!< PWM输出通道选择: PWM141  */
  PWM142 = (uint8_t)0x44,   /*!< PWM输出通道选择: PWM142  */
  PWM143 = (uint8_t)0x46,   /*!< PWM输出通道选择: PWM143  */
  PWM150 = (uint8_t)0x48,   /*!< PWM输出通道选择: PWM150  */
  PWM151 = (uint8_t)0x4A,   /*!< PWM输出通道选择: PWM151  */
  PWM152 = (uint8_t)0x4C,   /*!< PWM输出通道选择: PWM152  */
  PWM153 = (uint8_t)0x4E,   /*!< PWM输出通道选择: PWM153  */
} PWM_OutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM_PresSel_TypeDef PWM Prescaler
 * @{
 */
typedef enum
{
  PWM0_Type  = (uint8_t)0x00,	   /*!< PWM预分频为Fhrc/1 */
  PWM1_Type  = (uint8_t)0x01,	   /*!< PWM预分频为Fhrc/2 */
} PWM_Type_TypeDef;
/**
 * @}
 */

#elif defined (SC92L853x) || defined (SC92L753x) || defined (SC92L840x)
/** @brief PWM_PresSel_TypeDef PWM Prescaler
 * @{
 */
typedef enum
{
#if defined (SC92L853x) || defined (SC92L753x)
  PWM_PRESSEL_FHRC_D1 = (uint8_t)0x00, /*!< PWM预分频为Fhrc/1 */
  PWM_PRESSEL_FHRC_D2 = (uint8_t)0x10, /*!< PWM预分频为Fhrc/2 */
  PWM_PRESSEL_FHRC_D4 = (uint8_t)0x20, /*!< PWM预分频为Fhrc/4 */
  PWM_PRESSEL_FHRC_D8 = (uint8_t)0x30, /*!< PWM预分频为Fhrc/8 */
#elif defined (SC92L840x)
  PWM_PRESSEL_FHRC_D1 = (uint8_t)0x00, /*!< PWM预分频为Fhrc/1 */
  PWM_PRESSEL_FHRC_D4 = (uint8_t)0x10, /*!< PWM预分频为Fhrc/4 */
  PWM_PRESSEL_FHRC_D16 = (uint8_t)0x20, /*!< PWM预分频为Fhrc/16 */
  PWM_PRESSEL_FHRC_D64 = (uint8_t)0x30, /*!< PWM预分频为Fhrc/64 */
#endif	
} PWM_PresSel_TypeDef;
/**
 * @}
 */

/** @brief PWM1_OutputPin_TypeDef PWM Output Pin
 * @{
 */
typedef enum
{
#if defined (SC92L853x) || defined (SC92L753x)
  PWM0 = (uint8_t)0x01, /*!< PWM输出通道选择: PWM0  */
  PWM1 = (uint8_t)0x02, /*!< PWM输出通道选择: PWM1  */
  PWM2 = (uint8_t)0x04, /*!< PWM输出通道选择: PWM2  */
  PWM3 = (uint8_t)0x08, /*!< PWM输出通道选择: PWM3  */
  PWM4 = (uint8_t)0x10, /*!< PWM输出通道选择: PWM4  */
  PWM5 = (uint8_t)0x20, /*!< PWM输出通道选择: PWM5  */
  PWM6 = (uint8_t)0x40, /*!< PWM输出通道选择: PWM6  */
  PWM7 = (uint8_t)0x80, /*!< PWM输出通道选择: PWM7  */
#elif defined (SC92L840x)
  PWM0 = (uint8_t)0x01, /*!< PWM输出通道选择: PWM0  */
  PWM1 = (uint8_t)0x02, /*!< PWM输出通道选择: PWM1  */
  PWM2 = (uint8_t)0x04, /*!< PWM输出通道选择: PWM2  */
  PWM3 = (uint8_t)0x08, /*!< PWM输出通道选择: PWM3  */
  PWM4 = (uint8_t)0x10, /*!< PWM输出通道选择: PWM4  */
  PWM5 = (uint8_t)0x20, /*!< PWM输出通道选择: PWM5  */
  PWM6 = (uint8_t)0x40, /*!< PWM输出通道选择: PWM6  */
#endif
} PWM_OutputPin_TypeDef;

/** @brief PWM_Aligned_Mode_TypeDef PWM Aligned Mode
 * @{
 */
typedef enum
{
  PWM0_Edge_Aligned_Mode = (uint8_t)0x00,     /*!< PWM边沿对齐模式  */
  PWM0_Center_Alignment_Mode = (uint8_t)0x01, /*!< PWM中间对齐模式  */
} PWM_Aligned_Mode_TypeDef;
/**
 * @}
 */

/** @brief PWM_FaultDetectionMode_TypeDef PWM Fault Detection Mode
 * @{
 */
typedef enum
{
  PWM0_Latch_Mode = ((uint8_t)0x00),    /*!< PWM故障检测模式:锁存模式 */
  PWM0_Immediate_Mode = ((uint8_t)0x20) /*!< PWM故障检测模式:立即模式 */
} PWM_FaultDetectionMode_TypeDef;
/**
 * @}
 */

/** @brief PWM_FaultDetectionVoltageSelect_TypeDef PWM Fault Detection Voltage Select
 * @{
 */
typedef enum
{
  PWM0_FaultDetectionVoltage_Low = ((uint8_t)0x00), /*!< PWM故障检测低电平选择 */
  PWM0_FaultDetectionVoltage_high = ((uint8_t)0x10) /*!< PWM故障检测高电平选择 */
} PWM_FaultDetectionVoltageSelect_TypeDef;
/**
 * @}
 */

/** @brief PWM_FaultDetectionWaveFilteringTime_TypeDef PWM Fault Detection WaveFiltering Time
 * @{
 */
typedef enum
{
  PWM0_WaveFilteringTime_0us = ((uint8_t)0x00),  /*!< PWM故障检测输入信号滤波时间0us */
  PWM0_WaveFilteringTime_1us = ((uint8_t)0x01),  /*!< PWM故障检测输入信号滤波时间1us */
  PWM0_WaveFilteringTime_4us = ((uint8_t)0x02),  /*!< PWM故障检测输入信号滤波时间4us */
  PWM0_WaveFilteringTime_16us = ((uint8_t)0x03)  /*!< PWM故障检测输入信号滤波时间16us */
} PWM_FaultDetectionWaveFilteringTime_TypeDef;
/**
 * @}
 */

/** @brief PWM_ComplementaryOutputPin_TypeDef PWM Complementary OutputPin
 * @{
 */
typedef enum
{
#if defined (SC92L853x) || defined (SC92L753x)
  PWM0PWM1 = (uint8_t)0x00, /*!< PWM互补模式通道选择:PWM00、PWM01 */
  PWM2PWM3 = (uint8_t)0x04, /*!< PWM互补模式通道选择:PWM02、PWM03 */
  PWM4PWM5 = (uint8_t)0x08, /*!< PWM互补模式通道选择:PWM04、PWM05 */
  PWM6PWM7 = (uint8_t)0x0C, /*!< PWM互补模式通道选择:PWM06、PWM07 */
#elif defined (SC92L840x)
  PWM0PWM1 = (uint8_t)0x00, /*!< PWM互补模式通道选择:PWM00、PWM01 */
  PWM2PWM3 = (uint8_t)0x04, /*!< PWM互补模式通道选择:PWM02、PWM03 */
  PWM4PWM5 = (uint8_t)0x08, /*!< PWM互补模式通道选择:PWM04、PWM05 */
#endif
} PWM_ComplementaryOutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM_Type_TypeDef PWM Type
 * @{
 */
typedef enum
{
  PWM0_Type = (uint8_t)0x00, /*!< 操作PWM0 */
} PWM_Type_TypeDef;
/**
 * @}
 */

#elif defined(SC92F84Hx) || defined(SC92F83Hx)
/** @brief PWM_PresSel_TypeDef PWM Prescaler
 * @{
 */
typedef enum
{
  PWM2_PRESSEL_FHRC_D1 = (uint8_t)0x82,    /*!< PWM2预分频为Fhrc/1  */
	PWM2_PRESSEL_FHRC_D12 = (uint8_t)0x02, /*!< PWM2预分频为Fhrc/12 */
	PWM3_PRESSEL_FHRC_D1 = (uint8_t)0x83,  /*!< PWM3预分频为Fhrc/1  */
  PWM3_PRESSEL_FHRC_D12 = (uint8_t)0x03,   /*!< PWM3预分频为Fhrc/12 */
	PWM4_PRESSEL_FHRC_D1 = (uint8_t)0x84,  /*!< PWM4预分频为Fhrc/1  */
  PWM4_PRESSEL_FHRC_D12 = (uint8_t)0x04,   /*!< PWM4预分频为Fhrc/12 */
} PWM_PresSel_TypeDef;
/**
 * @}
 */

/** @brief PWM_Type_TypeDef PWM Type
 * @{
 */
typedef enum
{
  PWM2_Type = (uint8_t)0x02, /*!< 操作PWM2 */
  PWM3_Type = (uint8_t)0x03, /*!< 操作PWM3 */
  PWM4_Type = (uint8_t)0x04, /*!< 操作PWM4 */
} PWM_Type_TypeDef;
/**
 * @}
 */

/** @brief PWM_OutputPin_TypeDef PWM OutputPin
 * @{
 */
typedef enum
{
  PWM20 = (uint8_t)0x20, /*!< PWM输出通道选择: PWM20  */
  PWM21 = (uint8_t)0x21, /*!< PWM输出通道选择: PWM21  */
  PWM30 = (uint8_t)0x32, /*!< PWM输出通道选择: PWM30  */
  PWM31 = (uint8_t)0x33, /*!< PWM输出通道选择: PWM31  */
  PWM40 = (uint8_t)0x44, /*!< PWM输出通道选择: PWM40  */
  PWM41 = (uint8_t)0x45, /*!< PWM输出通道选择: PWM41  */
} PWM_OutputPin_TypeDef;
/**
 * @}
 */

#elif defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)
/** @brief PWM_PresSel_TypeDef PWM Prescaler
 * @{
 */
typedef enum
{
  PWM0_PRESSEL_FOSC_D1 = (uint8_t)0x00, /*!< PWM0预分频为Fhrc/1  */
  PWM0_PRESSEL_FOSC_D2 = (uint8_t)0x10, /*!< PWM0预分频为Fosc/2  */
  PWM0_PRESSEL_FOSC_D4 = (uint8_t)0x20, /*!< PWM0预分频为Fosc/4  */
  PWM0_PRESSEL_FOSC_D8 = (uint8_t)0x30, /*!< PWM0预分频为Fosc/8  */
  PWM2_PRESSEL_FHRC_D1 = (uint8_t)0x82, /*!< PWM2预分频为Fosc/1  */
	PWM2_PRESSEL_FHRC_D12 = (uint8_t)0x02, /*!< PWM2预分频为Fosc/12  */
	PWM3_PRESSEL_FHRC_D1 = (uint8_t)0x83, /*!< PWM3预分频为Fosc/1  */
  PWM3_PRESSEL_FHRC_D12 = (uint8_t)0x03,  /*!< PWM3预分频为Fosc/12  */
	PWM4_PRESSEL_FHRC_D1 = (uint8_t)0x84, /*!< PWM4预分频为Fosc/1  */
  PWM4_PRESSEL_FHRC_D12 = (uint8_t)0x04, /*!< PWM4预分频为Fosc/12  */
} PWM_PresSel_TypeDef;
/**
 * @}
 */

/** @brief PWM_Type_TypeDef PWM Type
 * @{
 */
typedef enum
{
  PWM0_Type = (uint8_t)0x00, /*!< 操作PWM0  */
  PWM2_Type = (uint8_t)0x02, /*!< 操作PWM2  */
  PWM3_Type = (uint8_t)0x03, /*!< 操作PWM3  */
  PWM4_Type = (uint8_t)0x04, /*!< 操作PWM4  */
} PWM_Type_TypeDef;
/**
 * @}
 */

/** @brief PWM_Aligned_Mode_TypeDef PWM Aligned Mode
 * @{
 */
typedef enum
{
  PWM0_Edge_Aligned_Mode = (uint8_t)0x00,     /*!< PWM边沿对齐模式  */
  PWM0_Center_Alignment_Mode = (uint8_t)0x01, /*!< PWM中心对齐模式  */
} PWM_Aligned_Mode_TypeDef;
/**
 * @}
 */

/** @brief PWM_OutputPin_TypeDef PWM OutputPin
 * @{
 */
typedef enum
{
  PWM00 = (uint8_t)0x00, /*!< PWM输出通道选择: PWM00  */
  PWM01 = (uint8_t)0x01, /*!< PWM输出通道选择: PWM01  */
  PWM02 = (uint8_t)0x02, /*!< PWM输出通道选择: PWM02  */
  PWM03 = (uint8_t)0x03, /*!< PWM输出通道选择: PWM03  */
  PWM04 = (uint8_t)0x04, /*!< PWM输出通道选择: PWM04  */
  PWM05 = (uint8_t)0x05, /*!< PWM输出通道选择: PWM05  */
  PWM06 = (uint8_t)0x06, /*!< PWM输出通道选择: PWM06  */
  PWM07 = (uint8_t)0x07, /*!< PWM输出通道选择: PWM07  */
  PWM20 = (uint8_t)0x20, /*!< PWM输出通道选择: PWM20  */
  PWM21 = (uint8_t)0x21, /*!< PWM输出通道选择: PWM21  */
  PWM30 = (uint8_t)0x32, /*!< PWM输出通道选择: PWM30  */
  PWM31 = (uint8_t)0x33, /*!< PWM输出通道选择: PWM31  */
  PWM40 = (uint8_t)0x44, /*!< PWM输出通道选择: PWM40  */
  PWM41 = (uint8_t)0x45, /*!< PWM输出通道选择: PWM41  */
} PWM_OutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM_ComplementaryOutputPin_TypeDef PWM Complementary OutputPin
 * @{
 */
typedef enum
{
  PWM0PWM1 = (uint8_t)0x00, /*!< PWM互补模式通道选择:PWM00、PWM01 */
  PWM2PWM3 = (uint8_t)0x02, /*!< PWM互补模式通道选择:PWM02、PWM03 */
  PWM4PWM5 = (uint8_t)0x04, /*!< PWM互补模式通道选择:PWM04、PWM05 */
  PWM6PWM7 = (uint8_t)0x06  /*!< PWM互补模式通道选择:PWM06、PWM07 */
} PWM_ComplementaryOutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM_FaultDetectionMode_TypeDef PWM Fault Detection Mode
 * @{
 */
typedef enum
{
  PWM_Latch_Mode = ((uint8_t)0x00),    /*!< PWM故障检测模式:锁存模式 */
  PWM_Immediate_Mode = ((uint8_t)0x20) /*!< PWM故障检测模式:立即模式 */
} PWM_FaultDetectionMode_TypeDef;
/**
 * @}
 */

/** @brief PWM_FaultDetectionVoltageSelect_TypeDef PWM Fault Detection Voltage Select
 * @{
 */
typedef enum
{
  PWM_FaultDetectionVoltage_Low = ((uint8_t)0x00), /*!< PWM故障检测低电平选择 */
  PWM_FaultDetectionVoltage_high = ((uint8_t)0x10) /*!< PWM故障检测高电平选择 */
} PWM_FaultDetectionVoltageSelect_TypeDef;
/**
 * @}
 */

/** @brief PWM_FaultDetectionWaveFilteringTime_TypeDef PWM Fault Detection WaveFiltering Time
 * @{
 */
typedef enum
{
  PWM_WaveFilteringTime_0us = ((uint8_t)0x00), /*!< PWM故障检测输入信号滤波时间0us */
  PWM_WaveFilteringTime_1us = ((uint8_t)0x01), /*!< PWM故障检测输入信号滤波时间1us */
  PWM_WaveFilteringTime_4us = ((uint8_t)0x02), /*!< PWM故障检测输入信号滤波时间4us */
  PWM_WaveFilteringTime_16us = ((uint8_t)0x03) /*!< PWM故障检测输入信号滤波时间16us */
} PWM_FaultDetectionWaveFilteringTime_TypeDef;
/**
 * @}
 */

#elif defined(SC92F6x1x) ||  defined(SC92F5x1x)||  defined(SC92R436)||  defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)\
		  || defined(SC92F531x)
/** @brief PWM_PresSel_TypeDef PWM Prescaler
 * @{
 */
typedef enum
{
  PWM0_PRESSEL_FOSC_D1 = (uint8_t)0x00, //PWM0预分频为Fosc/1
  PWM0_PRESSEL_FOSC_D2 = (uint8_t)0x10, //PWM0预分频为Fosc/2
  PWM0_PRESSEL_FOSC_D4 = (uint8_t)0x20, //PWM0预分频为Fosc/4
  PWM0_PRESSEL_FOSC_D8 = (uint8_t)0x30, //PWM0预分频为Fosc/8
  PWM2_PRESSEL_FHRC_D12 = (uint8_t)0x02, //PWM2预分频为Fhrc/12
  PWM2_PRESSEL_FHRC_D1 = (uint8_t)0x12, //PWM2预分频为Fhrc/1
} PWM_PresSel_TypeDef;
/**
 * @}
 */

/** @brief PWM_Type_TypeDef PWM Type
 * @{
 */
typedef enum
{
  PWM0_Type = (uint8_t)0x00, /*!< 操作PWM0 */
  PWM2_Type = (uint8_t)0x02, /*!< 操作PWM2 */
} PWM_Type_TypeDef;
/**
 * @}
 */

/** @brief PWM_Aligned_Mode_TypeDef PWM Aligned Mode
 * @{
 */
typedef enum
{
  PWM0_Edge_Aligned_Mode = (uint8_t)0x00,     /*!< PWM边沿对齐模式  */
  PWM0_Center_Alignment_Mode = (uint8_t)0x01, /*!< PWM中心对齐模式  */
} PWM_Aligned_Mode_TypeDef;
/**
 * @}
 */

/** @brief PWM_OutputPin_TypeDef PWM OutputPin
 * @{
 */
typedef enum
{
  PWM00 = (uint8_t)0x00, /*!< PWM输出通道选择: PWM00  */
  PWM01 = (uint8_t)0x01, /*!< PWM输出通道选择: PWM01  */
  PWM02 = (uint8_t)0x02, /*!< PWM输出通道选择: PWM02  */
  PWM03 = (uint8_t)0x03, /*!< PWM输出通道选择: PWM03  */
  PWM04 = (uint8_t)0x04, /*!< PWM输出通道选择: PWM04  */
  PWM05 = (uint8_t)0x05, /*!< PWM输出通道选择: PWM05  */
  PWM06 = (uint8_t)0x06, /*!< PWM输出通道选择: PWM06  */
  PWM07 = (uint8_t)0x07, /*!< PWM输出通道选择: PWM07  */
  PWM20 = (uint8_t)0x20, /*!< PWM输出通道选择: PWM20  */
  PWM21 = (uint8_t)0x21, /*!< PWM输出通道选择: PWM21  */
} PWM_OutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM_ComplementaryOutputPin_TypeDef PWM Complementary OutputPin
 * @{
 */
typedef enum
{
  PWM00PWM01 = (uint8_t)0x00, /*!< PWM互补模式通道选择:PWM00、PWM01 */
  PWM02PWM03 = (uint8_t)0x02, /*!< PWM互补模式通道选择:PWM02、PWM03 */
  PWM04PWM05 = (uint8_t)0x04, /*!< PWM互补模式通道选择:PWM04、PWM05 */
  PWM06PWM07 = (uint8_t)0x06  /*!< PWM互补模式通道选择:PWM06、PWM07 */
} PWM_ComplementaryOutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM_FaultDetectionMode_TypeDef PWM Fault Detection Mode
 * @{
 */
typedef enum
{
  PWM_Latch_Mode = ((uint8_t)0x00),    /*!< PWM故障检测模式:锁存模式 */
  PWM_Immediate_Mode = ((uint8_t)0x20) /*!< PWM故障检测模式:立即模式 */
} PWM_FaultDetectionMode_TypeDef;
/**
 * @}
 */

/** @brief PWM_FaultDetectionVoltageSelect_TypeDef PWM Fault Detection Voltage Select
 * @{
 */
typedef enum
{
  PWM_FaultDetectionVoltage_Low = ((uint8_t)0x00), /*!< PWM故障检测低电平选择 */
  PWM_FaultDetectionVoltage_high = ((uint8_t)0x10) /*!< PWM故障检测高电平选择 */
} PWM_FaultDetectionVoltageSelect_TypeDef;
/**
 * @}
 */

/** @brief PWM_FaultDetectionWaveFilteringTime_TypeDef PWM Fault Detection WaveFiltering Time
 * @{
 */
typedef enum
{
  PWM_WaveFilteringTime_0us = ((uint8_t)0x00), /*!< PWM故障检测输入信号滤波时间0us */
  PWM_WaveFilteringTime_1us = ((uint8_t)0x01), /*!< PWM故障检测输入信号滤波时间1us */
  PWM_WaveFilteringTime_4us = ((uint8_t)0x02), /*!< PWM故障检测输入信号滤波时间4us */
  PWM_WaveFilteringTime_16us = ((uint8_t)0x03) /*!< PWM故障检测输入信号滤波时间16us */
} PWM_FaultDetectionWaveFilteringTime_TypeDef;
/**
 * @}
 */

#if defined(SC92F531x)
/** @brief PWM21_PortMappingPin_TypeDef PWM21 Port Mapping Pins
 * @{
 */
typedef enum
{
  Mapped_to_P00 = (uint8_t)0x00, /*!< PWM21映射到P00 */
  Mapped_to_P01 = (uint8_t)0x01, /*!< PWM21映射到P01 */
  Mapped_to_P02 = (uint8_t)0x02, /*!< PWM21映射到P02 */
  Mapped_to_P03 = (uint8_t)0x03, /*!< PWM21映射到P03 */
	Mapped_to_P04 = (uint8_t)0x04, /*!< PWM21映射到P04 */
	Mapped_to_P05 = (uint8_t)0x05, /*!< PWM21映射到P05 */
	Mapped_to_P06 = (uint8_t)0x06, /*!< PWM21映射到P06 */
  Mapped_to_P07 = (uint8_t)0x07, /*!< PWM21映射到P07 */
  Mapped_to_P20 = (uint8_t)0x08, /*!< PWM21映射到P20 */
  Mapped_to_P21 = (uint8_t)0x09, /*!< PWM21映射到P21 */
	Mapped_to_P22 = (uint8_t)0x0A, /*!< PWM21映射到P22 */
	Mapped_to_P23 = (uint8_t)0x0B, /*!< PWM21映射到P23 */
  Mapped_to_P24 = (uint8_t)0x0C, /*!< PWM21映射到P24 */
  Mapped_to_P25 = (uint8_t)0x0D, /*!< PWM21映射到P25 */
  Mapped_to_P26 = (uint8_t)0x0E, /*!< PWM21映射到P26 */
	Mapped_to_P27 = (uint8_t)0x0F, /*!< PWM21映射到P27 */
	Mapped_to_P15 = (uint8_t)0x12, /*!< PWM21映射到P15 */
  Mapped_to_P14 = (uint8_t)0x13, /*!< PWM21映射到P14 */
  Mapped_to_P13 = (uint8_t)0x14, /*!< PWM21映射到P13 */
  Mapped_to_P12 = (uint8_t)0x15, /*!< PWM21映射到P12 */
	Mapped_to_P11 = (uint8_t)0x16, /*!< PWM21映射到P11 */
	Mapped_to_P10 = (uint8_t)0x19, /*!< PWM21映射到P10 */
} PWM21_PortMappingPin_TypeDef;
/**
 * @}
 */
#endif

#elif defined(SC92F652x) ||defined(SC92R51x_R52x) ||defined (SC92F552x) ||defined (SC92F663x) ||defined (SC92F563x)
/** @brief PWM_PresSel_TypeDef PWM Prescaler
 * @{
 */
typedef enum
{
  PWM0_PRESSEL_FOSC_D1  = (uint8_t)0x00, /*!< PWM0预分频为Fhrc/1  */
  PWM0_PRESSEL_FOSC_D2  = (uint8_t)0x10, /*!< PWM0预分频为Fosc/2  */
  PWM0_PRESSEL_FOSC_D4  = (uint8_t)0x20, /*!< PWM0预分频为Fosc/4  */
  PWM0_PRESSEL_FOSC_D8  = (uint8_t)0x30, /*!< PWM0预分频为Fosc/8  */
	PWM2_PRESSEL_FHRC_D12 = (uint8_t)0x02, /*!< PWM2预分频为Fhrc/12  */
  PWM2_PRESSEL_FHRC_D1  = (uint8_t)0x12, /*!< PWM2预分频为Fhrc/1  */
	PWM3_PRESSEL_FHRC_D12 = (uint8_t)0x03, /*!< PWM3预分频为Fhrc/12  */
	PWM3_PRESSEL_FHRC_D1  = (uint8_t)0x13, /*!< PWM3预分频为Fosc/1  */
	PWM4_PRESSEL_FHRC_D12 = (uint8_t)0x04, /*!< PWM4预分频为Fhrc/12  */
	PWM4_PRESSEL_FHRC_D1  = (uint8_t)0x14, /*!< PWM4预分频为Fosc/1  */
} PWM_PresSel_TypeDef;
/**
 * @}
 */

/** @brief PWM_Type_TypeDef PWM Type
 * @{
 */
typedef enum
{
  PWM0_Type = (uint8_t)0x00, /*!< 操作PWM0  */
  PWM2_Type = (uint8_t)0x02, /*!< 操作PWM2  */
  PWM3_Type = (uint8_t)0x03, /*!< 操作PWM3  */
  PWM4_Type = (uint8_t)0x04, /*!< 操作PWM4  */
} PWM_Type_TypeDef;
/**
 * @}
 */

/** @brief PWM_Aligned_Mode_TypeDef PWM Aligned Mode
 * @{
 */
typedef enum
{
  PWM0_Edge_Aligned_Mode = (uint8_t)0x00,     /*!< PWM边沿对齐模式  */
  PWM0_Center_Alignment_Mode = (uint8_t)0x01, /*!< PWM中心对齐模式  */
} PWM_Aligned_Mode_TypeDef;
/**
 * @}
 */

/** @brief PWM_OutputPin_TypeDef PWM OutputPin
 * @{
 */
typedef enum
{
  PWM00 = (uint8_t)0x00, /*!< PWM输出通道选择: PWM00  */
  PWM01 = (uint8_t)0x01, /*!< PWM输出通道选择: PWM01  */
  PWM02 = (uint8_t)0x02, /*!< PWM输出通道选择: PWM02  */
  PWM03 = (uint8_t)0x03, /*!< PWM输出通道选择: PWM03  */
  PWM04 = (uint8_t)0x04, /*!< PWM输出通道选择: PWM04  */
  PWM05 = (uint8_t)0x05, /*!< PWM输出通道选择: PWM05  */
  PWM06 = (uint8_t)0x06, /*!< PWM输出通道选择: PWM06  */
  PWM07 = (uint8_t)0x07, /*!< PWM输出通道选择: PWM07  */
  PWM20 = (uint8_t)0x20, /*!< PWM输出通道选择: PWM20  */
  PWM21 = (uint8_t)0x21, /*!< PWM输出通道选择: PWM21  */
#if !defined(SC92F552x)
  PWM30 = (uint8_t)0x32, /*!< PWM输出通道选择: PWM30  */
#endif
  PWM31 = (uint8_t)0x33, /*!< PWM输出通道选择: PWM31  */
  PWM40 = (uint8_t)0x44, /*!< PWM输出通道选择: PWM40  */
  PWM41 = (uint8_t)0x45, /*!< PWM输出通道选择: PWM41  */
} PWM_OutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM_ComplementaryOutputPin_TypeDef PWM Complementary OutputPin
 * @{
 */
typedef enum
{
  PWM00PWM01 = (uint8_t)0x00, /*!< PWM互补模式通道选择:PWM00、PWM01 */
  PWM02PWM03 = (uint8_t)0x02, /*!< PWM互补模式通道选择:PWM02、PWM03 */
  PWM04PWM05 = (uint8_t)0x04, /*!< PWM互补模式通道选择:PWM04、PWM05 */
  PWM06PWM07 = (uint8_t)0x06  /*!< PWM互补模式通道选择:PWM06、PWM07 */
} PWM_ComplementaryOutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM_FaultDetectionMode_TypeDef PWM Fault Detection Mode
 * @{
 */
typedef enum
{
  PWM_Latch_Mode = ((uint8_t)0x00),    /*!< PWM故障检测模式:锁存模式 */
  PWM_Immediate_Mode = ((uint8_t)0x20) /*!< PWM故障检测模式:立即模式 */
} PWM_FaultDetectionMode_TypeDef;
/**
 * @}
 */

/** @brief PWM_FaultDetectionVoltageSelect_TypeDef PWM Fault Detection Voltage Select
 * @{
 */
typedef enum
{
  PWM_FaultDetectionVoltage_Low = ((uint8_t)0x00), /*!< PWM故障检测低电平选择 */
  PWM_FaultDetectionVoltage_high = ((uint8_t)0x10) /*!< PWM故障检测高电平选择 */
} PWM_FaultDetectionVoltageSelect_TypeDef;
/**
 * @}
 */

/** @brief PWM_FaultDetectionWaveFilteringTime_TypeDef PWM Fault Detection WaveFiltering Time
 * @{
 */
typedef enum
{
  PWM_WaveFilteringTime_0us = ((uint8_t)0x00), /*!< PWM故障检测输入信号滤波时间0us */
  PWM_WaveFilteringTime_1us = ((uint8_t)0x01), /*!< PWM故障检测输入信号滤波时间1us */
  PWM_WaveFilteringTime_4us = ((uint8_t)0x02), /*!< PWM故障检测输入信号滤波时间4us */
  PWM_WaveFilteringTime_16us = ((uint8_t)0x03) /*!< PWM故障检测输入信号滤波时间16us */
} PWM_FaultDetectionWaveFilteringTime_TypeDef;
/**
 * @}
 */

/** @brief PWM21_PortMappingPin_TypeDef PWM21 Port Mapping Pins
 * @{
 */
#if defined (SC92F663x)
typedef enum
{
  PWM00Mapped_to_P45 = (uint8_t)0x00, /*!< PWM00映射到P45 */
  PWM00Mapped_to_P44 = (uint8_t)0x01, /*!< PWM00映射到P44 */
  PWM00Mapped_to_P42 = (uint8_t)0x02, /*!< PWM00映射到P42 */
  PWM00Mapped_to_P41 = (uint8_t)0x03, /*!< PWM00映射到P41 */
	PWM00Mapped_to_P37 = (uint8_t)0x04, /*!< PWM00映射到P37 */
	PWM00Mapped_to_P36 = (uint8_t)0x05, /*!< PWM00映射到P36 */
  PWM00Mapped_to_P35 = (uint8_t)0x06, /*!< PWM00映射到P35 */
  PWM00Mapped_to_P34 = (uint8_t)0x07, /*!< PWM00映射到P34 */
	PWM01Mapped_to_P05 = (uint8_t)0x10, /*!< PWM01映射到P05 */
	PWM01Mapped_to_P06 = (uint8_t)0x11, /*!< PWM01映射到P06 */
	PWM01Mapped_to_P50 = (uint8_t)0x12, /*!< PWM01映射到P50 */
  PWM01Mapped_to_P51 = (uint8_t)0x13, /*!< PWM01映射到P51 */
  PWM01Mapped_to_P52 = (uint8_t)0x14, /*!< PWM01映射到P52 */
  PWM01Mapped_to_P53 = (uint8_t)0x15, /*!< PWM01映射到P53 */
  PWM01Mapped_to_P00 = (uint8_t)0x16, /*!< PWM01映射到P00 */
	PWM01Mapped_to_P01 = (uint8_t)0x17, /*!< PWM01映射到P01 */
} PWM0_PortMappingPin_TypeDef;

typedef enum
{
  PWM20Mapped_to_P51 = (uint8_t)0x00, /*!< PWM20映射到P51 */
	PWM20Mapped_to_P44 = (uint8_t)0x01, /*!< PWM20映射到P44 */
	PWM20Mapped_to_P43 = (uint8_t)0x02, /*!< PWM20映射到P43 */
  PWM20Mapped_to_P42 = (uint8_t)0x03, /*!< PWM20映射到P42 */
  PWM20Mapped_to_P41 = (uint8_t)0x04, /*!< PWM20映射到P41 */
  PWM20Mapped_to_P40 = (uint8_t)0x05, /*!< PWM20映射到P40 */
  PWM20Mapped_to_P37 = (uint8_t)0x06, /*!< PWM20映射到P37 */
	PWM20Mapped_to_P36 = (uint8_t)0x07, /*!< PWM20映射到P36 */
} PWM20_PortMappingPin_TypeDef;

typedef enum
{
  PWM21Mapped_to_P45 = (uint8_t)0x00, /*!< PWM21映射到P45 */
  PWM21Mapped_to_P44 = (uint8_t)0x01, /*!< PWM21映射到P44 */
  PWM21Mapped_to_P42 = (uint8_t)0x02, /*!< PWM21映射到P42 */
  PWM21Mapped_to_P41 = (uint8_t)0x03, /*!< PWM21映射到P41 */
	PWM21Mapped_to_P37 = (uint8_t)0x04, /*!< PWM21映射到P37 */
	PWM21Mapped_to_P36 = (uint8_t)0x05, /*!< PWM21映射到P36 */
  PWM21Mapped_to_P35 = (uint8_t)0x06, /*!< PWM21映射到P35 */
  PWM21Mapped_to_P34 = (uint8_t)0x07, /*!< PWM21映射到P34 */
  PWM21Mapped_to_P33 = (uint8_t)0x08, /*!< PWM21映射到P33 */
	PWM21Mapped_to_P32 = (uint8_t)0x09, /*!< PWM21映射到P32 */
	PWM21Mapped_to_P31 = (uint8_t)0x0A, /*!< PWM21映射到P31 */
  PWM21Mapped_to_P30 = (uint8_t)0x0B, /*!< PWM21映射到P30 */
	PWM31Mapped_to_P02 = (uint8_t)0x10, /*!< PWM31映射到P02 */
  PWM31Mapped_to_P03 = (uint8_t)0x11, /*!< PWM31映射到P03 */
  PWM31Mapped_to_P04 = (uint8_t)0x12, /*!< PWM31映射到P04 */
  PWM31Mapped_to_P05 = (uint8_t)0x13, /*!< PWM31映射到P05 */
	PWM31Mapped_to_P06 = (uint8_t)0x14, /*!< PWM31映射到P06 */
	PWM31Mapped_to_P50 = (uint8_t)0x15, /*!< PWM31映射到P50 */
  PWM31Mapped_to_P51 = (uint8_t)0x16, /*!< PWM31映射到P51 */
  PWM31Mapped_to_P52 = (uint8_t)0x17, /*!< PWM31映射到P52 */
  PWM31Mapped_to_P53 = (uint8_t)0x18, /*!< PWM31映射到P53 */
	PWM31Mapped_to_P26 = (uint8_t)0x19, /*!< PWM31映射到P26 */
	PWM31Mapped_to_P27 = (uint8_t)0x1A, /*!< PWM31映射到P27 */
  PWM31Mapped_to_P00 = (uint8_t)0x1B, /*!< PWM31映射到P00 */
	PWM31Mapped_to_P01 = (uint8_t)0x1C, /*!< PWM31映射到P01 */
} PWMX1_PortMappingPin_TypeDef;

#else
typedef enum
{
  Mapped_to_P50 = (uint8_t)0x00, /*!< PWM21映射到P50 */
  Mapped_to_P51 = (uint8_t)0x01, /*!< PWM21映射到P51 */
  Mapped_to_P52 = (uint8_t)0x02, /*!< PWM21映射到P52 */
  Mapped_to_P53 = (uint8_t)0x03, /*!< PWM21映射到P53 */
	Mapped_to_P54 = (uint8_t)0x04, /*!< PWM21映射到P54 */
	Mapped_to_P56 = (uint8_t)0x06, /*!< PWM21映射到P56 */
  Mapped_to_P57 = (uint8_t)0x07, /*!< PWM21映射到P57 */
  Mapped_to_P10 = (uint8_t)0x08, /*!< PWM21映射到P10 */
  Mapped_to_P11 = (uint8_t)0x09, /*!< PWM21映射到P11 */
	Mapped_to_P12 = (uint8_t)0x0A, /*!< PWM21映射到P12 */
	Mapped_to_P13 = (uint8_t)0x0B, /*!< PWM21映射到P13 */
  Mapped_to_P14 = (uint8_t)0x0C, /*!< PWM21映射到P14 */
  Mapped_to_P15 = (uint8_t)0x0D, /*!< PWM21映射到P15 */
  Mapped_to_P16 = (uint8_t)0x0E, /*!< PWM21映射到P16 */
	Mapped_to_P17 = (uint8_t)0x0F, /*!< PWM21映射到P17 */
	Mapped_to_P27 = (uint8_t)0x10, /*!< PWM21映射到P27 */
  Mapped_to_P26 = (uint8_t)0x11, /*!< PWM21映射到P26 */
  Mapped_to_P25 = (uint8_t)0x12, /*!< PWM21映射到P25 */
  Mapped_to_P24 = (uint8_t)0x13, /*!< PWM21映射到P24 */
	Mapped_to_P23 = (uint8_t)0x14, /*!< PWM21映射到P23 */
	Mapped_to_P22 = (uint8_t)0x15, /*!< PWM21映射到P22 */
  Mapped_to_P21 = (uint8_t)0x16, /*!< PWM21映射到P21 */
  Mapped_to_P20 = (uint8_t)0x17, /*!< PWM21映射到P20 */
  Mapped_to_P07 = (uint8_t)0x18, /*!< PWM21映射到P07 */
  Mapped_to_P06 = (uint8_t)0x19, /*!< PWM21映射到P06 */
	Mapped_to_P05 = (uint8_t)0x1A, /*!< PWM21映射到P05 */
  Mapped_to_P04 = (uint8_t)0x1B, /*!< PWM21映射到P04 */
  Mapped_to_P03 = (uint8_t)0x1C, /*!< PWM21映射到P03 */
  Mapped_to_P02 = (uint8_t)0x1D, /*!< PWM21映射到P02 */
	Mapped_to_P01 = (uint8_t)0x1E, /*!< PWM21映射到P01 */
	Mapped_to_P00 = (uint8_t)0x1F, /*!< PWM21映射到P00 */
} PWM21_PortMappingPin_TypeDef;
#endif
/**
 * @}
 */
#elif defined(SC92F5x5x)
/** @brief PWM_PresSel_TypeDef PWM Prescaler
 * @{
 */
typedef enum
{
  PWM0_PRESSEL_FOSC_D1 = (uint8_t)0x00, //PWM0预分频为Fosc/1
  PWM0_PRESSEL_FOSC_D2 = (uint8_t)0x10, //PWM0预分频为Fosc/2
  PWM0_PRESSEL_FOSC_D4 = (uint8_t)0x20, //PWM0预分频为Fosc/4
  PWM0_PRESSEL_FOSC_D8 = (uint8_t)0x30, //PWM0预分频为Fosc/8
  PWM2_PRESSEL_FHRC_D12 = (uint8_t)0x02, //PWM2预分频为Fhrc/12
  PWM2_PRESSEL_FHRC_D1 = (uint8_t)0x12, //PWM2预分频为Fhrc/1
} PWM_PresSel_TypeDef;
/**
 * @}
 */

/** @brief PWM_Type_TypeDef PWM Type
 * @{
 */
typedef enum
{
  PWM0_Type = (uint8_t)0x00, /*!< 操作PWM0 */
  PWM2_Type = (uint8_t)0x02, /*!< 操作PWM2 */
} PWM_Type_TypeDef;
/**
 * @}
 */

/** @brief PWM_OutputPin_TypeDef PWM OutputPin
 * @{
 */
typedef enum
{
  PWM00 = (uint8_t)0x00, /*!< PWM输出通道选择: PWM00  */
  PWM01 = (uint8_t)0x01, /*!< PWM输出通道选择: PWM01  */
  PWM04 = (uint8_t)0x04, /*!< PWM输出通道选择: PWM04  */
  PWM05 = (uint8_t)0x05, /*!< PWM输出通道选择: PWM05  */
  PWM06 = (uint8_t)0x06, /*!< PWM输出通道选择: PWM06  */
  PWM21 = (uint8_t)0x21, /*!< PWM输出通道选择: PWM21  */
} PWM_OutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM_ComplementaryOutputPin_TypeDef PWM Complementary OutputPin
 * @{
 */
typedef enum
{
  PWM00PWM01 = (uint8_t)0x00, /*!< PWM互补模式通道选择:PWM00、PWM01 */
  PWM04PWM05 = (uint8_t)0x04, /*!< PWM互补模式通道选择:PWM04、PWM05 */
} PWM_ComplementaryOutputPin_TypeDef;
/**
 * @}
 */

/** @brief PWM21_PortMappingPin_TypeDef PWM21 Port Mapping Pins
 * @{
 */
typedef enum
{
  Mapped_to_P00 = (uint8_t)0x00, /*!< PWM21映射到P00 */
  Mapped_to_P01 = (uint8_t)0x01, /*!< PWM21映射到P01 */
  Mapped_to_P05 = (uint8_t)0x05, /*!< PWM21映射到P05 */
  Mapped_to_P20 = (uint8_t)0x08, /*!< PWM21映射到P20 */
	Mapped_to_P21 = (uint8_t)0x09, /*!< PWM21映射到P21 */
	Mapped_to_P22 = (uint8_t)0x0A, /*!< PWM21映射到P22 */
  Mapped_to_P23 = (uint8_t)0x0B, /*!< PWM21映射到P23 */
  Mapped_to_P24 = (uint8_t)0x0C, /*!< PWM21映射到P24 */
  Mapped_to_P25 = (uint8_t)0x0D, /*!< PWM21映射到P25 */
	Mapped_to_P26 = (uint8_t)0x0E, /*!< PWM21映射到P26 */
	Mapped_to_P13 = (uint8_t)0x14, /*!< PWM21映射到P13 */
	Mapped_to_P12 = (uint8_t)0x15, /*!< PWM21映射到P12 */
  Mapped_to_P11 = (uint8_t)0x16, /*!< PWM21映射到P11 */
  Mapped_to_P10 = (uint8_t)0x19, /*!< PWM21映射到P10 */
} PWM21_PortMappingPin_TypeDef;
/**
 * @}
 */
#elif defined(SC92F637x)
/** @brief PWM_PresSel_TypeDef PWM Prescaler
 * @{
 */
typedef enum
{
  PWM2_PRESSEL_FHRC_D12 = (uint8_t)0x02, //PWM2预分频为Fhrc/12
  PWM2_PRESSEL_FHRC_D1 = (uint8_t)0x12, //PWM2预分频为Fhrc/1
	PWM3_PRESSEL_FHRC_D12 = (uint8_t)0x03, //PWM3预分频为Fhrc/12
  PWM3_PRESSEL_FHRC_D1 = (uint8_t)0x13, //PWM3预分频为Fhrc/1
} PWM_PresSel_TypeDef;
/**
 * @}
 */

/** @brief PWM_Type_TypeDef PWM Type
 * @{
 */
typedef enum
{
  PWM2_Type = (uint8_t)0x02, /*!< 操作PWM2 */
  PWM3_Type = (uint8_t)0x03, /*!< 操作PWM3 */
} PWM_Type_TypeDef;
/**
 * @}
 */

/** @brief PWM_OutputPin_TypeDef PWM OutputPin
 * @{
 */
typedef enum
{
  PWM20 = (uint8_t)0x20, /*!< PWM输出通道选择: PWM20  */
	PWM21 = (uint8_t)0x21, /*!< PWM输出通道选择: PWM21  */
	PWM30 = (uint8_t)0x32, /*!< PWM输出通道选择: PWM30  */
	PWM31 = (uint8_t)0x33, /*!< PWM输出通道选择: PWM31  */
} PWM_OutputPin_TypeDef;
/**
 * @}
 */
#endif

/** @brief PWM_FaultDetectionWaveFilteringTime_TypeDef PWM Fault Detection WaveFiltering Time
 * @{
 */
typedef enum
{ 
  PWM_OUTPUTSTATE_DISABLE	= ((uint8_t)0x00),	/*!< 该PIN脚作为GPIO */
  PWM_OUTPUTSTATE_ENABLE	= ((uint8_t)0x01)	/*!< 该PIN脚作为PWM */
} PWM_OutputState_TypeDef;
/**
 * @}
 */

/** @brief PWM_Polarity_TypeDef PWM Polarity
 * @{
 */
typedef enum
{
  PWM_POLARITY_NON_INVERT	= ((uint8_t)0x00),	/*!< PWM输出不反向 */
  PWM_POLARITY_INVERT		= ((uint8_t)0x01)	/*!< PWM输出反向 */
} PWM_Polarity_TypeDef;
/**
 * @}
 */

/** @brief PWM_DutyChange_TypeDef PWM DutyChange
 * @{
 */
typedef enum
{
  PWM_DutyChange_Up = (uint8_t)0x01, 		/*!< PWM占空比增加 */
  PWM_DutyChange_Dowm = (uint8_t)0x00, 	    /*!< PWM占空比减少 */
} PWM_DutyChange_TypeDef;
/**
 * @}
 */
/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup PWM_Functions PWM Functions
 * @{
 */

/* PWM Base functions ********************************************************/
void PWM_DeInit(void);
void PWM_Init(PWM_PresSel_TypeDef PWM_PresSel,
              uint16_t PWM_Period);
void PWM_OutputStateConfig(uint8_t PWM_OutputPin,
                           PWM_OutputState_TypeDef PWM_OutputState);
void PWM_PolarityConfig(uint8_t PWM_OutputPin,
                        PWM_Polarity_TypeDef PWM_Polarity);
void PWM_IndependentModeConfig(PWM_OutputPin_TypeDef PWM_OutputPin,
                               uint16_t PWM_DutyCycle);
ErrorStatus PWM_IndependentMode_DutyChange(PWM_OutputPin_TypeDef PWM_OutputPin,
    PWM_DutyChange_TypeDef Change_Direction,
    uint16_t DutyIncremental);
void PWM_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority);

#if defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) ||defined(SC92F6x1x) \
    || defined(SC92F5x1x)||  defined(SC92R436)||  defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)|| defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)\
    || defined(SC92F5x5x) || defined(SC92F531x) || defined(SC92F637x) || defined(SC92F663x) || defined(SC92F563x)
void PWM_DeInitEX(PWM_Type_TypeDef PWM_Type);
void PWM_IndependentModeConfigEX(PWM_OutputPin_TypeDef PWM_OutputPin,
                                 uint16_t PWM_DutyCycle,
                                 PWM_OutputState_TypeDef PWM_OutputState);
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) ||defined(SC92F6x1x)||defined(SC92F5x1x)||  defined(SC92R436)\
    || defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)|| defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F5x5x)|| defined(SC92F531x)\
		|| defined(SC92F663x) || defined(SC92F563x)
void PWM_ComplementaryModeConfigEX(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
                                   uint16_t PWM_DutyCycle,
                                   PWM_OutputState_TypeDef PWM_OutputState);
void PWM_ComplementaryModeConfig(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
                                 uint16_t PWM_DutyCycle);
void PWM_DeadTimeConfig(uint8_t PWM_RisingDeadTime, uint8_t PWM_FallingDeadTime);
#if !defined(SC92F5x5x)
void PWM_Aligned_Mode_Select(PWM_Aligned_Mode_TypeDef PWM_Aligned_Mode);
FlagStatus PWM_GetFaultDetectionFlagStatusEX(PWM_Type_TypeDef PWM_Type);
void PWM_ClearFaultDetectionFlagEX(PWM_Type_TypeDef PWM_Type);
void PWM_FaultDetectionConfigEX(PWM_Type_TypeDef PWM_Type, FunctionalState NewState);
void PWM_FaultDetectionModeConfigEX(PWM_Type_TypeDef PWM_Type,
	                                PWM_FaultDetectionMode_TypeDef FaultDetectionMode,
                                  PWM_FaultDetectionVoltageSelect_TypeDef FaultDetectionVoltageSelect,
                                  PWM_FaultDetectionWaveFilteringTime_TypeDef FaultDetectionWaveFilteringTime);
#endif
ErrorStatus PWM_ComplementaryMode_DutyChange(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
                                                     PWM_DutyChange_TypeDef Change_Direction, uint16_t DutyIncremental);
#endif
void PWM_CmdEX(PWM_Type_TypeDef PWM_Type, FunctionalState NewState);
void PWM_ITConfigEX(PWM_Type_TypeDef PWM_Type, FunctionalState NewState, PriorityStatus Priority);
FlagStatus PWM_GetFlagStatusEX(PWM_Type_TypeDef PWM_Type);
void PWM_ClearFlagEX(PWM_Type_TypeDef PWM_Type);
#else
void PWM_Cmd(FunctionalState NewState);
FlagStatus PWM_GetFlagStatus(void);
void PWM_ClearFlag(void);
#endif

#if defined (SC92FWxx) || defined (SC92L853x) || defined (SC92L753x) || defined (SC92L840x)
#if !defined (SC92FWxx)
void PWM_ComplementaryModeConfig(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
                                 uint16_t PWM_DutyCycle);
void PWM_Aligned_Mode_Select(PWM_Aligned_Mode_TypeDef PWM_Aligned_Mode);
void PWM_FaultDetectionModeConfigEX(PWM_Type_TypeDef PWM_Type,
                                    PWM_FaultDetectionMode_TypeDef FaultDetectionMode,
                                    PWM_FaultDetectionVoltageSelect_TypeDef FaultDetectionVoltageSelect,
                                    PWM_FaultDetectionWaveFilteringTime_TypeDef FaultDetectionWaveFilteringTime);
#endif
void PWM_CmdEX(PWM_Type_TypeDef PWM_Type,
               FunctionalState NewState);
FlagStatus PWM_GetFlagStatusEX(PWM_Type_TypeDef PWM_Type);
void PWM_ClearFlagEX(PWM_Type_TypeDef PWM_Type);
void PWM_IndependentModeConfigEX(PWM_OutputPin_TypeDef PWM_OutputPin, uint16_t PWM_DutyCycle,
                                 PWM_OutputState_TypeDef PWM_OutputState);

void PWM_ITConfigEX(PWM_Type_TypeDef PWM_Type, FunctionalState NewState, PriorityStatus Priority);
FlagStatus PWM_GetFaultDetectionFlagStatusEX(PWM_Type_TypeDef PWM_Type);
void PWM_ClearFaultDetectionFlagEX(PWM_Type_TypeDef PWM_Type);
void PWM_FaultDetectionConfigEX(PWM_Type_TypeDef PWM_Type, FunctionalState NewState);
#else
void PWM_Cmd(FunctionalState NewState);
FlagStatus PWM_GetFlagStatus(void);
void PWM_ClearFlag(void);
#endif

/* 复用通道以及死区配置函数 */
#if defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB)|| defined (SC92F83Ax) || defined (SC92F73Ax)\
		|| defined (SC92F84Ax) || defined (SC92F74Ax)|| defined (SC92F7003) || defined (SC92F8003) || defined(SC92F8003B) || defined (SC92F740x)\
		|| defined (SC92F848x) || defined (SC92F748x)  || defined (SC92F848x) || defined (SC92F748x) || defined (SC92R342)\
		|| defined (SC92F841x) || defined (SC92F741x)|| defined (SC92Fx41xB) || defined (SC92R445)
void PWM_ComplementaryModeConfig(PWM_ComplementaryOutputPin_TypeDef
                                 PWM_ComplementaryOutputPin,
                                 uint16_t PWM_DutyCycle);
ErrorStatus PWM_ComplementaryMode_DutyChange(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
    PWM_DutyChange_TypeDef Change_Direction,
    uint16_t DutyIncremental);
void PWM_DeadTimeConfig(uint8_t PWM012_RisingDeadTime, uint8_t PWM345_fallingDeadTime);

#endif
#if defined (SC92L853x) || defined (SC92L753x)|| defined (SC92L840x)
void PWM_DeadTimeConfigEX(PWM_Type_TypeDef PWM_Type, uint8_t PWM_RisingDeadTime, uint8_t PWM_FallingDeadTime);
#endif
/* PWM输出通道选择 */
#if defined (SC92F8003) || defined(SC92F8003B) || defined (SC92F740x) || defined (SC92F7003)
void PWM_PWM2Selection(PWM2_OutputPin_TypeDef PWM2_OutputPin);
void PWM_PWM5Selection(PWM5_OutputPin_TypeDef PWM5_OutputPin);
#endif
#if defined (SC92F732X) ||  defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x)
void PWM_PWM0Selection(PWM0_OutputPin_TypeDef PWM0_OutputPin);
void PWM_PWM1Selection(PWM1_OutputPin_TypeDef PWM1_OutputPin);
void PWM_PWM2Selection(PWM2_OutputPin_TypeDef PWM2_OutputPin);
void PMM_DutyModeSelection(PWM_OutputPin_TypeDef PWM_OutputPin, PWM_DutyMode_TypeDef PWM_DutyMode);
#endif
#if defined (SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)|| defined(SC92F5x5x) || defined(SC92F531x)
void PWM21_PortMapping(PWM21_PortMappingPin_TypeDef PWM21_MappingPin);
#endif
#if defined (SC92F663x)
void PWM0_PortMapping(PWM0_PortMappingPin_TypeDef PWM0_MappingPin);
void PWM20_PortMapping(PWM20_PortMappingPin_TypeDef PWM20_MappingPin);
void PWMX1_PortMapping(PWMX1_PortMappingPin_TypeDef PWMX1_MappingPin);
#endif
/**
 * @}
 */
/* End of functions --------------------------------------------------*/

#endif
/**
 * @}
 */

/**
 * @}
 */
#endif
/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/