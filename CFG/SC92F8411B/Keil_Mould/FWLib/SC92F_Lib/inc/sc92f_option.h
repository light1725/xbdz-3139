/**
 ******************************************************************************
 * @file    sc92f_option.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of OPTION module.
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
#ifndef _sc92f_OPTION_H_
#define	_sc92f_OPTION_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @addtogroup OPTION
 * @{
 */

/** @defgroup OPTION_Enumerations OPTION Enumerations
 * @{
 */
 
 /** @brief SYSCLK clock Source
 * @{
 */
#if defined (SC92L853x) || defined (SC92L753x)
typedef enum
{
  SYSCLK_PRESSEL_FOSC_D1  = (uint8_t)0x00,	/*!< Fsys = Fosc/1   */
  SYSCLK_PRESSEL_FOSC_D2  = (uint8_t)0x10,	/*!< Fsys = Fosc/2   */
  SYSCLK_PRESSEL_FOSC_D4  = (uint8_t)0x20,	/*!< Fsys = Fosc/4   */
  SYSCLK_PRESSEL_FOSC_D8  = (uint8_t)0x30 	/*!< Fsys = Fosc/8   */
} SYSCLK_PresSel_TypeDef;
#elif defined (SC92R436) ||defined (SC92R438) || defined(SC92L840x)|| defined(SC92R439)|| defined(SC92R422A)
typedef enum
{
  SYSCLK_PRESSEL_FOSC_D2  = (uint8_t)0x10,	/*!< Fsys = Fosc/2   */
  SYSCLK_PRESSEL_FOSC_D4  = (uint8_t)0x20,	/*!< Fsys = Fosc/4   */
  SYSCLK_PRESSEL_FOSC_D12 = (uint8_t)0x30 	/*!< Fsys = Fosc/12   */
} SYSCLK_PresSel_TypeDef;
#else
typedef enum
{
  SYSCLK_PRESSEL_FOSC_D1  = (uint8_t)0x00,	/*!< Fsys = Fosc/1   */
  SYSCLK_PRESSEL_FOSC_D2  = (uint8_t)0x10,	/*!< Fsys = Fosc/2   */
  SYSCLK_PRESSEL_FOSC_D4  = (uint8_t)0x20,	/*!< Fsys = Fosc/4   */
  SYSCLK_PRESSEL_FOSC_D12 = (uint8_t)0x30 	/*!< Fsys = Fosc/12   */
} SYSCLK_PresSel_TypeDef;
#endif
/**
 * @}
 */

/** @brief OPTION_LVR  LVR stalls 
 * @{
 */
#if defined (SC92F859x) || defined (SC92F759x) || defined (SC92F848x) || defined (SC92F748x) || defined (SC92R511x) || defined (SC92F663x)\
    || defined (SC92F563x)
typedef enum
{
  LVR_INVALID	= (uint8_t)0x04,	/*!< LVR invalid  */
  LVR_1_9V    = (uint8_t)0x00,	    /*!< LVR 1.9V reset  */
  LVR_2_9V    = (uint8_t)0x01,	    /*!< LVR 2.9V reset  */
  LVR_3_7V    = (uint8_t)0x02,	    /*!< LVR 3.7V reset  */
  LVR_4_3V    = (uint8_t)0x03 	    /*!< LVR 4.3V reset  */
} LVR_Config_TypeDef;
#elif defined (SC92L853x) || defined (SC92L753x)
typedef enum
{
  LVR_INVALID	= (uint8_t)0x04,	/*!< LVR invalid  */
  LVR_1_7V    = (uint8_t)0x00,	/*!< LVR 1.7V reset  */
  LVR_2_7V    = (uint8_t)0x01,	/*!< LVR 2.7V reset  */
  LVR_3_7V    = (uint8_t)0x02,	/*!< LVR 3.7V reset  */
  LVR_4_3V    = (uint8_t)0x03 	/*!< LVR 4.3V reset  */
} LVR_Config_TypeDef;
#elif defined (SC92L840x) 
typedef enum
{
  LVR_INVALID	= (uint8_t)0x04,	/*!< LVR invalid  */
  LVR_1_7V    = (uint8_t)0x00,	/*!< LVR 1.7V reset  */
  LVR_1_9V    = (uint8_t)0x01,	/*!< LVR 1.9V reset  */
  LVR_2_3V    = (uint8_t)0x02,	/*!< LVR 2.3V reset  */
  LVR_2_7V    = (uint8_t)0x03 	/*!< LVR 2.7V reset  */
} LVR_Config_TypeDef;
#else
typedef enum
{
  LVR_INVALID	= (uint8_t)0x04,	/*!< LVR invalid  */
  LVR_2_3V    = (uint8_t)0x00,	/*!< LVR 2.3V reset  */
  LVR_2_9V    = (uint8_t)0x01,	/*!< LVR 2.9V reset  */
  LVR_3_7V    = (uint8_t)0x02,	/*!< LVR 3.7V reset  */
  LVR_4_3V    = (uint8_t)0x03 	/*!< LVR 4.3V reset  */
} LVR_Config_TypeDef;
#endif
/**
 * @}
 */

