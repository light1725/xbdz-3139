/**
 ******************************************************************************
 * @file    sc92F_usci1.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   USCI1 function module
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
#include "sc92f_usci1.h"

#if defined (SC92L853x) || defined (SC92L753x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92L840x)
/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
/** @defgroup USCI1
 * @brief USCI1 driver modules
 * @{
 */

/** @defgroup USCI1_Functions
 * @{
 */
 
 /** @defgroup USCI1_Group1 Initialization and Configuration functions
 *  @brief Initialization and Configuration functions
 *
 
@verbatim
 ====================================================================================================
                     ##### USCI1 SPI Initialization and Configuration functions #####
 ====================================================================================================
@endverbatim
  * @{
  */

/**
 * @brief  USCI1相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void USCI1_DeInit(void)
{
  OTCON &= 0X3F;
  US1CON0 = 0X00;
  US1CON1 = 0X00;
  US1CON2 = 0X00;
  US1CON3 = 0X00;
  IE2 &= (~0X01);
  IP2 &= (~0X01);
}

/**
 * @brief  SPI初始化配置函数
 * @param  FirstBit[in]:优先传送位选择（MSB/LSB）
 *          - USCI1_SPI_FIRSTBIT_MSB:MSB优先发送
 *          - USCI1_SPI_FIRSTBIT_LSB:LSB优先发送
 * @param  BaudRatePrescaler[in]:SPI时钟频率选择
 *          - USCI1_SPI_BAUDRATEPRESCALER_1:SPI时钟速率为系统时钟除以1
 *          - USCI1_SPI_BAUDRATEPRESCALER_2:SPI时钟速率为系统时钟除以2
 *          - USCI1_SPI_BAUDRATEPRESCALER_4:SPI时钟速率为系统时钟除以4
 *          - USCI1_SPI_BAUDRATEPRESCALER_8:SPI时钟速率为系统时钟除以8
 *          - USCI1_SPI_BAUDRATEPRESCALER_16:SPI时钟速率为系统时钟除以16
 *          - USCI1_SPI_BAUDRATEPRESCALER_32:SPI时钟速率为系统时钟除以32
 *          - USCI1_SPI_BAUDRATEPRESCALER_64:SPI时钟速率为系统时钟除以64
 *          - USCI1_SPI_BAUDRATEPRESCALER_128:SPI时钟速率为系统时钟除以128
 * @param  Mode[in]:SPI工作模式选择
 *          - USCI1_SPI_MODE_MASTER:SPI为主设备
 *          - USCI1_SPI_MODE_SLAVE:SPI为从设备
 * @param  ClockPolarity[in]:SPI时钟极性选择
 *          - USCI1_SPI_CLOCKPOLARITY_LOW:SCK在空闲状态下为低电平
 *          - USCI1_SPI_CLOCKPOLARITY_HIGH:SCK在空闲状态下为高电平
 * @param  ClockPhase[in]:SPI时钟相位选择
 *          - USCI1_SPI_CLOCKPHASE_1EDGE:SCK的第一沿采集数据
 *          - USCI1_SPI_CLOCKPHASE_2EDGE:SCK的第二沿采集数据
 * @param  SPI_TXE_INT[in]:发送缓存器中断允许选择
 *          - USCI1_SPI_TXE_DISINT:不允许发送中断
 *          - USCI1_SPI_TXE_ENINT:允许发送中断
 * @param  TransmissionMode[in]:TransmissionMode
 *          - USCI1_SPI_DATA8:SPI 8位传输模式
 *          - USCI1_SPI_DATA16:SPI 16位传输模式
 * @retval None
 */
void USCI1_SPI_Init(USCI1_SPI_FirstBit_TypeDef FirstBit,
                    USCI1_SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler, USCI1_SPI_Mode_TypeDef Mode,
                    USCI1_SPI_ClockPolarity_TypeDef ClockPolarity, USCI1_SPI_ClockPhase_TypeDef ClockPhase,
                    USCI1_SPI_TXE_INT_TypeDef SPI_TXE_INT, USCI1_TransmissionMode_TypeDef TransmissionMode)
{

  OTCON = (OTCON & 0X3F) | 0X40;
#if defined(SC92L853x) || defined(SC92L753x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92L840x)
  SPI_TXE_INT = USCI1_SPI_TXE_DISINT; //SPI_TXE_INT该功能无效
  US1CON1 = US1CON1 & (~0X06) | FirstBit | TransmissionMode;
#endif
  US1CON0 = US1CON0 & 0X80 | BaudRatePrescaler | Mode | ClockPolarity | ClockPhase;
}
/**
 * @}
 */
