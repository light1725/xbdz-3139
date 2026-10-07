/**
 ******************************************************************************
 * @file    sc92f_ddic.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   DDIC function module
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
#include "sc92f_ddic.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup DDIC
 * @brief DDIC driver modules
 * @{
 */

/** @defgroup DDIC_Functions
 * @{
 */
 
#if defined (SC92F854x) || defined (SC92F754x) || defined  (SC92F844xB) || defined (SC92F744xB) || defined  (SC92F84Ax_2) || defined (SC92F74Ax_2)\
		|| defined (SC92F859x) || defined (SC92F759x) || defined (SC92L853x) || defined (SC92L753x) || defined (SC92R511x) || defined (SC92F6x1x)\
		|| defined (SC92F5x1x) || defined (SC92R436)|| defined (SC92R438)|| defined (SC92R439)|| defined (SC92R422A)|| defined (SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)\
		|| defined (SC92F531x) || defined(SC92F663x) || defined(SC92F563x)
		
#if defined (SC92L853x) || defined (SC92L753x)
uint8_t xdata LCDRAM[30] _at_ 0xF00;
#elif defined(SC92F6x1x) || defined(SC92F5x1x)|| defined(SC92R436)|| defined(SC92R438)|| defined (SC92R439)|| defined (SC92R422A)
uint8_t xdata LEDRAM[24] _at_ 0x400;
#elif defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)
uint8_t xdata LED_LCDRAM[24] _at_ 0x1000;
#elif defined(SC92F531x)
uint8_t xdata LEDRAM[8] _at_ 0x100; 
#elif defined(SC92F663x)
uint8_t xdata LEDRAM[16] _at_ 0x1000;
#elif defined(SC92F563x)
uint8_t xdata LED_LCDRAM[32] _at_ 0x1000;
#else
uint8_t xdata LCDRAM[30] _at_ 0x700;
#endif

/** @defgroup DDIC_Group1 Initialization and Configuration functions
 *  @brief Initialization and Configuration functions
 *
 
@verbatim
 ===============================================================================
                     ##### Initialization and Configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */
  
 /**
 * @brief  DeInitializes the DDIC peripheral
 * @retval None
 */
void DDIC_DeInit(void)
{
#if !defined(SC92F6x1x) && !defined(SC92F5x1x) && !defined(SC92R436)&& !defined(SC92R438)&& !defined(SC92R439)&& !defined(SC92R422A)\
		&& !defined(SC92F652x) && !defined(SC92R51x_R52x) && !defined(SC92F552x) && !defined(SC92F531x) && !defined(SC92F663x)\
		&& !defined(SC92F563x)
  DDRCON = 0X00;
  P0VO = 0X00;
  P1VO = 0X00;
  P2VO = 0X00;
#if defined (SC92L853x) || defined (SC92L753x)
	P5VO = 0X00;
#else
  P3VO = 0X00;
#endif
  OTCON &= 0XF0;
#endif
#if defined(SC92F6x1x) || defined(SC92F5x1x) || defined (SC92R436)|| defined (SC92R438)|| defined (SC92R439)|| defined (SC92R422A)
   LEDVO1  = 0X00;  
   DDRCON  = 0X00;  
   SCANCON = 0X00; 
   LEDVO0  = 0X00;
#elif defined(SC92F531x)
	 DDRCON1  = 0X00;
	 DDRCON2  = 0X00;
	 DDRCON0  = 0X00;
	 LEDVO    = 0X00;
	 COMCON   = 0X00;
   SCANCON  = 0X00;
#elif defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)
	 OTCON   &= 0XF0;
   DDRCON1  = 0X00;
	 DDRCON2  = 0X00;
	 SCANCON  = 0X00;
	 
	 DDRCON0  = 0X08;
	 LEDVO    = 0X00;
	 DDRCON0  = 0X05;
	 LEDVO    = 0X00;
	 COMCON   = 0X00;
	 DDRCON0  = 0X00;
	 LEDVO    = 0X00;
	 COMCON   = 0X00;
#elif defined(SC92F663x)
	 DDRCON2  = 0X00;
	 COMCON   = 0X00;
	 SCANCON  = 0X00;
	 
	 DDRCON0  = 0X08;
	 LEDVO    = 0X00;
   DDRCON0  = 0X04;
	 LEDVO    = 0X00;
	 DDRCON0  = 0X00;
	 LEDVO    = 0X00;
#elif defined(SC92F563x)
	 OTCON   &= 0XF0;
   DDRCON1  = 0X00;
	 DDRCON2  = 0X00;
	 COMCON   = 0X00;
	 SCANCON  = 0X00;
	 
	 DDRCON0  = 0X0C;
	 LEDVO    = 0X00;
	 DDRCON0  = 0X08;
	 LEDVO    = 0X00;
   DDRCON0  = 0X04;
	 LEDVO    = 0X00;
	 DDRCON0  = 0X00;
	 LEDVO    = 0X00;
#endif
}

