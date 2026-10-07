/**
 ******************************************************************************
 * @file    sc92f_timer2.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   TIM0 function module
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
#include "sc92f_timer2.h"

#if !defined (SC92L853x) && !defined(SC92L753x) && !defined(SC92F84Hx) && !defined(SC92F83Hx) && !defined(SC92F646x) && !defined(SC92F546x) && !defined(SC92F542x)\
		&& !defined (SC92F652x) && !defined(SC92R51x_R52x) && !defined(SC92F552x) && !defined(SC92F637x) && !defined(SC92F663x) && !defined(SC92F563x)
/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup TIM2
 * @brief TIM2 driver modules
 * @{
 */

/** @defgroup TIM2_Functions
 * @{
 */

/** @defgroup TIM2_Group1 Configuration of the TIM2 computation unit functions
 *  @brief   Configuration of the TIM2 computation unit functions
 *
 
@verbatim
 ===============================================================================
                     ##### TIM2 configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */
  
/**
 * @brief  TIMER2相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void TIM2_DeInit(void)
{
  T2CON = 0X00;
#if !defined (SC92F730x) && !defined (SC92F827X) && !defined (SC92F837X) && !defined (SC92F725X) && !defined (SC92F735X) && !defined (SC92F730x_2) \
	  && !defined (SC92F720x) &&!defined(SC92F7308B)
  T2MOD = 0X00;
#endif
#if !defined (SC92F5x5x) && !defined (SC92F531x)
  TMCON &= 0XFB;
#endif
  TH2 = 0X00;
  TL2 = 0X00;
  RCAP2H = 0X00;
  RCAP2L = 0X00;
  ET2 = 0;
  IPT2 = 0;
}

/**
 * @brief  TIMER2基本设置配置函数
 * @param  TIM2_PrescalerSelection[in]:预分频选择
 *          - TIM2_PRESSEL_FSYS_D12:TIMER2计数源来自系统时钟12分频
 *          - TIM2_PRESSEL_FSYS_D1:TIMER2计数源来自系统时钟
 * @param  TIM2_CountMode[in]:计数/定时模式选择
 *          - TIM2_MODE_TIMER:TIMER2做定时器
 *          - TIM2_MODE_COUNTER:TIMER2做计数器
 * @param  TIM2_CountDirection[in]:计数/定时模式选择
 *          - TIM2_COUNTDIRECTION_UP:向上计数模式
 *          - TIM2_COUNTDIRECTION_DOWN_UP:向上/向下计数模式
 * @retval None
 */ 
void TIM2_TimeBaseInit(TIM2_PresSel_TypeDef
                       TIM2_PrescalerSelection,
                       TIM2_CountMode_TypeDef TIM2_CountMode,
                       TIM2_CountDirection_TypeDef TIM2_CountDirection)
{
#if !defined (SC92F6x1x) && !defined (SC92F5x1x) && !defined (SC92R436)&& !defined (SC92R438)&& !defined (SC92R439)&& !defined (SC92R422A)\
		&& !defined (SC92F5x5x) && !defined (SC92F531x)
  if(TIM2_PrescalerSelection == TIM2_PRESSEL_FSYS_D12)
  {
    TMCON &= 0XFB;
  }
  else if(TIM2_PrescalerSelection == TIM2_PRESSEL_FSYS_D1)
  {
    TMCON |= 0X04;
  }
#else
  if(TIM2_PrescalerSelection == TIM2_PRESSEL_FSYS_D12)
  {
    T2MOD &=~0x80;
  }
  else 
  {
    T2MOD |= 0x80;
  }
#endif	


#if !defined (SC92F730x) && !defined (SC92F827X) && !defined (SC92F837X) && !defined (SC92F725X) && !defined (SC92F735X)\
		&& !defined (SC92F825X) && !defined (SC92F835X) && !defined (SC92F730x_2) && !defined (SC92F720x) && !defined (SC92F7308B)

  if(TIM2_CountDirection == TIM2_COUNTDIRECTION_UP)
  {
    T2MOD &= 0XFE;
  }
  else if(TIM2_CountDirection ==
          TIM2_COUNTDIRECTION_DOWN_UP)
  {
    T2MOD |= 0X01;
  }
#if !defined (SC92F5x5x)
  if(TIM2_CountMode == TIM2_MODE_TIMER)
  {
    T2CON &= 0XFD;
  }
  else if(TIM2_CountMode == TIM2_MODE_COUNTER)
  {
    T2CON |= 0X02;
  }
#else
	TIM2_CountMode = 1;
#endif
	

	

#else
  TIM2_CountMode = 1;
  TIM2_CountDidrection = 0;
#endif

}


