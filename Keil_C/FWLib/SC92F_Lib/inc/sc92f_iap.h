/**
 ******************************************************************************
 * @file    sc92f_iap.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of IAP module.
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
#ifndef _sc92f_IAP_H_
#define	_sc92f_IAP_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"
#include "intrins.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
 /** @addtogroup IAP
 * @{
 */
 
  /* Exported enumerations ------------------------------------------------------------*/
/** @defgroup IAP_Exported_Enumerations IAP Exported Enumerations
 * @{
 */
 
  /** @brief IAP_MemType_TypeDef IAP Operation Section
 * @{
 */
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)
typedef enum
{
  IAP_MEMTYPE_ROM       = (uint8_t)0x00,    /*!< IAP操作区域为ROM  */
  IAP_MEMTYPE_UID				= (uint8_t)0x01,   /*!< IAP操作区域为UID，只允许读操作!!!  */
} IAP_MemType_TypeDef;
#elif defined(SC92F6x1x) ||  defined(SC92F5x1x)||  defined(SC92R436)||  defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)
typedef enum
{
  IAP_MEMTYPE_ROM       = (uint8_t)0x00,   /*!< IAP操作区域为ROM  */
  IAP_MEMTYPE_UID				= (uint8_t)0x01,    /*!< IAP操作区域为UID，只允许读操作!!!  */
} IAP_MemType_TypeDef;
#elif defined(SC92F5x5x) || defined(SC92F531x) || defined(SC92F637x)
typedef enum
{
  IAP_MEMTYPE_UID				= (uint8_t)0x01,    /*!< IAP操作区域为UID，只允许读操作!!!  */
  IAP_MEMTYPE_EEPROM    = (uint8_t)0x02     /*!< IAP操作区域为EEPROM  */
} IAP_MemType_TypeDef;
#else
typedef enum
{
  IAP_MEMTYPE_ROM       = (uint8_t)0x00,    /*!< IAP操作区域为ROM  */
  IAP_MEMTYPE_UID				= (uint8_t)0x01,    /*!< IAP操作区域为UID，只允许读操作!!!  */
  IAP_MEMTYPE_EEPROM    = (uint8_t)0x02     /*!< IAP操作区域为EEPROM  */
} IAP_MemType_TypeDef;
#endif
/**
 * @}
 */

  /** @brief IAP_HoldTime_TypeDef IAP HoldTime
 * @{
 */
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
|| defined(SC92F7003) || defined(SC92F8003) || defined(SC92F8003B) || defined(SC92F740x) || defined(SC92L840x)
typedef enum
{
  IAP_HOLDTIME_1500US   = (uint8_t)0x08,   /*!< 设定CPU Hold Time为1.5MS  */
  IAP_HOLDTIME_3000US   = (uint8_t)0x04,   /*!< 设定CPU Hold Time为3MS  */
  IAP_HOLDTIME_6000US	  = (uint8_t)0x00  /*!< 设定CPU Hold Time为6MS  */
}IAP_HoldTime_TypeDef;
#elif defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB)|| defined (SC92F83Ax) || defined (SC92F73Ax)\
	|| defined (SC92F84Ax) || defined (SC92F74Ax)	|| defined (SC92F742x) || defined (SC92F730x) || defined (SC92F827X) || defined (SC92F837X) \
	|| defined (SC92F725X) || defined (SC92F735X) || defined (SC92F732X) || defined (SC92F7490) || defined (SC93F833x) || defined (SC93F843x)\
	|| defined (SC93F733x) || defined (SC93F743x) || defined (SC92R342) || defined (SC92F841x) || defined (SC92F741x) || defined(SC92F84Hx) || defined(SC92F83Hx)\
  || defined (SC92F730x_2) || defined(SC92F720x)|| defined (SC92F7308B)|| defined (SC92Fx41xB)|| defined (SC92R445)
