/**
 ******************************************************************************
 * @file    sc92f_timer3.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   TIMER3 function module
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
#include "sc92f_timer3.h"

#if defined (SC92L853x) || defined (SC92L753x) || defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)\
		|| defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x) || defined (SC92F637x) || defined (SC92F663x) || defined(SC92F563x)
/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup TIM3
 * @brief TIM3 driver modules
 * @{
 */

/** @defgroup TIM3_Functions
 * @{
 */

/** @defgroup TIM3_Group1 Configuration of the TIM3 computation unit functions
 *  @brief   Configuration of the TIM3 computation unit functions
 *
 
@verbatim
 ===============================================================================
                     ##### TIM3 configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */
  
/**
 * @brief  TIMER3相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void TIM3_DeInit()
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x03;    //TIMER3 选择
  TXCON = 0X00;
  TXMOD = 0X00;
  RCAPXH = 0X00;
  RCAPXL = 0X00;
  THX = 0X00;
  TLX = 0X00;
  IE1 &= 0XBF;
  IP1 &= 0XBF;
	TXINX = TXINX_Stack;
}

#if defined(SC92F84Hx) || defined(SC92F83Hx)
/**
 * @brief  TIM3引脚选择
 * @param  PinSeletion[in]:选择TIM3引脚
 *          - TIM3_PinRemap_Default:TIM3引脚为默认引脚
 *          - TIM3_PinRemap_A:TIM3引脚为A组引脚
 * @retval None
 */
void TIM3_PinSelection(TIM3_PinSelection_TypeDef PinSeletion)
{
	TMCON = TMCON & 0XEF | PinSeletion;
}
#endif

/**
 * @brief  TIMER3基本设置配置函数
 * @param  TIM3_PrescalerSelection[in]:预分频选择
 *          - TIM3_PRESSEL_FSYS_D12:TIMER3计数源来自系统时钟12分频
 *          - TIM3_PRESSEL_FSYS_D1:TIMER3计数源来自系统时钟
 * @retval None
 */
void TIM3_PrescalerSelection(TIM3_PresSel_TypeDef TIM3_PrescalerSelection)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x03;

  if(TIM3_PrescalerSelection == TIM3_PRESSEL_FSYS_D12)
  {
    TXMOD &= 0X7F;
  }
  else if(TIM3_PrescalerSelection == TIM3_PRESSEL_FSYS_D1)
	{
		TXMOD |= 0X80;
	}
	
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIMER3工作模式1配置函数
 * @param  TIM3_SetCounter[in]:配置计数初值
 * @retval None
 */ 
void TIM3_WorkMode1Config(uint16_t TIM3_SetCounter)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x03;
	
  RCAPXL = TIM3_SetCounter % 256;
  RCAPXH = TIM3_SetCounter / 256;

  TLX = RCAPXL;
  THX = RCAPXH;
	
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIMER3功能开关函数
 * @param  NewState[in]: 功能启动/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */ 
void TIM3_Cmd(FunctionalState NewState)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x03;

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
/* End of TIM3_Group1.	*/

/** @defgroup TIM3_Group2 Interrupts and flags management functions
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
 * @brief  TIMER3中断初始化
 * @param  NewState[in]: 断使能/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @param  Priority[in]: 中断优先级选择
 *              - LOW:低
 *              - HIGH:高
 * @retval None
 */
void TIM3_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x03;

  if(NewState == DISABLE)
  {
    IE1 &= 0XBF;
  }
  else
  {
    IE1 |= 0X40;
  }

  if(Priority == LOW)
  {
    IP1 &= 0XBF;
  }
  else
  {
    IP1 |= 0X40;
  }
	
	TXINX = TXINX_Stack;
}

/**
 * @brief  获得TIMER3中断标志状态
 * @param  TIM3_Flag[in]:待读取的FLAG标志
 *              - TIM3_FLAG_TF3:中断标志位TF3
 *              - TIM3_FLAG_EXF3:中断标志位EXF3
 * @retval TIMER3中断标志状态
 *                  - RESET:置零
 *                  - SET:置起
 */ 
FlagStatus TIM3_GetFlagStatus(TIM3_Flag_TypeDef TIM3_Flag)
{
	unsigned char TXINX_Stack = TXINX;
  FlagStatus status = RESET;
  TXINX = 0x03;

  if((TIM3_Flag & TXCON) != (uint8_t)RESET)
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
 * @brief  清除TIMER3中断标志状态
 * @param  TIM3_Flag[in]:待读取的FLAG标志
 *              - TIM3_FLAG_TF3:中断标志位TF3
 *              - TIM3_FLAG_EXF3:中断标志位EXF3
 * @retval None
 */
void TIM3_ClearFlag(TIM3_Flag_TypeDef TIM3_Flag)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x03;
  TXCON &= (~TIM3_Flag);
	TXINX = TXINX_Stack;
}
/**
 * @}
 */
/* End of TIM3_Group2.	*/

