/**
 ******************************************************************************
 * @file    sc92f_int.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   INT function module
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
#include "sc92f_int.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
/** @defgroup INT
 * @brief INT driver modules
 * @{
 */

 /** @defgroup INT_Functions
 * @{
 */

 /** @defgroup INT_Group1 Initialization and Configuration functions
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
 * @brief The INTx related register is reset to the default value
 * @param  INTx[in]: INTx Selection
 *              SC92F827X,SC92F837X,SC92F730x,SC92F725X,SC92F735X,SC92F7490,SC92F730x_2,SC92F720x,SC92F7308B
 *              Selection range (INT0,INT2)
 *              SC92F84Hx,SC92F83Hx,SC92F6x1x,SC92F5x1x,SC92R436,SC92R439,SC92R422A,SC92F652x,SC92F531x,SC92F637x,SC92F663x,
 *              SC92F563x
 *              Selection range(INT0,INT1)
 *              else Selection range(INT0~INT2)
 *              - INT0:External interrupt 0
 *              - INT1:External interrupt 1
 *              - INT2:External interrupt 2
 * @retval None
 */ 
#if defined (SC92F827X) || defined (SC92F837X) || defined (SC92F730x) || defined (SC92F725X) || defined (SC92F735X)\
|| defined (SC92F7490) || defined(SC92F730x_2) || defined(SC92F720x)|| defined (SC92F7308B)
void INT_DeInit(INTx_Typedef INTx)
{
  switch(INTx)
  {
    case INT0:
      INT0R = 0x00;
      INT0F = 0x00;
      IE &= (~0X01);
      IP &= ~0X01;
      TCON &= (~0X02);
      break;

    case INT2:
      INT2R = 0x00;
      INT2F = 0x00;
      IE1 &= (~0X08);
      IP1 &= ~0X08;
      break;

    default:
      break;
  }
}
#elif defined(SC92F84Hx) || defined(SC92F83Hx)  || defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)|| defined(SC92R438)\
   || defined(SC92R439)|| defined(SC92R422A)|| defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)|| defined(SC92F5x5x)|| defined(SC92F531x)\
	 || defined(SC92F637x)|| defined(SC92F663x)|| defined(SC92F563x)

void INT_DeInit(INTx_Typedef INTx)
{
  switch(INTx)
  {
    case INT0:
      INT0R = 0x00;
      INT0F = 0x00;
      IE &= (~0X01);
      IP &= ~0X01;
      TCON &= (~0X02);
      break;

    case INT1:
      INT1R = 0x00;
      INT1F = 0x00;
      IE &= (~0X04);
      IP &= ~0X04;
      TCON &= (~0X08);
      break;
		
    default:
      break;
  }
}
#else
void INT_DeInit(INTx_Typedef INTx)
{
  switch(INTx)
  {
    case INT0:
      INT0R = 0x00;
      INT0F = 0x00;
      IE &= (~0X01);
      IP &= ~0X01;
      TCON &= (~0X02);
      break;

    case INT1:
      INT1R = 0x00;
      INT1F = 0x00;
      IE &= (~0X04);
      IP &= ~0X04;
      TCON &= (~0X08);
      break;

    case INT2:
      INT2R = 0x00;
      INT2F = 0x00;
      IE1 &= (~0X08);
      IP1 &= ~0X08;
      break;

    default:
      break;
  }
}
#endif

/**
 * @brief  INT0x Interrupt trigger configuration function
 * @param  INT0x[in]: INT0x Select
 * @param  TriggerMode[in]: 
 *              - INT_TRIGGER_RISE_ONLY:The external interrupt triggering mode is ascending edge
 *              - INT_TRIGGER_FALL_ONLY:The external interrupt triggering mode is falling edge
 *              - INT_TRIGGER_RISE_FALL:The external interrupt triggering modes are rising edge and falling edge
 *              - INT_TRIGGER_DISABLE:Disable external interrupt triggering
 * @retval None
 */ 
void INT0_SetTriggerMode(uint8_t INT0x,
                         INT_TriggerMode_Typedef TriggerMode)
{
  switch(TriggerMode)
  {
    case INT_TRIGGER_RISE_ONLY:
      INT0R |= INT0x;
      INT0F &= (~INT0x);
      break;

    case INT_TRIGGER_FALL_ONLY:
      INT0R &= (~INT0x);
      INT0F |= INT0x;
      break;

    case INT_TRIGGER_RISE_FALL:
      INT0R |= INT0x;
      INT0F |= INT0x;
      break;

    case INT_TRIGGER_DISABLE:
      INT0R &= (~INT0x);
      INT0F &= (~INT0x);

    default:
      break;
  }
}

/**
 * @brief  INT1x Configures the interrupt triggering mode
 * @param  INT1x[in]: INT1x selection
 * @param  TriggerMode[in]: 
 *              - INT_TRIGGER_RISE_ONLY:The external interrupt triggering mode is ascending edge
 *              - INT_TRIGGER_FALL_ONLY:The external interrupt triggering mode is falling edge
 *              - INT_TRIGGER_RISE_FALL:The external interrupt triggering modes are rising edge and falling edge
 *              - INT_TRIGGER_DISABLE:Disable external interrupt triggering
 * @retval None
 */ 
#if !defined (SC92F827X) && !defined (SC92F837X) && !defined (SC92F730x) && !defined (SC92F725X) && !defined (SC92F735X) && !defined (SC92F7490) && !defined(SC92F730x_2)\
   && !defined(SC92F720x) && !defined (SC92F7308B)
