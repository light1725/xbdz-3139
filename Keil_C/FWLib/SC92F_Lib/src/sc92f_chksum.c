/**
 ******************************************************************************
 * @file    sc92f_chksum.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   CHKSUM function module
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
#include "sc92f_chksum.h"

#if defined(SC92F7003) || defined(SC92F8003) || defined(SC92F8003B) || defined(SC92F736xB) || defined(SC92F836xB) || defined(SC92F740x) || defined(SC92F742x)\
		|| defined(SC92F73Ax) || defined(SC92F83Ax) || defined(SC92F744xB) || defined(SC92F844xB) || defined(SC92F746xB) || defined(SC92F846xB)\
		|| defined(SC92F748x) || defined(SC92F848x) || defined(SC92F74Ax) || defined(SC92F84Ax) || defined(SC92F74Ax_2) || defined(SC92F84Ax_2)\
		|| defined(SC92F754x)	|| defined (SC92F854x) || defined (SC92F759x) || defined(SC92F859x) || defined (SC92F7490) || defined(SC92FWxx)\
		|| defined(SC92F827X) || defined(SC92F837X) || defined(SC92F847X) || defined (SC92R511x) || defined (SC92R342) || defined(SC92F84Hx) || defined(SC92F83Hx)\
    || defined(SC92F5x5x) || defined(SC92F531x) || defined(SC92F637x)
/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup CHKSUM
 * @brief CHKSUM driver modules
 * @{
 */

/** @defgroup CHKSUM_Exported_Functions
 * @{
 */

/** @defgroup CHKSUM_Exported_Functions_Group1 Configuration of the CHKSUM computation unit functions
 *  @brief   Configuration of the CHKSUM computation unit functions
 *
 
@verbatim
 ===============================================================================
                     ##### CHKSUM base functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitializes the CHKSUM peripheral
 * @param  None         
 * @retval None
 */
void CHKSUM_DeInit(void)
{
  OPERCON &= 0XFE;
  CHKSUML = 0X00;
  CHKSUMH = 0X00;
}

/**
 * @brief  Trigger CHKSUM calculation
 * @param  None         
 * @retval None
 */
void CHKSUM_StartOperation(void)
{
  OPERCON |= 0X01;

  while(OPERCON & 0x01);
}

/**
 * @brief  retrieve the checksum value
 * @param  None         
* @retval checktemp:checksum value
 */
uint16_t CHKSUM_GetCheckValue(void)
{
  uint16_t checktemp;
  checktemp = (uint16_t)(CHKSUMH << 8) +
              (uint16_t)CHKSUML;
  return checktemp;
}
/**
 * @}
 */
/* End of CHKSUM_Group1.	*/
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