typedef enum
{
  IAP_HOLDTIME_4MS   = (uint8_t)0x00,		/*!< 设定CPU Hold Time为4MS   */
  IAP_HOLDTIME_2MS   = (uint8_t)0x04,	    /*!< 设定CPU Hold Time为2MS    */
  IAP_HOLDTIME_1MS   = (uint8_t)0x08		/*!< 设定CPU Hold Time为1MS    */
}IAP_HoldTime_TypeDef;
#elif defined (SC92FWxx)
typedef enum
{  
	IAP_HOLDTIME_3000US   = (uint8_t)0x00,		/*!< 设定CPU Hold Time为3MS    */
  IAP_HOLDTIME_1500US   = (uint8_t)0x04,		/*!< 设定CPU Hold Time为1.5MS    */
  IAP_HOLDTIME_1000US   = (uint8_t)0x08		    /*!< 设定CPU Hold Time为1MS    */
}IAP_HoldTime_TypeDef;
#elif defined(SC92F848x) || defined(SC92F748x) || defined(SC92F859x) || defined(SC92F759x) || defined (SC92L853x) || defined (SC92L753x)\
		|| defined (SC92R511x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)
typedef enum
{
	IAP_HOLDTIME_Null = (uint8_t)0x00		   /*!< 高速Flash，不需要Hold Time   */
}IAP_HoldTime_TypeDef;
/**
 * @}
 */

/** @brief IAP_BTLDType_TypeDef Reset Area
 * @{
 */
typedef enum
{
  IAP_BTLDType_APPROM = (uint8_t)0x00,  /*!< MCU复位后从APROM复位   */
  IAP_BTLDType_LDROM = (uint8_t)0x80,   /*!< MCU复位后从LDROM复位   */
} IAP_BTLDType_TypeDef;
#endif
#if defined(SC92F6x1x) || defined(SC92F5x1x) ||defined(SC92R436)||defined(SC92R438)||defined(SC92L840x) ||defined(SC92R439)||defined(SC92Fx41xB)\
    ||defined(SC92R445)|| defined(SC92R422A) || defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F663x)\
    || defined(SC92F563x)
typedef enum
{
  IAP_BTLDType_APPROM = (uint8_t)0x00,  /*!< MCU复位后从APROM复位   */
  IAP_BTLDType_LDROM = (uint8_t)0x80,   /*!< MCU复位后从LDROM复位   */
} IAP_BTLDType_TypeDef;
#endif
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup ADC_Exported_Functions ADC Exported Functions
 * @{
 */
#if defined(SC92F6x1x) || defined(SC92R436)||defined(SC92R438)||defined(SC92L840x) ||defined(SC92R439) ||defined(SC92Fx41xB)\
   ||defined(SC92R445) ||defined(SC92R422A) ||defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x) ||defined(SC92F5x5x) ||defined(SC92F531x)\
	 ||defined(SC92F637x) || defined(SC92F663x) || defined(SC92F563x)
/* IAP Firmware library function header file */
#include "IAP_Option_EW.h"

#if !defined(SC92L840x) &&  !defined(SC92Fx41xB) &&!defined(SC92R445) &&!defined(SC92F5x5x) &&!defined(SC92F531x) &&!defined(SC92F637x)
/**
 * @brief  IAP扇区擦除
 * @param  Address[in]: IAP操作地址
 * @param  IAP_MemType[in]: IAP操作对象
 * @retval None
 */ 
#define IAP_SectorEraseOption(Address,IAP_MemType) \
do{\
if(IAP_MemType == IAP_MEMTYPE_ROM)\
{\
	IAP_CodeSectorEraseOption(Address);\
}\
}while(0);

#endif
/**
 * @brief  IAP单Byte写入
 * @param  Address[in]: IAP操作地址
 * @param  IAP_MemType[in]: IAP操作对象
 * @retval None
 */ 
#if defined(SC92L840x)  ||defined(SC92Fx41xB)  ||defined(SC92R445) || defined(SC92F663x) || defined(SC92F563x) 
#define IAP_ProgramByteOption(Address,Data,IAP_MemType) \
do{\
if(IAP_MemType == IAP_MEMTYPE_ROM)\
{\
	IAP_CodeProgramByteOption(Address,Data);\
}\
else if(IAP_MemType == IAP_MEMTYPE_EEPROM)\
{\
	IAP_EEPROMProgramByteOption(Address,Data);\
}\
}while(0);
#elif defined(SC92F5x5x) || defined(SC92F531x) || defined(SC92F637x)
#define IAP_ProgramByteOption(Address,Data,IAP_MemType) \
do{\
if(IAP_MemType == IAP_MEMTYPE_EEPROM)\
{\
	IAP_EEPROMProgramByteOption(Address,Data);\
}\
}while(0);
#else
#define IAP_ProgramByteOption(Address,Data,IAP_MemType) \
do{\
if(IAP_MemType == IAP_MEMTYPE_ROM)\
{\
	IAP_CodeProgramByteOption(Address,Data);\
}\
}while(0);
#endif