/* End of USCI1_Group1.	*/

/** @defgroup USCI1_Group2 Base functions
 *  @brief   USCI1 functions
 *
@verbatim
 ===============================================================================
                     ##### USCI1_SPI Base functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  SPI 传输模式配置函数
 * @param  TransmissionMode[in]:TransmissionMode
 *          - USCI1_SPI_DATA8:SPI 8位传输模式
 *          - USCI1_SPI_DATA16:SPI 16位传输模式
 * @retval None
 */ 
void USCI1_TransmissionMode(USCI1_TransmissionMode_TypeDef TransmissionMode)
{
	OTCON =(OTCON & 0XCF) | 0X10;
  if (TransmissionMode == USCI1_SPI_DATA8)
  {
    US1CON1 &= 0xFD;
  }
  else
  {
    US1CON1 |= 0x02;
  }
}

/**
 * @brief  SPI功能开关函数
 * @param  NewState[in]:功能启动/关闭选择
 *          - DISABLE:失能
 *          - ENABLE:使能
 * @retval None
 */ 
void USCI1_SPI_Cmd(FunctionalState NewState)
{
  OTCON = (OTCON & 0X3F) | 0X40;

  if (NewState != DISABLE)
  {
    US1CON0 |= 0X80;
  }
  else
  {
    US1CON0 &= (~0X80);
  }
}

/**
 * @brief  USCI1 SPI发送数据
 * @param  Data[in]:发送的数据
 * @retval None
 */ 
void USCI1_SPI_SendData_8(uint8_t Data)
{
  US1CON2 = Data;
}

/**
 * @brief  获得US1CON2中的值
 * @param  None
 * @retval SPI接收到的8位数据
 */
uint8_t USCI1_SPI_ReceiveData_8(void)
{
  return US1CON2;
}

/**
 * @brief  US1CON2 SPI发送数据
 * @param  Data[in]:发送的数据
 * @retval None
 */
void USCI1_SPI_SendData_16(uint16_t Data)
{
  US1CON3 = (uint8_t)(Data >> 8);
  US1CON2 = (uint8_t)Data;
}

/**
 * @brief  获得US1CON2中的值
 * @param  None
 * @retval SPI接收到的16位数据
 */
uint16_t USCI1_SPI_ReceiveData_16(void)
{
  uint16_t SPI_data;
  SPI_data = ((uint16_t)US1CON3 << 8) | US1CON2;
  return SPI_data;
}
/**
 * @}
 */
/* End of USCI1_Group2.	*/

/** @defgroup USCI1_Group3 Initialization and Configuration functions
 *  @brief Initialization and Configuration functions
 *
@verbatim
 ====================================================================================================
                     ##### USCI1 TWI Initialization and Configuration functions #####
 ====================================================================================================
@endverbatim
  * @{
  */

/**
 * @brief  USCI1 TWI从机初始化配置函数
 * @param  TWI_Address[in]:TWI作为从机时7位从机地址配置
 * @retval None
 */
void USCI1_TWI_Slave_Init(uint8_t TWI_Address)
{
  OTCON = OTCON & 0X3F | 0X80;
  US1CON2 = TWI_Address << 1;
}

/**
 * @brief  USCI1 TWI主机模式下通讯速率设定
 * @param  TWI_MasterCommunicationRate[in]:TWI主机模式下通讯速率
 *              - USCI1_TWI_1024:TWI通信速率 Fhrc/1024
 *              - USCI1_TWI_512:TWI通信速率 Fhrc/512
 *              - USCI1_TWI_256:TWI通信速率 Fhrc/256
 *              - USCI1_TWI_128:TWI通信速率 Fhrc/128
 *              - USCI1_TWI_64:TWI通信速率 Fhrc/64
 *              - USCI1_TWI_32:TWI通信速率 Fhrc/32
 *              - USCI1_TWI_16:TWI通信速率 Fhrc/16
 * @retval None
 */
