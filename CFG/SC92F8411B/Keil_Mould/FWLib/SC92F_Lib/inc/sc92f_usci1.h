/**
 ******************************************************************************
 * @file    sc92F_usci1.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of UASI1 module.
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
 
 /* Define to prevent recursive inclusion ------------------------------------*/
#ifndef _sc92f_USCI1_H_
#define _sc92f_USCI1_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
 /** @addtogroup USCI1
 * @{
 */
 ///仅模式0可用，串行端口在系统时钟的1/12下运行
#define USCI1_UART_BaudRate_FsysDIV12 0X00 
///仅模式0可用，串行端口在系统时钟的1/4下运行
#define USCI1_UART_BaudRate_FsysDIV4 0X01  

/** @defgroup USCI1_Enumerations USCI1 Enumerations
 * @{
 */
 
 /** @brief USCI1_CommunicationMode_TypeDef USCI1 Communication Mode
 * @{
 */
typedef enum
{
  USCI1_Mode_SPI = (uint8_t)0x01, /*!< SPI */
  USCI1_Mode_TWI = (uint8_t)0x02, /*!< TWI */
  USCI1_Mode_UART = (uint8_t)0x03 /*!< UART */
} USCI1_CommunicationMode_TypeDef;
/**
 * @}
 */

/** @brief USCI1_SPI_FirstBit_TypeDef SPI FirstBit
 * @{
 */
typedef enum
{
  USCI1_SPI_FIRSTBIT_MSB = (uint8_t)0x00, /*!< MSB优先发送 */
  USCI1_SPI_FIRSTBIT_LSB = (uint8_t)0x04  /*!< LSB优先发送 */
} USCI1_SPI_FirstBit_TypeDef;
/**
 * @}
 */

/** @brief USCI1_SPI_BaudRatePrescaler_TypeDef SPI BaudRate Prescaler
 * @{
 */
typedef enum
{
  USCI1_SPI_BAUDRATEPRESCALER_1 = (uint8_t)0x00,  /*!< SPI时钟速率为系统时钟除以1 */
  USCI1_SPI_BAUDRATEPRESCALER_2 = (uint8_t)0x01,  /*!< SPI时钟速率为系统时钟除以2 */
  USCI1_SPI_BAUDRATEPRESCALER_4 = (uint8_t)0x02, /*!< SPI时钟速率为系统时钟除以4 */
  USCI1_SPI_BAUDRATEPRESCALER_8 = (uint8_t)0x03,  /*!< SPI时钟速率为系统时钟除以8 */
  USCI1_SPI_BAUDRATEPRESCALER_16 = (uint8_t)0x04, /*!< SPI时钟速率为系统时钟除以16 */
  USCI1_SPI_BAUDRATEPRESCALER_32 = (uint8_t)0x05, /*!< SPI时钟速率为系统时钟除以32 */
  USCI1_SPI_BAUDRATEPRESCALER_64 = (uint8_t)0x06, /*!< SPI时钟速率为系统时钟除以64 */
  USCI1_SPI_BAUDRATEPRESCALER_128 = (uint8_t)0x07 /*!< SPI时钟速率为系统时钟除以128 */
} USCI1_SPI_BaudRatePrescaler_TypeDef;
/**
 * @}
 */

/** @brief USCI1_SPI_Mode_TypeDef SPI Mode
 * @{
 */
typedef enum
{
  USCI1_SPI_MODE_MASTER = (uint8_t)0x20, /*!< SPI为主设备 */
  USCI1_SPI_MODE_SLAVE = (uint8_t)0x00   /*!< SPI为从设备 */
} USCI1_SPI_Mode_TypeDef;
/**
 * @}
 */

/** @brief USCI1_SPI_ClockPolarity_TypeDef SPI Clock Polarity
 * @{
 */
typedef enum
{
  USCI1_SPI_CLOCKPOLARITY_LOW = (uint8_t)0x00, /*!< SCK在空闲状态下为低电平 */
  USCI1_SPI_CLOCKPOLARITY_HIGH = (uint8_t)0x10 /*!< SCK在空闲状态下为高电平 */
} USCI1_SPI_ClockPolarity_TypeDef;
/**
 * @}
 */

/** @brief USCI1_SPI_ClockPhase_TypeDef SPI Mode
 * @{
 */
