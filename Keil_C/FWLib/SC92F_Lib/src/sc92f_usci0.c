/**
 ******************************************************************************
 * @file    sc92F_usci0.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   USCI0 function module
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
#include "sc92f_usci0.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
/** @defgroup USCI0
 * @brief USCI0 driver modules
 * @{
 */

/** @defgroup USCI0_Functions
 * @{
 */
 
#if defined (SC92L853x) || defined (SC92L753x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92L840x) || defined(SC92F663x)
 
/** @defgroup USCI0_Group1 Initialization and Configuration functions
 *  @brief Initialization and Configuration functions
 *
@verbatim
 ====================================================================================================
                     ##### USCI0 SPI Initialization and Configuration functions #####
 ====================================================================================================
@endverbatim
  * @{
  */

  /**
 * @brief  USCI0相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void USCI0_DeInit(void)
{
#if defined(SC92F663x)
	OTCON &= 0X3F;
#else
  OTCON &= 0XCF;
#endif
  US0CON0 = 0X00;
  US0CON1 = 0X00;
  US0CON2 = 0X00;
  US0CON3 = 0X00;
#if defined(SC92F663x)
	IE1 &= (~0X01);
  IP1 &= (~0X01);
	IE2 &= (~0X0C);
  IP2 &= (~0X0C);
#else
  IE1 &= (~0X01);
  IP1 &= (~0X01);
#endif
}

/**
 * @brief  SPI初始化配置函数
 * @param  FirstBit[in]:优先传送位选择（MSB/LSB）
 *          - USCI0_SPI_FIRSTBIT_MSB:MSB优先发送
 *          - USCI0_SPI_FIRSTBIT_LSB:LSB优先发送
 * @param  BaudRatePrescaler[in]:SPI时钟频率选择
 *          - USCI0_SPI_BAUDRATEPRESCALER_1:SPI时钟速率为系统时钟除以1
 *          - USCI0_SPI_BAUDRATEPRESCALER_2:SPI时钟速率为系统时钟除以2
 *          - USCI0_SPI_BAUDRATEPRESCALER_4:SPI时钟速率为系统时钟除以4
 *          - USCI0_SPI_BAUDRATEPRESCALER_8:SPI时钟速率为系统时钟除以8
 *          - USCI0_SPI_BAUDRATEPRESCALER_16:SPI时钟速率为系统时钟除以16
 *          - USCI0_SPI_BAUDRATEPRESCALER_32:SPI时钟速率为系统时钟除以32
 *          - USCI0_SPI_BAUDRATEPRESCALER_64:SPI时钟速率为系统时钟除以64
 *          - USCI0_SPI_BAUDRATEPRESCALER_128:SPI时钟速率为系统时钟除以128
 * @param  Mode[in]:SPI工作模式选择
 *          - USCI0_SPI_MODE_MASTER:SPI为主设备
 *          - USCI0_SPI_MODE_SLAVE:SPI为从设备
 * @param  ClockPolarity[in]:SPI时钟极性选择
 *          - USCI0_SPI_CLOCKPOLARITY_LOW:SCK在空闲状态下为低电平
 *          - USCI0_SPI_CLOCKPOLARITY_HIGH:SCK在空闲状态下为高电平
 * @param  ClockPhase[in]:SPI时钟相位选择
 *          - USCI0_SPI_CLOCKPHASE_1EDGE:SCK的第一沿采集数据
 *          - USCI0_SPI_CLOCKPHASE_2EDGE:SCK的第二沿采集数据
 * @param  SPI_TXE_INT[in]:发送缓存器中断允许选择
 *          - USCI0_SPI_TXE_DISINT:不允许发送中断
 *          - USCI0_SPI_TXE_ENINT:允许发送中断
 * @param  TransmissionMode[in]:TransmissionMode
 *          - USCI0_SPI_DATA8:SPI 8位传输模式
 *          - USCI0_SPI_DATA16:SPI 16位传输模式
 * @retval None
 */
