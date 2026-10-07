/**
 ******************************************************************************
 * @file    sc92f_ssi.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of SSI module.
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
#ifndef _sc92f_SSI_H_
#define	_sc92f_SSI_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @addtogroup SSI
 * @{
 */

#if defined (SC92F854x) || defined (SC92F754x) ||defined  (SC92F844xB) || defined (SC92F744xB)||defined  (SC92F84Ax_2) || defined (SC92F74Ax_2)\
		|| defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB)||defined  (SC92F84Ax) || defined (SC92F74Ax)\
		|| defined (SC92F83Ax) || defined (SC92F73Ax) || defined (SC92F7003) || defined(SC92F8003) || defined(SC92F8003B) || defined (SC92F740x) || defined (SC92F827X)\
		|| defined (SC92F837X) || defined (SC92FWxx) || defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x) || defined (SC92F848x) || defined (SC92F748x)\
		|| defined (SC92F859x) || defined (SC92F759x) || defined (SC92R511x) || defined (SC92R342) || defined (SC92F841x) || defined (SC92F741x)\
		|| defined(SC92F84Hx) || defined(SC92F83Hx) ||  defined(SC92F6x1x) || defined(SC92F5x1x)|| defined(SC92R436)|| defined(SC92R438)|| defined(SC92R439)\
		|| defined (SC92Fx41xB)|| defined (SC92R445)|| defined (SC92R422A)|| defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)|| defined(SC92F5x5x)\
		|| defined (SC92F531x) || defined (SC92F637x) || defined (SC92F563x)
/** @defgroup SSI_Enumerations SSI Enumerations
 * @{
 */
 
/** @brief SPI_FirstBit_TypeDef SPI FirstBit
 * @{
 */
typedef enum
{
  SPI_FIRSTBIT_MSB = (uint8_t)0x00, 			   /*!< MSB优先发送 */
  SPI_FIRSTBIT_LSB = (uint8_t)0x04  			   /*!< LSB优先发送 */
} SPI_FirstBit_TypeDef;
/**
 * @}
 */

/** @brief SPI_BaudRatePrescaler_TypeDef SPI BaudRate Prescaler
 * @{
 */
typedef enum
{
  SPI_BAUDRATEPRESCALER_4   = (uint8_t)0x00, /*!< SPI时钟速率为系统时钟除以4 */
  SPI_BAUDRATEPRESCALER_8   = (uint8_t)0x01, /*!< SPI时钟速率为系统时钟除以8 */
  SPI_BAUDRATEPRESCALER_16  = (uint8_t)0x02, /*!< SPI时钟速率为系统时钟除以16 */
  SPI_BAUDRATEPRESCALER_32  = (uint8_t)0x03, /*!< SPI时钟速率为系统时钟除以32 */
  SPI_BAUDRATEPRESCALER_64  = (uint8_t)0x04, /*!< SPI时钟速率为系统时钟除以64 */
  SPI_BAUDRATEPRESCALER_128 = (uint8_t)0x05, /*!< SPI时钟速率为系统时钟除以128 */
  SPI_BAUDRATEPRESCALER_256 = (uint8_t)0x06, /*!< SPI时钟速率为系统时钟除以256 */
  SPI_BAUDRATEPRESCALER_512 = (uint8_t)0x07  /*!< SPI时钟速率为系统时钟除以512 */
} SPI_BaudRatePrescaler_TypeDef;
/**
 * @}
 */

/** @brief SPI_Mode_TypeDef SPI Mode
 * @{
 */
typedef enum
{
  SPI_MODE_MASTER = (uint8_t)0x20, /*!< SPI为主设备 */
  SPI_MODE_SLAVE  = (uint8_t)0x00  /*!< SPI为从设备 */
} SPI_Mode_TypeDef;
/**
 * @}
 */

/** @brief SPI_ClockPolarity_TypeDef SPI Clock Polarity
 * @{
 */
typedef enum
{
  SPI_CLOCKPOLARITY_LOW  = (uint8_t)0x00, /*!< SCK在空闲状态下为低电平 */
  SPI_CLOCKPOLARITY_HIGH = (uint8_t)0x10  /*!< SCK在空闲状态下为高电平 */
} SPI_ClockPolarity_TypeDef;
/**
 * @}
 */

/** @brief SPI_Mode_TypeDef SPI Mode
 * @{
 */
typedef enum
{
  SPI_CLOCKPHASE_1EDGE = (uint8_t)0x00, /*!< SCK的第一沿采集数据 */
  SPI_CLOCKPHASE_2EDGE = (uint8_t)0x08  /*!< SCK的第二沿采集数据 */
} SPI_ClockPhase_TypeDef;
/**
 * @}
 */

/** @brief SSI_TWIState_TypeDef TWI State
 * @{
 */
