/**
 ******************************************************************************
 * @file    sc92f_adc.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   ADC function module
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
#include "sc92f_adc.h"

#if !defined(SC92F827X) && !defined(SC92F837X) && !defined(SC92F637x)
/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
/** @defgroup ADC
 * @brief ADC driver modules
 * @{
 */
 
/** @defgroup ADC_Exported_Functions
 * @{
 */
 
/** @defgroup ADC_Exported_Functions_Group1 Configuration of the ADC computation unit functions
 *  @brief   Configuration of the ADC computation unit functions
 *
 
@verbatim
 ===============================================================================
                     ##### ADC configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */
 
/**
 * @brief  DeInitializes the ADC peripheral
 * @param  None         
 * @retval None
 */
void ADC_DeInit(void)
{
  ADCCON = 0x00;
  ADCCFG0 = 0X00;
#if !defined(SC92F6x1x) && !defined(SC92F5x1x)&& !defined(SC92R436)&& !defined(SC92R438)&& !defined(SC92R439)&& !defined(SC92R422A)&& !defined(SC92F652x)&& !defined(SC92R51x_R52x)\
	&& !defined(SC92F552x) && !defined(SC92F5x5x)&& !defined(SC92F531x) && !defined(SC92F663x) && !defined(SC92F563x)
  ADCCFG1 = 0X00;
#endif
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
	|| defined(SC92F846xB) || defined(SC92F746xB) || defined(SC92F836xB) || defined(SC92F736xB) || defined(SC92F84Ax) || defined(SC92F74Ax)\
	|| defined(SC92F83Ax) || defined(SC92F73Ax) || defined(SC92F848x) || defined(SC92F748x) || defined (SC92F859x) || defined (SC92F759x)\
  || defined (SC92L853x) || defined (SC92L753x) || defined (SC92R511x) || defined (SC92R342) || defined (SC92F841x) || defined (SC92F741x)\
	|| defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)|| defined(SC92R438)\
  || defined(SC92L840x)	|| defined(SC92R439)|| defined (SC92Fx41xB)|| defined (SC92R445) || defined (SC92R422A) || defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)|| defined(SC92F5x5x)\
	|| defined(SC92F531x) || defined(SC92F663x) || defined(SC92F563x)  
  ADCCFG2 = 0X00;
#endif
#if defined(SC92F84Hx) || defined(SC92F83Hx)
	ADCCFG3 = 0X00;
#endif
  ADCVL = 0X00;
  ADCVH = 0X00;
  EADC = 0;
  IPADC = 0;
}

/**
 * @brief  Initializes the ADC peripheral
 * @param  ADC_PrescalerSelection[in]: Select ADC prescaler.
 * if the model is SC92F854x,SC92F754x,SC92F844xB,SC92F744xB,SC92F84Ax_2,SC92F74Ax_2 or SC92FWxx
 *                  - ADC_PRESSEL_FOSC_D6: Select ADC clock division by 6.
 *                  - ADC_PRESSEL_FOSC_D12: Select ADC clock division by 12.
 * if the model is SC92F846xB,SC92F746xB,SC92F836xB,SC92F736xB,SC92F83Ax,SC92F73Ax,SC92F84Ax
 *                 SC92F74Ax,SC92F7003,SC92F8003,SC92F8003B,SC92F740x,SC92R342,SC92F841x,SC92Fx41xB,SC92R445
 *                 SC92F741x,SC92F84Hx,SC92F83Hx
 *                  - ADC_PRESSEL_FSYS_D32: Select ADC clock division by 32.
 *                  - ADC_PRESSEL_FSYS_D24: Select ADC clock division by 24.
 *                  - ADC_PRESSEL_FSYS_D16: Select ADC clock division by 16.
 *                  - ADC_PRESSEL_FSYS_D12: Select ADC clock division by 12.
 *                  - ADC_PRESSEL_FSYS_D8: Select ADC clock division by 8.
 *                  - ADC_PRESSEL_FSYS_D6: Select ADC clock division by 6.
 *                  - ADC_PRESSEL_FSYS_D4: Select ADC clock division by 4.
 *                  - ADC_PRESSEL_FSYS_D3: Select ADC clock division by 3.
 * if the model is SC92F742x,SC92F730x,SC92F725X,SC92F735X,SC92F732X,SC93F833x,SC93F843x
 *                 SC93F743x,SC92F730x_2,SC92F720x,SC92F7308B
 *                  - ADC_PRESSEL_2_MHz: Select ADC clock as 2Mhz.
 *                  - ADC_PRESSEL_333_kHz: Select ADC clock as 333Khz.
 * if the model is SC92F848x,SC92F748x
 *                  - ADC_PRESSEL_FSYS_D16: Select ADC clock division by 16.
 *                  - ADC_PRESSEL_FSYS_D12: Select ADC clock division by 12.
 *                  - ADC_PRESSEL_FSYS_D8: Select ADC clock division by 8.
 *                  - ADC_PRESSEL_FSYS_D6: Select ADC clock division by 6.
 *                  - ADC_PRESSEL_FSYS_D4: Select ADC clock division by 4.
 *                  - ADC_PRESSEL_FSYS_D3: Select ADC clock division by 3.
 *                  - ADC_PRESSEL_FSYS_D2: Select ADC clock division by 2.
 *                  - ADC_PRESSEL_FSYS_D1: Select ADC clock division by 1.
 * if the model is SC92F859x,SC92F759x,SC92R511x,SC92F6x1x,SC92F5x1x,SC92R436,SC92R439,SC92R422A,SC92F652x,SC92F5x5x
 *                  - ADC_PRESSEL_FSYS_D16: Select ADC clock division by 16.
 *                  - ADC_PRESSEL_FSYS_D12: Select ADC clock division by 12.
 *                  - ADC_PRESSEL_FSYS_D6: Select ADC clock division by 6.
 *                  - ADC_PRESSEL_FSYS_D4: Select ADC clock division by 4.
 * if the model is SC92L853x,SC92L753x
 *                  - ADC_PRESSEL_3CLOCK: Sampling time is 3 system clocks.
 *                  - ADC_PRESSEL_6CLOCK: Sampling time is 6 system clocks.
 *                  - ADC_PRESSEL_16CLOCK: Sampling time is 16 system clocks.
 *                  - ADC_PRESSEL_32CLOCK: Sampling time is 32 system clocks.
 * if the model is SC92F646x,SC92F546x,SC92F542x,SC92F531x,SC92R51x_R52x,SC92F552x,SC92F663x,SC92F563x
 *                  - ADC_PRESSEL_Null: no prescaler.
 * @param  ADC_Cycle[in]:Select ADC sampling clock cyclef.
 * if the model is SC92F854x,SC92F754x,SC92F844xB,SC92F744xB,SC92F84Ax_2,SC92F74Ax_2,SC92F846xB,SC92F746xB,SC92F836xB
 *                 SC92FWxx,SC92F859x,SC92F759x,SC92R511x,SC92F740x,SC92F736xB,SC92F83Ax,SC92F73Ax,
 *                 SC92F84Ax,SC92F74Ax,SC92F7003,SC92F8003,SC92F8003B,SC92F848x,SC92F748x,SC92R342,SC92F841x,SC92Fx41xB,SC92R445,SC92F741x,SC92F84Hx,SC92F83Hx
 *                  - ADC_Cycle_6Cycle: Select 6 ADC clock cycles.
 *                  - ADC_Cycle_36Cycle: Select 36 ADC clock cycles.
 * if the model is SC92F742x,SC92F730x,SC92F725X,SC92F735X,SC92F732X,SC92F7490,SC93F833x,SC93F843x,
 *                 SC93F743x,SC92L853x,SC92L753x,SC92F730x_2,SC92F720x,SC92F7308B
 *                  - ADC_Cycle_Null: Don't select ADC cycles.    
 * if the model is SC92F646x,SC92F546x,SC92F542x,SC92F652x,SC92F531x,SC92R51x_R52x,SC92F552x,SC92F531x,SC92F663x,SC92F563x
 *                  - ADC_Cycle_3Cycle: Select 3 ADC clock cycles.  
 *                  - ADC_Cycle_6Cycle: Select 6 ADC clock cycles.
 *                  - ADC_Cycle_16Cycle: Select 16 ADC clock cycles.  
 *                  - ADC_Cycle_32Cycle: Select 32 ADC clock cycles.
 * if the model is SC92F6x1x,SC92F5x1x,SC92R436,SC92R438,SC92R439,SC92R422A,SC92F5x5x
 *                  - ADC_Cycle1_20Cycle: Select 20 ADC clock cycles.  
 *                  - ADC_Cycle1_50Cycle: Select 50 ADC clock cycles.
 *                  - ADC_Cycle2_20Cycle: Select 20 ADC clock cycles.  
 *                  - ADC_Cycle2_50Cycle: Select 50 ADC clock cycles.
 * @retval None
 */
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
	|| defined(SC92F846xB) || defined(SC92F746xB) || defined(SC92F836xB) || defined(SC92F736xB) || defined(SC92F84Ax) || defined(SC92F74Ax)\
	|| defined(SC92F83Ax) || defined(SC92F73Ax) || defined(SC92FWxx) || defined(SC92F848x) || defined(SC92F748x)\
	|| defined (SC92F859x) || defined (SC92F759x) || defined (SC92R511x) || defined (SC92R342) || defined (SC92F841x) || defined (SC92F741x)\
  || defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)|| defined(SC92R438)|| defined(SC92R439)\
	|| defined(SC92L840x)|| defined(SC92R439) || defined (SC92Fx41xB)|| defined (SC92R445)|| defined (SC92R422A)|| defined (SC92F652x)\ 
	|| defined (SC92F5x5x)
