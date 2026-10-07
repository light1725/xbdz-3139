/**
 ******************************************************************************
 * @file    putchar.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Rewrite the function when using the printf interface
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
#include "putchar.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
/** @defgroup putchar
 * @brief putchar driver modules
 * @{
 */

/** @defgroup putchar_Functions
 * @{
 */
 
   /** @defgroup putchar_Group1 Initialization and Configuration functions
 *  @brief Initialization and Configuration functions
 *
 
@verbatim
 ====================================================================================================
                     ##### putchar Configuration functions #####
 ====================================================================================================
@endverbatim
  * @{
  */
	


#if defined (SSIPENABLE) || defined(SSI0PENABLE) || defined(SSI1PENABLE) || defined(UART0PENABLE) || defined(UART2PENABLE) || defined(USCI0PENABLE)\
|| defined(USCI1PENABLE) || defined(USCI2PENABLE) || defined(UART3PENABLE)

char putchar(char c)
{
   uint16_t i = 0;
   Printf_SendData8(c);
   while(!Printf_GetTxStatus)
   {
		 
		 
			if(20000<i++)
			{
				break;
			}
   }
	 
   Printf_ClearTxFlag;
   return c;
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