typedef enum
{
  //作为从机
  TWI_SlaveIdle = 0x00,
  TWI_SlaveReceivedaAddress = 0x01,
  TWI_SlaveReceivedaData = 0x02,
  TWI_SlaveSendData = 0x03,
  TWI_SlaveReceivedaUACK = 0x04,
  TWI_SlaveDisableACK = 0x05,
  TWI_SlaveAddressError = 0x06,

} SSI_TWIState_TypeDef;
/**
 * @}
 */

/** @brief SPI_TXE_INT_TypeDef SPI TXE_INT
 * @{
 */
typedef enum
{
  SPI_TXE_DISINT = (uint8_t)0x00, /*!< TXE为0时不允许发送中断 */
  SPI_TXE_ENINT  = (uint8_t)0x08  /*!< TXE为1时允许发送中断 */
} SPI_TXE_INT_TypeDef;
/**
 * @}
 */

/** @brief UART1_Mode_TypeDef UART1 Mode
 * @{
 */
typedef enum
{
  UART1_Mode_10B  = 0X00,/*!< UART1设置为10位模式 */
  UART1_Mode_11B  = 0X80 /*!< UART1设置为11位模式 */
} UART1_Mode_TypeDef;
/**
 * @}
 */

/** @brief UART1_RX_TypeDef UART1 RX
 * @{
 */
typedef enum
{
  UART1_RX_ENABLE  = 0X10,/*!< UART1允许接收 */
  UART1_RX_DISABLE = 0X00 /*!< UART1禁止接收 */
} UART1_RX_TypeDef;
/**
 * @}
 */

/** @brief SSI_Flag_TypeDef SSI Flag
 * @{
 */
typedef enum
{
  SPI_FLAG_SPIF    = (uint8_t)0x80, /*!< SPI数据传送标志位SPIF */
  SPI_FLAG_WCOL    = (uint8_t)0x40, /*!< SPI写入冲突标志位WCOL */
  SPI_FLAG_TXE     = (uint8_t)0x08, /*!< SPI发送缓存器空标志TXE */
  TWI_FLAG_TWIF    = (uint8_t)0x40,	/*!< TWI中断标志位TWIF */
  TWI_FLAG_GCA	   = (uint8_t)0x10,	/*!< TWI通用地址响应标志位GCA */
  UART1_FLAG_TI	   = (uint8_t)0x02,	/*!< UART1发送中断标志位TI */
  UART1_FLAG_RI	   = (uint8_t)0x01	/*!< UART1接收中断标志位RI */
} SSI_Flag_TypeDef;
/**
 * @}
 */

/** @brief SSI_StatusTypeDef SSI Status
 * @{
 */
typedef enum
{
  SSI_STATE_READY = 0x00,   /*!< 准备标志 */
  SSI_STATE_BUSY = 0x01,    /*!< 忙碌标志 */
  SSI_STATE_ERROR = 0x02,   /*!< 错误标志 */
  SSI_STATE_TIMEOUT = 0x03, /*!< 超时标志 */
  SSI_STATE_WAIT = 0x04,    /*!< 等待标志 */
} SSI_StatusTypeDef;
/**
 * @}
 */

/** @brief SSI_HandleInfoDef SSI Handle Information
 * @{
 */
typedef struct __SSI_HandleInfoDef
{
  union
  {
    uint8_t* Size_u8;             /*!< 8位数据发送缓存区 */
    uint16_t* Size_u16;           /*!< 16位数据发送缓存区 */
  } pTxBuffPtr;
  uint8_t TxXferSize;              /*!< 数据发送量 */
  uint8_t TxXferCount;             /*!< 数据发送计数器 */
  union
  {
    uint8_t* Size_u8;              /*!< 8位数据接收缓存区 */
    uint16_t* Size_u16;            /*!< 16位数据接收缓存区 */
  } pRxBuffPtr;
  uint8_t RxXferSize;              /*!< 数据接收量 */
  uint8_t RxXferCount;             /*!< 数据接收计数器大小 */
  SSI_StatusTypeDef TxState;       /*!< 发送状态 */
  SSI_StatusTypeDef RxState;       /*!< 接收状态 */ 
} SSI_HandleInfoDef;
/**
 * @}
 */

#if defined (SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)
/** @brief SSI_PortMappingPin_TypeDef SSI Port Mapping Pins
 * @{
 */
