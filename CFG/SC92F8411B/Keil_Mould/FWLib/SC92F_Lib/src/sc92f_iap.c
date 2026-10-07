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
 
/* Includes ------------------------------------------------------------------*/
#include "sc92f_iap.h"

#if !defined(SC92F6x1x) && !defined(SC92R436) && !defined(SC92R438) && !defined(SC92L840x) && !defined(SC92R439) && !defined(SC92Fx41xB)\
   && !defined(SC92R445) && !defined(SC92R422A) && !defined(SC92F652x) && !defined(SC92R51x_R52x) && !defined(SC92F552x) && !defined(SC92F5x5x)\
	 && !defined(SC92F531x) && !defined(SC92F637x) && !defined(SC92F663x) && !defined(SC92F563x)
	 
	 unsigned char IapWriteFlag = IAP_DISABLE;  //写入0x69,允许IAP操作；IAP操作完后需清零
	 
#endif

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
/** @defgroup IAP
 * @brief IAP driver modules
 * @{
 */
 
 /** @defgroup IAP_Functions
 * @{
 */
 
 /** @defgroup IAP_Group1 Initialization and Configuration functions
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
 * @brief  IAP相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void IAP_DeInit(void)
{
  IAPKEY = 0X00;
#if defined(SC92F531x) || defined(SC92F5x5x) || defined(SC92F637x)
	IAPAD = 0X00;
#else
  IAPADL = 0X00;
  IAPADH = 0X00;
#endif
  IAPADE = 0X00;
  IAPDAT = 0X00;
  IAPCTL = 0X00;
}
#if !defined(SC92F6x1x) && !defined(SC92F5x1x) && !defined(SC92F848x)&& !defined(SC92F748x)&& !defined(SC92F859x)&& !defined(SC92F759x)\
   && !defined(SC92L853x)&& !defined(SC92L753x)&& !defined(SC92R511x)&& !defined(SC92F646x)&& !defined(SC92F546x)&& !defined(SC92F542x)\
   && !defined(SC92R436)&& !defined(SC92R438)&& !defined(SC92R439)&& !defined(SC92R422A)&& !defined(SC92F652x)&& !defined(SC92R51x_R52x) && !defined(SC92F552x) &&!defined(SC92F5x5x)\
	 && !defined(SC92F531x)&& !defined(SC92F637x) && !defined(SC92F663x) && !defined(SC92F563x)
/**
 * @brief  IAP操作CPU Hold Time配置函数
 * @param  IAP_HoldTime_TypeDef[in]: Hold TimeTime选择
 *                            - IAP_HOLDTIME_1500US:设定CPU Hold Time为1.5MS
 *                            - IAP_HOLDTIME_3000US:设定CPU Hold Time为3MS
 *                            - IAP_HOLDTIME_6000US:设定CPU Hold Time为6MS
 * @retval None
 */ 
void IAP_SetHoldTime(IAP_HoldTime_TypeDef IAP_HoldTime)
{
  IAPCTL = IAPCTL & 0XF3 | IAP_HoldTime;
}
#endif




#if !defined(SC92F6x1x) &&   !defined(SC92R436) && !defined(SC92R438) && !defined(SC92L840x) && !defined(SC92R439)&& !defined(SC92Fx41xB)\
    &&!defined(SC92R445) && !defined(SC92R422A)  && !defined(SC92F652x)&& !defined(SC92R51x_R52x) && !defined(SC92F552x) &&!defined(SC92F5x5x) &&!defined(SC92F531x)\
		&& !defined(SC92F637x) && !defined(SC92F663x) && !defined(SC92F563x)

/**
 * @brief  IAP写入一个字节
 * @param  Address[in]: IAP操作地址
 * @param  Data[in]: 写入的数据
 * @param  IAP_MemType[in]: IAP操作对象（ROM、EEPROM）
 *                    - IAP_MEMTYPE_ROM:IAP操作区域为ROM
 *                    - IAP_MEMTYPE_UID://IAP操作区域为UID，只允许读操作!!!
 * @param  WriteTimeLimit[in]: IAP操作时限	(非零值)
 * @retval ErrorStatus[out]:IAP操作完成返回值
 *                    - ERROR:错误
 *                    - SUCCESS:成功
 */