void USCI0_SPI_Init(USCI0_SPI_FirstBit_TypeDef FirstBit,
                    USCI0_SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler, USCI0_SPI_Mode_TypeDef Mode,
                    USCI0_SPI_ClockPolarity_TypeDef ClockPolarity, USCI0_SPI_ClockPhase_TypeDef ClockPhase,
                    USCI0_SPI_TXE_INT_TypeDef SPI_TXE_INT, USCI0_TransmissionMode_TypeDef TransmissionMode)
{
#if defined(SC92F663x)
	OTCON = (OTCON & 0X3F) | 0X40;
#else
  OTCON = (OTCON & 0XCF) | 0X10;
#endif
#if defined(SC92L853x) || defined(SC92L753x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)|| defined(SC92L840x)\
		|| defined(SC92F663x)
  SPI_TXE_INT = USCI0_SPI_TXE_DISINT; //SPI_TXE_INT该功能在该类芯片上无效
  US0CON1 = US0CON1 & (~0X06) | FirstBit | TransmissionMode;
#endif
  US0CON0 = US0CON0 & 0X80 | BaudRatePrescaler | Mode | ClockPolarity | ClockPhase;
}
/**
 * @}
 */
/* End of USCI0_Group1.	*/

/** @defgroup USCI0_Group2 Base functions
 *  @brief   USCI0 functions
 *
@verbatim
 ===============================================================================
                     ##### USCI0_SPI Base functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  SPI 传输模式配置函数
 * @param  TransmissionMode[in]:TransmissionMode
 *          - USCI0_SPI_DATA8:SPI 8位传输模式
 *          - USCI0_SPI_DATA16:SPI 16位传输模式
 * @retval None
 */ 
void USCI0_TransmissionMode(USCI0_TransmissionMode_TypeDef TransmissionMode)
{
#if defined(SC92F663x)
	OTCON = (OTCON & 0X3F) | 0X40;
#else
  OTCON = (OTCON & 0XCF) | 0X10;
#endif
  if (TransmissionMode == USCI0_SPI_DATA8)
  {
    US0CON1 &= 0xFD;
  }
  else
  {
    US0CON1 |= 0x02;
  }
}

/**
 * @brief  SPI功能开关函数
 * @param  NewState[in]:功能启动/关闭选择
 *          - DISABLE:失能
 *          - ENABLE:使能
 * @retval None
 */ 
void USCI0_SPI_Cmd(FunctionalState NewState)
{
#if defined(SC92F663x)
	OTCON = (OTCON & 0X3F) | 0X40;
#else
  OTCON = (OTCON & 0XCF) | 0X10;
#endif

  if (NewState != DISABLE)
  {
    US0CON0 |= 0X80;
  }
  else
  {
    US0CON0 &= (~0X80);
  }
}

/**
 * @brief  USCI0 SPI发送数据
 * @param  Data[in]:发送的数据
 * @retval None
 */ 
void USCI0_SPI_SendData_8(uint8_t Data)
{
  US0CON2 = Data;
}

/**
 * @brief  获得US0CON2中的值
 * @param  None
 * @retval SPI接收到的8位数据
 */
uint8_t USCI0_SPI_ReceiveData_8(void)
{
  return US0CON2;
}

/**
 * @brief  US0CON2 SPI发送数据
 * @param  Data[in]:发送的数据
 * @retval None
 */ 
void USCI0_SPI_SendData_16(uint16_t Data)
{
  US0CON3 = (uint8_t)(Data >> 8);
  US0CON2 = (uint8_t)Data;
}

/**
 * @brief  获得US0CON2中的值
 * @param  None
 * @retval SPI接收到的16位数据
 */
uint16_t USCI0_SPI_ReceiveData_16(void)
{
  uint16_t SPI_data;
  SPI_data = ((uint16_t)US0CON3 << 8) | US0CON2;
  return SPI_data;
}
/**
 * @}
 */
/* End of USCI0_Group2.	*/

/** @defgroup USCI0_Group3 Initialization and Configuration functions
 *  @brief Initialization and Configuration functions
 *
@verbatim
 ====================================================================================================
                     ##### USCI0 TWI Initialization and Configuration functions #####
 ====================================================================================================
@endverbatim
  * @{
  */

/**
 * @brief  USCI0 TWI从机初始化配置函数
 * @param  TWI_Address[in]:TWI作为从机时7位从机地址配置
 * @retval None
 */
void USCI0_TWI_Slave_Init(uint8_t TWI_Address)
{
#if defined(SC92F663x)
	OTCON = (OTCON & 0X3F) | 0X80;
#else
  OTCON = (OTCON & 0XCF) | 0X20;
#endif
  US0CON2 = TWI_Address << 1;
}

