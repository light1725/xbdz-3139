/**
 ******************************************************************************
 * @file    sc92f_timer4.c
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
#include "sc92f_timer4.h"

#if defined (SC92L853x) || defined (SC92L753x) || defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)\
	  || defined(SC92F652x)|| defined(SC92R51x_R52x) || defined(SC92F552x) || defined(SC92F663x) || defined(SC92F563x)
/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup TIM4
 * @brief TIM4 driver modules
 * @{
 */

/** @defgroup TIM4_Functions
 * @{
 */

/** @defgroup TIM4_Group1 Configuration of the TIM4 computation unit functions
 *  @brief   Configuration of the TIM4 computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### TIM4 configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  TIMER4相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */
void TIM4_DeInit()
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x04; //TIMER4 选择
  TXCON = 0X00;
  TXMOD = 0X00;
  RCAPXH = 0X00;
  RCAPXL = 0X00;
  THX = 0X00;
  TLX = 0X00;
  IE1 &= 0X7F;
  IP1 &= 0X7F;
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIMER4 预分频选择
 * @param  TIM4_PrescalerSelection[in]:预分频选择
 *          - TIM4_PRESSEL_FSYS_D12:TIMER4计数源来自系统时钟12分频
 *          - TIM4_PRESSEL_FSYS_D1:TIMER4计数源来自系统时钟
 * @retval None
 */
void TIM4_PrescalerSelection(TIM4_PresSel_TypeDef TIM4_PrescalerSelection)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x04;

  if (TIM4_PrescalerSelection == TIM4_PRESSEL_FSYS_D12)
  {
    TXMOD &= 0X7F;
  }
  else if (TIM4_PrescalerSelection == TIM4_PRESSEL_FSYS_D1)
  {
    TXMOD |= 0X80;
  }
	
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIMER4工作模式1配置函数
 * @param  TIM4_SetCounter[in]:配置计数初值
 * @retval None
 */ 
void TIM4_WorkMode1Config(uint16_t TIM4_SetCounter)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x04;
	
  RCAPXL = TIM4_SetCounter % 256;
  RCAPXH = TIM4_SetCounter / 256;

  TLX = RCAPXL;
  THX = RCAPXH;
	
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIMER4功能开关函数
 * @param  NewState[in]: 功能启动/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */ 
void TIM4_Cmd(FunctionalState NewState)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x04;

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
/* End of TIM4_Group1.	*/

/** @defgroup TIM4_Group2 Interrupts and flags management functions
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
 * @brief  TIMER4中断初始化
 * @param  NewState[in]: 断使能/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @param  Priority[in]: 中断优先级选择
 *              - LOW:低
 *              - HIGH:高
 * @retval None
 */
void TIM4_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x04;

  if (NewState == DISABLE)
  {
    IE1 &= 0X7F;
  }
  else
  {
    IE1 |= 0X80;
  }

  if (Priority == LOW)
  {
    IP1 &= 0X7F;
  }
  else
  {
    IP1 |= 0X80;
  }
	
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIM4_GetFlagStatus
 * @param  TIM4_Flag[in]:待读取的FLAG标志
 *              - TIM4_FLAG_TF4:中断标志位TF4
 *              - TIM4_FLAG_EXF4:中断标志位EXF4
 * @retval TIMER4中断标志状态
 *                  - RESET:置零
 *                  - SET:置起
 */ 
FlagStatus TIM4_GetFlagStatus(TIM4_Flag_TypeDef TIM4_Flag)
{
	unsigned char TXINX_Stack = TXINX;
  FlagStatus status = RESET;
  TXINX = 0x04;

  if ((TIM4_Flag & TXCON) != (uint8_t)RESET)
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
 * @brief  清除TIMER4中断标志状态
 * @param  TIM4_Flag[in]:待读取的FLAG标志
 *              - TIM4_FLAG_TF4:中断标志位TF4
 *              - TIM4_FLAG_EXF4:中断标志位EXF4
 * @retval None
 */
void TIM4_ClearFlag(TIM4_Flag_TypeDef TIM4_Flag)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x04;
  TXCON &= (~TIM4_Flag);
	TXINX = TXINX_Stack;
}
/**
 * @}
 */