/**
 * @brief  Initializes the peripheral DDIC register according to the parameters.
 * @param  DDIC_DutyCycle_TypeDef[in]: Set DDIC duty cycle configuration.
 *                     - DDIC_DUTYCYCLE_D8:1/8 duty cycle
 *                     - DDIC_DUTYCYCLE_D6:1/6 duty cycle
 *                     - DDIC_DUTYCYCLE_D5:1/5 duty cycle
 *                     - DDIC_DUTYCYCLE_D4:1/4 duty cycle
 * @param  P1OutputPin[in]: Set pin P1 as the LCD voltage output port.
 * @param  P2OutputPin[in]: Set pin P2 as the LCD voltage output port.
 * @param  P3OutputPin[in]: Set pin P3 as the LCD voltage output port.When the model is SC92L853x or SC92L753x, it actually corresponds to setting the P5 port.
 * @retval None
 */
#if !defined(SC92F6x1x) && !defined(SC92F5x1x) && !defined(SC92R436) && !defined(SC92R438)&& !defined(SC92R439)&& !defined(SC92R422A)
#if defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F663x)
void DDIC_Init(DDIC_DutyCycle_TypeDef DDIC_DutyCylce,
               uint8_t P0OutputPin, uint8_t P1OutputPin,
               uint8_t P2OutputPin)
{
  DDRCON0 = DDRCON0 & 0XCF | DDIC_DutyCylce;
	DDRCON0 = DDRCON0 & 0XF3 | 0X00;
	LEDVO = P0OutputPin;
	DDRCON0 = DDRCON0 & 0XF3 | 0X04;
	LEDVO = P1OutputPin;
	DDRCON0 = DDRCON0 & 0XF3 | 0X08;
	LEDVO = P2OutputPin;
#if defined(SC92F663x)
	COMCON = 0X00;
#else
	DDRCON0 = DDRCON0 & 0XFC | 0X00;
	COMCON = 0X00;
	DDRCON0 = DDRCON0 & 0XFC | 0X01;
	COMCON = 0X00;
#endif
}
#elif defined(SC92F531x)
void DDIC_Init(uint8_t P0OutputPin)
{
	LEDVO = P0OutputPin;
	COMCON = 0X00;
}
#elif defined(SC92F563x)
void DDIC_Init(DDIC_DutyCycle_TypeDef DDIC_DutyCylce,
               uint8_t P0OutputPin, uint8_t P1OutputPin,
               uint8_t P2OutputPin, uint8_t P3OutputPin)
{
  DDRCON0 = DDRCON0 & 0XCF | DDIC_DutyCylce;
	DDRCON0 = DDRCON0 & 0XF3 | 0X00;
	LEDVO = P0OutputPin;
	DDRCON0 = DDRCON0 & 0XF3 | 0X04;
	LEDVO = P1OutputPin;
	DDRCON0 = DDRCON0 & 0XF3 | 0X08;
	LEDVO = P2OutputPin;
	DDRCON0 = DDRCON0 & 0XF3 | 0X0C;
	LEDVO = P3OutputPin;
	COMCON = 0X00;
}
#else
void DDIC_Init(DDIC_DutyCycle_TypeDef DDIC_DutyCylce,
               uint8_t P0OutputPin, uint8_t P1OutputPin,
               uint8_t P2OutputPin, uint8_t P3OutputPin)
{
  DDRCON = DDRCON & 0XCF | DDIC_DutyCylce;
  P0VO = P0OutputPin;
  P1VO = P1OutputPin;
  P2VO = P2OutputPin;
#if defined (SC92L853x) || defined (SC92L753x)
	P5VO = P3OutputPin;
#else
  P3VO = P3OutputPin;
#endif
}
#endif

/**
 * @brief  Set DDIC to LED driving mode.
 * @param  None
 * @retval None
 */
#if !defined(SC92F531x) && !defined(SC92F663x)
#if defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F563x)
void DDIC_LEDDrivingModeConfig(void)
{
  DDRCON0 |= 0X40;
}
#else
void DDIC_LEDDrivingModeConfig(void)
{
  DDRCON |= 0X40;
}
#endif
#endif