/**
 * @brief  USCI0 TWI主机模式下通讯速率设定
 * @param  TWI_MasterCommunicationRate[in]:TWI主机模式下通讯速率
 *              - USCI0_TWI_1024:TWI通信速率 Fhrc/1024
 *              - USCI0_TWI_512:TWI通信速率 Fhrc/512
 *              - USCI0_TWI_256:TWI通信速率 Fhrc/256
 *              - USCI0_TWI_128:TWI通信速率 Fhrc/128
 *              - USCI0_TWI_64:TWI通信速率 Fhrc/64
 *              - USCI0_TWI_32:TWI通信速率 Fhrc/32
 *              - USCI0_TWI_16:TWI通信速率 Fhrc/16
 * @retval None
 */
void USCI0_TWI_MasterCommunicationRate(USCI0_TWI_MasterCommunicationRate_TypeDef
                                           TWI_MasterCommunicationRate)
{
#if defined(SC92F663x)
	OTCON = (OTCON & 0X3F) | 0X80;
#else
  OTCON = (OTCON & 0XCF) | 0X20;
#endif
	US0CON1 &= 0XF0;
  US0CON1 |= TWI_MasterCommunicationRate;
}

/**
 * @brief  USCI0 TWI 起始位
 * @param  None
 * @retval None
 */
void USCI0_TWI_Start(void)
{
  US0CON1 |= 0x20;
}

/**
 * @brief  USCI0 TWI主机模式停止位
 * @param  None
 * @retval None
 */
void USCI0_TWI_MasterModeStop(void)
{
  US0CON1 |= 0x10;
}

/**
 * @brief  USCI0 TWI从机模式时钟延长功能位
 * @param  NewState[in]: 功能启动/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */
void USCI0_TWI_SlaveClockExtension(FunctionalState NewState)
{
#if defined(SC92F663x)
	OTCON = (OTCON & 0X3F) | 0X80;
#else
  OTCON = (OTCON & 0XCF) | 0X20;
#endif

  if (NewState != DISABLE)
  {
    US0CON1 |= 0x40;
  }
  else
  {
    US0CON1 &= 0XBF;
  }
}

/**
 * @brief  TWI接收应答使能函数
 * @param  NewState[in]: 接收应答使能/失能选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */
void USCI0_TWI_AcknowledgeConfig(FunctionalState NewState)
{
#if defined(SC92F663x)
	OTCON = (OTCON & 0X3F) | 0X80;
#else
  OTCON = (OTCON & 0XCF) | 0X20;
#endif

  if (NewState != DISABLE)
  {
    US0CON0 |= 0X08;
  }
  else
  {
    US0CON0 &= 0XF7;
  }
}

/**
 * @brief  TWI通用地址响应使能函数
 * @param  NewState[in]: 通用地址响应使能/失能选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */
void USCI0_TWI_GeneralCallCmd(FunctionalState NewState)
{
#if defined(SC92F663x)
	OTCON = (OTCON & 0X3F) | 0X80;
#else
  OTCON = (OTCON & 0XCF) | 0X20;
#endif

  if (NewState != DISABLE)
  {
    US0CON2 |= 0X01;
  }
  else
  {
    US0CON2 &= 0XFE;
  }
}

/**
 * @brief  获取TWI状态机
 * @param  USCI0_TWIState[in]: TWI状态机状态
 *              - USCI0_TWI_SlaveBusy:从机忙模式
 *              - USCI0_TWI_SlaveReceivedaAddress:从机接收地址
 *              - USCI0_TWI_SlaveReceivedaData:从机接收数据
 *              - USCI0_TWI_SlaveSendData:从机发送数据
 *              - USCI0_TWI_SlaveReceivedaUACK:从机接收UACK
 *              - USCI0_TWI_SlaveDisableACK:从机关闭ACK
 *              - USCI0_TWI_SlaveAddressError:从机接收地址错误
 *              - USCI0_TWI_MasterBusy:主机忙状态
 *              - USCI0_TWI_MasterSendAddress:主机发送地址
 *              - USCI0_TWI_MasterReceivedaData:主机接收数据
 *              - USCI0_TWI_MasterSendData:主机发送数据
 *              - USCI0_TWI_MasterReceivedaUACK:主机接收UACK
 * @retval USCI0_SC标志状态
 *              - RESET:操作不成功
 *              - SET:操作成功
 */
