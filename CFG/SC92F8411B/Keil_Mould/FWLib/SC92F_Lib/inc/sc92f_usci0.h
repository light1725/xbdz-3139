/**
 ******************************************************************************
 * @file    sc92F_usci0.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of UASI0 module.
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
#ifndef _sc92f_USCI0_H_
#define _sc92f_USCI0_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @addtogroup USCI0
 * @{
 */
 
///仅模式0可用，串行端口在系统时钟的1/12下运行
#define USCI0_UART_BaudRate_FsysDIV12 0X00 
///仅模式0可用，串行端口在系统时钟的1/4下运行
#define USCI0_UART_BaudRate_FsysDIV4 0X01  

/** @defgroup USCI0_Enumerations USCI0 Enumerations
 * @{
 */
/** @brief USCI0_CommunicationMode_TypeDef USCI0 Communication Mode
 * @{
 */
typedef enum
{
  USCI0_Mode_SPI = (uint8_t)0x01, /*!< SPI */
  USCI0_Mode_TWI = (uint8_t)0x02, /*!< TWI */
  USCI0_Mode_UART = (uint8_t)0x03 /*!< UART */
} USCI0_CommunicationMode_TypeDef;
/**
 * @}
 */

/** @brief USCI0_SPI_FirstBit_TypeDef SPI FirstBit
 * @{
 */
typedef enum
{
  USCI0_SPI_FIRSTBIT_MSB = (uint8_t)0x00, /*!< MSB优先发送 */
  USCI0_SPI_FIRSTBIT_LSB = (uint8_t)0x04  /*!< LSB优先发送 */
} USCI0_SPI_FirstBit_TypeDef;
/**
 * @}
 */

/** @brief USCI0_SPI_BaudRatePrescaler_TypeDef SPI BaudRate Prescaler
 * @{
 */
typedef enum
{
  USCI0_SPI_BAUDRATEPRESCALER_1 = (uint8_t)0x00,  /*!< SPI时钟速率为系统时钟除以1 */
  USCI0_SPI_BAUDRATEPRESCALER_2 = (uint8_t)0x01,  /*!< SPI时钟速率为系统时钟除以2 */
  USCI0_SPI_BAUDRATEPRESCALER_4 = (uint8_t)0x02,  /*!< SPI时钟速率为系统时钟除以4 */
  USCI0_SPI_BAUDRATEPRESCALER_8 = (uint8_t)0x03,  /*!< SPI时钟速率为系统时钟除以8 */
  USCI0_SPI_BAUDRATEPRESCALER_16 = (uint8_t)0x04, /*!< SPI时钟速率为系统时钟除以16 */
  USCI0_SPI_BAUDRATEPRESCALER_32 = (uint8_t)0x05, /*!< SPI时钟速率为系统时钟除以32 */
  USCI0_SPI_BAUDRATEPRESCALER_64 = (uint8_t)0x06, /*!< SPI时钟速率为系统时钟除以64 */
  USCI0_SPI_BAUDRATEPRESCALER_128 = (uint8_t)0x07 /*!< SPI时钟速率为系统时钟除以128 */
} USCI0_SPI_BaudRatePrescaler_TypeDef;
/**
 * @}
 */

/** @brief USCI0_SPI_Mode_TypeDef SPI Mode
 * @{
 */
typedef enum
{
  USCI0_SPI_MODE_MASTER = (uint8_t)0x20, /*!< SPI为主设备 */
  USCI0_SPI_MODE_SLAVE = (uint8_t)0x00   /*!< SPI为从设备 */
} USCI0_SPI_Mode_TypeDef;
/**
 * @}
 */

/** @brief USCI0_SPI_ClockPolarity_TypeDef SPI Clock Polarity
 * @{
 */
typedef enum
{
  USCI0_SPI_CLOCKPOLARITY_LOW = (uint8_t)0x00, /*!< SCK在空闲状态下为低电平 */
  USCI0_SPI_CLOCKPOLARITY_HIGH = (uint8_t)0x10 /*!< SCK在空闲状态下为高电平 */
} USCI0_SPI_ClockPolarity_TypeDef;
/**
 * @}
 */

/** @brief USCI0_SPI_ClockPhase_TypeDef SPI Mode
 * @{
 */
typedef enum
{
  USCI0_SPI_CLOCKPHASE_1EDGE = (uint8_t)0x00, /*!< SCK的第一沿采集数据 */
  USCI0_SPI_CLOCKPHASE_2EDGE = (uint8_t)0x08  /*!< SCK的第二沿采集数据 */
} USCI0_SPI_ClockPhase_TypeDef;
/**
 * @}
 */