/**
 * @brief  Initializes the peripheral DDIC register according to the parameters.
 * @param  LCDVoltage[in]: LCD voltage regulation.
 * @param  DDIC_ResSel[in]:Set pin P1 as the LCD voltage output port.
 * if the model is SC92F652x,SC92R51x_R52x,SC92F552x
 *                     - DDIC_ResSel_11K:Set the internal voltage divider resistor to 11k.
 *                     - DDIC_ResSel_100K:Set the internal voltage divider resistor to 100k.
 *                     - DDIC_ResSel_300K:Set the internal voltage divider resistor to 300k.
 *                     - DDIC_ResSel_800K:Set the internal voltage divider resistor to 800k.
 * if the model is else model
 *                     - DDIC_ResSel_100K:Set the internal voltage divider resistor to 100k.
 *                     - DDIC_ResSel_200K:Set the internal voltage divider resistor to 200k.
 *                     - DDIC_ResSel_400K:Set the internal voltage divider resistor to 400k.
 *                     - DDIC_ResSel_800K:Set the internal voltage divider resistor to 800k.
 * @param  DDIC_BiasVoltage[in]:Set the LCD display driver bias voltage.
 *                     - DDIC_BIAS_D3:The LCD bias voltage is 1/3.
 *                     - DDIC_BIAS_D4:The LCD bias voltage is 1/4.
 * @retval None
 */
#if !defined(SC92F531x) && !defined(SC92F663x)
#if defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F563x)
void DDIC_LCDConfig(uint8_t LCDVoltage,
                    DDIC_ResSel_Typedef DDIC_ResSel,
                    DDIC_BiasVoltage_Typedef DDIC_BiasVoltage)
{
  DDRCON1 = DDRCON1 & 0XF0 | LCDVoltage;
  OTCON = OTCON & 0XF2 | DDIC_ResSel | DDIC_BiasVoltage;
}
#else
void DDIC_LCDConfig(uint8_t LCDVoltage,
                    DDIC_ResSel_Typedef DDIC_ResSel,
                    DDIC_BiasVoltage_Typedef DDIC_BiasVoltage)
{
  DDRCON = DDRCON & 0XB0 | LCDVoltage;
  OTCON = OTCON & 0XF2 | DDIC_ResSel | DDIC_BiasVoltage;
}
#endif
#endif

/**
 * @brief  DDIC Clock Configuration.
 * @param  Clock_Source[in]:LCD/LED clock source.
 *                     - Source_Fsys:Set the clock source to the system clock.
 *                     - Source_32K:Set the clock source to the internal 32KHz or the external 32.768KHz.
 * @param  Clock_Division[in]:LCD/LED clock division.
 *                     - Fsys_4096_or_16:Set the clock division ratio to 4096 (under Source_Fsys) or 16 (under Source_32K).
 *                     - Fsys_8192_or_32:Set the clock division ratio to 8192 (under Source_Fsys) or 32 (under Source_32K).
 *                     - Fsys_16384_or_64:Set the clock division ratio to 16384 (under Source_Fsys) or 64 (under Source_32K).
 *                     - Fsys_32768_or_128:Set the clock division ratio to 32768 (under Source_Fsys) or 128 (under Source_32K).
 * @retval None
 */
#if defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F563x)
void DDIC_LCDClockConfig(DDIC_ClockSource_TypeDef Clock_Source,
                         DDIC_CK_TypeDef Clock_Division)
{
  DDRCON1 = DDRCON1 & 0X7F | Clock_Source;
  SCANCON = SCANCON & 0XFC | Clock_Division;
}
#elif defined(SC92F531x)
void DDIC_LEDClockConfig(DDIC_ClockSource_TypeDef Clock_Source)
{
  DDRCON1 = DDRCON1 & 0X7F | Clock_Source;
}
#elif defined(SC92F663x)
void DDIC_LEDClockConfig(DDIC_ClockSource_TypeDef Clock_Source,
                         DDIC_CK_TypeDef Clock_Division)
{
  Clock_Source = 0x00;
  SCANCON = SCANCON & 0XFC | Clock_Division;
}
#endif

/**
 * @brief  Select DDIC display driver mode.
 * @param  DDIC_DMOD_TypeDef[in]: Select Display Mode.
 *                     - DMOD_LED:Select LED mode.
 *                     - DMOD_LCD:Select LCD mode.
 * @retval None
 */
#if !defined(SC92F531x) && !defined(SC92F663x)
#if defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F563x)
void DDIC_DMOD_Selcet(DDIC_LMOD_TypeDef DDIC_DMOD)
{
  if(DDIC_DMOD == DMOD_LED)
  {
    DDRCON0 &= 0XBF;
  }
  else
  {
    DDRCON0 |= 0X40;
  }
}
#else
void DDIC_DMOD_Selcet(DDIC_DMOD_TypeDef DDIC_DMOD)
{
  if(DDIC_DMOD == DMOD_LED)
  {
    DDRCON |= 0X40;
  }
  else
  {
    DDRCON &= 0XBF;
  }
}
#endif
#endif