void USCI1_TWI_MasterCommunicationRate(USCI1_TWI_MasterCommunicationRate_TypeDef
                                           TWI_MasterCommunicationRate)
{
  OTCON = OTCON & 0X3F | 0X80;
  US1CON1 |= TWI_MasterCommunicationRate;
}

/**
 * @brief  USCI1 TWI 起始位
 * @param  None
 * @retval None
 */
void USCI1_TWI_Start(void)
{
  US1CON1 |= 0x20;
}

/**
 * @brief  USCI1 TWI主机模式停止位
 * @param  None
 * @retval None
 */
void USCI1_TWI_MasterModeStop(void)
{
  US1CON1 |= 0x10;
}

/**
 * @brief  USCI1 TWI从机模式时钟延长功能位
 * @param  NewState[in]: 功能启动/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */
void USCI1_TWI_SlaveClockExtension(FunctionalState NewState)
{
  OTCON = OTCON & 0X3F | 0X80;

  if (NewState != DISABLE)
  {
    US1CON1 |= 0x40;
  }
  else
  {
    US1CON1 &= 0XBF;
  }
}

/**
 * @brief  TWI接收应答使能函数
 * @param  NewState[in]: 接收应答使能/失能选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */
void USCI1_TWI_AcknowledgeConfig(FunctionalState NewState)
{
  OTCON = OTCON & 0X3F | 0X80;

  if (NewState != DISABLE)
  {
    US1CON0 |= 0X08;
  }
  else
  {
    US1CON0 &= 0XF7;
  }
}

/**
 * @brief  TWI通用地址响应使能函数
 * @param  NewState[in]: 通用地址响应使能/失能选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */
void USCI1_TWI_GeneralCallCmd(FunctionalState NewState)
{
  OTCON = OTCON & 0X3F | 0X80;

  if (NewState != DISABLE)
  {
    US1CON2 |= 0X01;
  }
  else
  {
    US1CON2 &= 0XFE;
  }
}

/**
 * @brief  获取TWI状态机
 * @param  USCI1_TWIState[in]: TWI状态机状态
 *              - USCI1_TWI_SlaveBusy:从机忙模式
 *              - USCI1_TWI_SlaveReceivedaAddress:从机接收地址
 *              - USCI1_TWI_SlaveReceivedaData:从机接收数据
 *              - USCI1_TWI_SlaveSendData:从机发送数据
 *              - USCI1_TWI_SlaveReceivedaUACK:从机接收UACK
 *              - USCI1_TWI_SlaveDisableACK:从机关闭ACK
 *              - USCI1_TWI_SlaveAddressError:从机接收地址错误
 *              - USCI1_TWI_MasterBusy:主机忙状态
 *              - USCI1_TWI_MasterSendAddress:主机发送地址
 *              - USCI1_TWI_MasterReceivedaData:主机接收数据
 *              - USCI1_TWI_MasterSendData:主机发送数据
 *              - USCI1_TWI_MasterReceivedaUACK:主机接收UACK
 * @retval USCI1_SC标志状态
 *              - RESET:操作不成功
 *              - SET:操作成功
 */
FlagStatus USCI1_GetTWIStatus(USCI1_TWIState_TypeDef USCI1_TWIState)
{
  if ((US1CON0 & 0x07) == USCI1_TWIState)
    return SET;
  else
    return RESET;
}

/**
 * @brief  TWI功能开关函数
 * @param  NewState[in]: 功能启动/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */
void USCI1_TWI_Cmd(FunctionalState NewState)
{
  OTCON = OTCON & 0X3F | 0X80;

  if (NewState != DISABLE)
  {
    US1CON0 |= 0X80;
  }
  else
  {
    US1CON0 &= (~0X80);
  }
}

/**
 * @brief  TWI发送数据
 * @param  Data[in]:发送的数据
 * @retval None
 */ 
void USCI1_TWI_SendData(uint8_t Data)
{
  US1CON3 = Data;
}

