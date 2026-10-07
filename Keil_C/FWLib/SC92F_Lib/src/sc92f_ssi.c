/**
 ******************************************************************************
 * @file    sc92f_ssi.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   SSI function module
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
#include "sc92f_ssi.h"

#if defined (SC92F854x) || defined (SC92F754x) ||defined  (SC92F844xB) || defined (SC92F744xB)||defined  (SC92F84Ax_2) || defined (SC92F74Ax_2)\
		|| defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB) || defined (SC92F84Ax) || defined (SC92F74Ax)\
		|| defined (SC92F83Ax) || defined (SC92F73Ax) || defined (SC92F7003) || defined (SC92F8003) || defined (SC92F8003B) || defined (SC92F740x) || defined (SC92F827X)\
		|| defined (SC92F837X) || defined (SC92FWxx) || defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x)\
		|| defined (SC92F848x) || defined (SC92F748x) || defined (SC92F859x) || defined (SC92F759x) || defined (SC92R511x) || defined (SC92R342)\
		|| defined (SC92F841x)|| defined (SC92F741x) || defined(SC92F84Hx) || defined(SC92F83Hx) ||defined(SC92F6x1x)||defined(SC92F5x1x)||defined(SC92R436)||defined(SC92R438)||defined(SC92R439)\
		|| defined (SC92Fx41xB)||defined(SC92R445)||defined(SC92R422A)|| defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)|| defined(SC92F5x5x)|| defined(SC92F531x)\
		|| defined (SC92F637x) || defined (SC92F563x)
/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
/** @defgroup SSI
 * @brief SSI driver modules
 * @{
 */

/** @defgroup SSI_Functions
 * @{
 */
		
/** @defgroup SSI_Group1 Initialization and Configuration functions
 *  @brief Initialization and Configuration functions
 *
 
@verbatim
 ===============================================================================
                     ##### Initialization and Configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */
  
/**
 * @brief  SSI相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void SSI_DeInit(void)
{
  OTCON &= 0X3F;
  SSCON0 = 0X00;
  SSCON1 = 0X00;
  SSCON2 = 0X00;
  SSDAT = 0X00;
  IE1 &= (~0X01);
  IP1 &= (~0X01);
}
#if defined (SC92F7003) || defined (SC92F8003) || defined (SC92F8003B) || defined (SC92F740x) || defined(SC92F84Hx) || defined(SC92F83Hx)
/**
 * @brief  SSI引脚选择
 * @param  PinSeletion[in]:选择SSI引脚
 *          SC92F7003、SC92F8003、SC92F8003B、SC92F740x：
 *          - SSI_PinSelection_P10P27P26:SSI共用引脚为P10，P27，P26
 *          - SSI_PinSelection_P21P22P23:SSI共用引脚为P21，P22，P23
 *          - SSI_PinSelection_URATP27:SSIUART引脚为P27,无RX
 *          - SSI_PinSelection_URATP22:SSIUART引脚为P22,无RX
 *          SC92F84Hx、SC92F83Hx：
 *          - SSI_SPI_PinRemap_Defalut:SPI引脚为默认引脚
 *          - SSI_SPI_PinRemap_A:SPI引脚为A组引脚
 *          - SSI_UART_PinRemap_Defalut:UART引脚为默认引脚
 *          - SSI_UART_PinRemap_A:UART引脚为A组引脚
 *          - SSI_TWI_PinRemap_Defalut:TWI引脚为默认引脚
 *          - SSI_TWI_PinRemap_A:TWI引脚为A组引脚
 * @retval None
 */ 
void SSI_PinSelection(SSI_PinSelection_TypeDef PinSeletion)
{
#if defined (SC92F7003) || defined (SC92F8003) || defined (SC92F8003B) || defined (SC92F740x)
  OTCON = OTCON & 0XDF | PinSeletion;
#elif defined(SC92F84Hx) || defined(SC92F83Hx)
	OTCON = OTCON & 0XFD | PinSeletion;
#endif	
}
#endif

/**
 * @brief  SPI初始化配置函数
 * @param  FirstBit[in]:优先传送位选择（MSB/LSB）
 *          - SPI_FIRSTBIT_MSB:MSB优先发送
 *          - SPI_FIRSTBIT_LSB:LSB优先发送
 * @param  BaudRatePrescaler[in]:选择SSI引脚
 *          - SPI_BAUDRATEPRESCALER_4:SPI时钟速率为系统时钟除以4
 *          - SPI_BAUDRATEPRESCALER_8:SPI时钟速率为系统时钟除以8
 *          - SPI_BAUDRATEPRESCALER_16:SPI时钟速率为系统时钟除以16
 *          - SPI_BAUDRATEPRESCALER_32:SPI时钟速率为系统时钟除以32
 *          - SPI_BAUDRATEPRESCALER_64:SPI时钟速率为系统时钟除以64
 *          - SPI_BAUDRATEPRESCALER_128:SPI时钟速率为系统时钟除以128
 *          - SPI_BAUDRATEPRESCALER_256:SPI时钟速率为系统时钟除以256
 *          - SPI_BAUDRATEPRESCALER_512:SPI时钟速率为系统时钟除以512
 * @param  Mode[in]:SPI工作模式选择
 *          - SPI_MODE_MASTER:SPI为主设备
 *          - SPI_MODE_SLAVE:SPI为从设备
 * @param  ClockPolarity[in]:选择SSI引脚
 *          - SPI_CLOCKPOLARITY_LOW:SCK在空闲状态下为低电平
 *          - SPI_CLOCKPOLARITY_HIGH:SCK在空闲状态下为高电平
 * @param  ClockPhase[in]:选择SSI引脚
 *          - SPI_CLOCKPHASE_1EDGE:SCK的第一沿采集数据
 *          - SPI_CLOCKPHASE_2EDGE:SCK的第二沿采集数据
 * @param  SPI_TXE_INT[in]:选择SSI引脚
 *          - SPI_TXE_DISINT:不允许发送中断
 *          - SPI_TXE_ENINT:允许发送中断
 * @retval None
 */
void SSI_SPI_Init(SPI_FirstBit_TypeDef FirstBit,
                  SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler,
                  SPI_Mode_TypeDef Mode,
                  SPI_ClockPolarity_TypeDef ClockPolarity,
                  SPI_ClockPhase_TypeDef ClockPhase,
                  SPI_TXE_INT_TypeDef SPI_TXE_INT)
{
  OTCON = (OTCON & 0X3F) | 0X40;
	SPI_TXE_INT = SPI_TXE_DISINT;//SPI_TXE_INT该功能在SSI芯片上无效
  SSCON1 = SSCON1 & (~0X05) | FirstBit ;
  SSCON0 = SSCON0 & 0X80 | BaudRatePrescaler | Mode
           | ClockPolarity | ClockPhase;
}
/**
 * @}
 */
/* End of SSI_Group1.	*/

/** @defgroup SSI_Group2 Base functions
 *  @brief   SSI functions
 *
@verbatim
 ===============================================================================
                     ##### Base functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  SPI功能开关函数
 * @param  NewState[in]:功能启动/关闭选择
 *          - DISABLE:失能
 *          - ENABLE:使能
 * @retval None
 */ 
void SSI_SPI_Cmd(FunctionalState NewState)
{
  if(NewState != DISABLE)
  {
    SSCON0 |= 0X80;
  }
  else
  {
    SSCON0 &= (~0X80);
  }
}

/**
 * @brief  SPI发送数据
 * @param  Data[in]:发送的数据
 * @retval None
 */ 
void SSI_SPI_SendData(uint8_t Data)
{
  SSDAT = Data;
}

/**
 * @brief  获得SSDAT中的值
 * @param  None
 * @retval SPI接收到的8位数据
 */
uint8_t SSI_SPI_ReceiveData(void)
{
  return SSDAT;
}

/**
 * @brief  SPI0 中断处理
 * @param  SSI_HANDLE[in]:指向包含 SPI0 信息的 SSI_HandleInfoDef 结构体的指针
 * @retval None
 */