/**
 * @brief  Selection of segment and common multiplexing pins for LED at 1/4 duty cycle.
 * @param  DDIC_OutputPin_TypeDef[in]: Select segment and common multiplexing pins.
 *                     - SEG4_11COM0_7:S4-S11 are segments, C0-C7 are common.
 *                     - SEG2_11COM2_7:S2-S11 are segments, C2-C7 are common.
 *                     - SEG1_11COM3_7:S1-S11 are segments, C3-C7 are common.
 *                     - SEG0_11COM4_7:S0-S11 are segments, C4-C7 are common.
 * @retval None
 */
#if !defined(SC92F652x)&& !defined(SC92R51x_R52x) && !defined(SC92F552x)&& !defined(SC92F531x) && !defined(SC92F663x) && !defined(SC92F563x)
void DDIC_OutputPinOfDutycycleD4(DDIC_OutputPin_TypeDef DDIC_OutputPin)
{
	OTCON &=  ~0X02;
	OTCON |= DDIC_OutputPin<<1;
}
#endif

/**
 * @brief  Selection of segment and common multiplexing pins for LED at 1/4 duty cycle.
 * @param  DDIC_Control_SEG_TypeDef[in]: Select segment pins.
 *                     - DDIC_SEG0:select SEG0.
 *                     - DDIC_SEG1:select SEG1.
 *                     - DDIC_SEG2:select SEG2.
 *                     - DDIC_SEG3:select SEG3.
 *                     - DDIC_SEG4:select SEG4.
 *                     - DDIC_SEG5:select SEG5.
 *                     - DDIC_SEG6:select SEG6.
 *                     - DDIC_SEG7:select SEG7.
 *                     - DDIC_SEG8:select SEG8.
 *                     - DDIC_SEG9:select SEG9.
 *                     - DDIC_SEG10:select SEG10.
 *                     - DDIC_SEG11:select SEG11.
 *                     - DDIC_SEG12:select SEG12.
 *                     - DDIC_SEG13:select SEG13.
 *                     - DDIC_SEG14:select SEG14.
 *                     - DDIC_SEG15:select SEG15.
 *                     - DDIC_SEG16:select SEG16.
 *                     - DDIC_SEG17:select SEG17.
 *                     - DDIC_SEG18:select SEG18.
 *                     - DDIC_SEG19:select SEG19.
 *                     - DDIC_SEG20:select SEG20.
 *                     - DDIC_SEG21:select SEG21.
 *                     - DDIC_SEG22:select SEG22.
 *                     - DDIC_SEG23:select SEG23.
 *                     - DDIC_SEG24:select SEG24.
 *                     - DDIC_SEG25:select SEG25.
 *                     - DDIC_SEG26:select SEG26.
 *                     - DDIC_SEG27:select SEG27.
 * @param  DDIC_Control_COM_TypeDef[in]: Select common pins.
 * @param  DDIC_Control_Status[in]: The status of the control bit corresponding to DDIC.
 *                     - DDIC_Control_ON:Enable.
 *                     - DDIC_Control_OFF:Disable.
 * @retval None
 */
