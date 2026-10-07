/**
 ******************************************************************************
 * @file    sc92f_uart0.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   UART0 function module
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
 *  COPYRIGHT 202 5 SinOne Microelectronics
 ******************************************************************************
 */
 
/* Includes ------------------------------------------------------------------*/
#include "sc92f_uart0.h"

#if !defined (SC92F742x) && !defined (SC92F827X) && !defined (SC92F837X) && !defined (SC92F7490) && !defined (SC92F5x5x) && !defined (SC92F637x)
/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup UART0
 * @brief UART0 driver modules
 * @{
 */

/** @defgroup UART0_Functions
 * @{
 */
 
#if !defined (SC92F652x) && !defined(SC92R51x_R52x) && !defined(SC92F552x) && !defined(SC92F663x) && !defined(SC92F563x)

/** @defgroup UART0_Group1 Configuration of the UART0 computation unit functions
 *  @brief   Configuration of the UART0 computation unit functions
 *
 
@verbatim
 ===============================================================================
                     ##### UART0 configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */
 
 /**
 * @brief  UART0相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void UART0_DeInit(void)
{
#if defined (SC92F7003) || defined (SC92F8003) || defined (SC92F8003B) || defined (SC92F740x)
  OTCON &= 0XEF;
#elif defined(SC92F84Hx) || defined(SC92F83Hx)
	OTCON &= 0XCF;
#endif
  SCON = 0X00;
  PCON &= 0X7F;
  IE &= 0XEF;
  IP &= 0XEF;
}

#if defined (SC92F7003) || defined (SC92F8003) || defined (SC92F8003B) || defined (SC92F740x) || defined(SC92F84Hx) || defined(SC92F83Hx)
/**
 * @brief  UART0引脚选择
 * @param  PinSeletion[in]:配置计数初值
 *          - UART0_PinSelection_P15P16:UART0引脚为P15，P16
 *          - UART0_PinSelection_P15:UART0引脚为P15，P16，无RX
 *          - UART0_PinSelection_P11P20:UART0引脚为P11，P20
 *          - UART0_PinSelection_P20:UART0引脚为P20，无RX
 * @retval None
 */
void UART0_PinSelection(UART0_PinSelection_TypeDef
                        PinSeletion)
{
#if defined (SC92F7003) || defined (SC92F8003) || defined (SC92F8003B) || defined (SC92F740x)
  OTCON = OTCON & 0XDF | PinSeletion;
#elif defined(SC92F84Hx) || defined(SC92F83Hx)
	OTCON = OTCON & 0XCF | PinSeletion;
#endif
}
#endif

/**
 * @brief  UART0初始化配置函数
 * @param  Uart0Fsys[in]:系统时钟频率
 * @param  BaudRate[in]:波特率
 * @param  Mode[in]:系统时钟频率
 *          - UART0_PinSelection_P15P16:UART0引脚为P15，P16
 *          - UART0_PinSelection_P15:UART0引脚为P15，P16，无RX
 *          - UART0_PinSelection_P11P20:UART0引脚为P11，P20
 *          - UART0_PinSelection_P20:UART0引脚为P20，无RX
 * @param  ClockMode[in]:波特率时钟源（TIMER1/TIMER2）
 *          - UART0_CLOCK_TIMER1:TIMER1做波特率发生器
 *          - UART0_CLOCK_TIMER2:TIMER2做波特率发生器
 * @param  RxMode[in]:接收允许选择
 *          - UART0_RX_ENABLE:允许接收数据
 *          - UART0_RX_DISABLE:不允许接收数据
 * @retval None
 */
void UART0_Init(uint32_t Uart0Fsys, uint32_t BaudRate,
                UART0_Mode_Typedef Mode, UART0_Clock_Typedef ClockMode,
                UART0_RX_Typedef RxMode)
{
#if defined (SC92F725X) || defined (SC92F735X) || defined (SC92F730x) || defined (SC92F732X)  || defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x)\
	  || defined (SC92F730x_2) || defined (SC92F720x) ||defined(SC92F7308B)
  {
    SCON  = SCON & 0X2F | Mode | RxMode;	//设置UART工作模式,设置接收允许位

    if(Mode == UART0_Mode_8B ||
        Mode == UART0_Mode_11B_BaudRateFix)
    {
      if(BaudRate == UART0_BaudRate_FsysDIV12 ||
          BaudRate == UART0_BaudRate_FsysDIV64)
      {
        PCON &= 0X7F;
      }
      else if(BaudRate == UART0_BaudRate_FsysDIV4 ||
              BaudRate == UART0_BaudRate_FsysDIV32)
      {
        PCON |= 0X80;
      }
    }
    else
    {
      T2CON = (T2CON & 0xCF) | (ClockMode &  0X30);		//设置波特率时钟源

      if((ClockMode & 0X70) == 0X00)
      {
        TMOD |= 0X20;
        if(ClockMode & 0x80)
        {
          PCON |= 0X80;
          Uart0Fsys = Uart0Fsys * 2;
        }
        else
        {
          PCON &= 0X7F;
        }

        if(ClockMode & 0x0F)
        {
          TMCON |= 0x02;
        }
        else
        {
          TMCON &= 0xFD;
          Uart0Fsys = Uart0Fsys / 12;
        }

        TH1 = 256 - (Uart0Fsys / 32 / BaudRate);
        TL1 = TH1;
        TR1 = 1;
      }
      else if((ClockMode & 0X70) == 0X30)
      {
        if(ClockMode & 0x0F)
        {
          TMCON |= 0x04;
        }
        else
        {
          TMCON &= 0xFB;
          Uart0Fsys = Uart0Fsys / 12;
        }

        RCAP2H = (65536 - Uart0Fsys / 32 / BaudRate) /
                 256;
        RCAP2L = (65536 - Uart0Fsys / 32 / BaudRate) %
                 256;
        TR2 = 1;
      }
    }
  }
#elif defined (SC92F848x) || defined (SC92F748x) || defined (SC92F859x) || defined (SC92F759x) || defined (SC92R511x)
  {
    SCON  = (SCON & 0X2F) | Mode | RxMode;	//设置UART工作模式,设置接收允许位

    if(Mode == UART0_Mode_8B)
    {
      if(BaudRate == UART0_BaudRate_FsysDIV12)
      {
        PCON &= 0X7F;
      }
      else if(BaudRate == UART0_BaudRate_FsysDIV4)
      {
        PCON |= 0X80;
      }
    }
    else
    {
      T2CON = (T2CON & 0xCF) | (ClockMode & 0x30);		//设置波特率时钟源

      if(ClockMode & 0x80)
      {
        PCON |= 0x80;
        Uart0Fsys = Uart0Fsys / 16;
      }
      else
      {
        PCON &= 0x7F;
      }

      if((ClockMode & 0x7F)  == UART0_CLOCK_TIMER1)
      {
        TH1 = (Uart0Fsys / BaudRate) / 256;
        TL1 = (Uart0Fsys / BaudRate) % 256;
        TR1 = 0;
      }
      else if((ClockMode & 0x7F)  == UART0_CLOCK_TIMER2)
      {
        RCAP2H = (Uart0Fsys / BaudRate) / 256;
        RCAP2L = (Uart0Fsys / BaudRate) % 256;
        TR2 = 1;
      }
    }
  }
#elif defined (SC92L853x) || defined (SC92L753x) || defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) 
  {
    SCON = (SCON & 0X2F) | Mode | RxMode;	//设置UART工作模式,设置接收允许位

    /* 如果UART0选择为8位半双工同步通信模式，串行端口在系统时钟的12分频或4分频下运行*/
    if(Mode == UART0_Mode_8B)
    {
      if(BaudRate == UART0_BaudRate_FsysDIV12)
      {
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) 
            SCON &= 0XDF;
#else
            PCON &= 0X7F;
#endif
      }
      else if(BaudRate == UART0_BaudRate_FsysDIV4)
      {
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)  
            SCON |= 0X20;
#else				
            PCON |= 0X80;
#endif
      }
    }
		/* UART0选择模式1/3，波特率为可变 */
    else
    {


			/* 模式1/3可以在系统时钟的1分频或16分频下运行 */
			if(ClockMode & 0x80)
      {
        PCON |= 0x80;
        Uart0Fsys = Uart0Fsys / 16;
      }
      else
      {
        PCON &= 0x7F;
      }

			/* 配置UART0时钟源 */
      if((ClockMode & 0x7F)  == UART0_CLOCK_TIMER1)//UART0时钟源为TIMER1
      {
        TH1 = (Uart0Fsys / BaudRate) / 256;
        TL1 = (Uart0Fsys / BaudRate) % 256;
        TR1 = 0;
      }
      else if((ClockMode & 0x7F)  == UART0_CLOCK_TIMER2)//UART0时钟源为TIMER2
      {
				TXINX = 0X02;
        RCAPXH = (Uart0Fsys / BaudRate) / 256;
        RCAPXL = (Uart0Fsys / BaudRate) % 256;
        TRX = 1;
      }
      TXCON = (TXCON & 0xCF) | ClockMode;		//设置波特率时钟源
    }
  }