/**
 * @brief  获得US1CON3中的值
 * @param  None
 * @retval TWI接收到的8位数据
 */
uint8_t USCI1_TWI_ReceiveData(void)
{
  return US1CON3;
}
/**
 * @}
 */
/* End of USCI1_Group4.	*/

/** @defgroup USCI1_Group5 Base functions
 *  @brief   USCI1 functions
 *
@verbatim
 ===============================================================================
                     ##### USCI1_UART Base functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  UART初始化配置函数
 * @param  UARTFsys[in]:系统时钟频率
 * @param  BaudRate[in]:波特率
 * @param  Mode[in]:UART0工作模式
 *          - USCI1_UART_Mode_8B:UART设置为8位模式
 *          - USCI1_UART_Mode_10B:UART设置为10位模式
 *          - USCI1_UART_Mode_11B:UART设置为11位模式
 * @param  RxMode[in]:接收允许选择
 *          - USCI1_UART_RX_ENABLE:UART允许接收
 *          - USCI1_UART_RX_DISABLE:UART禁止接收
 * @retval None
 */
void USCI1_UART_Init(uint32_t UARTFsys, uint32_t BaudRate, USCI1_UART_Mode_TypeDef Mode,
                     USCI1_UART_RX_TypeDef RxMode)
{
  OTCON |= 0xC0;
  US1CON0 = US1CON0 & 0X0F | Mode | RxMode;

  if (Mode == USCI1_UART_Mode_8B)
  {
    if (BaudRate == USCI1_UART_BaudRate_FsysDIV12)
    {
      US1CON0 &= 0XDF;
    }
    else if (BaudRate == USCI1_UART_BaudRate_FsysDIV4)
    {
      US1CON0 |= 0X20;
    }
  }
  else
  {
    US1CON2 = UARTFsys / BaudRate / 256;
    US1CON1 = UARTFsys / BaudRate % 256;
  }
}

/**
 * @brief  USCI1 UART1发送8位数据
 * @param  Data[in]:发送的数据
 * @retval None
 */
void USCI1_UART_SendData8(uint8_t Data)
{
	US1CON3 = Data;
}

/**
 * @brief  获得US1CON3中的值
 * @param  None
 * @retval UART接收到的8位数据
 */
uint8_t USCI1_UART_ReceiveData8(void)
{
  return US1CON3;
}

/**
 * @brief  UART发送9位数据
 * @param  Data[in]:发送的数据
 * @retval None
 */
void USCI1_UART_SendData9(uint16_t Data)
{
  uint8_t Data_9Bit;
  Data_9Bit = (Data >> 8);

  if (Data_9Bit)
  {
    US1CON0 |= 0x08;
  }
  else
  {
    US1CON0 &= 0xf7;
  }

  US1CON3 = (uint8_t)Data;
}

/**
 * @brief  获得US1CON3中的值及第九位的值
 * @param  None
 * @retval 接收到的数据
 */
uint16_t USCI1_UART_ReceiveData9(void)
{
  uint16_t Data9;
  Data9 = US1CON3 + (((uint16_t)(US1CON0 & 0X04) & 0x00FF) << 6);
  return Data9;
}

/**
 * @brief  USCI1中断初始化
 * @param  NewState[in]: 断使能/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @param  Priority[in]: 中断优先级选择
 *              - LOW:低
 *              - HIGH:高
 * @retval None
 */ 
void USCI1_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
  if (NewState != DISABLE)
  {
    IE2 |= 0x01;
  }
  else
  {
    IE2 &= 0xFE;
  }

  /************************************************************/
  if (Priority != LOW)
  {
    IP2 |= 0x01;
  }
  else
  {
    IP2 &= 0xFE;
  }
}

