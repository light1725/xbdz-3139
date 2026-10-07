/**
 ******************************************************************************
 * @file    sc92f_int.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of INT module.
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
#ifndef _sc92f_INT_H_
#define	_sc92f_INT_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
 /** @addtogroup INT
 * @{
 */
 
/* Exported enumerations ------------------------------------------------------------*/
/** @defgroup INT_Exported_Enumerations INT Exported Enumerations
 * @{
 */
 
 /** @brief INT_TriggerMode_Typedef INT TriggerMode
 * @{
 */
typedef enum
{
  INT_TRIGGER_RISE_ONLY = (uint8_t)0x01,	/*!< 外部中断触发方式为上升沿  */
  INT_TRIGGER_FALL_ONLY = (uint8_t)0x02,    /*!< 外部中断触发方式为下降沿  */
  INT_TRIGGER_RISE_FALL = (uint8_t)0x03,    /*!< 外部中断触发方式为上升沿与下降沿  */
  INT_TRIGGER_DISABLE   = (uint8_t)0x04		/*!< 关闭外部中断触发  */
} INT_TriggerMode_Typedef;
/**
 * @}
 */

/** @brief INTx_Typedef INTx Seclection
 * @{
 */
#if defined (SC92F827X) || defined (SC92F837X) || defined (SC92F730x) || defined (SC92F725X) || defined (SC92F735X) || defined (SC92F7490) || defined(SC92F730x_2) \
|| defined(SC92F720x) ||defined (SC92F7308B)
typedef enum
{
  INT0 = (uint8_t)0x00,			/*!< 外部中断0  */
  INT2 = (uint8_t)0x02			/*!< 外部中断2  */
} INTx_Typedef;
#elif defined(SC92F84Hx) || defined(SC92F83Hx) || defined (SC92F6x1x) || defined (SC92F5x1x) || defined (SC92R436) || defined (SC92R438)|| defined(SC92R439)\
   || defined(SC92R422A) || defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)|| defined(SC92F5x5x) || defined(SC92F531x) || defined(SC92F637x)\
	 || defined(SC92F663x) || defined(SC92F563x)
typedef enum
{
  INT0 = (uint8_t)0x00,			/*!< 外部中断0  */
  INT1 = (uint8_t)0x01,		/*!< 外部中断1  */
} INTx_Typedef;
#else
typedef enum
{
  INT0 = (uint8_t)0x00,			/*!< 外部中断0  */
  INT1 = (uint8_t)0x01,			/*!< 外部中断1  */
  INT2 = (uint8_t)0x02			/*!< 外部中断2  */
} INTx_Typedef;
#endif
/**
 * @}
 */

/** @brief INT0x_Typedef INT0x Seclection
 * @{
 */
#if defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB) || defined (SC92F83Ax) || defined (SC92F73Ax)\
		|| defined (SC92F84Ax) || defined (SC92F74Ax) || defined (SC92F848x) || defined (SC92F748x) || defined (SC92R342) || defined (SC92F841x) || defined (SC92F741x)\
    || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)|| defined (SC92Fx41xB)|| defined (SC92R445) || defined(SC92F637x)
typedef enum
{
  INT01 = (uint8_t)0x02,			/*!< 将P11设置为INT0脚  */
  INT02 = (uint8_t)0x04,			/*!< 将P12设置为INT0脚  */
  INT03 = (uint8_t)0x08			    /*!< 将P13设置为INT0脚  */

} INT0x_Typedef;

#elif defined (SC92F854x) || defined (SC92F754x) ||defined  (SC92F844xB) || defined (SC92F744xB)||defined  (SC92F84Ax_2) || defined (SC92F74Ax_2)\
		|| defined (SC92FWxx) || defined (SC92F859x) || defined (SC92F759x) || defined (SC92R511x)