StatusTypeDef SSI_SPI_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE)
{
  StatusTypeDef TempStatus = Status_ERROR;

  if(SSI_HANDLE->RxState == SSI_STATE_BUSY)
  {
    /* 当数据没有接收完成 */
    if(SSI_HANDLE->RxXferCount < SSI_HANDLE->RxXferSize)
    {
      /* SPI处于8位通信模式 */
      *(SSI_HANDLE->pRxBuffPtr.Size_u8 + SSI_HANDLE->RxXferCount) = SSI_SPI_ReceiveData();			//读取16位数据

      SSI_HANDLE->RxXferCount++;			//接收到数据，计数值加1

      /* 数据接收完成，状态位进行修改 */
      if(SSI_HANDLE->RxXferCount == SSI_HANDLE->RxXferSize)
      {
        SSI_HANDLE->RxState = SSI_STATE_READY;
        TempStatus =  Status_OK;
      }
    }
	 TempStatus = Status_BUSY;
  }

  if(SSI_HANDLE->TxState == SSI_STATE_BUSY)
  {
    SSI_HANDLE->TxXferCount++;			//数据发送完成，计数值加1
    /* 当数据没有发送完成 */
    if(SSI_HANDLE->TxXferCount < SSI_HANDLE->TxXferSize)
    {
      /* SPI处于8位通信模式 */
      SSI_SPI_SendData(*(SSI_HANDLE->pTxBuffPtr.Size_u8 + SSI_HANDLE->TxXferCount));			//发送16位数据

    }
    /* 数据发送完成，状态位进行修改 */
    else if(SSI_HANDLE->TxXferCount == SSI_HANDLE->TxXferSize)
    {
      SSI_HANDLE->TxState = SSI_STATE_READY;
      TempStatus = Status_OK;
    }
	 TempStatus = Status_BUSY;
  }
  /* 当SPI处于主机时，SPI需要发送数据，才能同步接收到数据 */
  else if(SSI_HANDLE->RxXferCount < SSI_HANDLE->RxXferSize)
  {
    SSI_SPI_SendData(0x00);
  }

  return TempStatus;
}

/**
 * @brief  SPI在轮询模式下接收大量数据
 * @param  SSI_HANDLE[out]:指向包含指定SPI模块的配置信息结构体的指针
 * @param  pData[out]:接收数据的存放区
 * @param  Size[in]:待接收的数据量
 * @param  Timeout[in]:超时时间
 * @retval SSI 状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_SPI_Receive(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout)
{
  uint32_t TimeoutCnt = 0;

  if(SSI_HANDLE->RxState == SSI_STATE_READY)
  {
    /* 待接收数据长度必须大于0，否则返回错误状态 */
    if(((IE1 & 0x01) != 0) || (Size == 0U))
    {
      return SSI_STATE_ERROR;
    }

    /* SPI作为主机时，接收数据必定跟随发送数据 */
    if((SSCON0 & SPI_MODE_MASTER) != 0)
    {
      return SSI_SPI_TransmitReceive(SSI_HANDLE, pData, pData, Size, Timeout);			//跳转到阻塞模式数据收发函数
    }

    SSI_HANDLE->RxState = SSI_STATE_BUSY;			//接收进程忙碌中
    SSI_ClearFlag(SPI_FLAG_SPIF);			 //接收前清除接收中断标志
    SSI_HANDLE->pRxBuffPtr.Size_u8 = pData;			//指向待接收数据的地址
    SSI_HANDLE->RxXferSize = Size;			//更新待接收的数据量
    SSI_HANDLE->RxXferCount = 0;			//接收计数器清零

    while(SSI_HANDLE->RxXferCount < SSI_HANDLE->RxXferSize)
    {
      /* 等待SPI中断标志位置起 */
      if(SSI_GetFlagStatus(SPI_FLAG_SPIF))
      {
          *(SSI_HANDLE->pRxBuffPtr.Size_u8 + SSI_HANDLE->RxXferCount) = SSI_SPI_ReceiveData();			//读取16位数据,并且地址自增
        SSI_ClearFlag(SPI_FLAG_SPIF);				//清除标志位
        SSI_HANDLE->RxXferCount++;	//接收数据量计数加1
        TimeoutCnt = 0;			//超时计数值清零
      }
      else
      {
        /* 超时计数器不断累加，直到超出设定的超时时间 */
        if((TimeoutCnt++) > Timeout)
        {
          if(Timeout == 0)
            return SSI_STATE_TIMEOUT;				//返回超时错误
        }
        WDTCON |= 0x10;          //喂狗函数，防止看门狗复位
      }
    }

    if(SSI_HANDLE->RxXferCount == SSI_HANDLE->RxXferSize)
    {
      SSI_HANDLE->RxState = SSI_STATE_READY;	//接收完成
      return Status_OK;
    }
    else
    {
      SSI_HANDLE->RxState = SSI_STATE_ERROR;//接收错误
      return Status_ERROR;
    }
  }
  else
  {
    return Status_BUSY;//返回忙碌状态
  }
}

/**
 * @brief  中断模式接收一定量数据
 * @param  SSI_HANDLE[out]:指向包含指定SPI模块的配置信息结构体的指针
 * @param  pData[out]:接收数据的存放区
 * @param  Size[in]:待接收的数据量
 * @retval SSI 状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_SPI_Receive_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size)
{
  /* 检查一个接收进程是否正在进行 */
  if(SSI_HANDLE->RxState == SSI_STATE_READY)
  {
    /* 待接收数据长度必须大于0，否则返回错误状态 */
    if(((IE1 & 0x01) == 0) || (Size == 0U))
    {
      return SSI_STATE_ERROR;
    }

    /* SPI作为主机时，接收数据必定跟随发送数据 */
    if((SSCON0 & SPI_MODE_MASTER) != 0)
    {
      return SSI_SPI_TransmitReceive_IT(SSI_HANDLE, pData, pData, Size);			//跳转到中断模式数据收发函数
    }

    SSI_HANDLE->RxState = SSI_STATE_BUSY;			//状态更新为接收忙碌中
    SSI_ClearFlag(SPI_FLAG_SPIF);			//清除中断标志位
    SSI_HANDLE->pRxBuffPtr.Size_u8 = pData;			//指向待接收数据的地址
    SSI_HANDLE->RxXferSize = Size;			//更新待接收的数据量
    SSI_HANDLE->RxXferCount = 0;			//接收计数器清零

    return Status_OK;
  }
  else
  {
    return Status_BUSY;//返回标志位
  }
}

/**
 * @brief  SPI在轮询模式下发送大量数据
 * @param  SSI_HANDLE[out]:指向包含指定SPI模块的配置信息结构体的指针
 * @param  pData[out]:指向数据缓存的指针
 * @param  Size[in]:发送数据的大小
 * @param  Timeout[in]:超时时间
 * @retval SSI 状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_SPI_Transmit(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout)
{
  uint32_t TimeoutCnt = 0;
	
  /* 检查一个发送进程是否正在进行 */
  if(SSI_HANDLE->TxState == SSI_STATE_READY)
  { 
    /* 待发送数据长度必须大于0，否则返回错误状态 */
    if(((IE1 & 0x01) != 0) || (Size == 0U))
    {
      return Status_ERROR;
    }

    SSI_HANDLE->TxState = SSI_STATE_BUSY;			//发送进程忙碌中
    SSI_ClearFlag(SPI_FLAG_SPIF);			 //发送前清除标志位
    SSI_HANDLE->pTxBuffPtr.Size_u8 = pData;			//指向待发送数据的地址
    SSI_HANDLE->TxXferSize = Size;			//更新待发送的数据量
    SSI_HANDLE->TxXferCount = 0;			//发送计数器清零

    while(SSI_HANDLE->TxXferCount < SSI_HANDLE->TxXferSize)//判断是否接收所有数据
    {

        SSI_SPI_SendData(*(SSI_HANDLE->pTxBuffPtr.Size_u8 + SSI_HANDLE->TxXferCount));			//发送8位数据并且数据地址增加
      while(!SSI_GetFlagStatus(SPI_FLAG_SPIF))			//等待发送完成
      {
        /* 超时计数器不断累加，直到超出设定的超时时间 */
        if(TimeoutCnt++ > Timeout)
        {
          SSI_HANDLE->TxState = SSI_STATE_TIMEOUT;//发送超时
          return Status_TIMEOUT;
        }
        WDTCON |= 0x10;			//喂狗，防止等待时间过长，导致WDT复位
      }

      SSI_ClearFlag(SPI_FLAG_SPIF);				//发送前先清除标志位
      TimeoutCnt = 0;			//超时计数器清零
      SSI_HANDLE->TxXferCount ++;	//发送数据量计数
    }
    if(SSI_HANDLE->TxXferCount == SSI_HANDLE->TxXferSize)
    {
      SSI_HANDLE->TxState = SSI_STATE_READY;	//发送完成
      return Status_OK;
    }
    else
    {
      SSI_HANDLE->TxState = SSI_STATE_ERROR;//发生发送错误
      return Status_ERROR;
    }
  }
  else
  {
    return Status_BUSY;//返回忙碌状态
  }
}

