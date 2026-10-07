/**
 ******************************************************************************
 * @file    sc92f_uart0.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of UART0 module.
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
#ifndef _sc92f_UART0_H_
#define	_sc92f_UART0_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @addtogroup UART0
 * @{
 */
 
#if !defined (SC92F742x) && !defined (SC92F827X) && !defined (SC92F837X)

#if !defined (SC92F6x1x) && !defined (SC92F5x1x) && !defined (SC92R436)&& !defined (SC92R438)&& !defined (SC92R439)&& !defined (SC92R422A)
///仅模式0可用，串行端口在系统时钟的1/12下运行
#define  UART0_BaudRate_FsysDIV12    0X00	
///仅模式0可用，串行端口在系统时钟的1/4下运行
#define  UART0_BaudRate_FsysDIV4	 0X01
///仅模式1可用，串行端口在系统时钟的1/64下运行
#define  UART0_BaudRate_FsysDIV64   0X00 
///仅模式1可用，串行端口在系统时钟的1/32下运行
#define  UART0_BaudRate_FsysDIV32   0X01 
#else
///仅模式0可用，串行端口在系统时钟的1/12下运行
#define  UART0_BaudRate_FsysDIV12    0X00
///仅模式0可用，串行端口在系统时钟的1/4下运行
#define  UART0_BaudRate_FsysDIV4	 0X01
///仅模式1可用，串行端口在系统时钟的1/1下运行
#define  UART0_BaudRate_FsysDIV1   0X00 
///仅模式1可用，串行端口在系统时钟的1/16下运行
#define  UART0_BaudRate_FsysDIV16   0X01 
#endif

/** @defgroup UART0_Enumerations UART0 Enumerations
 * @{
 */

#if defined (SC92F7003) || defined (SC92F8003) || defined(SC92F8003B) || defined (SC92F740x)
/** @brief UART0_PinSelection_TypeDef UART0 PinSelection
 * @{
 */
typedef enum
{
  UART0_PinSelection_P15P16 = (uint8_t)0x00,  /*!< UART0引脚为P15，P16 */
  UART0_PinSelection_P15 = (uint8_t)0x00,     /*!< UART0引脚为P15，P16，无RX */
  UART0_PinSelection_P11P20 = (uint8_t)0x10,  /*!< UART0引脚为P11，P20 */
  UART0_PinSelection_P20 = (uint8_t)0x10,     /*!< UART0引脚为P20，无RX */
} UART0_PinSelection_TypeDef;
#elif defined(SC92F84Hx) || defined(SC92F83Hx)
typedef enum
{
  UART0_PinRemap_Default = (uint8_t)0x00, /*!< UART0引脚为默认引脚 */
  UART0_PinRemap_A = (uint8_t)0x10,       /*!< UART0引脚为A组引脚 */
  UART0_PinRemap_B = (uint8_t)0x20,       /*!< UART0引脚为B组引脚 */
} UART0_PinSelection_TypeDef;
#endif
/**
 * @}
 */

#if defined (SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)
/** @brief UART0_PortMappingPin_TypeDef UART0 Port Mapping Pins
 * @{
 */