void ADC_Init(ADC_PresSel_TypeDef ADC_PrescalerSelection,
			  ADC_Cycle_TypeDef ADC_Cycle)
{
	/* Configure ADC clock division and sampling period */
  ADCCFG2 = ADC_PrescalerSelection | ADC_Cycle;
}
#elif defined(SC92F7003) || defined(SC92F8003) || defined(SC92F8003B) || defined(SC92F740x)
void ADC_Init(ADC_PresSel_TypeDef ADC_PrescalerSelection,
			  ADC_Cycle_TypeDef ADC_Cycle)
{
	/* Configure ADC clock division and sampling period */
	ADCCFG1 = ADC_PrescalerSelection | ADC_Cycle;
}
#elif defined(SC92F742x) || defined(SC92F725X) || defined(SC92F735X) || defined(SC92F730x) || defined(SC92F732X) || defined(SC92F7490)\
  || defined(SC93F833x) || defined(SC93F843x) || defined(SC93F743x) || defined(SC92F730x_2) || defined(SC92F720x) || defined (SC92F7308B)
void ADC_Init(ADC_PresSel_TypeDef ADC_PrescalerSelection,
			  ADC_Cycle_TypeDef ADC_Cycle)
{
	ADC_Cycle = 0; //SC92F742x does not have this function
	/* Configure ADC clock divider */
  ADCCON = (ADCCON & 0xDF) | ADC_PrescalerSelection;
}
#elif defined (SC92L853x) || defined (SC92L753x)
void ADC_Init(ADC_PresSel_TypeDef ADC_PrescalerSelection, ADC_Cycle_TypeDef ADC_Cycle)
{
  ADC_Cycle = 0x00; //The input parameter is invalid in the 92L series.
	/* Configure ADC clock divider */
  ADCCFG2 = ADC_PrescalerSelection;
}
#elif defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined (SC92F531x) || defined(SC92R51x_R52x) || defined (SC92F552x)\
 || defined(SC92F663x) || defined(SC92F563x) 
void ADC_Init(ADC_PresSel_TypeDef ADC_PrescalerSelection,
			  ADC_Cycle_TypeDef ADC_Cycle)
{
	ADC_PrescalerSelection = 0x00;//The input parameter is invalid. 
	/* Configure ADC clock division and sampling period */
  ADCCFG2 = (ADCCFG2 & 0xE3) | ADC_Cycle;
}
#endif