/** @brief IAP_OperateRange  Address range that allows IAP operations
 * @{
 */
#if !defined(SC92F5x5x) && !defined(SC92F531x) && !defined(SC92F637x)
#if defined (SC92F848x) || defined (SC92F748x) || defined (SC92L853x) || defined (SC92L753x) || defined (SC92F663x) || defined (SC92F563x)
typedef enum
{
  IAP_OPERATERANGE_ONLY_EEPROM 		    = (uint8_t)0x00,	 /*!< Only IAP operations on EEPROM  */
  IAP_OPERATERANGE__LAST_1K_CODEREGION  = (uint8_t)0x04,	 /*!< Only IAP operations in the last 1k of FLASH  */
  IAP_OPERATERANGE__LAST_2K_CODEREGION  = (uint8_t)0x08,	 /*!< Only IAP operations in the last 2k of FLASH  */
  IAP_OPERATERANGE__ALL_CODEREGION 	    = (uint8_t)0x0c	     /*!< Allow IAP operations in the all of FLASH */
} IAP_OperateRange_TypeDef;
#elif defined (SC92L840x)
typedef enum
{
  IAP_OPERATERANGE_ONLY_EEPROM 		    = (uint8_t)0x00,	 /*!< Only IAP operations on EEPROM  */
  IAP_OPERATERANGE__ALL_CODEREGION 	   = (uint8_t)0x0c	     /*!< Allow IAP operations in the all of FLASH */
} IAP_OperateRange_TypeDef;
#else
typedef enum
{
  IAP_OPERATERANGE_ONLY_EEPROM 		    = (uint8_t)0x00,	/*!< Only IAP operations on EEPROM  */
  IAP_OPERATERANGE__LAST_0_5K_CODEREGION  = (uint8_t)0x04,	/*!< Only IAP operations in the last 0.5k of FLASH  */
  IAP_OPERATERANGE__LAST_1K_CODEREGION    = (uint8_t)0x08,	/*!< Only IAP operations in the last 1k of FLASH  */
  IAP_OPERATERANGE__ALL_CODEREGION 	    = (uint8_t)0x0c		/*!< Allow IAP operations in the all of FLASH */
} IAP_OperateRange_TypeDef;
#endif
#endif
/**
 * @}
 */

/** @brief ADC_Vref  Reference voltage value for ADC
 * @{
 */
#if !defined(SC92F637x)
#if defined (SC92F859x) || defined (SC92F759x) || defined (SC92F848x) || defined (SC92F748x) || defined (SC92L853x) || defined (SC92L753x)\
		|| defined (SC92R511x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined (SC92F6x1x) || defined (SC92F5x1x)\
    || defined(SC92R436) || defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)|| defined(SC92F652x)|| defined(SC92R51x_R52x)\
    || defined (SC92F552x)|| defined(SC92F5x5x) || defined(SC92F531x) || defined(SC92F663x) || defined(SC92F563x)
typedef enum
{
  ADC_VREF_VDD  = 0x00,				    /*!< VDD as the ADC reference voltage */
  ADC_VREF_1_024V = 0x40,   		    /*!< the internal 1.024V as the ADC reference voltage value */
  ADC_VREF_2_4V = 0x80,   			    /*!< the internal 2.4V as the ADC reference voltage value */
  ADC_VREF_2_048V = 0xC0,				/*!< the internal 2.048V as the ADC reference voltage value */
} ADC_Vref_TypeDef;

#elif defined (SC92L840x)

typedef enum
{
  ADC_VREF_VDD  = 0x00,				    /*!< VDD as the ADC reference voltage */
  ADC_VREF_1_024V = 0x80,   			    /*!< internal 2.4V as the ADC reference voltage value */
} ADC_Vref_TypeDef;

#else

typedef enum
{
  ADC_VREF_VDD  = 0x00,				    /*!< VDD as the ADC reference voltage */
  ADC_VREF_2_4V = 0x80,   			    /*!< internal 2.4V as the ADC reference voltage value */
} ADC_Vref_TypeDef;
#endif
#endif
/**
 * @}
 */