#else
  {
    SCON  = (SCON & 0X2F) | Mode | RxMode;	//设置UART工作模式,设置接收允许位

    if(Mode == UART0_Mode_8B)
    {
      if(BaudRate == UART0_BaudRate_FsysDIV12)
      {
			#if !defined(SC92L840x) 
        PCON &= 0X7F;
			#else
				SCON &= 0XDF;
			#endif
				
      }
      else if(BaudRate == UART0_BaudRate_FsysDIV4)
      {
			#if !defined(SC92L840x) 
        PCON |= 0X80;
			#else
				 SCON |= 0X20;
			#endif
				
      }
    }
    else
    {
      T2CON = (T2CON & 0xCF) |
              (ClockMode & 0x30);		//设置波特率时钟源

      if(ClockMode == UART0_CLOCK_TIMER1)
      {
        TH1 = (Uart0Fsys / BaudRate) / 256;
        TL1 = (Uart0Fsys / BaudRate) % 256;
        TR1 = 0;
      }
      else if(ClockMode == UART0_CLOCK_TIMER2)
      {
        RCAP2H = (Uart0Fsys / BaudRate) / 256;
        RCAP2L = (Uart0Fsys / BaudRate) % 256;
#if defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB) || defined (SC92F83Ax) || defined (SC92F73Ax)\
		|| defined (SC92F84Ax) || defined (SC92F74Ax) || defined (SC92F7003) || defined (SC92F8003) || defined (SC92F8003B) || defined (SC92F740x)\
		|| defined (SC92R342) || defined (SC92F6x1x) || defined (SC92F5x1x)|| defined (SC92R436)|| defined (SC92R438)|| defined (SC92R439)|| defined (SC92R422A)\
		|| defined (SC92F531x)		
        TR2 = 1;
#endif
      }
    }
  }
