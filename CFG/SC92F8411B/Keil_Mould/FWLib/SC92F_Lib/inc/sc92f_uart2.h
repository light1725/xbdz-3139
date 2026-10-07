/**
 ******************************************************************************
 * @file    sc92f_uart2.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of UART2 module.
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
#ifndef _sc92f_UART2_H_
#define	_sc92f_UART2_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @addtogroup UART2
 * @{
 */

///仅模式0可用，串行端口在系统时钟的1/12下运行
#define UART2_BaudRate_FsysDIV12 0X00 
///仅模式0可用，串行端口在系统时钟的1/4下运行
#define UART2_BaudRate_FsysDIV4 0X01  
 
#if defined (SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x) || defined (SC92F663x)
/** @defgroup UART2_Enumerations UART2 Enumerations
 * @{
 */

/** @brief UART2_Mode_Typedef UART2 Mode
 * @{
 */
#if defined (SC92F663x)
typedef enum
{
	UART2_Mode_8B = 0X00,
  UART2_Mode_10B = 0X40,		/*!< UART工作模式:10位全双工 */
  UART2_Mode_11B = 0XC0,  	    /*!< UART工作模式:11位全双工 */
}UART2_Mode_Typedef;
#else
typedef enum
{
  UART2_Mode_10B = 0X00,		/*!< UART工作模式:10位全双工 */
  UART2_Mode_11B = 0X80,  	    /*!< UART工作模式:11位全双工 */
}UART2_Mode_Typedef;
#endif
/**
 * @}
 */

/** @brief UART2_RX_Typedef UART2 RX
 * @{
 */
typedef enum
{
  UART2_RX_ENABLE  = 0x10,      /*!< 允许接收数据 */
  UART2_RX_DISABLE = 0x00	    /*!< 不允许接收数据 */
} UART2_RX_Typedef;
/**
 * @}
 */

/** @brief UART2_Flag_Typedef UART2 Flag
 * @{
 */
typedef enum
{
  UART2_FLAG_RI = 0X01,		/*!< 接收中断标志位RI */
  UART2_FLAG_TI = 0X02	    /*!< 发送中断标志位TI */
} UART2_Flag_Typedef;
/**
 * @}
 */

/** @brief UART2_StatusTypeDef UART2 Status
 * @{
 */
typedef enum
{
  UART2_STATE_READY = 0x00,   /*!< 准备标志 */
  UART2_STATE_BUSY = 0x01,    /*!< 忙碌标志 */
  UART2_STATE_ERROR = 0x02,   /*!< 错误标志 */
  UART2_STATE_TIMEOUT = 0x03  /*!< 超时标志 */
} UART2_StatusTypeDef; 
/**
 * @}
 */

/** @brief UART2_HandleInfoDef UART2 Handle
 * @{
 */
typedef struct __UART2_HandleInfoDef
{
  union
  {
    uint8_t* Size_u8;             /*!< 8位数据发送缓存区 */
    uint16_t* Size_u16;           /*!< 16位数据发送缓存区 */
  } pTxBuffPtr;					  /*!< 指向UART2 Tx传输缓冲区的指针 */
  uint8_t TxXferSize;             /*!< 数据发送量大小 */
  uint8_t TxXferCount;            /*!< 数据发送计数器 */
  union
  {
    uint8_t* Size_u8;             /*!< 8位数据接收缓存区 */
    uint16_t* Size_u16;           /*!< 16位数据接收缓存区 */
  } pRxBuffPtr;				      /*!< 指向UART2 Rx传输缓冲区的指针 */
  uint8_t RxXferSize;             /*!< 数据接收量 */
  uint8_t RxXferCount;            /*!< 数据接收计数器大小 */
  UART2_StatusTypeDef TxState;    /*!< 发送状态 */
  UART2_StatusTypeDef RxState;    /*!< 接收状态 */
} UART2_HandleInfoDef;
/**
 * @}
 */

#if defined (SC92F663x)
/** @brief UART2_PortMappingPin_TypeDef UART2 Mapping Pins
 * @{
 */
