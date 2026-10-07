/**
 ******************************************************************************
 * @file    sc92f_mdu.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of MDU module.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _sc92f_MDU_H_
#define	_sc92f_MDU_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @addtogroup MDU
 * @{
 */
 
 /** @defgroup MDU_Struct MDU Struct
 * @{
 */
#if defined (SC92F854x) || defined (SC92F754x) || defined  (SC92F844xB) || defined (SC92F744xB) || defined  (SC92F84Ax_2) || defined (SC92F74Ax_2)\
  || defined (SC92F74Ax) || defined (SC92F84Ax) || defined (SC92F73Ax) || defined (SC92F83Ax) || defined(SC92FWxx)\
	|| defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB) || defined (SC92F848x) || defined (SC92F748x)\
	|| defined (SC92F859x) || defined (SC92F759x) || defined (SC92L853x) || defined (SC92L753x) || defined (SC92R511x) || defined (SC92R342)\
	|| defined (SC92F841x) || defined (SC92F741x) || defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)\
  || defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)|| defined(SC92R438)|| defined(SC92L840x)|| defined(SC92R439)|| defined (SC92Fx41xB)\
	|| defined (SC92R445)||defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)||defined(SC92F531x)||defined(SC92F663x)||defined(SC92F563x)
/** @defgroup MDU_EXAxReg_Typedef MDU EXAx
 * @{
 */
typedef struct
{
  uint8_t MDU_EXA3Reg;	  /*!< EXA3 Register */
  uint8_t MDU_EXA2Reg;	  /*!< EXA2 Register */
  uint8_t MDU_EXA1Reg;	  /*!< EXA1 Register */
  uint8_t MDU_EXA0Reg;	  /*!< EXA0 Register */
} MDU_EXAxReg_Typedef;
/**
 * @}
 */

/**
 * @}
 */
/* End of Struct -----------------------------------------------------*/

typedef union
{
  MDU_EXAxReg_Typedef MDU_EXAxReg;
  uint32_t MDU_Temp;
} MDU_Temp_Union;

 /** @addtogroup MDU_Exported_Functions MDU Exported Functions
 * @{
 */
void MDU_DeInit(void);
void MDU_MultiplicationConfig(uint16_t
                              Multiplicand, uint16_t Multiplier);
void MDU_DivisionConfig(uint32_t Dividend,
                        uint16_t Divisor);
void MDU_StartOperation(void);
uint32_t MDU_GetProduct(void);
uint32_t MDU_GetQuotient(void);
uint16_t MDU_GetRemainder(void);

#endif
/**
 * @}
 */
/* End of MDU Functions.	*/

/**
 * @}
 */

/**
 * @}
 */
#endif

/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/