typedef enum
{
  INT04 = (uint8_t)0x10,			/*!< 将P04设置为外部中断脚  */
  INT05 = (uint8_t)0x20,			/*!< 将P05设置为外部中断脚  */
  INT06 = (uint8_t)0x40,	 		/*!< 将P06设置为外部中断脚  */
  INT07 = (uint8_t)0x80			    /*!< 将P07设置为外部中断脚  */
} INT0x_Typedef;  

#elif defined (SC92F7003) || defined (SC92F8003) || defined(SC92F8003B) || defined (SC92F740x)
typedef enum
{
  INT00 = (uint8_t)0x01,		    /*!< 将P00设置为INT0脚  */
  INT01 = (uint8_t)0x02			    /*!< 将P01设置为INT0脚  */
} INT0x_Typedef;

#elif defined (SC92F742x) || defined (SC92F730x) || defined (SC92F725X) || defined (SC92F735X) || defined (SC92F732X) || defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F730x_2)\
|| defined(SC92F720x) ||defined (SC92F7308B) || defined(SC92L840x)
typedef enum
{
  INT00 = (uint8_t)0x01,			/*!< 将P10设置为INT0脚  */
  INT01 = (uint8_t)0x02,			/*!< 将P11设置为INT0脚  */
  INT02 = (uint8_t)0x04,			/*!< 将P12设置为INT0脚  */
  INT03 = (uint8_t)0x08			    /*!< 将P13设置为INT0脚  */
} INT0x_Typedef;

#elif defined (SC92F827X) || defined (SC92F837X) || defined (SC92F7490) ||  defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x) || defined (SC92L853x) || defined (SC92L753x)
typedef enum
{
  INT01 = (uint8_t)0x02,			/*!< 将P11设置为INT0脚  */
  INT02 = (uint8_t)0x04,			/*!< 将P12设置为INT0脚  */
  INT03 = (uint8_t)0x08			    /*!< 将P13设置为INT0脚  */
} INT0x_Typedef;
#elif defined (SC92F6x1x) || defined (SC92F5x1x) || defined (SC92R436) || defined (SC92R438)|| defined(SC92R439)|| defined(SC92R422A)\
			|| defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F663x) || defined(SC92F563x)
typedef enum
{
  INT00 = (uint8_t)0x01,			/*!< 将P00设置为INT0脚  */
  INT01 = (uint8_t)0x02,			/*!< 将P01设置为INT0脚  */
  INT02 = (uint8_t)0x04,			/*!< 将P02设置为INT0脚  */
	INT03 = (uint8_t)0x08,			/*!< 将P03设置为INT0脚  */
  INT04 = (uint8_t)0x10,			/*!< 将P04设置为INT0脚  */
  INT05 = (uint8_t)0x20,			/*!< 将P05设置为INT0脚  */
  INT06 = (uint8_t)0x40,			/*!< 将P06设置为INT0脚  */
	INT07 = (uint8_t)0x80			  /*!< 将P07设置为INT0脚  */
} INT0x_Typedef;
#elif defined (SC92F5x5x)
typedef enum
{
  INT00 = (uint8_t)0x01,			/*!< 将P10设置为INT0脚  */
  INT01 = (uint8_t)0x02,			/*!< 将P11设置为INT0脚  */
  INT02 = (uint8_t)0x04,			/*!< 将P12设置为INT0脚  */
	INT03 = (uint8_t)0x08,			/*!< 将P13设置为INT0脚  */
  INT05 = (uint8_t)0x20,			/*!< 将P05设置为INT0脚  */
} INT0x_Typedef;
#elif defined (SC92F531x)
typedef enum
{
  INT00 = (uint8_t)0x01,			/*!< 将P10设置为INT0脚  */
  INT01 = (uint8_t)0x02,			/*!< 将P11设置为INT0脚  */
  INT02 = (uint8_t)0x04,			/*!< 将P12设置为INT0脚  */
	INT03 = (uint8_t)0x08,			/*!< 将P13设置为INT0脚  */
	INT04 = (uint8_t)0x10,			/*!< 将P14设置为INT0脚  */
  INT05 = (uint8_t)0x20,			/*!< 将P15设置为INT0脚  */
} INT0x_Typedef;
#endif
/**
 * @}
 */