#if defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)
void DDIC_Control(DDIC_Control_SEG_TypeDef DDIC_Seg,
                  uint8_t DDIC_Com,
                  DDIC_Control_Status DDIC_Contr)
{
  if(DDIC_Contr)
  {
		if(DDIC_Seg < 0x0100)
		{
			LED_LCDRAM[DDIC_Com*2] |= (uint8_t)DDIC_Seg;
		}
		else if(DDIC_Seg < 0x010000)
		{
			LED_LCDRAM[DDIC_Com*2+1] |= (uint8_t)(DDIC_Seg>>8);
		}
  }
  else
  {
    if(DDIC_Seg < 0x0100)
		{
			LED_LCDRAM[DDIC_Com*2] &= ~(uint8_t)DDIC_Seg;
		}
		else if(DDIC_Seg < 0x010000)
		{
			LED_LCDRAM[DDIC_Com*2+1] &= ~(uint8_t)(DDIC_Seg>>8);
		}
  }
}
#elif defined(SC92F663x)
void DDIC_Control(DDIC_Control_SEG_TypeDef DDIC_Seg,
                  uint8_t DDIC_Com,
                  DDIC_Control_Status DDIC_Contr)
{
  if(DDIC_Contr)
  {
		if(DDIC_Seg < 0x0100)
		{
			LEDRAM[DDIC_Com*2+1] |= (uint8_t)DDIC_Seg;
		}
		else if(DDIC_Seg < 0x010000)
		{
			LEDRAM[DDIC_Com*2] |= (uint8_t)(DDIC_Seg>>8);
		}
  }
  else
  {
    if(DDIC_Seg < 0x0100)
		{
			LEDRAM[DDIC_Com*2+1] &= ~(uint8_t)DDIC_Seg;
		}
		else if(DDIC_Seg < 0x010000)
		{
			LEDRAM[DDIC_Com*2] &= ~(uint8_t)(DDIC_Seg>>8);
		}
  }
}
#elif defined(SC92F563x)
void DDIC_Control(DDIC_Control_SEG_TypeDef DDIC_Seg,
                  uint8_t DDIC_Com,
                  DDIC_Control_Status DDIC_Contr)
{
  if(DDIC_Contr)
  {
		if(DDIC_Seg < 0x0100)
		{
			LED_LCDRAM[DDIC_Com*4+3] |= (uint8_t)DDIC_Seg;
		}
		else if(DDIC_Seg < 0x010000)
		{
			LED_LCDRAM[DDIC_Com*4+2] |= (uint8_t)(DDIC_Seg>>8);
		}
		else if(DDIC_Seg < 0x01000000)
		{
			LED_LCDRAM[DDIC_Com*4+1] |= (uint8_t)(DDIC_Seg>>16);
		}
		else
		{
			LED_LCDRAM[DDIC_Com*4] |= (uint8_t)(DDIC_Seg>>24);
		}
  }
  else
  {
    if(DDIC_Seg < 0x0100)
		{
			LED_LCDRAM[DDIC_Com*4+3] &= ~(uint8_t)DDIC_Seg;
		}
		else if(DDIC_Seg < 0x010000)
		{
			LED_LCDRAM[DDIC_Com*4+2] &= ~(uint8_t)(DDIC_Seg>>8);
		}
		else if(DDIC_Seg < 0x01000000)
		{
			LED_LCDRAM[DDIC_Com*4+1] &= ~(uint8_t)(DDIC_Seg>>16);
		}
		else
		{
			LED_LCDRAM[DDIC_Com*4] &= ~(uint8_t)(DDIC_Seg>>24);
		}
  }
}
#elif defined(SC92F531x)
void DDIC_Control(uint8_t OutputPin,
                  DDIC_Control_Status DDIC_Contr)
{
	uint16_t i;
	for(i=0;i<=7;i++)
	{
		if((OutputPin>>i)&0x01)
		{
			if(DDIC_Contr)
			{
				LEDRAM[i] |= OutputPin;
			}
			else
			{
				LEDRAM[i] &= (~OutputPin);
			}
		}
	}
}
#else
void DDIC_Control(DDIC_Control_SEG_TypeDef DDIC_Seg,
                  uint8_t DDIC_Com,
                  DDIC_Control_Status DDIC_Contr)
{
  if(DDIC_Contr)
  {
    LCDRAM[DDIC_Seg] |= DDIC_Com;
  }
  else
  {
    LCDRAM[DDIC_Seg] &= (~DDIC_Com);
  }
}
#endif

#endif

#if defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436) || defined(SC92R438) || defined(SC92R439) || defined(SC92R422A)\
      || defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F531x) || defined(SC92F663x) || defined(SC92F563x)
/**
 * @brief  Initialization configuration function for the LED mode.
 * @param  DDIC_OutputPin_TypeDef[in]: Select segment and common multiplexing pins.
 *                     - SEG4_11COM0_7:S4-S11 are segments, C0-C7 are common.
 *                     - SEG2_11COM2_7:S2-S11 are segments, C2-C7 are common.
 *                     - SEG1_11COM3_7:S1-S11 are segments, C3-C7 are common.
 *                     - SEG0_11COM4_7:S0-S11 are segments, C4-C7 are common.
 * @param  OutputPin[in]: Set the I/O port pins as LCD voltage output pins.
 * @retval None
 */
