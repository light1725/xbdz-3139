/**
 ******************************************************************************
 * @file    sc92f_pwr.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   PWR function module
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
#include "sc92f_pwr.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
/** @defgroup PWR
 * @brief PWR driver modules
 * @{
 */

/** @defgroup PWR_Functions
 * @{
 */
 
/** @defgroup PWR_Group1 Initialization and Configuration functions
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
 * @brief  PWR相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void PWR_DeInit(void)
{
  PCON &= 0XFC;
}

#if defined(SC92L840x)
#include "STOP_Option_EW.h"
/**
 * @brief  MCU进入STOP模式
 * @param  None
 * @retval None
 */ 
void PWR_EnterSTOPMode(void)
{
  EnterSTOPMode();
}

/**
 * @brief  MCU进入IDLE模式
 * @param  None
 * @retval None
 */ 
void PWR_EnterIDLEMode(void)
{
   EnterIDLEMode();
}

#else

  


/**
 * @}
 */
/* End of PWR_Group1.	*/

/** @defgroup PWR_Group2 Base functions
 *  @brief   Interrupts management functions
 *
@verbatim
 ===============================================================================
                     ##### Base functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  MCU进入STOP模式
 * @param  None
 * @retval None
 */ 
void PWR_EnterSTOPMode(void)
{
  PCON |= 0X02;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
}

/**
 * @brief  MCU进入IDLE模式
 * @param  None
 * @retval None
 */ 
void PWR_EnterIDLEMode(void)
{
  PCON |= 0X01;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
}
#endif
#if defined(SC92F848x) || defined(SC92F748x)|| defined(SC92F859x) || defined(SC92F759x) || defined(SC92L853x) || defined(SC92L753x) || defined(SC92R511x)\
  || defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F6x1x)|| defined(SC92F5x1x)\
  || defined(SC92R436)|| defined(SC92R438)|| defined(SC92L840x)|| defined(SC92R439)|| defined(SC92R422A)|| defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)|| defined(SC92F5x5x)\
	|| defined(SC92F531x)|| defined(SC92F637x)|| defined(SC92F663x) || defined(SC92F563x)
/**
 * @brief  MCU进入软件复位
 * @param  None
 * @retval None
 */ 
void PWR_SoftwareReset(void)
{
	PCON |= 0X08;	//软件复位
	_nop_();		
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
  _nop_();
  _nop_();
	_nop_();
}
#endif

/**
 * @}
 */
/* End of PWR_Group2.	*/

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