ErrorStatus IAP_ProgramByte(uint16_t Address,
                            uint8_t Data, IAP_MemType_TypeDef IAP_MemType,
                            uint8_t WriteTimeLimit)
{
  BitStatus tmpbit;
  uint8_t TmpIAPADE;
  uint8_t tmpData;
	uint8_t  WriteFlag1 = 0xA5;
	
	/* SC92F646x/546x/542x型号若使用外部晶振，在进行IAP操作时则需使能PWM0 */
	
//#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)	
//	uint8_t tempPWMCON1 = PWMCON1;
//	uint8_t tempPWMCON0 = PWMCON0;
//#endif
	
	
  /* UID操作区域不允许写操作 */
  if(IAP_MemType == IAP_MEMTYPE_UID)
    return ERROR;

  tmpbit = (BitStatus)EA;
  TmpIAPADE = IAPADE;

  if(tmpbit != RESET)
  {
    disableInterrupts();
  }

		
	/* SC92F646x/546x/542x型号若使用外部晶振，在进行IAP操作时则需使能PWM0 */
	
//#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)	  				  
//		if(!(PWMCON0 & 0x80))
//	  {
//      PWMCON1 = 0x00;
//	    PWMCON0 |= 0x80;
//	  }	
//#endif
	
  IAPADE = IAP_MemType;
  IAPDAT = Data;
  IAPADH = (unsigned char)(Address >> 8);
  IAPADL = (unsigned char)Address;

	if((IapWriteFlag==0x69)&&(WriteFlag1==0xA5))  //如果允许IAP操作，则开锁
	{
		IAPKEY = WriteTimeLimit;
#if defined (SC92F848x) || defined (SC92F748x) || defined (SC92F859x) || defined (SC92F759x) || defined (SC92L853x) || defined (SC92L753x)\
			|| defined (SC92R511x)
		IAPCTL |= 0x10;
#elif defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F5x1x) 
		IAPCTL |= 0x08;
#endif
	}
	if((IapWriteFlag==0x69)&&(WriteFlag1==0xA5))  //如果允许IAP操作，则开锁
	{
		IAPCTL |= 0x02;
	}
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
  _nop_();
  _nop_();
  _nop_();
  _nop_();
	

	
	/* SC92F646x/546x/542x型号若使用外部晶振，在进行IAP操作时则需使能PWM0 */
	
//#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)	
//    PWMCON1 = tempPWMCON1;
//	  PWMCON0 = tempPWMCON0;
//#endif		
	
	

  if(tmpbit != RESET)
  {
    enableInterrupts();
  } 
  tmpData=*((uint8_t code*)Address); 
	IAPADE = TmpIAPADE;
	WriteFlag1 = 0;
	if(Data != tmpData)
    return ERROR;
  return SUCCESS;

}

/**
 * @brief  IAP写入长度可设的字节数组
 * @param  Address[in]: IAP操作地址
 * @param  ByteArray[in]:写入数据的数组指针
 * @param  ArraySize[out]:需要写入数组的长度
 * @param  IAP_MemType[in]:IAP操作对象（ROM、UID、EEPROM）
 *              SC92F646x,SC92F546x,SC92F542x
 *                    选择范围(IAP_MEMTYPE_ROM,IAP_MEMTYPE_UID)
 *              SC92F6x1x,SC92F5x1x,SC92R436,SC92R439,SC92R422A
 *                    选择范围(IAP_MEMTYPE_ROM,IAP_MEMTYPE_UID)
 *              其他
 *                    选择范围(IAP_MEMTYPE_ROM,IAP_MEMTYPE_UID)
 *                     - IAP_MEMTYPE_ROM:IAP操作区域为ROM
 *                     - IAP_MEMTYPE_UID:IAP操作区域为UID，只允许读操作!!!
 *                     - IAP_MEMTYPE_EEPROM:IAP操作区域为EEPROM
 * @param  WriteTimeLimit[in]:IAP操作时限（值需大于等于0x40）
* @retval tmpCnt:数组中数据写入成功的长度
 */