/**
 * @brief  Configure the ADC input channel
 * @param  ADC_Channel[in]: ADC input channel selection.
 *              SC92F854x,SC92F754x,SC92F844xB,SC92F744xB,SC92F84Ax_2,SC92F74Ax_2,SC92FWxx,SC92F859x,
 *              SC92F759x,SC92R511x 
 *                   Selection range(ADC_CHANNEL_0 - ADC_CHANNEL_15,ADC_CHANNEL_VDD_D4)
 *              SC92F84Hx,SC92F83Hx
 *                   Selection range(ADC_CHANNEL_0 - ADC_CHANNEL_19,ADC_CHANNEL_VDD_D4)
 *              SC92F646x,SC92F546x,SC92F542x
 *                   Selection range(ADC_CHANNEL_0 - ADC_CHANNEL_11,ADC_CHANNEL_VDD_D4)
 *              SC92F7003,SC92F8003,SC92F8003B,SC92F740x
 *                   Selection range(ADC_CHANNEL_0 - ADC_CHANNEL_6,ADC_CHANNEL_VDD_D4)
 *              SC92F846xB,SC92F746xB,SC92F836xB,SC92F736xB,SC92F83Ax,SC92F73Ax,SC92F84Ax,SC92F74Ax,
 *              SC92F742x,SC92F725X,SC92F735X,SC92F732X,SC92F848x,SC92F748x,SC92L853x,SC92L753x,SC92R342
 *              SC92F841x,SC92Fx41xB,SC92F741x ,SC92R445
 *                   Selection range(ADC_CHANNEL_0 - ADC_CHANNEL_9,ADC_CHANNEL_VDD_D4)
 *              SC92F730x,SC92F7308B
 *                   Selection range(ADC_CHANNEL_0,ADC_CHANNEL_1,ADC_CHANNEL_6,ADC_CHANNEL_7,ADC_CHANNEL_VDD_D4)
 *              SC92F730x_2,SC92F720x
 *                   Selection range(ADC_CHANNEL_0,ADC_CHANNEL_1,ADC_CHANNEL_4 - ADC_CHANNEL_9,ADC_CHANNEL_VDD_D4)
 *              SC92F7490
 *                   Selection range(ADC_CHANNEL_0,ADC_CHANNEL_1,ADC_CHANNEL_VDD_D4)
 *              SC93F833x,SC93F843x,SC93F743x
 *                   Selection range(ADC_CHANNEL_0 - ADC_CHANNEL_9,ADC_CHANNEL_9_PGA,ADC_CHANNEL_Temp,ADC_CHANNEL_VDD_D4)
 *              SC92F6x1x,SC92F5x1x,SC92R436,SC92R439,SC92R422A
 *                   Selection range(ADC_CHANNEL_0 - ADC_CHANNEL_25,ADC_CHANNEL_VDD_D4)
 *              SC92F652x,SC92R51x_R52x,SC92F552x
 *                   Selection range(ADC_CHANNEL_0 - ADC_CHANNEL_30,ADC_CHANNEL_VDD_D4)
 *              SC92F5x5x
 *                   Selection range(ADC_CHANNEL_0 - ADC_CHANNEL_1,ADC_CHANNEL_5,ADC_CHANNEL_8,ADC_CHANNEL_10 - ADC_CHANNEL_14,ADC_CHANNEL_18 - ADC_CHANNEL_21,ADC_CHANNEL_VDD_D4)
 *              SC92F531x
 *                   Selection range(ADC_CHANNEL_0 - ADC_CHANNEL_21,ADC_CHANNEL_OP,ADC_CHANNEL_VDD_D4)
 *              SC92F663x
 *                   Selection range(ADC_CHANNEL_0 - ADC_CHANNEL_8,ADC_CHANNEL_VDD_D4)
 *              SC92F563x
 *                   Selection range(ADC_CHANNEL_0 - ADC_CHANNEL_20,ADC_CHANNEL_VDD_D4)
 *                         - ADC_CHANNEL_0 : ADC input channel 0 
 *                         - ADC_CHANNEL_1 : ADC input channel 1 
 *                         - ADC_CHANNEL_2 : ADC input channel 2 
 *                         - ADC_CHANNEL_3 : ADC input channel 3  
 *                         - ADC_CHANNEL_4 : ADC input channel 4  
 *                         - ADC_CHANNEL_5 : ADC input channel 5  
 *                         - ADC_CHANNEL_6 : ADC input channel 6  
 *                         - ADC_CHANNEL_7 : ADC input channel 7  
 *                         - ADC_CHANNEL_8 : ADC input channel 8 
 *                         - ADC_CHANNEL_9 : ADC input channel 9
 *                         - ADC_CHANNEL_9_PGA : ADC input channel 9_PGA
 *                         - ADC_CHANNEL_10 :ADC input channel 10  
 *                         - ADC_CHANNEL_11 :ADC input channel 11 
 *                         - ADC_CHANNEL_12 :ADC input channel 12  
 *                         - ADC_CHANNEL_13 :ADC input channel 13 
 *                         - ADC_CHANNEL_14 :ADC input channel 14
 *                         - ADC_CHANNEL_15 :ADC input channel 15 
 *                         - ADC_CHANNEL_16 :ADC input channel 16 
 *                         - ADC_CHANNEL_17 :ADC input channel 17
 *                         - ADC_CHANNEL_18 :ADC input channel 18 
 *                         - ADC_CHANNEL_19 :ADC input channel 19 
 *                         - ADC_CHANNEL_20 :ADC input channel 20 
 *                         - ADC_CHANNEL_21 :ADC input channel 21
 *                         - ADC_CHANNEL_22 :ADC input channel 22 
 *                         - ADC_CHANNEL_23 :ADC input channel 23 
 *                         - ADC_CHANNEL_24 :ADC input channel 24 
 *                         - ADC_CHANNEL_25 :ADC input channel 25 
 *                         - ADC_CHANNEL_26 :ADC input channel 26
 *                         - ADC_CHANNEL_27 :ADC input channel 27 
 *                         - ADC_CHANNEL_28 :ADC input channel 28 
 *                         - ADC_CHANNEL_29 :ADC input channel 29 
 *                         - ADC_CHANNEL_30 :ADC input channel 30 
 *                         - ADC_CHANNEL_VDD_D4:ADC_CHANNEL VDD Divide 4
 *                         - ADC_CHANNEL_Temp:Temperature sensor serves as an ADC input
 * @param  NewState[in]: new state of the ADCx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable  
 * @retval None
 */
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
		|| defined(SC92F846xB) || defined(SC92F746xB) || defined(SC92F836xB) || defined(SC92F736xB) || defined(SC92F84Ax) || defined(SC92F74Ax)\
		|| defined(SC92F83Ax) || defined(SC92F73Ax) || defined(SC92FWxx) || defined(SC92F848x) || defined(SC92F748x)\
		|| defined(SC92F859x) || defined(SC92F759x) || defined (SC92L853x) || defined (SC92L753x) || defined (SC92R511x) || defined (SC92R342)\
		|| defined (SC92F841x) || defined (SC92F741x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined (SC92Fx41xB)\
		|| defined (SC92R445) 
void ADC_ChannelConfig(ADC_Channel_TypeDef ADC_Channel, FunctionalState NewState)
{
  uint16_t TempReg;
	/* Set the ADC channel type */
  ADCCON = (ADCCON & 0XE0) | ADC_Channel;
	
	/*Configure ADC external sampling channel*/
  if (ADC_Channel < ADC_CHANNEL_VDD_D4)	//Internal sampling channels do not need configuration
  {
		TempReg = (0x0001 << ADC_Channel);
		if (NewState == DISABLE)//Enable ADC sampling channel
		{
			ADCCFG0 &= (~(uint8_t)TempReg);
			ADCCFG1 &= (~(uint8_t)(TempReg >> 8));
		}
		else	// Disable ADC sampling channel
		{
			ADCCFG0 |= ((uint8_t)TempReg);
			ADCCFG1 |= ((uint8_t)(TempReg >> 8));
		}
  }
}
#elif defined(SC92F84Hx) || defined(SC92F83Hx) 
void ADC_ChannelConfig(ADC_Channel_TypeDef ADC_Channel, FunctionalState NewState)
{
  uint32_t TempReg;
	/* Set the ADC channel type */
  ADCCON = (ADCCON & 0XE0) | ADC_Channel;
	
	/*Configure ADC external sampling channel*/
  if (ADC_Channel < ADC_CHANNEL_VDD_D4)	//Internal sampling channels do not need configuration
  {
		TempReg = (0x0001UL << ADC_Channel);
		if (NewState == DISABLE)// Enable ADC sampling channel
		{
			ADCCFG0 &= (~(uint8_t)TempReg);
			ADCCFG1 &= (~(uint8_t)(TempReg >> 8));
			ADCCFG3 &= (~(uint8_t)(TempReg >> 16));
		}
		else	//Disable ADC sampling channel
		{
			ADCCFG0 |= ((uint8_t)TempReg);
			ADCCFG1 |= ((uint8_t)(TempReg >> 8));
			ADCCFG3 |= ((uint8_t)(TempReg >> 16));
		}
  }
}
#elif defined(SC92F7003) || defined(SC92F8003) || defined(SC92F8003B) || defined(SC92F740x) || defined(SC92F7490)
void ADC_ChannelConfig(ADC_Channel_TypeDef ADC_Channel, FunctionalState NewState)
{
  uint8_t TempReg;
	/* Set the ADC channel type */
  ADCCON = (ADCCON & 0xE0) | ADC_Channel;
	
	/*Configure ADC external sampling channel*/
  if (ADC_Channel < ADC_CHANNEL_VDD_D4)	//Internal sampling channels do not need configuration
  {
		TempReg = (0x01 << ADC_Channel);
		if (ADC_Channel < ADC_CHANNEL_VDD_D4)
		{
			if (NewState == DISABLE)	//Disable ADC sampling channel
			{
				ADCCFG0 &= (~TempReg);
			}
			else	//Enable ADC sampling channel
			{
				ADCCFG0 |= TempReg;
			}
		}
	}
}
#elif defined(SC92F742x) || defined(SC92F730x) || defined(SC92F725X) || defined(SC92F735X) || defined(SC92F732X) || defined(SC92F730x_2) || defined(SC92F720x) \
||defined (SC92F7308B) ||defined (SC92L840x)
void ADC_ChannelConfig(ADC_Channel_TypeDef ADC_Channel, FunctionalState NewState)
{
  uint16_t TempReg;
	/* Set the ADC channel type */
  ADCCON = (ADCCON & 0xF0) | ADC_Channel;
	
	/*Configure ADC external sampling channel*/
  if (ADC_Channel < ADC_CHANNEL_VDD_D4)	//Internal sampling channels do not need configuration
  {
		TempReg = (0x0001 << ADC_Channel);
		if (NewState == DISABLE)
		{
			ADCCFG0 &= (~(uint8_t)TempReg);
			ADCCFG1 &= (~(uint8_t)(TempReg >> 8));
		}
		else
		{
			ADCCFG0 |= ((uint8_t)TempReg);
			ADCCFG1 |= ((uint8_t)(TempReg >> 8));
		}
  }
}
#elif defined(SC93F833x) || defined(SC93F843x) || defined(SC93F743x)
void ADC_ChannelConfig(ADC_Channel_TypeDef ADC_Channel, FunctionalState NewState)
{
  uint16_t TempReg;
	/* Set the ADC channel type */
  ADCCON = (ADCCON & 0xF0) | ADC_Channel;
	
	/*Configure ADC external sampling channel*/
  if (ADC_Channel < ADC_CHANNEL_Temp)	//Internal sampling channels do not need configuration
  {
		TempReg = (0x0001 << ADC_Channel);
		if (NewState == DISABLE)
		{
			ADCCFG0 &= (~(uint8_t)TempReg);
			ADCCFG1 &= (~(uint8_t)(TempReg >> 8));
		}
		else
		{
			ADCCFG0 |= ((uint8_t)TempReg);
			ADCCFG1 |= ((uint8_t)(TempReg >> 8));
		}
  }
  else if (ADC_Channel == ADC_CHANNEL_Temp) //Internal temperature sampling channel
  {
		if (NewState == DISABLE)
		{
			TSCFG &= 0X7F;
		}
		else
		{
			/* ADC reference voltage selected internal 2.4V as reference */ 
			OPINX = 0xC2;
			OPREG = OPREG & 0X7F | 0x80;
				
			TSCFG |= 0x80;
		}
  }
  else if (ADC_Channel == ADC_CHANNEL_9_PGA) //Variable gain amplifier sampling channel
  {
		unsigned char code *IFBAddr = 0x3D;
		if (NewState == DISABLE)
		{
			ADCCFG1 &= (~(uint8_t)0x02); //Close channel 9
			PGACON &= 0x7F;              //ENABLE PGA
		}
			/* Read PGA internal factory calibration values */
		else
		{
			ADCCFG1 |= ((uint8_t)0x02); //The PGA input channel is multiplexed with channel 9;Enable channel 9

			IAPADE = 0x01;       //Pointer points to IFB area
			PGACFG = *(IFBAddr); //Read calibration values
			IAPADE = 0x00;       //The pointer points to the ROM area

			PGACON |= 0x80; //ENABLE PGA
		}
  }
}
#elif defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)|| defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)\
      || defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)