/**
 * @brief  中断模式发送一定量数据
 * @param  SSI_HANDLE[out]:指向包含指定SPI模块的配置信息结构体的指针
 * @param  pData[out]:指向数据缓存的指针
 * @param  Size[in]:发送数据的大小
 * @retval SSI 状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_SPI_Transmit_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size)
{
  /* 检查一个发送进程是否正在进行 */
  if(SSI_HANDLE->TxState == SSI_STATE_READY)
  {
    /* 没有开启SSI中断或发送数据量大小为0，返回错误 */
    if(((IE1 & 0x01) == 0) || (Size == 0U))
    {
      return Status_ERROR;
    }

    SSI_HANDLE->TxState = SSI_STATE_BUSY;			//发送进程忙碌中
    SSI_ClearFlag(SPI_FLAG_SPIF);			//清除中断标志位
    SSI_HANDLE->pTxBuffPtr.Size_u8 = pData;			//指向待发送数据的地址
    SSI_HANDLE->TxXferSize = Size;			//更新待发送的数据量
    SSI_HANDLE->TxXferCount = 0;			//发送计数器置0

    /* 发送第1byte数据 */
      SSI_SPI_SendData(*(SSI_HANDLE->pTxBuffPtr.Size_u8));

    return Status_OK;
  }
  else
  {
    return  Status_BUSY;			//状态位修改为忙碌状态
  }
}

/**
 * @brief  阻塞模式收发一定量数据
 * @param  SSI_HANDLE[out]:指向包含指定SPI模块的配置信息结构体的指针
 * @param  pTxData[out]:指向发送数据缓存的指针
 * @param  pRxData[out]:指向接收数据缓存的指针
 * @param  Size[in]:发送数据的大小
 * @param  Timeout[in]:超时时间
 * @retval SSI 状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_SPI_TransmitReceive(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pTxData, uint8_t* pRxData, uint8_t Size, uint32_t Timeout)
{
  uint32_t TimeoutCnt = 0;
  /* 检查一个发送与接收进程是否正在进行 */
  if((SSI_HANDLE->TxState == SSI_STATE_READY) && (SSI_HANDLE->RxState == SSI_STATE_READY))
  {

    /* 待发送和接收数据长度必须大于0，否则返回错误状态 */
    if(((IE1 & 0x01) != 0) || (Size == 0U))
    {
      return  Status_ERROR;
    }

    SSI_HANDLE->TxState = SSI_HANDLE->RxState = SSI_STATE_BUSY;			//发送与接收进程忙碌中
    SSI_ClearFlag(SPI_FLAG_SPIF);			//清除中断标志位
    SSI_HANDLE->pTxBuffPtr.Size_u8 = pTxData;       //指向待发送数据的地址
    SSI_HANDLE->pRxBuffPtr.Size_u8 = pRxData;				//指向待接收数据的地址
    SSI_HANDLE->TxXferSize = SSI_HANDLE->RxXferSize = Size;			//更新待发送与接收的数据量
    SSI_HANDLE->TxXferCount = SSI_HANDLE->RxXferCount = 0;			//发送与接收计数器清零

    while(SSI_HANDLE->TxXferCount < SSI_HANDLE->TxXferSize);
    {


      SSI_SPI_SendData(*(SSI_HANDLE->pTxBuffPtr.Size_u8 + SSI_HANDLE->TxXferCount));			//发送16位数据并且地址增加
      while(!SSI_GetFlagStatus(SPI_FLAG_SPIF))			//等待发送完成
      {
        /* 等待时间是否发生了超时 */
        if(TimeoutCnt++ > Timeout)
        {
          return SSI_STATE_TIMEOUT;				//返回超时错误
        }
        WDTCON |= 0x10;			//喂狗，防止等待时间过长，导致WDT复位
      }
      SSI_ClearFlag(SPI_FLAG_SPIF);				//发送前先清除标志位
      *(SSI_HANDLE->pTxBuffPtr.Size_u8 + SSI_HANDLE->TxXferCount) = SSI_SPI_ReceiveData();

      TimeoutCnt = 0;			//超时计数值清零
      SSI_HANDLE->TxXferCount++;			//数据量计数值加1
      SSI_HANDLE->TxXferCount++;			//数据量计数值加1
    }
    if(SSI_HANDLE->TxXferCount == SSI_HANDLE->TxXferSize)
    {
      SSI_HANDLE->TxState = SSI_HANDLE->RxState = SSI_STATE_READY;	//发送完成
      return Status_OK;
    }
    else
    {
      SSI_HANDLE->TxState = SSI_STATE_ERROR;//发生发送错误
      return Status_ERROR;
    }
  }
  else
  {
    return Status_ERROR;
  }

}

/**
 * @brief  SPI在中断模式下发送和接收大量数据时，先在main函数中调用此函数
 * @param  SSI_HANDLE[out]:指向包含指定SPI模块的配置信息结构体的指针
 * @param  pTxData[out]:指向发送数据缓存的指针
 * @param  pRxData[out]:指向接收数据缓存的指针
 * @param  Size[in]:发送数据的大小
 * @retval SSI 状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_SPI_TransmitReceive_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pTxData, uint8_t* pRxData, uint8_t Size)
{
  /* 待发送与接收数据长度必须大于0，否则返回错误状态 */
  if((SSI_HANDLE->TxState == SSI_STATE_READY) && (SSI_HANDLE->RxState == SSI_STATE_READY))
  {

    /* 待发送和接收数据长度必须大于0，否则返回错误状态 */
    if(((IE1 & 0x01) == 0) || (Size == 0U))
    {
      return  Status_ERROR;
    }
    SSI_SPI_Cmd(DISABLE);
    SSI_HANDLE->TxState = SSI_HANDLE->RxState = SSI_STATE_BUSY;			//发送与接收进程忙碌中
    SSI_ClearFlag(SPI_FLAG_SPIF);			//清除中断标志位
    SSI_HANDLE->pTxBuffPtr.Size_u8 = pTxData;			//指向待发送数据的地址
    SSI_HANDLE->pRxBuffPtr.Size_u8 = pRxData;			//指向待接收数据的地址
    SSI_HANDLE->TxXferSize = SSI_HANDLE->RxXferSize = Size;			//更新待发送与接收的数据量
    SSI_HANDLE->TxXferCount = SSI_HANDLE->RxXferCount = 0;			//发送与接收计数器清零
    SSI_SPI_Cmd(ENABLE);

    /* 发送第1byte数据 */
    /* SPI处于8位通信模式 */
    SSI_SPI_SendData(*(SSI_HANDLE->pTxBuffPtr.Size_u8));			//发送8位数据

    return  Status_OK;
  }
  else
  {
    return Status_ERROR;
  }
}

/**
 * @brief  TWI初始化配置函数
 * @param  TWI_Address[in]:TWI作为从机时7位从机地址配置
 * @retval None
 */
void SSI_TWI_Init(uint8_t TWI_Address)
{
  OTCON = OTCON & 0X3F | 0X80;
  SSCON1 = TWI_Address << 1;
}

/**
 * @brief  TWI接收应答使能函数
 * @param  NewState[in]: 接收应答使能/失能选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */
void SSI_TWI_AcknowledgeConfig(FunctionalState
                               NewState)
{
  if(NewState != DISABLE)
  {
    SSCON0 |= 0X08;
  }
  else
  {
    SSCON0 &= 0XF7;
  }
}

/**
 * @brief  TWI通用地址响应使能函数
 * @param  NewState[in]: 通用地址响应使能/失能选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */
void SSI_TWI_GeneralCallCmd(FunctionalState
                            NewState)
{
  if(NewState != DISABLE)
  {
    SSCON1 |= 0X01;
  }
  else
  {
    SSCON1 &= 0XFE;
  }
}

