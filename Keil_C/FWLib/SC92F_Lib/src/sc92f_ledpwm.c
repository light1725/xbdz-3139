/**
 ******************************************************************************
 * @file    sc92f_ledpwm.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   LEDPWM function module
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
#include "sc92f_ledpwm.h"

#if defined(SC92F663x)

uint8_t xdata LEDPWMCON _at_ 0x1010;  //LEDPWM¿ØÖÆ¼Ä´æÆ÷
uint8_t xdata LEDPWMEN0 _at_ 0x1011;  //LEDPWMÍ¨µÀÅäÖÃ¼Ä´æÆ÷0
uint8_t xdata LEDPWMEN1 _at_ 0x1012;  //LEDPWMÍ¨µÀÅäÖÃ¼Ä´æÆ÷1
uint8_t xdata LEDPWMCFG0 _at_ 0x1013;  //LEDPWM·´Ïà¿ØÖÆ¼Ä´æÆ÷0
uint8_t xdata LEDPWMCFG1 _at_ 0x1014;  //LEDPWM·´Ïà¿ØÖÆ¼Ä´æÆ÷1
uint8_t xdata LEDPWMPD _at_ 0x1015;  //LEDPWMÖÜÆÚ¼Ä´æÆ÷

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup LEDPWM
 * @brief LEDPWM driver modules
 * @{
 */

/** @defgroup LEDPWM_Functions
 * @{
 */

/** @defgroup LEDPWM_Group1 Configuration of the LEDPWM computation unit functions
 *  @brief   Configuration of the LEDPWM computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### LEDPWM configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  Deinitialize the LEDPWM peripheral registers to their default reset values.
 * @param  None
 * @retval None
 */
void LEDPWM_DeInit(void)
{
	static uint8_t i;
	uint8_t *pPDT;
	pPDT = (uint8_t *)0x1000;
	for(i = 0; i < 16; i++)
  {
    *(pPDT + i) = 0x00;
  }
  LEDPWMCON   = 0x00; 
  LEDPWMEN0   = 0x00;
  LEDPWMEN1   = 0x00;
	LEDPWMCFG0  = 0x00;
  LEDPWMCFG1  = 0x00;
	LEDPWMPD    = 0x00;
	IE2 &= 0xBF;
	IP2 &= 0xBF;
}

/**
 * @brief  Initialize the LEDPWM clock and period.
 * @param  ClkSrc: Clock source selection.
 * @param  PeriodVal: Value for LEDPWM period register (PWMPD[7:0]).
 * @retval None
 */
void LEDPWM_Init(LEDPWM_ClockSource_Typedef ClkSrc, uint8_t PeriodVal)
{
  /* Set clock source */
  LEDPWMCON = (LEDPWMCON & 0xF0) | (uint8_t)ClkSrc;
  /* Set period */
  LEDPWMPD = PeriodVal-1;
}

/**
 * @brief  Configure LEDPWM channel output enable.
 * @param  ChannelMask: Bit mask for channels 0~15.
 * @param  NewState: ENABLE or DISABLE.
 * @retval None
 */
void LEDPWM_ChannelConfig(uint16_t ChannelMask, FunctionalState NewState)
{
  if (NewState == ENABLE)
  {
    if (ChannelMask & 0xFF)
      LEDPWMEN0 |= (ChannelMask & 0xFF);
    if (ChannelMask & 0xFF00)
      LEDPWMEN1 |= ((ChannelMask >> 8) & 0xFF);
  }
  else
  {
    if (ChannelMask & 0xFF)
      LEDPWMEN0 &= ~(ChannelMask & 0xFF);
    if (ChannelMask & 0xFF00)
      LEDPWMEN1 &= ~((ChannelMask >> 8) & 0xFF);
  }
}

/**
 * @brief  Configure LEDPWM waveform inversion.
 * @param  ChannelMask: Bit mask for channels 0~15.
 * @param  NewState: ENABLE to invert, DISABLE to normal.
 * @retval None
 */
void LEDPWM_InvertConfig(uint16_t ChannelMask, FunctionalState NewState)
{
  if (NewState == ENABLE)
  {
    if (ChannelMask & 0xFF)
      LEDPWMCFG0 |= (ChannelMask & 0xFF);
    if (ChannelMask & 0xFF00)
      LEDPWMCFG1 |= ((ChannelMask >> 8) & 0xFF);
  }
  else
  {
    if (ChannelMask & 0xFF)
      LEDPWMCFG0 &= ~(ChannelMask & 0xFF);
    if (ChannelMask & 0xFF00)
      LEDPWMCFG1 &= ~((ChannelMask >> 8) & 0xFF);
  }
}

/**
 * @brief  Set the LEDPWM output period.
 * @param  period  Period count value (range 1~256). 
 *                 Actual output period = period ¡Á LEDPWM clock period.
 * @note   This function writes directly to the LEDPWMPD register (address 1015H).
 *         According to the datasheet, PWMPD[7:0] holds (period - 1); therefore,
 *         setting PWMPD = N results in a period of N clocks.
 *         Before changing the period, it is recommended to disable PWM output 
 *         (ENPWM = 0) and then re-enable after configuration.
 */
void LEDPWM_SetPeriod(uint8_t period)
{
   LEDPWMPD = period-1;  /* Write period value to LEDPWM Period Register */
}

/**
 * @brief  Set duty cycle for a specific channel.
 * @param  Channel: Channel number (0~15).
 * @param  DutyVal: Duty value (1~256), high level width = DutyVal*LEDPWMÊ±ÖÓ.
 * @retval None
 */
void LEDPWM_SetDuty(LEDPWM_Channel_TypeDef Channel, uint8_t DutyVal)
{
  uint8_t *pPDT;
  pPDT = (uint8_t *)(0x1000 + Channel); /* PDT0~PDT15 address range */
  *pPDT = DutyVal-1;
}

/**
 * @brief  Enable or disable LEDPWM module.
 * @param  NewState: ENABLE or DISABLE.
 * @retval None
 */
void LEDPWM_Cmd(FunctionalState NewState)
{
  if (NewState != DISABLE)
		LEDPWMCON |= 0x80;
  else
    LEDPWMCON &= 0x7F;
}

/** @defgroup LEDPWM_Group2 Interrupts and flags management functions
 *  @brief   Interrupts and flags management functions
 *
@verbatim
 ===============================================================================
            ##### Interrupts and flags management functions #####
 ===============================================================================
@endverbatim
 * @{
 */

/**
 * @brief  Configure LEDPWM interrupt.
 * @param  NewState: ENABLE or DISABLE.
 * @param  Priority: LOW or HIGH.
 * @retval None
 */
void LEDPWM_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
  if (NewState != DISABLE)
		IE2 |= 0x40;
  else
    IE2 &= 0xBF;

  if (Priority != LOW)
		IP2 |= 0x40;
  else
    IP2 &= 0xBF;
}

/**
 * @brief  Get LEDPWM flag status.
 * @param  None
 * @retval FlagStatus: SET or RESET.
 */
FlagStatus LEDPWM_GetFlagStatus(void)
{
  return (FlagStatus)(LEDPWMCON & 0X40);
}

/**
 * @brief  Clear LEDPWM interrupt flag.
 * @param  None
 * @retval None
 */
void LEDPWM_ClearFlag(void)
{
  LEDPWMCON &= (uint8_t)(~0X40);
}

#endif

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