uint8_t IAP_ProgramByteArray(uint32_t Address, uint8_t* ByteArray, uint8_t ArraySize, IAP_MemType_TypeDef IAP_MemType,
                             uint8_t WriteTimeLimit)
{
  BitStatus tmpbit;
  uint8_t TmpIAPADE = IAPADE;
  uint8_t tmpCnt;
	uint8_t  WriteFlag2 = 0xA5;
 
	
	/* SC92F646x/546x/542x型号若使用外部晶振，在进行IAP操作时则需使能PWM0 */
	
//#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)	
//	uint8_t tempPWMCON1 = PWMCON1;
//	uint8_t tempPWMCON0 = PWMCON0;
//#endif
	
	
	
  /* UID区域不允许写操作 */
  if((IAP_MemType == IAP_MEMTYPE_UID))
    return 0;

  /* 获取总中断控制位，如果总中断控制位 */
  tmpbit = (BitStatus)EA;
  if(tmpbit != RESET)
  {
    disableInterrupts();
  }

	IAPADE = IAP_MemType;
	
	/* SC92F646x/546x/542x型号若使用外部晶振，在进行IAP操作时则需使能PWM0 */
	
//#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)	  				  
//		if(!(PWMCON0 & 0x80))
//	  {
//      PWMCON1 = 0x00;
//	    PWMCON0 |= 0x80;
//	  }	
//#endif
	
	
	
	
  

  for(tmpCnt = 0; tmpCnt < ArraySize; tmpCnt++)
  {

    IAPDAT = ByteArray[tmpCnt];
    IAPADH = (uint8_t)(Address>> 8);
    IAPADL = (uint8_t)Address;
		if((IapWriteFlag==0x69)&&(WriteFlag2==0xA5))  //如果允许IAP操作，则开锁
		{
			IAPKEY = WriteTimeLimit;
#if defined (SC92F848x) || defined (SC92F748x) || defined (SC92F859x) || defined (SC92F759x) || defined (SC92L853x) || defined (SC92L753x)\
			|| defined (SC92R511x)
			IAPCTL |= 0x10;
#elif defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)|| defined(SC92F5x1x) 
			IAPCTL |= 0x08;
#endif
		}
		if((IapWriteFlag==0x69)&&(WriteFlag2==0xA5))  //如果允许IAP操作，则开锁
		{
			IAPCTL |= 0x02;
		}
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
		_nop_();
    _nop_();
    _nop_();
    _nop_();
		
	    //cccc=	*((uint8_t code*)Address);
      if(ByteArray[tmpCnt] != *((uint8_t code*)Address))
        break;
			Address ++;

  }
  
	IAPADE = TmpIAPADE;
	WriteFlag2 = 0;
	
	/* SC92F646x/546x/542x型号若使用外部晶振，在进行IAP操作时则需使能PWM0 */
	
//#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)	
//    PWMCON1 = tempPWMCON1;
//	  PWMCON0 = tempPWMCON0;
//#endif
	
	
	
  /* 恢复原中断总开关 */
  if(tmpbit != RESET)
  {
    enableInterrupts();
  }
  return tmpCnt;
}



#endif
/**************************************************
*函数名称:uint8_t IAP_ReadByte(uint16_t Address, IAP_MemType_TypeDef IAP_MemType)
*函数功能:IAP读一个字节
*入口参数:
uint16_t:Address:IAP操作地址
IAP_MemType_TypeDef:FLASH_MemType:IAP操作对象（ROM、UID、EEPROM）
*出口参数:uint8_t			读到的字节数据
**************************************************/
uint8_t IAP_ReadByte(uint16_t Address,
                     IAP_MemType_TypeDef IAP_MemType)
{
  uint8_t tmpbyte;
  BitStatus tmpbit;
  uint8_t TmpIAPADE = IAPADE;
  tmpbit = (BitStatus)EA;

  if(tmpbit != RESET)
  {
    disableInterrupts();
  }

  IAPADE = IAP_MemType;
  tmpbyte = *((uint8_t code*)Address);
  IAPADE = TmpIAPADE;

  if(tmpbit != RESET)
  {
    enableInterrupts();
  }

  return tmpbyte;
}


/**************************************************
*函数名称:uint8_t IAP_ReadByteArray(uint32_t Address, uint8_t* ByteArray, uint8_t ArraySize, IAP_MemType_TypeDef IAP_MemType)
*函数功能:IAP读取长度可设的字节数组
*入口参数:
uint32_t:Address:IAP操作地址
IAP_MemType_TypeDef:IAP_MemType:IAP操作对象
uint8_t:ArraySize:需要读取数组的长度
uint8_t *:ByteArray:存放读取数据的数组指针
*出口参数:
uint8_t：成功读取到的字节数组长度
**************************************************/
uint8_t IAP_ReadByteArray(uint32_t Address, uint8_t* ByteArray, uint8_t ArraySize, IAP_MemType_TypeDef IAP_MemType)
{
  BitStatus tmpbit;
  uint8_t tmpCnt;
  uint8_t TmpIAPADE = IAPADE;
  tmpbit = (BitStatus)EA;

  if(tmpbit != RESET)
  {
    disableInterrupts();
  }

  IAPADE = IAP_MemType;

  for(tmpCnt = 0; tmpCnt < ArraySize; tmpCnt++)
  {
    ByteArray[tmpCnt] = *((uint8_t code*)Address);
    Address ++;
  }

  IAPADE = TmpIAPADE;
  if(tmpbit != RESET)
  {
    enableInterrupts();
  }

  return tmpCnt;
}
#if defined (SC92F848x) || defined (SC92F748x) || defined (SC92F859x) || defined (SC92F759x) || defined (SC92L853x) || defined (SC92L753x)\
		|| defined (SC92R511x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)