#if defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)
void DDIC_LEDInit(DDIC_OutputPin_TypeDef DDIC_DutyCylce,uint32_t OutputPin)
{
	uint16_t i;
  DDRCON0 = DDRCON0 & 0XCF | DDIC_DutyCylce;
	for(i=0;i<=19;i++)
	{
		if((OutputPin>>i)&0x01)
		{
			if(i<=7)
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x00; 
				LEDVO |= (0x01<<i);
			}
			else if(i<=15)
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x04;
				LEDVO |=(0x01<<(i-8));
			}
			else
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x08;
				LEDVO |=(0x01<<(i-16));
			}
		}
  }
}
#elif defined(SC92F663x)
void DDIC_LEDInit(DDIC_OutputPin_TypeDef DDIC_DutyCylce,uint32_t OutputPin)
{
	uint16_t i;
  DDRCON0 = DDRCON0 & 0XCF | DDIC_DutyCylce;
	for(i=0;i<=23;i++)
	{
		if((OutputPin>>i)&0x01)
		{
			if(i<=7)
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x00; 
				LEDVO |= (0x01<<i);
			}
			else if(i<=15)
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x04;
				LEDVO |=(0x01<<(i-8));
			}
			else
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x08;
				LEDVO |=(0x01<<(i-16));
			}
		}
  }
}
#elif defined(SC92F563x)
void DDIC_LEDInit(DDIC_OutputPin_TypeDef DDIC_DutyCylce,uint32_t OutputPin)
{
	uint16_t i;
  DDRCON0 = DDRCON0 & 0XCF | DDIC_DutyCylce;
	for(i=0;i<=27;i++)
	{
		if((OutputPin>>i)&0x01)
		{
			if(i<=7)
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x00; 
				LEDVO |= (0x01<<i);
			}
			else if(i<=15)
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x04;
				LEDVO |=(0x01<<(i-8));
			}
			else if(i<=23)
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x08;
				LEDVO |=(0x01<<(i-16));
			}
			else
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x0C;
				LEDVO |=(0x01<<(i-24));
			}
		}
  }
}
#elif defined(SC92F531x)
void DDIC_LEDInit(DDIC_OutputPin_TypeDef DDIC_DutyCylce,uint16_t OutputPin)
{
	uint16_t i;
  DDIC_DutyCylce = None;
	for(i=0;i<=7;i++)
	{
		if((OutputPin>>i)&0x01)
		{
			if(i<=7)
			{
				LEDVO |= (0x01<<i);
			}
		}
  }
}
#else
void DDIC_LEDInit(DDIC_OutputPin_TypeDef DDIC_DutyCylce,uint16_t OutputPin)
{
	uint16_t i;
  DDRCON = DDRCON & 0XCF | DDIC_DutyCylce;
	for(i=0;i<=15;i++)
	{
		if((OutputPin>>i)&0x01)
		{
			if(i<=7)
			{
				LEDVO0 |= (0x01<<i);
			}
			else
			{
				LEDVO1 |=(0x01<<(i-8));
			}
		}
  }
}
#endif

/**
 * @brief  Initialization configuration function for the LED mode.
 * @param  OutputPin[in]: Set the I/O port pins as LCD voltage output pins.
 * @retval None
 */
#if defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)
void DDIC_LEDOutputPinOfDuty(uint32_t OutputPin)
{
	uint16_t i;
	for(i=0;i<=19;i++)
	{
		if((OutputPin>>i)&0x01)
		{
			if(i<=7)
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x00; 
				LEDVO |= (0x01<<i);
			}
			else if(i<=15)
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x04;
				LEDVO |=(0x01<<(i-8));
			}
			else
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x08;
				LEDVO |=(0x01<<(i-16));
			}
		}
  }
}
#elif defined(SC92F663x)
void DDIC_LEDOutputPinOfDuty(uint32_t OutputPin)
{
	uint16_t i;
	for(i=0;i<=23;i++)
	{
		if((OutputPin>>i)&0x01)
		{
			if(i<=7)
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x00; 
				LEDVO |= (0x01<<i);
			}
			else if(i<=15)
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x04;
				LEDVO |=(0x01<<(i-8));
			}
			else
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x08;
				LEDVO |=(0x01<<(i-16));
			}
		}
  }
}
#elif defined(SC92F563x)
void DDIC_LEDOutputPinOfDuty(uint32_t OutputPin)
{
	uint16_t i;
	for(i=0;i<=27;i++)
	{
		if((OutputPin>>i)&0x01)
		{
			if(i<=7)
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x00; 
				LEDVO |= (0x01<<i);
			}
			else if(i<=15)
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x04;
				LEDVO |=(0x01<<(i-8));
			}
			else if(i<=23)
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x08;
				LEDVO |=(0x01<<(i-16));
			}
			else
			{
				DDRCON0 &= 0xF3;
				DDRCON0 |= 0x0C;
				LEDVO |=(0x01<<(i-24));
			}
		}
  }
}
#elif defined(SC92F531x)
void DDIC_LEDOutputPinOfDuty(uint16_t OutputPin)
{
  uint16_t i;
	for(i=0;i<=7;i++)
	{
		if((OutputPin>>i)&0x01)
		{
			if(i<=7)
			{
				LEDVO |= (0x01<<i);
			}
		}
  }
}
#else
void DDIC_LEDOutputPinOfDuty(uint16_t OutputPin)
{
  uint16_t i;
	for(i=0;i<=15;i++)
	{
		if((OutputPin>>i)&0x01)
		{
			if(i<=7)
			{
				LEDVO0 |= (0x01<<i);
			}
			else
			{
				LEDVO1 |=(0x01<<(i-8));
			}
		}
  }
}
#endif

