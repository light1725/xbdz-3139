/**
 ******************************************************************************
 * @file    sc92f_option.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   option function module
 *          -This document is for the SinOne 92F/93F/92L series microcontrollers.
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
 
/* Includes ------------------------------------------------------------------*/
#include "sc92f_option.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup OPTION
 *  @brief option driver modules
 *  @{
 */
 
 /** @defgroup OPTION_Functions
 * @{
 */
 
 /** @defgroup OPTION_Group1 Configuration of the option computation unit functions
 *  @brief   Configuration of the option computation unit functions
 *
 
@verbatim
 ===============================================================================
                     ##### option configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */
  
  /**
  * @brief  Enables or disables the WDT peripheral.
  * @param  NewState[in]:  new state of the WDT peripheral.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable 
  * @retval None
  */
void OPTION_WDT_Cmd(FunctionalState NewState)
{
  OPINX = 0XC1;

  if(NewState == DISABLE)
  {
    OPREG &= 0X7F;
  }
  else
  {
    OPREG |= 0X80;
  } 
}

/**
  * @brief  Enables or disables the XTIPLL clock.
  * @param  NewState[in]: new state of the XTIPLL clock. 
  *                   - DISABLE:Function disable
  *                   - ENABLE:Function enable   
  * @retval None
  */
#if !defined(SC92F848x) && !defined(SC92F748x) && !defined(SC92F730x_2) && !defined(SC92F720x) && !defined(SC92F5x5x) && !defined(SC92F531x)\
		&& !defined(SC92F637x) && !defined(SC92F663x)
void OPTION_XTIPLL_Cmd(FunctionalState NewState)
{
  OPINX = 0XC1;

  if(NewState == DISABLE)
  {
    OPREG &= 0XBF;
  }
  else
  {
    OPREG |= 0X40;
  }
}
#endif
/**
  * @brief  System clock frequency initialization.
  * @param  SYSCLK_PresSel[in]: specifies the SYSCLK crossover frequencies. 
  *                   - SYSCLK_PRESSEL_FOSC_D1:SYSCLK clock = SYSCLK/1
  *                   - SYSCLK_PRESSEL_FOSC_D2:SYSCLK clock = SYSCLK/2 
  *                   - SYSCLK_PRESSEL_FOSC_D4:SYSCLK clock = SYSCLK/4
  *                   - SYSCLK_PRESSEL_FOSC_D12:SYSCLK clock = SYSCLK/12
  *  SC92L853x,SC92L753x SYSCLK crossover frequencies selection range
  *                   - SYSCLK_PRESSEL_FOSC_D1:SYSCLK clock = SYSCLK/1
  *                   - SYSCLK_PRESSEL_FOSC_D2:SYSCLK clock = SYSCLK/2 
  *                   - SYSCLK_PRESSEL_FOSC_D4:SYSCLK clock = SYSCLK/4
  *                   - SYSCLK_PRESSEL_FOSC_D8:SYSCLK clock = SYSCLK/8
  *  SC92R436,SC92R438,SC92R439,SC92L840x,SC92R422A SYSCLK crossover frequencies selection range
  *                   - SYSCLK_PRESSEL_FOSC_D2:SYSCLK clock = SYSCLK/2 
  *                   - SYSCLK_PRESSEL_FOSC_D4:SYSCLK clock = SYSCLK/4
  *                   - SYSCLK_PRESSEL_FOSC_D12:SYSCLK clock = SYSCLK/12
  * @retval None
  */
void OPTION_SYSCLK_Init(SYSCLK_PresSel_TypeDef
                        SYSCLK_PresSel)
{
  OPINX = 0XC1;
  OPREG = OPREG & 0XCF | SYSCLK_PresSel;
}

/**
  * @brief  Enables or disables the RST Pin.
  * @param  NewState[in]:  new state of the RST Pin.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable 
  * @retval None
  */
#if !defined(SC92F848x) && !defined(SC92F748x)  && !defined(SC92F859x) && !defined (SC92F759x)  && !defined(SC92L853x) && !defined (SC92L753x)\
		&& !defined (SC92R511x) && !defined (SC92L840x)
void OPTION_RST_PIN_Cmd(FunctionalState NewState)
{
  OPINX = 0XC1;

  if(NewState == DISABLE)
  {
    OPREG |= 0X08;
  }
  else
  {
    OPREG &= 0XF7;
  }
}
#endif

/**
 * @brief  Configures the LVR voltage gear.
 * @param  LVR_Config[in]: specifies the LVR voltage gear.
 *            - LVR_INVALID: LVR Reset: disable 
 *            - LVR_2_3V: LVR Reset: 2.3V  
 *            - LVR_2_9V: LVR Reset: 2.9V  
 *            - LVR_3_7V: LVR Reset: 3.7V  
 *            - LVR_4_3V: LVR Reset: 4.3V 
 * SC92F859x,SC92F759x,SC92F848x,SC92F748x,SC92R511x,SC92F663x,SC92F563x Selection Range
 *            - LVR_INVALID: LVR Reset: disable 
 *            - LVR_1_9V: LVR Reset: 1.9V  
 *            - LVR_2_9V: LVR Reset: 2.9V  
 *            - LVR_3_7V: LVR Reset: 3.7V  
 *            - LVR_4_3V: LVR Reset: 4.3V 
 * SC92L853x,SC92L753x Selection Range
 *            - LVR_INVALID: LVR Reset: disable 
 *            - LVR_1_7V: LVR Reset: 1.9V  
 *            - LVR_2_7V: LVR Reset: 2.9V  
 *            - LVR_3_7V: LVR Reset: 3.7V  
 *            - LVR_4_3V: LVR Reset: 4.3V 
 * SC92L840x Selection Range
 *            - LVR_INVALID: LVR Reset: disable 
 *            - LVR_1_7V: LVR Reset: 1.7V  
 *            - LVR_1_9V: LVR Reset: 1.9V  
 *            - LVR_2_3V: LVR Reset: 2.3V  
 *            - LVR_2_7V: LVR Reset: 2.7V 
 * @retval None
 */
void OPTION_LVR_Init(LVR_Config_TypeDef
                     LVR_Config)
{
  OPINX = 0XC1;
  OPREG = OPREG & 0XF8 | LVR_Config;
}

/**
 * @brief  Configures the ADC Reference voltage gear.
 * @param  ADC_Vref[in]: specifies the ADC Reference voltage.
 *            - ADC_VREF_VDD: ADC reference voltage is VDD 
 *            - ADC_VREF_2_4V: ADC reference voltage is 2.4V
 * SC92F859x,SC92F759x,SC92F848x,SC92F748x,SC92L853x,SC92L753x,SC92R511x,SC92F646x,SC92F546x,SC92F542x,SC92F6x1x,SC92F5x1x 
 * SC92R436,SC92R438,SC92R439,SC92R422A,SC92F652x,SC92F5x5x,SC92F531x,SC92F663x,SC92F563x Selection Range
 *            - ADC_VREF_VDD: ADC reference voltage is VDD 
 *            - ADC_VREF_1_024V: ADC reference voltage is 1.024V
 *            - ADC_VREF_2_4V: ADC reference voltage is 2.4V
 *            - ADC_VREF_2_048V: ADC reference voltage is 2.048V
 * SC92L840x Selection Range
 *            - ADC_VREF_VDD: ADC reference voltage is VDD 
 *            - ADC_VREF_1_024V: ADC reference voltage is 2.4V
 * @retval None
 */
#if !defined(SC92F637x)
void OPTION_ADC_VrefConfig(ADC_Vref_TypeDef
                           ADC_Vref)
{
	OPINX = 0xC2;
	#if defined (SC92F859x) || defined (SC92F759x) || defined (SC92F848x) || defined (SC92F748x) || defined (SC92L853x) || defined (SC92L753x)\
		|| defined (SC92R511x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F6x1x) || defined(SC92F5x1x)|| defined(SC92R436)\
  	|| defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)|| defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)|| defined(SC92F5x5x)\
		|| defined(SC92F531x) || defined(SC92F663x) || defined(SC92F563x)
	{
		OPREG = OPREG & 0X3F | ADC_Vref;
	}
	#else
  {
		OPREG = OPREG & 0X7F | ADC_Vref;
	}
	#endif
}
#endif

