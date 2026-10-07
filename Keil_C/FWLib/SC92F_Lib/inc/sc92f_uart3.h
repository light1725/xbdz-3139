/**
 ******************************************************************************
 * @file    sc92f_uart3.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of UART3 module.
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
#ifndef _sc92f_UART3_H_
#define	_sc92f_UART3_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @addtogroup UART3
 * @{
 */
 
#if defined (SC92F663x) || defined (SC92F563x)
/** @defgroup UART3_Enumerations UART3 Enumerations
 * @{
 */

/** @brief UART3_Mode_Typedef UART3 Mode
 * @{
 */
typedef enum
{
	UART3_Mode_8B = 0X00,
  UART3_Mode_10B = 0X40,		/*!< UART工作模式:10位全双工 */
  UART3_Mode_11B = 0XC0,  	    /*!< UART工作模式:11位全双工 */
}UART3_Mode_Typedef;
/**
 * @}
 */

/** @brief UART3_RX_Typedef UART3 RX
 * @{
 */
typedef enum
{
  UART3_RX_ENABLE  = 0x10,      /*!< 允许接收数据 */
  UART3_RX_DISABLE = 0x00	    /*!< 不允许接收数据 */
} UART3_RX_Typedef;
/**
 * @}
 */

/** @brief UART3_Flag_Typedef UART3 Flag
 * @{
 */
typedef enum
{
  UART3_FLAG_RI = 0X01,		/*!< 接收中断标志位RI */
  UART3_FLAG_TI = 0X02	    /*!< 发送中断标志位TI */
} UART3_Flag_Typedef;
/**
 * @}
 */

/** @brief UART3_StatusTypeDef UART3 Status
 * @{
 */
typedef enum
{
  UART3_STATE_READY = 0x00,   /*!< 准备标志 */
  UART3_STATE_BUSY = 0x01,    /*!< 忙碌标志 */
  UART3_STATE_ERROR = 0x02,   /*!< 错误标志 */
  UART3_STATE_TIMEOUT = 0x03  /*!< 超时标志 */
} UART3_StatusTypeDef; 
/**
 * @}
 */

/** @brief UART3_HandleInfoDef UART3 Handle
 * @{
 */
typedef struct __UART3_HandleInfoDef
{
  union
  {
    uint8_t* Size_u8;             /*!< 8位数据发送缓存区 */
    uint16_t* Size_u16;           /*!< 16位数据发送缓存区 */
  } pTxBuffPtr;					  /*!< 指向UART3 Tx传输缓冲区的指针 */
  uint8_t TxXferSize;             /*!< 数据发送量大小 */
  uint8_t TxXferCount;            /*!< 数据发送计数器 */
  union
  {
    uint8_t* Size_u8;             /*!< 8位数据接收缓存区 */
    uint16_t* Size_u16;           /*!< 16位数据接收缓存区 */
  } pRxBuffPtr;				      /*!< 指向UART3 Rx传输缓冲区的指针 */
  uint8_t RxXferSize;             /*!< 数据接收量 */
  uint8_t RxXferCount;            /*!< 数据接收计数器大小 */
  UART3_StatusTypeDef TxState;    /*!< 发送状态 */
  UART3_StatusTypeDef RxState;    /*!< 接收状态 */
} UART3_HandleInfoDef;
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
 * @brief  获得UART3中断标志状态
 * @param  UART3_Flag[in]:中断标志位选择
 *          - UART3_FLAG_RI:接收中断标志位RI
 *          - UART3_FLAG_TI:发送中断标志位TI
 * @retval UART3中断标志位置起状态
 *                  - RESET:置零
 *                  - SET:置起
 */ 
#define UART3_GetFlagStatus(UART3_Flag) ((UART3_Flag == UART3_FLAG_TI) ? (TI):(RI))

void UART3_DeInit(void);
void UART3_Init(uint32_t Uart2Fsys,
                uint32_t BaudRate, 
								UART3_Mode_Typedef Mode,
                UART3_RX_Typedef RxMode);
/* UART3 Base functions ********************************************************/
void UART3_SendData8(uint8_t Data);
uint8_t UART3_ReceiveData8(void);
void UART3_SendData9(uint16_t Data);
uint16_t UART3_ReceiveData9(void);

StatusTypeDef UART3_Transmit(UART3_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef UART3_Transmit_IT(UART3_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef UART3_Transmit_IRQHandler(UART3_HandleInfoDef* UART_HANDLE);

StatusTypeDef UART3_Receive(UART3_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef UART3_Receive_IT(UART3_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef UART3_Receive_IRQHandler(UART3_HandleInfoDef* UART_HANDLE);
/* Interrupts and flags management functions  **********************************************/
void UART3_ITConfig(FunctionalState NewState,
                    PriorityStatus Priority);
void UART3_ClearFlag(UART3_Flag_Typedef UART3_FLAG);
/**
 * @}
 */
/* End of UART3 Functions.	*/
#endif

#endif
/**
 * @}
 */

/**
 * @}
 */
/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/