/**
 * @brief  TIMER2工作模式1配置函数
 * @param  TIM2_SetCounter[in]:配置计数初值
 * @retval None
 */
void TIM2_WorkMode1Config(uint16_t TIM2_SetCounter)
{
  RCAP2L = TIM2_SetCounter % 256;
  RCAP2H = TIM2_SetCounter / 256;
  TL2 = RCAP2L;
  TH2 = RCAP2H;
}

/**
 * @brief  TIMER2工作模式配置函数
 * @param  TIM2_WorkMode_TypeDef[in]:TIMER2工作模式选择
 *          - TIM2_WORK_MODE0:TIMER2选择工作模式0
 *          - TIM2_WORK_MODE1:TIMER2选择工作模式1
 *          - TIM2_WORK_MODE3:TIMER2选择工作模式3
 * @param  TIM2_SetCounter[in]:TIMER2计数初值配置
 * @retval None
 */
void TIM2_WorkModeConfig(TIM2_WorkMode_TypeDef
                         TIM2_WorkMode, uint16_t TIM2_SetCounter)
{
  switch(TIM2_WorkMode)
  {
    case TIM2_WORK_MODE1:
      TIM2_WorkMode1Config(TIM2_SetCounter);
      break;
#if !defined (SC92F730x) && !defined (SC92F827X) && !defined (SC92F837X) && !defined (SC92F725X) && !defined (SC92F735X) && !defined (SC92F725X) && !defined (SC92F730x_2)\
		&& !defined (SC92F720x)  && !defined (SC92F7308B)
    case TIM2_WORK_MODE0:
      TIM2_WorkMode0Config(TIM2_SetCounter);
      break;
#if !defined (SC92F5x5x)
    case TIM2_WORK_MODE3:
      TIM2_WorkMode3Config(TIM2_SetCounter);
      break;
#endif
#endif
    default:
      break;
  }
}

#if !defined (SC92F730x) && !defined (SC92F827X) && !defined (SC92F837X) && !defined (SC92F725X) && !defined (SC92F735X) && !defined (SC92F730x_2) && !defined (SC92F720x)\
 && !defined (SC92F7308B)
/**
 * @brief  TIMER2工作模式0配置函数
 * @param  TIM2_SetCounter[in]:配置计数初值
 * @retval None
 */
void TIM2_WorkMode0Config(uint16_t TIM2_SetCounter)
{
  T2CON |= 0x09;
  TL2 = TIM2_SetCounter % 256;
  TH2 = TIM2_SetCounter / 256;
}

#if !defined (SC92F5x5x)
/**
 * @brief  TIMER2工作模式3配置函数
 * @param  TIM2_SetCounter[in]:配置计数初值
 * @retval None
 */
void TIM2_WorkMode3Config(uint16_t TIM2_SetCounter)
{
  RCAP2L = TIM2_SetCounter % 256;
  RCAP2H = TIM2_SetCounter / 256;
  T2MOD |= 0X02;
}
#endif

/**
 * @brief  TIMER2_EXEN2配置函数
 * @param  NewState[in]:EXEN2使能选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */
void TIM2_SetEXEN2(FunctionalState NewState)
{
  if(NewState == DISABLE)
  {
    EXEN2 = 0;
  }
  else
  {
    EXEN2 = 1;
  }
}
#endif

/**
 * @brief  TIMER2功能开关函数
 * @param  NewState[in]:功能启动/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */
void TIM2_Cmd(FunctionalState NewState)
{
  if(NewState == DISABLE)
  {
    TR2 = 0;
  }
  else
  {
    TR2 = 1;
  }
}

/**
 * @}
 */
/* End of TIM2_Group1.	*/

/** @defgroup TIM2_Group2 Interrupts and flags management functions
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
 * @brief  TIMER2中断初始化
 * @param  NewState[in]: 断使能/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @param  Priority[in]: 中断优先级选择
 *              - LOW:低
 *              - HIGH:高
 * @retval None
 */
void TIM2_ITConfig(FunctionalState NewState,
                   PriorityStatus Priority)
{
  if(NewState == DISABLE)
  {
    ET2 = 0;
  }
  else
  {
    ET2 = 1;
  }

  /************************************************************/
  if(Priority == LOW)
  {
    IPT2 = 0;
  }
  else
  {
    IPT2 = 1;
  }
}