typedef enum
{
	UART2TX_Mapped_to_P02 = (uint8_t)0x00, /*!< UART2TX 映射到P02 */
  UART2TX_Mapped_to_P03 = (uint8_t)0x01, /*!< UART2TX 映射到P03 */
  UART2TX_Mapped_to_P52 = (uint8_t)0x02, /*!< UART2TX 映射到P52 */
  UART2TX_Mapped_to_P53 = (uint8_t)0x03, /*!< UART2TX 映射到P53 */
	UART2TX_Mapped_to_P26 = (uint8_t)0x04, /*!< UART2TX 映射到P26 */
	UART2TX_Mapped_to_P27 = (uint8_t)0x05, /*!< UART2TX 映射到P27 */
  UART2TX_Mapped_to_P00 = (uint8_t)0x06, /*!< UART2TX 映射到P00 */
  UART2TX_Mapped_to_P01 = (uint8_t)0x07, /*!< UART2TX 映射到P01 */
  UART2RX_Mapped_to_P02 = (uint8_t)0x10, /*!< UART2RX 映射到P02 */
  UART2RX_Mapped_to_P03 = (uint8_t)0x11, /*!< UART2RX 映射到P03 */
  UART2RX_Mapped_to_P52 = (uint8_t)0x12, /*!< UART2RX 映射到P52 */
  UART2RX_Mapped_to_P53 = (uint8_t)0x13, /*!< UART2RX 映射到P53 */
	UART2RX_Mapped_to_P26 = (uint8_t)0x14, /*!< UART2RX 映射到P26 */
	UART2RX_Mapped_to_P27 = (uint8_t)0x15, /*!< UART2RX 映射到P27 */
  UART2RX_Mapped_to_P00 = (uint8_t)0x16, /*!< UART2RX 映射到P00 */
  UART2RX_Mapped_to_P01 = (uint8_t)0x17, /*!< UART2RX 映射到P01 */
} UART2_PortMappingPin_TypeDef;
/**
 * @}
 */
#endif

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup BTM_Exported_Functions BTM Exported Functions
 * @{
 */

/*macro function********************************************************/
/**
 * @brief  获得UART2中断标志状态
 * @param  UART2_Flag[in]:中断标志位选择
 *          - UART2_FLAG_RI:接收中断标志位RI
 *          - UART2_FLAG_TI:发送中断标志位TI
 * @retval UART2中断标志位置起状态
 *                  - RESET:置零
 *                  - SET:置起
 */ 
#define UART2_GetFlagStatus(UART2_Flag) ((UART2_Flag == UART2_FLAG_TI) ? (TI):(RI))

void UART2_DeInit(void);
void UART2_Init(uint32_t Uart2Fsys,
                uint32_t BaudRate, 
								UART2_Mode_Typedef Mode,
                UART2_RX_Typedef RxMode);
#if defined (SC92F663x)
void UART2_PortMapping(UART2_PortMappingPin_TypeDef UART2_MappingPin);
#endif
/* UART2 Base functions ********************************************************/
void UART2_SendData8(uint8_t Data);
uint8_t UART2_ReceiveData8(void);
void UART2_SendData9(uint16_t Data);
uint16_t UART2_ReceiveData9(void);

StatusTypeDef UART2_Transmit(UART2_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef UART2_Transmit_IT(UART2_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef UART2_Transmit_IRQHandler(UART2_HandleInfoDef* UART_HANDLE);

StatusTypeDef UART2_Receive(UART2_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef UART2_Receive_IT(UART2_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef UART2_Receive_IRQHandler(UART2_HandleInfoDef* UART_HANDLE);
/* Interrupts and flags management functions  **********************************************/
void UART2_ITConfig(FunctionalState NewState,
                    PriorityStatus Priority);
void UART2_ClearFlag(UART2_Flag_Typedef UART2_FLAG);
/**
 * @}
 */
/* End of UART2 Functions.	*/
#endif

#endif
/**
 * @}
 */

/**
 * @}
 */
/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/
