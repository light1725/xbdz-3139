/**
 ******************************************************************************
 * @file    sc92f_uart3.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   UART3 function module
 *******************************************************************************
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
#include "sc92f_uart3.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup UART3
 * @brief UART3 driver modules
 * @{
 */

/** @defgroup UART3_Functions
 * @{
 */
 
#if defined (SC92F663x) || defined (SC92F563x)
/** @defgroup UART3_Group1 Configuration of the UART3 computation unit functions
 *  @brief   Configuration of the UART3 computation unit functions
 *
 
@verbatim
 ===============================================================================
                     ##### UART3 configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  UART3相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void UART3_DeInit(void)
{
#if defined (SC92F663x)
	TMCON |= 0X80;
#endif
	UXCON = 0X00;
  IE2 &= 0XFD;
  IP2 &= 0XFD;
}

/**
 * @brief  UART3初始化配置函数
 * @param  Uart2Fsys[in]:系统时钟频率
 * @param  BaudRate[in]:波特率
 * @param  Mode[in]:工作模式
 *          - UART3_Mode_10B:UART3工作模式:10位全双工
 *          - UART3_Mode_11B:UART3工作模式:11位全双工
 * @param  RxMode[in]:接收允许选择
 *          - UART3_RX_ENABLE:允许接收数据
 *          - UART3_RX_DISABLE:不允许接收数据
 * @retval None
 */
void UART3_Init(uint32_t Uart3Fsys, 
								uint32_t BaudRate,
                UART3_Mode_Typedef Mode,
                UART3_RX_Typedef RxMode)
{
#if defined (SC92F663x)
	TMCON |= 0X80;  //UART控制寄存器指针指向UART3
#endif
	UXCON  = (UXCON & 0X2F) | Mode | RxMode;	//设置UART工作模式,设置接收允许位

	/* 配置UART3波特率 */
	UXBAUDH = (Uart3Fsys / BaudRate) / 256;
	UXBAUDL = (Uart3Fsys / BaudRate) % 256;
}

/**
 * @}
 */
/* End of UART3_Group1.	*/

/** @defgroup UART3_Group2 Base functions
 *  @brief   UART3 functions
 *
@verbatim
 ===============================================================================
                     ##### Base functions #####
 ===============================================================================
@endverbatim
  * @{
  */


/**
 * @brief  UART3发送8位数据
 * @param  Data[in]:UART3发送8位数据
 * @retval None
 */
void UART3_SendData8(uint8_t Data)
{
#if defined (SC92F663x)
	TMCON |= 0X80;  //UART控制寄存器指针指向UART3
#endif
  UXSBUF = Data;
}

/**
 * @brief  获得SBUF中的值
 * @param  None
 * @retval UART接收到的8位数据
 */
uint8_t UART3_ReceiveData8(void)
{
#if defined (SC92F663x)
	TMCON |= 0X80;  //UART控制寄存器指针指向UART3
#endif
  return UXSBUF;
}

/**
 * @brief  UART3发送9位数据
 * @param  Data[in]:发送的数据
 * @retval None
 */
void UART3_SendData9(uint16_t Data)
{
  uint8_t Data_9Bit;
  Data_9Bit = (Data >> 8);
	
#if defined (SC92F663x)
	TMCON |= 0X80;  //UART控制寄存器指针指向UART3
#endif

  if(Data_9Bit)
  {
    UXCON |= 0X08;
  }
  else
  {
    UXCON &= 0XF7;
  }

  UXSBUF = (uint8_t)Data;
}

/**
 * @brief  获得SBUF中的值及第九位的值
 * @param  None
 * @retval UART接收到的数据
 */
uint16_t UART3_ReceiveData9(void)
{
  uint16_t Data9;
#if defined (SC92F663x)
	TMCON |= 0X80;  //UART控制寄存器指针指向UART3
#endif
  Data9 =  UXSBUF + (((uint16_t)(UXCON & 0X04) & 0X00FF) << 6);
  UXCON &= 0XFB;
  return Data9;
}

