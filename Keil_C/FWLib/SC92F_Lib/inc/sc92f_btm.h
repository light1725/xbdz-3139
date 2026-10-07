/**
 ******************************************************************************
 * @file    sc92f_btm.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of BTM module.
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
#ifndef _sc92f_BTM_H_
#define	_sc92f_BTM_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @addtogroup BTM
 * @{
 */

/** @defgroup BTM_Enumerations BTM Enumerations
 * @{
 */
 
 /** @brief BTM_TIMEBASE BTM TIMEBASE
 * @{
 */
#if defined(SC92F748x) || defined(SC92F848x) || defined(SC92F859x) || defined(SC92F759x) || defined (SC92L853x) || defined (SC92L753x)\
		|| defined (SC92R511x) || defined (SC92F6x1x) || defined (SC92F5x1x) || defined (SC92R436)|| defined (SC92R438) || defined (SC92L840x)\
		|| defined (SC92R439) || defined (SC92R422A) || defined (SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)|| defined (SC92F5x5x)\
		|| defined (SC92F531x) || defined (SC92F637x)
typedef enum
{
  BTM_TIMEBASE_15_625MS = (uint8_t)0x00,		 /*!< Every 15.625 milliseconds generates one interrupt */
  BTM_TIMEBASE_31_25MS  = (uint8_t)0x01,		/*!< Every 31.25 milliseconds generates one interrupt */
  BTM_TIMEBASE_62_5MS   = (uint8_t)0x02,		/*!< Every 62.5 milliseconds generates one interrupt */
  BTM_TIMEBASE_125MS    = (uint8_t)0x03,		/*!< Every 125 milliseconds generates one interrupt */
  BTM_TIMEBASE_250MS    = (uint8_t)0x04,		/*!< Every 250 milliseconds generates one interrupt */
  BTM_TIMEBASE_500MS    = (uint8_t)0x05,		/*!< Every 500 milliseconds generates one interrupt */
  BTM_TIMEBASE_1S       = (uint8_t)0x06,	    /*!< Every 1 seconds generates one interrupt*/
  BTM_TIMEBASE_2S       = (uint8_t)0x07,		/*!< Every 2 seconds generates one interrupt*/
	BTM_TIMEBASE_4S       = (uint8_t)0x08,		/*!< Every 4 seconds generates one interrupt*/
	BTM_TIMEBASE_8S       = (uint8_t)0x09,		/*!< Every 8 seconds generates one interrupt*/
	BTM_TIMEBASE_16S       = (uint8_t)0x0A,		/*!< Every 16 seconds generates one interrupt*/
	BTM_TIMEBASE_32S       = (uint8_t)0x0B,		/*!< Every 32 seconds generates one interrupt*/
} BTM_Timebase_TypeDef;
#elif defined(SC92F84Hx) || defined(SC92F83Hx)
typedef enum
{
  BTM_TIMEBASE_15_625MS = (uint8_t)0x00,		/*!< Every 15.625 milliseconds generates one interrupt */
  BTM_TIMEBASE_31_25MS  = (uint8_t)0x01,		/*!< Every 31.25 milliseconds generates one interrupt */
  BTM_TIMEBASE_62_5MS   = (uint8_t)0x02,		/*!< Every 62.5 milliseconds generates one interrupt */
  BTM_TIMEBASE_125MS    = (uint8_t)0x03,		/*!< Every 125 milliseconds generates one interrupt */
  BTM_TIMEBASE_250MS    = (uint8_t)0x04,		/*!< Every 250 milliseconds generates one interrupt */
  BTM_TIMEBASE_500MS    = (uint8_t)0x05,		/*!< Every 500 milliseconds generates one interrupt */
  BTM_TIMEBASE_1S       = (uint8_t)0x06,		/*!< Every 1 seconds generates one interrupt*/
  BTM_TIMEBASE_2S       = (uint8_t)0x07,		/*!< Every 2 seconds generates one interrupt*/
  BTM_TIMEBASE_4S       = (uint8_t)0x08,			/*!< Every 4 seconds generates one interrupt*/
	BTM_TIMEBASE_8S       = (uint8_t)0x09,			/*!< Every 8 seconds generates one interrupt*/
	BTM_TIMEBASE_16S       = (uint8_t)0x0A,			/*!< Every 16 seconds generates one interrupt*/
	BTM_TIMEBASE_32S       = (uint8_t)0x0B,			/*!< Every 32 seconds generates one interrupt*/
	BTM_TIMEBASE_64S       = (uint8_t)0x0C,			/*!< Every 64 seconds generates one interrupt*/
	BTM_TIMEBASE_128S       = (uint8_t)0x0D,			/*!< Every 128 seconds generates one interrupt*/
	BTM_TIMEBASE_256S       = (uint8_t)0x0E,			/*!< Every 256 seconds generates one interrupt*/
} BTM_Timebase_TypeDef;
#elif defined (SC92F732X)
typedef enum
{
  BTM_TIMEBASE_15_625MS = (uint8_t)0x00,		/*!< Every 15.625 milliseconds generates one interrupt */
  BTM_TIMEBASE_31_25MS  = (uint8_t)0x01,		/*!< Every 31.25 milliseconds generates one interrupt */
  BTM_TIMEBASE_62_5MS   = (uint8_t)0x02,		/*!< Every 62.5 milliseconds generates one interrupt */
  BTM_TIMEBASE_125MS    = (uint8_t)0x03,		/*!< Every 125 milliseconds generates one interrupt */
  BTM_TIMEBASE_250MS    = (uint8_t)0x04,		/*!< Every 250 milliseconds generates one interrupt */
  BTM_TIMEBASE_500MS    = (uint8_t)0x05,		/*!< Every 500 milliseconds generates one interrupt */
  BTM_TIMEBASE_1S       = (uint8_t)0x06,		/*!< Every 1 seconds generates one interrupt*/
  BTM_TIMEBASE_2S       = (uint8_t)0x07,		/*!< Every 2 seconds generates one interrupt*/
} BTM_Timebase_TypeDef;
#else
typedef enum
{
  BTM_TIMEBASE_15_625MS = (uint8_t)0x00,		/*!< Every 15.625 milliseconds generates one interrupt */
  BTM_TIMEBASE_31_25MS  = (uint8_t)0x01,		/*!< Every 31.25 milliseconds generates one interrupt */
  BTM_TIMEBASE_62_5MS   = (uint8_t)0x02,		/*!< Every 62.5 milliseconds generates one interrupt */
  BTM_TIMEBASE_125MS    = (uint8_t)0x03,		/*!< Every 125 milliseconds generates one interrupt */
  BTM_TIMEBASE_250MS    = (uint8_t)0x04,		/*!< Every 250 milliseconds generates one interrupt */
  BTM_TIMEBASE_500MS    = (uint8_t)0x05,		/*!< Every 500 milliseconds generates one interrupt */
  BTM_TIMEBASE_1S       = (uint8_t)0x06,		/*!< Every 1 seconds generates one interrupt*/
  BTM_TIMEBASE_2S       = (uint8_t)0x07,		/*!< Every 2 seconds generates one interrupt*/
  BTM_TIMEBASE_4S       = (uint8_t)0x08,	    /*!< Every 4 seconds generates one interrupt*/
} BTM_Timebase_TypeDef;
#endif

