/**
 ******************************************************************************
 * @file    sc92f_CRC.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   CRC function module
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
#include "sc92f_crc.h"
#include "intrins.H"

#if defined(SC92F6x1x)  || defined(SC92R436) || defined(SC92R438)||defined(SC92L840x) || defined(SC92R439)\
    || defined(SC92R422A) || defined(SC92F652x) || defined(SC92R51x_R52x) || defined(SC92F552x) || defined(SC92F663x)\
		|| defined(SC92F563x)

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup CRC
 * @brief CRC driver modules
 * @{
 */

/** @defgroup CRC_Functions
 * @{
 */

/** @defgroup CRC_Group1 Data calculation functions
 *  @brief   Data calculation functions
 *
 
@verbatim
 ===============================================================================
                     ##### Data calculation functions #####
 ===============================================================================
@endverbatim
  * @{
  */
#if !defined(SC92L840x)
/**
  * @brief  To calculate the CRC32 checksum of the project HEX file,the result will vary based on the IAR Range option.
  * @param  None
  * @retval 32-bit CRC
  */
uint32_t CRC_All()
{
 return CRC_CodeAllOption();
}
#endif
/**
  * @brief  Calculate the CRC check value of the input frame.
  * @param  buff:Input the array that needs to be computed for CRC.
  * @param  Length:Length of the array to be calculated.
  * @retval CRC_Result:32-bit CRC.
  */
uint32_t CRC_Frame(uint8_t* buff, uint8_t Length)
{
	uint8_t i;
  uint32_t CRC_Input ,CRC_Result;
	
	CRC_ResetDROption();
  for(i = 0; i < Length; i++)
  {
    CRC_Input = *(buff + i);
		CRC_CalcOption(CRC_Input);
  }
  CRC_Result = CRC_GetOption();
  return CRC_Result;
}

#elif  defined (SC92L853x) || defined (SC92L753x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) 
/**
  * @brief  To calculate the CRC32 checksum of the project HEX file,the result will vary based on the IAR Range option.
  * @param  None
  * @retval 32-bit CRC
  */
uint32_t CRC_All()
{
  uint32_t CRC_Result;
  OPERCON |= 0x01;
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
  CRCINX = 0x00;
  CRC_Result = CRCREG;
  CRC_Result = CRCREG * 256 + CRC_Result;
  CRC_Result = CRCREG * 65536 + CRC_Result;
  CRC_Result = CRCREG * 16777216 + CRC_Result;
  return CRC_Result;
}

/**
  * @brief  Calculate the CRC check value of the input frame.
  * @param  buff:Input the array that needs to be computed for CRC.
  * @param  Length:Length of the array to be calculated.
  * @retval CRC_Result:32-bit CRC.
  */
uint32_t CRC_Frame(uint8_t *buff, uint8_t Length)
{
  uint8_t i;
  uint32_t CRC_Result = 0;
  
  EA = 0;
  OPERCON |= 0x02;
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

  for (i = 0; i < Length; i++)
  {
    CRC_Result = *(buff + i);
    CRCREG = CRC_Result;
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

  CRCINX = 0x00;
  CRC_Result = CRCREG;
  CRC_Result = CRCREG * 256 + CRC_Result;
  CRC_Result = CRCREG * 65536 + CRC_Result;
  CRC_Result = CRCREG * 16777216 + CRC_Result;
  EA = 1;

  return CRC_Result;
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