/**
 * @brief  UART在轮询模式下发送大量数据
 * @param  UART_HANDLE[out]:指向包含指定UART模块的配置信息结构体的指针
 * @param  pData[out]:接收数据的存放区
 * @param  Size[in]:待接收的数据量
 * @param  timeout[in]:超时时间设置
 * @retval SSI 状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef UART3_Transmit(UART3_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout)
{
    uint32_t TimeoutCnt;
#if defined (SC92F663x)
		TMCON |= 0X80;  //UART控制寄存器指针指向UART3
#endif
    /* 检查一个发送进程是否正在进行 */
    if (UART_HANDLE->TxState == UART3_STATE_READY)
    {
        /* 待发送数据长度必须大于0，否则返回错误状态 */
        if (Size == 0U)
        {
            return  Status_ERROR;
        }

        UART_HANDLE->TxState = UART3_STATE_BUSY;			//发送进程忙碌中
				UART3_ClearFlag(UART3_FLAG_TI); //发送前清除发送标志,写1清0
        UART_HANDLE->pTxBuffPtr.Size_u8 = pData;			//指向待发送数据的地址
        UART_HANDLE->TxXferSize = Size;			//更新待发送的数据量
        UART_HANDLE->TxXferCount = 0;			//发送计数器清零

        while (UART_HANDLE->TxXferCount < UART_HANDLE->TxXferSize)//判断是否接收所有数据
        {
            if (UXCON & 0xC0 == UART3_Mode_11B)
            {
                UXCON &= ~0x08;
                UXCON |= (*(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount) >> 5);//设置第9位校验位
                UXSBUF = *(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount);
            }
            else
            {
                UXSBUF = *(UART_HANDLE->pTxBuffPtr.Size_u8 + UART_HANDLE->TxXferCount);
            }

            while (!(UART3_GetFlagStatus(UART3_FLAG_TI))) //等待发送完成
            {
                if (TimeoutCnt++ > Timeout)
                {
                    UART_HANDLE->TxState = UART3_STATE_TIMEOUT;//发送超时
                    return Status_TIMEOUT;
                }
                WDTCON |= 0x10;;          //喂狗函数，防止看门狗复位
            }

            UART3_ClearFlag(UART3_FLAG_TI); //发送中断标志清除，写1清零
            TimeoutCnt = 0;
            UART_HANDLE->TxXferCount++;	//发送数据量计数
        }

        if (UART_HANDLE->TxXferCount == UART_HANDLE->TxXferSize)
        {
            UART_HANDLE->TxState = UART3_STATE_READY;	//发送完成
            return Status_OK;
        }
        else
        {
            UART_HANDLE->TxState = UART3_STATE_ERROR;//发生发送错误
            return Status_ERROR;
        }
    }
    else
    {
        return Status_BUSY;//返回忙碌状态
    }
}

/**
 * @brief  UART在中断模式下发送大量数据时，先在main函数中调用此函数
 * @param  UART_HANDLE[out]:指针指向UART数据信息存放区
 * @param  pData[out]:接收数据的存放区
 * @param  Size[in]:待接收的数据量
 * @param  timeout[in]:超时时间设置
 * @retval 函数执行状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef UART3_Transmit_IT(UART3_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size)
{
#if defined (SC92F663x)
		TMCON |= 0X80;  //UART控制寄存器指针指向UART3
#endif
    /* 检查一个发送进程是否正在进行 */
    if (UART_HANDLE->TxState == UART3_STATE_READY)
    {
        /* 没有开启UART3中断或发送数据量大小为0，返回错误 */
        if ((IE2&0x02 == 0) || (UART_HANDLE->TxXferSize == 0U))
        {
            return Status_ERROR;
        }

        UART_HANDLE->TxState = UART3_STATE_BUSY;			//发送进程忙碌中
        UART3_ClearFlag(UART3_FLAG_TI);  //发送前清除发送标志,写1清0
        UART_HANDLE->pTxBuffPtr.Size_u8 = pData;			//指向待发送数据的地址
        UART_HANDLE->TxXferSize = Size;			//更新待发送的数据量
        UART_HANDLE->TxXferCount = 0;			//发送计数器清零


        /* 发送第1帧数据 */
        if (UXCON & 0xC0 == UART3_Mode_11B)
        {
            UXCON |= (*(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount) >> 5) & 0x08;//设置第9位校验位
            UXSBUF = *(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount);
        }
        else
        {
            UXSBUF = *(UART_HANDLE->pTxBuffPtr.Size_u8 + UART_HANDLE->TxXferCount);
        }
        return Status_OK;
    }
    else
    {
        return Status_BUSY;//返回标志位
    }
}