/**
 * @brief  获取TWI状态机
 * @param  SSI_TWIState[in]: TWI状态机状态
 *              - TWI_SlaveIdle:从机空闲模式
 *              - TWI_SlaveReceivedaAddress:从机接收地址
 *              - TWI_SlaveReceivedaData:从机接收数据
 *              - TWI_SlaveSendData:从机发送数据
 *              - TWI_SlaveReceivedaUACK:从机接收UACK
 *              - TWI_SlaveDisableACK:从机关闭ACK
 *              - TWI_SlaveAddressError:从机接收地址错误
 * @retval 返回操作状态
 *              - RESET:操作不成功
 *              - SET:操作成功
 */
FlagStatus SSI_GetTWIStatus(SSI_TWIState_TypeDef SSI_TWIState)
{
  if((SSCON0 & 0x07) == SSI_TWIState)
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
void SSI_TWI_Cmd(FunctionalState NewState)
{
  if(NewState != DISABLE)
  {
    SSCON0 |= 0X80;
  }
  else
  {
    SSCON0 &= (~0X80);
  }
}

/**
 * @brief  TWI发送数据
 * @param  Data[in]:发送的数据
 * @retval None
 */ 
void SSI_TWI_SendData(uint8_t Data)
{
  SSDAT = Data;
}

/**
 * @brief  获得SSDAT中的值
 * @param  None
 * @retval TWI接收到的8位数据
 */
uint8_t SSI_TWI_ReceiveData(void)
{
  return SSDAT;
}

/**
 * @brief  等待TWIF置起
 * @param  SSI_HANDLE[in]:指针指向SSI数据信息存放区
 * @param  Timeout[in]:超时时间设置
 * @retval 函数执行状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_TWI_Wait_TWIF(SSI_HandleInfoDef* SSI_HANDLE, uint32_t Timeout)
{
  uint32_t TimeoutCnt = 0;
  while(!(SSI_GetFlagStatus(TWI_FLAG_TWIF)))			//等待启动信号发送完毕
  {
    TimeoutCnt++;
    if(TimeoutCnt > Timeout)
    {
      /* 超时更新状态 */
      if(SSI_HANDLE->TxState == SSI_STATE_BUSY)
        SSI_HANDLE->TxState = SSI_STATE_TIMEOUT;
      if(SSI_HANDLE->RxState == SSI_STATE_BUSY)
        SSI_HANDLE->RxState = SSI_STATE_TIMEOUT;
      return Status_TIMEOUT;
    }
  }
  SSI_ClearFlag(TWI_FLAG_TWIF);			//清除标志位
  return Status_OK;
}

/**
 * @brief  发送8位数据时，从机轮询模式下发送大量数据 注：默认开启时钟延长模式
 * @param  SSI_HANDLE[out]:指向包含指定SPI模块的配置信息结构体的指针
 * @param  Timeout[in]:超时时间
 * @retval SSI 状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_TWI_Slave_Transmit(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout)
{
  /* 检查一个发送进程是否正在进行 */
  if(SSI_HANDLE->TxState == SSI_STATE_READY)
  {
    /* 待发送数据长度必须大于0，否则返回错误状态 */
    if((IE1 & 0x01 != 0) || (Size == 0U))
    {
      return Status_ERROR;
    }
    else
    {
      SSI_HANDLE->TxState = SSI_STATE_BUSY;			//发送进程忙碌中
      SSI_ClearFlag(TWI_FLAG_TWIF);			 //发送前清除标志位
      SSI_HANDLE->pTxBuffPtr.Size_u8 = pData;			//指向待发送数据的地址
      SSI_HANDLE->TxXferSize = Size;			//更新待发送的数据量
      SSI_HANDLE->TxXferCount = 0;			//发送计数器清零

      
      SSI_TWI_AcknowledgeConfig(ENABLE);         //开启AA使能位
      if(SSI_TWI_Wait_TWIF(SSI_HANDLE, Timeout) == Status_TIMEOUT)            //等待地址匹配
      {
        SSI_TWI_AcknowledgeConfig(DISABLE);            //关闭AA使能
        return Status_TIMEOUT;
      }

      do
      {
        if(SSI_GetTWIStatus(TWI_SlaveSendData) == SET)           //检测状态机状态
        {

          SSCON2 = *(SSI_HANDLE->pTxBuffPtr.Size_u8 + SSI_HANDLE->TxXferCount);             //TWI发送数据

          if(SSI_TWI_Wait_TWIF(SSI_HANDLE, Timeout) == Status_TIMEOUT)             //等待启动信号发送完毕
          {
            SSI_TWI_AcknowledgeConfig(DISABLE);            //关闭AA使能
            return Status_TIMEOUT;
          }
          SSI_HANDLE->TxXferCount++;

          if(SSI_HANDLE->TxXferCount == SSI_HANDLE->TxXferSize - 1)

            SSI_TWI_AcknowledgeConfig(DISABLE);            //关闭AA使能

        }
        else if(SSI_GetTWIStatus(TWI_SlaveDisableACK) == SET)
        {

          SSI_HANDLE->TxXferCount++;
        }
        else
        {
          SSI_HANDLE->TxState = SSI_STATE_ERROR;
          return Status_ERROR;
        }
      }
      while(SSI_HANDLE->TxXferCount < SSI_HANDLE->TxXferSize);

      if(SSI_GetTWIStatus(TWI_SlaveDisableACK) == RESET)           //检测状态机状态
      {
        SSI_HANDLE->TxState = SSI_STATE_ERROR;
        return Status_ERROR;
      }

      if(SSI_HANDLE->TxXferCount == SSI_HANDLE->TxXferSize)
      {
        SSI_HANDLE->TxState = SSI_STATE_READY;	//发送完成
        return Status_OK;
      }
      else
      {
        SSI_HANDLE->TxState = SSI_STATE_ERROR;//发生发送错误
        return Status_ERROR;
      }
    }
  }
  else
  {
    return Status_BUSY;
  }
}

/**
 * @brief  从机使用中断模式下发送大量数据时，先在main函数中调用此函数
 * @param  SSI_HANDLE[out]:指向包含指定SPI模块的配置信息结构体的指针
 * @param  pData[out]:指针指向存储区
 * @param  Size[in]:存储数据长度
 * @retval SSI 状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_TWI_Slave_Transmit_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size)
{
  /* 检查一个发送进程是否正在进行 */
  if(SSI_HANDLE->TxState == SSI_STATE_READY)
  {
    /* 待发送数据长度必须大于0，否则返回错误状态 */
    if(((IE1 & 0x01) == 0) || (Size == 0U))
    {
      return Status_ERROR;
    }
    else
    {
      
      SSI_TWI_AcknowledgeConfig(DISABLE);         //开启AA
      SSI_ClearFlag(TWI_FLAG_TWIF);			 //发送前清除标志位
      
      SSI_HANDLE->TxState = SSI_STATE_WAIT;			//发送进程忙碌中
      SSI_HANDLE->pTxBuffPtr.Size_u8 = pData;			//指向待发送数据的地址
      SSI_HANDLE->TxXferSize = Size;			//更新待发送的数据量
      SSI_HANDLE->TxXferCount = 0;			//发送计数器清零

      SSI_TWI_AcknowledgeConfig(ENABLE);         //开启AA

      return Status_OK;;
    }
  }
  else
  {
    return Status_ERROR;
  }
}