/**
 * @brief  获得TIMER2中断标志状态
 * @param  TIM2_Flag[in]:待读取的FLAG标志
 * @retval TIMER2中断标志状态
 *                  - RESET:置零
 *                  - SET:置起
 */ 
FlagStatus TIM2_GetFlagStatus(TIM2_Flag_TypeDef TIM2_Flag)
{
  FlagStatus status = RESET;

  if((TIM2_Flag & T2CON) != (uint8_t)RESET)
  {
    status = SET;
  }
  else
  {
    status = RESET;
  }

  return status;
}

/**
 * @brief  清除TIMER2中断标志状态
 * @param  None
 * @retval None
 */
void TIM2_ClearFlag(TIM2_Flag_TypeDef TIM2_Flag)
{
  T2CON &= (~TIM2_Flag);
}


/**
 * @}
 */
/* End of TIM2_Group2.	*/
#else
/** @defgroup TIM2_Group1 Configuration of the TIM2 computation unit functions
 *  @brief   Configuration of the TIM2 computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### TIM2 configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  TIMER2相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void TIM2_DeInit()
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x02; //TIMER2选择
  TXCON = 0X00;
  TXMOD = 0X00;
  RCAPXH = 0X00;
  RCAPXL = 0X00;
  THX = 0X00;
  TLX = 0X00;
  ET2 = 0;
  IPT2 = 0;
	TXINX = TXINX_Stack;
}

#if defined(SC92F84Hx) || defined(SC92F83Hx)
/**
 * @brief  TIM2引脚选择
 * @param  PinSeletion[in]:TIMER1工作模式选择
 *          - TIM2_PinRemap_Default:TIM2引脚为默认引脚
 *          - TIM2_PinRemap_A:TIM2引脚为A组引脚
 * @retval None
 */ 
void TIM2_PinSelection(TIM2_PinSelection_TypeDef PinSeletion)
{
	TMCON = TMCON & 0XFB | PinSeletion;
}
#endif
/**
 * @brief  TIMER2 预分频选择
 * @param  TIM2_PrescalerSelection[in]:预分频选择
 *          - TIM2_PRESSEL_FSYS_D12:TIMER2计数源来自系统时钟12分频
 *          - TIM2_PRESSEL_FSYS_D1:TIMER2计数源来自系统时钟
 * @retval None
 */
void TIM2_PrescalerSelection(TIM2_PresSel_TypeDef TIM2_PrescalerSelection)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x02;

  if (TIM2_PrescalerSelection == TIM2_PRESSEL_FSYS_D12)
  {
    TXMOD &= 0X7F;
  }
  else if (TIM2_PrescalerSelection == TIM2_PRESSEL_FSYS_D1)
  {
    TXMOD |= 0X80;
  }
	
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIM2基本设置配置函数
 * @param  TIM2_PrescalerSelection[in]:预分频选择
 *          - TIM2_PRESSEL_FSYS_D12:TIMER2计数源来自系统时钟12分频
 *          - TIM2_PRESSEL_FSYS_D1:TIMER2计数源来自系统时钟
 * @param  TIM2_CountMode[in]:计数/定时模式选择
 *          - TIM2_MODE_TIMER:TIMER2做定时器
 *          - TIM2_MODE_COUNTER:TIMER2做计数器
 * @param  TIM2_CountDirection[in]:计数/定时模式选择
 *          - TIM2_COUNTDIRECTION_UP:向上计数模式
 *          - TIM2_COUNTDIRECTION_DOWN_UP:向上/向下计数模式
 * @retval None
 */
void TIM2_TimeBaseInit(TIM2_PresSel_TypeDef TIM2_PrescalerSelection,
                       TIM2_CountMode_TypeDef TIM2_CountMode,
                       TIM2_CountDirection_TypeDef TIM2_CountDirection)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x02;
	
	if (TIM2_PrescalerSelection == TIM2_PRESSEL_FSYS_D12)
  {
    TXMOD &= 0X7F;
  }
  else if (TIM2_PrescalerSelection == TIM2_PRESSEL_FSYS_D1)
  {
    TXMOD |= 0X80;
  }
	
  if (TIM2_CountMode == TIM2_MODE_TIMER)
  {
    TXCON &= 0XFD;
  }
  else if (TIM2_CountMode == TIM2_MODE_COUNTER)
  {
    TXCON |= 0X02;
  }

  if (TIM2_CountDirection == TIM2_COUNTDIRECTION_UP)
  {
    TXMOD &= 0XFE;
  }
  else if (TIM2_CountDirection == TIM2_COUNTDIRECTION_DOWN_UP)
  {
    TXMOD |= 0X01;
  }
	
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIMER2工作模式0配置函数
 * @param  TIM2_SetCounter[in]:配置计数初值
 * @retval None
 */ 