void ADC_ChannelConfig(ADC_Channel_TypeDef ADC_Channel, FunctionalState NewState)
{
 
	/* Set the ADC channel type */
  ADCCON = (ADCCON & 0xE0) | ADC_Channel;
	
	/*Configure ADC external sampling channel*/
  if (ADC_Channel < ADC_CHANNEL_VDD_D4)	//Internal sampling channels do not need configuration
  {
		if (NewState == DISABLE)
		{
			if(ADC_Channel<8)
			{
				ADCCFG2 &=~(0xC0);
				ADCCFG0 &= ~(1<<ADC_Channel);   //Set the channel as the sampling port
			}
			else if(ADC_Channel<16)
			{
				ADCCFG2 &=~(0xC0);
				ADCCFG2 |=0x40;
				ADCCFG0 &= ~(1<<(ADC_Channel-8));   //Set the channel as the sampling port
			}
			else if(ADC_Channel<24)
			{
			 ADCCFG2 &=~(0xC0);
				ADCCFG2 |=0x80;
				ADCCFG0 &= ~(1<<(ADC_Channel-16));   //Set the channel as the sampling port
			}
			else 
			{
				ADCCFG2 &=~(0xC0);
				ADCCFG2 |=0xC0;
				ADCCFG0 &= ~(1<<(ADC_Channel-24));   //Set the channel as the sampling port
			}
		}
		else
		{
			if(ADC_Channel<8)
			{
				ADCCFG2 &=~(0xC0);
				ADCCFG0 |= 1<<ADC_Channel;   //Set the channel as the sampling port
			}
			else if(ADC_Channel<16)
			{
				ADCCFG2 &=~(0xC0);
				ADCCFG2 |=0x40;
				ADCCFG0 |= 1<<(ADC_Channel-8);   //Set the channel as the sampling port
			}
			else if(ADC_Channel<24)
			{
			  ADCCFG2 &=~(0xC0);
				ADCCFG2 |=0x80;
				ADCCFG0 |= 1<<(ADC_Channel-16);   //Set the channel as the sampling port
			}
			else 
			{
				ADCCFG2 &=~(0xC0);
				ADCCFG2 |=0xC0;
				ADCCFG0 |= 1<<(ADC_Channel-24);   //Set the channel as the sampling port
			}

		}
  }
}
#elif defined(SC92F5x5x) || defined(SC92F531x) || defined(SC92F563x)
void ADC_ChannelConfig(ADC_Channel_TypeDef ADC_Channel, FunctionalState NewState)
{
 
	/* Set the ADC channel type */
  ADCCON = (ADCCON & 0xE0) | ADC_Channel;
	
	/*Configure ADC external sampling channel*/
  if (ADC_Channel < ADC_CHANNEL_VDD_D4)	//Internal sampling channels do not need configuration
  {
		if (NewState == DISABLE)
		{
				if(ADC_Channel<8)
				{
					ADCCFG2 &=~(0xC0);
					ADCCFG0 &= ~(1<<ADC_Channel);   //Set the channel as the sampling port
				}
				else if(ADC_Channel<16)
				{
					ADCCFG2 &=~(0xC0);
					ADCCFG2 |=0x40;
					ADCCFG0 &= ~(1<<(ADC_Channel-8));   //Set the channel as the sampling port
				}
				else if(ADC_Channel<24)
				{
				 ADCCFG2 &=~(0xC0);
					ADCCFG2 |=0x80;
					ADCCFG0 &= ~(1<<(ADC_Channel-16));   //Set the channel as the sampling port
				}
		}
		else
		{
				if(ADC_Channel<8)
				{
					ADCCFG2 &=~(0xC0);
					ADCCFG0 |= 1<<ADC_Channel;   //Set the channel as the sampling port
				}
				else if(ADC_Channel<16)
				{
					ADCCFG2 &=~(0xC0);
					ADCCFG2 |=0x40;
					ADCCFG0 |= 1<<(ADC_Channel-8);   //Set the channel as the sampling port
				}
				else if(ADC_Channel<24)
				{
				  ADCCFG2 &=~(0xC0);
					ADCCFG2 |=0x80;
					ADCCFG0 |= 1<<(ADC_Channel-16);   //Set the channel as the sampling port
				}
		}
  }
}
#elif defined(SC92F663x)
void ADC_ChannelConfig(ADC_Channel_TypeDef ADC_Channel, FunctionalState NewState)
{
 
	/* Set the ADC channel type */
  ADCCON = (ADCCON & 0xE0) | ADC_Channel;
	
	/*Configure ADC external sampling channel*/
  if (ADC_Channel < ADC_CHANNEL_VDD_D4)	//Internal sampling channels do not need configuration
  {
		if (NewState == DISABLE)
		{
				if(ADC_Channel<8)
				{
					ADCCFG2 &=~(0x40);
					ADCCFG0 &= ~(1<<ADC_Channel);   //Set the channel as the sampling port
				}
				else if(ADC_Channel<16)
				{
					ADCCFG2 &=~(0x40);
					ADCCFG2 |=0x40;
					ADCCFG0 &= ~(1<<(ADC_Channel-8));   //Set the channel as the sampling port
				}
		}
		else
		{
				if(ADC_Channel<8)
				{
					ADCCFG2 &=~(0x40);
					ADCCFG0 |= 1<<ADC_Channel;   //Set the channel as the sampling port
				}
				else if(ADC_Channel<16)
				{
					ADCCFG2 &=~(0x40);
					ADCCFG2 |=0x40;
					ADCCFG0 |= 1<<(ADC_Channel-8);   //Set the channel as the sampling port
				}
		}
  }
}
#endif