/** @defgroup TIM3_Group3 Configuration of the TIM3 computation unit functions
 *  @brief   Configuration of the TIM3 Base functions
 *
@verbatim
 ===============================================================================
                     ##### TIM2 base functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  TIM3基本设置配置函数
 * @param  TIM3_PrescalerSelection[in]:预分频选择
 *          - TIM3_PRESSEL_FSYS_D12:TIMER3计数源来自系统时钟12分频
 *          - TIM3_PRESSEL_FSYS_D1:TIMER3计数源来自系统时钟
 * @param  TIM3_CountMode[in]:计数/定时模式选择
 *          - TIM3_MODE_TIMER:TIMER3做定时器
 *          - TIM3_MODE_COUNTER:TIMER3做计数器
 * @param  TIM3_CountDirection[in]:计数/定时模式选择
 *          - TIM3_COUNTDIRECTION_UP:向上计数模式
 *          - TIM3_COUNTDIRECTION_DOWN_UP:向上/向下计数模式
 * @retval None
 */
void TIM3_TimeBaseInit(TIM3_PresSel_TypeDef TIM3_PrescalerSelection,TIM3_CountMode_TypeDef TIM3_CountMode,
                       TIM3_CountDirection_TypeDef TIM3_CountDirection)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x03;

	if(TIM3_PrescalerSelection == TIM3_PRESSEL_FSYS_D12)
  {
    TXMOD &= 0X7F;
  }
  else
  if(TIM3_PrescalerSelection == TIM3_PRESSEL_FSYS_D1)
  {
    TXMOD |= 0X80;
  }
	
  if(TIM3_CountMode == TIM3_MODE_TIMER)
  {
    TXCON &= 0XFD;
  }
  else
  if(TIM3_CountMode == TIM3_MODE_COUNTER)
  {
    TXCON |= 0X02;
  }

  if(TIM3_CountDirection == TIM3_COUNTDIRECTION_UP)
  {
    TXMOD &= 0XFE;
  }
  else
  if(TIM3_CountDirection == TIM3_COUNTDIRECTION_DOWN_UP)
  {
      TXMOD |= 0X01;
  }
	
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIMER3工作模式0配置函数
 * @param  TIM3_SetCounter[in]:配置计数初值
 * @retval None
 */ 
void TIM3_WorkMode0Config(uint16_t TIM3_SetCounter)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x03;
	
	CP = 1;
  TLX = TIM3_SetCounter % 256;
  THX = TIM3_SetCounter / 256;
	
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIMER3工作模式3配置函数
 * @param  TIM3_SetCounter[in]:配置计数初值
 * @retval None
 */ 
void TIM3_WorkMode3Config(uint16_t TIM3_SetCounter)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x03;
	
  RCAPXL = TIM3_SetCounter % 256;
  RCAPXH = TIM3_SetCounter / 256;
  TXMOD |= 0X02;
	
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIMER3工作模式配置函数
 * @param  TIMER3工作模式选择[in]:TIMER3工作模式选择
 *          - TIM3_WORK_MODE0:TIMER3选择工作模式0
 *          - TIM3_WORK_MODE1:TIMER3选择工作模式1
 *          - TIM3_WORK_MODE3:TIMER3选择工作模式3
 * @param  TIM3_SetCounter[in]:TIMER2计数初值配置
 * @retval None
 */ 
void TIM3_WorkModeConfig(TIM3_WorkMode_TypeDef TIM3_WorkMode, uint16_t TIM3_SetCounter)
{
  switch (TIM3_WorkMode)
  {
    case TIM3_WORK_MODE0:
      TIM3_WorkMode0Config(TIM3_SetCounter);
      break;

    case TIM3_WORK_MODE1:
      TIM3_WorkMode1Config(TIM3_SetCounter);
      break;

    case TIM3_WORK_MODE3:
      TIM3_WorkMode3Config(TIM3_SetCounter);
      break;

    default:
      break;
  }
}

/**
 * @brief  TIMER3_EXEN3配置函数
 * @param  NewState[in]:EXEN3使能选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */
void TIM3_SetEXEN3(FunctionalState NewState)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x03;

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

#if defined (SC92F663x)
/**
 * @brief  T3EX端口映射函数
 * @param  T3EX_MappingPin[in]: T3EX端口映射管脚选择
 *          SC92F663x:
 *          - T3EXMapped_to_P45:T3EX映射到P45
 *          - T3EXMapped_to_P44:T3EX映射到P44
 *          - T3EXMapped_to_P42:T3EX映射到P42
 *  				- T3EXMapped_to_P41:T3EX映射到P41
 *					- T3EXMapped_to_P37:T3EX映射到P37
 *					- T3EXMapped_to_P36:T3EX映射到P36
 * 					- T3EXMapped_to_P35:T3EX映射到P35
 * 					- T3EXMapped_to_P34:T3EX映射到P34
 *					- T3EXMapped_to_P33:T3EX映射到P33
 *					- T3EXMapped_to_P32:T3EX映射到P32
 * 					- T3EXMapped_to_P31:T3EX映射到P31
 * 					- T3EXMapped_to_P30:T3EX映射到P30
 * @retval None
 */ 
void T3EX_PortMapping(T3EX_PortMappingPin_TypeDef T3EX_MappingPin)
{
	uint8_t *pSPOS_TEX;
	pSPOS_TEX = (uint8_t *)0x102A;
	*pSPOS_TEX = (*pSPOS_TEX & 0x0F) | (T3EX_MappingPin<<4);
}
#endif
/**
 * @}
 */
/* End of TIM3_Group3.	*/
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