/**
 * @brief  Configures the IAP Operate Range.
 * @param  IAP_OperateRange[in]: specifies the IAP Operate Range.
 *            - IAP_OPERATERANGE_ONLY_EEPROM: Only IAP operations on EEPROM
 *            - IAP_OPERATERANGE__LAST_0_5K_CODEREGION:  Only IAP operations in the last 0.5k of FLASH
 *            - IAP_OPERATERANGE__LAST_1K_CODEREGION: Only IAP operations in the last 1k of FLASH
 *            - IAP_OPERATERANGE__ALL_CODEREGION: Only IAP operations in the all of FLASH
 *              SC92F848x,SC92F748x,SC92L853x,SC92L753x,SC92L840x,SC92F663x,SC92F563x Selection Range
 *            - IAP_OPERATERANGE_ONLY_EEPROM: Only IAP operations on EEPROM
 *            - IAP_OPERATERANGE__LAST_1K_CODEREGION: Only IAP operations in the last 1k of FLASH
 *            - IAP_OPERATERANGE__LAST_2K_CODEREGION: Only IAP operations in the last 2k of FLASH
 *            - IAP_OPERATERANGE__ALL_CODEREGION: Only IAP operations in the all of FLASH
 * @retval None
 */
#if !defined(SC92F5x5x) && !defined(SC92F531x) && !defined(SC92F637x)
void OPTION_IAP_SetOperateRange(IAP_OperateRange_TypeDef IAP_OperateRange)
{
  OPINX = 0xC2;
  OPREG = (OPREG & 0xF3) | IAP_OperateRange;
}
#endif