/**
 * @brief  Configure ADC IO mode
 * @param  ADC_EAIN_Select[in]:Select the ADC port that needs to be configured.
 *              SC92F854x,SC92F754x,SC92F844xB,SC92F744xB,SC92F84Ax_2,SC92F74Ax_2,SC92FWxx,SC92F859x,
 *              SC92F759x,SC92R511x 
 *                   Selection range(ADC_EAIN_0 - ADC_EAIN_15)
 *              SC92F84Hx,SC92F83Hx
 *                   Selection range(ADC_EAIN_0 - ADC_EAIN_19)
 *              SC92F646x,SC92F546x,SC92F542x
 *                   Selection range(ADC_EAIN_0 - ADC_EAIN_11)
 *              SC92F7003,SC92F8003,SC92F8003B,SC92F740x
 *                   Selection range(ADC_EAIN_0 - ADC_EAIN_6)
 *              SC92F846xB,SC92F746xB,SC92F836xB,SC92F736xB,SC92F83Ax,SC92F73Ax,SC92F84Ax,SC92F74Ax,
 *              SC92F742x,SC92F725X,SC92F735X,SC92F732X,SC92F848x,SC92F748x,SC92L853x,SC92L753x,SC92R342
 *              SC92F841x,SC92Fx41xB,SC92R445,SC92F741x 
 *                   Selection range(ADC_EAIN_0 - ADC_EAIN_9)
 *              SC92F730x,SC92F7308B
 *                   Selection range(ADC_EAIN_0,ADC_EAIN_1,ADC_EAIN_6,ADC_EAIN_7)
 *              SC92F730x_2,SC92F720x
 *                   Selection range(ADC_EAIN_0,ADC_EAIN_1,ADC_EAIN_4 - ADC_EAIN_9)
 *              SC92F7490
 *                   Selection range(ADC_EAIN_0,ADC_EAIN_1)
 *              SC93F833x,SC93F843x,SC93F743x
 *                   Selection range(ADC_EAIN_0 - ADC_EAIN_9)
 *              SC92F6x1x,SC92F5x1x,SC92R436,SC92R439,SC92R422A
 *                   Selection range(ADC_EAIN_0 - ADC_EAIN_25)
 *              SC92F652x,SC92R51x_R52x,SC92F552x
 *                   Selection range(ADC_EAIN_0 - ADC_EAIN_30)
 *              SC92F5x5x
 *                   Selection range(ADC_EAIN_0,ADC_EAIN_1,ADC_EAIN_5,ADC_EAIN_8 - ADC_EAIN_14,ADC_EAIN_18 - ADC_EAIN_21)
 *              SC92F531x
 *                   Selection range(ADC_EAIN_0 - ADC_EAIN_21)
 *              SC92F663x
 *                   Selection range(ADC_EAIN_0 - ADC_EAIN_8)
 *              SC92F563x
 *                   Selection range(ADC_EAIN_0 - ADC_EAIN_20)
 *                      - ADC_EAIN_0:Select AIN0.
 *                      - ADC_EAIN_1:Select AIN1.
 *                      - ADC_EAIN_2:Select AIN2.
 *                      - ADC_EAIN_3:Select AIN3.
 *                      - ADC_EAIN_4:Select AIN4.
 *                      - ADC_EAIN_5:Select AIN5.
 *                      - ADC_EAIN_6:Select AIN6.
 *                      - ADC_EAIN_7:Select AIN7.
 *                      - ADC_EAIN_8:Select AIN8.
 *                      - ADC_EAIN_9:Select AIN9.
 *                      - ADC_EAIN_10:Select AIN10.
 *                      - ADC_EAIN_11:Select AIN11.
 *                      - ADC_EAIN_12:Select AIN12.
 *                      - ADC_EAIN_13:Select AIN13.
 *                      - ADC_EAIN_14:Select AIN14.
 *                      - ADC_EAIN_15:Select AIN15.
 *                      - ADC_EAIN_16:Select AIN16.
 *                      - ADC_EAIN_17:Select AIN17.
 *                      - ADC_EAIN_18:Select AIN18.
 *                      - ADC_EAIN_19:Select AIN19.
 *                      - ADC_EAIN_20:Select AIN20.
 *                      - ADC_EAIN_21:Select AIN21.
 *                      - ADC_EAIN_22:Select AIN22.
 *                      - ADC_EAIN_23:Select AIN23.
 *                      - ADC_EAIN_24:Select AIN24.
 *                      - ADC_EAIN_25:Select AIN25.
 *                      - ADC_EAIN_26:Select AIN26.
 *                      - ADC_EAIN_27:Select AIN27.
 *                      - ADC_EAIN_28:Select AIN28.
 *                      - ADC_EAIN_29:Select AIN29.
 *                      - ADC_EAIN_30:Select AIN30.
 * @param  NewState[in]:new state of the ADCx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void ADC_EAINConfig(uint32_t ADC_EAIN_Select,
					FunctionalState NewState)
{
  if (NewState == DISABLE)
  {
#if !defined(SC92F6x1x) && !defined(SC92F5x1x) && !defined(SC92R436)&& !defined(SC92R438)&& !defined(SC92R439)&& !defined(SC92R422A)\
		&& !defined(SC92F652x) && !defined(SC92R51x_R52x) && !defined(SC92F552x) && !defined(SC92F5x5x)&& !defined(SC92F531x)\
		&& !defined(SC92F663x) && !defined(SC92F563x)
	ADCCFG0 &= (~(uint8_t)ADC_EAIN_Select);
#if defined (SC92F854x) || defined (SC92F754x) || defined  (SC92F844xB) || defined (SC92F744xB) || defined  (SC92F84Ax_2) || defined (SC92F74Ax_2)\
		|| defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB)||defined  (SC92F84Ax) || defined (SC92F74Ax)\
		|| defined(SC92F83Ax) || defined(SC92F73Ax) || defined(SC92F848x) || defined(SC92F748x) || defined(SC92F859x)  || defined (SC92F759x)\
		|| defined (SC92L853x) || defined (SC92L753x) || defined (SC92R511x) || defined (SC92R342) || defined (SC92F841x) || defined (SC92F741x)\
		|| defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F730x_2) || defined(SC92F720x) || defined(SC92L840x)\
		|| defined (SC92Fx41xB)|| defined (SC92R445)
	ADCCFG1 &= (~(uint8_t)(ADC_EAIN_Select >> 8));
#elif defined(SC92F84Hx) || defined(SC92F83Hx)
	ADCCFG1 &= (~(uint8_t)(ADC_EAIN_Select >> 8));
	ADCCFG3 &= (~(uint8_t)(ADC_EAIN_Select >> 16));
#endif
#endif
#if defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)|| defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)|| defined(SC92F652x)\
		|| defined(SC92R51x_R52x) || defined (SC92F552x)
		if(ADC_EAIN_Select<=0X80)
		{
			ADCCFG2 &=~(0xC0);
			ADCCFG0 &= (~(uint8_t)(ADC_EAIN_Select));   //Set the channel as the sampling port
		}
		else if(ADC_EAIN_Select<=0X8000)
		{
			ADCCFG2 &=~(0xC0);
			ADCCFG2 |=0x40;
			ADCCFG0 &= (~(uint8_t)(ADC_EAIN_Select>>8));   //Set the channel as the sampling port
		}
		else if(ADC_EAIN_Select<=0X800000)
		{
		 ADCCFG2 &=~(0xC0);
			ADCCFG2 |=0x80;
			ADCCFG0 &= (~(uint8_t)(ADC_EAIN_Select>>16));   //Set the channel as the sampling port
		}
		else 
		{
			ADCCFG2 &=~(0xC0);
			ADCCFG2 |=0xC0;
			ADCCFG0 &= (~(uint8_t)(ADC_EAIN_Select>>24));   //Set the channel as the sampling port
		}
#endif
#if defined(SC92F5x5x) || defined(SC92F531x) || defined(SC92F563x)
		if(ADC_EAIN_Select<=0X80)
		{
			ADCCFG2 &=~(0xC0);
			ADCCFG0 &= (~(uint8_t)(ADC_EAIN_Select));   //Set the channel as the sampling port
		}
		else if(ADC_EAIN_Select<=0X8000)
		{
			ADCCFG2 &=~(0xC0);
			ADCCFG2 |=0x40;
			ADCCFG0 &= (~(uint8_t)(ADC_EAIN_Select>>8));   //Set the channel as the sampling port
		}
		else if(ADC_EAIN_Select<=0X800000)
		{
		 ADCCFG2 &=~(0xC0);
			ADCCFG2 |=0x80;
			ADCCFG0 &= (~(uint8_t)(ADC_EAIN_Select>>16));   //Set the channel as the sampling port
		}
#endif	
#if defined(SC92F663x)
		if(ADC_EAIN_Select<=0X80)
		{
			ADCCFG2 &=~(0x40);
			ADCCFG0 &= (~(uint8_t)(ADC_EAIN_Select));   //Set the channel as the sampling port
		}
		else if(ADC_EAIN_Select<=0X8000)
		{
			ADCCFG2 &=~(0x40);
			ADCCFG2 |=0x40;
			ADCCFG0 &= (~(uint8_t)(ADC_EAIN_Select>>8));   //Set the channel as the sampling port
		}
#endif
  }
  else
  {
#if !defined(SC92F6x1x) && !defined(SC92F5x1x) && !defined(SC92F652x) && !defined(SC92R51x_R52x) && !defined(SC92F552x) && !defined(SC92F5x5x) && !defined(SC92F531x)\
		&& !defined(SC92F663x) && !defined(SC92F563x)
	ADCCFG0 |= ((uint8_t)ADC_EAIN_Select);
#if defined (SC92F854x) || defined (SC92F754x) || defined (SC92F844xB) || defined (SC92F744xB)||defined  (SC92F84Ax_2) || defined (SC92F74Ax_2)\
		|| defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB) || defined  (SC92F84Ax) || defined (SC92F74Ax)\
		|| defined(SC92F83Ax) || defined(SC92F73Ax) || defined(SC92F848x) || defined(SC92F748x) || defined(SC92F859x) || defined (SC92F759x)\
		|| defined (SC92L853x) || defined (SC92L753x) || defined (SC92R511x) || defined (SC92R342) || defined (SC92F841x) || defined (SC92F741x)\
		|| defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F730x_2) || defined(SC92F720x)  || defined(SC92L840x)\
		|| defined (SC92Fx41xB) || defined (SC92R445)
	ADCCFG1 |= ((uint8_t)(ADC_EAIN_Select >> 8));
#elif defined(SC92F84Hx) || defined(SC92F83Hx)
	ADCCFG1 |= ((uint8_t)(ADC_EAIN_Select >> 8));
	ADCCFG3 |= ((uint8_t)(ADC_EAIN_Select >> 16));
#endif
#endif
#if defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436) || defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)|| defined(SC92F652x)\
		|| defined(SC92R51x_R52x) || defined (SC92F552x)
		if(ADC_EAIN_Select<=0X80)
		{
			ADCCFG2 &=~(0xC0);
			ADCCFG0 |= (uint8_t)(ADC_EAIN_Select);   //Set the channel as the sampling port
		}
		else if(ADC_EAIN_Select<=0X8000)
		{
			ADCCFG2 &=~(0xC0);
			ADCCFG2 |=0x40;
			ADCCFG0 |= (uint8_t)(ADC_EAIN_Select>>8);   //Set the channel as the sampling port
		}
		else if(ADC_EAIN_Select<=0X800000)
		{
		  ADCCFG2 &=~(0xC0);
			ADCCFG2 |=0x80;
			ADCCFG0 |= (uint8_t)(ADC_EAIN_Select>>16);   //Set the channel as the sampling port
		}
		else 
		{
			ADCCFG2 &=~(0xC0);
			ADCCFG2 |=0xC0;
			ADCCFG0 |= (uint8_t)(ADC_EAIN_Select>>24);   //Set the channel as the sampling port
		}
#endif
#if defined(SC92F5x5x) || defined(SC92F531x) || defined(SC92F563x)
		if(ADC_EAIN_Select<=0X80)
		{
			ADCCFG2 &=~(0xC0);
			ADCCFG0 |= (uint8_t)(ADC_EAIN_Select);   //Set the channel as the sampling port
		}
		else if(ADC_EAIN_Select<<=0X8000)
		{
			ADCCFG2 &=~(0xC0);
			ADCCFG2 |=0x40;
			ADCCFG0 |= (uint8_t)(ADC_EAIN_Select>>8);   //Set the channel as the sampling port
		}
		else if(ADC_EAIN_Select<=0X800000)
		{
		  ADCCFG2 &=~(0xC0);
			ADCCFG2 |=0x80;
			ADCCFG0 |= (uint8_t)(ADC_EAIN_Select>>16);   //Set the channel as the sampling port
		}
#endif
#if defined(SC92F663x)
		if(ADC_EAIN_Select<=0X80)
		{
			ADCCFG2 &=~(0x40);
			ADCCFG0 |= (uint8_t)(ADC_EAIN_Select);   //Set the channel as the sampling port
		}
		else if(ADC_EAIN_Select<=0X8000)
		{
			ADCCFG2 &=~(0x40);
			ADCCFG2 |=0x40;
			ADCCFG0 |= (uint8_t)(ADC_EAIN_Select>>8);   //Set the channel as the sampling port
		}
#endif
  }
}

/**
 * @brief  Enables or disables the specified ADC peripheral.
 * @param  NewState[in]: new state of the ADCx peripheral.
 *                  @ DISABLE:Function disable
 *                  @ ENABLE:Function enable  
 * @retval None
 */