/**
 * @brief  发送8位数据时，从机中断模式下发送大量数据
 * @param  SSI_HANDLE[out]:指针指向SSI数据信息存放区
 * @retval SSI 状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_TWI_Slave_Transmit_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE)
{
  if(SSI_HANDLE->TxState == SSI_STATE_BUSY)
  {

    if(SSI_GetTWIStatus(TWI_SlaveSendData) == SET)
    {
      if(SSI_HANDLE->TxXferCount < SSI_HANDLE->TxXferSize)
      {
        SSI_HANDLE->TxXferCount++;			//第一次中断是接受到地址了
        SSCON2 = *(SSI_HANDLE->pTxBuffPtr.Size_u8 + SSI_HANDLE->TxXferCount);
        if(SSI_HANDLE->TxXferCount == SSI_HANDLE->TxXferSize - 1)
        {
          SSI_TWI_AcknowledgeConfig(DISABLE);         //关闭AA使能位
        }
        return Status_BUSY;
      }
      else
      {
        SSI_TWI_AcknowledgeConfig(DISABLE);         //关闭AA使能位
        SSI_HANDLE->TxState = SSI_STATE_ERROR;
        return Status_ERROR;
      }
    }
    /*
    1.但数据传输过程中，其他程序修改了AA控制位
    2.接收到主机回来的UACK */
    else if((SSI_GetTWIStatus(TWI_SlaveDisableACK) == SET) || (SSI_GetTWIStatus(TWI_SlaveReceivedaUACK) == SET))
    {
      SSI_TWI_AcknowledgeConfig(DISABLE);         //关闭AA使能位
		 SSI_HANDLE->TxXferCount++;
      if(SSI_HANDLE->TxXferCount == SSI_HANDLE->TxXferSize)			//所有数据已发送
      {
        SSI_HANDLE->TxState = SSI_STATE_READY;
        return Status_OK;
      }
      else
      {
        SSI_HANDLE->TxState = SSI_STATE_ERROR;
        return Status_ERROR;
      }
    }
    else
    {
      SSI_TWI_AcknowledgeConfig(DISABLE);         //关闭AA使能位
      /* 以下情况未发送过程出错
      1.数据发送后接受到UACK
      2.TWI不是工作在从机发送状态 */
      SSI_HANDLE->TxState = SSI_STATE_ERROR;
      return Status_ERROR;
    }
  }
  else if(SSI_HANDLE->TxState == SSI_STATE_WAIT)
  {
    if(SSI_GetTWIStatus(TWI_SlaveSendData) == SET)
    {
      SSCON2 = *(SSI_HANDLE->pTxBuffPtr.Size_u8 + SSI_HANDLE->TxXferCount);
      SSI_HANDLE->TxState = SSI_STATE_BUSY;
    }
    return Status_BUSY;
  }
  else
  {
    return Status_ERROR;//返回标志位
  }
}

/**
 * @brief  接收8位数据时，从机轮询模式下接收大量数据
 * @param  SSI_HANDLE[out]:指向包含指定SPI模块的配置信息结构体的指针
 * @param  pData[out]:接收数据的存放区
 * @param  Size[in]:待接收的数据量
 * @param  Timeout[in]:超时时间
 * @retval SSI 状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_TWI_Slave_Receive(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout)
{
  if(SSI_HANDLE->RxState == SSI_STATE_READY)
  {
    /* 待接收数据长度必须大于0，否则返回错误状态 */
    if((IE1 & 0x01 != 0) || (Size == 0U))
    {
      return Status_ERROR;
    }

    SSI_HANDLE->RxState = SSI_STATE_BUSY;			//接收进程忙碌中
    SSI_ClearFlag(TWI_FLAG_TWIF);			 //接收前清除标志位
    SSI_TWI_AcknowledgeConfig(ENABLE);         //开启AA使能位
    SSI_HANDLE->pRxBuffPtr.Size_u8 = pData;			//指向待接收数据的地址
    SSI_HANDLE->RxXferSize = Size;			//更新待接收的数据量
    SSI_HANDLE->RxXferCount = 0;			//接收计数器清零

    /* 接收地址工程 */
    if(SSI_TWI_Wait_TWIF(SSI_HANDLE, Timeout) == Status_TIMEOUT)            //等待信号接收完毕
    {
      /* 无论是否接收完成，都需要接收结束信号，防止主机占用总线 */
		 SSI_TWI_AcknowledgeConfig(DISABLE);         //关闭AA使能位
      return Status_TIMEOUT;
    }

    if(SSI_GetTWIStatus(TWI_SlaveReceivedaData) == RESET)           //检测状态机状态
    {
      SSI_HANDLE->RxState = SSI_STATE_ERROR;
      /* 无论是否接收完成，都需要接收结束信号，防止主机占用总线 */
		 SSI_TWI_AcknowledgeConfig(DISABLE);         //关闭AA使能位
      return Status_ERROR;
    }

    /* 接收数据过程 */
    do
    {
      if(SSI_TWI_Wait_TWIF(SSI_HANDLE, Timeout) == Status_TIMEOUT)            //等待启动信号发送完毕
      {
        return Status_TIMEOUT;
      }

      if(SSI_GetTWIStatus(TWI_SlaveReceivedaData) == SET)           //检测状态机状态
      {
        *(SSI_HANDLE->pRxBuffPtr.Size_u8 + SSI_HANDLE->RxXferCount) = SSCON2;             //TWI接收数据
        SSI_HANDLE->RxXferCount++;
        if(SSI_HANDLE->RxXferCount == SSI_HANDLE->RxXferSize - 1)
          SSI_TWI_AcknowledgeConfig(DISABLE);         //关闭AA使能位,回主机UAC
      }
      else if(SSI_GetTWIStatus(TWI_SlaveIdle) == SET)
      {
        if(SSI_HANDLE->RxXferCount == SSI_HANDLE->RxXferSize - 1)
        {
          *(SSI_HANDLE->pRxBuffPtr.Size_u8 + SSI_HANDLE->RxXferCount) = SSCON2;
          SSI_HANDLE->RxXferCount++;
        }
        else
        {
          SSI_HANDLE->RxState = SSI_STATE_ERROR;
          SSI_TWI_AcknowledgeConfig(DISABLE);         //关闭AA使能位
          return Status_ERROR;
        }
      }
      else
      {
        SSI_HANDLE->RxState = SSI_STATE_ERROR;
        SSI_TWI_AcknowledgeConfig(DISABLE);         //关闭AA使能位
        return Status_ERROR;
      }

    }
    while(SSI_HANDLE->RxXferCount < SSI_HANDLE->RxXferSize);

    if(SSI_HANDLE->RxXferCount == SSI_HANDLE->RxXferSize)
    {
      SSI_HANDLE->RxState = SSI_STATE_READY;	//接收完成
      return Status_OK;
    }
    else
    {
      SSI_HANDLE->RxState = SSI_STATE_ERROR;//发生接收错误
      return Status_ERROR;
    }
  }
  else
  {
    return Status_BUSY;
  }
}

/**
 * @brief  从机使用中断模式下接收大量数据时，先在main函数中调用此函数
 * @param  SSI_HANDLE[out]:指针指向SSI数据信息存放区
 * @param  pData[out]:接收数据的存放区
 * @param  Size[in]:待接收的数据量
 * @retval SSI 状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_TWI_Slave_Receive_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size)
{
  if(SSI_HANDLE->RxState == SSI_STATE_READY)
  {
    /* 待接收数据长度必须大于0，否则返回错误状态 */
    if(((IE1 & 0x01) == 0) || (Size == 0U))
    {
      return Status_ERROR;
    }
    
    SSI_TWI_AcknowledgeConfig(DISABLE);         //关闭AA使能位
    SSI_ClearFlag(TWI_FLAG_TWIF);			 //接收前清除标志位
    SSI_HANDLE->RxState = SSI_STATE_WAIT;			//接收进程忙碌中
    SSI_HANDLE->pRxBuffPtr.Size_u8 = pData;			//指向待接收数据的地址
    SSI_HANDLE->RxXferSize = Size;			//更新待接收的数据量
    SSI_HANDLE->RxXferCount = 0;			//接收计数器清零
    SSI_TWI_AcknowledgeConfig(ENABLE);         //开启AA使能位

    return Status_OK;
  }
  else
  {
    return Status_BUSY;
  }
}