/** @brief INT1x_Typedef INT1x Seclection
 * @{
 */
#if defined (SC92F854x) || defined (SC92F754x) ||defined  (SC92F844xB) || defined (SC92F744xB)||defined  (SC92F84Ax_2) || defined (SC92F74Ax_2)\
		|| defined (SC92FWxx) || defined (SC92F859x) || defined (SC92F759x) || defined (SC92R511x) || defined (SC92F652x)|| defined(SC92R51x_R52x)\
		|| defined (SC92F552x) || defined(SC92F663x) || defined(SC92F563x)
typedef enum
{
  INT10 = (uint8_t)0x01,			/*!< 将P40设置为外部中断脚  */
  INT11 = (uint8_t)0x02,			/*!< 将P41设置为外部中断脚  */
  INT12 = (uint8_t)0x04,			/*!< 将P42设置为外部中断脚  */
  INT13 = (uint8_t)0x08,			/*!< 将P43设置为外部中断脚  */
  INT14 = (uint8_t)0x10,			/*!< 将P14设置为外部中断脚  */
  INT15 = (uint8_t)0x20,			/*!< 将P15设置为外部中断脚  */
  INT16 = (uint8_t)0x40,			/*!< 将P16设置为外部中断脚  */
  INT17 = (uint8_t)0x80 			/*!< 将P17设置为外部中断脚  */
} INT1x_Typedef;

#elif defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB)|| defined (SC92F83Ax) || defined (SC92F73Ax)\
		|| defined (SC92F84Ax) || defined (SC92F74Ax) || defined (SC92F848x) || defined (SC92F748x) || defined (SC92L853x) || defined (SC92L753x)\
		|| defined (SC92R342) || defined (SC92F841x) || defined (SC92F741x) || defined(SC92F84Hx) || defined(SC92F83Hx) ||defined(SC92F646x) || defined(SC92F546x)\
    || defined(SC92F542x)  || defined(SC92L840x)|| defined (SC92Fx41xB)|| defined (SC92R445) || defined(SC92F637x)
typedef enum
{
  INT10 = (uint8_t)0x01,		    /*!< 将P14设置为INT1脚  */
  INT11 = (uint8_t)0x02,		    /*!< 将P15设置为INT1脚  */
  INT12 = (uint8_t)0x04,		    /*!< 将P16设置为INT1脚  */
  INT13 = (uint8_t)0x08			    /*!< 将P17设置为INT1脚  */
} INT1x_Typedef;

#elif defined (SC92F7003) || defined (SC92F8003) || defined(SC92F8003B) || defined (SC92F740x)
typedef enum
{
  INT10 = (uint8_t)0x01,				    /*!< 将P10设置为INT1脚  */
  INT11 = (uint8_t)0x02,					/*!< 将P11设置为INT1脚  */
  INT12 = (uint8_t)0x04,					/*!< 将P12设置为INT1脚  */
  INT13 = (uint8_t)0x08,					/*!< 将P13设置为INT1脚  */
  INT14 = (uint8_t)0x10,					/*!< 将P14设置为INT1脚  */
  INT15 = (uint8_t)0x20,					/*!< 将P15设置为INT1脚  */
  INT16 = (uint8_t)0x40					    /*!< 将P16设置为INT1脚  */
} INT1x_Typedef;

#elif defined (SC92F742x) || defined (SC92F732X) ||  defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x) 
typedef enum
{
  INT10 = (uint8_t)0x01,					/*!< 将P14设置为INT1脚  */
  INT11 = (uint8_t)0x02,					/*!< 将P15设置为INT1脚  */
  INT12 = (uint8_t)0x04,					/*!< 将P16设置为INT1脚  */
  INT13 = (uint8_t)0x08					    /*!< 将P17设置为INT1脚  */
} INT1x_Typedef;
#elif defined (SC92F6x1x) || defined (SC92F5x1x) || defined (SC92R436) || defined (SC92R438)|| defined(SC92R439)|| defined(SC92R422A)\
		  || defined(SC92F5x5x) || defined(SC92F531x)