typedef enum
{
  USCI1_SPI_CLOCKPHASE_1EDGE = (uint8_t)0x00, /*!< SCK的第一沿采集数据 */
  USCI1_SPI_CLOCKPHASE_2EDGE = (uint8_t)0x08  /*!< SCK的第二沿采集数据 */
} USCI1_SPI_ClockPhase_TypeDef;
/**
 * @}
 */

/** @brief SPI_TXE_INT_TypeDef SPI TXE_INT
 * @{
 */
typedef enum
{
  USCI1_SPI_TXE_DISINT = (uint8_t)0x00, /*!< TXE为0时不允许发送中断 */
  USCI1_SPI_TXE_ENINT = (uint8_t)0x08   /*!< TXE为1时允许发送中断 */
} USCI1_SPI_TXE_INT_TypeDef;
/**
 * @}
 */

/** @brief USCI1_TransmissionMode_TypeDef UART Transmission Mode
 * @{
 */
typedef enum
{
  USCI1_SPI_DATA8 = (uint8_t)0x00, /*!< SPI 8位传输模式 */
  USCI1_SPI_DATA16 = (uint8_t)0x02 /*!< SPI 16位传输模式 */
} USCI1_TransmissionMode_TypeDef;
/**
 * @}
 */

/** @brief USCI1_TWI_MasterCommunicationRate_TypeDef TWI Communication Rate
 * @{
 */
typedef enum
{
  USCI1_TWI_1024 = (uint8_t)0x00, /*!< TWI通信速率 Fhrc/1024  */
  USCI1_TWI_512 = (uint8_t)0x01,  /*!< TWI通信速率 Fhrc/512  */
  USCI1_TWI_256 = (uint8_t)0x02,  /*!< TWI通信速率 Fhrc/256  */
  USCI1_TWI_128 = (uint8_t)0x03,  /*!< TWI通信速率 Fhrc/128  */
  USCI1_TWI_64 = (uint8_t)0x04,   /*!< TWI通信速率 Fhrc/64  */
  USCI1_TWI_32 = (uint8_t)0x05,   /*!< TWI通信速率 Fhrc/32  */
  USCI1_TWI_16 = (uint8_t)0x06,   /*!< TWI通信速率 Fhrc/16  */
} USCI1_TWI_MasterCommunicationRate_TypeDef;
/**
 * @}
 */

/** @brief USCI1_TWIState_TypeDef TWI State
 * @{
 */
typedef enum
{
  USCI1_TWI_SlaveBusy = 0x00,
  USCI1_TWI_SlaveReceivedaAddress = 0x01,
  USCI1_TWI_SlaveReceivedaData = 0x02,
  USCI1_TWI_SlaveSendData = 0x03,
  USCI1_TWI_SlaveReceivedaUACK = 0x04,
  USCI1_TWI_SlaveDisableACK = 0x05,
  USCI1_TWI_SlaveAddressError = 0x06,
  USCI1_TWI_MasterBusy = 0x00,
  USCI1_TWI_MasterSendAddress = 0x01,
  USCI1_TWI_MasterSendData = 0x02,
  USCI1_TWI_MasterReceivedaData = 0x03,
  USCI1_TWI_MasterReceivedaUACK = 0x04,
} USCI1_TWIState_TypeDef;
/**
 * @}
 */

/** @brief USCI1_UART_Mode_TypeDef UART Mode
 * @{
 */
typedef enum
{
  USCI1_UART_Mode_8B = 0X00,  /*!< UART设置为8位模式 */
  USCI1_UART_Mode_10B = 0X40, /*!< UART设置为10位模式 */
  USCI1_UART_Mode_11B = 0XC0  /*!< UART设置为11位模式 */
} USCI1_UART_Mode_TypeDef;
/**
 * @}
 */

/** @brief USCI1_UART_RX_TypeDef UART RX
 * @{
 */
typedef enum
{
  USCI1_UART_RX_ENABLE = 0X10, /*!< UART允许接收 */
  USCI1_UART_RX_DISABLE = 0X00 /*!< UART禁止接收 */
} USCI1_UART_RX_TypeDef;
/**
 * @}
 */

/** @brief USCI1_Flag_TypeDef UART Flag
 * @{
 */