typedef enum
{
  SSIMapped_to_P50 = (uint8_t)0x00, /*!< SSI端口映射到P50 */
  SSIMapped_to_P51 = (uint8_t)0x01, /*!< SSI端口映射到P51 */
  SSIMapped_to_P52 = (uint8_t)0x02, /*!< SSI端口映射到P52 */
  SSIMapped_to_P53 = (uint8_t)0x03, /*!< SSI端口映射到P53 */
	SSIMapped_to_P54 = (uint8_t)0x04, /*!< SSI端口映射到P54 */
	SSIMapped_to_P56 = (uint8_t)0x06, /*!< SSI端口映射到P56 */
  SSIMapped_to_P57 = (uint8_t)0x07, /*!< SSI端口映射到P57 */
  SSIMapped_to_P10 = (uint8_t)0x08, /*!< SSI端口映射到P10 */
  SSIMapped_to_P11 = (uint8_t)0x09, /*!< SSI端口映射到P11 */
	SSIMapped_to_P12 = (uint8_t)0x0A, /*!< SSI端口映射到P12 */
	SSIMapped_to_P13 = (uint8_t)0x0B, /*!< SSI端口映射到P13 */
  SSIMapped_to_P14 = (uint8_t)0x0C, /*!< SSI端口映射到P14 */
  SSIMapped_to_P15 = (uint8_t)0x0D, /*!< SSI端口映射到P15 */
  SSIMapped_to_P16 = (uint8_t)0x0E, /*!< SSI端口映射到P16 */
	SSIMapped_to_P17 = (uint8_t)0x0F, /*!< SSI端口映射到P17 */
	SSIMapped_to_P27 = (uint8_t)0x10, /*!< SSI端口映射到P27 */
  SSIMapped_to_P26 = (uint8_t)0x11, /*!< SSI端口映射到P26 */
  SSIMapped_to_P25 = (uint8_t)0x12, /*!< SSI端口映射到P25 */
  SSIMapped_to_P24 = (uint8_t)0x13, /*!< SSI端口映射到P24 */
	SSIMapped_to_P23 = (uint8_t)0x14, /*!< SSI端口映射到P23 */
	SSIMapped_to_P22 = (uint8_t)0x15, /*!< SSI端口映射到P22 */
	SSIMapped_to_P21 = (uint8_t)0x16, /*!< SSI端口映射到P21 */
	SSIMapped_to_P20 = (uint8_t)0x17, /*!< SSI端口映射到P20 */
  SSIMapped_to_P07 = (uint8_t)0x18, /*!< SSI端口映射到P07 */
	SSIMapped_to_P06 = (uint8_t)0x19, /*!< SSI端口映射到P06 */
	SSIMapped_to_P05 = (uint8_t)0x1A, /*!< SSI端口映射到P05 */
  SSIMapped_to_P04 = (uint8_t)0x1B, /*!< SSI端口映射到P04 */
  SSIMapped_to_P03 = (uint8_t)0x1C, /*!< SSI端口映射到P03 */
  SSIMapped_to_P02 = (uint8_t)0x1D, /*!< SSI端口映射到P02 */
	SSIMapped_to_P01 = (uint8_t)0x1E, /*!< SSI端口映射到P01 */
	SSIMapped_to_P00 = (uint8_t)0x1F, /*!< SSI端口映射到P00 */
} SSI_PortMappingPin_TypeDef;
#elif defined(SC92F5x5x)
typedef enum
{
  SSIMapped_to_P00 = (uint8_t)0x00, /*!< SSI映射到P00 */
  SSIMapped_to_P01 = (uint8_t)0x01, /*!< SSI映射到P01 */
	SSIMapped_to_P05 = (uint8_t)0x05, /*!< SSI映射到P05 */
	SSIMapped_to_P20 = (uint8_t)0x08, /*!< SSI映射到P20 */
	SSIMapped_to_P21 = (uint8_t)0x09, /*!< SSI映射到P21 */
	SSIMapped_to_P22 = (uint8_t)0x0A, /*!< SSI映射到P22 */
  SSIMapped_to_P23 = (uint8_t)0x0B, /*!< SSI映射到P23 */
  SSIMapped_to_P24 = (uint8_t)0x0C, /*!< SSI映射到P24 */
  SSIMapped_to_P25 = (uint8_t)0x0D, /*!< SSI映射到P25 */
	SSIMapped_to_P26 = (uint8_t)0x0E, /*!< SSI映射到P26 */
	SSIMapped_to_P13 = (uint8_t)0x14, /*!< SSI映射到P13 */
  SSIMapped_to_P12 = (uint8_t)0x15, /*!< SSI映射到P12 */
  SSIMapped_to_P11 = (uint8_t)0x16, /*!< SSI映射到P11 */
  SSIMapped_to_P10 = (uint8_t)0x19, /*!< SSI映射到P10 */
} SSI_PortMappingPin_TypeDef;
#elif defined(SC92F531x)
typedef enum
{
  SSIMapped_to_P00 = (uint8_t)0x00, /*!< SSI映射到P00 */
  SSIMapped_to_P01 = (uint8_t)0x01, /*!< SSI映射到P01 */
  SSIMapped_to_P02 = (uint8_t)0x02, /*!< SSI映射到P02 */
  SSIMapped_to_P03 = (uint8_t)0x03, /*!< SSI映射到P03 */
	SSIMapped_to_P04 = (uint8_t)0x04, /*!< SSI映射到P04 */
	SSIMapped_to_P05 = (uint8_t)0x05, /*!< SSI映射到P05 */
	SSIMapped_to_P06 = (uint8_t)0x06, /*!< SSI映射到P06 */
  SSIMapped_to_P07 = (uint8_t)0x07, /*!< SSI映射到P07 */
	SSIMapped_to_P20 = (uint8_t)0x08, /*!< SSI映射到P20 */
	SSIMapped_to_P21 = (uint8_t)0x09, /*!< SSI映射到P21 */
	SSIMapped_to_P22 = (uint8_t)0x0A, /*!< SSI映射到P22 */
	SSIMapped_to_P23 = (uint8_t)0x0B, /*!< SSI映射到P23 */
  SSIMapped_to_P24 = (uint8_t)0x0C, /*!< SSI映射到P24 */
  SSIMapped_to_P25 = (uint8_t)0x0D, /*!< SSI映射到P25 */
  SSIMapped_to_P26 = (uint8_t)0x0E, /*!< SSI映射到P26 */
	SSIMapped_to_P27 = (uint8_t)0x0F, /*!< SSI映射到P27 */
	SSIMapped_to_P15 = (uint8_t)0x12, /*!< SSI映射到P15 */
  SSIMapped_to_P14 = (uint8_t)0x13, /*!< SSI映射到P14 */
  SSIMapped_to_P13 = (uint8_t)0x14, /*!< SSI映射到P13 */
  SSIMapped_to_P12 = (uint8_t)0x15, /*!< SSI映射到P12 */
	SSIMapped_to_P11 = (uint8_t)0x16, /*!< SSI映射到P11 */
	SSIMapped_to_P10 = (uint8_t)0x19, /*!< SSI映射到P10 */
} SSI_PortMappingPin_TypeDef;
#elif defined(SC92F637x)
typedef enum
{
  SSIMapped_to_P00 = (uint8_t)0x00, /*!< SSI映射到P00 */
  SSIMapped_to_P01 = (uint8_t)0x01, /*!< SSI映射到P01 */
  SSIMapped_to_P02 = (uint8_t)0x02, /*!< SSI映射到P02 */
  SSIMapped_to_P03 = (uint8_t)0x03, /*!< SSI映射到P03 */
	SSIMapped_to_P04 = (uint8_t)0x04, /*!< SSI映射到P04 */
	SSIMapped_to_P05 = (uint8_t)0x05, /*!< SSI映射到P05 */
	SSIMapped_to_P20 = (uint8_t)0x06, /*!< SSI映射到P20 */
	SSIMapped_to_P21 = (uint8_t)0x07, /*!< SSI映射到P21 */
  SSIMapped_to_P24 = (uint8_t)0x08, /*!< SSI映射到P24 */
  SSIMapped_to_P25 = (uint8_t)0x09, /*!< SSI映射到P25 */
  SSIMapped_to_P26 = (uint8_t)0x0A, /*!< SSI映射到P26 */
	SSIMapped_to_P27 = (uint8_t)0x0B, /*!< SSI映射到P27 */
	SSIMapped_to_P15 = (uint8_t)0x0C, /*!< SSI映射到P15 */
  SSIMapped_to_P14 = (uint8_t)0x0D, /*!< SSI映射到P14 */
  SSIMapped_to_P13 = (uint8_t)0x0E, /*!< SSI映射到P13 */
  SSIMapped_to_P12 = (uint8_t)0x0F, /*!< SSI映射到P12 */
	SSIMapped_to_P11 = (uint8_t)0x10, /*!< SSI映射到P11 */
	SSIMapped_to_P10 = (uint8_t)0x11, /*!< SSI映射到P10 */
} SSI_PortMappingPin_TypeDef;
#elif defined(SC92F563x)
typedef enum
{
  SSIMapped_to_P02 = (uint8_t)0x00, /*!< SSI映射到P02 */
  SSIMapped_to_P54 = (uint8_t)0x01, /*!< SSI映射到P54 */
  SSIMapped_to_P55 = (uint8_t)0x02, /*!< SSI映射到P55 */
  SSIMapped_to_P47 = (uint8_t)0x03, /*!< SSI映射到P47 */
	SSIMapped_to_P43 = (uint8_t)0x04, /*!< SSI映射到P43 */
	SSIMapped_to_P42 = (uint8_t)0x05, /*!< SSI映射到P42 */
	SSIMapped_to_P41 = (uint8_t)0x06, /*!< SSI映射到P41 */
	SSIMapped_to_P22 = (uint8_t)0x07, /*!< SSI映射到P22 */
  SSIMapped_to_P23 = (uint8_t)0x08, /*!< SSI映射到P23 */
  SSIMapped_to_P24 = (uint8_t)0x08, /*!< SSI映射到P24 */
  SSIMapped_to_P25 = (uint8_t)0x09, /*!< SSI映射到P25 */
  SSIMapped_to_P26 = (uint8_t)0x0A, /*!< SSI映射到P26 */
} SSI_PortMappingPin_TypeDef;
/**
 * @}
 */