/** @brief SPI_TXE_INT_TypeDef SPI TXE_INT
 * @{
 */
typedef enum
{
  USCI0_SPI_TXE_DISINT = (uint8_t)0x00, /*!< TXE为0时不允许发送中断 */
  USCI0_SPI_TXE_ENINT = (uint8_t)0x08   /*!< TXE为1时允许发送中断 */
} USCI0_SPI_TXE_INT_TypeDef;
/**
 * @}
 */

/** @brief USCI0_TransmissionMode_TypeDef UART Transmission Mode
 * @{
 */
typedef enum
{
  USCI0_SPI_DATA8 = (uint8_t)0x00, /*!< SPI 8位传输模式 */
  USCI0_SPI_DATA16 = (uint8_t)0x02 /*!< SPI 16位传输模式 */
} USCI0_TransmissionMode_TypeDef;
/**
 * @}
 */

/** @brief USCI0_TWI_MasterCommunicationRate_TypeDef TWI Communication Rate
 * @{
 */
typedef enum
{
  USCI0_TWI_1024 = (uint8_t)0x00, /*!< TWI通信速率 Fhrc/1024 16位传输模式 */
  USCI0_TWI_512 = (uint8_t)0x01,  /*!< TWI通信速率 Fhrc/512 16位传输模式 */
  USCI0_TWI_256 = (uint8_t)0x02,  /*!< TWI通信速率 Fhrc/256 16位传输模式 */
  USCI0_TWI_128 = (uint8_t)0x03,  /*!< TWI通信速率 Fhrc/128 16位传输模式 */
  USCI0_TWI_64 = (uint8_t)0x04,   /*!< TWI通信速率 Fhrc/64  16位传输模式 */
  USCI0_TWI_32 = (uint8_t)0x05,   /*!< TWI通信速率 Fhrc/32 16位传输模式 */
  USCI0_TWI_16 = (uint8_t)0x06,   /*!< TWI通信速率 Fhrc/16 16位传输模式 */
} USCI0_TWI_MasterCommunicationRate_TypeDef;
/**
 * @}
 */

/** @brief USCI0_TWIState_TypeDef TWI State
 * @{
 */
typedef enum
{ 
  USCI0_TWI_SlaveBusy = 0x00, /*!< 作为从机 */
  USCI0_TWI_SlaveReceivedaAddress = 0x01,
  USCI0_TWI_SlaveReceivedaData = 0x02,
  USCI0_TWI_SlaveSendData = 0x03,
  USCI0_TWI_SlaveReceivedaUACK = 0x04,
  USCI0_TWI_SlaveDisableACK = 0x05,
  USCI0_TWI_SlaveAddressError = 0x06,
  USCI0_TWI_MasterBusy = 0x00, /*!< 作为主机 */
  USCI0_TWI_MasterSendAddress = 0x01,
  USCI0_TWI_MasterSendData = 0x02,
  USCI0_TWI_MasterReceivedaData = 0x03,
  USCI0_TWI_MasterReceivedaUACK = 0x04,
} USCI0_TWIState_TypeDef;
/**
 * @}
 */

/** @brief USCI0_UART_Mode_TypeDef UART Mode
 * @{
 */
typedef enum
{
  USCI0_UART_Mode_8B = 0X00,  /*!< UART设置为8位模式 */
  USCI0_UART_Mode_10B = 0X40, /*!< UART设置为10位模式 */
  USCI0_UART_Mode_11B = 0XC0  /*!< UART设置为11位模式 */
} USCI0_UART_Mode_TypeDef;
/**
 * @}
 */

/** @brief USCI0_UART_RX_TypeDef UART RX
 * @{
 */
typedef enum
{
  USCI0_UART_RX_ENABLE = 0X10, /*!< UART允许接收 */
  USCI0_UART_RX_DISABLE = 0X00 /*!< UART禁止接收 */
} USCI0_UART_RX_TypeDef;
/**
 * @}
 */

/** @brief USCI0_Flag_TypeDef UART Flag
 * @{
 */