/**
 * @brief  Adjust LED brightness.
 * @param  DDIC_DRIV_TypeDef[in]: Adjust LED current levels.
 *                     - LED_DRIV0:Brightness level 1.
 *                     - LED_DRIV1:Brightness level 2.
 *                     - LED_DRIV2:Brightness level 3.
 *                     - LED_DRIV3:Brightness level 4.
 *                     - LED_DRIV4:Brightness level 5.
 *                     - LED_DRIV5:Brightness level 6.
 *                     - LED_DRIV6:Brightness level 7.
 *                     - LED_DRIV7:Brightness level 8.
 *                     - LED_DRIV8:Brightness level 9.
 *                     - LED_DRIV9:Brightness level 10.
 *                     - LED_DRIV10:Brightness level 11.
 *                     - LED_DRIV11:Brightness level 12.
 *                     - LED_DRIV12:Brightness level 13.
 *                     - LED_DRIV13:Brightness level 14.
 *                     - LED_DRIV14:Brightness level 15.
 *                     - LED_DRIV15:Brightness level 16.
 * @retval None
 */
#if !defined(SC92F663x) && !defined(SC92F563x)
#if defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F531x)
void DDIC_LEDDRIVSelect(DDIC_DRIV_TypeDef LEDVoltage)
{
  DDRCON2 = DDRCON2 & 0XF0 | LEDVoltage;
}
#else
void DDIC_LEDDRIVSelect(DDIC_DRIV_TypeDef LEDVoltage)
{
  DDRCON = DDRCON & 0XF0 | LEDVoltage;
}
#endif
#endif

/**
 * @brief  Initialize LED configuration..
 * @param  DDIC_LEDXT_TypeDef[in]: Set the specific scan port scan time for the LED.
 *                     - LED_0_5T:The LED scanning period is 0.5T.
 *                     - LED_1T:The LED scanning period is 1T.
 *                     - LED_1_5T:The LED scanning period is 1.5T.
 *                     - LED_2T:The LED scanning period is 2 T.
 * @param  DDIC_LEDEL_TypeDef[in]: Select LED specific port.
 *                     - LED0:LED0 is selected for a specific port.
 *                     - LED1:LED1 is selected for a specific port.
 *                     - LED8:LED8 is selected for a specific port.
 *                     - LED9:LED9 is selected for a specific port.
 * @param  DDIC_LEDCK_TypeDef[in]: Select LED module clock division.
 *                     - LED_Fsys_8182:LED clock 8182 frequency division.
 *                     - LED_Fsys_16384:LED clock 16384 frequency division.
 *                     - LED_Fsys_32768:LED clock 32768 frequency division.
 *                     - LED_Fsys_65536:LED clock 65536 frequency division.
 * @retval None
 */
void DDIC_LEDConfig(DDIC_LEDXT_TypeDef DDIC_LEDXT,
                    DDIC_LEDEL_TypeDef DDIC_LEDEL,
                    DDIC_LEDCK_TypeDef DDIC_LEDCK)
{
  SCANCON = SCANCON & 0XC0 | DDIC_LEDXT |DDIC_LEDEL| DDIC_LEDCK;
}

/**
 * @brief  Select DDIC display driver mode.
 * @param  DDIC_DMOD_TypeDef[in]: Select Display Mode.
 *                     - DMOD_Normal:Select Normal mode.
 *                     - DMOD_ForBack:Select LED forward and reverse drive mode.
 * @retval None
 */
#if !defined(SC92F531x)
#if defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)
void DDIC_LEDDMOD_Selcet(DDIC_DMOD_TypeDef DDIC_DMOD)
{
	DDRCON2 &=0xBF;
  DDRCON2 |= DDIC_DMOD;
	if(DDRCON2&0x40 != 0)
	{
		DDRCON0 = DDRCON0 & 0XFC | 0X00;
		COMCON = 0xFF;
		DDRCON0 = DDRCON0 & 0XFC | 0X01;
		COMCON = 0xFF;
	}
}
#elif defined(SC92F663x) || defined(SC92F563x)
void DDIC_LEDDMOD_Selcet(DDIC_DMOD_TypeDef DDIC_DMOD)
{
	DDRCON2 &=0xBF;
  DDRCON2 |= DDIC_DMOD;
	if(DDRCON2&0x40 != 0)
	{
		COMCON = 0xFF;
	}
}
#else
void DDIC_LEDDMOD_Selcet(DDIC_DMOD_TypeDef DDIC_DMOD)
{
	DDRCON &=0xBF;
  DDRCON |= DDIC_DMOD;
}
#endif
#endif