#endif

#if defined (SC92F7003) || defined (SC92F8003) || defined(SC92F8003B) || defined (SC92F740x) || defined(SC92F84Hx) || defined(SC92F83Hx)
#if defined (SC92F7003) || defined (SC92F8003) || defined(SC92F8003B) || defined (SC92F740x)
/** @brief SSI_PinSelection_TypeDef SSI PinSelection
 * @{
 */
typedef enum
{
  SSI_PinSelection_P10P27P26 = (uint8_t)0x00, 		   /*!< SSI共用引脚为P10，P27，P26 */
  SSI_PinSelection_P21P22P23 = (uint8_t)0x20, 		   /*!< SSI共用引脚为P21，P22，P23 */
  SSI_PinSelection_URATP27 = (uint8_t)0x00,  		   /*!< SSIUART引脚为P27,无RX */
  SSI_PinSelection_URATP22 = (uint8_t)0x20  		   /*!< SSIUART引脚为P22,无RX */
} SSI_PinSelection_TypeDef;
/**
 * @}
 */
#else 
/** @brief SSI_PinSelection_TypeDef PinSelection
 * @{
 */
typedef enum
{
  SSI_SPI_PinRemap_Defalut  = (uint8_t)0x00,     /*!< SPI引脚为默认引脚 */
  SSI_SPI_PinRemap_A = (uint8_t)0x02, 		     /*!< SPI引脚为A组引脚 */
	SSI_UART_PinRemap_Defalut  = (uint8_t)0x00,  /*!< UART引脚为默认引脚 */
  SSI_UART_PinRemap_A = (uint8_t)0x02, 		     /*!< UART引脚为A组引脚 */
	SSI_TWI_PinRemap_Defalut  = (uint8_t)0x00,   /*!< TWI引脚为默认引脚 */
  SSI_TWI_PinRemap_A = (uint8_t)0x02, 		     /*!< TWI引脚为A组引脚 */	
} SSI_PinSelection_TypeDef;
/**
 * @}
 */