/**
 * @brief  接收8位数据时，从机中断模式下接收大量数据
 * @param  SSI_HANDLE[out]:指针指向SSI数据信息存放区
 * @retval SSI 状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_TWI_Slave_Receive_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE)
{
  if(SSI_HANDLE->RxState == SSI_STATE_BUSY)
  {
    if(SSI_GetTWIStatus(TWI_SlaveReceivedaData) == SET)           //检测状态机状态
    {
      if(SSI_HANDLE->RxXferCount < SSI_HANDLE->RxXferSize)
      {
        *(SSI_HANDLE->pRxBuffPtr.Size_u8 + SSI_HANDLE->RxXferCount) = SSCON2;             //TWI发送数据
        SSI_HANDLE->RxXferCount++;
        if(SSI_HANDLE->RxXferCount == SSI_HANDLE->RxXferSize - 1)
        {
          SSI_TWI_AcknowledgeConfig(DISABLE);         //关闭AA使能位,回主机UACK
        }
      }
      else
      {
        SSI_TWI_AcknowledgeConfig(DISABLE);
        return Status_ERROR;
      }
      return Status_BUSY;
    }
    else if(SSI_GetTWIStatus(TWI_SlaveIdle) == SET)
    {
      if(SSI_HANDLE->RxXferCount == SSI_HANDLE->RxXferSize - 1)
      {
        *(SSI_HANDLE->pRxBuffPtr.Size_u8 + SSI_HANDLE->RxXferCount) = SSCON2;
        SSI_HANDLE->RxXferCount++;
        SSI_TWI_AcknowledgeConfig(DISABLE);         //关闭AA使能位,回主机UACK
        SSI_HANDLE->RxState = SSI_STATE_READY;
        return Status_OK;
      }
      else
      {
        SSI_TWI_AcknowledgeConfig(DISABLE);         //关闭AA使能位
        SSI_HANDLE->RxState = SSI_STATE_ERROR;
        return Status_ERROR;
      }
    }
    else
    {
      SSI_HANDLE->RxState = SSI_STATE_ERROR;
      SSI_TWI_AcknowledgeConfig(DISABLE);         //关闭AA使能位
      return Status_ERROR;
    }
  }
  else if(SSI_HANDLE->RxState == SSI_STATE_WAIT)
  {
    SSI_HANDLE->RxState = SSI_STATE_BUSY;
    return Status_BUSY;
  }
  else
  {
    return Status_ERROR;
  }
}

/**
 * @brief  UART1初始化配置函数
 * @param  UART1Fsys[in]:系统时钟频率
 * @param  BaudRate[in]:波特率
 * @param  Mode[in]:UART1工作模式
 *          - UART1_Mode_10B:UART1设置为10位模式
 *          - UART1_Mode_11B:UART1设置为11位模式
 * @param  RxMode[in]:接收允许选择
 *          - UART1_RX_ENABLE:UART1允许接收
 *          - UART1_RX_DISABLE:UART1禁止接收
 * @retval None
 */
void SSI_UART1_Init(uint32_t UART1Fsys,
                    uint32_t BaudRate, UART1_Mode_TypeDef Mode,
                    UART1_RX_TypeDef RxMode)
{

#if  defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x)
  OTCON |= 0xC0;
  SSCON0 = SSCON0 & 0X0F | Mode | RxMode;
  SSCON2 = UART1Fsys / 16 / BaudRate / 256;
  SSCON1 = UART1Fsys / 16 / BaudRate % 256;

#else
  OTCON |= 0xC0;
  SSCON0 = SSCON0 & 0X0F | Mode | RxMode;
  SSCON2 = UART1Fsys / BaudRate / 256;
  SSCON1 = UART1Fsys / BaudRate % 256;

#endif


}

/**
 * @brief  UART1发送8位数据
 * @param  Data[in]:发送的数据
 * @retval None
 */
void SSI_UART1_SendData8(uint8_t Data)
{
  SSDAT = Data;
}

/**
 * @brief  获得SSDAT中的值
 * @param  None
 * @retval UART接收到的8位数据
 */
uint8_t SSI_UART1_ReceiveData8(void)
{
  return SSDAT;
}

/**
 * @brief  UART1发送9位数据
 * @param  Data[in]:发送的数据
 * @retval None
 */
void SSI_UART1_SendData9(uint16_t Data)
{
  uint8_t Data_9Bit;
  Data_9Bit = (Data >> 8);

  if(Data_9Bit)
  {
    SSCON0	|= 0x08;
  }
  else
  {
    SSCON0	&= 0xf7;
  }

  SSDAT = (uint8_t)Data;
}

/**
 * @brief  获得SSDAT中的值及第九位的值
 * @param  None
 * @retval 接收到的数据
 */
uint16_t SSI_UART1_ReceiveData9(void)
{
  uint16_t Data9;
  Data9 =  SSDAT + (((uint16_t)(SSCON0 & 0X04) & 0x00FF) << 6);
  SSCON0 &= 0XFB;
  return Data9;
}

/**
 * @brief  UART在轮询模式下发送大量数据
 * @param  SSI_HANDLE[out]:指针指向SSI数据信息存放区
 * @param  pData[out]:接收数据的存放区
 * @param  Size[in]:待接收的数据量
 * @param  timeout[in]:超时时间设置
 * @retval SSI 状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_UART_Transmit(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout)
{
  uint32_t delaytime = 0;
  /* 检查一个发送进程是否正在进行 */
  if(SSI_HANDLE->TxState == SSI_STATE_READY)
  {
    /* 检查发送数据量是否为0 */
    if((IE1 & 0x01 != 0) || (Size == 0U))
    {
      return  Status_ERROR;
    }

    SSI_HANDLE->TxState = SSI_STATE_BUSY;			//发送进程忙碌中
    SSI_ClearFlag(UART1_FLAG_TI); //发送前清除发送中断标志，写1/写0清零
    SSI_HANDLE->pTxBuffPtr.Size_u8 = pData;			//指向待发送数据的地址
    SSI_HANDLE->TxXferSize = Size;			//更新待发送的数据量
    SSI_HANDLE->TxXferCount = 0;			//发送计数器清零

    while(SSI_HANDLE->TxXferCount < SSI_HANDLE->TxXferSize)//判断是否接收所有数据
    {
      if((SSCON0 & 0x80) == UART1_Mode_11B)
      {
        /* 发送9位数据 */
        SSI_UART1_SendData9(*(SSI_HANDLE->pTxBuffPtr.Size_u16 + SSI_HANDLE->TxXferCount));
      }
      else
      {
        /* 发送8位数据 */
        SSI_UART1_SendData8(*(SSI_HANDLE->pTxBuffPtr.Size_u8 + SSI_HANDLE->TxXferCount));
      }

      /* 等待发送完成 */
      delaytime = 0;
      while(!(SSCON0 & 0x02))
      {
        if(delaytime++ > Timeout)
        {
          SSI_HANDLE->TxState = SSI_STATE_TIMEOUT;//发送超时
          return Status_TIMEOUT;
        }
      }

      SSI_ClearFlag(UART1_FLAG_TI); //发送中断标志清除，写1/写0清零
      SSI_HANDLE->TxXferCount ++;	//发送数据量计数
    }

    if(SSI_HANDLE->TxXferCount == SSI_HANDLE->TxXferSize)
    {
      SSI_HANDLE->TxState = SSI_STATE_READY;	//发送完成
      return Status_OK;
    }
    else
    {
      SSI_HANDLE->TxState = SSI_STATE_ERROR;//发生发送错误
      return Status_ERROR;
    }
  }
  else
  {
    return Status_BUSY;//返回标志位
  }
}

/**
 * @brief  UART在中断模式下发送大量数据时，先在main函数中调用此函数
 * @param  SSI_HANDLE[out]:指针指向UART数据信息存放区
 * @param  pData[out]:接收数据的存放区
 * @param  Size[in]:待接收的数据量
 * @param  timeout[in]:超时时间设置
 * @retval 函数执行状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_UART_Transmit_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size)
{
  /* 检查一个发送进程是否正在进行 */
  if(SSI_HANDLE->TxState == SSI_STATE_READY)
  {
    /* 没有开启SSI中断或发送数据量大小为0，返回错误 */
    if(((IE1 & 0x01) == 0) || (Size == 0U))
    {
      return Status_ERROR;
    }

    SSI_HANDLE->TxState = SSI_STATE_BUSY;
    SSI_HANDLE->pTxBuffPtr.Size_u8 = pData;			//指向待发送数据的地址
    SSI_HANDLE->TxXferSize = Size;			//更新待发送的数据量
    SSI_HANDLE->TxXferCount = 0;			//发送计数器清零

    /* 发送第1帧数据 */
    if((SSCON0 & 0x80) == UART1_Mode_11B)
    {
      /* 发送9位数据 */
      SSI_UART1_SendData9(*(SSI_HANDLE->pTxBuffPtr.Size_u16 + SSI_HANDLE->TxXferCount));
    }
    else
    {
      /* 发送8位数据 */
      SSI_UART1_SendData8(*(SSI_HANDLE->pTxBuffPtr.Size_u8 + SSI_HANDLE->TxXferCount));
    }
    return Status_OK;
  }
  else
  {
    return Status_BUSY;//返回标志位
  }
}

