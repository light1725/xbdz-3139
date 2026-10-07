/**
 ******************************************************************************
 * @file    sc92f_zoc.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   ZOC function module
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
#include "sc92f_zoc.h"

#if defined(SC92F531x)

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup ZOC
 * @brief ZOC driver modules
 * @{
 */

/** @defgroup ZOC_Functions
 * @{
 */
 
/** @defgroup ZOC_Group1 Configuration of the ZOC computation unit functions
 *  @brief   Configuration of the ZOC computation unit functions
 *
 
@verbatim
 ===============================================================================
                     ##### ZOC configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */
  
/**
 * @brief  ZOC相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void ZOC_DeInit(void)
{
  ZOCINX = 0X00;
  ZOCCON = 0X00;
  ZOCCFG = 0X00;
}

/**
 * @brief  ZOC模式选择函数
 * @param  ZOC_ModeSel[in]:模式选择
 *          - ZOC_DISABLE:ZOC关闭
 *          - ZOC_ZCD_Mode:ZOC设置为ZCD模式
 *          - ZOC_CMP_Mode:ZOC设置为CMP模式
 *          - ZOC_OP_Mode:ZOC设置为OP模式
 * @retval None
 */ 
void ZOC_ModeSelection(ZOC_ModeSel_TypeDef ZOC_ModeSel)
{
  ZOCINX &= ~0xC0;
	ZOCINX |= ZOC_ModeSel<<6;
}

/**
 * @brief  ZCD output configuration function.
 * @param  ZCD_OutputEn[in]: ZCD output enable or disable.
 *          - ZCD_OutputDisable:过零方波信号不通过管脚输出
 *          - ZCD_OutputEnable:过零方波信号可通过管脚输出
 * @param  ZCD_OutputInv[in]: ZCD output inversion control.
 *          - ZCD_OutputInPhase:ZCD输出逻辑不反相
 *          - ZCD_OutputAntiPhase:ZCD输出逻辑反相
 * @retval None
 */
void ZOC_ZCD_OutputConfig(ZCD_OutputEn_TypeDef ZCD_OutputEn,
													ZCD_OutputInv_TypeDef ZCD_OutputInv)
{
	ZOCCFG &= 0XDF;
	ZOCCFG |= ZCD_OutputEn;
	ZOCCFG &= 0XBF;
	ZOCCFG |= ZCD_OutputInv;
}

/**
 * @brief  ZCD负端比较电压选择
 * @param  ZCD_NegaVoltSel[in]:选择ZCD负端比较电压
 *          - ZCD_NegaV_ZCDN:选用ZCDN为ZCD负端的比较电压
 *          - ZCD_NegaV_1VDD16:选用1/16VDD 为ZCD负端的比较电压
 *          - ZCD_NegaV_2VDD16:选用2/16VDD 为ZCD负端的比较电压
 *          - ZCD_NegaV_3VDD16:选用3/16VDD 为ZCD负端的比较电压
 *          - ZCD_NegaV_4VDD16:选用4/16VDD 为ZCD负端的比较电压
 *          - ZCD_NegaV_5VDD16:选用5/16VDD 为ZCD负端的比较电压
 *          - ZCD_NegaV_6VDD16:选用6/16VDD 为ZCD负端的比较电压
 *          - ZCD_NegaV_7VDD16:选用7/16VDD 为ZCD负端的比较电压
 *          - ZCD_NegaV_8VDD16:选用8/16VDD 为ZCD负端的比较电压
 *          - ZCD_NegaV_9VDD16:选用9/16VDD 为ZCD负端的比较电压
 *          - ZCD_NegaV_10VDD16:选用10/16VDD 为ZCD负端的比较电压
 *          - ZCD_NegaV_11VDD16:选用11/16VDD 为ZCD负端的比较电压
 *          - ZCD_NegaV_12VDD16:选用12/16VDD 为ZCD负端的比较电压
 *          - ZCD_NegaV_13VDD16:选用13/16VDD 为ZCD负端的比较电压
 *          - ZCD_NegaV_14VDD16:选用14/16VDD 为ZCD负端的比较电压
 *          - ZCD_NegaV_15VDD16:选用15/16VDD 为ZCD负端的比较电压
 * @retval None
 */ 