/**
 * @brief  获得USCI1标志状态
 * @param  USCI1_FLAG[in]:所需获取的标志位
 *              - USCI1_SPI_FLAG_SPIF:SPI数据传送标志位SPIF
 *              - USCI1_SPI_FLAG_WCOL:SPI写入冲突标志位WCOL
 *              - USCI1_SPI_FLAG_TXE:SPI发送缓存器空标志TXE
 *              - USCI1_TWI_FLAG_TWIF:TWI中断标志位TWIF
 *              - USCI1_TWI_FLAG_GCA:TWI通用地址响应标志位GCA
 *              - USCI1_TWI_FLAG_MSTR:TWI主从标志位MSTR
 *              - USCI1_TWI_FLAG_TXRXnE:TWI发送接收标志位
 *              - USCI1_UART_FLAG_RI:UART发送中断标志位TI
 *              - USCI1_UART_FLAG_TI:UART接收中断标志位RI
 * @retval USCI1标志状态
 *              - RESET:置零
 *              - SET:置起
 */
FlagStatus USCI1_GetFlagStatus(USCI1_Flag_TypeDef USCI1_FLAG)
{
  FlagStatus bitstatus = RESET;
#if defined(SC92L853x) || defined(SC92L753x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)|| defined(SC92L840x)
  if ((USCI1_FLAG == USCI1_SPI_FLAG_SPIF) || (USCI1_FLAG == USCI1_SPI_FLAG_WCOL) || (USCI1_FLAG == USCI1_TWI_FLAG_TXRXnE))
#endif
    {
      if ((USCI1_FLAG & US1CON1) != (uint8_t)RESET)
      {
        bitstatus = SET;
      }
      else
      {
        bitstatus = RESET;
      }
    }
    else
    {
      if ((USCI1_FLAG & US1CON0) != (uint8_t)RESET)
      {
        bitstatus = SET;
      }
      else
      {
        bitstatus = RESET;
      }
    }

  return bitstatus;
}

/**
 * @brief  清除USCI1标志状态
 * @param  USCI1_FLAG[in]:所需清除的标志位
 *              - USCI1_SPI_FLAG_SPIF:SPI数据传送标志位SPIF
 *              - USCI1_SPI_FLAG_WCOL:SPI写入冲突标志位WCOL
 *              - USCI1_SPI_FLAG_TXE:SPI发送缓存器空标志TXE
 *              - USCI1_TWI_FLAG_TWIF:TWI中断标志位TWIF
 *              - USCI1_TWI_FLAG_GCA:TWI通用地址响应标志位GCA
 *              - USCI1_TWI_FLAG_MSTR:TWI主从标志位MSTR
 *              - USCI1_TWI_FLAG_TXRXnE:TWI发送接收标志位
 *              - USCI1_UART_FLAG_RI:UART发送中断标志位TI
 *              - USCI1_UART_FLAG_TI:UART接收中断标志位RI
 * @retval None
 */
void USCI1_ClearFlag(USCI1_Flag_TypeDef USCI1_FLAG)
{
#if defined(SC92L853x) || defined(SC92L753x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)|| defined(SC92L840x)
  if ((USCI1_FLAG == USCI1_SPI_FLAG_SPIF) || (USCI1_FLAG == USCI1_SPI_FLAG_WCOL) || (USCI1_FLAG == USCI1_TWI_FLAG_TXRXnE))
#endif
  {
    US1CON1 &= (~USCI1_FLAG); //操作寄存器US1CON1
  }
  else if ((USCI1_FLAG == USCI1_UART_FLAG_TI) || (USCI1_FLAG == USCI1_UART_FLAG_RI))
  {
#if defined(SC92L853x) || defined(SC92L753x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)|| defined(SC92L840x)
	if((US1CON0 & USCI1_UART_FLAG_TI))
	{
		US1CON0 &=0xFE;
	}
	if((US1CON0 & USCI1_UART_FLAG_RI))
	{
		US1CON0 &=0xFD;
	}		//写1清零
#endif
  }
  else
  {
    US1CON0 &= (~USCI1_FLAG); //操作寄存器US1CON0
  }
}

/**
 * @brief  TWI发送地址，读写类型
 * @param  Addr[in]:发送的地址 0~127
 * @param  RW[in]:读写类型
 *              - USCI1_TWI_Write:写操作
 *              - USCI1_TWI_Read:读操作
 * @retval None
 */
void USCI1_TWI_SendAddr(uint8_t Addr, USCI1_TWI_RWType RW)
{
  US1CON3 = (Addr << 1) | RW;
}
/**
 * @}
 */
/* End of USCI1_Group5.	*/
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