/**
 * @brief  UART在中断模式下发送大量数据时，在中断服务函数中调用 注：该函数调用需要判断中断标志位是否置起
 * @param  SSI_HANDLE[out]:指针指向UART数据信息存放区
 * @retval 函数执行状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_UART_Transmit_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE)
{
  /* 处于发送线程 */
  if(SSI_HANDLE->TxState == SSI_STATE_BUSY)
  {
    SSI_HANDLE->TxXferCount++;
    /* 判断上一次发送是否是最后一次 */
    if(SSI_HANDLE->TxXferCount < SSI_HANDLE->TxXferSize)
    {
      /* 待发送数据量未为0，继续发送 */
      if((SSCON0 & 0x80) == UART1_Mode_11B)
      {
        /* 发送9位数据 */
        SSI_UART1_SendData9(*(SSI_HANDLE->pTxBuffPtr.Size_u16 + SSI_HANDLE->TxXferCount));
      }
      else
      {
        /* 发送8位数据 */
        SSI_UART1_SendData8(*(SSI_HANDLE->pTxBuffPtr.Size_u8 + SSI_HANDLE->TxXferCount));
      }
      return Status_BUSY;
    }
    else if(SSI_HANDLE->TxXferCount == SSI_HANDLE->TxXferSize)
    {
      /* 发送完成 */
      SSI_HANDLE->TxState = SSI_STATE_READY;
      return Status_OK;
    }
    else
    {
      /* 发送数据量为0时还发送数据，返回错误 */
      SSI_HANDLE->TxState = SSI_STATE_ERROR;
      return Status_ERROR;
    }
  }
  else
  {
    return Status_BUSY;
  }
}