typedef enum
{
  USCI0_SPI_FLAG_SPIF = (uint8_t)0x80, /*!< SPI数据传送标志位SPIF */
  USCI0_SPI_FLAG_WCOL = (uint8_t)0x50, /*!< SPI写入冲突标志位WCOL */
  USCI0_SPI_FLAG_TXE = (uint8_t)0x08,  /*!< SPI发送缓存器空标志TXE */
  USCI0_TWI_FLAG_TWIF = (uint8_t)0x40, /*!< TWI中断标志位TWIF */
  USCI0_TWI_FLAG_GCA = (uint8_t)0x10,  /*!< TWI通用地址响应标志位GCA */
  USCI0_TWI_FLAG_MSTR = (uint8_t)0x20, /*!< TWI主从标志位MSTR */
  USCI0_TWI_FLAG_TXRXnE = (uint8_t)0x80,
  USCI0_UART_FLAG_RI = (uint8_t)0x01,  /*!< UART接收中断标志位RI */
  USCI0_UART_FLAG_TI = (uint8_t)0x02,  /*!< UART发送中断标志位TI */ 
} USCI0_Flag_TypeDef;
/**
 * @}
 */

/** @brief USCI0_TWI_RWType TWI RW
 * @{
 */
typedef enum
{
  USCI0_TWI_Write = 0x00, /*!< 写操作 */
  USCI0_TWI_Read = 0x01,  /*!< 读操作 */
} USCI0_TWI_RWType;
/**
 * @}
 */

#if defined (SC92F663x)
/** @brief TWI_PortMappingPin_TypeDef  TWI Port Mapping Pins
 * @{
 */
typedef enum
{
  TWISCLMapped_to_P45 = (uint8_t)0x00, /*!< TWISCL映射到P45 */
  TWISCLMapped_to_P44 = (uint8_t)0x01, /*!< TWISCL映射到P44 */
  TWISCLMapped_to_P43 = (uint8_t)0x02, /*!< TWISCL映射到P43 */
  TWISCLMapped_to_P42 = (uint8_t)0x03, /*!< TWISCL映射到P42 */
	TWISCLMapped_to_P22 = (uint8_t)0x04, /*!< TWISCL映射到P22 */
	TWISCLMapped_to_P23 = (uint8_t)0x05, /*!< TWISCL映射到P23 */
  TWISCLMapped_to_P00 = (uint8_t)0x06, /*!< TWISCL映射到P00 */
  TWISCLMapped_to_P01 = (uint8_t)0x07, /*!< TWISCL映射到P01 */
  TWISDAMapped_to_P45 = (uint8_t)0x10, /*!< TWISDA映射到P45 */
  TWISDAMapped_to_P44 = (uint8_t)0x11, /*!< TWISDA映射到P44 */
  TWISDAMapped_to_P43 = (uint8_t)0x12, /*!< TWISDA映射到P43 */
  TWISDAMapped_to_P42 = (uint8_t)0x13, /*!< TWISDA映射到P42 */
	TWISDAMapped_to_P22 = (uint8_t)0x14, /*!< TWISDA映射到P22 */
	TWISDAMapped_to_P23 = (uint8_t)0x15, /*!< TWISDA映射到P23 */
  TWISDAMapped_to_P00 = (uint8_t)0x16, /*!< TWISDA映射到P00 */
  TWISDAMapped_to_P01 = (uint8_t)0x17, /*!< TWISDA映射到P01 */
} TWI_PortMappingPin_TypeDef;
/**
 * @}
 */
/** @brief UART1RX_PortMappingPin_TypeDef UART1 RX Mapping Pins
 * @{
 */
typedef enum
{
	UART1TX_Mapped_to_P50 = (uint8_t)0x00, /*!< UART1TX 映射到P50 */
  UART1TX_Mapped_to_P51 = (uint8_t)0x01, /*!< UART1TX 映射到P51 */
  UART1TX_Mapped_to_P43 = (uint8_t)0x02, /*!< UART1TX 映射到P43 */
  UART1TX_Mapped_to_P42 = (uint8_t)0x03, /*!< UART1TX 映射到P42 */
	UART1TX_Mapped_to_P41 = (uint8_t)0x04, /*!< UART1TX 映射到P41 */
	UART1TX_Mapped_to_P40 = (uint8_t)0x05, /*!< UART1TX 映射到P40 */
  UART1TX_Mapped_to_P26 = (uint8_t)0x06, /*!< UART1TX 映射到P26 */
  UART1TX_Mapped_to_P27 = (uint8_t)0x07, /*!< UART1TX 映射到P27 */
  UART1RX_Mapped_to_P50 = (uint8_t)0x10, /*!< UART1RX 映射到P50 */
  UART1RX_Mapped_to_P51 = (uint8_t)0x11, /*!< UART1RX 映射到P51 */
  UART1RX_Mapped_to_P43 = (uint8_t)0x12, /*!< UART1RX 映射到P43 */
  UART1RX_Mapped_to_P42 = (uint8_t)0x13, /*!< UART1RX 映射到P42 */
	UART1RX_Mapped_to_P41 = (uint8_t)0x14, /*!< UART1RX 映射到P41 */
	UART1RX_Mapped_to_P40 = (uint8_t)0x15, /*!< UART1RX 映射到P40 */
  UART1RX_Mapped_to_P26 = (uint8_t)0x16, /*!< UART1RX 映射到P26 */
  UART1RX_Mapped_to_P27 = (uint8_t)0x17, /*!< UART1RX 映射到P27 */
} UART1_PortMappingPin_TypeDef;
/**
 * @}
 */