typedef enum
{
  UART0TX_Mapped_to_P50 = (uint8_t)0x00, /*!< UART0TX映射到P50 */
  UART0TX_Mapped_to_P51 = (uint8_t)0x01, /*!< UART0TX映射到P51 */
  UART0TX_Mapped_to_P52 = (uint8_t)0x02, /*!< UART0TX映射到P52 */
  UART0TX_Mapped_to_P53 = (uint8_t)0x03, /*!< UART0TX映射到P53 */
	UART0TX_Mapped_to_P54 = (uint8_t)0x04, /*!< UART0TX映射到P54 */
	UART0TX_Mapped_to_P56 = (uint8_t)0x06, /*!< UART0TX映射到P56 */
  UART0TX_Mapped_to_P57 = (uint8_t)0x07, /*!< UART0TX映射到P57 */
  UART0TX_Mapped_to_P10 = (uint8_t)0x08, /*!< UART0TX映射到P10 */
  UART0TX_Mapped_to_P11 = (uint8_t)0x09, /*!< UART0TX映射到P11 */
	UART0TX_Mapped_to_P12 = (uint8_t)0x0A, /*!< UART0TX映射到P12 */
	UART0TX_Mapped_to_P13 = (uint8_t)0x0B, /*!< UART0TX映射到P13 */
  UART0TX_Mapped_to_P14 = (uint8_t)0x0C, /*!< UART0TX映射到P14 */
  UART0TX_Mapped_to_P15 = (uint8_t)0x0D, /*!< UART0TX映射到P15 */
  UART0TX_Mapped_to_P16 = (uint8_t)0x0E, /*!< UART0TX映射到P16 */
	UART0TX_Mapped_to_P17 = (uint8_t)0x0F, /*!< UART0TX映射到P17 */
	UART0TX_Mapped_to_P27 = (uint8_t)0x10, /*!< UART0TX映射到P27 */
  UART0TX_Mapped_to_P26 = (uint8_t)0x11, /*!< UART0TX映射到P26 */
  UART0TX_Mapped_to_P25 = (uint8_t)0x12, /*!< UART0TX映射到P25 */
  UART0TX_Mapped_to_P24 = (uint8_t)0x13, /*!< UART0TX映射到P24 */
	UART0TX_Mapped_to_P23 = (uint8_t)0x14, /*!< UART0TX映射到P23 */
	UART0TX_Mapped_to_P22 = (uint8_t)0x15, /*!< UART0TX映射到P22 */
  UART0TX_Mapped_to_P21 = (uint8_t)0x16, /*!< UART0TX映射到P21 */
  UART0TX_Mapped_to_P20 = (uint8_t)0x17, /*!< UART0TX映射到P20 */
  UART0TX_Mapped_to_P07 = (uint8_t)0x18, /*!< UART0TX映射到P07 */
	UART0TX_Mapped_to_P06 = (uint8_t)0x19, /*!< UART0TX映射到P06 */
	UART0TX_Mapped_to_P05 = (uint8_t)0x1A, /*!< UART0TX映射到P05 */
  UART0TX_Mapped_to_P04 = (uint8_t)0x1B, /*!< UART0TX映射到P04 */
  UART0TX_Mapped_to_P03 = (uint8_t)0x1C, /*!< UART0TX映射到P03 */
  UART0TX_Mapped_to_P02 = (uint8_t)0x1D, /*!< UART0TX映射到P02 */
	UART0TX_Mapped_to_P01 = (uint8_t)0x1E, /*!< UART0TX映射到P01 */
	UART0TX_Mapped_to_P00 = (uint8_t)0x1F, /*!< UART0TX映射到P00 */
	
	UART0RX_Mapped_to_P50 = (uint8_t)0x80, /*!< UART0RX映射到P50 */
  UART0RX_Mapped_to_P51 = (uint8_t)0x81, /*!< UART0RX映射到P51 */
  UART0RX_Mapped_to_P52 = (uint8_t)0x82, /*!< UART0RX映射到P52 */
  UART0RX_Mapped_to_P53 = (uint8_t)0x83, /*!< UART0RX映射到P53 */
	UART0RX_Mapped_to_P54 = (uint8_t)0x84, /*!< UART0RX映射到P54 */
	UART0RX_Mapped_to_P56 = (uint8_t)0x86, /*!< UART0RX映射到P56 */
  UART0RX_Mapped_to_P57 = (uint8_t)0x87, /*!< UART0RX映射到P57 */
  UART0RX_Mapped_to_P10 = (uint8_t)0x88, /*!< UART0RX映射到P10 */
  UART0RX_Mapped_to_P11 = (uint8_t)0x89, /*!< UART0RX映射到P11 */
	UART0RX_Mapped_to_P12 = (uint8_t)0x8A, /*!< UART0RX映射到P12 */
	UART0RX_Mapped_to_P13 = (uint8_t)0x8B, /*!< UART0RX映射到P13 */
  UART0RX_Mapped_to_P14 = (uint8_t)0x8C, /*!< UART0RX映射到P14 */
  UART0RX_Mapped_to_P15 = (uint8_t)0x8D, /*!< UART0RX映射到P15 */
  UART0RX_Mapped_to_P16 = (uint8_t)0x8E, /*!< UART0RX映射到P16 */
	UART0RX_Mapped_to_P17 = (uint8_t)0x8F, /*!< UART0RX映射到P17 */
	UART0RX_Mapped_to_P27 = (uint8_t)0x90, /*!< UART0RX映射到P27 */
  UART0RX_Mapped_to_P26 = (uint8_t)0x91, /*!< UART0RX映射到P26 */
  UART0RX_Mapped_to_P25 = (uint8_t)0x92, /*!< UART0RX映射到P25 */
  UART0RX_Mapped_to_P24 = (uint8_t)0x93, /*!< UART0RX映射到P24 */
	UART0RX_Mapped_to_P23 = (uint8_t)0x94, /*!< UART0RX映射到P23 */
	UART0RX_Mapped_to_P22 = (uint8_t)0x95, /*!< UART0RX映射到P22 */
  UART0RX_Mapped_to_P21 = (uint8_t)0x96, /*!< UART0RX映射到P21 */
  UART0RX_Mapped_to_P20 = (uint8_t)0x97, /*!< UART0RX映射到P20 */
  UART0RX_Mapped_to_P07 = (uint8_t)0x98, /*!< UART0RX映射到P07 */
	UART0RX_Mapped_to_P06 = (uint8_t)0x99, /*!< UART0RX映射到P06 */
	UART0RX_Mapped_to_P05 = (uint8_t)0x9A, /*!< UART0RX映射到P05 */
  UART0RX_Mapped_to_P04 = (uint8_t)0x9B, /*!< UART0RX映射到P04 */
  UART0RX_Mapped_to_P03 = (uint8_t)0x9C, /*!< UART0RX映射到P03 */
  UART0RX_Mapped_to_P02 = (uint8_t)0x9D, /*!< UART0RX映射到P02 */
	UART0RX_Mapped_to_P01 = (uint8_t)0x9E, /*!< UART0RX映射到P01 */
	UART0RX_Mapped_to_P00 = (uint8_t)0x9F, /*!< UART0RX映射到P00 */
} UART0_PortMappingPin_TypeDef;