/**
 * @brief  Configure IO port constant current output mode.
 * @param  FunctionalState[in]: new state of the DDIC peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable  
 * @retval None
 */
#if !defined(SC92F663x) && !defined(SC92F563x)
void DDIC_LEDCMCmd(FunctionalState NewState)
{
  if(NewState != ENABLE)
	{
		SCANCON &=~(0x40) ;
	}
	else
	{
		SCANCON |= (0x40) ;
	}
}
#endif

/**
 * @brief  Clear DDIC Status flag.
 * @param  DDIC_Flag_TypeDef[in]: DDIC Flag.
 *                  - LED_Flag_AUIF:AUIF Flag
 * @retval None
 */
void DDIC_ClearFlag(DDIC_Flag_TypeDef DDIC_FLAG)
{
   SCANCON |= DDIC_FLAG;
}
#endif

/**
 * @brief  Enable or disable DDIC peripheral.
 * @param  FunctionalState[in]: new state of the DDIC peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable  
 * @retval None
 */
#if defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F531x) || defined(SC92F663x) || defined(SC92F563x)
void DDIC_Cmd(FunctionalState NewState)
{
  if(NewState == DISABLE)
  {
    DDRCON0 &= 0X7F;
  }
  else
  {
    DDRCON0 |= 0x80;
  }
}
#else
void DDIC_Cmd(FunctionalState NewState)
{
  if(NewState == DISABLE)
  {
    DDRCON &= 0X7F;
  }
  else
  {
    DDRCON |= 0x80;
  }
}
#endif


#endif

#if defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB) || defined (SC92F83Ax) || defined (SC92F73Ax)\
		|| defined (SC92F84Ax) || defined (SC92F74Ax) || defined (SC92F742x) || defined (SC92F730x) || defined (SC92F725X) || defined (SC92F735X)\
		|| defined (SC92F732X) || defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x) || defined (SC92F848x) || defined (SC92F748x)\
		|| defined (SC92R342) || defined (SC92F841x) || defined (SC92F741x) || defined(SC92F730x_2) || defined(SC92F720x) || defined (SC92F7308B)\
    || defined (SC92Fx41xB)|| defined (SC92R445)
 /**
 * @brief  DeInitializes the DDIC peripheral
 * @retval None
 */
void DDIC_DeInit(void)
{
  P0VO   = 0X00;
  OTCON &= 0XF3;
}

/**
 * @brief  Initializes the peripheral DDIC register according to the parameters.
 * @param  P0OutputPin[in]: Set P0 pin as the LCD voltage output pin.
 * @retval None
 */
void DDIC_Init(uint8_t P0OutputPin)
{
  P0VO = P0OutputPin;
}

/**
 * @brief  Initializes the LCD according to the parameters.
 * @param  DDIC_ResSel_Typedef[in]:Select the output resistance of the LCD voltage output port.
 *                     - DDIC_ResSel_100K:Set the internal voltage divider resistor to 100k.
 *                     - DDIC_ResSel_200K:Set the internal voltage divider resistor to 200k.
 *                     - DDIC_ResSel_400K:Set the internal voltage divider resistor to 400k.
 *                     - DDIC_ResSel_800K:Set the internal voltage divider resistor to 800k.

 * @retval None
 */
void DDIC_LCDConfig(DDIC_ResSel_Typedef DDIC_ResSel)
{
  OTCON = (OTCON & 0XF3) | DDIC_ResSel;
}

/**
 * @brief  Initializes the peripheral DDIC register according to the parameters.
 * @param  P0OutputPin[in]: Set pin P0 as the LCD voltage output pin.
 * @param  DDIC_ResSel_Typedef[in]:Set pin P1 as the LCD voltage output port.
 *                     - DDIC_ResSel_100K:Set the internal voltage divider resistor to 100k.
 *                     - DDIC_ResSel_200K:Set the internal voltage divider resistor to 200k.
 *                     - DDIC_ResSel_400K:Set the internal voltage divider resistor to 400k.
 *                     - DDIC_ResSel_800K:Set the internal voltage divider resistor to 800k.
 * @retval None
 */
void DDIC_Config_Init(uint8_t P0OutputPin,
                      DDIC_ResSel_Typedef DDIC_ResSel)
{
  P0VO = P0OutputPin;
  OTCON = (OTCON & 0XF3) | DDIC_ResSel;
}

#endif
/**
 * @}
 */
/* End of DDIC_Group1.	*/

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