typedef enum
{
  INT10 = (uint8_t)0x01,					/*!< 将P10设置为INT1脚  */
  INT11 = (uint8_t)0x02,					/*!< 将P11设置为INT1脚  */
  INT12 = (uint8_t)0x04,					/*!< 将P12设置为INT1脚  */
  INT13 = (uint8_t)0x08,					/*!< 将P13设置为INT1脚  */
  INT14 = (uint8_t)0x10,					/*!< 将P14设置为INT1脚  */
  INT15 = (uint8_t)0x20,					/*!< 将P15设置为INT1脚  */
} INT1x_Typedef;
#elif defined (SC92F730x) || defined (SC92F827X) || defined (SC92F837X) || defined (SC92F725X) || defined (SC92F735X) || defined (SC92F7490) || defined(SC92F730x_2) || defined(SC92F720x)\
||defined (SC92F7308B)
typedef enum
{
  INT_Null = (uint8_t)0x00,		 /*!< 没有INT1引脚  */
} INT1x_Typedef;

#endif
/**
 * @}
 */

/** @brief INT2x_Typedef INT2x Seclection
 * @{
 */
#if defined (SC92F854x) || defined (SC92F754x) ||defined  (SC92F844xB) || defined (SC92F744xB)||defined  (SC92F84Ax_2) || defined (SC92F74Ax_2)\
		|| defined (SC92FWxx) || defined (SC92F859x) || defined (SC92F759x) || defined (SC92R511x)
typedef enum
{
  INT20 = (uint8_t)0x01,		    /*!< 将P20设置为外部中断脚  */
  INT21 = (uint8_t)0x02,			/*!< 将P21设置为外部中断脚  */
  INT22 = (uint8_t)0x04,			/*!< 将P22设置为外部中断脚  */
  INT23 = (uint8_t)0x08 			/*!< 将P23设置为外部中断脚  */
} INT2x_Typedef;

#elif defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB)|| defined (SC92F83Ax) || defined (SC92F73Ax)\
		|| defined (SC92F84Ax) || defined (SC92F74Ax) || defined (SC92F848x) || defined (SC92F748x) || defined (SC92L853x) || defined (SC92L753x)\
		|| defined (SC92R342) || defined (SC92F841x) || defined (SC92F741x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)|| defined(SC92L840x)\
    || defined (SC92Fx41xB)|| defined (SC92R445)
typedef enum
{
  INT20 = (uint8_t)0x01,			/*!< 将P04设置为INT2脚  */
  INT21 = (uint8_t)0x02,			/*!< 将P05设置为INT2脚  */
  INT22 = (uint8_t)0x04,			/*!< 将P06设置为INT2脚  */
  INT23 = (uint8_t)0x08,			/*!< 将P07设置为INT2脚  */
  INT24 = (uint8_t)0x10,			/*!< 将P20设置为INT2脚  */
  INT25 = (uint8_t)0x20			    /*!< 将P21设置为INT2脚  */
} INT2x_Typedef;

#elif defined (SC92F7003) || defined (SC92F8003) || defined(SC92F8003B) || defined (SC92F740x)
typedef enum
{
  INT21 = (uint8_t)0x02,				/*!< 将P21设置为INT2脚  */
  INT22 = (uint8_t)0x04,			    /*!< 将P22设置为INT2脚  */
  INT23 = (uint8_t)0x08,				/*!< 将P23设置为INT2脚  */
  INT24 = (uint8_t)0x10,				/*!< 将P24设置为INT2脚  */
  INT25 = (uint8_t)0x20,				/*!< 将P25设置为INT2脚  */
  INT26 = (uint8_t)0x40,				/*!< 将P26设置为INT2脚  */
  INT27 = (uint8_t)0x80					/*!< 将P27设置为INT2脚  */
} INT2x_Typedef;