/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup BTM_Exported_Functions BTM Exported Functions
 * @{
 */

/*macro function********************************************************/

/**
 * @brief  BTM related registers reset to default values.
 * @param  None
 * @retval None
 */
#if defined(SC92F663x) || defined(SC92F563x)
extern uint16_t xdata BTMCNT;
#define BTM_DeInit() do{CLEAR_REG(BTMCON);\
												CLEAR_REG(BTMCNT);\
											 }while(0)
#else
#define BTM_DeInit() CLEAR_REG(BTMCON)
#endif

/**
 * @brief  BTM related registers reset to default values.
 * @param  None
 * @retval BTM Interrupt flag :SET or RESET
 */
#define BTM_GetFlagStatus() ((READ_BIT(BTMCON,0x40)) ? (SET):(RESET))

/**
 * @brief  Clear BTM Flag.
 * @param  None
 * @retval None
 */  
#define BTM_ClearFlag() CLEAR_BIT(BTMCON,0x40)

/* BTM Base functions ********************************************************/
#if defined(SC92F663x) || defined(SC92F563x)
void BTM_Init(uint16_t BTM_Timebase);
#else
void BTM_Init(BTM_Timebase_TypeDef BTM_Timebase);
#endif
void BTM_Cmd(FunctionalState NewState);
/* Interrupts and flags management functions  **********************************************/
void BTM_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority);
/**
 * @}
 */
/* End of BTM Functions.	*/

/**
 * @}
 */

/**
 * @}
 */
#endif

/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/