#elif defined (SC92F531x)
typedef enum
{
  UART0TX_Mapped_to_P00 = (uint8_t)0x00, /*!< UART0TX映射到P00 */
  UART0TX_Mapped_to_P01 = (uint8_t)0x01, /*!< UART0TX映射到P01 */
  UART0TX_Mapped_to_P02 = (uint8_t)0x02, /*!< UART0TX映射到P02 */
  UART0TX_Mapped_to_P03 = (uint8_t)0x03, /*!< UART0TX映射到P03 */
	UART0TX_Mapped_to_P04 = (uint8_t)0x04, /*!< UART0TX映射到P04 */
	UART0TX_Mapped_to_P05 = (uint8_t)0x05, /*!< UART0TX映射到P05 */
	UART0TX_Mapped_to_P06 = (uint8_t)0x06, /*!< UART0TX映射到P06 */
  UART0TX_Mapped_to_P07 = (uint8_t)0x07, /*!< UART0TX映射到P07 */
  UART0TX_Mapped_to_P20 = (uint8_t)0x08, /*!< UART0TX映射到P20 */
  UART0TX_Mapped_to_P21 = (uint8_t)0x09, /*!< UART0TX映射到P21 */
	UART0TX_Mapped_to_P22 = (uint8_t)0x0A, /*!< UART0TX映射到P22 */
	UART0TX_Mapped_to_P23 = (uint8_t)0x0B, /*!< UART0TX映射到P23 */
  UART0TX_Mapped_to_P24 = (uint8_t)0x0C, /*!< UART0TX映射到P24 */
  UART0TX_Mapped_to_P25 = (uint8_t)0x0D, /*!< UART0TX映射到P25 */
  UART0TX_Mapped_to_P26 = (uint8_t)0x0E, /*!< UART0TX映射到P26 */
	UART0TX_Mapped_to_P27 = (uint8_t)0x0F, /*!< UART0TX映射到P27 */
	UART0TX_Mapped_to_P15 = (uint8_t)0x12, /*!< UART0TX映射到P15 */
  UART0TX_Mapped_to_P14 = (uint8_t)0x13, /*!< UART0TX映射到P14 */
	UART0TX_Mapped_to_P13 = (uint8_t)0x14, /*!< UART0TX映射到P13 */
	UART0TX_Mapped_to_P12 = (uint8_t)0x15, /*!< UART0TX映射到P12 */
	UART0TX_Mapped_to_P11 = (uint8_t)0x16, /*!< UART0TX映射到P11 */
	UART0TX_Mapped_to_P10 = (uint8_t)0x19, /*!< UART0TX映射到P10 */
	
	UART0RX_Mapped_to_P00 = (uint8_t)0x80, /*!< UART0RX映射到P00 */
  UART0RX_Mapped_to_P01 = (uint8_t)0x81, /*!< UART0RX映射到P01 */
  UART0RX_Mapped_to_P02 = (uint8_t)0x82, /*!< UART0RX映射到P02 */
  UART0RX_Mapped_to_P03 = (uint8_t)0x83, /*!< UART0RX映射到P03 */
	UART0RX_Mapped_to_P04 = (uint8_t)0x84, /*!< UART0RX映射到P04 */
	UART0RX_Mapped_to_P05 = (uint8_t)0x85, /*!< UART0RX映射到P05 */
	UART0RX_Mapped_to_P06 = (uint8_t)0x86, /*!< UART0RX映射到P06 */
  UART0RX_Mapped_to_P07 = (uint8_t)0x87, /*!< UART0RX映射到P07 */
  UART0RX_Mapped_to_P20 = (uint8_t)0x88, /*!< UART0RX映射到P20 */
  UART0RX_Mapped_to_P21 = (uint8_t)0x89, /*!< UART0RX映射到P21 */
	UART0RX_Mapped_to_P22 = (uint8_t)0x8A, /*!< UART0RX映射到P22 */
	UART0RX_Mapped_to_P23 = (uint8_t)0x8B, /*!< UART0RX映射到P23 */
  UART0RX_Mapped_to_P24 = (uint8_t)0x8C, /*!< UART0RX映射到P24 */
  UART0RX_Mapped_to_P25 = (uint8_t)0x8D, /*!< UART0RX映射到P25 */
  UART0RX_Mapped_to_P26 = (uint8_t)0x8E, /*!< UART0RX映射到P26 */
	UART0RX_Mapped_to_P27 = (uint8_t)0x8F, /*!< UART0RX映射到P27 */
	UART0RX_Mapped_to_P15 = (uint8_t)0x92, /*!< UART0RX映射到P15 */
  UART0RX_Mapped_to_P14 = (uint8_t)0x93, /*!< UART0RX映射到P14 */
	UART0RX_Mapped_to_P13 = (uint8_t)0x94, /*!< UART0RX映射到P13 */
	UART0RX_Mapped_to_P12 = (uint8_t)0x95, /*!< UART0RX映射到P12 */
	UART0RX_Mapped_to_P11 = (uint8_t)0x96, /*!< UART0RX映射到P11 */
	UART0RX_Mapped_to_P10 = (uint8_t)0x99, /*!< UART0RX映射到P10 */
} UART0_PortMappingPin_TypeDef;
/**
 * @}
 */