FlagStatus USCI0_GetTWIStatus(USCI0_TWIState_TypeDef USCI0_TWIState)
{
  if ((US0CON0 & 0x07) == USCI0_TWIState)
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
void USCI0_TWI_Cmd(FunctionalState NewState)
{
#if defined(SC92F663x)
	OTCON = (OTCON & 0X3F) | 0X80;
#else
  OTCON = (OTCON & 0XCF) | 0X20;
#endif

  if (NewState != DISABLE)
  {
    US0CON0 |= 0X80;
  }
  else
  {
    US0CON0 &= (~0X80);
  }
}

/**
 * @brief  TWI发送数据
 * @param  Data[in]:发送的数据
 * @retval None
 */ 
void USCI0_TWI_SendData(uint8_t Data)
{
  US0CON3 = Data;
}

/**
 * @brief  获得US0CON3中的值
 * @param  None
 * @retval TWI接收到的8位数据
 */
uint8_t USCI0_TWI_ReceiveData(void)
{
  return US0CON3;
}

#if defined (SC92F663x)
uint8_t xdata SPOS_SCK _at_ 0x1026;
uint8_t xdata SPOS_UART1 _at_ 0x1027;
/**
 * @brief  TWI端口映射函数
 * @param  TWI_MappingPin[in]: TWI端口映射管脚选择
 *          SC92F663x:
 *          - TWISCLMapped_to_P45:TWISCL映射到P45
 *          - TWISCLMapped_to_P44:TWISCL映射到P44
 *          - TWISCLMapped_to_P43:TWISCL映射到P43
 *          - TWISCLMapped_to_P42:TWISCL映射到P42
 *          - TWISCLMapped_to_P22:TWISCL映射到P22
 *          - TWISCLMapped_to_P23:TWISCL映射到P23
 *          - TWISCLMapped_to_P00:TWISCL映射到P00
 *          - TWISCLMapped_to_P01:TWISCL映射到P01
 *          - TWISDAMapped_to_P45:TWISDA映射到P45
 *          - TWISDAMapped_to_P44:TWISDA映射到P44
 *          - TWISDAMapped_to_P43:TWISDA映射到P43
 *          - TWISDAMapped_to_P42:TWISDA映射到P42
 *          - TWISDAMapped_to_P22:TWISDA映射到P22
 *          - TWISDAMapped_to_P23:TWISDA映射到P23
 *          - TWISDAMapped_to_P00:TWISDA映射到P00
 *          - TWISDAMapped_to_P01:TWISDA映射到P01
 * @retval None
 */ 
void TWI_PortMapping(TWI_PortMappingPin_TypeDef TWI_MappingPin)
{
	if((TWI_MappingPin & 0xF0) == 0x00)
	{
		SPOS_SCK = SPOS_SCK & 0xF0 | TWI_MappingPin;
	}
	else
	{
		SPOS_SCK = SPOS_SCK & 0x0F | (TWI_MappingPin<<4);
	}
}

/**
 * @brief  UART1端口映射函数
 * @param  UART1_TX_MappingPin[in]: UART1_TX映射管脚选择
 *          - UART1TX_Mapped_to_P50:UART1TX映射到P50
 *          - UART1TX_Mapped_to_P51:UART1TX映射到P51
 *          - UART1TX_Mapped_to_P43:UART1TX映射到P43
 *          - UART1TX_Mapped_to_P42:UART1TX映射到P42
 *          - UART1TX_Mapped_to_P41:UART1TX映射到P41
 *          - UART1TX_Mapped_to_P40:UART1TX映射到P40
 *          - UART1TX_Mapped_to_P26:UART1TX映射到P26
 *          - UART1TX_Mapped_to_P27:UART1TX映射到P27
 *          - UART1RX_Mapped_to_P50:UART1RX映射到P50
 *          - UART1RX_Mapped_to_P51:UART1RX映射到P51
 *          - UART1RX_Mapped_to_P43:UART1RX映射到P43
 *          - UART1RX_Mapped_to_P42:UART1RX映射到P42
 *          - UART1RX_Mapped_to_P41:UART1RX映射到P41
 *          - UART1RX_Mapped_to_P40:UART1RX映射到P40
 *          - UART1RX_Mapped_to_P26:UART1RX映射到P26
 *          - UART1RX_Mapped_to_P27:UART1RX映射到P27
 * @retval None
 */
void UART1_PortMapping(UART1_PortMappingPin_TypeDef UART1_MappingPin)
{
	if((UART1_MappingPin & 0xF0) == 0x00)
	{
		SPOS_UART1 = SPOS_UART1 & 0xF0 | UART1_MappingPin;
	}
	else
	{
		SPOS_UART1 = SPOS_UART1 & 0x0F | (UART1_MappingPin<<4);
	}
}
#endif
/**
 * @}
 */
/* End of USCI0_Group4.	*/

/** @defgroup USCI0_Group5 Base functions
 *  @brief   USCI0 functions
 *
@verbatim
 ===============================================================================
                     ##### USCI0_UART Base functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  UART初始化配置函数
 * @param  UARTFsys[in]:系统时钟频率
 * @param  BaudRate[in]:波特率
 * @param  Mode[in]:UART0工作模式
 *          - USCI0_UART_Mode_8B:UART设置为8位模式
 *          - USCI0_UART_Mode_10B:UART设置为10位模式
 *          - USCI0_UART_Mode_11B:UART设置为11位模式
 * @param  RxMode[in]:接收允许选择
 *          - USCI0_UART_RX_ENABLE:UART允许接收
 *          - USCI0_UART_RX_DISABLE:UART禁止接收
 * @retval None
 */
void USCI0_UART_Init(uint32_t UARTFsys, uint32_t BaudRate, USCI0_UART_Mode_TypeDef Mode,
                     USCI0_UART_RX_TypeDef RxMode)
{
#if defined(SC92F663x)
	OTCON = (OTCON & 0X3F) | 0XC0;
#else
  OTCON = (OTCON & 0XCF) | 0X30;
#endif
  US0CON0 = US0CON0 & 0X0F | Mode | RxMode;

  if (Mode == USCI0_UART_Mode_8B)
  {
    if (BaudRate == USCI0_UART_BaudRate_FsysDIV12)
    {
      US0CON0 &= 0XDF;
    }
    else if (BaudRate == USCI0_UART_BaudRate_FsysDIV4)
    {
      US0CON0 |= 0X20;
    }
  }
  else
  {
    US0CON2 = UARTFsys / BaudRate / 256;
    US0CON1 = UARTFsys / BaudRate % 256;
  }
}

/**
 * @brief  USCI0 UART1发送8位数据
 * @param  Data[in]:发送的数据
 * @retval None
 */
void USCI0_UART_SendData8(uint8_t Data)
{
  US0CON3 = Data;
}

/**
 * @brief  获得US0CON3中的值
 * @param  None
 * @retval UART接收到的8位数据
 */
uint8_t USCI0_UART_ReceiveData8(void)
{
  return US0CON3;
}

/**
 * @brief  UART发送9位数据
 * @param  Data[in]:发送的数据
 * @retval None
 */
void USCI0_UART_SendData9(uint16_t Data)
{
  uint8_t Data_9Bit;
  Data_9Bit = (Data >> 8);

  if (Data_9Bit)
  {
    US0CON0 |= 0x08;
  }
  else
  {
    US0CON0 &= 0xf7;
  }

  US0CON3 = (uint8_t)Data;
}

/**
 * @brief  获得US0CON3中的值及第九位的值
 * @param  None
 * @retval 接收到的数据
 */
uint16_t USCI0_UART_ReceiveData9(void)
{
  uint16_t Data9;
  Data9 = US0CON3 + (((uint16_t)(US0CON0 & 0X04) & 0x00FF) << 6);
  return Data9;
}

/**
 * @brief  USCI0中断初始化
 * @param  NewState[in]: 断使能/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @param  Priority[in]: 中断优先级选择
 *              - LOW:低
 *              - HIGH:高
 * @retval None
 */ 
#if defined(SC92F663x)
void USCI0_UART_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
  if (NewState != DISABLE)
  {
    IE1 |= 0x01;
  }
  else
  {
    IE1 &= 0xFE;
  }

  /************************************************************/
  if (Priority != LOW)
  {
    IP1 |= 0x01;
  }
  else
  {
    IP1 &= 0xFE;
  }
}