void ADC_Cmd(FunctionalState NewState)
{
  if (NewState == DISABLE)
  {
    /* Disable the ADC Counter */
	  ADCCON &= 0X7F;
  }
  else
  {
    /* Enable the ADC Counter */
	  ADCCON |= 0x80;
  }
}

/**
 * @}
 */
/* End of ADC_Group1.	*/

/** @defgroup ADC_Group2 Conversion management functions
 *  @brief   Conversion management functions
 *
@verbatim
 ===============================================================================
                     ##### ADC Conversion management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  Returns the last ADCx conversion result data for regular channel.
 * @param  None
 * @retval the result of the latest ADCx conversion
 */
unsigned int ADC_GetConversionValue(void)
{
	return ((ADCVH << 4) + (ADCVL >> 4));
}

#if defined (SC92F854x) || defined (SC92F754x) || defined  (SC92F844xB) || defined (SC92F744xB) || defined  (SC92F84Ax_2) || defined (SC92F74Ax_2)\
	|| defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB) || defined (SC92F848x) || defined (SC92F748x)\
	|| defined (SC92F859x) || defined (SC92F759x) || defined (SC92L853x) || defined (SC92L753x) || defined (SC92R511x) || defined (SC92R342)\
	|| defined (SC92F841x) || defined (SC92F741x) || defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)\
  || defined (SC92Fx41xB)|| defined (SC92R445)|| defined (SC92F563x)