#endif

/** @brief UART0_Clock_Typedef UART0 Clock
 * @{
 */
#if  defined(SC92F725X) || defined(SC92F735X)|| defined (SC92F730x ) || defined (SC92F732X) || defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x)\
    || defined (SC92F730x_2) || defined(SC92F720x)|| defined (SC92F7308B) 
typedef enum
{
  UART0_CLOCK_TIMER1 = (uint8_t)0X02,	          /*!< TIMER1做波特率发生器 */
  UART0_CLOCK_TIMER1_FreqMcl2 = (uint8_t)0X82,    /*!< TIMER1做波特率发生器,且二倍频 */
  UART0_CLOCK_TIMER1_DIV6 = (uint8_t)0X80,        /*!< TIMER1做波特率发生器,且6分频 */
  UART0_CLOCK_TIMER1_DIV12 = (uint8_t)0X00,       /*!< TIMER1做波特率发生器,且12分频 */
  UART0_CLOCK_TIMER2 = (uint8_t)0X34,	          /*!< TIMER2做波特率发生器 */
  UART0_CLOCK_TIMER2_DIV12 = (uint8_t)0X30,		  /*!< 定时器2 12分频，模式1和3通用  */
}UART0_Clock_Typedef;
#elif defined (SC92F848x) || defined (SC92F748x) || defined(SC92F859x) || defined(SC92F759x) || defined(SC92L853x) || defined(SC92L753x)\
		|| defined (SC92R511x) || defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)\
		|| defined (SC92R422A) || defined (SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x) || defined (SC92F663x) || defined (SC92F563x)