/**
 * @brief  Configures the XTIPPL frequency range.
 * @param  XTIPLL_Range[in]: specifies the XTIPPL frequency Range.
 *            - XTIPLL_HIGHER_THAN_12M: XTIPPL frequency is greater than 12 MHz
 *            - XTIPLL_UNDER_12M:  XTIPPL frequency is less than 12 MHz
 * @retval None
 */
#if defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB)|| defined (SC92F83Ax)\
	|| defined (SC92F73Ax) || defined (SC92F84Ax) || defined (SC92F74Ax) || defined (SC92F740x)\
	|| defined (SC92F8003) || defined (SC92F8003B) || defined (SC92F7003) || defined (SC92R342) || defined (SC92F841x) || defined (SC92F741x)\
  ||defined (SC92L840x)  || defined (SC92Fx41xB) || defined(SC92R445) 
void OPTION_XTIPLL_SetRange(XTIPLL_Range_TypeDef XTIPLL_Range)
{
  OPINX = 0XC2;
  OPREG = OPREG & 0XBF | XTIPLL_Range;
}
#elif defined(SC92F563x)
void OPTION_XTIPLL_SetRange(XTIPLL_Range_TypeDef XTIPLL_Range)
{
  OPINX = 0XC3;
  OPREG = OPREG & 0XDF | XTIPLL_Range;
}
#endif

#if defined (SC92F742x)||defined (SC92F83Ax) || defined (SC92F73Ax)|| defined (SC92F84Ax) || defined (SC92F74Ax) \
		||defined (SC92F74Ax_2) || defined (SC92F84Ax_2) || defined (SC92F844xB) || defined (SC92F744xB)|| defined (SC92F7490) \
		||defined (SC92F859x) || defined (SC92F759x) ||defined (SC92F848x) || defined (SC92F748x) || defined (SC92L853x) || defined (SC92L753x)\
		|| defined (SC92R511x) || defined (SC92F84Hx) || defined (SC92F83Hx) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)\
    || defined(SC92F8003B)|| defined(SC92F6x1x) || defined(SC92F5x1x)|| defined(SC92R436)|| defined(SC92R438)|| defined(SC92R439) || defined(SC92L840x)\
    || defined(SC92R445) || defined(SC92R422A) || defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F5x5x)\
		|| defined(SC92F531x) || defined(SC92F637x) || defined(SC92F663x) || defined(SC92F563x)
/**
 * @brief  Enables or disables the JTAG function.
 * @param  NewState[in]: new state of the JTAG peripheral. 
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable 
 * @retval None
 */
void OPTION_JTG_Cmd(FunctionalState NewState)
{
  OPINX = 0xC2;

  if(NewState == DISABLE)
  {
    OPREG |= 0X10;	   //1 JTAG DISABLE
  }
  else
  {
    OPREG &= 0XEF;	   //0 JTAG ENABLE
  }
}
#endif
/**
 * @}
 */
/* End of option_Group1.	*/


/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */
/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/