/**
 * @brief  UART在中断模式下发送大量数据时，在中断服务函数中调用
 * @param  UART_HANDLE[out]:指向包含指定UART模块的配置信息结构体的指针
 * @retval 函数执行状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef UART3_Transmit_IRQHandler(UART3_HandleInfoDef* UART_HANDLE)
{
#if defined (SC92F663x)
		TMCON |= 0X80;  //UART控制寄存器指针指向UART3
#endif
    /* 处于发送线程 */
    if (UART_HANDLE->TxState == UART3_STATE_BUSY)
    {
        UART_HANDLE->TxXferCount++;
        /* 判断上一次发送是否是最后一次 */
        if (UART_HANDLE->TxXferCount < UART_HANDLE->TxXferSize)
        {
            /* 待发送数据量未为0，继续发送 */
            if (UXCON & 0xC0 == UART3_Mode_11B)
            {
                UXCON |= (*(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount) >> 5) & 0x08;//设置第9位校验位
                UXSBUF = *(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount);
            }
            else
            {
                UXSBUF = *(UART_HANDLE->pTxBuffPtr.Size_u8 + UART_HANDLE->TxXferCount);
            }
            return Status_BUSY;
        }
        else if (UART_HANDLE->TxXferCount == UART_HANDLE->TxXferSize)
        {
            /* 发送完成 */
            UART_HANDLE->TxState = UART3_STATE_READY;
            return Status_OK;
        }
        else
        {
            /* 发送数据量为0时还发送数据，返回错误 */
            UART_HANDLE->TxState = UART3_STATE_ERROR;
            return Status_ERROR;
        }
    }
    else
    {
        return Status_ERROR;
    }
}

/**
 * @brief  UART在轮询模式下接收大量数据
 * @param  UART_HANDLE[out]:指针指向UART数据信息存放区
 * @param  pData[out]:接收数据的存放区
 * @param  Size[in]:待接收的数据量
 * @param  timeout[in]:超时时间设置
 * @retval 函数执行状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef UART3_Receive(UART3_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout)
{
    uint32_t TimeoutCnt = 0;
#if defined (SC92F663x)
		TMCON |= 0X80;  //UART控制寄存器指针指向UART3
#endif
    /* 检查接收进程正在运行 */
    if (UART_HANDLE->RxState == UART3_STATE_READY)
    {
        /* 检查接收数据量大小和是否开启接收使能 */
        if ((UART_HANDLE->RxXferSize == 0U) || ((UXCON & 0x10) == UART3_RX_ENABLE))
        {
            return  Status_ERROR;
        }

        UART_HANDLE->RxState = UART3_STATE_BUSY;			//状态更新为接收忙碌中
        UART3_ClearFlag(UART3_FLAG_RI);			 //接收前清除接收中断标志
        UART_HANDLE->pRxBuffPtr.Size_u8 = pData;			//指向待发送数据的地址
        UART_HANDLE->RxXferSize = Size;			//更新待发送的数据量
        UART_HANDLE->RxXferCount = 0;			//发送计数器清零

        while (UART_HANDLE->RxXferCount < UART_HANDLE->RxXferSize) //判断是否接收所有数据
        {
            if (UART3_GetFlagStatus(UART3_FLAG_RI)) //判断接收标志位
            {
                if (UXCON & 0xC0 == UART3_Mode_11B)
                {
                    *(UART_HANDLE->pRxBuffPtr.Size_u16 + UART_HANDLE->RxXferCount) = UXSBUF + ((uint16_t)(UXCON & 0X04) << 6); //接收数据
                }
                else
                {
                    *(UART_HANDLE->pRxBuffPtr.Size_u8 + UART_HANDLE->RxXferCount) = UXSBUF;			//接收数据
                }
                UART3_ClearFlag(UART3_FLAG_RI);			//接收标志位清零
                UART_HANDLE->RxXferCount++;	//接收数据量计数加1
                TimeoutCnt = 0;//收到数据，超时计数清零
            }
            else
            {
                if (TimeoutCnt++ > Timeout)//计时溢出
                {
                    UART_HANDLE->RxState = UART3_STATE_TIMEOUT;//发送超时
                    return Status_TIMEOUT;
                }
                WDTCON |= 0x10;;			//喂狗，防止等待时间过长，导致WDT复位
            }
        }

        if (UART_HANDLE->RxXferCount == UART_HANDLE->RxXferSize)
        {
            UART_HANDLE->RxState = UART3_STATE_READY;	//接收完成
            return Status_OK;
        }
        else
        {
            UART_HANDLE->RxState = UART3_STATE_ERROR;//接收错误
            return Status_ERROR;
        }
    }
    else
    {
        return Status_BUSY;//返回标志位
    }
}