typedef enum
{
	UART0_CLOCK_TIMER1 = (uint8_t)0X00,	     /*!< TIMER1做波特率发生器 */
  UART0_CLOCK_TIMER2 = (uint8_t)0X30,	     /*!< TIMER2做波特率发生器 */
	UART0_CLOCK_TIMER1_DIV16 = (uint8_t)0X80,	/*!< TIMER1做波特率发生器 */
  UART0_CLOCK_TIMER2_DIV16 = (uint8_t)0XB0,	/*!< TIMER2做波特率发生器 */
}UART0_Clock_Typedef;
#else
typedef enum
{
  //模式0和3的定时器选择
  UART0_CLOCK_TIMER1 = (uint8_t)0X00,	/*!< TIMER1做波特率发生器 */
  UART0_CLOCK_TIMER2 = (uint8_t)0X30,	/*!< TIMER2做波特率发生器 */
}UART0_Clock_Typedef;	 
#endif
/**
 * @}
 */

/** @brief UART0_Mode_Typedef UART0 Mode
 * @{
 */
#if defined (SC92F730x) || defined (SC92F725X) || defined (SC92F735X) || defined (SC92F732X) || defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x)\
  || defined (SC92F730x_2) || defined(SC92F720x) ||defined (SC92F7308B)
typedef enum
{
  UART0_Mode_8B  = 0X00,		/*!< UART工作模式:8位半双工 */
  UART0_Mode_10B = 0X40,	    /*!< UART工作模式:10位全双工 */
  UART0_Mode_11B = 0XC0,  	    /*!< UART工作模式:11位全双工 */
  UART0_Mode_11B_BaudRateFix = 80/*!< UART工作模式:11位全双工,波特率固定 */
}UART0_Mode_Typedef;
#else
typedef enum
{
  UART0_Mode_8B  = 0X00,		/*!< UART工作模式:8位半双工 */
  UART0_Mode_10B = 0X40,		/*!< UART工作模式:10位全双工 */
  UART0_Mode_11B = 0XC0,  	    /*!< UART工作模式:11位全双工 */
}UART0_Mode_Typedef;
#endif
/**
 * @}
 */

/** @brief UART0_RX_Typedef UART0 RX
 * @{
 */
typedef enum
{
  UART0_RX_ENABLE  = 0x10,      /*!< 允许接收数据 */
  UART0_RX_DISABLE = 0x00	    /*!< 不允许接收数据 */
} UART0_RX_Typedef;
/**
 * @}
 */

/** @brief UART0_Flag_Typedef UART0 Flag
 * @{
 */
typedef enum
{
  UART0_FLAG_RI = 0X01,		/*!< 接收中断标志位RI */
  UART0_FLAG_TI = 0X02	    /*!< 发送中断标志位TI */
} UART0_Flag_Typedef;
/**
 * @}
 */

/** @brief UART0_StatusTypeDef UART0 Status
 * @{
 */