/** @brief XTIPLL_Range  Selection of external crystal oscillator frequency
 * @{
 */
#if defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB)|| defined (SC92F83Ax)\
	|| defined (SC92F73Ax) || defined (SC92F84Ax) || defined (SC92F74Ax) || defined (SC92F740x)\
	|| defined (SC92F848x) || defined (SC92F748x) || defined (SC92F8003) || defined(SC92F8003B) || defined (SC92F7003) || defined (SC92R342)\
	|| defined (SC92F841x) || defined (SC92F741x) || defined (SC92L840x)|| defined (SC92Fx41xB)|| defined (SC92R445)
typedef enum
{
  XTIPLL_HIGHER_THAN_12M  = (uint8_t)0x40,	/*!< XTIPPL frequency is greater than 12 MHz  */
  XTIPLL_UNDER_12M        = (uint8_t)0x00   /*!< XTIPPL frequency is less than 12 MHz */
} XTIPLL_Range_TypeDef;
#elif defined(SC92F563x)
typedef enum
{
  XTIPLL_HIGHER_THAN_12M  = (uint8_t)0x20,	/*!< XTIPPL frequency is greater than 12 MHz  */
  XTIPLL_UNDER_12M        = (uint8_t)0x00   /*!< XTIPPL frequency is less than 12 MHz */
} XTIPLL_Range_TypeDef;
#endif
/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup OPTION_Functions OPTION Functions
 * @{
 */

/* option configuration ********************************************************/
void OPTION_WDT_Cmd(FunctionalState NewState);

void OPTION_SYSCLK_Init(SYSCLK_PresSel_TypeDef
                        SYSCLK_PresSel);
#if !defined(SC92F848x) && !defined(SC92F748x) && !defined(SC92F859x) && !defined (SC92F759x)  && !defined(SC92L853x) && !defined (SC92L753x)\
		&& !defined(SC92R511x)&& !defined(SC92L840x)
void OPTION_RST_PIN_Cmd(FunctionalState NewState);
#endif
void OPTION_LVR_Init(LVR_Config_TypeDef LVR_Config);
#if !defined(SC92F637x)
void OPTION_ADC_VrefConfig(ADC_Vref_TypeDef ADC_Vref);
#endif
#if !defined(SC92F5x5x) && !defined(SC92F531x) && !defined(SC92F637x)
void OPTION_IAP_SetOperateRange(IAP_OperateRange_TypeDef IAP_OperateRange);
#endif
#if defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB)|| defined (SC92F83Ax)\
	|| defined (SC92F73Ax) || defined (SC92F84Ax) || defined (SC92F74Ax) || defined (SC92F740x)\
	|| defined (SC92F8003) || defined(SC92F8003B) || defined (SC92F7003) || defined (SC92R342) || defined (SC92F841x) || defined (SC92F741x)\
  || defined (SC92L840x) || defined (SC92Fx41xB)|| defined (SC92R445) || defined(SC92F563x)
void OPTION_XTIPLL_SetRange(XTIPLL_Range_TypeDef XTIPLL_Range);
#endif

#if !defined(SC92F848x) && !defined(SC92F748x) && !defined(SC92F730x_2) && !defined(SC92F720x) && !defined(SC92F5x5x) && !defined(SC92F531x)\
		&& !defined(SC92F637x) && !defined(SC92F663x)
void OPTION_XTIPLL_Cmd(FunctionalState NewState);
#endif

#if defined (SC92F742x)||defined (SC92F83Ax) || defined (SC92F73Ax)|| defined (SC92F84Ax) || defined (SC92F74Ax) \
		||defined (SC92F74Ax_2)||defined (SC92F84Ax_2)||defined (SC92F844xB)||defined (SC92F744xB)|| defined (SC92F7490) \
		||defined (SC92F859x) || defined (SC92F759x) ||defined (SC92F848x) || defined (SC92F748x) || defined (SC92L853x) || defined (SC92L753x)\
		|| defined (SC92R511x) || defined (SC92F84Hx) || defined (SC92F83Hx) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) \
    || defined(SC92F8003B)|| defined (SC92F6x1x) || defined (SC92F5x1x) || defined (SC92R436)|| defined (SC92R438) || defined(SC92L840x)|| defined(SC92R439)\
    || defined(SC92R445) || defined(SC92R422A) || defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)|| defined(SC92F5x5x) || defined(SC92F531x)\
		|| defined(SC92F637x) || defined(SC92F663x) || defined(SC92F563x)
void OPTION_JTG_Cmd(FunctionalState NewState);
#endif


#endif

/* End of exported functions --------------------------------------------------*/

/**
 * @}
 */

/**
 * @}
 */
 