void INT1_SetTriggerMode(uint8_t INT1x,
                         INT_TriggerMode_Typedef TriggerMode)
{
  switch(TriggerMode)
  {
    case INT_TRIGGER_RISE_ONLY:
      INT1R |= INT1x;
      INT1F &= (~INT1x);
      break;

    case INT_TRIGGER_FALL_ONLY:
      INT1R &= (~INT1x);
      INT1F |= INT1x;
      break;

    case INT_TRIGGER_RISE_FALL:
      INT1R |= INT1x;
      INT1F |= INT1x;
      break;

    case INT_TRIGGER_DISABLE:
      INT1R &= (~INT1x);
      INT1F &= (~INT1x);

    default:
      break;
  }
}
#endif

/**
 * @brief INT2x Configures the interrupt triggering mode
 * @param  INT2x[in]:  INT1x selection
 * @param  TriggerMode[in]: 
 *              - INT_TRIGGER_RISE_ONLY:The external interrupt triggering mode is ascending edge
 *              - INT_TRIGGER_FALL_ONLY:The external interrupt triggering mode is falling edge
 *              - INT_TRIGGER_RISE_FALL:The external interrupt triggering modes are rising edge and falling edge
 *              - INT_TRIGGER_DISABLE:Disable external interrupt triggering

 * @retval None
 */ 
#if !defined(SC92F84Hx) && !defined(SC92F83Hx)&& !defined(SC92F6x1x) && !defined(SC92F5x1x) && !defined(SC92R436)&& !defined(SC92R438)\
   && !defined(SC92R439) && !defined(SC92R422A)&& !defined(SC92F652x)&& !defined(SC92R51x_R52x) && !defined(SC92F552x)&& !defined(SC92F5x5x)&& !defined(SC92F531x)\
	 && !defined(SC92F637x) && !defined(SC92F663x) && !defined(SC92F563x)
void INT2_SetTriggerMode(uint8_t INT2x,
                         INT_TriggerMode_Typedef TriggerMode)
{
  switch(TriggerMode)
  {
    case INT_TRIGGER_RISE_ONLY:
      INT2R |= INT2x;
      INT2F &= (~INT2x);
      break;

    case INT_TRIGGER_FALL_ONLY:
      INT2R &= (~INT2x);
      INT2F |= INT2x;
      break;

    case INT_TRIGGER_RISE_FALL:
      INT2R |= INT2x;
      INT2F |= INT2x;
      break;

    case INT_TRIGGER_DISABLE:
      INT2R &= (~INT2x);
      INT2F &= (~INT2x);

    default:
      break;
  }
}
#endif

/**
 * @brief INT0 interrupts initialization
 * @param  NewState[in]: Disable Enable/Disable selection
 *              - DISABLE:Off
 *              - ENABLE:enable
 * @param  Priority[in]: Interrupt priority selection
 *              - LOW:low
 *              - HIGH:high
 * @retval None
 */ 
void INT0_ITConfig(FunctionalState NewState,
                   PriorityStatus Priority)
{
  if(NewState != DISABLE)
  {
    IE |= 0X01;
  }
  else
  {
    IE &= (~0X01);
  }

  if(Priority == LOW)
  {
    IP &= ~0X01;
  }
  else
  {
    IP |= 0X01;
  }
}



/**
* @brief INT1 Interrupt initialization
* @param NewState[in]: disables the enable/disable selection
*                -DISABLE: disables the function
*                -ENABLE: enables the function
* @param Priority[in]: indicates the interrupt priority
*                -LOW: indicates the low value
*                - HIGH: High
* @retval None
*/

#if !defined (SC92F827X) && !defined (SC92F837X) && !defined (SC92F730x) && !defined (SC92F725X) && !defined (SC92F735X) && !defined (SC92F7490)\
&& !defined(SC92F730x_2) && !defined(SC92F720x) && !defined (SC92F7308B)
void INT1_ITConfig(FunctionalState NewState,
                   PriorityStatus Priority)
{
  if(NewState != DISABLE)
  {
    IE |= 0X04;
  }
  else
  {
    IE &= (~0X04);
  }

  if(Priority == LOW)
  {
    IP &= ~0X04;
  }
  else
  {
    IP |= 0X04;
  }
}
#endif
/**
* @brief INT2 Interrupt initialization
* @param NewState[in]: disables the enable/disable selection
*                 -DISABLE: disables the function
*                 -ENABLE: enables the function
* @param Priority[in]: indicates the interrupt priority
*                 -LOW: indicates the low value
*                 - HIGH: High
* @retval None
*/

#if !defined(SC92F84Hx) && !defined(SC92F83Hx) &&!defined(SC92F6x1x) && !defined(SC92F5x1x) && !defined(SC92R436)&& !defined(SC92R438)\
    && !defined(SC92R439)&& !defined(SC92R422A)&& !defined(SC92F652x)&& !defined(SC92R51x_R52x) && !defined(SC92F552x)&& !defined(SC92F5x5x)&& !defined(SC92F531x)\
		&& !defined(SC92F637x) && !defined(SC92F663x) && !defined(SC92F563x)
void INT2_ITConfig(FunctionalState NewState,
                   PriorityStatus Priority)
{
  if(NewState != DISABLE)
  {
    IE1 |= 0X08;
  }
  else
  {
    IE1 &= (~0X08);
  }

  if(Priority == LOW)
  {
    IP1 &= ~0X08;
  }
  else
  {
    IP1 |= 0X08;
  }
}
#endif

/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/