#endif
/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/
void SSI_PinSelection(SSI_PinSelection_TypeDef PinSeletion);
#endif

/** @addtogroup SSI_Functions SSI Functions
 * @{
 */
void SSI_DeInit(void);
/********************************* SPI **************************************************/
void SSI_SPI_Init(SPI_FirstBit_TypeDef FirstBit,
                  SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler,
                  SPI_Mode_TypeDef Mode,
                  SPI_ClockPolarity_TypeDef ClockPolarity,
                  SPI_ClockPhase_TypeDef ClockPhase,
                  SPI_TXE_INT_TypeDef SPI_TXE_INT);
void SSI_SPI_Cmd(FunctionalState NewState);
void SSI_SPI_SendData(uint8_t Data);
uint8_t SSI_SPI_ReceiveData(void);

StatusTypeDef SSI_SPI_Receive(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI_SPI_Transmit(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI_SPI_TransmitReceive(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pTxData, uint8_t* pRxData, uint8_t Size, uint32_t Timeout);

StatusTypeDef SSI_SPI_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE);
StatusTypeDef SSI_SPI_Receive_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI_SPI_Transmit_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI_SPI_TransmitReceive_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pTxData, uint8_t* pRxData, uint8_t Size);


/********************************* TWI **************************************************/
void SSI_TWI_Init(uint8_t TWI_Address);
void SSI_TWI_AcknowledgeConfig(FunctionalState NewState);
void SSI_TWI_GeneralCallCmd(FunctionalState NewState);
FlagStatus SSI_GetTWIStatus(SSI_TWIState_TypeDef SSI_TWIState);
FlagStatus SSI_GetFlagStatus(SSI_Flag_TypeDef SSI_FLAG);
void SSI_TWI_Cmd(FunctionalState NewState);
void SSI_TWI_SendData(uint8_t Data);
uint8_t SSI_TWI_ReceiveData(void);
StatusTypeDef SSI_TWI_Wait_TWIF(SSI_HandleInfoDef* SSI_HANDLE, uint32_t Timeout);
StatusTypeDef SSI_TWI_Slave_Transmit(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI_TWI_Slave_Transmit_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI_TWI_Slave_Transmit_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE);

StatusTypeDef SSI_TWI_Slave_Receive(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI_TWI_Slave_Receive_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI_TWI_Slave_Receive_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE);

/********************************* UART **************************************************/
void SSI_UART1_Init(uint32_t UART1Fsys,
                    uint32_t BaudRate, UART1_Mode_TypeDef Mode,
                    UART1_RX_TypeDef RxMode);
void SSI_UART1_SendData8(uint8_t Data);
uint8_t SSI_UART1_ReceiveData8(void);
void SSI_UART1_SendData9(uint16_t Data);
uint16_t SSI_UART1_ReceiveData9(void);
StatusTypeDef SSI_UART_Transmit(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI_UART_Transmit_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI_UART_Transmit_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE);
StatusTypeDef SSI_UART_Receive(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI_UART_Receive_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI_UART1_Receive_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE);