void USCI0_SPI_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
  if (NewState != DISABLE)
  {
    IE2 |= 0x04;
  }
  else
  {
    IE2 &= 0xFB;
  }

  /************************************************************/
  if (Priority != LOW)
  {
    IP1 |= 0x04;
  }
  else
  {
    IP1 &= 0xFB;
  }
}

void USCI0_TWI_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
  if (NewState != DISABLE)
  {
    IE1 |= 0x08;
  }
  else
  {
    IE1 &= 0xF7;
  }

  /************************************************************/
  if (Priority != LOW)
  {
    IP1 |= 0x08;
  }
  else
  {
    IP1 &= 0xF7;
  }
}
#else
void USCI0_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
  if (NewState != DISABLE)
  {
    IE1 |= 0x01;
  }
  else
  {
    IE1 &= 0xFE;
  }

  /************************************************************/
  if (Priority != LOW)
  {
    IP1 |= 0x01;
  }
  else
  {
    IP1 &= 0xFE;
  }
}
#endif

/**
 * @brief  获得USCI0标志状态
 * @param  USCI0_FLAG[in]:所需获取的标志位
 *              - USCI0_SPI_FLAG_SPIF:SPI数据传送标志位SPIF
 *              - USCI0_SPI_FLAG_WCOL:SPI写入冲突标志位WCOL
 *              - USCI0_SPI_FLAG_TXE:SPI发送缓存器空标志TXE
 *              - USCI0_TWI_FLAG_TWIF:TWI中断标志位TWIF
 *              - USCI0_TWI_FLAG_GCA:TWI通用地址响应标志位GCA
 *              - USCI0_TWI_FLAG_MSTR:TWI主从标志位MSTR
 *              - USCI0_TWI_FLAG_TXRXnE:TWI发送接收标志位
 *              - USCI0_UART_FLAG_RI:UART发送中断标志位TI
 *              - USCI0_UART_FLAG_TI:UART接收中断标志位RI
 * @retval USCI0标志状态
 *              - RESET:置零
 *              - SET:置起
 */