void TIM2_WorkMode0Config(uint16_t TIM2_SetCounter)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x02;

  CP = 1;
  TLX = TIM2_SetCounter % 256;
  THX = TIM2_SetCounter / 256;
	
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIMER2工作模式1配置函数
 * @param  TIM2_SetCounter[in]:配置计数初值
 * @retval None
 */
void TIM2_WorkMode1Config(uint16_t TIM2_SetCounter)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x02;

  RCAPXL = TIM2_SetCounter % 256;
  RCAPXH = TIM2_SetCounter / 256;

  TLX = RCAPXL;
  THX = RCAPXH;
	
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIMER2工作模式3配置函数
 * @param  TIM1_SetCounter[in]:配置计数初值
 * @retval None
 */ 
void TIM2_WorkMode3Config(uint16_t TIM2_SetCounter)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x02;

  RCAPXL = TIM2_SetCounter % 256;
  RCAPXH = TIM2_SetCounter / 256;
  TXMOD |= 0X02;
	
	TXINX = TXINX_Stack;
}
/**
 * @brief  TIMER2工作模式配置函数
 * @param  TIM2_WorkMode[in]:TIMER1工作模式选择
 *          - TIM2_WORK_MODE0:TIMER2选择工作模式0
 *          - TIM2_WORK_MODE1:TIMER2选择工作模式1
 *          - TIM2_WORK_MODE3:TIMER2选择工作模式3
 * @param  TIM2_SetCounter[in]:TIMER2计数初值配置
 * @retval None
 */ 
void TIM2_WorkModeConfig(TIM2_WorkMode_TypeDef TIM2_WorkMode, uint16_t TIM2_SetCounter)
{
  switch (TIM2_WorkMode)
  {
  case TIM2_WORK_MODE0:
    TIM2_WorkMode0Config(TIM2_SetCounter);
    break;

  case TIM2_WORK_MODE1:
    TIM2_WorkMode1Config(TIM2_SetCounter);
    break;

  case TIM2_WORK_MODE3:
    TIM2_WorkMode3Config(TIM2_SetCounter);
    break;

  default:
    break;
  }
}
/**
 * @brief  TIMER2_EXEN2配置函数
 * @param  NewState[in]:EXEN2使能选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */
void TIM2_SetEXEN2(FunctionalState NewState)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x02;

  if (NewState == DISABLE)
  {
    EXENX = 0;
  }
  else
  {
    EXENX = 1;
  }
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIMER2功能开关函数
 * @param  NewState[in]:功能启动/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */
void TIM2_Cmd(FunctionalState NewState)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x02;

  if (NewState == DISABLE)
  {
    TRX = 0;
  }
  else
  {
    TRX = 1;
  }
	TXINX = TXINX_Stack;
}

/**
 * @}
 */
/* End of TIM2_Group1.	*/

/** @defgroup TIM2_Group2 Interrupts and flags management functions
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
 * @brief  TIMER2中断初始化
 * @param  NewState[in]: 断使能/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @param  Priority[in]: 中断优先级选择
 *              - LOW:低
 *              - HIGH:高
 * @retval None
 */
void TIM2_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x02;

  if (NewState == DISABLE)
  {
    ET2 = 0;
  }
  else
  {
    ET2 = 1;
  }

  if (Priority == LOW)
  {
    IPT2 = 0;
  }
  else
  {
    IPT2 = 1;
  }
	TXINX = TXINX_Stack;
}

/**
 * @brief  获得TIMER2中断标志状态
 * @param  TIM2_Flag[in]:TIMER2标志选择
 *          - TIM2_FLAG_TF2:中断标志位TF2，计数溢出
 *          - TIM2_FLAG_EXF2:中断标志位EXF2，外部触发
 * @retval TIMER2中断标志状态
 *                  - RESET:置零
 *                  - SET:置起
 */ 
FlagStatus TIM2_GetFlagStatus(TIM2_Flag_TypeDef TIM2_Flag)
{
	unsigned char TXINX_Stack = TXINX;
  FlagStatus status = RESET;
  TXINX = 0x02;

  if ((TIM2_Flag & TXCON) != (uint8_t)RESET)
  {
    status = SET;
  }
  else
  {
    status = RESET;
  }
  TXINX = TXINX_Stack;
  return status;
}