void ZCD_NegaVoltSelection(ZCD_NegaVoltSel_TypeDef ZCD_NegaVoltSel)
{
  ZOCCON &= 0XF0;
  ZOCCON |= ZCD_NegaVoltSel;
}

/**
 * @brief  ZCD信号输入端口选择函数
 * @param  ZCD_InputPort[in]:ZCD信号输入端口选择
 *          - ZCD_NegativeInput:选择负端为信号输入端
 *          - ZCD_PositiveInput:选择正端为信号输入端
 * @retval None
 */ 
void ZCD_InputPortSelection(ZCD_InputPortSel_TypeDef ZCD_InputPort)
{
  ZOCCFG &= 0X7F;
  ZOCCFG |= ZCD_InputPort;
}

/**
 * @brief  ZCD正端输入通道选择函数
 * @param  ZCD_PosInputChannel[in]:正端输入通道
 *          - Channel_ZCDP0:选用 ZCDP0 为模拟比较器正端的输入
 *          - Channel_ZCDP1:选用 ZCDP1 为模拟比较器正端的输入
 *          - Channel_ZCDP2:选用 ZCDP2 为模拟比较器正端的输入
 *          - Channel_ZCDP3:选用 ZCDP3 为模拟比较器正端的输入
 * @retval None
 */ 
void ZCD_PosInputChannelSelection(ZCD_PosInputChannelSel_TypeDef ZCD_PosInputChannel)
{
  ZOCCFG &= 0XFC;
	ZOCCFG |= ZCD_PosInputChannel;
}

/**
 * @brief  ZCD数字输入通道使能函数
 * @param  FunctionalState[in]: new state of the ZCD Digital input.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable 
 * @retval None
 */ 
void ZCD_DigInputCmd(FunctionalState NewState)
{
  if(NewState != ENABLE)
	{
		ZOCINX &=~(0x10) ;
	}
	else
	{
		ZOCINX |= (0x10) ;
	}
}

/**
 * @brief  ZCD使能函数
 * @param  FunctionalState[in]: new state of the ZCD.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable 
 * @retval None
 */ 
void ZOC_ZCD_Cmd(FunctionalState NewState)
{
  if(NewState != ENABLE)
	{
		ZOCCON &=~(0x80) ;
	}
	else
	{
		ZOCCON |= (0x80) ;
	}
}