/**
 * @brief  UART在轮询模式下接收大量数据
 * @param  SSI_HANDLE[out]:指针指向UART数据信息存放区
 * @param  pData[out]:接收数据的存放区
 * @param  Size[in]:待接收的数据量
 * @param  timeout[in]:超时时间设置
 * @retval 函数执行状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_UART_Receive(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size, uint32_t Timeout)
{
  uint32_t delaytime = 0;
  /* 检查接收进程正在运行 */
  if(SSI_HANDLE->RxState == SSI_STATE_READY)
  {
    /* 检查接收数据量大小和是否开启接收使能 */
    if((IE1 & 0x01 != 0) || (Size == 0U) || ((SSCON0 & 0x10) != UART1_RX_ENABLE))
    {
      return  Status_ERROR;
    }

    SSI_HANDLE->RxState = SSI_STATE_BUSY;			//接收进程忙碌中
    SSI_ClearFlag(UART1_FLAG_RI);			 //接收前清除接收中断标志
    SSI_HANDLE->pRxBuffPtr.Size_u8 = pData;			//指向待接收数据的地址
    SSI_HANDLE->RxXferSize = Size;			//更新待接收的数据量
    SSI_HANDLE->RxXferCount = 0;			//接收计数器清零

    while(SSI_HANDLE->RxXferCount < SSI_HANDLE->RxXferSize) //判断是否接收所有数据
    {
      if(SSI_GetFlagStatus(UART1_FLAG_RI)) //判断接收标志位
      {
        SSI_ClearFlag(UART1_FLAG_RI);			//接收标志位清零

        /* 待接收数据量未为0，继续发送 */
        if((SSCON0 & 0x80) == UART1_Mode_11B)
        {
          /* 接收9位数据 */
          *(SSI_HANDLE->pRxBuffPtr.Size_u16 + SSI_HANDLE->RxXferCount) = SSI_UART1_ReceiveData9();
        }
        else
        {
          /* 接收8位数据 */
          *(SSI_HANDLE->pRxBuffPtr.Size_u8 + SSI_HANDLE->RxXferCount) = SSI_UART1_ReceiveData8();
        }

        SSI_HANDLE->RxXferCount++;	//接收数据量计数
        delaytime = 0;//收到数据，超时计数清零
      }
      if(delaytime++ > Timeout)//计时溢出
      {
        SSI_HANDLE->RxState = SSI_STATE_TIMEOUT;//接收超时
        return Status_TIMEOUT;
      }
    }

    if(SSI_HANDLE->RxXferCount == SSI_HANDLE->RxXferSize)
    {
      SSI_HANDLE->RxState = SSI_STATE_READY;	//接收完成
      return Status_OK;
    }
    else
    {
      SSI_HANDLE->RxState = SSI_STATE_ERROR;//发生接收错误
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
 * @param  SSI_HANDLE[out]:指针指向UART数据信息存放区
 * @param  pData[out]:接收数据的存放区
 * @param  Size[in]:待接收的数据量
 * @retval 函数执行状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_UART_Receive_IT(SSI_HandleInfoDef* SSI_HANDLE, uint8_t* pData, uint8_t Size)
{
  /* 检查一个接收进程是否正在进行 */
  if(SSI_HANDLE->RxState == SSI_STATE_READY)
  {
    /* 检查是否开启SSI_UART中断或发送数据量大小为0或是否开启接收使能，返回错误 */
    if(((IE1 & 0x01) == 0) || (Size == 0U) || ((SSCON0 & 0x10) != UART1_RX_ENABLE))
    {
      return Status_ERROR;
    }

    SSI_HANDLE->RxState = SSI_STATE_BUSY;
    SSI_HANDLE->pRxBuffPtr.Size_u8 = pData;			//指向接收数据的存放地址
    SSI_HANDLE->RxXferSize = Size;			//更新待接收的数据量
    SSI_HANDLE->RxXferCount = 0;			//接收计数器清零

    return Status_OK;
  }
  else
  {
    return Status_BUSY;//返回标志位
  }
}

/**
 * @brief  UART在中断模式下接收大量数据时，在中断服务函数中调用 注：该函数调用需要判断中断标志位是否置起
 * @param  SSI_HANDLE[out]:指针指向SSI数据信息存放区
 * @retval 函数执行状态
 *          - Status_ERROR:错误
 *          - Status_OK:正常
 *          - Status_BUSY:正忙
 *          - Status_TIMEOUT:超时
 */
StatusTypeDef SSI_UART1_Receive_IRQHandler(SSI_HandleInfoDef* SSI_HANDLE)
{
  /* 检查一个接收进程是否正在进行 */
  if(SSI_HANDLE->RxState == SSI_STATE_BUSY)
  {
    /* 处于接收线程，检查待接收数据量是否为0 */
    if(SSI_HANDLE->RxXferCount < SSI_HANDLE->RxXferSize)
    {
      /* 待接收数据量未为0，继续接收 */
      if((SSCON0 & 0x80) == UART1_Mode_11B)
      {
        /* 接收9位数据 */
        *(SSI_HANDLE->pRxBuffPtr.Size_u16 + SSI_HANDLE->RxXferCount) = SSI_UART1_ReceiveData9();
      }
      else
      {
        /* 接收8位数据 */
        *(SSI_HANDLE->pRxBuffPtr.Size_u8 + SSI_HANDLE->RxXferCount) = SSI_UART1_ReceiveData8();
      }
      SSI_HANDLE->RxXferCount ++;
      /* 判断上一次发送是否是最后一次 */
      if(SSI_HANDLE->RxXferCount == SSI_HANDLE->RxXferSize)
      {
        /* 接收完成 */
        SSI_HANDLE->RxState = SSI_STATE_READY;
        return Status_OK;
			}
        return Status_BUSY;
    }
    else
    {
      /* 接收数据量为0时还接收数据，返回错误 */
      SSI_HANDLE->RxState = SSI_STATE_ERROR;
      return Status_ERROR;
    }
  }
  else
  {
    return Status_BUSY;
  }
}

/**
 * @brief  SSI中断初始化
 * @param  NewState[in]: 断使能/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @param  Priority[in]: 中断优先级选择
 *              - LOW:低
 *              - HIGH:高
 * @retval None
 */ 
void SSI_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority)
{
  if(NewState != DISABLE)
  {
    IE1 |= 0x01;
  }
  else
  {
    IE1 &= 0xFE;
  }

  /************************************************************/
  if(Priority != LOW)
  {
    IP1 |= 0x01;
  }
  else
  {
    IP1 &= 0xFE;
  }
}

/**
 * @brief  获得SSI标志状态
 * @param  SSI_FLAG[in]:所需获取的标志位
 *              - SPI_FLAG_SPIF:SPI数据传送标志位SPIF
 *              - SPI_FLAG_WCOL:SPI写入冲突标志位WCOL
 *              - SPI_FLAG_TXE:SPI发送缓存器空标志TXE
 *              - TWI_FLAG_TWIF:TWI中断标志位TWIF
 *              - TWI_FLAG_GCA:TWI通用地址响应标志位GCA
 *              - UART1_FLAG_TI:UART1发送中断标志位TI
 *              - UART1_FLAG_RI:UART1接收中断标志位RI
 * @retval SSI标志位置起状态
 *              - RESET:置零
 *              - SET:置起
 */
FlagStatus SSI_GetFlagStatus(SSI_Flag_TypeDef
                             SSI_FLAG)
{
  FlagStatus bitstatus = RESET;

  if((SSI_FLAG == SPI_FLAG_SPIF) ||
      (SSI_FLAG == SPI_FLAG_WCOL) ||
      (SSI_FLAG == SPI_FLAG_TXE))
  {
    if((SSI_FLAG & SSCON1) != (uint8_t)RESET)
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
    if((SSI_FLAG & SSCON0) != (uint8_t)RESET)
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
 * @brief  清除SSI标志状态
 * @param  SSI_FLAG[in]:所需清除的标志位
 *              - SPI_FLAG_SPIF:SPI数据传送标志位SPIF
 *              - SPI_FLAG_WCOL:SPI写入冲突标志位WCOL
 *              - SPI_FLAG_TXE:SPI发送缓存器空标志TXE
 *              - TWI_FLAG_TWIF:TWI中断标志位TWIF
 *              - TWI_FLAG_GCA:TWI通用地址响应标志位GCA
 *              - UART1_FLAG_TI:UART1发送中断标志位TI
 *              - UART1_FLAG_RI:UART1接收中断标志位RI
 * @retval None
 */
void SSI_ClearFlag(SSI_Flag_TypeDef SSI_FLAG)
{
  if((SSI_FLAG == SPI_FLAG_SPIF) ||
      (SSI_FLAG == SPI_FLAG_WCOL) ||
      (SSI_FLAG == SPI_FLAG_TXE))
  {
    SSCON1 &= (~SSI_FLAG);
  }
  else if(SSI_FLAG == TWI_FLAG_TWIF)
	{
		SSCON0 &= (~SSI_FLAG);
	}
	else
  {
		#if defined (SC92F84Hx) || defined(SC92F83Hx) || defined (SC92F6x1x) || defined (SC92F5x1x) || defined (SC92R436) || defined (SC92R438)|| defined (SC92R439)\
		    || defined(SC92R422A)|| defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)|| defined(SC92F5x5x)|| defined(SC92F531x)|| defined(SC92F563x)
		if(SSI_FLAG == UART1_FLAG_TI)
		{
			SSCON0 &= (~UART1_FLAG_RI);
		}
		else
		{
			SSCON0 &= (~UART1_FLAG_TI);
		}
		#else
		SSCON0 &= (~SSI_FLAG);
    #endif
	}
	
}

#if defined (SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)|| defined (SC92F5x5x) || defined (SC92F531x) || defined (SC92F637x)|| defined(SC92F563x)
#if defined (SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)
uint8_t xdata SPOS_SSICK _at_ 0x102D;
uint8_t xdata SPOS_SSITX _at_ 0x102E;
uint8_t xdata SPOS_SSIRX _at_ 0x102F;
#elif defined (SC92F5x5x) || defined (SC92F531x)
uint8_t xdata SPOS_SSICK _at_ 0x11D;
uint8_t xdata SPOS_SSITX _at_ 0x11E;
uint8_t xdata SPOS_SSIRX _at_ 0x11F;
#elif defined (SC92F637x)
uint8_t xdata SPOS_SSITX _at_ 0x108;
uint8_t xdata SPOS_SSIRX _at_ 0x109;
uint8_t xdata SPOS_SSICK _at_ 0x10A;
#elif defined (SC92F563x)
uint8_t xdata SPOS_SSITX _at_ 0x103B;
uint8_t xdata SPOS_SSIRX _at_ 0x103C;
uint8_t xdata SPOS_SSICK _at_ 0x103D;
#endif

#if defined (SC92F563x)
/**
 * @brief  SSI端口映射函数
 * @param  SSIxx_MappingPin[in]: SSI端口映射管脚选择
 *          - SSIMapped_to_P02:SSI端口映射到P02
 *          - SSIMapped_to_P54:SSI端口映射到P54
 *          - SSIMapped_to_P55:SSI端口映射到P55
 *          - SSIMapped_to_P47:SSI端口映射到P47
 *          - SSIMapped_to_P43:SSI端口映射到P43
 *          - SSIMapped_to_P42:SSI端口映射到P42
 *          - SSIMapped_to_P41:SSI端口映射到P41
 *          - SSIMapped_to_P22:SSI端口映射到P22
 *          - SSIMapped_to_P23:SSI端口映射到P23
 *          - SSIMapped_to_P24:SSI端口映射到P24
 *          - SSIMapped_to_P25:SSI端口映射到P25
 *          - SSIMapped_to_P26:SSI端口映射到P26
 * @retval None
 */ 
void SSI_PortMapping(SSI_PortMappingPin_TypeDef SSICK_MappingPin,
	                   SSI_PortMappingPin_TypeDef SSITX_MappingPin,
										 SSI_PortMappingPin_TypeDef SSIRX_MappingPin)
{
	SPOS_SSICK = SPOS_SSICK & 0xE0 | SSICK_MappingPin;
	SPOS_SSITX = SPOS_SSITX & 0xE0 | SSITX_MappingPin;
	SPOS_SSIRX = SPOS_SSIRX & 0xE0 | SSIRX_MappingPin;
}
#else
/**
 * @brief  SSI端口映射函数
 * @param  SSIxx_MappingPin[in]: SSI端口映射管脚选择
 *          - SSIMapped_to_P50:SSI端口映射到P50
 *          - SSIMapped_to_P51:SSI端口映射到P51
 *          - SSIMapped_to_P52:SSI端口映射到P52
 *          - SSIMapped_to_P53:SSI端口映射到P53
 *          - SSIMapped_to_P54:SSI端口映射到P54
 *          - SSIMapped_to_P56:SSI端口映射到P56
 *          - SSIMapped_to_P57:SSI端口映射到P57
 *          - SSIMapped_to_P10:SSI端口映射到P10
 *          - SSIMapped_to_P11:SSI端口映射到P11
 *          - SSIMapped_to_P12:SSI端口映射到P12
 *          - SSIMapped_to_P13:SSI端口映射到P13
 *          - SSIMapped_to_P14:SSI端口映射到P14
 *          - SSIMapped_to_P15:SSI端口映射到P15
 *          - SSIMapped_to_P16:SSI端口映射到P16
 *          - SSIMapped_to_P17:SSI端口映射到P17
 *          - SSIMapped_to_P27:SSI端口映射到P27
 *          - SSIMapped_to_P26:SSI端口映射到P26
 *          - SSIMapped_to_P25:SSI端口映射到P25
 *          - SSIMapped_to_P24:SSI端口映射到P24
 *          - SSIMapped_to_P23:SSI端口映射到P23
 *          - SSIMapped_to_P22:SSI端口映射到P22
 *          - SSIMapped_to_P07:SSI端口映射到P07
 *          - SSIMapped_to_P06:SSI端口映射到P06
 *          - SSIMapped_to_P04:SSI端口映射到P04
 *          - SSIMapped_to_P03:SSI端口映射到P03
 *          - SSIMapped_to_P02:SSI端口映射到P02
 *          - SSIMapped_to_P01:SSI端口映射到P01
 *          - SSIMapped_to_P00:SSI端口映射到P00
 * @retval None
 */ 
void SSI_PortMapping(SSI_PortMappingPin_TypeDef SSICK_MappingPin,
	                   SSI_PortMappingPin_TypeDef SSITX_MappingPin,
										 SSI_PortMappingPin_TypeDef SSIRX_MappingPin)
{
	SPOS_SSICK = SPOS_SSICK & 0xF0 | SSICK_MappingPin;
	SPOS_SSITX = SPOS_SSITX & 0xF0 | SSITX_MappingPin;
	SPOS_SSIRX = SPOS_SSIRX & 0xF0 | SSIRX_MappingPin;
}
#endif

#endif
/**
 * @}
 */
/* End of SSI_Group2.	*/
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
/********* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/