/**
 * @brief  清除TIMER2中断标志状态
 * @param  TIM2_Flag[in]:TIMER2标志选择
 *          - TIM2_FLAG_TF2:中断标志位TF2，计数溢出
 *          - TIM2_FLAG_EXF2:中断标志位EXF2，外部触发
 * @retval TIMER2中断标志状态
 *                  - RESET:置零
 *                  - SET:置起
 */
void TIM2_ClearFlag(TIM2_Flag_TypeDef TIM2_Flag)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x02;
  TXCON &= (~TIM2_Flag);
  TXINX = TXINX_Stack;
}

#if defined (SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)|| defined (SC92F5x5x) || defined (SC92F531x)
#if defined (SC92F5x5x) || defined (SC92F531x)
uint8_t xdata SPOS_T2EX _at_ 0x122;
#else
uint8_t xdata SPOS_T2EX _at_ 0x1032;
#endif
/**
 * @brief  T2EX端口映射函数
 * @param  T2EX_MappingPin[in]: T2EX端口映射管脚选择
 *          SC92F5x5x:
 *          - T2EXMapped_to_P00:T2EX映射到P00
 *          - T2EXMapped_to_P01:T2EX映射到P01
 *          - T2EXMapped_to_P05:T2EX映射到P05
 *  				- T2EXMapped_to_P20:T2EX映射到P20
 *					- T2EXMapped_to_P21:T2EX映射到P21
 *					- T2EXMapped_to_P22:T2EX映射到P22
 * 					- T2EXMapped_to_P23:T2EX映射到P23
 * 					- T2EXMapped_to_P24:T2EX映射到P24
 * 					- T2EXMapped_to_P25:T2EX映射到P25
 * 					- T2EXMapped_to_P26:T2EX映射到P26
 *				  - T2EXMapped_to_P13:T2EX映射到P13
 *				  - T2EXMapped_to_P11:T2EX映射到P11
 *				  - T2EXMapped_to_P10:T2EX映射到P10
 * @retval None
 */ 
void T2EX_PortMapping(T2EX_PortMappingPin_TypeDef T2EX_MappingPin)
{
	SPOS_T2EX = SPOS_T2EX & 0xE0 | T2EX_MappingPin;
}
#endif

#if defined (SC92F663x)
/**
 * @brief  T2端口映射函数
 * @param  T2_MappingPin[in]: T2端口映射管脚选择
 *          SC92F663x:
 *          - T2Mapped_to_P51:T2映射到P51
 *          - T2Mapped_to_P44:T2映射到P44
 *          - T2Mapped_to_P43:T2映射到P43
 *  				- T2Mapped_to_P42:T2映射到P42
 *					- T2Mapped_to_P41:T2映射到P41
 *					- T2Mapped_to_P40:T2映射到P40
 * 					- T2Mapped_to_P37:T2映射到P37
 * 					- T2Mapped_to_P36:T2映射到P36
 * @retval None
 */ 
void T2_PortMapping(T2_PortMappingPin_TypeDef T2_MappingPin)
{
	uint8_t *pSPOS_T2;
	pSPOS_T2 = (uint8_t *)0x1029;
	*pSPOS_T2 = (*pSPOS_T2 & 0xF8) | T2_MappingPin;
}

/**
 * @brief  T2EX端口映射函数
 * @param  T2EX_MappingPin[in]: T2EX端口映射管脚选择
 *          SC92F663x:
 *          - T2EXMapped_to_P45:T2EX映射到P45
 *          - T2EXMapped_to_P44:T2EX映射到P44
 *          - T2EXMapped_to_P42:T2EX映射到P42
 *  				- T2EXMapped_to_P41:T2EX映射到P41
 *					- T2EXMapped_to_P37:T2EX映射到P37
 *					- T2EXMapped_to_P36:T2EX映射到P36
 * 					- T2EXMapped_to_P35:T2EX映射到P35
 * 					- T2EXMapped_to_P34:T2EX映射到P34
 *					- T2EXMapped_to_P33:T2EX映射到P33
 *					- T2EXMapped_to_P32:T2EX映射到P32
 * 					- T2EXMapped_to_P31:T2EX映射到P31
 * 					- T2EXMapped_to_P30:T2EX映射到P30
 * @retval None
 */ 
void T2EX_PortMapping(T2EX_PortMappingPin_TypeDef T2EX_MappingPin)
{
	uint8_t *pSPOS_TEX;
	pSPOS_TEX = (uint8_t *)0x102A;
	*pSPOS_TEX = (*pSPOS_TEX & 0xF0) | T2EX_MappingPin;
}
#endif

/**
 * @}
 */
/* End of TIM2_Group2.	*/
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