/* End of TIM4_Group2.	*/

/** @defgroup TIM4_Group3 Configuration of the TIM4 computation unit functions
 *  @brief   Configuration of the TIM4 Base functions
 *
@verbatim
 ===============================================================================
                     ##### TIM4 base functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  TIM4基本设置配置函数
 * @param  TIM4_PrescalerSelection[in]:预分频选择
 *          - TIM4_PRESSEL_FSYS_D12:TIMER3计数源来自系统时钟12分频
 *          - TIM4_PRESSEL_FSYS_D1:TIMER3计数源来自系统时钟
 * @param  TIM4_CountMode[in]:计数/定时模式选择
 *          - TIM4_MODE_TIMER:TIMER4做定时器
 *          - TIM4_MODE_COUNTER:TIMER4做计数器
 * @param  TIM4_CountDirection[in]:计数/定时模式选择
 *          - TIM4_COUNTDIRECTION_UP:向上计数模式
 *          - TIM4_COUNTDIRECTION_DOWN_UP:向上/向下计数模式
 * @retval None
 */
void TIM4_TimeBaseInit(TIM4_PresSel_TypeDef TIM4_PrescalerSelection,TIM4_CountMode_TypeDef TIM4_CountMode,
                       TIM4_CountDirection_TypeDef TIM4_CountDirection)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x04;

	TXMOD &= 0X7F;
	TXMOD = TIM4_PrescalerSelection<<7;
	
  if (TIM4_CountMode == TIM4_MODE_TIMER)
  {
    TXCON &= 0XFD;
  }
  else if (TIM4_CountMode == TIM4_MODE_COUNTER)
  {
    TXCON |= 0X02;
  }

  /************************************************************/
  if (TIM4_CountDirection == TIM4_COUNTDIRECTION_UP)
  {
    TXMOD &= 0XFE;
  }
  else if (TIM4_CountDirection == TIM4_COUNTDIRECTION_DOWN_UP)
  {
    TXMOD |= 0X01;
  }
	
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIMER4工作模式0配置函数
 * @param  TIM4_SetCounter[in]:配置计数初值
 * @retval None
 */ 
void TIM4_WorkMode0Config(uint16_t TIM4_SetCounter)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x04;
	
  CP = 1;
  TLX = TIM4_SetCounter % 256;
  THX = TIM4_SetCounter / 256;
	
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIMER4工作模式3配置函数
 * @param  TIM4_SetCounter[in]:配置计数初值
 * @retval None
 */ 
void TIM4_WorkMode3Config(uint16_t TIM4_SetCounter)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x04;
	
  RCAPXL = TIM4_SetCounter % 256;
  RCAPXH = TIM4_SetCounter / 256;
  TXMOD |= 0X02;
	
	TXINX = TXINX_Stack;
}

/**
 * @brief  TIMER4工作模式配置函数
 * @param  TIMER4工作模式选择[in]:TIMER4工作模式选择
 *          - TIM4_WORK_MODE0:TIMER4选择工作模式0
 *          - TIM4_WORK_MODE1:TIMER4选择工作模式1
 *          - TIM4_WORK_MODE3:TIMER4选择工作模式3
 * @param  TIM4_SetCounter[in]:TIMER4计数初值配置
 * @retval None
 */ 
void TIM4_WorkModeConfig(TIM4_WorkMode_TypeDef TIM4_WorkMode, uint16_t TIM4_SetCounter)
{
  switch (TIM4_WorkMode)
  {
  case TIM4_WORK_MODE0:
    TIM4_WorkMode0Config(TIM4_SetCounter);
    break;

  case TIM4_WORK_MODE1:
    TIM4_WorkMode1Config(TIM4_SetCounter);
    break;

  case TIM4_WORK_MODE3:
    TIM4_WorkMode3Config(TIM4_SetCounter);
    break;

  default:
    break;
  }
}

/**
 * @brief  TIMER4_EXEN4配置函数
 * @param  NewState[in]:EXEN4使能选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @retval None
 */
void TIM4_SetEXEN4(FunctionalState NewState)
{
	unsigned char TXINX_Stack = TXINX;
  TXINX = 0x04;

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
 * @}
 */
/* End of TIM4_Group3.	*/
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