/********************************* 标志位相关 **************************************************/
void SSI_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority);
void SSI_ClearFlag(SSI_Flag_TypeDef SSI_FLAG);

#if defined (SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)|| defined(SC92F5x5x)|| defined(SC92F531x) || defined (SC92F563x)
/******************************* SSI端口映射相关 ***********************************************/
void SSI_PortMapping(SSI_PortMappingPin_TypeDef SSICK_MappingPin,
	                   SSI_PortMappingPin_TypeDef SSITX_MappingPin,
										 SSI_PortMappingPin_TypeDef SSIRX_MappingPin);
#endif
/**
 * @}
 */
/* End of functions --------------------------------------------------*/
#endif

#if defined (SC92F742x) || defined (SC92F7490)
/** @defgroup SSI_Enumerations SSI Enumerations
 * @{
 */

/** @brief SPI_FirstBit_TypeDef SPI FirstBit
 * @{
 */
typedef enum
{
  SPI_FIRSTBIT_MSB = (uint8_t)0x00,			/*!< MSB优先发送 */
  SPI_FIRSTBIT_LSB = (uint8_t)0x04			/*!< LSB优先发送 */
} SPI_FirstBit_TypeDef;
/**
 * @}
 */

/** @brief SPI_BaudRatePrescaler_TypeDef SPI BaudRate Prescaler
 * @{
 */
typedef enum
{
  SPI_BAUDRATEPRESCALER_1   = (uint8_t)0x00,	/*!< SPI时钟速率为系统时钟除以1 */
  SPI_BAUDRATEPRESCALER_2   = (uint8_t)0x01,	/*!< SPI时钟速率为系统时钟除以2 */
  SPI_BAUDRATEPRESCALER_4   = (uint8_t)0x02,	/*!< SPI时钟速率为系统时钟除以4 */
  SPI_BAUDRATEPRESCALER_8   = (uint8_t)0x03,	/*!< SPI时钟速率为系统时钟除以8 */
  SPI_BAUDRATEPRESCALER_16  = (uint8_t)0x04,	/*!< SPI时钟速率为系统时钟除以16*/
  SPI_BAUDRATEPRESCALER_32  = (uint8_t)0x05,	/*!< SPI时钟速率为系统时钟除以32*/
  SPI_BAUDRATEPRESCALER_64  = (uint8_t)0x06,	/*!< SPI时钟速率为系统时钟除以64*/
  SPI_BAUDRATEPRESCALER_128 = (uint8_t)0x07 	/*!< SPI时钟速率为系统时钟除以128*/
} SPI_BaudRatePrescaler_TypeDef;
/**
 * @}
 */

/** @brief SPI_Mode_TypeDef SPI Mode
 * @{
 */
typedef enum
{
  SPI_MODE_MASTER = (uint8_t)0x20,			/*!< SPI为主设备 */
  SPI_MODE_SLAVE  = (uint8_t)0x00			/*!< SPI为从设备 */
} SPI_Mode_TypeDef;
/**
 * @}
 */

/** @brief SPI_ClockPolarity_TypeDef SPI Clock Polarity
 * @{
 */
typedef enum
{
  SPI_CLOCKPOLARITY_LOW  = (uint8_t)0x00,	/*!< SCK在空闲状态下为低电平 */
  SPI_CLOCKPOLARITY_HIGH = (uint8_t)0x10  	/*!< SCK在空闲状态下为高电平 */
} SPI_ClockPolarity_TypeDef;
/**
 * @}
 */

/** @brief SPI_Mode_TypeDef SPI Mode
 * @{
 */
typedef enum
{
  SPI_CLOCKPHASE_1EDGE = (uint8_t)0x00,		/*!< SCK的第一沿采集数据 */
  SPI_CLOCKPHASE_2EDGE = (uint8_t)0x08		/*!< SCK的第二沿采集数据 */
} SPI_ClockPhase_TypeDef;
/**
 * @}
 */

/** @brief SPI_TXE_INT_TypeDef SPI TXE_INT
 * @{
 */
typedef enum
{
  SPI_TXE_DISINT = (uint8_t)0x00, 			/*!< TXE为0时不允许发送中断 */
  SPI_TXE_ENINT  = (uint8_t)0x01  			/*!< TXE为1时允许发送中断 */
} SPI_TXE_INT_TypeDef;
/**
 * @}
 */

/** @brief UART1_Mode_TypeDef UART1 Mode
 * @{
 */
typedef enum
{ 
  UART_Mode_10B  = 0X00,				    /*!< UART设置为10位模式 */ 
  UART_Mode_11B  = 0X80						/*!< UART设置为11位模式 */ 
} UART_Mode_TypeDef;
/**
 * @}
 */

/** @brief UART_RX_TypeDef UART RX
 * @{
 */