/*  Using MDU to reduce computation time */
#include "sc92f_mdu.h"
uint16_t ADC_GetConversionAverageValue(ADC_SamplesNum_TypeDef ADC_SamplesNum)
{
	uint8_t tmpCnt;
	uint16_t tmpValueSum = 0, tmpValue;
	uint16_t tmpValue_Max = 0, tmpValue_Min = 0xFFFF;
	bit tmpStaus = EADC;
	EADC = 0;

	for (tmpCnt = 0; tmpCnt < ADC_SamplesNum; tmpCnt++)
	{
		ADC_StartConversion();			//Start an ADC conversion.
		while (!ADC_GetFlagStatus());			//Waiting for ADC conversion to complete.
		ADC_ClearFlag();			//Clear ADC conversion flag.
		tmpValue = ADC_GetConversionValue();			//Obtain a single conversion value.

		/*Get the maximum value among multiple conversion values */
		if (tmpValue > tmpValue_Max)
			tmpValue_Max = tmpValue;
		/* Get the minimum value among multiple conversion results */
		if (tmpValue < tmpValue_Min)
			tmpValue_Min = tmpValue;

		tmpValueSum += tmpValue;//The sum of accumulated conversion values
	}

	/* Calculate the average using hardware multiplier/divider */
	{
		OPERCON |= 0X40;
		/* Dividend is a 16-bit data */
		tmpValueSum -= (tmpValue_Max + tmpValue_Min);
		EXA0 = tmpValueSum;
		EXA1 = tmpValueSum >> 8;
		EXBL = ADC_SamplesNum - 2;			//The divisor is an 8-bit data.

		OPERCON |= 0x80;				//Start division calculation.
		while (OPERCON & 0x80);			//Waiting for computation to complete.

		//Acquisition Factor
		tmpValue = (uint16_t)EXA0;
		tmpValue |= EXA1 << 8;
	}

	EADC = tmpStaus;			//Restore EADC
	return tmpValue;			//return the average
}

#else
uint16_t ADC_GetConversionAverageValue(ADC_SamplesNum_TypeDef ADC_SamplesNum)
{
	uint8_t tmpCnt;
	uint16_t tmpValueSum = 0, tmpValue;
	uint16_t tmpValue_Max = 0, tmpValue_Min = 0xFFFF;
	bit tmpStaus = EADC;
	EADC = 0;

	for (tmpCnt = 0; tmpCnt < ADC_SamplesNum; tmpCnt++)
	{
		ADC_StartConversion();			//Start an ADC conversion.
		while (!ADC_GetFlagStatus());			//Waiting for ADC conversion to complete.
		ADC_ClearFlag();			//Clear ADC conversion flag.
		tmpValue = ADC_GetConversionValue();			//Obtain a single conversion value.

		/*Get the maximum value among multiple conversion values */
		if (tmpValue > tmpValue_Max)
			tmpValue_Max = tmpValue;
		/* Get the minimum value among multiple conversion results */
		if (tmpValue < tmpValue_Min)
			tmpValue_Min = tmpValue;

		tmpValueSum += tmpValue;//The sum of accumulated conversion values
	}

	/* Calculate the average using software multiplication and division */
	{
		/* Dividend is a 16-bit data */
		tmpValueSum -= (tmpValue_Max + tmpValue_Min);

		//Acquisition Factor
		tmpValue = tmpValueSum / (ADC_SamplesNum - 2);
	}

	EADC = tmpStaus;			//Restore EADC
	return tmpValue;			//return the average
}
#endif
/**
 * @}
 */
/* End of ADC_Group2.	*/

/** @defgroup ADC_Group3 Interrupts and flags management functions
 *  @brief    Interrupts and flags management functions
 *
@verbatim
 ===============================================================================
                     ##### Interrupts and flags management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  Checks whether the specified ADC flag is set or not.
 * @param  None
 * @retval The new state of ADC_FLAG (SET or RESET).
 *                  -  RESET:Flag reset
 *                  -  SET :Flag up
 */
FlagStatus ADC_GetFlagStatus(void)
{
#if defined (SC92F854x) || defined (SC92F754x) ||defined  (SC92F844xB) || defined (SC92F744xB)||defined  (SC92F84Ax_2) || defined (SC92F74Ax_2)\
		|| defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB)||defined  (SC92F84Ax) || defined (SC92F74Ax)\
		|| defined  (SC92F83Ax) || defined (SC92F73Ax) || defined (SC92F7003) || defined (SC92F8003) || defined(SC92F8003B) || defined (SC92F740x) || defined (SC92FWxx)\
		|| defined(SC92F848x) || defined(SC92F748x) || defined(SC92F859x) || defined (SC92F759x)	|| defined (SC92L853x) || defined (SC92L753x)\
		|| defined (SC92R511x) || defined (SC92R342) || defined (SC92F841x) || defined (SC92F741x) || defined(SC92F84Hx) || defined(SC92F83Hx)\
	  || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F6x1x) || defined(SC92F5x1x)|| defined(SC92R436)|| defined(SC92R438)|| defined(SC92L840x)\
  	|| defined(SC92R439)  || defined (SC92Fx41xB)|| defined (SC92R445)|| defined (SC92R422A)|| defined (SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)\
	  || defined (SC92F5x5x)|| defined (SC92F531x) || defined (SC92F663x) || defined (SC92F563x)
  return (bool)(ADCCON & 0x20);
#elif defined(SC92F742x) || defined(SC92F730x) || defined(SC92F725X) || defined(SC92F735X) || defined(SC92F732X) || defined(SC92F7490) || defined(SC93F833x) || defined(SC93F843x) || defined(SC93F743x)\
     || defined(SC92F730x_2) || defined(SC92F720x) ||defined (SC92F7308B)
	return (bool)(ADCCON & 0x10);
#endif
}

/**
 * @brief  Clears the ADCx's pending flags.
 * @param  None
 * @retval None
 */
void ADC_ClearFlag(void)
{
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
		|| defined(SC92F846xB) || defined(SC92F746xB) || defined(SC92F836xB) || defined(SC92F736xB) || defined(SC92F84Ax) || defined(SC92F74Ax)\
		|| defined(SC92F83Ax) || defined(SC92F73Ax) || defined(SC92F8003) || defined(SC92F8003B) || defined(SC92F740x) || defined(SC92F848x) || defined(SC92F748x)\
		|| defined(SC92F859x) || defined(SC92F759x)	|| defined (SC92L853x) || defined (SC92L753x) || defined (SC92R511x) || defined (SC92R342)\
		|| defined (SC92F841x) || defined (SC92F741x) || defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)\
	  || defined(SC92F6x1x) || defined(SC92F5x1x)|| defined(SC92R436)|| defined(SC92R438)|| defined(SC92L840x)|| defined(SC92R439)|| defined (SC92Fx41xB)|| defined (SC92R445)\
	  || defined (SC92R422A)|| defined (SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)|| defined (SC92F5x5x)|| defined (SC92F531x) || defined (SC92F663x)\
		|| defined (SC92F563x)
  ADCCON &= 0xdf;
