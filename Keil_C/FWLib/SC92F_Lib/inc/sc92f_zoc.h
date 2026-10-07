/**
 ******************************************************************************
 * @file    sc92f_zoc.h
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   Header file of ZOC module.
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
 
/* Define to prevent recursive inclusion -----------------------------------*/
#ifndef _sc92f_ZOC_H_
#define	_sc92f_ZOC_H_

/* Includes ------------------------------------------------------------------*/
#include "sc92f.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @addtogroup ZOC
 * @{
 */
 
/** @defgroup ZOC_Enumerations
 * @{
 */
 
/** @brief ZOC_ModeSel_TypeDef ZOC mode selection
 * @{
 */
typedef enum
{
  ZOC_DISABLE = ((uint8_t)0x00),      /*!< ZOC关闭 */
  ZOC_ZCD_Mode  = ((uint8_t)0x01),    /*!< ZOC设置为ZCD模式 */
	ZOC_CMP_Mode = ((uint8_t)0x02),     /*!< ZOC设置为CMP模式 */
	ZOC_OP_Mode = ((uint8_t)0x03),       /*!< ZOC设置为OP模式 */
} ZOC_ModeSel_TypeDef;
/**
 * @}
 */

/** @brief ZCD_NegaVoltSel_TypeDef ZCD negative comparison voltage selection
 * @{
 */
typedef enum
{
  ZCD_NegaV_ZCDN   = ((uint8_t)0x00), /*!< 选用ZCDN为ZCD负端的比较电压 */
  ZCD_NegaV_1VDD16 = ((uint8_t)0x01),  /*!< 选用1/16VDD 为ZCD负端的比较电压 */
  ZCD_NegaV_2VDD16 = ((uint8_t)0x02),  /*!< 选用2/16VDD 为ZCD负端的比较电压 */
  ZCD_NegaV_3VDD16 = ((uint8_t)0x03),  /*!< 选用3/16VDD 为ZCD负端的比较电压 */
  ZCD_NegaV_4VDD16 = ((uint8_t)0x04),  /*!< 选用4/16VDD 为ZCD负端的比较电压 */
  ZCD_NegaV_5VDD16 = ((uint8_t)0x05),  /*!< 选用5/16VDD 为ZCD负端的比较电压 */
  ZCD_NegaV_6VDD16 = ((uint8_t)0x06),  /*!< 选用6/16VDD 为ZCD负端的比较电压 */
  ZCD_NegaV_7VDD16 = ((uint8_t)0x07),  /*!< 选用7/16VDD 为ZCD负端的比较电压 */
  ZCD_NegaV_8VDD16 = ((uint8_t)0x08),  /*!< 选用8/16VDD 为ZCD负端的比较电压 */
  ZCD_NegaV_9VDD16 = ((uint8_t)0x09),  /*!< 选用9/16VDD 为ZCD负端的比较电压 */
  ZCD_NegaV_10VDD16 = ((uint8_t)0x0A),  /*!< 选用10/16VDD 为ZCD负端的比较电压 */
  ZCD_NegaV_11VDD16 = ((uint8_t)0x0B),  /*!< 选用11/16VDD 为ZCD负端的比较电压 */
  ZCD_NegaV_12VDD16 = ((uint8_t)0x0C),  /*!< 选用12/16VDD 为ZCD负端的比较电压 */
  ZCD_NegaV_13VDD16 = ((uint8_t)0x0D),  /*!< 选用13/16VDD 为ZCD负端的比较电压 */
  ZCD_NegaV_14VDD16 = ((uint8_t)0x0E),  /*!< 选用14/16VDD 为ZCD负端的比较电压 */
  ZCD_NegaV_15VDD16 = ((uint8_t)0x0F),  /*!< 选用15/16VDD 为ZCD负端的比较电压 */
} ZCD_NegaVoltSel_TypeDef;
/**
 * @}
 */

/** @brief ZCD_InputPortSel_TypeDef ZCD input port selection
 * @{
 */
typedef enum
{
  ZCD_NegativeInput   = ((uint8_t)0x00),		/*!< 选择负端为信号输入端 */
  ZCD_PositiveInput   = ((uint8_t)0x80),		/*!< 选择正端为信号输入端 */
} ZCD_InputPortSel_TypeDef;
/**
 * @}
 */

/** @brief ZCD_OutputInv_TypeDef ZCD output inversion control
 * @{
 */
typedef enum
{
  ZCD_OutputInPhase   = ((uint8_t)0x00),		/*!< ZCD输出逻辑不反相 */
  ZCD_OutputAntiPhase   = ((uint8_t)0x40),		/*!< ZCD输出逻辑反相 */
} ZCD_OutputInv_TypeDef;
/**
 * @}
 */

/** @brief ZCD_OutputEn_TypeDef ZCD output enable or disable
 * @{
 */
typedef enum
{
  ZCD_OutputDisable   = ((uint8_t)0x00),		/*!< 过零方波信号不通过管脚输出 */
  ZCD_OutputEnable   = ((uint8_t)0x20),		/*!< 过零方波信号可通过管脚输出 */
} ZCD_OutputEn_TypeDef;
/**
 * @}
 */

/** @brief ZCD_PosInputChannelSel_TypeDef ZCD positive input channel selection
 * @{
 */
typedef enum
{
  Channel_ZCDP0   = ((uint8_t)0x00),		/*!< 选用 ZCDP0 为模拟比较器正端的输入 */
  Channel_ZCDP1   = ((uint8_t)0x01),		/*!< 选用 ZCDP1 为模拟比较器正端的输入 */
  Channel_ZCDP2   = ((uint8_t)0x02),		/*!< 选用 ZCDP2 为模拟比较器正端的输入 */
  Channel_ZCDP3   = ((uint8_t)0x03),		/*!< 选用 ZCDP3 为模拟比较器正端的输入 */
} ZCD_PosInputChannelSel_TypeDef;
/**
 * @}
 */

/** @brief CMP_NegaVoltSel_TypeDef CMP negative comparison voltage selection
 * @{
 */
typedef enum
{
  CMP_NegaV_CMPR   = ((uint8_t)0x00), /*!< 选用CMPR为CMP负端的比较电压 */
  CMP_NegaV_1VDD16 = ((uint8_t)0x01),  /*!< 选用1/16VDD 为CMP负端的比较电压 */
  CMP_NegaV_2VDD16 = ((uint8_t)0x02),  /*!< 选用2/16VDD 为CMP负端的比较电压 */
  CMP_NegaV_3VDD16 = ((uint8_t)0x03),  /*!< 选用3/16VDD 为CMP负端的比较电压 */
  CMP_NegaV_4VDD16 = ((uint8_t)0x04),  /*!< 选用4/16VDD 为CMP负端的比较电压 */
  CMP_NegaV_5VDD16 = ((uint8_t)0x05),  /*!< 选用5/16VDD 为CMP负端的比较电压 */
  CMP_NegaV_6VDD16 = ((uint8_t)0x06),  /*!< 选用6/16VDD 为CMP负端的比较电压 */
  CMP_NegaV_7VDD16 = ((uint8_t)0x07),  /*!< 选用7/16VDD 为CMP负端的比较电压 */
  CMP_NegaV_8VDD16 = ((uint8_t)0x08),  /*!< 选用8/16VDD 为CMP负端的比较电压 */
  CMP_NegaV_9VDD16 = ((uint8_t)0x09),  /*!< 选用9/16VDD 为CMP负端的比较电压 */
  CMP_NegaV_10VDD16 = ((uint8_t)0x0A),  /*!< 选用10/16VDD 为CMP负端的比较电压 */
  CMP_NegaV_11VDD16 = ((uint8_t)0x0B),  /*!< 选用11/16VDD 为CMP负端的比较电压 */
  CMP_NegaV_12VDD16 = ((uint8_t)0x0C),  /*!< 选用12/16VDD 为CMP负端的比较电压 */
  CMP_NegaV_13VDD16 = ((uint8_t)0x0D),  /*!< 选用13/16VDD 为CMP负端的比较电压 */
  CMP_NegaV_14VDD16 = ((uint8_t)0x0E),  /*!< 选用14/16VDD 为CMP负端的比较电压 */
  CMP_NegaV_15VDD16 = ((uint8_t)0x0F),  /*!< 选用15/16VDD 为CMP负端的比较电压 */
} CMP_NegaVoltSel_TypeDef;
/**
 * @}
 */

/** @brief CMP_PosInputSel_TypeDef CMP positive input selection
 * @{
 */
typedef enum
{
  CMP_CMPX   = ((uint8_t)0x00),		/*!< CMP正端的输入为CMP0~3之一 */
  CMP_1_2V   = ((uint8_t)0x10),		/*!< CMP正端的输入为内部1.2V基准电压 */
} CMP_PosInputSel_TypeDef;
/**
 * @}
 */

/** @brief CMP_PosInputChannelSel_TypeDef CMP positive input channel selection
 * @{
 */
typedef enum
{
  PosInput_CMP0   = ((uint8_t)0x00),		/*!< 选用 CMP0 为模拟比较器正端的输入 */
  PosInput_CMP1   = ((uint8_t)0x01),		/*!< 选用 CMP1 为模拟比较器正端的输入 */
  PosInput_CMP2   = ((uint8_t)0x02),		/*!< 选用 CMP2 为模拟比较器正端的输入 */
  PosInput_CMP3   = ((uint8_t)0x03),		/*!< 选用 CMP3 为模拟比较器正端的输入 */
} CMP_PosInputChannelSel_TypeDef;
/**
 * @}
 */

/** @brief CMP_PosInputSel_TypeDef CMP positive input selection
 * @{
 */
typedef enum
{
  OP_OPO_Disable   = ((uint8_t)0x00),		/*!< 与OP_O连接断开 */
  OP_OPO_Enable   = ((uint8_t)0x01),		/*!< OP输出到OP_O(外部引脚) */
} OP_OPOSel_TypeDef;
/**
 * @}
 */

/** @brief ZCD_IT ZCD Interrupt
 * @{
 */
typedef enum
{
    ZCD_IT_DLYIE  = ((uint8_t)0x10),	/*!< 延时完成中断 */
    ZCD_IT_ZCDFIE = ((uint8_t)0x08),	/*!< 下降沿中断 */
    ZCD_IT_ZCDRIE = ((uint8_t)0x04),  /*!< 上升沿中断 */
} ZCD_IT_TypeDef;
/**
 * @}
 */

/** @brief ZCD_IT ZCD Interrupt
 * @{
 */
typedef enum
{
    ZCD_Flag_ZCDFIF  = ((uint8_t)0x40),	 /*!< 下降沿中断标志 */
    ZCD_Flag_ZCDRIF  = ((uint8_t)0x20),	 /*!< 上升沿中断标志 */
    ZCD_Flag_DLYIF   = ((uint8_t)0x10),  /*!< 延时完成中断标志 */
    CMP_Flag_CMPIF   = ((uint8_t)0x40),	 /*!< CMP中断标志 */
		CMP_Flag_CMPSTA  = ((uint8_t)0x20),	 /*!< CMP输出状态 */
} ZOC_Flag_TypeDef;
/**
 * @}
 */

/** @brief CMP_IT CMP Interrupt
 * @{
 */
typedef enum
{
    CMP_IT_NONE    = ((uint8_t)0x00),	 /*!< 不产生中断 */
    CMP_IT_CMPRIE  = ((uint8_t)0x04),	 /*!< 上升沿中断 */
    CMP_IT_CMPFIE  = ((uint8_t)0x08),  /*!< 下降沿中断 */
    CMP_IT_CMPRFIE = ((uint8_t)0x0C),  /*!< 双沿中断 */
} CMP_IT_TypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup ZOC_Functions ZOC Functions
 * @{
 */

/* ZOC Base functions ********************************************************/
void ZOC_DeInit(void);
void ZOC_ModeSelection(ZOC_ModeSel_TypeDef ZOC_ModeSel);
void ZOC_ZCD_OutputConfig(ZCD_OutputEn_TypeDef ZCD_OutputEn,
													ZCD_OutputInv_TypeDef ZCD_OutputInv);
void ZCD_NegaVoltSelection(ZCD_NegaVoltSel_TypeDef ZCD_NegaVoltSel);
void ZCD_InputPortSelection(ZCD_InputPortSel_TypeDef ZCD_InputPort);
void ZCD_PosInputChannelSelection(ZCD_PosInputChannelSel_TypeDef ZCD_PosInputChannel);
void ZCD_DigInputCmd(FunctionalState NewState);
void ZOC_ZCD_Cmd(FunctionalState NewState);
void ZOC_CMP_Init(CMP_NegaVoltSel_TypeDef CMP_NegaVoltSel,
              CMP_PosInputSel_TypeDef CMP_PosInputSel,
							CMP_PosInputChannelSel_TypeDef PosInputChannel);
void ZOC_CMP_Cmd(FunctionalState NewState);
void OP_OPOSelection(OP_OPOSel_TypeDef OP_OPO);
void ZOC_OP_Cmd(FunctionalState NewState);

/* ZOC Interrupts and flags management functions******************************/
void ZOC_ZCD_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority);
void ZOC_ZCD_ITSelection(uint8_t ZCD_IT,
												 FunctionalState NewState);
void ZOC_CMP_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority);
void ZOC_CMP_ITSelection(uint8_t CMP_IT);
FlagStatus ZOC_GetFlagStatus(ZOC_Flag_TypeDef ZOC_FLAG);
void ZOC_ClearFlag(ZOC_Flag_TypeDef ZOC_FLAG);
/**
 * @}
 */
/* End of exported functions --------------------------------------------------*/
#endif

/**
 * @}
 */

/**
 * @}
 */
/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/