typedef enum
{
  UART_RX_ENABLE  = 0X10,						/*!< UART允许接收 */
  UART_RX_DISABLE = 0X00						/*!< UART禁止接收 */
} UART_RX_TypeDef;
/**
 * @}
 */

/** @brief SSI_TWIState_TypeDef TWI State
 * @{
 */
typedef enum
{
  //作为从机
  TWI_SlaveIdle = 0x00,
  TWI_SlaveReceivedaAddress = 0x01,
  TWI_SlaveReceivedaData = 0x02,
  TWI_SlaveSendData = 0x03,
  TWI_SlaveReceivedaUACK = 0x04,
  TWI_SlaveDisableACK = 0x05,
  TWI_SlaveAddressError = 0x06,

} SSI_TWIState_TypeDef;
/**
 * @}
 */

/** @brief SPI_TXE_INT_TypeDef SPI TXE_INT
 * @{
 */
typedef enum
{
  SPI_FLAG_SPIF    = (uint8_t)0x80,				/*!< SPI数据传送标志位SPIF */
  SPI_FLAG_WCOL    = (uint8_t)0x40, 			/*!< SPI写入冲突标志位WCOL */
  SPI_FLAG_TXE     = (uint8_t)0x08,  			/*!< SPI发送缓存器空标志TXE */
  TWI_FLAG_TWIF    = (uint8_t)0x40,				/*!< TWI中断标志位TWIF */
  TWI_FLAG_GCA	   = (uint8_t)0x10,				/*!< TWI通用地址响应标志位GCA */
  UART_FLAG_TI	   = (uint8_t)0x02,				/*!< UART发送中断标志位TI */
  UART_FLAG_RI	   = (uint8_t)0x01				/*!< UART接收中断标志位RI */
} SSI_Flag_TypeDef;
/**
 * @}
 */

/** @brief SSI_StatusTypeDef SSI Status
 * @{
 */
typedef enum
{
  SSI_STATE_READY = 0x00,   /*!< 准备标志 */
  SSI_STATE_BUSY = 0x01,    /*!< 忙碌标志 */
  SSI_STATE_ERROR = 0x02,   /*!< 错误标志 */
  SSI_STATE_TIMEOUT = 0x03, /*!< 超时标志 */
  SSI_STATE_WAIT = 0x04,    /*!< 等待标志 */
} SSI_StatusTypeDef;
/**
 * @}
 */

/** @brief SSI_HandleInfoDef SSI Handle Information
 * @{
 */
typedef struct __SSI_HandleInfoDef
{
  union
  {
    uint8_t* Size_u8;             /*!< 8位数据发送缓存区 */
    uint16_t* Size_u16;           /*!< 16位数据发送缓存区 */
  } pTxBuffPtr;
  uint8_t TxXferSize;             /*!< 数据发送量 */
  uint8_t TxXferCount;            /*!< 数据发送计数器 */
  union
  {
    uint8_t* Size_u8;             /*!< 8位数据接收缓存区 */
    uint16_t* Size_u16;           /*!< 16位数据接收缓存区 */
  } pRxBuffPtr;
  uint8_t RxXferSize;             /*!< 数据接收量 */
  uint8_t RxXferCount;            /*!< 数据接收计数器大小 */
  SSI_StatusTypeDef TxState;      /*!< 发送状态 */
  SSI_StatusTypeDef RxState;      /*!< 接收状态 */ 
} SSI_HandleInfoDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup SSI_Functions SSI Functions
 * @{
 */
void SSI0_DeInit(void);
/********************************* SPI **************************************************/
void SSI0_SPI_Init(SPI_FirstBit_TypeDef FirstBit,
                   SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler,
                   SPI_Mode_TypeDef Mode,
                   SPI_ClockPolarity_TypeDef ClockPolarity,
                   SPI_ClockPhase_TypeDef ClockPhase,
                   SPI_TXE_INT_TypeDef SPI_TXE_INT);
void SSI0_SPI_Cmd(FunctionalState NewState);
void SSI0_SPI_SendData(uint8_t Data);
uint8_t SSI0_SPI_ReceiveData(void);
StatusTypeDef SSI0_SPI_Receive(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI0_SPI_Transmit(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI0_SPI_TransmitReceive(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pTxData, uint8_t* pRxData, uint8_t Size, uint32_t Timeout);

StatusTypeDef SSI0_SPI_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE);
StatusTypeDef SSI0_SPI_Receive_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI0_SPI_Transmit_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI0_SPI_TransmitReceive_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pTxData, uint8_t* pRxData, uint8_t Size);

/********************************* TWI **************************************************/
void SSI0_TWI_Init(uint8_t TWI_Address);
void SSI0_TWI_AcknowledgeConfig(FunctionalState NewState);
void SSI0_TWI_GeneralCallCmd(FunctionalState NewState);
FlagStatus SSI0_GetTWIStatus(SSI_TWIState_TypeDef SSI_TWIState);
void SSI0_TWI_Cmd(FunctionalState NewState);
void SSI0_TWI_SendData(uint8_t Data);
uint8_t SSI0_TWI_ReceiveData(void);
StatusTypeDef SSI0_TWI_Wait_TWIF(SSI_HandleInfoDef* SSI_HANDLE, uint32_t Timeout);
StatusTypeDef SSI0_TWI_Slave_Transmit(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI0_TWI_Slave_Transmit_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI0_TWI_Slave_Transmit_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE);

StatusTypeDef SSI0_TWI_Slave_Receive(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI0_TWI_Slave_Receive_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI0_TWI_Slave_Receive_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE);

/********************************* UART **************************************************/
void SSI0_UART_Init(uint32_t UARTFsys,
                    uint32_t BaudRate, UART_Mode_TypeDef Mode,
                    UART_RX_TypeDef RxMode);
void SSI0_UART_SendData8(uint8_t Data);
uint8_t SSI0_UART_ReceiveData8(void);
void SSI0_UART_SendData9(uint16_t Data);
uint16_t SSI0_UART_ReceiveData9(void);
StatusTypeDef SSI0_UART_Transmit(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI0_UART_Transmit_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI0_UART_Transmit_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE);
StatusTypeDef SSI0_UART_Receive(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI0_UART_Receive_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);

StatusTypeDef SSI0_UART_Receive_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE);
void SSI0_ITConfig(FunctionalState NewState,
                   PriorityStatus Priority);