#endif
}

#if defined (SC92F531x)
uint8_t xdata SPOS_TX0 _at_ 0x120;
uint8_t xdata SPOS_RX0 _at_ 0x121;
/**
 * @brief  UART0端口映射函数
 * @param  UART0_TX0_MappingPin[in]: UART0_TX0映射管脚选择
 *          - UART0TX_Mapped_to_P50:UART0TX映射到P50
 *          - UART0TX_Mapped_to_P51:UART0TX映射到P51
 *          - ...
 *          - UART0TX_Mapped_to_P01:UART0TX映射到P01
 *          - UART0TX_Mapped_to_P00:UART0TX映射到P00
 
 *          - UART0RX_Mapped_to_P50:UART0RX映射到P50
 *          - UART0RX_Mapped_to_P51:UART0RX映射到P51
 *          - ...
 *          - UART0RX_Mapped_to_P01:UART0RX映射到P01
 *          - UART0RX_Mapped_to_P00:UART0RX映射到P00
 * @retval None
 */
void UART0_PortMapping(UART0_PortMappingPin_TypeDef UART0_MappingPin)
{
	if((UART0_MappingPin & 0x80) == 0x00)
	{
		SPOS_TX0 = SPOS_TX0 & 0xE0 | UART0_MappingPin;
	}
	else
	{
		SPOS_RX0 = SPOS_RX0 & 0xE0 | (UART0_MappingPin & 0x7F);
	}
}

#endif


/**
 * @}
 */
/* End of UART0_Group1.	*/

/** @defgroup UART0_Group2 Base functions
 *  @brief   UART0 functions
 *
@verbatim
 ===============================================================================
                     ##### Base functions #####
 ===============================================================================
@endverbatim
  * @{
  */


/**
 * @brief  UART0发送8位数据
 * @param  Data[in]:UART0发送8位数据
 * @retval None
 */
void UART0_SendData8(uint8_t Data)
{
  SBUF = Data;
}

/**
 * @brief  获得SBUF中的值
 * @param  None
 * @retval UART接收到的8位数据
 */
uint8_t UART0_ReceiveData8(void)
{
  return SBUF;
}

/**
 * @brief  UART0发送9位数据
 * @param  Data[in]:发送的数据
 * @retval None
 */
void UART0_SendData9(uint16_t Data)
{
  uint8_t Data_9Bit;
  Data_9Bit = (Data >> 8);

  if(Data_9Bit)
  {
    SCON |= 0X08;
  }
  else
  {
    SCON &= 0XF7;
  }

  SBUF = (uint8_t)Data;
}

/**
 * @brief  获得SBUF中的值及第九位的值
 * @param  None
 * @retval UART接收到的数据
 */
