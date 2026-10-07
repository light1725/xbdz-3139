/**
 ******************************************************************************
 * @file    sc92f_acmp.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   ACMP function module
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
#include "sc92f_acmp.h"

#if defined (SC92F854x) || defined (SC92F754x) ||defined  (SC92F844xB) || defined (SC92F744xB) || defined  (SC92F84Ax_2) || defined (SC92F74Ax_2)\
		|| defined (SC92FWxx) || defined(SC92F859x) || defined(SC92F759x) || defined (SC92R511x) || defined (SC92F563x) 
/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup ACMP
 * @brief ACMP driver modules
 * @{
 */

/** @defgroup ACMP_Functions
 * @{
 */

/** @defgroup ACMP_Group1 Configuration of the aCMP computation unit functions
 *  @brief   Configuration of the ACMP computation unit functions
 *
 
@verbatim
 ===============================================================================
                     ##### ACMP configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */
  
 /**
 * @brief  DeInitialize the ACMP peripheral registers to their default reset values.
 * @param  None
 * @retval None
 */
void ACMP_DeInit(void)
{
  CMPCON = 0X00;
  CMPCFG = 0X00;
}

/**
 * @brief  Initializes the peripheral ACMP register.
 * @param  ACMP_Vref[in]: Select the reference voltage for the ACMP peripheral.
 *                  - ACMP_VREF_EXTERNAL: Select CMPR port for ACMP reference voltage.
 *                  - ACMP_VREF_1D16VDD: Select 1/16 VDD as the comparison voltage for ACMP.
 *                  - ACMP_VREF_2D16VDD: Select 2/16 VDD as the comparison voltage for ACMP.
 *                  - ACMP_VREF_3D16VDD: Select 3/16 VDD as the comparison voltage for ACMP.
 *                  - ACMP_VREF_4D16VDD: Select 4/16 VDD as the comparison voltage for ACMP.
 *                  - ACMP_VREF_5D16VDD: Select 5/16 VDD as the comparison voltage for ACMP.
 *                  - ACMP_VREF_6D16VDD: Select 6/16 VDD as the comparison voltage for ACMP.
 *                  - ACMP_VREF_7D16VDD: Select 7/16 VDD as the comparison voltage for ACMP.
 *                  - ACMP_VREF_8D16VDD: Select 8/16 VDD as the comparison voltage for ACMP.
 *                  - ACMP_VREF_9D16VDD: Select 9/16 VDD as the comparison voltage for ACMP.
 *                  - ACMP_VREF_10D16VDD: Select 10/16 VDD as the comparison voltage for ACMP.
 *                  - ACMP_VREF_11D16VDD: Select 11/16 VDD as the comparison voltage for ACMP.
 *                  - ACMP_VREF_12D16VDD: Select 12/16 VDD as the comparison voltage for ACMP.
 *                  - ACMP_VREF_13D16VDD: Select 13/16 VDD as the comparison voltage for ACMP.
 *                  - ACMP_VREF_14D16VDD: Select 14/16 VDD as the comparison voltage for ACMP.
 *                  - ACMP_VREF_15D16VDD: Select 15/16 VDD as the comparison voltage for ACMP.
 * @param  ACMP_Channel[in]:ACMP Input Channel Selection.
 *                  - ACMP_CHANNEL_0: Select CMP0 as the ACMP input
 *                  - ACMP_CHANNEL_1: Select CMP1 as the ACMP input
 *                  - ACMP_CHANNEL_2: Select CMP2 as the ACMP input
 *                  - ACMP_CHANNEL_3: Select CMP3 as the ACMP input
 *          If SC92F859x,SC92F759x and SC92R511x models are chosen, you can also choose from the following options
 *                  - ACMP_CHANNEL_P: Select CMPP as the ACMP input, with CMPP set to a baseline voltage of 1.5V
 * @retval None
 */
void ACMP_Init(ACMP_Vref_Typedef ACMP_Vref,
               ACMP_Channel_TypeDef ACMP_Channel)
{
  /*Comparator Reverse Terminal Voltage Selection*/
  CMPCON = CMPCON & 0XF0 | ACMP_Vref;
  /*Comparator in-phase terminal input channel selection*/
  CMPCFG = CMPCFG & 0XEC | ACMP_Channel;
}

 /**
 * @brief  Configure ACMP peripheral interrupt trigger mode..
 * @param  ACMP_TriggerMode[in]: Select Terminal Trigger mode.
 *                  - ACMP_TRIGGER_NO: No interruptions.
 *                  - ACMP_TRIGGER_RISE_ONLY: Select simulation comparator trigger mode as rising edge.
 *                  - ACMP_TRIGGER_FALL_ONLY: Select simulation comparator trigger mode as falling edge.
 *                  - ACMP_TRIGGER_RISE_FALL: Select simulation comparator trigger mode as rising edge and falling edge.
 * @retval None
 */
void ACMP_SetTriggerMode(ACMP_TriggerMode_Typedef
                         ACMP_TriggerMode)
{
  CMPCFG = CMPCFG & 0XF3 | ACMP_TriggerMode;
}

/**
 * @brief  Enables or disables the specified ACMP.
 * @param  NewState[in]: new state of the ACMP peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable   
 * @retval None
 */
void ACMP_Cmd(FunctionalState NewState)
{
  if(NewState == DISABLE)
  {
    /* Enable the ACMP Function */
    CMPCON &= 0X7F;
  }
  else
  {
    /* Disable the ACMP Function */
    CMPCON |= 0x80;
  }
}

/** @defgroup ACMP_Group2 Interrupts and flags management functions
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
 * @brief  Configure ACMP interrupt.
 * @param  NewState[in]: new state of the ACMP peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable  
 * @param  Priority[in]: Interrupt priority.
 *                  - LOW:Low priority.
 *                  - HIGH:High priority.
 * @retval None
 */
void ACMP_ITConfig(FunctionalState NewState,
                   PriorityStatus Priority)
{
  if(NewState == DISABLE)
  {
    IE1 &= 0XDF;
  }
  else
  {
    IE1 |= 0X20;
  }

  /************************************************************/
  if(Priority == LOW)
  {
    IP1 &= 0XDF;
  }
  else
  {
    IP1 |= 0X20;
  }
}

/**
 * @brief  Return the ACMP state (RESET or SET) of the selected comparator. 
 * @param  ACMP_Flag[in]: 
 *                  - ACMP_FLAG_CMPIF:  Check if the AMCP interrupt has been triggered.
 *                  - ACMP_FLAG_CMPSTA: ACMP output status.
 * @retval The new state of ACMP.
 *                  - RESET:state reset
 *                  - SET:state set
 */
FlagStatus ACMP_GetFlagStatus(ACMP_Flag_TypeDef
                              ACMP_Flag)
{
  return (bool)(CMPCON & ACMP_Flag);
}

/**
 * @brief  Clears the ACMP's pending flags.
 * @param  None
 * @retval None
 */
void ACMP_ClearFlag(void)
{
  CMPCON &= (~ACMP_FLAG_CMPIF);
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