FlagStatus SSI0_GetFlagStatus(SSI_Flag_TypeDef SSI_FLAG);
void SSI0_ClearFlag(SSI_Flag_TypeDef SSI_FLAG);


void SSI1_DeInit(void);
/********************************* SPI **************************************************/
void SSI1_SPI_Init(SPI_FirstBit_TypeDef FirstBit,
                   SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler,
                   SPI_Mode_TypeDef Mode,
                   SPI_ClockPolarity_TypeDef ClockPolarity,
                   SPI_ClockPhase_TypeDef ClockPhase,
                   SPI_TXE_INT_TypeDef SPI_TXE_INT);
void SSI1_SPI_Cmd(FunctionalState NewState);
void SSI1_SPI_SendData(uint8_t Data);
uint8_t SSI1_SPI_ReceiveData(void);

StatusTypeDef SSI1_SPI_Receive(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI1_SPI_Transmit(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI1_SPI_TransmitReceive(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pTxData, uint8_t* pRxData, uint8_t Size, uint32_t Timeout);

StatusTypeDef SSI1_SPI_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE);
StatusTypeDef SSI1_SPI_Receive_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI1_SPI_Transmit_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI1_SPI_TransmitReceive_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pTxData, uint8_t* pRxData, uint8_t Size);

/********************************* TWI **************************************************/
void SSI1_TWI_Init(uint8_t TWI_Address);
void SSI1_TWI_AcknowledgeConfig(FunctionalState NewState);
void SSI1_TWI_GeneralCallCmd(FunctionalState NewState);
FlagStatus SSI1_GetTWIStatus(SSI_TWIState_TypeDef SSI_TWIState);
void SSI1_TWI_Cmd(FunctionalState NewState);
void SSI1_TWI_SendData(uint8_t Data);
uint8_t SSI1_TWI_ReceiveData(void);
StatusTypeDef SSI1_TWI_Wait_TWIF(SSI_HandleInfoDef* SSI_HANDLE, uint32_t Timeout);
StatusTypeDef SSI1_TWI_Slave_Transmit(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI1_TWI_Slave_Transmit_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI1_TWI_Slave_Transmit_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE);

StatusTypeDef SSI1_TWI_Slave_Receive(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI1_TWI_Slave_Receive_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI1_TWI_Slave_Receive_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE);

/********************************* UART **************************************************/
void SSI1_UART_Init(uint32_t UARTFsys,
                    uint32_t BaudRate, UART_Mode_TypeDef Mode,
                    UART_RX_TypeDef RxMode);
void SSI1_UART_SendData8(uint8_t Data);
uint8_t SSI1_UART_ReceiveData8(void);
void SSI1_UART_SendData9(uint16_t Data);
uint16_t SSI1_UART_ReceiveData9(void);
StatusTypeDef SSI1_UART_Transmit(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI1_UART_Transmit_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI1_UART_Transmit_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE);
StatusTypeDef SSI1_UART_Receive(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef SSI1_UART_Receive_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef SSI1_UART_Receive_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE);
void SSI1_ITConfig(FunctionalState NewState,
                   PriorityStatus Priority);
FlagStatus SSI1_GetFlagStatus(SSI_Flag_TypeDef SSI_FLAG);
void SSI1_ClearFlag(SSI_Flag_TypeDef SSI_FLAG);
/**
 * @}
 */
/* End of exported functions --------------------------------------------------*/
#endif

#endif
/**
 * @}
 */

/**
 * @}
 */
/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/