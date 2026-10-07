/**
 ******************************************************************************
 * @file    sc92f_mdu.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   mdu function module
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
#include "sc92f_mdu.h"

#if defined (SC92F854x) || defined (SC92F754x) || defined  (SC92F844xB) || defined (SC92F744xB) || defined  (SC92F84Ax_2) || defined (SC92F74Ax_2)\
  || defined (SC92F74Ax) || defined (SC92F84Ax) || defined (SC92F73Ax) || defined (SC92F83Ax) || defined(SC92FWxx)\
	|| defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB) || defined (SC92F848x) || defined (SC92F748x)\
	|| defined (SC92F859x) || defined (SC92F759x) || defined (SC92L853x) || defined (SC92L753x) || defined (SC92R511x) || defined (SC92R342)\
	|| defined (SC92F841x) || defined (SC92F741x) || defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)\
	|| defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436) || defined(SC92R438)|| defined(SC92L840x)|| defined(SC92R439) || defined (SC92Fx41xB)\
	||defined(SC92R445) ||defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)||defined(SC92F531x)||defined(SC92F663x)||defined(SC92F563x)
/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup mdu
 * @brief mdu driver modules
 * @{
 */

/** @defgroup mdu_Exported_Functions
 * @{
 */

/** @defgroup mdu_Exported_Functions_Group1 Configuration of the mdu computation unit functions
 *  @brief   Configuration of the mdu computation unit functions
 *
 
@verbatim
 ===============================================================================
                     ##### mdu base functions #####
 ===============================================================================
@endverbatim
  * @{
  */
  
/**
 * @brief  DeInitializes the mdu peripheral
 * @param  None         
 * @retval None
 */
void MDU_DeInit(void)
{
  OPERCON &= 0X3F;
  EXA0 = 0X00;
  EXA1 = 0X00;
  EXA2 = 0X00;
  EXA3 = 0X00;
  EXBL = 0X00;
  EXBH = 0X00;
}

/**
 * @brief  Configure MDU multiplication operation register.
 * @param  Multiplicand:  Multiplicand of MDU
 * @param  Multiplier:  Multiplier of MDU
 * @retval None
 */
void MDU_MultiplicationConfig(uint16_t
                              Multiplicand, uint16_t Multiplier)
{
  OPERCON &= 0XBF;
  EXBL = Multiplier ;
  EXBH = Multiplier >> 8;
  EXA0 = Multiplicand ;
  EXA1 = Multiplicand >> 8;
}

/**
 * @brief  Configure MDU division operation register.
 * @param  Dividend:  Dividend of MDU.
 * @param  Divisor:  Divisor of MDU.
 * @retval None
 */
void MDU_DivisionConfig(uint32_t Dividend,
                        uint16_t Divisor)
{
  MDU_Temp_Union MDU_DivisionTemp;
  MDU_DivisionTemp.MDU_Temp = Dividend;
  OPERCON |= 0X40;
  EXA0 = MDU_DivisionTemp.MDU_EXAxReg.MDU_EXA0Reg;
  EXA1 = MDU_DivisionTemp.MDU_EXAxReg.MDU_EXA1Reg;
  EXA2 = MDU_DivisionTemp.MDU_EXAxReg.MDU_EXA2Reg;
  EXA3 = MDU_DivisionTemp.MDU_EXAxReg.MDU_EXA3Reg;
  EXBL = Divisor;
  EXBH = Divisor >> 8;
}

/**
 * @brief  Initiate one MDU operation.
 * @param  None
 * @retval None
 */
void MDU_StartOperation(void)
{
  OPERCON |= 0x80;

  while(OPERCON & 0x80);
}

/**
 * @brief  Obtain the product after MDU operation.
 * @param  None
 * @retval MDU_Product: product value
 */
uint32_t MDU_GetProduct(void)
{
  MDU_Temp_Union MDU_ProductTemp;
  MDU_ProductTemp.MDU_EXAxReg.MDU_EXA0Reg = EXA0;
  MDU_ProductTemp.MDU_EXAxReg.MDU_EXA1Reg = EXA1;
  MDU_ProductTemp.MDU_EXAxReg.MDU_EXA2Reg = EXA2;
  MDU_ProductTemp.MDU_EXAxReg.MDU_EXA3Reg = EXA3;
  return MDU_ProductTemp.MDU_Temp;
}

/**
 * @brief  Obtain the quotient after MDU operation.
 * @param  None
 * @retval MDU_Quotient: Quotient value
 */
uint32_t MDU_GetQuotient(void)
{
  MDU_Temp_Union MDU_QuotientTemp;
  MDU_QuotientTemp.MDU_EXAxReg.MDU_EXA0Reg = EXA0;
  MDU_QuotientTemp.MDU_EXAxReg.MDU_EXA1Reg = EXA1;
  MDU_QuotientTemp.MDU_EXAxReg.MDU_EXA2Reg = EXA2;
  MDU_QuotientTemp.MDU_EXAxReg.MDU_EXA3Reg = EXA3;
  return MDU_QuotientTemp.MDU_Temp;
}

/**
 * @brief  Obtain the remainder after MDU operation.
 * @param  None
 * @retval MDU_Remainder: Remainde value.
 */
uint16_t MDU_GetRemainder(void)
{
  uint16_t MDU_RemainderTemp;
  MDU_RemainderTemp = EXBH * 256 + EXBL;
  return MDU_RemainderTemp;
}
/**
 * @}
 */
/* End of MDU_Group1.	*/
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