#endif

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup USCI0_Functions USCI0 Functions
 * @{
 */
/********************************* SPI **************************************************/
void USCI0_DeInit(void);
void USCI0_SPI_Init(USCI0_SPI_FirstBit_TypeDef FirstBit,
                    USCI0_SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler, USCI0_SPI_Mode_TypeDef Mode,
                    USCI0_SPI_ClockPolarity_TypeDef ClockPolarity, USCI0_SPI_ClockPhase_TypeDef ClockPhase,
                    USCI0_SPI_TXE_INT_TypeDef SPI_TXE_INT, USCI0_TransmissionMode_TypeDef TransmissionMode);
void USCI0_TransmissionMode(USCI0_TransmissionMode_TypeDef TransmissionMode);
void USCI0_SPI_Cmd(FunctionalState NewState);
void USCI0_SPI_SendData_8(uint8_t Data);
uint8_t USCI0_SPI_ReceiveData_8(void);
void USCI0_SPI_SendData_16(uint16_t Data);
uint16_t USCI0_SPI_ReceiveData_16(void);
/********************************* TWI **************************************************/
void USCI0_TWI_Slave_Init(uint8_t TWI_Address);
void USCI0_TWI_MasterCommunicationRate(USCI0_TWI_MasterCommunicationRate_TypeDef
                                           TWI_MasterCommunicationRate);
void USCI0_TWI_Start(void);
void USCI0_TWI_MasterModeStop(void);
void USCI0_TWI_SendAddr(uint8_t Addr, USCI0_TWI_RWType RW);
void USCI0_TWI_SlaveClockExtension(FunctionalState NewState);
void USCI0_TWI_AcknowledgeConfig(FunctionalState NewState);
void USCI0_TWI_GeneralCallCmd(FunctionalState NewState);
FlagStatus USCI0_GetTWIStatus(USCI0_TWIState_TypeDef USCI0_TWIState);
void USCI0_TWI_Cmd(FunctionalState NewState);
void USCI0_TWI_SendData(uint8_t Data);
uint8_t USCI0_TWI_ReceiveData(void);
/********************************* UART **************************************************/
void USCI0_UART_Init(uint32_t UART1Fsys, uint32_t BaudRate, USCI0_UART_Mode_TypeDef Mode,
                     USCI0_UART_RX_TypeDef RxMode);
void USCI0_UART_SendData8(uint8_t Data);
uint8_t USCI0_UART_ReceiveData8(void);
void USCI0_UART_SendData9(uint16_t Data);
uint16_t USCI0_UART_ReceiveData9(void);
#if defined(SC92F663x)
void TWI_PortMapping(TWI_PortMappingPin_TypeDef TWI_MappingPin);
void UART1_PortMapping(UART1_PortMappingPin_TypeDef UART1_MappingPin);
void USCI0_UART_ITConfig(FunctionalState NewState, PriorityStatus Priority);
void USCI0_SPI_ITConfig(FunctionalState NewState, PriorityStatus Priority);
void USCI0_TWI_ITConfig(FunctionalState NewState, PriorityStatus Priority);
#else
void USCI0_ITConfig(FunctionalState NewState, PriorityStatus Priority);
#endif
FlagStatus USCI0_GetFlagStatus(USCI0_Flag_TypeDef USCI0_FLAG);
void USCI0_ClearFlag(USCI0_Flag_TypeDef USCI0_FLAG);
/**
 * @}
 */
/* End of functions --------------------------------------------------*/
#endif
/**
 * @}
 */

/**
 * @}
 */
/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/