#endif
#if defined(SC92F742x) || defined(SC92F730x) || defined(SC92F725X) || defined(SC92F735X) || defined(SC92F732X) || defined(SC92F7490) || defined(SC93F833x) || defined(SC93F843x) || defined(SC93F743x)\
	|| defined(SC92F730x_2) || defined(SC92F720x) || defined (SC92F7308B)
  ADCCON &= 0xef;
#endif
}

/**
 * @}
 */
/* End of ADC_Group3.	*/

/** @defgroup ADC_Group4 Temperature sensor and PGA management functions
 *  @brief    Temperature sensor  and PGA management functions
 *
@verbatim
 ===============================================================================
                     ##### Temperature sensor and PGA management functions #####
 ===============================================================================
@endverbatim
  * @{
  */
#if defined(SC93F833x) || defined(SC93F843x) || defined(SC93F743x)
unsigned int ADC_TS_StandardData = 0x8000;

/**
 * @brief  Switch temperature sensor function.
 * @param  NewState[in]:new state of the temperature sensor sources.
 *                  @ DISABLE:Function disable
 *                  @ ENABLE:Function enable  
 * @retval None
 */
void ADC_TSCmd(FunctionalState NewState)
{
  if (NewState == DISABLE)
  {
	TSCFG &= 0X7F;
  }
  else
  {
	TSCFG |= 0X80;
  }
}

/**
 * @brief  Temperature sensor high/low selection.
 * @param  NewState[in]:new state of the temperature sensor sources.
 *                  @ LOW:Pull-up compensation offset application control bit.
 *                  @ HIGH:Pull-down compensation offset application control bit.
 * @retval None
 */
void ADC_CHOPConfig(PriorityStatus NewState)
{
  if (NewState == LOW)
  {
	TSCFG &= 0XFE;
  }
  else
  {
	TSCFG |= 0x01;
  }
}

/**
 * @brief  The conversion value of ADC at 25 degrees Celsius when it leaves the factory.
 * @param  None
 * @retval ADC_TS_StandardData:
 */
uint16_t ADC_Get_TS_StandardData(void)
{
  unsigned int code *IFBAddr = 0x3E;
  IAPADE = 0x01; //Pointer points to IFB area.
  ADC_TS_StandardData = *(IFBAddr);
  IAPADE = 0x00; //Pointer points to ROM area.
  return ADC_TS_StandardData;
}

/**
 * @brief  Get the current temperature value.
 * @param  None
* @retval Temperature value:Return the temperature value as a float type.
 */
float ADC_GetTSValue(void)
{
  unsigned char EADC_Flag = EADC; //Get the status of the EA flag.
  unsigned int ADC_Value1 = 0, ADC_Value2 = 0, ADC_Value = 0;
  unsigned int code *IFBAddr = 0x3E;

  ADC_Get_TS_StandardData();
  disableInterrupts();   //Disable interrupts
  ADC_CHOPConfig(LOW);   //Lower the application control bit of offset cancellation.
  ADC_StartConversion(); //Start AD conversion
  while(!ADC_GetFlagStatus());    //Waiting for conversion to complete.
  ADC_ClearFlag();                       //Clear conversion flag.
  ADC_Value1 = ADC_GetConversionValue(); //Retrieve the conversion value for the first AD.
  ADC_CHOPConfig(HIGH);                  //Pull-up to offset application control bit.
  ADC_StartConversion();                 //Start AD conversion.
  while(!ADC_GetFlagStatus());   //Waiting for conversion to complete.
  ADC_ClearFlag();                           //Clear conversion flag.
  ADC_Value2 = ADC_GetConversionValue();     //Retrieve the conversion value for the second AD.
  ADC_Value = (ADC_Value1 + ADC_Value2) / 2; //Calculate the average of two AD samples.

  if (EADC_Flag) //Restore the EA flag before joining the operation.
  {
	enableInterrupts();
  }
  return (25 + ((float)ADC_Value - (float)ADC_TS_StandardData) / 8);
}

/**
 * @brief  Configure PGA related parameters.
 * @param  ADC_PGACOM[in]:PGA common-mode voltage selection.
 *                     - ADC_PGACOM_0V:The common mode voltage is 0V.
 *                     - ADC_PGACOM_1_2V:The common mode voltage is 1.2V.
 * @param  ADC_PGAGAN[in]:Programmable Gain Amplifier.
 *                     - ADC_PGAGAN_NonInvert20:The gain in-phase is 20, and the gain out-of-phase is 19.
 *                     - ADC_PGAGAN_NonInvert100:The gain in-phase is 100, and the gain out-of-phase is 99.
 * @param  ADC_PGAIPT[in]:Programmable Gain Amplifier Phase/Amplitude Selection.
 *                     - ADC_PGAIPT_NonInvert:NonInvert input.
 *                     - ADC_PGAIPT_Invert:inverted input.
 * @retval None
 */
void ADC_PGAConfig(ADC_PGACOM_TypeDef ADC_PGACOM, ADC_PGAGAN_TypeDef ADC_PGAGAN, ADC_PGAIPT_TypeDef ADC_PGAIPT)
{
  PGACON &= 0x8F;
  PGACON |= (ADC_PGACOM | ADC_PGAGAN | ADC_PGAIPT);
}

/**
 * @brief  switch PGA function.
 * @param  NewState[in]:PGA common-mode voltage selection.
 *                     - LOW:Disable PGA .
 *                     - HIGH:Enable PGA .
 * @retval None
 */
void ADC_PGACmd(PriorityStatus NewState)
{
  if (NewState == LOW)
  {
	PGACON &= 0XFE;
  }
  else
  {
	PGACON |= 0x01;
  }
}
#endif

/**
 * @brief  ADC reference voltage selection
 * @param  ADC_Vref[in]:Select reference voltage.
 *              SC92F859x,SC92F759x,SC92F848x,SC92F748x,SC92L853x,SC92L753x,SC92R511x,SC92F646x,
 *              SC92F546x,SC92F542x,SC92F6x1x,SC92F5x1x,SC92R436,SC92R439,SC92R422A,SC92F652x,
 *              SC92R51x_R52x,SC92F552x,SC92F5x5x,SC92F531x,SC92F663x
 *                   Selection range(ADC_VREF_VDD - ADC_VREF_2_048V)
 *              else
 *                   Selection range(ADC_VREF_VDD,ADC_VREF_2_4V)
 *                     - ADC_VREF_VDD:Select VDD as the reference voltage.
 *                     - ADC_VREF_1_024V:Select 1.024V as the reference voltage.
 *                     - ADC_VREF_2_4V:Select 2.4V as the reference voltage.
 *                     - ADC_VREF_2_048V:Select 2.048V as the reference voltage.
 * @retval None
 */
void ADC_VrefConfig(ADC_Vref_TypeDef ADC_Vref)
{
  OPINX = 0xC2;
  OPREG = OPREG & 0X3F | ADC_Vref;
}

/**
 * @}
 */
/* End of ADC_Group4.	*/

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */
#endif

/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/
