/**
 ******************************************************************************
 * @file    sc92F_CRC.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of CRC module.
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
#ifndef _sc92f_CRC_H_
#define _sc92f_CRC_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"
#if defined(SC92F6x1x)  || defined(SC92R436) || defined(SC92R438)||defined(SC92L840x) || defined(SC92R439)\
    || defined(SC92R422A) || defined(SC92F652x) || defined(SC92R51x_R52x) || defined(SC92F552x) || defined(SC92F663x)\
		|| defined(SC92F563x)
/* CRC firmware library function header file */
#include "CRC_Option_EW.h"
#endif

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @addtogroup CRC
 * @{
 */
 
/** @addtogroup CRC_Exported_Functions CRC Exported Functions
 * @{
 */
#if defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436) || defined(SC92R438)||defined(SC92L840x) || defined(SC92R439)\
    || defined(SC92R422A) || defined(SC92F652x) || defined(SC92R51x_R52x) || defined(SC92F552x) || defined(SC92F663x)\
		|| defined(SC92F563x)
#if !defined(SC92L840x)
uint32_t CRC_All(void);
#endif
uint32_t CRC_Frame(uint8_t* buff, uint8_t Length);

#elif defined (SC92L853x) || defined (SC92L753x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)
uint32_t CRC_All(void); /*!< 根据IAP Range选项，硬件CRC运算CODE内容，返回CRC结果   */
uint32_t CRC_Frame(uint8_t *buff,
                   uint8_t Length); /*!< 软件CRC，将buff指向的数组进行CRC运算，返回CRC结果   */
#endif
/**
 * @}
 */
/* End of CRC Functions.	*/

/**
 * @}
 */

/**
 * @}
 */
#endif

/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/