/**************************************************
*函数名称:void IAP_SectorErase(IAP_MemType_TypeDef IAP_MemType, uint16_t IAP_SectorEraseAddress)
*函数功能:IAP扇区擦除
*入口参数:
IAP_MemType_TypeDef:IAP_MemType:IAP操作对象（ROM）
uint32_t:IAP_SectorEraseAddress:IAP扇区擦除目标地址
uint8_t:WriteTimeLimit:IAP操作时限(值需大于等于0x40)
*出口参数:void
**************************************************/
void IAP_SectorErase(IAP_MemType_TypeDef IAP_MemType, uint32_t IAP_SectorEraseAddress,
                     uint8_t WriteTimeLimit)
{
	BitStatus tmpbit;
	uint8_t TmpIAPADE = IAPADE;
	uint8_t  WriteFlag3=0xA5;
	
	
/* SC92F646x/546x/542x恤使用外部晶振，在进行IAP操作时则需使能PWM0 */
	
//#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)	
//	uint8_t tempPWMCON1 = PWMCON1;
//	uint8_t tempPWMCON0 = PWMCON0;
//#endif
	
	
	
	tmpbit = (BitStatus)EA;

  if(tmpbit != RESET)
  {
    disableInterrupts();
  }
  /* UID操作区域不允许扇区擦除操作 */
  if(IAP_MemType == IAP_MEMTYPE_UID)
    return;
	
	
	
	/* SC92F646x/546x/542x型号若使用外部晶振，在进行IAP操作时则需使能PWM0 */
	
//#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)	  				  
//		if(!(PWMCON0 & 0x80))
//	  {
//      PWMCON1 = 0x00;
//	    PWMCON0 |= 0x80;
//	  }	
//#endif
	
	

  IAPADE = IAP_MemType;
  IAPADH = (uint8_t)(IAP_SectorEraseAddress >> 8); //擦除IAP目标地址高位值
  IAPADL = (uint8_t)IAP_SectorEraseAddress;        //擦除IAP目标地址低位值
  
	if((IapWriteFlag==0x69)&&(WriteFlag3==0xA5))  //如果允许IAP操作，则开锁
	{
		IAPKEY = WriteTimeLimit;
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)
		IAPCTL |= 0x10;
#else
		IAPCTL = 0x20;
#endif
	}
	if((IapWriteFlag==0x69)&&(WriteFlag3==0xA5))  //如果允许IAP操作，则开锁
	{
		IAPCTL |= 0x02;
	}
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
  _nop_();
  _nop_();
  _nop_();
  _nop_();
	
	IAPADE = TmpIAPADE;
	WriteFlag3 = 0;
	
	/* SC92F646x/546x/542x型号若使用外部晶振，在进行IAP操作时则需使能PWM0 */
	
//#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)	
//    PWMCON1 = tempPWMCON1;
//	  PWMCON0 = tempPWMCON0;
//#endif



	if(tmpbit != RESET)
  {
    enableInterrupts();
  }
}

/**************************************************
*函数名称:void IAP_BootLoaderControl(IAP_BTLDType_TypeDef IAP_BTLDType)
*函数功能:MCU复位后从那个区域启动
*入口参数:
IAP_BTLDType_TypeDef:IAP_BTLDType:选择启动区域
*出口参数:void
**************************************************/
void IAP_BootLoaderControl(IAP_BTLDType_TypeDef IAP_BTLDType)
{
  IAPCTL = (IAPCTL & ~IAP_BTLDType_LDROM) | IAP_BTLDType;
}
#elif defined(SC92F6x1x) || defined(SC92R436)||defined(SC92R438)||defined(SC92L840x) ||defined(SC92R439)\
     ||defined(SC92Fx41xB)||defined(SC92R445)|| defined(SC92R422A)|| defined(SC92F652x)|| defined(SC92R51x_R52x) || defined(SC92F552x)\
		 ||defined(SC92F663x) || defined(SC92F563x)