typedef enum
{
  USCI1_SPI_FLAG_SPIF = (uint8_t)0x80, /*!< SPI数据传送标志位SPIF */
  USCI1_SPI_FLAG_WCOL = (uint8_t)0x50, /*!< SPI写入冲突标志位WCOL */
  USCI1_SPI_FLAG_TXE = (uint8_t)0x08,  /*!< SPI发送缓存器空标志TXE */
  USCI1_TWI_FLAG_TWIF = (uint8_t)0x40, /*!< TWI中断标志位TWIF */
  USCI1_TWI_FLAG_GCA = (uint8_t)0x10,  /*!< TWI通用地址响应标志位GCA */
  USCI1_TWI_FLAG_MSTR = (uint8_t)0x20, /*!< TWI主从标志位MSTR */
  USCI1_TWI_FLAG_TXRXnE = (uint8_t)0x80,
  USCI1_UART_FLAG_RI = (uint8_t)0x01, /*!< UART接收中断标志位RI */
  USCI1_UART_FLAG_TI = (uint8_t)0x02, /*!< UART发送中断标志位TI */ 
} USCI1_Flag_TypeDef;
/**
 * @}
 */

/** @brief USCI1_TWI_RWType TWI RW
 * @{
 */
typedef enum
{
  USCI1_TWI_Write = 0x00, /*!< 写操作 */
  USCI1_TWI_Read = 0x01,  /*!< 读操作 */
} USCI1_TWI_RWType;
/**
 * @}
 */
/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup USCI1_Functions USCI1 Functions
 * @{
 */
/********************************* SPI **************************************************/
void USCI1_DeInit(void);
void USCI1_SPI_Init(USCI1_SPI_FirstBit_TypeDef FirstBit,
                    USCI1_SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler, USCI1_SPI_Mode_TypeDef Mode,
                    USCI1_SPI_ClockPolarity_TypeDef ClockPolarity, USCI1_SPI_ClockPhase_TypeDef ClockPhase,
                    USCI1_SPI_TXE_INT_TypeDef SPI_TXE_INT, USCI1_TransmissionMode_TypeDef TransmissionMode);
void USCI1_TransmissionMode(USCI1_TransmissionMode_TypeDef TransmissionMode);
void USCI1_SPI_Cmd(FunctionalState NewState);
void USCI1_SPI_SendData_8(uint8_t Data);
uint8_t USCI1_SPI_ReceiveData_8(void);
void USCI1_SPI_SendData_16(uint16_t Data);
uint16_t USCI1_SPI_ReceiveData_16(void);
/********************************* TWI **************************************************/
void USCI1_TWI_Slave_Init(uint8_t TWI_Address);
void USCI1_TWI_MasterCommunicationRate(USCI1_TWI_MasterCommunicationRate_TypeDef
                                           TWI_MasterCommunicationRate);
void USCI1_TWI_Start(void);
void USCI1_TWI_MasterModeStop(void);
void USCI1_TWI_SlaveClockExtension(FunctionalState NewState);
void USCI1_TWI_AcknowledgeConfig(FunctionalState NewState);
void USCI1_TWI_GeneralCallCmd(FunctionalState NewState);
FlagStatus USCI1_GetTWIStatus(USCI1_TWIState_TypeDef USCI1_TWIState);
void USCI1_TWI_Cmd(FunctionalState NewState);
void USCI1_TWI_SendData(uint8_t Data);
uint8_t USCI1_TWI_ReceiveData(void);
/********************************* UART **************************************************/
void USCI1_UART_Init(uint32_t UART1Fsys, uint32_t BaudRate, USCI1_UART_Mode_TypeDef Mode,
                     USCI1_UART_RX_TypeDef RxMode);
void USCI1_UART_SendData8(uint8_t Data);
uint8_t USCI1_UART_ReceiveData8(void);
void USCI1_UART_SendData9(uint16_t Data);
uint16_t USCI1_UART_ReceiveData9(void);
void USCI1_ITConfig(FunctionalState NewState, PriorityStatus Priority);
FlagStatus USCI1_GetFlagStatus(USCI1_Flag_TypeDef USCI1_FLAG);
void USCI1_ClearFlag(USCI1_Flag_TypeDef USCI1_FLAG);
void USCI1_TWI_SendAddr(uint8_t Addr, USCI1_TWI_RWType RW);
#endif
/**
 * @}
 */
/* End of functions --------------------------------------------------*/
/**
 * @}
 */

/**
 * @}
 */
/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/