FlagStatus USCI0_GetFlagStatus(USCI0_Flag_TypeDef USCI0_FLAG)
{
  FlagStatus bitstatus = RESET;
  if ((USCI0_FLAG == USCI0_SPI_FLAG_SPIF) || (USCI0_FLAG == USCI0_SPI_FLAG_WCOL) || (USCI0_FLAG == USCI0_TWI_FLAG_TXRXnE))
	{
		if ((USCI0_FLAG & US0CON1) != (uint8_t)RESET)
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
		if ((USCI0_FLAG & US0CON0) != (uint8_t)RESET)
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
 * @brief  清除USCI0标志状态
 * @param  USCI0_FLAG[in]:所需清除的标志位
 *              - USCI0_SPI_FLAG_SPIF:SPI数据传送标志位SPIF
 *              - USCI0_SPI_FLAG_WCOL:SPI写入冲突标志位WCOL
 *              - USCI0_SPI_FLAG_TXE:SPI发送缓存器空标志TXE
 *              - USCI0_TWI_FLAG_TWIF:TWI中断标志位TWIF
 *              - USCI0_TWI_FLAG_GCA:TWI通用地址响应标志位GCA
 *              - USCI0_TWI_FLAG_MSTR:TWI主从标志位MSTR
 *              - USCI0_TWI_FLAG_TXRXnE:TWI发送接收标志位
 *              - USCI0_UART_FLAG_RI:UART发送中断标志位TI
 *              - USCI0_UART_FLAG_TI:UART接收中断标志位RI
 * @retval None
 */
void USCI0_ClearFlag(USCI0_Flag_TypeDef USCI0_FLAG)
{
  if ((USCI0_FLAG == USCI0_SPI_FLAG_SPIF) || (USCI0_FLAG == USCI0_SPI_FLAG_WCOL) || (USCI0_FLAG == USCI0_TWI_FLAG_TXRXnE))
  {
    US0CON1 &= (~USCI0_FLAG); //操作寄存器US0CON1
  }
  else if ((USCI0_FLAG == USCI0_UART_FLAG_TI) || (USCI0_FLAG == USCI0_UART_FLAG_RI))
  {
		if((US0CON0 & USCI0_UART_FLAG_TI))
		{
			US0CON0 &=0xFE;
		}
		if((US0CON0 & USCI0_UART_FLAG_RI))
		{
			US0CON0 &=0xFD;
		}		
  }
  else
  {
    US0CON0 &= (~USCI0_FLAG); //操作寄存器US0CON0
  }
}

/**
 * @brief  TWI发送地址，读写类型
 * @param  Addr[in]:发送的地址 0~127
 * @param  RW[in]:读写类型
 *              - USCI0_TWI_Write:写操作
 *              - USCI0_TWI_Read:读操作
 * @retval None
 */
void USCI0_TWI_SendAddr(uint8_t Addr, USCI0_TWI_RWType RW)
{
  US0CON3 = (Addr << 1) | RW;
}
/**
 * @}
 */
/* End of USCI0_Group5.	*/
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