/**
 * @brief  UART在中断模式下接收大量数据时，先在main函数中调用此函数
 * @param  UART_HANDLE[out]:指针指向UART数据信息存放区
 * @param  pData[out]:接收数据的存放区
 * @param  Size[in]:待接收的数据量
 * @retval 函数执行状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef UART3_Receive_IT(UART3_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size)
{
#if defined (SC92F663x)
		TMCON |= 0X80;  //UART控制寄存器指针指向UART3
#endif
    /* 检查一个接收进程是否正在进行 */
    if (UART_HANDLE->RxState == UART3_STATE_READY)
    {
        /* 检查是否开启UART3中断或发送数据量大小为0或是否开启接收使能，返回错误 */
        if ((IE2&0x02 == 0) || (Size == 0U) || ((UXCON & 0x10) == UART3_RX_ENABLE))
        {
            return UART3_STATE_ERROR;
        }

        UART_HANDLE->RxState = UART3_STATE_BUSY;
        UART_HANDLE->pRxBuffPtr.Size_u8 = pData;			//指向接收数据的存放地址
        UART_HANDLE->RxXferSize = Size;			//更新待接收的数据量
        UART_HANDLE->RxXferCount = 0;			//发送计数器清零

        return Status_OK;
    }
    else
    {
        return Status_BUSY;//返回标志位
    }
}

/**
 * @brief  UART在中断模式下接收大量数据时，在中断服务函数中调用 注：该函数调用需要判断中断标志位是否置起
 * @param  UART_HANDLE[out]:指针指向SSI数据信息存放区
 * @retval 函数执行状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef UART3_Receive_IRQHandler(UART3_HandleInfoDef* UART_HANDLE)
{
#if defined (SC92F663x)
		TMCON |= 0X80;  //UART控制寄存器指针指向UART3
#endif
    /* 检查一个接收进程是否正在进行 */
    if (UART_HANDLE->RxState == UART3_STATE_BUSY)
    {
        /* 处于接收线程，检查待接收数据量是否为0 */
        if (UART_HANDLE->RxXferCount < UART_HANDLE->RxXferSize)
        {
            if (UXCON & 0xC0 == UART3_Mode_11B)
            {
                *(UART_HANDLE->pRxBuffPtr.Size_u16 + UART_HANDLE->RxXferCount) = UXSBUF + ((uint16_t)(UXCON & 0X04) << 6); //接收数据
            }
            else
            {
                *(UART_HANDLE->pRxBuffPtr.Size_u8 + UART_HANDLE->RxXferCount) = UXSBUF;			//接收数据
            }
            UART_HANDLE->RxXferCount++;
            /* 判断上一次发送是否是最后一次 */
            if (UART_HANDLE->RxXferCount == UART_HANDLE->RxXferSize)
            {
                /* 接收完成 */
                UART_HANDLE->RxState = UART3_STATE_READY;
                return Status_OK;
						}
            return Status_BUSY;
        }
        else
        {
            /* 接收数据量为0时还接收数据，返回错误 */
            UART_HANDLE->RxState = UART3_STATE_ERROR;
            return Status_ERROR;
        }
    }
    else
    {
        return Status_BUSY;
    }
}
/**
 * @}
 */
/* End of UART3_Group2.	*/

/** @defgroup UART3_Group3 Interrupts and flags management functions
 *  @brief   Interrupts and flags management functions
 *
@verbatim
 ===============================================================================
                     ##### Interrupts and flags management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  UART3中断初始化
 * @param  NewState[in]: 断使能/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @param  Priority[in]: 中断优先级选择
 *              - LOW:低
 *              - HIGH:高
 * @retval None
 */ 
void UART3_ITConfig(FunctionalState NewState,
                    PriorityStatus Priority)
{
  if(NewState == DISABLE)
  {
    IE2 &= 0XFD;
  }
  else
  {
    IE2 |= 0X02;
  }

  //设置中断优先级
  if(Priority == LOW)
  {
    IP2 &= 0XFD;
  }
  else
  {
    IP2 |= 0X02;
  }
}

/**
 * @brief  清除UART3标志状态
 * @param  UART3_FLAG[in]:所需清除的标志位
 *              - UART3_FLAG_TI:UART3发送中断标志位TI
 *              - UART3_FLAG_RI:UART3接收中断标志位RI
 * @retval None
 */
void UART3_ClearFlag(UART3_Flag_Typedef UART3_FLAG)
{
#if defined (SC92F663x)
	TMCON |= 0X80;  //UART控制寄存器指针指向UART3
#endif
	if(UART3_FLAG == UART3_FLAG_TI)
	{
		UXCON &= (~UART3_FLAG_RI);
	}
	else
	{
		UXCON &= (~UART3_FLAG_TI);
	}
}
/**
 * @}
 */
/* End of UART3_Group3.	*/

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