/**
 * @brief  Initializes the peripheral CMP register according to the parameters.
 * @param  CMP_NegaVoltSel[in]:ZCD信号输入端口选择
 *          - CMP_NegaV_CMPR:选用CMPR为CMP负端的比较电压
 *          - CMP_NegaV_1VDD16:选用1/16VDD 为CMP负端的比较电压
 *          - CMP_NegaV_2VDD16:选用2/16VDD 为CMP负端的比较电压
 *          - CMP_NegaV_3VDD16:选用3/16VDD 为CMP负端的比较电压
 *          - CMP_NegaV_4VDD16:选用4/16VDD 为CMP负端的比较电压
 *          - CMP_NegaV_5VDD16:选用5/16VDD 为CMP负端的比较电压
 *          - CMP_NegaV_6VDD16:选用6/16VDD 为CMP负端的比较电压
 *          - CMP_NegaV_7VDD16:选用7/16VDD 为CMP负端的比较电压
 *          - CMP_NegaV_8VDD16:选用8/16VDD 为CMP负端的比较电压
 *          - CMP_NegaV_9VDD16:选用9/16VDD 为CMP负端的比较电压
 *          - CMP_NegaV_10VDD16:选用10/16VDD 为CMP负端的比较电压
 *          - CMP_NegaV_11VDD16:选用11/16VDD 为CMP负端的比较电压
 *          - CMP_NegaV_12VDD16:选用12/16VDD 为CMP负端的比较电压
 *          - CMP_NegaV_13VDD16:选用13/16VDD 为CMP负端的比较电压
 *          - CMP_NegaV_14VDD16:选用14/16VDD 为CMP负端的比较电压
 *          - CMP_NegaV_15VDD16:选用15/16VDD 为CMP负端的比较电压
 * @param  CMP_PosInputSel[in]: CMP positive input selection.
 *          - CMP_CMPX:CMP正端的输入为CMP0~3之一
 *          - CMP_1_2V:CMP正端的输入为内部1.2V基准电压
 * @param  PosInputChannel[in]: CMP positive input channel selection.
 *          - PosInput_CMP0:选用 CMP0 为模拟比较器正端的输入
 *          - PosInput_CMP1:选用 CMP1 为模拟比较器正端的输入
 *          - PosInput_CMP2:选用 CMP2 为模拟比较器正端的输入
 *          - PosInput_CMP3:选用 CMP3 为模拟比较器正端的输入
 * @retval None
 */
void ZOC_CMP_Init(CMP_NegaVoltSel_TypeDef CMP_NegaVoltSel,
              CMP_PosInputSel_TypeDef CMP_PosInputSel,
							CMP_PosInputChannelSel_TypeDef PosInputChannel)
{
  ZOCCON &= 0XF0;
  ZOCCON |= CMP_NegaVoltSel;
	ZOCCFG &= 0XEF;
	ZOCCFG |= CMP_PosInputSel;
	ZOCCFG &= 0XFC;
	ZOCCFG |= PosInputChannel;
}

/**
 * @brief  CMP使能函数
 * @param  FunctionalState[in]: new state of the CMP.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable 
 * @retval None
 */ 
void ZOC_CMP_Cmd(FunctionalState NewState)
{
  if(NewState != ENABLE)
	{
		ZOCCON &=~(0x80) ;
	}
	else
	{
		ZOCCON |= (0x80) ;
	}
}

/**
 * @brief  OP输出端连接选择
 * @param  OP_OPO[in]:选择OP输出端连接
 *                  - OP_OPO_Disable:与OP_O连接断开
 *                  - OP_OPO_Enable:OP输出到OP_O(外部引脚)
 * @retval None
 */
void OP_OPOSelection(OP_OPOSel_TypeDef OP_OPO)
{
  ZOCCON &= 0XFE;
  ZOCCON |= OP_OPO;
}

/**
 * @brief  OP使能函数
 * @param  FunctionalState[in]: new state of the OP.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable 
 * @retval None
 */ 
void ZOC_OP_Cmd(FunctionalState NewState)
{
  if(NewState != ENABLE)
	{
		ZOCCON &=~(0x80) ;
	}
	else
	{
		ZOCCON |= (0x80) ;
	}
}

/**
 * @}
 */
/* End of ZOC_Group1.	*/

/** @defgroup ZOC_Group2 Interrupts and flags management functions
 *  @brief    Interrupts and flags management functions
 *
@verbatim
 ===============================================================================
                     ##### Interrupts and flags management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  Enables or disables the specified ZCD interrupts.
 * @param  NewState[in]: new state of the ZCD interrupts.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable 
 * @param  Priority[in]: priority of the ZCD interrupts.
 *                  - LOW:Low priority
 *                  - HIGH:High priority
 * @retval None
 */
void ZOC_ZCD_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority)
{
  //Interrupt configuration
  if(NewState == DISABLE)
  {
    IE1 &= 0xBF;
  }
  else
  {
    IE1 |= 0x40;
  }

  //Interrupt Priority Setting
  if(Priority == LOW)
  {
    IP1 &= 0xBF;
  }
  else
  {
    IP1 |= 0x40;
  }
}