typedef enum
{
  UART0_STATE_READY = 0x00,   /*!< 准备标志 */
  UART0_STATE_BUSY = 0x01,    /*!< 忙碌标志 */
  UART0_STATE_ERROR = 0x02,   /*!< 错误标志 */
  UART0_STATE_TIMEOUT = 0x03  /*!< 超时标志 */
} UART0_StatusTypeDef; 
/**
 * @}
 */

/** @brief UART0_HandleInfoDef UART0 Handle
 * @{
 */
typedef struct __UART0_HandleInfoDef
{
  union
  {
    uint8_t* Size_u8;             /*!< 8位数据发送缓存区 */
    uint16_t* Size_u16;           /*!< 16位数据发送缓存区 */
  } pTxBuffPtr;					  /*!< 指向UART0 Tx传输缓冲区的指针 */
  uint8_t TxXferSize;             /*!< 数据发送量大小 */
  uint8_t TxXferCount;            /*!< 数据发送计数器 */
  union
  {
    uint8_t* Size_u8;             /*!< 8位数据接收缓存区 */
    uint16_t* Size_u16;           /*!< 16位数据接收缓存区 */
  } pRxBuffPtr;				      /*!< 指向UART0 Rx传输缓冲区的指针 */
  uint8_t RxXferSize;             /*!< 数据接收量 */
  uint8_t RxXferCount;            /*!< 数据接收计数器大小 */
  UART0_StatusTypeDef TxState;    /*!< 发送状态 */
  UART0_StatusTypeDef RxState;    /*!< 接收状态 */
} UART0_HandleInfoDef;
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
 * @brief  获得UART0中断标志状态
 * @param  UART0_Flag[in]:中断标志位选择
 *          - UART0_FLAG_RI:接收中断标志位RI
 *          - UART0_FLAG_TI:发送中断标志位TI
 * @retval UART0中断标志位置起状态
 *                  - RESET:置零
 *                  - SET:置起
 */ 
#define UART0_GetFlagStatus(UART0_Flag) ((UART0_Flag == UART0_FLAG_TI) ? (TI):(RI))

/**
 * @brief  清除UART0中断标志状态
 * @param  UART0_Flag[in]:UART0
 *          - UART0_FLAG_RI:接收中断标志位RI
 *          - UART0_FLAG_TI:发送中断标志位TI
 * @retval None
 */ 
#define UART0_ClearFlag(UART0_Flag) ((UART0_Flag == UART0_FLAG_TI) ? (TI=0):(RI=0))

void UART0_DeInit(void);
void UART0_Init(uint32_t Uart0Fsys,
                uint32_t BaudRate, UART0_Mode_Typedef Mode,
                UART0_Clock_Typedef ClockMode,
                UART0_RX_Typedef RxMode);
#if defined (SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)|| defined (SC92F531x)
void UART0_PortMapping(UART0_PortMappingPin_TypeDef UART0_MappingPin);
#endif
/* UART0 Base functions ********************************************************/
void UART0_SendData8(uint8_t Data);
uint8_t UART0_ReceiveData8(void);
void UART0_SendData9(uint16_t Data);
uint16_t UART0_ReceiveData9(void);

StatusTypeDef UART0_Transmit(UART0_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef UART0_Transmit_IT(UART0_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef UART0_Transmit_IRQHandler(UART0_HandleInfoDef* UART_HANDLE);

StatusTypeDef UART0_Receive(UART0_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout);
StatusTypeDef UART0_Receive_IT(UART0_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size);
StatusTypeDef UART0_Receive_IRQHandler(UART0_HandleInfoDef* UART_HANDLE);
/* Interrupts and flags management functions  **********************************************/
void UART0_ITConfig(FunctionalState NewState,
                    PriorityStatus Priority);

#if defined (SC92F8003) || defined(SC92F8003B) || defined (SC92F740x)  || defined (SC92F7003) || defined(SC92F84Hx) || defined(SC92F83Hx)
void UART0_PinSelection(UART0_PinSelection_TypeDef PinSeletion);
#endif
/**
 * @}
 */
/* End of UART0 Functions.	*/
#endif

#endif
/**
 * @}
 */

/**
 * @}
 */
/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/