uint16_t UART0_ReceiveData9(void)
{
  uint16_t Data9;
  Data9 =  SBUF + (((uint16_t)(SCON & 0X04) & 0x00FF) << 6);
  SCON &= 0XFB;
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
StatusTypeDef UART0_Transmit(UART0_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout)
{
    uint32_t TimeoutCnt;
    /* 检查一个发送进程是否正在进行 */
    if (UART_HANDLE->TxState == UART0_STATE_READY)
    {
        /* 待发送数据长度必须大于0，否则返回错误状态 */
        if (Size == 0U)
        {
            return  Status_ERROR;
        }

        UART_HANDLE->TxState = UART0_STATE_BUSY;			//发送进程忙碌中
        TI = 0; //发送前清除发送标志
        UART_HANDLE->pTxBuffPtr.Size_u8 = pData;			//指向待发送数据的地址
        UART_HANDLE->TxXferSize = Size;			//更新待发送的数据量
        UART_HANDLE->TxXferCount = 0;			//发送计数器清零

        while (UART_HANDLE->TxXferCount < UART_HANDLE->TxXferSize)//判断是否接收所有数据
        {
            if (SCON & 0xC0 == UART0_Mode_11B)
            {
                SCON &= ~0x08;
                SCON |= (*(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount) >> 5);//设置第9位校验位
                SBUF = *(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount);
            }
            else
            {
                SBUF = *(UART_HANDLE->pTxBuffPtr.Size_u8 + UART_HANDLE->TxXferCount);
            }

            while (!TI) //等待发送完成
            {
                if (TimeoutCnt++ > Timeout)
                {
                    UART_HANDLE->TxState = UART0_STATE_TIMEOUT;//发送超时
                    return Status_TIMEOUT;
                }
                WDTCON |= 0x10;;          //喂狗函数，防止看门狗复位
            }

            UART0_ClearFlag(UART0_FLAG_TI); //发送中断标志清除，写1/写0清零
            TimeoutCnt = 0;
            UART_HANDLE->TxXferCount++;	//发送数据量计数
        }

        if (UART_HANDLE->TxXferCount == UART_HANDLE->TxXferSize)
        {
            UART_HANDLE->TxState = UART0_STATE_READY;	//发送完成
            return Status_OK;
        }
        else
        {
            UART_HANDLE->TxState = UART0_STATE_ERROR;//发生发送错误
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
StatusTypeDef UART0_Transmit_IT(UART0_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size)
{
    /* 检查一个发送进程是否正在进行 */
    if (UART_HANDLE->TxState == UART0_STATE_READY)
    {
        /* 没有开启UART0中断或发送数据量大小为0，返回错误 */
        if ((EUART == 0) || (UART_HANDLE->TxXferSize == 0U))
        {
            return Status_ERROR;
        }

        UART_HANDLE->TxState = UART0_STATE_BUSY;			//发送进程忙碌中
        TI = 0; //发送前清除发送标志
        UART_HANDLE->pTxBuffPtr.Size_u8 = pData;			//指向待发送数据的地址
        UART_HANDLE->TxXferSize = Size;			//更新待发送的数据量
        UART_HANDLE->TxXferCount = 0;			//发送计数器清零


        /* 发送第1帧数据 */
        if (SCON & 0xC0 == UART0_Mode_11B)
        {
            SCON |= (*(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount) >> 5) & 0x08;//设置第9位校验位
            SBUF = *(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount);
        }
        else
        {
            SBUF = *(UART_HANDLE->pTxBuffPtr.Size_u8 + UART_HANDLE->TxXferCount);
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
StatusTypeDef UART0_Transmit_IRQHandler(UART0_HandleInfoDef* UART_HANDLE)
{
    /* 处于发送线程 */
    if (UART_HANDLE->TxState == UART0_STATE_BUSY)
    {
        UART_HANDLE->TxXferCount++;
        /* 判断上一次发送是否是最后一次 */
        if (UART_HANDLE->TxXferCount < UART_HANDLE->TxXferSize)
        {
            /* 待发送数据量未为0，继续发送 */
            if (SCON & 0xC0 == UART0_Mode_11B)
            {
                SCON |= (*(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount) >> 5) & 0x08;//设置第9位校验位
                SBUF = *(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount);
            }
            else
            {
                SBUF = *(UART_HANDLE->pTxBuffPtr.Size_u8 + UART_HANDLE->TxXferCount);
            }
            return Status_BUSY;
        }
        else if (UART_HANDLE->TxXferCount == UART_HANDLE->TxXferSize)
        {
            /* 发送完成 */
            UART_HANDLE->TxState = UART0_STATE_READY;
            return Status_OK;
        }
        else
        {
            /* 发送数据量为0时还发送数据，返回错误 */
            UART_HANDLE->TxState = UART0_STATE_ERROR;
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
StatusTypeDef UART0_Receive(UART0_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout)
{
    uint32_t TimeoutCnt = 0;
    /* 检查接收进程正在运行 */
    if (UART_HANDLE->RxState == UART0_STATE_READY)
    {
        /* 检查接收数据量大小和是否开启接收使能 */
        if ((UART_HANDLE->RxXferSize == 0U) || ((SCON & 0x10) == UART0_RX_ENABLE))
        {
            return  Status_ERROR;
        }

        UART_HANDLE->RxState = UART0_STATE_BUSY;			//状态更新为接收忙碌中
        RI = 0;			 //接收前清除接收中断标志
        UART_HANDLE->pRxBuffPtr.Size_u8 = pData;			//指向待发送数据的地址
        UART_HANDLE->RxXferSize = Size;			//更新待发送的数据量
        UART_HANDLE->RxXferCount = 0;			//发送计数器清零

        while (UART_HANDLE->RxXferCount < UART_HANDLE->RxXferSize) //判断是否接收所有数据
        {
            if (RI) //判断接收标志位
            {
                if (SCON & 0xC0 == UART0_Mode_11B)
                {
                    *(UART_HANDLE->pRxBuffPtr.Size_u16 + UART_HANDLE->RxXferCount) = SBUF + ((uint16_t)(SCON & 0X04) << 6); //接收数据
                }
                else
                {
                    *(UART_HANDLE->pRxBuffPtr.Size_u8 + UART_HANDLE->RxXferCount) = SBUF;			//接收数据
                }
                RI = 0;			//接收标志位清零
                UART_HANDLE->RxXferCount++;	//接收数据量计数加1
                TimeoutCnt = 0;//收到数据，超时计数清零
            }
            else
            {
                if (TimeoutCnt++ > Timeout)//计时溢出
                {
                    UART_HANDLE->RxState = UART0_STATE_TIMEOUT;//发送超时
                    return Status_TIMEOUT;
                }
                WDTCON |= 0x10;;			//喂狗，防止等待时间过长，导致WDT复位
            }
        }

        if (UART_HANDLE->RxXferCount == UART_HANDLE->RxXferSize)
        {
            UART_HANDLE->RxState = UART0_STATE_READY;	//接收完成
            return Status_OK;
        }
        else
        {
            UART_HANDLE->RxState = UART0_STATE_ERROR;//接收错误
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
StatusTypeDef UART0_Receive_IT(UART0_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size)
{
    /* 检查一个接收进程是否正在进行 */
    if (UART_HANDLE->RxState == UART0_STATE_READY)
    {
        /* 检查是否开启UART0中断或发送数据量大小为0或是否开启接收使能，返回错误 */
        if ((EUART == 0) || (Size == 0U) || ((SCON & 0x10) == UART0_RX_ENABLE))
        {
            return UART0_STATE_ERROR;
        }

        UART_HANDLE->RxState = UART0_STATE_BUSY;
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
StatusTypeDef UART0_Receive_IRQHandler(UART0_HandleInfoDef* UART_HANDLE)
{
    /* 检查一个接收进程是否正在进行 */
    if (UART_HANDLE->RxState == UART0_STATE_BUSY)
    {
        /* 处于接收线程，检查待接收数据量是否为0 */
        if (UART_HANDLE->RxXferCount < UART_HANDLE->RxXferSize)
        {
            if (SCON & 0xC0 == UART0_Mode_11B)
            {
                *(UART_HANDLE->pRxBuffPtr.Size_u16 + UART_HANDLE->RxXferCount) = SBUF + ((uint16_t)(SCON & 0X04) << 6); //接收数据
            }
            else
            {
                *(UART_HANDLE->pRxBuffPtr.Size_u8 + UART_HANDLE->RxXferCount) = SBUF;			//接收数据
            }
            UART_HANDLE->RxXferCount++;
            /* 判断上一次发送是否是最后一次 */
            if (UART_HANDLE->RxXferCount == UART_HANDLE->RxXferSize)
            {
                /* 接收完成 */
                UART_HANDLE->RxState = UART0_STATE_READY;
                return Status_OK;
						}
            return Status_BUSY;
        }
        else
        {
            /* 接收数据量为0时还接收数据，返回错误 */
            UART_HANDLE->RxState = UART0_STATE_ERROR;
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
/* End of UART0_Group2.	*/

/** @defgroup UART0_Group3 Interrupts and flags management functions
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
 * @brief  UART0中断初始化
 * @param  NewState[in]: 断使能/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @param  Priority[in]: 中断优先级选择
 *              - LOW:低
 *              - HIGH:高
 * @retval None
 */ 
void UART0_ITConfig(FunctionalState NewState,
                    PriorityStatus Priority)
{
  if(NewState == DISABLE)
  {
    EUART = 0;
  }
  else
  {
    EUART = 1;
  }

  //设置中断优先级
  if(Priority == LOW)
  {
    IPUART = 0;
  }
  else
  {
    IPUART = 1;
  }
}
/**
 * @}
 */
/* End of UART0_Group3.	*/

#else

/** @defgroup UART0_Group1 Configuration of the UART0 computation unit functions
 *  @brief   Configuration of the UART0 computation unit functions
 *
 
@verbatim
 ===============================================================================
                     ##### UART0 configuration functions #####
 ===============================================================================


@endverbatim
  * @{
  */
 
 /**
 * @brief  UART0相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
//#define UART0_GetFlagStatus(UART0_Flag) ((UART0_Flag == UART0_FLAG_TI) ? (TI):(RI))
//#define UART0_ClearFlag(UART0_Flag) CLEAR_BIT(U0SCON,UART0_Flag)

void UART0_DeInit(void)
{
  U0SCON = 0X00;
  PCON &= 0X7F;
  IE &= 0XEF;
  IP &= 0XEF;
}

/**
 * @brief  UART0初始化配置函数
 * @param  Uart0Fsys[in]:系统时钟频率
 * @param  BaudRate[in]:波特率
 * @param  Mode[in]:系统时钟频率
 *          - UART0_Mode_8B:UART0工作模式:8位半双工
 *          - UART0_Mode_10B:UART0工作模式:10位全双工
 *          - UART0_Mode_11B:UART0工作模式:11位全双工
 * @param  ClockMode[in]:波特率时钟源（TIMER1/TIMER2）
 *          - UART0_CLOCK_TIMER1:TIMER1做波特率发生器
 *          - UART0_CLOCK_TIMER2:TIMER2做波特率发生器
 * @param  RxMode[in]:接收允许选择
 *          - UART0_RX_ENABLE:允许接收数据
 *          - UART0_RX_DISABLE:不允许接收数据
 * @retval None
 */
void UART0_Init(uint32_t Uart0Fsys, uint32_t BaudRate,
                UART0_Mode_Typedef Mode, UART0_Clock_Typedef ClockMode,
                UART0_RX_Typedef RxMode)
{
	U0SCON  = (U0SCON & 0X2F) | Mode | RxMode;	//设置UART工作模式,设置接收允许位
//	TMCON |= 0X02;
//	TMOD  |= 0X20;
	/* 如果UART0选择为8位半双工同步通信模式，串行端口在系统时钟的12分频或4分频下运行*/
	if(Mode == UART0_Mode_8B)
	{
		if(BaudRate == UART0_BaudRate_FsysDIV12)
		{
			PCON &= 0X7F;
		}
		else if(BaudRate == UART0_BaudRate_FsysDIV4)
		{			
			PCON |= 0X80;
		}
	}
	/* UART0选择模式1/3，波特率为可变 */
	else
	{
		/* 模式1/3可以在系统时钟的1分频或16分频下运行 */
		if(ClockMode & 0x80)
		{
			PCON |= 0x80;
			Uart0Fsys = Uart0Fsys / 16;
		}
		else
		{
			PCON &= 0x7F;
		}

		/* 配置UART0时钟源 */
		if((ClockMode & 0x7F)  == UART0_CLOCK_TIMER1)//UART0时钟源为TIMER1
		{
			TH1 = (Uart0Fsys / BaudRate) / 256;
			TL1 = (Uart0Fsys / BaudRate) % 256;
			TR1 = 0;
		}
		else if((ClockMode & 0x7F)  == UART0_CLOCK_TIMER2)//UART0时钟源为TIMER2
		{
			TXINX = 0X02;
			RCAPXH = (Uart0Fsys / BaudRate) / 256;
			RCAPXL = (Uart0Fsys / BaudRate) % 256;
			TRX = 1;
		}
		TXCON = (TXCON & 0xCF) | ClockMode;		//设置波特率时钟源
	}
}

#if defined (SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)
uint8_t xdata SPOS_TX0 _at_ 0x1030;
uint8_t xdata SPOS_RX0 _at_ 0x1031;
/**
 * @brief  UART0端口映射函数
 * @param  UART0_TX0_MappingPin[in]: UART0_TX0映射管脚选择
 *          - UART0TX_Mapped_to_P50:UART0TX映射到P50
 *          - UART0TX_Mapped_to_P51:UART0TX映射到P51
 *          - ...
 *          - UART0TX_Mapped_to_P01:UART0TX映射到P01
 *          - UART0TX_Mapped_to_P00:UART0TX映射到P00
 
 *          - UART0RX_Mapped_to_P50:UART0RX映射到P50
 *          - UART0RX_Mapped_to_P51:UART0RX映射到P51
 *          - ...
 *          - UART0RX_Mapped_to_P01:UART0RX映射到P01
 *          - UART0RX_Mapped_to_P00:UART0RX映射到P00
 * @retval None
 */
void UART0_PortMapping(UART0_PortMappingPin_TypeDef UART0_MappingPin)
{
	if((UART0_MappingPin & 0x80) == 0x00)
	{
		SPOS_TX0 = SPOS_TX0 & 0xE0 | UART0_MappingPin;
	}
	else
	{
		SPOS_RX0 = SPOS_RX0 & 0xE0 | (UART0_MappingPin & 0x7F);
	}
}
#endif

/**
 * @}
 */
/* End of UART0_Group1.	*/

/** @defgroup UART0_Group2 Base functions
 *  @brief   UART0 functions
 *
@verbatim
 ===============================================================================
                     ##### Base functions #####
 ===============================================================================
@endverbatim
  * @{
  */


/**
 * @brief  UART0发送8位数据
 * @param  Data[in]:UART0发送8位数据
 * @retval None
 */
void UART0_SendData8(uint8_t Data)
{
  U0SBUF = Data;
}

/**
 * @brief  获得SBUF中的值
 * @param  None
 * @retval UART接收到的8位数据
 */
uint8_t UART0_ReceiveData8(void)
{
  return U0SBUF;
}

/**
 * @brief  UART0发送9位数据
 * @param  Data[in]:发送的数据
 * @retval None
 */
void UART0_SendData9(uint16_t Data)
{
  uint8_t Data_9Bit;
  Data_9Bit = (Data >> 8);

  if(Data_9Bit)
  {
    U0SCON |= 0X08;
  }
  else
  {
    U0SCON &= 0XF7;
  }

  U0SBUF = (uint8_t)Data;
}

/**
 * @brief  获得SBUF中的值及第九位的值
 * @param  None
 * @retval UART接收到的数据
 */
uint16_t UART0_ReceiveData9(void)
{
  uint16_t Data9;
  Data9 =  U0SBUF + ((uint16_t)(U0SCON & 0X04) << 6);
  U0SCON &= 0XFB;
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
StatusTypeDef UART0_Transmit(UART0_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout)
{
    uint32_t TimeoutCnt;
    /* 检查一个发送进程是否正在进行 */
    if (UART_HANDLE->TxState == UART0_STATE_READY)
    {
        /* 待发送数据长度必须大于0，否则返回错误状态 */
        if (Size == 0U)
        {
            return  Status_ERROR;
        }

        UART_HANDLE->TxState = UART0_STATE_BUSY;			//发送进程忙碌中
        TI = 0; //发送前清除发送标志
        UART_HANDLE->pTxBuffPtr.Size_u8 = pData;			//指向待发送数据的地址
        UART_HANDLE->TxXferSize = Size;			//更新待发送的数据量
        UART_HANDLE->TxXferCount = 0;			//发送计数器清零

        while (UART_HANDLE->TxXferCount < UART_HANDLE->TxXferSize)//判断是否接收所有数据
        {
            if (U0SCON & 0xC0 == UART0_Mode_11B)
            {
                U0SCON &= ~0x08;
                U0SCON |= (*(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount) >> 5);//设置第9位校验位
                U0SBUF = *(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount);
            }
            else
            {
                U0SBUF = *(UART_HANDLE->pTxBuffPtr.Size_u8 + UART_HANDLE->TxXferCount);
            }

            while (!TI) //等待发送完成
            {
                if (TimeoutCnt++ > Timeout)
                {
                    UART_HANDLE->TxState = UART0_STATE_TIMEOUT;//发送超时
                    return Status_TIMEOUT;
                }
                WDTCON |= 0x10;;          //喂狗函数，防止看门狗复位
            }

            UART0_ClearFlag(UART0_FLAG_TI); //发送中断标志清除，写1/写0清零
            TimeoutCnt = 0;
            UART_HANDLE->TxXferCount++;	//发送数据量计数
        }

        if (UART_HANDLE->TxXferCount == UART_HANDLE->TxXferSize)
        {
            UART_HANDLE->TxState = UART0_STATE_READY;	//发送完成
            return Status_OK;
        }
        else
        {
            UART_HANDLE->TxState = UART0_STATE_ERROR;//发生发送错误
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
StatusTypeDef UART0_Transmit_IT(UART0_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size)
{
    /* 检查一个发送进程是否正在进行 */
    if (UART_HANDLE->TxState == UART0_STATE_READY)
    {
        /* 没有开启UART0中断或发送数据量大小为0，返回错误 */
        if ((EUART0 == 0) || (UART_HANDLE->TxXferSize == 0U))
        {
            return Status_ERROR;
        }

        UART_HANDLE->TxState = UART0_STATE_BUSY;			//发送进程忙碌中
        TI = 0; //发送前清除发送标志
        UART_HANDLE->pTxBuffPtr.Size_u8 = pData;			//指向待发送数据的地址
        UART_HANDLE->TxXferSize = Size;			//更新待发送的数据量
        UART_HANDLE->TxXferCount = 0;			//发送计数器清零


        /* 发送第1帧数据 */
        if (U0SCON & 0xC0 == UART0_Mode_11B)
        {
            U0SCON |= (*(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount) >> 5) & 0x08;//设置第9位校验位
            U0SBUF = *(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount);
        }
        else
        {
            U0SBUF = *(UART_HANDLE->pTxBuffPtr.Size_u8 + UART_HANDLE->TxXferCount);
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
StatusTypeDef UART0_Transmit_IRQHandler(UART0_HandleInfoDef* UART_HANDLE)
{
    /* 处于发送线程 */
    if (UART_HANDLE->TxState == UART0_STATE_BUSY)
    {
        UART_HANDLE->TxXferCount++;
        /* 判断上一次发送是否是最后一次 */
        if (UART_HANDLE->TxXferCount < UART_HANDLE->TxXferSize)
        {
            /* 待发送数据量未为0，继续发送 */
            if (U0SCON & 0xC0 == UART0_Mode_11B)
            {
                U0SCON |= (*(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount) >> 5) & 0x08;//设置第9位校验位
                U0SBUF = *(UART_HANDLE->pTxBuffPtr.Size_u16 + UART_HANDLE->TxXferCount);
            }
            else
            {
                U0SBUF = *(UART_HANDLE->pTxBuffPtr.Size_u8 + UART_HANDLE->TxXferCount);
            }
            return Status_BUSY;
        }
        else if (UART_HANDLE->TxXferCount == UART_HANDLE->TxXferSize)
        {
            /* 发送完成 */
            UART_HANDLE->TxState = UART0_STATE_READY;
            return Status_OK;
        }
        else
        {
            /* 发送数据量为0时还发送数据，返回错误 */
            UART_HANDLE->TxState = UART0_STATE_ERROR;
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
StatusTypeDef UART0_Receive(UART0_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout)
{
    uint32_t TimeoutCnt = 0;
    /* 检查接收进程正在运行 */
    if (UART_HANDLE->RxState == UART0_STATE_READY)
    {
        /* 检查接收数据量大小和是否开启接收使能 */
        if ((UART_HANDLE->RxXferSize == 0U) || ((U0SCON & 0x10) == UART0_RX_ENABLE))
        {
            return  Status_ERROR;
        }

        UART_HANDLE->RxState = UART0_STATE_BUSY;			//状态更新为接收忙碌中
        RI = 0;			 //接收前清除接收中断标志
        UART_HANDLE->pRxBuffPtr.Size_u8 = pData;			//指向待发送数据的地址
        UART_HANDLE->RxXferSize = Size;			//更新待发送的数据量
        UART_HANDLE->RxXferCount = 0;			//发送计数器清零

        while (UART_HANDLE->RxXferCount < UART_HANDLE->RxXferSize) //判断是否接收所有数据
        {
            if (RI) //判断接收标志位
            {
                if (U0SCON & 0xC0 == UART0_Mode_11B)
                {
                    *(UART_HANDLE->pRxBuffPtr.Size_u16 + UART_HANDLE->RxXferCount) = U0SBUF + ((uint16_t)(U0SCON & 0X04) << 6); //接收数据
                }
                else
                {
                    *(UART_HANDLE->pRxBuffPtr.Size_u8 + UART_HANDLE->RxXferCount) = U0SBUF;			//接收数据
                }
                RI = 0;			//接收标志位清零
                UART_HANDLE->RxXferCount++;	//接收数据量计数加1
                TimeoutCnt = 0;//收到数据，超时计数清零
            }
            else
            {
                if (TimeoutCnt++ > Timeout)//计时溢出
                {
                    UART_HANDLE->RxState = UART0_STATE_TIMEOUT;//发送超时
                    return Status_TIMEOUT;
                }
                WDTCON |= 0x10;;			//喂狗，防止等待时间过长，导致WDT复位
            }
        }

        if (UART_HANDLE->RxXferCount == UART_HANDLE->RxXferSize)
        {
            UART_HANDLE->RxState = UART0_STATE_READY;	//接收完成
            return Status_OK;
        }
        else
        {
            UART_HANDLE->RxState = UART0_STATE_ERROR;//接收错误
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
StatusTypeDef UART0_Receive_IT(UART0_HandleInfoDef* UART_HANDLE, uint8_t* pData, uint8_t Size)
{
    /* 检查一个接收进程是否正在进行 */
    if (UART_HANDLE->RxState == UART0_STATE_READY)
    {
        /* 检查是否开启UART0中断或发送数据量大小为0或是否开启接收使能，返回错误 */
        if ((EUART0 == 0) || (Size == 0U) || ((U0SCON & 0x10) == UART0_RX_ENABLE))
        {
            return UART0_STATE_ERROR;
        }

        UART_HANDLE->RxState = UART0_STATE_BUSY;
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
StatusTypeDef UART0_Receive_IRQHandler(UART0_HandleInfoDef* UART_HANDLE)
{
    /* 检查一个接收进程是否正在进行 */
    if (UART_HANDLE->RxState == UART0_STATE_BUSY)
    {
        /* 处于接收线程，检查待接收数据量是否为0 */
        if (UART_HANDLE->RxXferCount < UART_HANDLE->RxXferSize)
        {
            if (U0SCON & 0xC0 == UART0_Mode_11B)
            {
                *(UART_HANDLE->pRxBuffPtr.Size_u16 + UART_HANDLE->RxXferCount) = U0SBUF + ((uint16_t)(U0SCON & 0X04) << 6); //接收数据
            }
            else
            {
                *(UART_HANDLE->pRxBuffPtr.Size_u8 + UART_HANDLE->RxXferCount) = U0SBUF;			//接收数据
            }
            UART_HANDLE->RxXferCount++;
            /* 判断上一次发送是否是最后一次 */
            if (UART_HANDLE->RxXferCount == UART_HANDLE->RxXferSize)
            {
                /* 接收完成 */
                UART_HANDLE->RxState = UART0_STATE_READY;
                return Status_OK;
						}
            return Status_BUSY;
        }
        else
        {
            /* 接收数据量为0时还接收数据，返回错误 */
            UART_HANDLE->RxState = UART0_STATE_ERROR;
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
/* End of UART0_Group2.	*/

/** @defgroup UART0_Group3 Interrupts and flags management functions
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
 * @brief  UART0中断初始化
 * @param  NewState[in]: 断使能/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @param  Priority[in]: 中断优先级选择
 *              - LOW:低
 *              - HIGH:高
 * @retval None
 */ 
void UART0_ITConfig(FunctionalState NewState,
                    PriorityStatus Priority)
{
  if(NewState == DISABLE)
  {
    EUART0 = 0;
  }
  else
  {
    EUART0 = 1;
  }

  //设置中断优先级
  if(Priority == LOW)
  {
    IPUART0 = 0;
  }
  else
  {
    IPUART0 = 1;
  }
}
/**
 * @}
 */
/* End of UART0_Group3.	*/
#endif

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