#elif defined (SC92F742x) || defined (SC92F732X) ||  defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x) 
typedef enum
{
  INT20 = (uint8_t)0x01,					/*!< 将P04设置为INT2脚  */
  INT21 = (uint8_t)0x02,					/*!< 将P05设置为INT2脚  */
  INT22 = (uint8_t)0x04,					/*!< 将P06设置为INT2脚  */
  INT23 = (uint8_t)0x08,					/*!< 将P07设置为INT2脚  */
  INT24 = (uint8_t)0x10,					/*!< 将P20设置为INT2脚  */
  INT25 = (uint8_t)0x20					    /*!< 将P21设置为INT2脚  */
} INT2x_Typedef; 

#elif defined (SC92F730x) || defined (SC92F725X) || defined (SC92F735X)|| defined (SC92F7308B)
typedef enum
{
  INT24 = (uint8_t)0x10,			/*!< 将P20设置为外部中断脚  */
  INT25 = (uint8_t)0x20			    /*!< 将P21设置为外部中断脚  */
} INT2x_Typedef; 

#elif defined (SC92F837X) || defined(SC92F730x_2) || defined(SC92F720x)
typedef enum
{
  INT20 = (uint8_t)0x01,					/*!< 将P04设置为INT2脚  */
  INT21 = (uint8_t)0x02,					/*!< 将P05设置为INT2脚  */
  INT24 = (uint8_t)0x10,					/*!< 将P20设置为INT2脚  */
  INT25 = (uint8_t)0x20					    /*!< 将P21设置为INT2脚  */
} INT2x_Typedef; 

#elif defined (SC92F7490)  || defined (SC92F827X) 
typedef enum
{
  INT21 = (uint8_t)0x02,					/*!< 将P05设置为INT2脚  */
  INT24 = (uint8_t)0x10,					/*!< 将P20设置为INT2脚  */
  INT25 = (uint8_t)0x20					    /*!< 将P21设置为INT2脚  */
} INT2x_Typedef;

#elif defined(SC92F84Hx) || defined(SC92F83Hx)
typedef enum
{
  INT_Null = (uint8_t)0x00,			 /*!< 没有INT2引脚  */
} INT2x_Typedef;

#endif
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup INT_Exported_Functions INT Exported Functions
 * @{
 */

/* INT Base functions ********************************************************/
void INT_DeInit(INTx_Typedef INTx);
void INT0_SetTriggerMode(uint8_t INT0x,
                         INT_TriggerMode_Typedef TriggerMode);
void INT0_ITConfig(FunctionalState NewState,
                   PriorityStatus Priority);
#if !defined (SC92F730x) && !defined (SC92F827X) && !defined (SC92F837X) && !defined (SC92F725X) && !defined (SC92F735X) && !defined(SC92F730x_2)\
		&& !defined(SC92F720x) && !defined (SC92F7308B)
void INT1_SetTriggerMode(uint8_t INT1x,
                         INT_TriggerMode_Typedef TriggerMode);
void INT1_ITConfig(FunctionalState NewState,
                   PriorityStatus Priority);
#endif
#if !defined(SC92F84Hx) && !defined(SC92F83Hx)&& !defined(SC92F6x1x) && !defined(SC92F5x1x) && !defined(SC92R436)&& !defined(SC92R438)\
   && !defined(SC92R439) && !defined(SC92R422A)&& !defined(SC92F652x)&& !defined(SC92R51x_R52x) && !defined(SC92F552x)&& !defined(SC92F5x5x)&& !defined(SC92F531x)\
	 && !defined(SC92F637x) && !defined(SC92F663x) && !defined(SC92F563x)
void INT2_SetTriggerMode(uint8_t INT2x,
                         INT_TriggerMode_Typedef TriggerMode);
void INT2_ITConfig(FunctionalState NewState,
                   PriorityStatus Priority);
#endif
/**
 * @}
 */
/* End of exported functions --------------------------------------------------*/

/**
 * @}
 */

/**
 * @}
 */
#endif

/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/