/**
 * @brief  Enables or disables the specified ZCD interrupts.
 * @param  ZCD_IT[in]: ZCD interrupts.
 *                  - ZCD_IT_DLYIE:延时完成中断
 *                  - ZCD_IT_ZCDFIE:下降沿中断 
 *                  - ZCD_IT_ZCDRIE:上升沿中断
 * @param  NewState[in]: new state of the ZCD interrupts.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable 
 * @retval None
 */
void ZOC_ZCD_ITSelection(uint8_t ZCD_IT,
												 FunctionalState NewState)
{
  //Interrupt configuration
  if(NewState == DISABLE)
  {
    ZOCCFG &= ~ZCD_IT;
  }
  else
  {
    ZOCCFG |= ZCD_IT;
  }
}

/**
 * @brief  Enables or disables the specified CMP interrupts.
 * @param  NewState[in]: new state of the CMP interrupts.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable 
 * @param  Priority[in]: priority of the CMP interrupts.
 *                  - LOW:Low priority
 *                  - HIGH:High priority
 * @retval None
 */
void ZOC_CMP_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority)
{
  //Interrupt configuration
  if(NewState == DISABLE)
  {
    IE1 &= 0xDF;
  }
  else
  {
    IE1 |= 0x20;
  }

  //Interrupt Priority Setting
  if(Priority == LOW)
  {
    IP1 &= 0xDF;
  }
  else
  {
    IP1 |= 0x20;
  }
}

/**
 * @brief  Enables or disables the specified CMP interrupts.
 * @param  CMP_IT[in]: CMP Interrupt.
 *                  - CMP_IT_NONE:不产生中断
 *                  - CMP_IT_CMPRIE:上升沿中断 
 *                  - CMP_IT_CMPFIE:下降沿中断
 *                  - CMP_IT_CMPRFIE:双沿中断
 * @retval None
 */
void ZOC_CMP_ITSelection(uint8_t CMP_IT)
{
	ZOCCFG &= 0xF3;
	ZOCCFG |= CMP_IT;
}

/**
 * @brief  Checks whether the specified ZOC flag is set or not.
 * @param  ZOC_FLAG[in]:所需清除的标志位
 *              - ZCD_Flag_ZCDFIF:下降沿中断标志
 *              - ZCD_Flag_ZCDRIF:上升沿中断标志
 *              - ZCD_Flag_DLYIF:延时完成中断标志
 *              - CMP_Flag_CMPIF:CMP中断标志
 *              - CMP_Flag_CMPSTA:CMP输出状态
 * @retval The new state of ZOC_FLAG (SET or RESET).
 *                  -  RESET:Flag reset
 *                  -  SET :Flag up
 */
FlagStatus ZOC_GetFlagStatus(ZOC_Flag_TypeDef ZOC_FLAG)
{
  FlagStatus bitstatus = RESET;

	if((ZOC_FLAG & ZOCCON) != (uint8_t)RESET)
	{
		bitstatus = SET;
	}
	else
	{
		bitstatus = RESET;
	}

  return bitstatus;
}

/**
 * @brief  清除ZOC标志状态
 * @param  ZOC_FLAG[in]:所需清除的标志位
 *              - ZCD_Flag_ZCDFIF:下降沿中断标志
 *              - ZCD_Flag_ZCDRIF:上升沿中断标志
 *              - ZCD_Flag_DLYIF:延时完成中断标志
 *              - CMP_Flag_CMPIF:CMP中断标志
 *              - CMP_Flag_CMPSTA:CMP输出状态
 * @retval None
 */
void ZOC_ClearFlag(ZOC_Flag_TypeDef ZOC_FLAG)
{
  ZOCCON &= (~ZOC_FLAG);
}

/**
 * @}
 */
/* End of ADC_Group2.	*/

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