#if !defined(SC92L840x) &&  !defined(SC92Fx41xB)&&  !defined(SC92R445)
/**************************************************
*函数名称:void IAP_SectorErase(IAP_MemType_TypeDef IAP_MemType, uint16_t IAP_SectorEraseAddress)
*函数功能:IAP扇区擦除
*入口参数:
IAP_MemType_TypeDef:IAP_MemType:IAP操作对象（ROM）
uint32_t:IAP_SectorEraseAddress:IAP扇区擦除目标地址
uint8_t:WriteTimeLimit:IAP操作时限(值需大于等于0x40)
*出口参数:void
**************************************************/
void IAP_SectorErase(IAP_MemType_TypeDef IAP_MemType, uint32_t IAP_SectorEraseAddress,
                     uint8_t WriteTimeLimit)
{
   WriteTimeLimit = 0x00;	
	 IAP_SectorEraseOption(IAP_SectorEraseAddress, IAP_MemType);
	
}
#endif
/**************************************************
*函数名称:void IAP_BootLoaderControl(IAP_BTLDType_TypeDef IAP_BTLDType)
*函数功能:MCU复位后从那个区域启动
*入口参数:
IAP_BTLDType_TypeDef:IAP_BTLDType:选择启动区域
*出口参数:void
**************************************************/
void IAP_BootLoaderControl(IAP_BTLDType_TypeDef IAP_BTLDType)
{
  IAPCTL = (IAPCTL & (~IAP_BTLDType_LDROM)) | IAP_BTLDType;
}
#endif

#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)
/**************************************************
*函数名称:void IAP_PageErase(IAP_MemType_TypeDef IAP_MemType, uint16_t IAP_PageEraseAddress)
*函数功能:IAP页擦除
*入口参数:
IAP_MemType_TypeDef:IAP_MemType:IAP操作对象（ROM）
uint32_t:IAP_PageEraseAddress:IAP扇区擦除目标地址
uint8_t:WriteTimeLimit:IAP操作时限(值需大于等于0x40)
*出口参数:void
**************************************************/
void IAP_PageErase(IAP_MemType_TypeDef IAP_MemType, uint32_t IAP_PageEraseAddress,
                     uint8_t WriteTimeLimit)
{
	BitStatus tmpbit;
	uint8_t TmpIAPADE = IAPADE;
	uint8_t  WriteFlag4=0xA5; 
	/* SC92F646x/546x/542x型号若使用外部晶振，在进行IAP操作时则需使能PWM0 */
	
//	uint8_t tempPWMCON1 = PWMCON1;
//	uint8_t tempPWMCON0 = PWMCON0;

	
	
	tmpbit = (BitStatus)EA;

  if(tmpbit != RESET)
  {
    disableInterrupts();
  }
  /* UID操作区域不允许页擦除操作 */
  if(IAP_MemType == IAP_MEMTYPE_UID)
    return;
	
	
	/* SC92F646x/546x/542x型号若使用外部晶振，在进行IAP操作时则需使能PWM0 */
  				  
//		if(!(PWMCON0 & 0x80))
//	  {
//      PWMCON1 = 0x00;
//	    PWMCON0 |= 0x80;
//	  }	

	
	
  IAPADE = IAP_MemType;
  IAPADH = (uint8_t)(IAP_PageEraseAddress >> 8); //擦除IAP目标地址高位值
  IAPADL = (uint8_t)IAP_PageEraseAddress;        //擦除IAP目标地址低位值
  if((IapWriteFlag==0x69)&&(WriteFlag4==0xA5))  //如果允许IAP操作，则开锁
	{
		IAPKEY = WriteTimeLimit;
		IAPCTL = 0x20;
	}
	if((IapWriteFlag==0x69)&&(WriteFlag4==0xA5))  //如果允许IAP操作，则开锁
	{
		IAPCTL |= 0x02;
	}
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
  _nop_();
  _nop_();
  _nop_();
  _nop_();
	
	IAPADE = TmpIAPADE;
	WriteFlag4 = 0;
	
	/* SC92F646x/546x/542x型号若使用外部晶振，在进行IAP操作时则需使能PWM0 */
	
//    PWMCON1 = tempPWMCON1;
//	  PWMCON0 = tempPWMCON0;



	if(tmpbit != RESET)
  {
    enableInterrupts();
  }
}
#endif

/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/