#else
extern unsigned char IapWriteFlag;  //写入0x69,允许IAP操作；IAP操作完后需清零

typedef enum{
	IAP_ENABLE =0x69,
	IAP_SOFTKEY1 =0x09,
	IAP_SOFTKEY2 =0x60,
	IAP_DISABLE=0x00,
}IAPOPTION_FLAG;

#endif


/* IAP Base functions ********************************************************/
void IAP_DeInit(void);
#if !defined(SC92F6x1x) && !defined(SC92F5x1x) && !defined(SC92F848x)&& !defined(SC92F748x)&& !defined(SC92F859x)&& !defined(SC92F759x)\
   && !defined(SC92L853x)&& !defined(SC92L753x)&& !defined(SC92R511x)&& !defined(SC92F646x)&& !defined(SC92F546x)&& !defined(SC92F542x)\
   && !defined(SC92R436)&& !defined(SC92R438)&& !defined(SC92R439)&& !defined(SC92R422A)&& !defined(SC92F652x)&& !defined(SC92R51x_R52x) && !defined(SC92F552x)&& !defined(SC92F5x5x)\
	 && !defined(SC92F531x)&& !defined(SC92F637x)&& !defined(SC92F663x) && !defined(SC92F563x)
void IAP_SetHoldTime(IAP_HoldTime_TypeDef IAP_HoldTime);
#endif

#if !defined(SC92F6x1x) &&   !defined(SC92R436) && !defined(SC92R438) && !defined(SC92L840x) && !defined(SC92R439)&& !defined(SC92Fx41xB)\
    && !defined(SC92R445) && !defined(SC92R422A)  && !defined(SC92F652x)&& !defined(SC92R51x_R52x) && !defined(SC92F552x) &&!defined(SC92F5x5x) &&!defined(SC92F531x)\
		&& !defined(SC92F637x)&& !defined(SC92F663x)
ErrorStatus IAP_ProgramByte(uint16_t Address,
                     uint8_t Data, IAP_MemType_TypeDef IAP_MemType,
                     uint8_t WriteTimeLimit);
uint8_t IAP_ProgramByteArray(uint32_t Address, uint8_t* ByteArray, uint8_t ArraySize, IAP_MemType_TypeDef IAP_MemType,uint8_t WriteTimeLimit);
#endif
uint8_t IAP_ReadByte(uint16_t Address,
                     IAP_MemType_TypeDef IAP_MemType);
uint8_t IAP_ReadByteArray(uint32_t Address, uint8_t* ByteArray, uint8_t ArraySize, IAP_MemType_TypeDef IAP_MemType);

#if defined(SC92F848x) || defined(SC92F748x) || defined(SC92F859x) || defined(SC92F759x) || defined (SC92L853x) || defined (SC92L753x)\
		|| defined (SC92R511x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F6x1x) ||defined(SC92F5x1x)\
		||defined(SC92R436)||defined(SC92R438)||defined(SC92L840x) ||defined(SC92R439)||defined(SC92Fx41xB)||defined(SC92R445)|| defined(SC92R422A)\
		|| defined(SC92F652x)|| defined(SC92R51x_R52x) || defined(SC92F552x) || defined(SC92F663x) || defined(SC92F563x)
void IAP_SectorErase(IAP_MemType_TypeDef IAP_MemType, uint32_t IAP_SectorEraseAddress,
                     uint8_t WriteTimeLimit);
void IAP_BootLoaderControl(IAP_BTLDType_TypeDef IAP_BTLDType);
#endif

#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)
void IAP_PageErase(IAP_MemType_TypeDef IAP_MemType, uint32_t IAP_PageEraseAddress, uint8_t WriteTimeLimit);
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