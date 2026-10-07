/**
 ******************************************************************************
 * @file    sc92f_pwm.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   PWM function module
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
#include "sc92f_pwm.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */
 
/** @defgroup PWM
 * @brief PWM driver modules
 * @{
 */

/** @defgroup PWM_Functions
 * @{
 */
 
#if defined (SC92F854x) || defined (SC92F754x) ||defined  (SC92F844xB) || defined (SC92F744xB)||defined  (SC92F84Ax_2) || defined (SC92F74Ax_2)\
		||defined  (SC92F859x) || defined (SC92F759x) || defined (SC92R511x)

uint16_t xdata PWMREG[8] _at_ 0x740;	//PWM占空比调节寄存器
uint16_t pwm_tmpreg[8] = {0, 0, 0, 0, 0, 0, 0, 0};		//PWM占空比调节寄存器缓存数组

/** @defgroup PWM_Group1 Initialization and Configuration functions
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
 * @brief  PWM相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void PWM_DeInit(void)
{
  static uint8_t i;
  PWMCFG = 0X00;
  PWMCON = 0X00;
  IE1 &= 0XFD;
  IP1 &= 0XFD;

  for(i = 0; i < 8; i++)
  {
    PWMREG[i] = 0;
  }
}

/**
 * @brief  PWM初始化配置函数
 * @param  PWM_PresSel[in]:预分频选择
 *          - PWM0_PRESSEL_FOSC_D1:PWM0预分频为Fosc/1
 *          - PWM0_PRESSEL_FOSC_D2:PWM0预分频为Fosc/2
 *          - PWM0_PRESSEL_FOSC_D4:PWM0预分频为Fosc/4
 *          - PWM0_PRESSEL_FOSC_D8:PWM0预分频为Fosc/8
 * @param  PWM_Period:PWM周期配置
 * @retval None
 */ 
void PWM_Init(PWM_PresSel_TypeDef PWM_PresSel,
              uint16_t PWM_Period)
{
  PWM_Period -= 1;
  PWMCFG = (PWMCFG & 0XCF) |
           PWM_PresSel;					//预分频
  PWMCFG = (PWMCFG & 0XF0) | (uint8_t)(
             PWM_Period / 256);	//周期高4位
  PWMCON = (uint8_t)(PWM_Period & 0X00FF);				//周期低8位
}

/**
 * @brief  PWM初始化配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 * @param  PWM_OutputState[in]:PWM输出状态配置
 *          - PWM_OUTPUTSTATE_DISABLE:该PIN脚作为GPIO
 *          - PWM_OUTPUTSTATE_ENABLE:该PIN脚作为PWM
 * @retval None
 */ 
void PWM_OutputStateConfig(uint8_t PWM_OutputPin,
                           PWM_OutputState_TypeDef PWM_OutputState)
{
  uint8_t i;

  for(i = 0; i < 8; i++)
  {
    if(PWM_OutputPin & (0x01 << i))
    {
      if(PWM_OutputState == PWM_OUTPUTSTATE_DISABLE)
      {
        pwm_tmpreg[i] &= 0X7FFF;
      }
      else
      {
        pwm_tmpreg[i] |= 0X8000;
      }

      PWMREG[i] = pwm_tmpreg[i];
    }
  }
}

/**
 * @brief  PWMx正/反向输出配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 * @param  PWM_Polarity[in]:PWM输出状态配置
 *          - PWM_POLARITY_NON_INVERT:PWM输出不反向
 *          - PWM_POLARITY_INVERT:PWM输出反向
 * @retval None
 */ 
void PWM_PolarityConfig(uint8_t PWM_OutputPin,
                        PWM_Polarity_TypeDef PWM_Polarity)
{
  uint8_t i;

  for(i = 0; i < 8; i++)
  {
    if(PWM_OutputPin & (0x01 << i))
    {
      if(PWM_Polarity == PWM_POLARITY_NON_INVERT)
      {
        pwm_tmpreg[i] &= 0XBFFF;
      }
      else
      {
        pwm_tmpreg[i] |= 0X4000;
      }

      PWMREG[i] = pwm_tmpreg[i];
    }
  }
}

/**
 * @brief  PWMx独立工作模式配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  PWM_DutyCycle[in]:PWM占空比配置
 * @retval None
 */ 
void PWM_IndependentModeConfig(PWM_OutputPin_TypeDef PWM_OutputPin,
                               uint16_t PWM_DutyCycle)
{
  uint8_t i;

  for(i = 0; i < 8; i++)
  {
    if(PWM_OutputPin & (0x01 << i))
    {
      pwm_tmpreg[i] = pwm_tmpreg[i] & 0XF000 |
                      PWM_DutyCycle;
      PWMREG[i] = pwm_tmpreg[i];
    }
  }
}
/**
 * @}
 */
/* End of PWM_Group1.	*/

/** @defgroup PWM_Group2 Base functions
 *  @brief   Base functions
 *
@verbatim
 ===============================================================================
                     ##### Base functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  PWM独立模式占空比修改
 * @param  PWM_OutputPin[in]:待修改的PWM独立通道
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  Change_Direction[in]:PWM修改方向
 *          - PWM_DutyChange_Up:PWM占空比增加
 *          - PWM_DutyChange_Dowm:PWM占空比减少
 * @param  DutyIncremental[in]:修改的增量
 * @retval 返回修改成功状态位
 *          - ERROR:失败
 *          - SUCCESS:成功
 */ 
ErrorStatus PWM_IndependentMode_DutyChange(PWM_OutputPin_TypeDef PWM_OutputPin,
    PWM_DutyChange_TypeDef Change_Direction,
    uint16_t DutyIncremental)
{
  uint8_t i;
  uint16_t tmpRegValue;
  uint16_t tmpPolarity = PWMCON | ((PWMCFG & 0x0F) << 8);

  for(i = 0; i < 8; i++)
  {
    if(PWM_OutputPin & (0x01 << i))
    {
	    pwm_tmpreg[i] = PWMREG[i];
      tmpRegValue = pwm_tmpreg[i];

      if(Change_Direction == PWM_DutyChange_Up)
      {
        tmpRegValue += DutyIncremental;				//占空比增加
      }
      else
      {
				if(tmpRegValue<DutyIncremental)
					return ERROR;
				else
					tmpRegValue -= DutyIncremental;				//占空比减少
      }
      /* 计数器发生了溢出 */
      if(tmpRegValue > tmpPolarity)
        return ERROR;
      pwm_tmpreg[i] = pwm_tmpreg[i] & 0XF000 |
                      tmpRegValue;
      PWMREG[i] = pwm_tmpreg[i];
      
    }
  }
  return SUCCESS;
}

/**
 * @brief  PWM功能开关函数
 * @param  NewState[in]:功能启动/关闭选择
 *          - DISABLE:失能
 *          - ENABLE:使能
 * @retval None
 */ 
void PWM_Cmd(FunctionalState NewState)
{
  if(NewState != DISABLE)
  {
    PWMCFG |= 0X80;
  }
  else
  {
    PWMCFG &= 0X7F;
  }
}
/**
 * @}
 */
/* End of PWM_Group2.	*/

/** @defgroup PWM_Group3 Interrupts management functions
 *  @brief   Interrupts management functions
 *
@verbatim
 ===============================================================================
                     ##### Interrupts management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  PWM中断初始化
 * @param  NewState[in]: 断使能/关闭选择
 *              - DISABLE:关闭
 *              - ENABLE:使能
 * @param  Priority[in]: 中断优先级选择
 *              - LOW:低
 *              - HIGH:高
 * @retval None
 */ 
void PWM_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority)
{
  if(NewState != DISABLE)
  {
    IE1 |= 0X02;
  }
  else
  {
    IE1 &= 0XFD;
  }

  if(Priority == LOW)
  {
    IP1 &= ~0X02;
  }
  else
  {
    IP1 |= 0X02;
  }
}

/**
 * @brief  获得PWM中断标志状态
 * @param  None
 * @retval PWM中断标志状态
 *              - RESET:置零
 *              - SET:置起
 */
FlagStatus PWM_GetFlagStatus(void)
{
  return (bool)(PWMCFG & 0X40);
}

/**
 * @brief  清除PWM中断标志状态
 * @param  None
 * @retval None
 */
void PWM_ClearFlag(void)
{
  PWMCFG &= 0XBF;
}
/**
 * @}
 */
/* End of PWM_Group3.	*/
#endif

#if defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)||defined(SC92F6x1x)||defined(SC92F5x1x)\
    ||defined(SC92R436)|| defined(SC92R438) || defined(SC92R439) || defined(SC92R422A) || defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)\
		|| defined(SC92F5x5x) || defined(SC92F531x) || defined(SC92F637x) || defined(SC92F663x) || defined(SC92F563x)
#if defined(SC92F84Hx) || defined(SC92F83Hx) 
uint16_t xdata PWMREG[6] _at_ 0x0334; //PWM占空比调节寄存器
#elif defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)|| defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)
uint16_t xdata PWM0REG4_7[10];
#define  PWM0REG4_7   (((uint16_t xdata*)0x408))
uint16_t xdata PWM0REG0_3[4] _at_ 0x0418;	//PWM占空比调节寄存器
uint16_t xdata PWM2REG[2] _at_ 0x0420;	//PWM占空比调节寄存器
#elif defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)
uint16_t xdata PWM0REG0_3[4] _at_ 0x1018; //PWM00/01/02/03占空比调节寄存器
uint16_t xdata PWM0REG4_7[4];  //PWM04/05/06/07占空比调节寄存器
#define  PWM0REG4_7   (((uint16_t xdata*)0x1008))
uint16_t xdata PWMXREG[6] _at_ 0x1020; //PWM2/PWM3/PWM4占空比调节寄存器
#elif defined(SC92F5x5x)
uint16_t xdata PWMREG[5] _at_ 0x0108; //PWM0占空比调节寄存器
uint16_t xdata PWM2REG _at_ 0x011A; //PWM2占空比调节寄存器
#elif defined(SC92F531x)
uint16_t xdata PWMREG[8] _at_ 0x0108; //PWM0占空比调节寄存器
uint16_t xdata PWM2REG[2] _at_ 0x0118; //PWM2占空比调节寄存器
#elif defined(SC92F637x)
uint16_t xdata PWMREG[4] _at_ 0x0100; //PWM占空比调节寄存器
#elif defined(SC92F663x)
uint16_t xdata PWMREG[2] _at_ 0x1016; //PWM0占空比调节寄存器
uint16_t xdata PWMXREG[6] _at_ 0x101A; //PWM2/PWM3/PWM4占空比调节寄存器
#elif defined(SC92F563x)
uint16_t xdata PWMREG[6] _at_ 0x1020; //PWM0占空比调节寄存器
uint16_t xdata PWMXREG[6] _at_ 0x102C; //PWM2/PWM3/PWM4占空比调节寄存器
#else
uint16_t xdata PWMREG[14] _at_ 0x0834; //PWM占空比调节寄存器
#endif

/** @defgroup PWM_Group4 Expanded Initialization and Configuration functions
 *  @brief Initialization and Configuration functions
 *
@verbatim
 ===============================================================================
                     ##### Expanded Initialization and Configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */
  
/**
 * @brief  PWM相关寄存器复位至缺省值-扩展版
 * @param  None
 * @retval None
 */ 
void PWM_DeInitEX(PWM_Type_TypeDef PWM_Type)
{
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)\
  	|| defined (SC92F663x) || defined (SC92F563x)
	
	  /* PWM0相关寄存器复位到保留值 */
  if(PWM_Type == PWM0_Type)
  {
    uint8_t i;

    //PWM0相关寄存器清零
    PWMCON0 = 0X00;
    PWMCFG = 0X00;
    PWMCON1 = 0X00;
    PWMPDL = 0x00;
    PWMPDH = 0x00;
    IE1 &= 0XFD;
    IP1 &= 0XFD;

    //占空比寄存器
#if defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)
		for(i = 0; i < 4; i++)
    {
      PWM0REG0_3[i] = 0;
		  PWM0REG4_7[i] = 0;
    }
#elif defined(SC92F663x)
		for(i = 0; i < 2; i++)
    {
      PWMREG[i] = 0;
    }
#elif defined(SC92F563x)
		for(i = 0; i < 6; i++)
    {
      PWMREG[i] = 0;
    }
#else
    for(i = 0; i < 14; i++)
    {
      PWMREG[i] = 0;
    }
#endif
  }
  else /* PWM2/3/4相关寄存器复位到保留值 */
  {
#if defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x) || defined(SC92F663x) || defined (SC92F563x)
		TXINX = PWM_Type;
    TXCON &= ~0x04;
    TXMOD &= ~0x3C;
		RCAPXL = 0x00;
		RCAPXH = 0x00;
    switch(PWM_Type)
    {
      case PWM2_Type:
       ET2 = 0;
       IP &= ~0x20;
       PWMXREG[0] = 0;
		   PWMXREG[1] = 0; 
       break;
      case PWM3_Type:
       IE1 &= ~0x40;
       IP1 &= ~0x40;
#if !defined(SC92F552x)
       PWMXREG[2] = 0;
#endif
		   PWMXREG[3] = 0;
       break;
      case PWM4_Type:
       IE1 &= ~0x80;
       IP1 &= ~0x80;
       PWMXREG[4] = 0;
		   PWMXREG[5] = 0;
       break;
      default:
       break;
    }
#else
	  TXINX = PWM_Type;
    TXCON &= ~0x04;
    TXMOD &= ~0x3C;
    switch(PWM_Type)
    {
      case PWM2_Type:
       ET2 = 0;
       IP &= ~0x20;
       PWMREG[0] = 0;
		   PWMREG[1] = 0; 
       break;
      case PWM3_Type:
       IE1 &= ~0x40;
       IP1 &= ~0x40;
       PWMREG[2] = 0;
		   PWMREG[3] = 0;
       break;
      case PWM4_Type:
       IE1 &= ~0x80;
       IP1 &= ~0x80;
       PWMREG[4] = 0;
		   PWMREG[5] = 0;
       break;
      default:
       break;
    }
#endif
   }
#elif defined(SC92F84Hx) || defined(SC92F83Hx)
	  TXINX = PWM_Type;
    TXCON &= ~0x04;
    TXMOD &= ~0x3C;
    switch(PWM_Type)
    {
      case PWM2_Type:
       ET2 = 0;
       IP &= ~0x20;
       PWMREG[0] = 0;
		   PWMREG[1] = 0; 
       break;
      case PWM3_Type:
       IE1 &= ~0x40;
       IP1 &= ~0x40;
       PWMREG[2] = 0;
		   PWMREG[3] = 0;
       break;
      case PWM4_Type:
       IE1 &= ~0x80;
       IP1 &= ~0x80;
       PWMREG[4] = 0;
		   PWMREG[5] = 0;
       break;
      default:
       break;
		}
#elif defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)|| defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)
	  if(PWM_Type == PWM0_Type)
		{
			uint8_t i;

			//PWM0相关寄存器清零
			PWMCON0 = 0X00;
			PWMCFG = 0X00;
			PWMCON1 = 0X00;
			PWMPDL = 0x00;
			PWMPDH = 0x00;
			IE1 &= 0XFD;
			IP1 &= 0XFD;

			//占空比寄存器
			for(i = 0; i < 4; i++)
			{
				PWM0REG0_3[i] = 0;
				PWM0REG4_7[i] = 0;
			}
		}
		else /* PWM2相关寄存器复位到保留值 */
		{
			T2CON &= ~0x04;
			T2MOD &= ~0x3C;
			RCAP2L = 0x00;
			RCAP2H= 0x00;
			ET2 = 0;
			IP &= ~0x20;
			PWM2REG[0] = 0;
			PWM2REG[1] = 0; 
		}
#elif defined(SC92F5x5x)
	  if(PWM_Type == PWM0_Type)
		{
			//PWM0相关寄存器清零
			PWMCON0 = 0X00;
			PWMCFG = 0X00;
			PWMCON1 = 0X00;
			PWMPDL = 0x00;
			PWMPDH = 0x00;
			IE1 &= 0XFD;
			IP1 &= 0XFD;

			//占空比寄存器
			PWMREG[0] = 0;
			PWMREG[1] = 0;
			PWMREG[4] = 0;
			PWMREG[5] = 0;
			PWMREG[6] = 0;
		}
		else /* PWM2相关寄存器复位到保留值 */
		{
			T2CON &= ~0x04;
			T2MOD &= ~0x28;
			RCAP2L = 0x00;
			RCAP2H= 0x00;
			ET2 = 0;
			IP &= ~0x20;
			PWM2REG = 0;
		}
#elif defined(SC92F531x)
	  if(PWM_Type == PWM0_Type)
		{
			uint8_t i;

			//PWM0相关寄存器清零
			PWMCON0 = 0X00;
			PWMCFG = 0X00;
			PWMCON1 = 0X00;
			PWMPDL = 0x00;
			PWMPDH = 0x00;
			IE1 &= 0XFD;
			IP1 &= 0XFD;

			//占空比寄存器
			for(i = 0; i < 8; i++)
			{
				PWMREG[i] = 0;
			}
		}
		else /* PWM2相关寄存器复位到保留值 */
		{
			T2CON &= ~0x04;
			T2MOD &= ~0x3C;
			RCAP2L = 0x00;
			RCAP2H= 0x00;
			ET2 = 0;
			IP &= ~0x20;
			PWM2REG[0] = 0;
			PWM2REG[1] = 0; 
		}
#elif defined(SC92F637x)
	  TXINX = PWM_Type;
    TXCON &= ~0x04;
    TXMOD &= ~0x3C;
		RCAPXL = 0x00;
		RCAPXH = 0x00;
    switch(PWM_Type)
    {
      case PWM2_Type:
       ET2 = 0;
       IP &= ~0x20;
       PWMREG[0] = 0;
		   PWMREG[1] = 0; 
       break;
      case PWM3_Type:
       IE1 &= ~0x40;
       IP1 &= ~0x40;
       PWMREG[2] = 0;
		   PWMREG[3] = 0;
       break;
      default:
       break;
		}
#endif
}

 /**
 * @brief  PWM初始化配置函数
 * @param  PWM_PresSel[in]:预分频选择
 *          - PWM0_PRESSEL_FOSC_D1:PWM0预分频为Fosc/1
 *          - PWM0_PRESSEL_FOSC_D2:PWM0预分频为Fosc/2
 *          - PWM0_PRESSEL_FOSC_D4:PWM0预分频为Fosc/4
 *          - PWM0_PRESSEL_FOSC_D8:PWM0预分频为Fosc/8
 * @param  PWM_Period:PWM周期配置
 * @retval None
 */ 
void PWM_Init(PWM_PresSel_TypeDef PWM_PresSel, uint16_t PWM_Period)
{
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)\
	  || defined (SC92F663x) || defined (SC92F563x)
  if((PWM_PresSel & 0X0F) == PWM0_Type)
  {
		/* PWM0时基初始化 */
    PWM_Period -= 1;
    PWMCON0 = ((PWMCON0 & 0XCF) | PWM_PresSel);        //预分频
    PWMPDH = (uint8_t)(PWM_Period >> 8);               //周期高8位
    PWMPDL = (uint8_t)(PWM_Period & 0X00FF);           //周期低8位
  }
  else
  {
		PWM_Period -= 1;
    TXINX = (PWM_PresSel & 0X0F);							//控制寄存器指针指向对应的PWM源	
		if(PWM_PresSel & 0XF0)
	  {		
	    TXMOD |= 0x80; 
	  }
    else
	  {
	    TXMOD &= ~0x80;
	  }		
    RCAPXH = (uint8_t)(PWM_Period >> 8);			//周期高8位
    RCAPXL = (uint8_t)(PWM_Period & 0X00FF);		//周期低8位
  }
#elif defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F637x)
	PWM_Period -= 1;
	TXINX = (PWM_PresSel & 0X0F);							//控制寄存器指针指向对应的PWM源
	if(PWM_PresSel & 0XF0)
	{		
	  TXMOD |= 0x80; 
	}
  else
	{
	  TXMOD &= ~0x80;
	}		
  RCAPXH = (uint8_t)(PWM_Period >> 8);			//周期高8位
  RCAPXL = (uint8_t)(PWM_Period & 0X00FF);		//周期低8位
#elif  defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)|| defined(SC92R438) || defined(SC92R439)|| defined(SC92R422A)\
	     || defined(SC92F531x)
  if((PWM_PresSel & 0X0F) == PWM0_Type)
  {
		/* PWM0时基初始化 */
    PWM_Period -= 1;
    PWMCON0 = ((PWMCON0 & 0XCF) | PWM_PresSel);        //预分频
    PWMPDH = (uint8_t)(PWM_Period >> 8);               //周期高8位
    PWMPDL = (uint8_t)(PWM_Period & 0X00FF);           //周期低8位
  }
  else
  {
		PWM_Period -= 1;
 		if((PWM_PresSel & 0xF0)!=0)
		{
			T2MOD |=0x80;
		}
    RCAP2H = (uint8_t)(PWM_Period >> 8);			//周期高8位
    RCAP2L = (uint8_t)(PWM_Period & 0X00FF);		//周期低8位
  }
#elif  defined(SC92F5x5x)
	
  if((PWM_PresSel & 0X0F) == PWM0_Type)
  {
		/* PWM0时基初始化 */
    PWM_Period -= 1;
    PWMCON0 = ((PWMCON0 & 0XCF) | PWM_PresSel);        //预分频
    PWMPDH = (uint8_t)(PWM_Period >> 8);               //周期高8位
    PWMPDL = (uint8_t)(PWM_Period & 0X0003);           //周期低2位
  }
  else
  {
		PWM_Period -= 1;
 		if((PWM_PresSel & 0xF0)!=0)
		{
			T2MOD |=0x80;
		}
    RCAP2H = (uint8_t)(PWM_Period >> 8);			//周期高8位
    RCAP2L = (uint8_t)(PWM_Period & 0X00FF);		//周期低8位
  }
#endif
}
/**
 * @}
 */
/* End of PWM_Group4.	*/

/** @defgroup PWM_Group5 Expanded  Base functions
 *  @brief   Expanded Base functions
 *
@verbatim
 ===============================================================================
                     ##### Expanded  Base functions #####
 ===============================================================================
@endverbatim
  * @{
  */
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)  || defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)\
    || defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)|| defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)\
		|| defined(SC92F531x) || defined(SC92F663x) || defined(SC92F563x)
/**
 * @brief  选择PWM的对齐模式
 * @param  PWM_Aligned_Mode[in]:选择对齐模式
 *          - PWM0_Edge_Aligned_Mode:PWM边沿对齐模式
 *          - PWM0_Center_Alignment_Mode:PWM中心对齐模式
 * @retval None
 */ 
void PWM_Aligned_Mode_Select(PWM_Aligned_Mode_TypeDef PWM_Aligned_Mode)
{
  //PWM0选择对齐模式配置
  if(PWM_Aligned_Mode == PWM0_Edge_Aligned_Mode)
  {
    PWMCON0 &= 0XFE;
  }
  else if(PWM_Aligned_Mode == PWM0_Center_Alignment_Mode)
  {
    PWMCON0 |= 0X01;
  }
}
#endif

/**
 * @brief  PWMx输出使能/失能配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 *          - PWM00:PWM输出通道选择: PWM00
 *          - PWM01:PWM输出通道选择: PWM01
 *          - PWM02:PWM输出通道选择: PWM02
 *          - PWM03:PWM输出通道选择: PWM03
 *          - PWM04:PWM输出通道选择: PWM04
 *          - PWM05:PWM输出通道选择: PWM05
 *          - PWM06:PWM输出通道选择: PWM06
 *          - PWM07:PWM输出通道选择: PWM07
 *          - PWM20:PWM输出通道选择: PWM20
 *          - PWM21:PWM输出通道选择: PWM21
 *          - PWM30:PWM输出通道选择: PWM30
 *          - PWM31:PWM输出通道选择: PWM31
 *          - PWM40:PWM输出通道选择: PWM40
 *          - PWM41:PWM输出通道选择: PWM41
 * @param  PWM_OutputState[in]:PWM输出状态配置
 *          - PWM_OUTPUTSTATE_DISABLE:该PIN脚作为GPIO
 *          - PWM_OUTPUTSTATE_ENABLE:该PIN脚作为PWM
 * @retval None
 */ 
void PWM_OutputStateConfig(uint8_t PWM_OutputPin,
                           PWM_OutputState_TypeDef PWM_OutputState)
{
	unsigned char Reg_Data;
	
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)\
		|| defined(SC92F663x) || defined(SC92F563x)
 
	/* PWM0输出通道使能配置 */
	if((PWM_OutputPin & 0xF0) == 0x00)
  {
    if(PWM_OutputState == PWM_OUTPUTSTATE_ENABLE)
    {
      PWMCON1 |= 1 << (PWM_OutputPin & 0x0F);
    }
    else
    {
      PWMCON1 &= ~(1 << (PWM_OutputPin & 0x0F));
    }
  }
  else
  {
    TXINX = (PWM_OutputPin & 0xF0) >> 4;

    if(PWM_OutputPin & 0x01)
    {
      Reg_Data = 0x20;
    }
    else
    {
      Reg_Data = 0x10;
    }

    if(PWM_OutputState == PWM_OUTPUTSTATE_ENABLE)
    {
      TXMOD |= Reg_Data;
    }
    else
    {
      TXMOD &= ~Reg_Data;
    }
  }	
#elif defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F637x)
	
	TXINX = (PWM_OutputPin & 0xF0) >> 4;
	if(PWM_OutputPin & 0x01)
	{
		Reg_Data = 0x20;
	}
	else
	{
		Reg_Data = 0x10;
	}
	if(PWM_OutputState == PWM_OUTPUTSTATE_ENABLE)
	{
		TXMOD |= Reg_Data;
	}
	else
	{
		TXMOD &= ~Reg_Data;
	}
#elif defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)|| defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)\
			|| defined(SC92F531x)
	/* PWM0输出通道使能配置 */
	if((PWM_OutputPin & 0xF0) == 0x00)
  {
    if(PWM_OutputState == PWM_OUTPUTSTATE_ENABLE)
    {
      PWMCON1 |= 1 << (PWM_OutputPin & 0x0F);
    }
    else
    {
      PWMCON1 &= ~(1 << (PWM_OutputPin & 0x0F));
    }
  }
  else
  {

    if(PWM_OutputPin & 0x01)
    {
      Reg_Data = 0x20;
    }
    else
    {
      Reg_Data = 0x10;
    }

    if(PWM_OutputState == PWM_OUTPUTSTATE_ENABLE)
    {
      T2MOD |= Reg_Data;
    }
    else
    {
      T2MOD &= ~Reg_Data;
    }
  }
#elif defined(SC92F5x5x)
 
	/* PWM0输出通道使能配置 */
	if((PWM_OutputPin & 0xF0) == 0x00)
  {
    if(PWM_OutputState == PWM_OUTPUTSTATE_ENABLE)
    {
      PWMCON1 |= 1 << (PWM_OutputPin & 0x0F);
    }
    else
    {
      PWMCON1 &= ~(1 << (PWM_OutputPin & 0x0F));
    }
  }
  else
  {
    if(PWM_OutputPin & 0x01)
    {
      Reg_Data = 0x20;
    }

    if(PWM_OutputState == PWM_OUTPUTSTATE_ENABLE)
    {
      T2MOD |= Reg_Data;
    }
    else
    {
      T2MOD &= ~Reg_Data;
    }
  }		
#endif
		
}

/**
 * @brief  PWMx正/反向输出配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 * @param  PWM_Polarity[in]: PWM输出正/反向配置
 *              - PWM_POLARITY_NON_INVERT:PWM输出不反向
 *              - PWM_POLARITY_INVERT:PWM输出反向
 * @retval None
 */ 
void PWM_PolarityConfig(uint8_t PWM_OutputPin,
                        PWM_Polarity_TypeDef PWM_Polarity)
{
	unsigned char Reg_Data;
	
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)\
		|| defined(SC92F663x) || defined(SC92F563x)
  if((PWM_OutputPin & 0xF0) == 0x00)
  {
    if(PWM_Polarity == PWM_POLARITY_INVERT)
    {
      PWMCFG |= 1 << (PWM_OutputPin & 0x0F);
    }
    else
    {
      PWMCFG &= ~(1 << (PWM_OutputPin & 0x0F));
    }
  }
  else
  {
    TXINX = (PWM_OutputPin & 0xF0) >> 4;

    if(PWM_OutputPin & 0x01)
    {
      Reg_Data = 0x08;
    }
    else
    {
      Reg_Data = 0x04;
    }

    if(PWM_Polarity == PWM_POLARITY_INVERT)
    {
      TXMOD |= Reg_Data;
    }
    else
    {
      TXMOD &= ~Reg_Data;
    }
  }	
#elif defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F637x)
	
	TXINX = (PWM_OutputPin & 0xF0) >> 4;

	if(PWM_OutputPin & 0x01)
	{
		Reg_Data = 0x08;
	}
	else
	{
		Reg_Data = 0x04;
	}

	if(PWM_Polarity == PWM_POLARITY_INVERT)
	{
		TXMOD |= Reg_Data;
	}
	else
	{
		TXMOD &= ~Reg_Data;
	}
#elif defined(SC92F6x1x) || defined(SC92F5x1x)|| defined(SC92R436)|| defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)\
	    || defined(SC92F531x)
  if((PWM_OutputPin & 0xF0) == 0x00)
  {
    if(PWM_Polarity == PWM_POLARITY_INVERT)
    {
      PWMCFG |= 1 << (PWM_OutputPin & 0x0F);
    }
    else
    {
      PWMCFG &= ~(1 << (PWM_OutputPin & 0x0F));
    }
  }
  else
  {

    if(PWM_OutputPin & 0x01)
    {
      Reg_Data = 0x08;
    }
    else
    {
      Reg_Data = 0x04;
    }

    if(PWM_Polarity == PWM_POLARITY_INVERT)
    {
      T2MOD |= Reg_Data;
    }
    else
    {
      T2MOD &= ~Reg_Data;
    }
  }
#elif defined(SC92F5x5x)
  if((PWM_OutputPin & 0xF0) == 0x00)
  {
    if(PWM_Polarity == PWM_POLARITY_INVERT)
    {
      PWMCFG |= 1 << (PWM_OutputPin & 0x0F);
    }
    else
    {
      PWMCFG &= ~(1 << (PWM_OutputPin & 0x0F));
    }
  }
  else
  {

    if(PWM_OutputPin & 0x01)
    {
      Reg_Data = 0x08;
    }

    if(PWM_Polarity == PWM_POLARITY_INVERT)
    {
      T2MOD |= Reg_Data;
    }
    else
    {
      T2MOD &= ~Reg_Data;
    }
  }
#endif
		
}	

/**
 * @brief  PWMx独立工作模式配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 *          - PWM00:PWM输出通道选择: PWM00
 *          - PWM01:PWM输出通道选择: PWM01
 *          - PWM02:PWM输出通道选择: PWM02
 *          - PWM03:PWM输出通道选择: PWM03
 *          - PWM04:PWM输出通道选择: PWM04
 *          - PWM05:PWM输出通道选择: PWM05
 *          - PWM06:PWM输出通道选择: PWM06
 *          - PWM07:PWM输出通道选择: PWM07
 *          - PWM20:PWM输出通道选择: PWM20
 *          - PWM21:PWM输出通道选择: PWM21
 *          - PWM30:PWM输出通道选择: PWM30
 *          - PWM31:PWM输出通道选择: PWM31
 *          - PWM40:PWM输出通道选择: PWM40
 *          - PWM41:PWM输出通道选择: PWM41
 * @param  PWM_DutyCycle[in]: PWM占空比配置
 * @retval None
 */ 
void PWM_IndependentModeConfig(PWM_OutputPin_TypeDef PWM_OutputPin,
                               uint16_t PWM_DutyCycle)
{
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)
  if((PWM_OutputPin & 0xF0) == 0x00)
  {
    PWMCON0 &= ~0x02;				//配置为独立模式
    /* 设置PWM占空比 */
    PWMREG[ PWM_OutputPin + 6] = PWM_DutyCycle;
  }
  else
  {
    PWMREG[PWM_OutputPin & 0x0F] = PWM_DutyCycle;
  }
#elif defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)
	if((PWM_OutputPin & 0xF0) == 0x00)
  {
    PWMCON0 &= ~0x02;				//配置为独立模式
    /* 设置PWM占空比 */
		if((PWM_OutputPin>=0)&&(PWM_OutputPin<=3))
		{
			PWM0REG0_3[ PWM_OutputPin ] = PWM_DutyCycle;
		}
		else
		{
			PWM0REG4_7[ 7-PWM_OutputPin ] = PWM_DutyCycle;
		}
  }
  else
  {
    PWMXREG[PWM_OutputPin & 0x0F] = PWM_DutyCycle;
  }
#elif defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F637x)
	PWMREG[PWM_OutputPin & 0x0F] = PWM_DutyCycle;
#elif defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)|| defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)
  if((PWM_OutputPin & 0xF0) == 0x00)
  {
    PWMCON0 &= ~0x02;				//配置为独立模式
    /* 设置PWM占空比 */
		if((PWM_OutputPin>=0)&&(PWM_OutputPin<=3))
    {
			PWM0REG0_3[ PWM_OutputPin ] = PWM_DutyCycle;
		}
		else
		{
			PWM0REG4_7[ 7-PWM_OutputPin ] = PWM_DutyCycle;
		}
  }
  else
  {
      (uint16_t)PWM2REG[PWM_OutputPin & 0x0F] = PWM_DutyCycle;
  }	
#elif defined(SC92F5x5x)
  if((PWM_OutputPin & 0xF0) == 0x00)
  {
    PWMCON0 &= ~0x02;				//配置为独立模式
    /* 设置PWM占空比 */
		PWMREG[ PWM_OutputPin ] = PWM_DutyCycle<<6;
  }
  else
  {
    PWM2REG = PWM_DutyCycle;
  }	
#elif defined(SC92F531x)
  if((PWM_OutputPin & 0xF0) == 0x00)
  {
    PWMCON0 &= ~0x02;				//配置为独立模式
    /* 设置PWM占空比 */
		PWMREG[ PWM_OutputPin ] = PWM_DutyCycle;
  }
  else
  {
    (uint16_t)PWM2REG[PWM_OutputPin & 0x0F] = PWM_DutyCycle;
  }
#elif defined(SC92F663x) || defined (SC92F563x)
  if((PWM_OutputPin & 0xF0) == 0x00)
  {
    PWMCON0 &= ~0x02;				//配置为独立模式
    /* 设置PWM占空比 */
		PWMREG[ PWM_OutputPin ] = PWM_DutyCycle;
  }
  else
  {
    (uint16_t)PWMXREG[PWM_OutputPin & 0x0F] = PWM_DutyCycle;
  }
#endif
}

#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)\
   || defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)|| defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)\
	 || defined(SC92F5x5x)|| defined(SC92F531x)|| defined(SC92F663x) || defined(SC92F563x)
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)
/**
 * @brief  PWMxPWMy互补工作模式配置函数
 * @param  PWM_ComplementaryOutputPin[in]:PWMxPWMy互补通道选择
 *          - PWM0PWM3:PWM输出通道选择:PWM互补模式通道选择:PWM0、PWM3
 *          - PWM1PWM4:PWM输出通道选择:PWM互补模式通道选择:PWM1、PWM4
 *          - PWM2PWM5:PWM输出通道选择:PWM互补模式通道选择:PWM2、PWM5
 * @param  PWM_DutyCycle[in]: PWM占空比配置
 * @retval None
 */ 
void PWM_ComplementaryModeConfig(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
                                 uint16_t PWM_DutyCycle)
{
  PWMCON0 |= 0x02;				//配置为互补模式
  PWMREG[6 + PWM_ComplementaryOutputPin] = PWM_DutyCycle;
}
#elif defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)|| defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)\
		  || defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)|| defined(SC92F531x) || defined(SC92F563x)
/**
 * @brief  PWMxPWMy互补工作模式配置函数
 * @param  PWM_ComplementaryOutputPin[in]:PWMxPWMy互补通道选择
 *          - PWM0PWM3:PWM输出通道选择:PWM互补模式通道选择:PWM00、PWM01
 *          - PWM2PWM3:PWM输出通道选择:PWM互补模式通道选择:PWM02、PWM03
 *          - PWM4PWM5:PWM输出通道选择:PWM互补模式通道选择:PWM04、PWM05
 *          - PWM6PWM7:PWM输出通道选择:PWM互补模式通道选择:PWM06、PWM07
 * @param  PWM_DutyCycle[in]: PWM占空比配置
 * @retval None
 */ 
#if defined(SC92F531x) || defined(SC92F563x)
void PWM_ComplementaryModeConfig(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
                                 uint16_t PWM_DutyCycle)
{
  PWMCON0 |= 0x02;				//配置为互补模式

	PWMREG[ PWM_ComplementaryOutputPin ] = PWM_DutyCycle;
}
#else
void PWM_ComplementaryModeConfig(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
                                 uint16_t PWM_DutyCycle)
{
  PWMCON0 |= 0x02;				//配置为互补模式

	if((PWM_ComplementaryOutputPin>=0)&&(PWM_ComplementaryOutputPin<=2))
  {
		PWM0REG0_3[ PWM_ComplementaryOutputPin ] = PWM_DutyCycle;
	}
	else
	{
	  PWM0REG4_7[ 7-PWM_ComplementaryOutputPin] = PWM_DutyCycle;
	}
}
#endif
#elif defined(SC92F5x5x) || defined(SC92F663x)
/**
 * @brief  PWMxPWMy互补工作模式配置函数
 * @param  PWM_ComplementaryOutputPin[in]:PWMxPWMy互补通道选择
 *          - PWM0PWM1:PWM输出通道选择:PWM互补模式通道选择:PWM00、PWM01
 *          - PWM4PWM5:PWM输出通道选择:PWM互补模式通道选择:PWM04、PWM05
 * @param  PWM_DutyCycle[in]: PWM占空比配置
 * @retval None
 */ 
void PWM_ComplementaryModeConfig(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
                                 uint16_t PWM_DutyCycle)
{
  PWMCON0 |= 0x02;				//配置为互补模式

	PWMREG[ PWM_ComplementaryOutputPin ] = PWM_DutyCycle;
}
#endif

/**
 * @brief  PWM互补工作模式下死区时间配置函数
 * @param  PWM_RisingDeadTime[in]:PWM_RisingDeadTime:PWM死区上升时间00-FF
 * @param  PWM_RisingDeadTime[in]: PWM_FallingDeadTime:PWM死区下降时间00-FF
 * @retval None
 */ 
void PWM_DeadTimeConfig(uint8_t PWM_RisingDeadTime, uint8_t PWM_FallingDeadTime)
{
  PWMDFR = (PWM_RisingDeadTime | (PWM_FallingDeadTime << 4));
}
#endif

/**
 * @brief  PWM功能开关函数-扩展版
 * @param  PWM_Type[in]:PWM类型
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @param  NewState[in]: 功能启动/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @retval None
 */ 
void PWM_CmdEX(PWM_Type_TypeDef PWM_Type,
               FunctionalState NewState)
{
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)\
		|| defined(SC92F663x) || defined(SC92F563x)
  if(PWM_Type == PWM0_Type)
  {
    if(NewState != DISABLE)
    {
      PWMCON0 |= 0X80;
    }
    else
    {
      PWMCON0 &= 0X7F;
    }
  }
  else
  {
    TXINX = PWM_Type;
    if(NewState != DISABLE)
    {
      TXCON |= 0X04;
    }
    else
    {
      TXCON &= ~0X04;
    }
  }	
#elif defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F637x)
	TXINX = PWM_Type;
  if(NewState != DISABLE)
  {
    TXCON |= 0X04;
  }
  else
  {
    TXCON &= ~0X04;
  }
#elif defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)|| defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)\
	    || defined(SC92F5x5x) || defined(SC92F531x)
  if(PWM_Type == PWM0_Type)
  {
    if(NewState != DISABLE)
    {
      PWMCON0 |= 0X80;
    }
    else
    {
      PWMCON0 &= 0X7F;
    }
  }
  else
  {
    if(NewState != DISABLE)
    {
      T2CON |= 0X04;
    }
    else
    {
      T2CON &= ~0X04;
    }
  }	
#endif
}

/**
 * @brief  PWM中断初始化
 * @param  NewState[in]: 中断使能/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @param  Priority[in]: 中断优先级选择
 *          - LOW:低
 *          - HIGH:高
 * @retval None
 */ 
void PWM_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority)
{
  if(NewState != DISABLE)
  {
    IE1 |= 0X02;
  }
  else
  {
    IE1 &= 0XFD;
  }

  if(Priority == LOW)
  {
    IP1 &= ~0X02;
  }
  else
  {
    IP1 |= 0X02;
  }
}

/**
 * @brief  PWM中断配置函数-扩展版
 * @param  PWM_Type[in]: PWM源选择
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @param  NewState[in]: 中断使能/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @param  Priority[in]: 中断优先级选择
 *          - LOW:低
 *          - HIGH:高
 * @retval None
 */ 
void PWM_ITConfigEX(PWM_Type_TypeDef PWM_Type, FunctionalState NewState, PriorityStatus Priority)
{
	switch(PWM_Type)
  {
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F6x1x) || defined(SC92F5x1x)|| defined(SC92R436)\
		|| defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)|| defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)\
		|| defined(SC92F5x5x) || defined(SC92F531x) || defined(SC92F663x) || defined(SC92F563x)
		case PWM0_Type:
      PWM_ITConfig(NewState, Priority);
      break;
#endif	
    case PWM2_Type:
    {
      if(NewState == DISABLE)
        ET2 = 0;
      else
        ET2 = 1;

      if(Priority == LOW)
        IPT2 = 0;
      else
        IPT2 = 1;
    }
    break;
#if !defined(SC92F6x1x) && !defined(SC92F5x1x)&& !defined(SC92R436)&& !defined(SC92R438)&& !defined(SC92R439)&& !defined(SC92R422A)\
		&& !defined(SC92F5x5x) && !defined(SC92F531x)
    case PWM3_Type:
    {
      if(NewState == DISABLE)
        IE1 &= 0XBF;
      else
        IE1 |= 0X40;

      if(Priority == LOW)
        IP1 &= 0XBF;
      else
        IP1 |= 0X40;
    }
    break;
#if !defined(SC92F637x)
    case PWM4_Type:
    {
      if(NewState == DISABLE)
        IE1 &= 0X7F;
      else
        IE1 |= 0X80;

      if(Priority == LOW)
        IP1 &= 0X7F;
      else
        IP1 |= 0X80;
    }
    break;
#endif
#endif
    default:
      break;
  }
}

/**
 * @brief  PWM独立模式配置-扩展版
 * @param  PWM_OutputPin[in]: PWM通道
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  PWM_DutyCycle[in]: PWM占空比配置
 * @param  PWM_OutputState[in]: 功能启动/关闭选择
 *          - PWM_OUTPUTSTATE_DISABLE:该PIN脚作为GPIO
 *          - PWM_OUTPUTSTATE_ENABLE:该PIN脚作为PWM
 * @retval None
 */
void PWM_IndependentModeConfigEX(PWM_OutputPin_TypeDef PWM_OutputPin,
                                 uint16_t PWM_DutyCycle,
                                 PWM_OutputState_TypeDef PWM_OutputState)
{
  PWM_IndependentModeConfig(PWM_OutputPin, PWM_DutyCycle); //配置占空比
  PWM_OutputStateConfig(PWM_OutputPin, PWM_OutputState);   //IO复用PWM配置函数
  if(PWM_OutputState == ENABLE)
  {
    PWM_CmdEX(PWM_OutputPin >> 4, ENABLE); //开启PWM
  }
}
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)\
    || defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)|| defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)\
		|| defined(SC92F5x5x) || defined(SC92F531x) || defined(SC92F663x) || defined(SC92F563x)
/**
 * @brief  PWM互补模式配置-扩展版
 * @param  PWM_ComplementaryOutputPin[in]:PWM通道
 *          - PWM00PWM01:PWM互补模式通道选择:PWM00、PWM01
 *          - PWM02PWM03:PWM互补模式通道选择:PWM02、PWM03
 *          - PWM04PWM05:PWM互补模式通道选择:PWM04、PWM05
 *          - PWM06PWM07:PWM互补模式通道选择:PWM06、PWM07
 * @param  PWM_DutyCycle[in]: PWM占空比配置
 * @param  PWM_OutputState[in]: 功能启动/关闭选择
 * @retval None
 */ 
void PWM_ComplementaryModeConfigEX(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
                                   uint16_t PWM_DutyCycle,
                                   PWM_OutputState_TypeDef PWM_OutputState)
{
  PWM_ComplementaryModeConfig(PWM_ComplementaryOutputPin, PWM_DutyCycle); //配置占空比
  PWM_OutputStateConfig(PWM_ComplementaryOutputPin, PWM_OutputState);     //IO复用PWM配置函数
  PWM_OutputStateConfig(PWM_ComplementaryOutputPin + 1, PWM_OutputState); //IO复用PWM配置函数
  if(PWM_OutputState == ENABLE)
  {
    PWM_CmdEX(PWM_ComplementaryOutputPin >> 4, ENABLE); //开启PWM
  }
}
#endif
/**
 * @brief  获取PWM中断标志位-扩展版
 * @param  PWM_Type[in]:PWM源选择
 *          - PWM0_Type:操作PWM0
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @retval PWM中断标志位状态
 *              - RESET:置零
 *              - SET:置起
 */ 
FlagStatus PWM_GetFlagStatusEX(PWM_Type_TypeDef PWM_Type)
{
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F6x1x) || defined(SC92F5x1x)|| defined(SC92R436)\
	  || defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)|| defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)\
		|| defined(SC92F5x5x) || defined(SC92F531x) || defined(SC92F663x) || defined(SC92F563x)
	if((PWM_Type == PWM0_Type))
  {
    return (bool)(PWMCON0 & 0X40);
  }
#endif
#if !defined(SC92F6x1x) && !defined(SC92F5x1x)&& !defined(SC92R436)&& !defined(SC92R438)&& !defined(SC92R439)&& !defined(SC92R422A)\
		&& !defined(SC92F5x5x) && !defined(SC92F531x) && !defined(SC92F637x)
  if((PWM_Type == PWM2_Type) || (PWM_Type == PWM3_Type) || (PWM_Type == PWM4_Type))
  {
    TXINX = PWM_Type;
    return (bool)(TXCON & 0x80);
  }
#elif defined(SC92F6x1x) || defined(SC92F5x1x) ||defined(SC92R436)||defined(SC92R438)||defined(SC92R439)||defined(SC92R422A)\
			|| defined(SC92F5x5x) || defined(SC92F531x)
  if((PWM_Type == PWM2_Type))
  {
    return (bool)(T2CON & 0x80);
  }
#elif defined(SC92F637x)
  if((PWM_Type == PWM2_Type) || (PWM_Type == PWM3_Type))
  {
    TXINX = PWM_Type;
    return (bool)(TXCON & 0x80);
  }
#endif
  return RESET;
}

/**
 * @brief  清除PWM中断标志位-扩展版
 * @param  PWM_Type[in]:PWM源选择
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @retval None
 */ 
void PWM_ClearFlagEX(PWM_Type_TypeDef PWM_Type)
{
#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F6x1x) || defined(SC92F5x1x)|| defined(SC92R436)\
	  || defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)|| defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)\
		|| defined(SC92F5x5x) || defined(SC92F531x)|| defined(SC92F663x)|| defined(SC92F563x)
	if((PWM_Type == PWM0_Type))
  {
    PWMCON0 &= ~0X40;
  }
#endif
#if !defined(SC92F6x1x) && !defined(SC92F5x1x)&& !defined(SC92R436)&& !defined(SC92R438)&& !defined(SC92R439)&& !defined(SC92R422A)\
		&& !defined(SC92F5x5x) && !defined(SC92F531x) && !defined(SC92F637x)
  if((PWM_Type == PWM2_Type) || (PWM_Type == PWM3_Type) || (PWM_Type == PWM4_Type))
  {
    TXINX = PWM_Type;
    TXCON &= ~0x80;
  }
#elif defined(SC92F6x1x) || defined(SC92F5x1x)|| defined(SC92R436)|| defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)\
			|| defined(SC92F5x5x) || defined(SC92F531x)
  if((PWM_Type == PWM2_Type))
  {
    T2CON &= ~0x80;
  }
#elif defined(SC92F637x)
  if((PWM_Type == PWM2_Type) || (PWM_Type == PWM3_Type))
  {
    TXINX = PWM_Type;
    TXCON &= ~0x80;
  }
#endif
}

#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x) || defined(SC92F6x1x) || defined(SC92F5x1x)|| defined(SC92R436)\
    || defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)|| defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)\
		|| defined(SC92F531x) || defined(SC92F663x) || defined(SC92F563x)
/**
 * @brief  获得PWM故障检测标志位状态
 * @param  PWM_Type[in]:PWM选择类型
 * @retval PWM故障检测标志位状态
 *              - RESET:置零
 *              - SET:置起
 */ 
FlagStatus PWM_GetFaultDetectionFlagStatusEX(PWM_Type_TypeDef PWM_Type)
{
  if(PWM_Type == PWM0_Type)
  {
		return (bool)(PWMFLT & 0X40);
	}
	return RESET;
}

/**
 * @brief  清除PWM故障检测标志位状态   // ！注意,处于锁存模式下，此位可软件清除
 * @param  PWM_Type[in]:PWM源选择
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @retval None
 */ 
void PWM_ClearFaultDetectionFlagEX(PWM_Type_TypeDef PWM_Type)
{
  if(PWM_Type == PWM0_Type)
  {
		PWMFLT &= 0XBF;
	}
}

/**
 * @brief  PWM故障检测功能开启/关闭-扩展版
 * @param  PWM_Type[in]: PWM源选择
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @param  NewState[in]: 中断使能/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @retval None
 */ 
void PWM_FaultDetectionConfigEX(PWM_Type_TypeDef PWM_Type, FunctionalState NewState)
{
  if(PWM_Type == PWM0_Type)
	{
		if(NewState != DISABLE)
		{
			PWMFLT |= 0X80;
		}
		else
		{
			PWMFLT &= 0X7F;
		}
	}
}

/**
 * @brief  PWM故障检测模式设置
 * @param  PWM_Type[in]: PWM源选择
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @param  FaultDetectionMode[in]: 故障检测功能模式设置:立即模式/锁存模式
 *          - PWM0_Latch_Mode:PWM故障检测模式:锁存模式
 *          - PWM0_Immediate_Mode:PWM故障检测模式:立即模式
 * @param  FaultDetectionVoltageSelect[in]: 故障检测电平选择
 *          - PWM_FaultDetectionVoltage_Low:PWM故障检测低电平选择
 *          - PWM_FaultDetectionVoltage_high:PWM故障检测高电平选择
 * @param  FaultDetectionWaveFilteringTime[in]: 故障检测输入信号滤波时间选择
 *          - PWM_WaveFilteringTime_0us:PWM故障检测输入信号滤波时间0us
 *          - PWM_WaveFilteringTime_1us:PWM故障检测输入信号滤波时间1us
 *          - PWM_WaveFilteringTime_4us:PWM故障检测输入信号滤波时间4us
 *          - PWM_WaveFilteringTime_16us:PWM故障检测输入信号滤波时间16us
 * @retval None
 */ 
void PWM_FaultDetectionModeConfigEX(PWM_Type_TypeDef PWM_Type,PWM_FaultDetectionMode_TypeDef FaultDetectionMode,
                                  PWM_FaultDetectionVoltageSelect_TypeDef FaultDetectionVoltageSelect,
                                  PWM_FaultDetectionWaveFilteringTime_TypeDef FaultDetectionWaveFilteringTime)
{
	if(PWM_Type == PWM0_Type)
  {
		PWMFLT = (PWMFLT & 0XC0) | FaultDetectionMode | FaultDetectionVoltageSelect |
           FaultDetectionWaveFilteringTime;
	}
}

/**
 * @brief  PWM互补模式占空比修改
 * @param  PWM_ComplementaryOutputPin[in]: 待修改的PWM互补通道
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @param  Change_Direction[in]:PWM修改方向
 *          - PWM_DutyChange_Up:PWM占空比增加
 *          - PWM_DutyChange_Dowm:PWM占空比减少
 * @param  DutyIncremental[in]: 修改的增量
 * @retval 返回修改成功状态位
 *          - ERROR:失败
 *          - SUCCESS:成功
 */ 
ErrorStatus PWM_ComplementaryMode_DutyChange(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
    PWM_DutyChange_TypeDef Change_Direction, uint16_t DutyIncremental)
{
  uint16_t tmpRegValue;
  uint16_t tmpRegAdress;
#if defined(SC92F5x5x)
	uint16_t tmpPolarity = (PWMPDL >> 6) + (PWMPDH << 2);
#else
  uint16_t tmpPolarity = PWMPDL + (PWMPDH << 8);
#endif
  /* PWM0的占空比寄存器地址 */
#if !defined(SC92F6x1x) && !defined(SC92F5x1x)&& !defined(SC92R436)&& !defined(SC92R438)&& !defined(SC92R439)&& !defined(SC92R422A)&& !defined(SC92F652x)&& !defined(SC92R51x_R52x) && !defined(SC92F552x)\
		&& !defined(SC92F5x5x) && !defined(SC92F531x) && !defined(SC92F663x) && !defined(SC92F563x)
  tmpRegAdress = PWMREG + 6 + PWM_ComplementaryOutputPin;
#elif  defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)|| defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)|| defined(SC92F652x)|| defined(SC92R51x_R52x) || defined (SC92F552x)
	if((PWM_ComplementaryOutputPin>=0)&&(PWM_ComplementaryOutputPin<=3))
	{
		tmpRegAdress = PWM0REG0_3 + PWM_ComplementaryOutputPin;
	}
	else
	{
		tmpRegAdress = PWM0REG4_7 +4-PWM_ComplementaryOutputPin;
	}
#elif  defined(SC92F5x5x) || defined(SC92F531x) || defined(SC92F663x) || defined(SC92F563x)
	tmpRegAdress = PWMREG + PWM_ComplementaryOutputPin;
#endif

  tmpRegValue = *(uint16_t xdata*)tmpRegAdress;
  if(Change_Direction == PWM_DutyChange_Up)
  {
    tmpRegValue += DutyIncremental;				//占空比增加
  }
  else
  {
    tmpRegValue -= DutyIncremental;				//占空比减少
  }
  /* 计数器发生了溢出 */
  if(tmpRegValue > tmpPolarity)
    return ERROR;
  *((uint16_t xdata*)tmpRegAdress) = tmpRegValue;		//占空比寄存器赋值
  return SUCCESS;
}
#endif

/**
 * @brief  PWM独立模式占空比修改
 * @param  PWM_OutputPin[in]: 待修改的PWM通道
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @param  Change_Direction[in]:PWM修改方向
 *          - PWM_DutyChange_Up:PWM占空比增加
 *          - PWM_DutyChange_Dowm:PWM占空比减少
 * @param  DutyIncremental[in]: 修改的增量
 * @retval 返回修改成功状态位
 *          - ERROR:失败
 *          - SUCCESS:成功
 */ 
ErrorStatus PWM_IndependentMode_DutyChange(PWM_OutputPin_TypeDef PWM_OutputPin,
    PWM_DutyChange_TypeDef Change_Direction, uint16_t DutyIncremental)
{
  uint16_t tmpRegValue;
  uint16_t tmpRegAdress;

#if defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)		
	uint16_t tmpPolarity = PWMPDL + (PWMPDH << 8);
  /* PWM0的输出通道 */
  if((PWM_OutputPin & 0xF0) == 0x00)
  {
    PWMCON0 &= ~0x02;			//配置为独立模式
    tmpRegAdress = PWMREG + 6 + PWM_OutputPin;
  }
  else		/* PWM2/3/4的占空比寄存器地址 */
  {
    tmpRegAdress = PWMREG + (PWM_OutputPin & 0x0F);
  }
#elif defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)
	uint16_t tmpPolarity;
	/* PWM0的输出通道 */
  if((PWM_OutputPin & 0xF0) == 0x00)
  {
		tmpPolarity = PWMPDL + (PWMPDH << 8);
    PWMCON0 &= ~0x02;			//配置为独立模式
    if((PWM_OutputPin>=0)&&(PWM_OutputPin<=3))
		{
			tmpRegAdress = PWM0REG0_3 + PWM_OutputPin;
		}
		else
		{
			tmpRegAdress = PWM0REG4_7 - PWM_OutputPin+4;
		}
  }
  else		/* PWM2/3/4的占空比寄存器地址 */
  {
		tmpPolarity = RCAPXL + (RCAPXH << 8);
    tmpRegAdress = PWMXREG + (PWM_OutputPin & 0x0F);
  }
#elif defined(SC92F663x) || defined(SC92F563x)
	uint16_t tmpPolarity;
	/* PWM0的输出通道 */
  if((PWM_OutputPin & 0xF0) == 0x00)
  {
		tmpPolarity = PWMPDL + (PWMPDH << 8);
    PWMCON0 &= ~0x02;			//配置为独立模式
		tmpRegAdress = PWMREG + PWM_OutputPin;
  }
  else		/* PWM2/3/4的占空比寄存器地址 */
  {
		tmpPolarity = RCAPXL + (RCAPXH << 8);
    tmpRegAdress = PWMXREG + (PWM_OutputPin & 0x0F);
  }
#elif defined(SC92F84Hx) || defined(SC92F83Hx) || defined(SC92F637x)
	uint16_t tmpPolarity;
	TXINX = (PWM_OutputPin & 0xF0) >> 4;
	tmpPolarity = RCAPXL + (RCAPXH << 8);
  tmpRegAdress = PWMREG + (PWM_OutputPin & 0x0F);
#elif defined(SC92F6x1x) || defined(SC92F5x1x) || defined(SC92R436)|| defined(SC92R438)|| defined(SC92R439)|| defined(SC92R422A)
	uint16_t tmpPolarity = PWMPDL + (PWMPDH << 8);
  /* PWM0的输出通道 */
  if((PWM_OutputPin & 0xF0) == 0x00)
  {
    PWMCON0 &= ~0x02;			//配置为独立模式
		if((PWM_OutputPin>=0)&&(PWM_OutputPin<=3))
		{
			tmpRegAdress = PWM0REG0_3 + PWM_OutputPin;
		}
		else
		{
			tmpRegAdress = PWM0REG4_7 - PWM_OutputPin+4;
		}
  
  }
  else		/* PWM2/3/4的占空比寄存器地址 */
  {
    tmpRegAdress = PWM2REG + (PWM_OutputPin & 0x0F);
  }
#elif defined(SC92F531x)
	uint16_t tmpPolarity = PWMPDL + (PWMPDH << 8);
  /* PWM0的输出通道 */
  if((PWM_OutputPin & 0xF0) == 0x00)
  {
    PWMCON0 &= ~0x02;			//配置为独立模式
		tmpRegAdress = PWMREG + PWM_OutputPin;
  }
  else		/* PWM2的占空比寄存器地址 */
  {
    tmpRegAdress = PWM2REG + (PWM_OutputPin & 0x0F);
  }
#elif defined(SC92F5x5x)
	uint16_t tmpPolarity = PWMPDL + (PWMPDH << 2);
  /* PWM0的输出通道 */
  if((PWM_OutputPin & 0xF0) == 0x00)
  {
    PWMCON0 &= ~0x02;			//配置为独立模式
		tmpRegAdress = PWMREG + PWM_OutputPin;
  }
  else		/* PWM2的占空比寄存器地址 */
  {
    tmpRegAdress = PWM2REG;
  }
#endif
	
  tmpRegValue = *((uint16_t xdata*)tmpRegAdress);
  if(Change_Direction == PWM_DutyChange_Up)
  {
    tmpRegValue += DutyIncremental;				//占空比增加
  }
  else
  {
    tmpRegValue -= DutyIncremental;				//占空比减少
  }
  /* 计数器发生了溢出 */
  if(tmpRegValue > tmpPolarity)
    return ERROR;
  *((uint16_t xdata*)tmpRegAdress) = tmpRegValue;		//占空比寄存器赋值
  return SUCCESS;
}

#if defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)|| defined(SC92F5x5x) || defined(SC92F531x) || defined(SC92F663x)
#if defined(SC92F652x) || defined(SC92R51x_R52x) || defined (SC92F552x)
uint8_t xdata SPOS_PWM21 _at_ 0x102C;
#elif defined(SC92F5x5x) || defined(SC92F531x)
uint8_t xdata SPOS_PWM21 _at_ 0x11C;
#endif

#if defined(SC92F663x)
/**
 * @brief  PWM0端口映射函数
 * @param  PWM0_MappingPin[in]: PWM映射管脚选择
 *          - PWM00Mapped_to_P45:PWM00映射到P45
 *          - PWM00Mapped_to_P44:PWM00映射到P44
 *          - PWM00Mapped_to_P42:PWM00映射到P42
 *          - PWM00Mapped_to_P41:PWM00映射到P41
 *          - PWM00Mapped_to_P37:PWM00映射到P37
 *          - PWM00Mapped_to_P36:PWM00映射到P36
 *          - PWM00Mapped_to_P35:PWM00映射到P35
 *          - PWM00Mapped_to_P34:PWM00映射到P34
 *          - PWM01Mapped_to_P05:PWM01映射到P05
 *          - PWM01Mapped_to_P06:PWM01映射到P06
 *          - PWM01Mapped_to_P50:PWM01映射到P50
 *          - PWM01Mapped_to_P51:PWM01映射到P51
 *          - PWM01Mapped_to_P52:PWM01映射到P52
 *          - PWM01Mapped_to_P53:PWM01映射到P53
 *          - PWM01Mapped_to_P00:PWM01映射到P00
 *          - PWM01Mapped_to_P01:PWM01映射到P01
 * @retval None
 */ 
void PWM0_PortMapping(PWM0_PortMappingPin_TypeDef PWM0_MappingPin)
{
	uint8_t *pSPOS_PWM0;
	pSPOS_PWM0 = (uint8_t *)0x102B;
	if((PWM0_MappingPin & 0xF0) == 0x00)
	{
		*pSPOS_PWM0 = (*pSPOS_PWM0 & 0xF8) | PWM0_MappingPin;
	}
	else
	{
		*pSPOS_PWM0 = (*pSPOS_PWM0 & 0xF8) | (PWM0_MappingPin<<4);
	}
}

/**
 * @brief  PWM20端口映射函数
 * @param  PWM20_MappingPin[in]: PWM映射管脚选择
 *          - PWM20Mapped_to_P51:PWM20映射到P51
 *          - PWM20Mapped_to_P44:PWM20映射到P44
 *          - PWM20Mapped_to_P43:PWM20映射到P43
 *          - PWM20Mapped_to_P42:PWM20映射到P42
 *          - PWM20Mapped_to_P41:PWM20映射到P41
 *          - PWM20Mapped_to_P40:PWM20映射到P40
 *          - PWM20Mapped_to_P37:PWM20映射到P37
 *          - PWM20Mapped_to_P36:PWM20映射到P36
 * @retval None
 */ 
void PWM20_PortMapping(PWM20_PortMappingPin_TypeDef PWM20_MappingPin)
{
	uint8_t *pSPOS_T2;
	pSPOS_T2 = (uint8_t *)0x1029;
	*pSPOS_T2 = (*pSPOS_T2 & 0xF8) | PWM20_MappingPin;
}

/**
 * @brief  PWMX1端口映射函数
 * @param  PWMX1_MappingPin[in]: PWM映射管脚选择
 *          - PWM21Mapped_to_P45:PWM21映射到P45
 *          - PWM21Mapped_to_P44:PWM21映射到P44
 *          - PWM21Mapped_to_P42:PWM21映射到P42
 *          - PWM21Mapped_to_P41:PWM21映射到P41
 *          - PWM21Mapped_to_P37:PWM21映射到P37
 *          - PWM21Mapped_to_P36:PWM21映射到P36
 *          - PWM21Mapped_to_P35:PWM21映射到P35
 *          - PWM21Mapped_to_P34:PWM21映射到P34
 *          - PWM21Mapped_to_P33:PWM21映射到P33
 *          - PWM21Mapped_to_P32:PWM21映射到P32
 *          - PWM21Mapped_to_P31:PWM21映射到P31
 *          - PWM21Mapped_to_P30:PWM21映射到P30
 *          - PWM31Mapped_to_P02:PWM31映射到P02
 *          - PWM31Mapped_to_P03:PWM31映射到P03
 *          - PWM31Mapped_to_P04:PWM31映射到P04
 *          - PWM31Mapped_to_P05:PWM31映射到P05
 *          - PWM31Mapped_to_P06:PWM31映射到P06
 *          - PWM31Mapped_to_P50:PWM31映射到P50
 *          - PWM31Mapped_to_P51:PWM31映射到P51
 *          - PWM31Mapped_to_P52:PWM31映射到P52
 *          - PWM31Mapped_to_P53:PWM31映射到P53
 *          - PWM31Mapped_to_P26:PWM31映射到P26
 *          - PWM31Mapped_to_P27:PWM31映射到P27
 *          - PWM31Mapped_to_P00:PWM31映射到P00
 *          - PWM31Mapped_to_P01:PWM31映射到P01
 * @retval None
 */ 
void PWMX1_PortMapping(PWMX1_PortMappingPin_TypeDef PWMX1_MappingPin)
{
	uint8_t *pSPOS_TEX;
	pSPOS_TEX = (uint8_t *)0x102A;
	if((PWMX1_MappingPin & 0xF0) == 0x00)
	{
		*pSPOS_TEX = (*pSPOS_TEX & 0xF0) | PWMX1_MappingPin;
	}
	else
	{
		*pSPOS_TEX = (*pSPOS_TEX & 0x0F) | (PWMX1_MappingPin<<4);
	}
}
#else
/**
 * @brief  PWM21端口映射函数
 * @param  PWM21_MappingPin[in]: PWM映射管脚选择
 *          - Mapped_to_P50:PWM21映射到P50
 *          - Mapped_to_P51:PWM21映射到P51
 *          - Mapped_to_P52:PWM21映射到P52
 *          - Mapped_to_P53:PWM21映射到P53
 *          - Mapped_to_P54:PWM21映射到P54
 *          - Mapped_to_P56:PWM21映射到P56
 *          - Mapped_to_P57:PWM21映射到P57
 *          - Mapped_to_P10:PWM21映射到P10
 *          - Mapped_to_P11:PWM21映射到P11
 *          - Mapped_to_P12:PWM21映射到P12
 *          - Mapped_to_P13:PWM21映射到P13
 *          - Mapped_to_P14:PWM21映射到P14
 *          - Mapped_to_P15:PWM21映射到P15
 *          - Mapped_to_P16:PWM21映射到P16
 *          - Mapped_to_P17:PWM21映射到P17
 *          - Mapped_to_P27:PWM21映射到P27
 *          - Mapped_to_P26:PWM21映射到P26
 *          - Mapped_to_P25:PWM21映射到P25
 *          - Mapped_to_P24:PWM21映射到P24
 *          - Mapped_to_P23:PWM21映射到P23
 *          - Mapped_to_P22:PWM21映射到P22
 *          - Mapped_to_P21:PWM21映射到P21
 *          - Mapped_to_P20:PWM21映射到P20
 *          - Mapped_to_P07:PWM21映射到P07
 *          - Mapped_to_P06:PWM21映射到P06
 *          - Mapped_to_P05:PWM21映射到P05
 *          - Mapped_to_P04:PWM21映射到P04
 *          - Mapped_to_P03:PWM21映射到P03
 *          - Mapped_to_P02:PWM21映射到P02
 *          - Mapped_to_P01:PWM21映射到P01
 *          - Mapped_to_P00:PWM21映射到P00
 * @retval None
 */ 
void PWM21_PortMapping(PWM21_PortMappingPin_TypeDef PWM21_MappingPin)
{
	SPOS_PWM21 = SPOS_PWM21 & 0xE0 | PWM21_MappingPin;
}
#endif
#endif

#endif

#if defined (SC92F846xB) || defined (SC92F746xB) || defined (SC92F836xB) || defined (SC92F736xB) || defined (SC92F83Ax) || defined (SC92F73Ax)\
		|| defined (SC92F84Ax) || defined (SC92F74Ax) || defined (SC92F848x) || defined (SC92F748x) || defined (SC92R342)\
		|| defined (SC92F841x)|| defined (SC92F741x) || defined (SC92Fx41xB)||defined(SC92R445) 
/**
 * @brief  PWM相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void PWM_DeInit(void)
{
  PWMCFG = 0X00;
  PWMCON = 0X00;
  PWMPRD = 0X00;
  PWMDTYA = 0X00;
  PWMDTY0 = 0X00;
  PWMDTY1 = 0X00;
  PWMDTY2 = 0X00;
  PWMDTYB = 0X00;
  PWMDTY3 = 0X00;
  PWMDTY4 = 0X00;
  PWMDTY5 = 0X00;
  IE1 &= ~0X02;
  IP1 &= ~0X02;
}

/**
 * @brief  PWM初始化配置函数
 * @param  PWM_PresSel[in]:预分频选择
 *          - PWM0_PRESSEL_FOSC_D1:PWM0预分频为Fosc/1
 *          - PWM0_PRESSEL_FOSC_D2:PWM0预分频为Fosc/2
 *          - PWM0_PRESSEL_FOSC_D4:PWM0预分频为Fosc/4
 *          - PWM0_PRESSEL_FOSC_D8:PWM0预分频为Fosc/8
 * @param  PWM_Period:PWM周期配置
 * @retval None
 */ 
void PWM_Init(PWM_PresSel_TypeDef PWM_PresSel,
              uint16_t PWM_Period)
{
  PWM_Period -= 1;
  PWMCFG  = (PWMCFG & 0X3F) | (PWM_PresSel << 6);					//预分频
  PWMDTYA = (PWMDTYA & 0X3F) | ((uint8_t)(PWM_Period % 4) << 6);	//周期低两位
  PWMPRD  = (uint8_t)(PWM_Period >> 2);							//周期高八位
}

/**
 * @brief  PWMx输出使能/失能配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 * @param  PWM_OutputState[in]:PWM输出状态配置
 *          - PWM_OUTPUTSTATE_DISABLE:该PIN脚作为GPIO
 *          - PWM_OUTPUTSTATE_ENABLE:该PIN脚作为PWM
 * @retval None
 */ 
void PWM_OutputStateConfig(uint8_t PWM_OutputPin,
                           PWM_OutputState_TypeDef PWM_OutputState)
{
  if(PWM_OutputState == PWM_OUTPUTSTATE_ENABLE)
  {
    PWMCON |= PWM_OutputPin;
  }
  else
  {
    PWMCON &= (~PWM_OutputPin);
  }
}

/**
 * @brief  PWMx正/反向输出配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 * @param  PWM_Polarity[in]:PWM输出状态配置
 *          - PWM_POLARITY_NON_INVERT:PWM输出不反向
 *          - PWM_POLARITY_INVERT:PWM输出反向
 * @retval None
 */ 
void PWM_PolarityConfig(uint8_t PWM_OutputPin,
                        PWM_Polarity_TypeDef PWM_Polarity)
{
  if(PWM_Polarity == PWM_POLARITY_INVERT)
  {
    PWMCFG |= PWM_OutputPin;
  }
  else
  {
    PWMCFG &= (~PWM_OutputPin);
  }
}

/**
 * @brief  PWMx独立工作模式配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  PWM_DutyCycle[in]:PWM占空比配置
 * @retval None
 */ 
void PWM_IndependentModeConfig(PWM_OutputPin_TypeDef PWM_OutputPin,
                               uint16_t PWM_DutyCycle)
{
  PWMDTYB &= 0X7F;		//设置PWM为独立模式

  switch(PWM_OutputPin)	//设置占空比
  {
    case PWM0:
      PWMDTYA = PWMDTYA & 0xfc | (PWM_DutyCycle % 4);
      PWMDTY0 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    case PWM1:
      PWMDTYA = PWMDTYA & 0xf3 | ((PWM_DutyCycle % 4) <<
                                  2);
      PWMDTY1 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    case PWM2:
      PWMDTYA = PWMDTYA & 0xcf | ((PWM_DutyCycle % 4) <<
                                  4);
      PWMDTY2 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    case PWM3:
      PWMDTYB = PWMDTYB & 0xfc | (PWM_DutyCycle % 4);
      PWMDTY3 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    case PWM4:
      PWMDTYB = PWMDTYB & 0xf3 | ((PWM_DutyCycle % 4) <<
                                  2);
      PWMDTY4 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    case PWM5:
      PWMDTYB = PWMDTYB & 0xcf | ((PWM_DutyCycle % 4) <<
                                  4);
      PWMDTY5 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    default:
      break;
  }
}

/**
 * @brief  PWM独立模式占空比修改
 * @param  PWM_OutputPin[in]:待修改的PWM独立通道
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  Change_Direction[in]:PWM修改方向
 *          - PWM_DutyChange_Up:PWM占空比增加
 *          - PWM_DutyChange_Dowm:PWM占空比减少
 * @param  DutyIncremental[in]:修改的增量
 * @retval 返回修改成功状态位
 *          - ERROR:失败
 *          - SUCCESS:成功
 */ 
ErrorStatus PWM_IndependentMode_DutyChange(PWM_OutputPin_TypeDef PWM_OutputPin,
    PWM_DutyChange_TypeDef Change_Direction,
    uint16_t DutyIncremental)
{
  uint16_t tmpRegValue;
  uint16_t tmpPolarity = (((PWMDTYA & ~0x3f) >> 6) | (PWMPRD << 2));
	int16_t DutychangeValue = 0;
  ErrorStatus Result = ERROR;

	if(Change_Direction == PWM_DutyChange_Up)
  {
    DutychangeValue += DutyIncremental;				//占空比增加
  }
  else
  {
    DutychangeValue -= DutyIncremental;				//占空比减少
  }
	
  switch(PWM_OutputPin)	//设置占空比
  {
    case PWM0:
      tmpRegValue = ((PWMDTYA & 0xfc) | (PWMDTY0 << 2)); //读取原来的占空比
		  tmpRegValue += DutychangeValue; //设置新的占空比
		 
      if(tmpRegValue <= tmpPolarity)  //计数器没有发生溢出
			{
				PWMDTYA = PWMDTYA & 0xfc | (tmpRegValue % 4);
        PWMDTY0 = (uint8_t)(tmpRegValue >> 2);
			  Result = SUCCESS;				
			}
      break;

    case PWM1:
      tmpRegValue = (((PWMDTYA & 0xf3) >> 2) | (PWMDTY1 << 2));
		  tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  //计数器没有发生溢出
			{
				PWMDTYA = PWMDTYA & 0xf3 | ((tmpRegValue % 4) << 2);
        PWMDTY1 = (uint8_t)(tmpRegValue >> 2);
			  Result = SUCCESS;				
			}
      break;

    case PWM2:
      tmpRegValue = (((PWMDTYA & 0xcf) >> 4) | (PWMDTY2 << 2));
		  tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  //计数器没有发生溢出
			{
				PWMDTYA = PWMDTYA & 0xcf | ((tmpRegValue % 4) << 4);
        PWMDTY2 = (uint8_t)(tmpRegValue >> 2);
			  Result = SUCCESS;				
			}
      break;

    case PWM3:
      tmpRegValue = (((PWMDTYB & 0xfc)) | (PWMDTY3 << 2));
		  tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  //计数器没有发生溢出
			{
				PWMDTYB = PWMDTYB & 0xfc | (tmpRegValue % 4);
        PWMDTY3 = (uint8_t)(tmpRegValue >> 2);
			  Result = SUCCESS;				
			}
      break;

    case PWM4:
      tmpRegValue = (((PWMDTYB & 0xf3) >> 2) | (PWMDTY4 << 2));
		  tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  //计数器没有发生溢出
			{
				PWMDTYB = PWMDTYB & 0xf3 | ((tmpRegValue % 4) << 2);
        PWMDTY4 = (uint8_t)(tmpRegValue >> 2);
			  Result = SUCCESS;				
			}		
      break;

    case PWM5:
      tmpRegValue = (((PWMDTYB & 0xcf) >> 4) | (PWMDTY5 << 2));
		  tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  //计数器没有发生溢出
			{
				PWMDTYB = PWMDTYB & 0xcf | ((tmpRegValue % 4) << 4);
        PWMDTY5 = (uint8_t)(tmpRegValue >> 2);
			  Result = SUCCESS;				
			}		
      break;

    default:
      break;
  }
  return Result;
}

/**
 * @brief  PWMxPWMy互补工作模式配置函数
 * @param  PWM_ComplementaryOutputPin[in]:PWMxPWMy互补通道选择
 *          - PWM0PWM3:PWM输出通道选择:PWM互补模式通道选择:PWM0、PWM3
 *          - PWM1PWM4:PWM输出通道选择:PWM互补模式通道选择:PWM1、PWM4
 *          - PWM2PWM5:PWM输出通道选择:PWM互补模式通道选择:PWM2、PWM5
 * @param  PWM_DutyCycle[in]: PWM占空比配置
 * @retval None
 */ 
void PWM_ComplementaryModeConfig(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
                                 uint16_t PWM_DutyCycle)
{
  PWMDTYB |= 0X80;					//设置PWM为互补模式

  switch(PWM_ComplementaryOutputPin)	//设置占空比
  {
    case PWM0PWM3:
      PWMDTYA = PWMDTYA & 0xfc | (PWM_DutyCycle % 4);
      PWMDTY0 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    case PWM1PWM4:
      PWMDTYA = PWMDTYA & 0xf3 | ((PWM_DutyCycle % 4) <<
                                  2);
      PWMDTY1 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    case PWM2PWM5:
      PWMDTYA = PWMDTYA & 0xcf | ((PWM_DutyCycle % 4) <<
                                  4);
      PWMDTY2 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    default:
      break;
  }
}

/**
 * @brief  PWM互补模式占空比修改
 * @param  PWM_ComplementaryOutputPin[in]: 待修改的PWM互补通道
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @param  Change_Direction[in]:PWM修改方向
 *          - PWM_DutyChange_Up:PWM占空比增加
 *          - PWM_DutyChange_Dowm:PWM占空比减少
 * @param  DutyIncremental[in]: 修改的增量
 * @retval 返回修改成功状态位
 *          - ERROR:失败
 *          - SUCCESS:成功
 */ 
ErrorStatus PWM_ComplementaryMode_DutyChange(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
    PWM_DutyChange_TypeDef Change_Direction,
    uint16_t DutyIncremental)
{
  uint16_t tmpRegValue;
  uint16_t tmpPolarity = (((PWMDTYA & ~0x3f) >> 6) | (PWMPRD << 2));

  switch(PWM_ComplementaryOutputPin)	//设置占空比
  {
    case PWM0PWM3:
      tmpRegValue = ((PWMDTYA & 0xfc) | (PWMDTY0 << 2));
      break;

    case PWM1PWM4:
      tmpRegValue = (((PWMDTYA & 0xf3) >> 2) | (PWMDTY1 << 2));
      break;

    case PWM2PWM5:
      tmpRegValue = (((PWMDTYA & 0xcf) >> 4) | (PWMDTY2 << 2));
      break;

    default:
      break;
  }

  if(Change_Direction == PWM_DutyChange_Up)
  {
    tmpRegValue += DutyIncremental;				//占空比增加
  }
  else
  {
    tmpRegValue -= DutyIncremental;				//占空比减少
  }

  /* 计数器发生了溢出 */
  if(tmpRegValue > tmpPolarity)
    return ERROR;

  switch(PWM_ComplementaryOutputPin)	//设置占空比
  {
    case PWM0PWM3:
      PWMDTYA = PWMDTYA & 0xfc | (tmpRegValue % 4);
      PWMDTY0 = (uint8_t)(tmpRegValue >> 2);
      break;

    case PWM1PWM4:
      PWMDTYA = PWMDTYA & 0xf3 | ((tmpRegValue % 4) << 2);
      PWMDTY1 = (uint8_t)(tmpRegValue >> 2);
      break;

    case PWM2PWM5:
      PWMDTYA = PWMDTYA & 0xcf | ((tmpRegValue % 4) << 4);
      PWMDTY2 = (uint8_t)(tmpRegValue >> 2);
      break;

    default:
      break;
  }
  return SUCCESS;
}

/**
 * @brief  PWM互补工作模式下死区时间配置函数
 * @param  PWM012_RisingDeadTime[in]:PWM死区上升时间
 * @param  PWM345_fallingDeadTime[in]:PWM死区下降时间
 * @retval None
 */
void PWM_DeadTimeConfig(uint8_t PWM012_RisingDeadTime,
                        uint8_t PWM345_fallingDeadTime)
{
  PWMDTY3 = (PWM012_RisingDeadTime |
             (PWM345_fallingDeadTime << 4));
}

/**
 * @brief  PWM功能开关函数
 * @param  NewState[in]: 功能启动/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @retval None
 */ 
void PWM_Cmd(FunctionalState NewState)
{
  if(NewState != DISABLE)
  {
    PWMCON |= 0X80;
  }
  else
  {
    PWMCON &= ~0X80;
  }
}

/**
 * @brief  PWM中断初始化
 * @param  NewState[in]: 中断使能/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @param  Priority[in]: 中断优先级选择
 *          - LOW:低
 *          - HIGH:高
 * @retval None
 */ 
void PWM_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority)
{
  if(NewState != DISABLE)
  {
    IE1 |= 0X02;
  }
  else
  {
    IE1 &= 0XFD;
  }

  if(Priority == LOW)
  {
    IP1 &= 0XFD;
  }
  else
  {
    IP1 |= 0X02;
  }
}

/**
 * @brief  获得PWM中断标志状态
 * @param  None
 * @retval PWM中断标志状态
 *              - RESET:置零
 *              - SET:置起
 */
FlagStatus PWM_GetFlagStatus(void)
{
  return (bool)(PWMCON & 0X40);
}

/**
 * @brief  清除PWM中断标志状态
 * @param  None
 * @retval None
 */
void PWM_ClearFlag(void)
{
  PWMCON &= 0XBF;
}
#endif

#if defined (SC92F7003) || defined (SC92F8003) || defined(SC92F8003B) || defined (SC92F740x)
/**
 * @brief  PWM相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */
void PWM_DeInit(void)
{
  PWMCFG = 0X00;
  PWMCON0 = 0X00;
  PWMPRD = 0X00;
  PWMDTYA = 0X00;
  PWMDTY0 = 0X00;
  PWMDTY1 = 0X00;
  PWMDTY2 = 0X00;
  PWMCON1 = 0X00;
  PWMDTYB = 0X00;
  PWMDTY3 = 0X00;
  PWMDTY4 = 0X00;
  PWMDTY5 = 0X00;
  PWMDTY6 = 0X00;
  IE1 &= 0XFD;
  IP1 &= 0XFD;
}

/**
 * @brief  PWM初始化配置函数
 * @param  PWM_PresSel[in]:预分频选择
 *          - PWM0_PRESSEL_FOSC_D1:PWM0预分频为Fosc/1
 *          - PWM0_PRESSEL_FOSC_D2:PWM0预分频为Fosc/2
 *          - PWM0_PRESSEL_FOSC_D4:PWM0预分频为Fosc/4
 *          - PWM0_PRESSEL_FOSC_D8:PWM0预分频为Fosc/8
 * @param  PWM_Period:PWM周期配置
 * @retval None
 */ 
void PWM_Init(PWM_PresSel_TypeDef PWM_PresSel,
              uint16_t PWM_Period)
{
  PWM_Period -= 1;
  PWMCON0 = (PWMCON0 & 0XCC) | PWM_PresSel |
            (uint8_t)(PWM_Period &
                      0X0003);	//预分频及周期的低2位
  PWMPRD = (uint8_t)(PWM_Period >>
                     2);									    //周期高八位
}

/**
 * @brief  PWMx正/反向输出配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 * @param  PWM_Polarity[in]:PWM输出状态配置
 *          - PWM_POLARITY_NON_INVERT:PWM输出不反向
 *          - PWM_POLARITY_INVERT:PWM输出反向
 * @retval None
 */ 
void PWM_OutputStateConfig(uint8_t PWM_OutputPin,
                           PWM_OutputState_TypeDef PWM_OutputState)
{
  if(PWM_OutputState == PWM_OUTPUTSTATE_ENABLE)
  {
    PWMCON1 |= PWM_OutputPin;
  }
  else
  {
    PWMCON1 &= (~PWM_OutputPin);
  }
}

/**
 * @brief  PWM2管脚选择函数
 * @param  PWM2_OutputPin[in]:PWM2管脚选择函数
 *          - PWM2_OutputPin_P26:PWM2输出口选择P26
 *          - PWM2_OutputPin_P14:PWM2输出口选择P14
 * @retval None
 */ 
void PWM_PWM2Selection(PWM2_OutputPin_TypeDef
                       PWM2_OutputPin)
{
  PWMCON0 = PWMCON0 & 0XFB | PWM2_OutputPin;
}

/**
 * @brief  PWM5管脚选择函数
 * @param  PWM5_OutputPin[in]:PWM5管脚选择函数
 *          - PWM5_OutputPin_P12:PWM2输出口选择P12
 *          - PWM5_OutputPin_P21:PWM2输出口选择P21
 * @retval None
 */ 
void PWM_PWM5Selection(PWM5_OutputPin_TypeDef
                       PWM5_OutputPin)
{
  PWMCON0 = PWMCON0 & 0XF7 | PWM5_OutputPin;
}

/**
 * @brief  PWMx正/反向输出配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 * @param  PWM_Polarity[in]: PWM输出正/反向配置
 *              - PWM_POLARITY_NON_INVERT:PWM输出不反向
 *              - PWM_POLARITY_INVERT:PWM输出反向
 * @retval None
 */ 
void PWM_PolarityConfig(uint8_t PWM_OutputPin,
                        PWM_Polarity_TypeDef PWM_Polarity)
{
  if(PWM_Polarity == PWM_POLARITY_INVERT)
  {
    PWMCFG |= PWM_OutputPin;
  }
  else
  {
    PWMCFG &= (~PWM_OutputPin);
  }
}

/**
 * @brief  PWMx独立工作模式配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  PWM_DutyCycle[in]: PWM占空比配置
 * @retval None
 */
void PWM_IndependentModeConfig(PWM_OutputPin_TypeDef PWM_OutputPin,
                               uint16_t PWM_DutyCycle)
{
  if(PWM_OutputPin != PWM6)
  {
    PWMCON1 &= 0X7F;		//设置PWM为独立模式
  }

  switch(PWM_OutputPin)	//设置占空比
  {
    case PWM0:
      PWMDTYA = PWMDTYA & 0XFC | (PWM_DutyCycle % 4);
      PWMDTY0 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    case PWM1:
      PWMDTYA = PWMDTYA & 0XF3 | ((PWM_DutyCycle % 4) <<
                                  2);
      PWMDTY1 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    case PWM2:
      PWMDTYA = PWMDTYA & 0XCF | ((PWM_DutyCycle % 4) <<
                                  4);
      PWMDTY2 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    case PWM3:
      PWMDTYA = PWMDTYA & 0X3F | ((PWM_DutyCycle % 4) <<
                                  6);
      PWMDTY3 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    case PWM4:
      PWMDTYB = PWMDTYB & 0XFC | (PWM_DutyCycle % 4);
      PWMDTY4 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    case PWM5:
      PWMDTYB = PWMDTYB & 0XF3 | ((PWM_DutyCycle % 4) <<
                                  2);
      PWMDTY5 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    case PWM6:
      PWMDTYB = PWMDTYB & 0XCF | ((PWM_DutyCycle % 4) <<
                                  4);
      PWMDTY6 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    default:
      break;
  }
}

/**
 * @brief  PWM独立模式占空比修改
 * @param  PWM_OutputPin[in]:待修改的PWM独立通道
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  Change_Direction[in]:PWM修改方向
 *          - PWM_DutyChange_Up:PWM占空比增加
 *          - PWM_DutyChange_Dowm:PWM占空比减少
 * @param  DutyIncremental[in]:修改的增量
 * @retval 返回修改成功状态位
 *          - ERROR:失败
 *          - SUCCESS:成功
 */ 
ErrorStatus PWM_IndependentMode_DutyChange(PWM_OutputPin_TypeDef PWM_OutputPin,
    PWM_DutyChange_TypeDef Change_Direction,
    uint16_t DutyIncremental)
{
  uint16_t tmpRegValue;
  uint16_t tmpPolarity = ((PWMCON0 & 0x03) | (PWMPRD << 2));
	int16_t DutychangeValue = 0;
  ErrorStatus Result = ERROR;

	if(Change_Direction == PWM_DutyChange_Up)
  {
    DutychangeValue += DutyIncremental;				//占空比增加
  }
  else
  {
    DutychangeValue -= DutyIncremental;				//占空比减少
  }
	
  switch(PWM_OutputPin)	//设置占空比
  {
    case PWM0:
      tmpRegValue = ((PWMDTYA & 0xfc) | (PWMDTY0 << 2));
		  tmpRegValue += DutychangeValue; //设置新的占空比
		 
      if(tmpRegValue <= tmpPolarity)  //计数器没有发生溢出
			{
			 	PWMDTYA = PWMDTYA & 0xfc | (tmpRegValue % 4);
        PWMDTY0 = (uint8_t)(tmpRegValue >> 2);
			  Result = SUCCESS;				
			}
      break;

    case PWM1:
      tmpRegValue = (((PWMDTYA & 0xf3) >> 2) | (PWMDTY1 << 2));
		  tmpRegValue += DutychangeValue; //设置新的占空比
		 
      if(tmpRegValue <= tmpPolarity)  //计数器没有发生溢出
			{
			 	PWMDTYA = PWMDTYA & 0xf3 | ((tmpRegValue % 4) << 2);
        PWMDTY1 = (uint8_t)(tmpRegValue >> 2);
			  Result = SUCCESS;				
			}
      break;

    case PWM2:
      tmpRegValue = (((PWMDTYA & 0xcf) >> 4) | (PWMDTY2 << 2));
		  tmpRegValue += DutychangeValue; //设置新的占空比
		 
      if(tmpRegValue <= tmpPolarity)  //计数器没有发生溢出
			{
			 	PWMDTYA = PWMDTYA & 0xcf | ((tmpRegValue % 4) << 4);
        PWMDTY2 = (uint8_t)(tmpRegValue >> 2);
			  Result = SUCCESS;				
			}
      break;

    case PWM3:
      tmpRegValue = (((PWMDTYA & 0x3f) >> 6) | (PWMDTY3 << 2));
		  tmpRegValue += DutychangeValue; //设置新的占空比
		 
      if(tmpRegValue <= tmpPolarity)  //计数器没有发生溢出
			{
			 	PWMDTYA = PWMDTYA & 0x3f | ((tmpRegValue % 4) << 6);
        PWMDTY3 = (uint8_t)(tmpRegValue >> 2);
			  Result = SUCCESS;				
			} 
      break;

    case PWM4:
      tmpRegValue = (((PWMDTYB & 0xfc)) | (PWMDTY4 << 2));
		  tmpRegValue += DutychangeValue; //设置新的占空比
		 
      if(tmpRegValue <= tmpPolarity)  //计数器没有发生溢出
			{
			 	PWMDTYB = PWMDTYB & 0xfc | (tmpRegValue % 4);
        PWMDTY4 = (uint8_t)(tmpRegValue >> 2);
			  Result = SUCCESS;				
			} 
      break;

    case PWM5:
      tmpRegValue = (((PWMDTYB & 0xf3) >> 2) | (PWMDTY5 << 2));
		  tmpRegValue += DutychangeValue; //设置新的占空比
		 
      if(tmpRegValue <= tmpPolarity)  //计数器没有发生溢出
			{
			 	PWMDTYB = PWMDTYB & 0xf3 | ((tmpRegValue % 4) << 2);
        PWMDTY5 = (uint8_t)(tmpRegValue >> 2);
			  Result = SUCCESS;				
			} 
      break;

    case PWM6:
      tmpRegValue = (((PWMDTYB & 0xcf) >> 4) | (PWMDTY6 << 2));
	  	tmpRegValue += DutychangeValue; //设置新的占空比
		 
      if(tmpRegValue <= tmpPolarity)  //计数器没有发生溢出
			{
			  PWMDTYB = PWMDTYB & 0xcf | ((tmpRegValue % 4) << 4);
        PWMDTY6 = (uint8_t)(tmpRegValue >> 2);
			  Result = SUCCESS;				
			} 
      break;

    default:
      break;
  }
  return Result;
}

/**
 * @brief  PWMxPWMy互补工作模式配置函数
 * @param  PWM_ComplementaryOutputPin[in]:PWMxPWMy互补通道选择
 *          - PWM0PWM3:PWM输出通道选择:PWM互补模式通道选择:PWM0、PWM3
 *          - PWM1PWM4:PWM输出通道选择:PWM互补模式通道选择:PWM1、PWM4
 *          - PWM2PWM5:PWM输出通道选择:PWM互补模式通道选择:PWM2、PWM5
 * @param  PWM_DutyCycle[in]: PWM占空比配置
 * @retval None
 */
void PWM_ComplementaryModeConfig(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
                                 uint16_t PWM_DutyCycle)
{
  PWMCON1 |= 0X80;					//设置PWM为互补模式

  switch(PWM_ComplementaryOutputPin)	//设置占空比
  {
    case PWM0PWM3:
      PWMDTYA = PWMDTYA & 0XFC | (PWM_DutyCycle % 4);
      PWMDTY0 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    case PWM1PWM4:
      PWMDTYA = PWMDTYA & 0XF3 | ((PWM_DutyCycle % 4) <<
                                  2);
      PWMDTY1 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    case PWM2PWM5:
      PWMDTYA = PWMDTYA & 0XCF | ((PWM_DutyCycle % 4) <<
                                  4);
      PWMDTY2 = (uint8_t)(PWM_DutyCycle >> 2);
      break;

    default:
      break;
  }
}

/**
 * @brief  PWM互补模式占空比修改
 * @param  PWM_ComplementaryOutputPin[in]: 待修改的PWM互补通道
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @param  Change_Direction[in]:PWM修改方向
 *          - PWM_DutyChange_Up:PWM占空比增加
 *          - PWM_DutyChange_Dowm:PWM占空比减少
 * @param  DutyIncremental[in]: 修改的增量
 * @retval 返回修改成功状态位
 *          - ERROR:失败
 *          - SUCCESS:成功
 */ 
ErrorStatus PWM_ComplementaryMode_DutyChange(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
    PWM_DutyChange_TypeDef Change_Direction,
    uint16_t DutyIncremental)
{
  uint16_t tmpRegValue;
  uint16_t tmpPolarity = ((PWMCON0 & 0x03) | (PWMPRD << 2));

  switch(PWM_ComplementaryOutputPin)	//设置占空比
  {
    case PWM0PWM3:
      tmpRegValue = ((PWMDTYA & 0xfc) | (PWMDTY0 << 2));
      break;

    case PWM1PWM4:
      tmpRegValue = (((PWMDTYA & 0xf3) >> 2) | (PWMDTY1 << 2));
      break;

    case PWM2PWM5:
      tmpRegValue = (((PWMDTYA & 0xcf) >> 4) | (PWMDTY2 << 2));
      break;

    default:
      break;
  }

  if(Change_Direction == PWM_DutyChange_Up)
  {
    tmpRegValue += DutyIncremental;				//占空比增加
  }
  else
  {
    tmpRegValue -= DutyIncremental;				//占空比减少
  }

  /* 计数器发生了溢出 */
  if(tmpRegValue > tmpPolarity)
    return ERROR;

  switch(PWM_ComplementaryOutputPin)	//设置占空比
  {
    case PWM0PWM3:
      PWMDTYA = PWMDTYA & 0xfc | (tmpRegValue % 4);
      PWMDTY0 = (uint8_t)(tmpRegValue >> 2);
      break;

    case PWM1PWM4:
      PWMDTYA = PWMDTYA & 0xf3 | ((tmpRegValue % 4) << 2);
      PWMDTY1 = (uint8_t)(tmpRegValue >> 2);
      break;

    case PWM2PWM5:
      PWMDTYA = PWMDTYA & 0xcf | ((tmpRegValue % 4) << 4);
      PWMDTY2 = (uint8_t)(tmpRegValue >> 2);
      break;

    default:
      break;
  }
  return SUCCESS;
}

/**
 * @brief  PWM互补工作模式下死区时间配置函数
 * @param  PWM012_RisingDeadTime[in]:PWM死区上升时间
 * @param  PWM345_fallingDeadTime[in]:PWM死区下降时间
 * @retval None
 */
void PWM_DeadTimeConfig(uint8_t
                        PWM012_RisingDeadTime,
                        uint8_t PWM345_fallingDeadTime)
{
  PWMDTY3 = (PWM012_RisingDeadTime |
             (PWM345_fallingDeadTime << 4));
}

/**
 * @brief  PWM功能开关函数
 * @param  NewState[in]: 功能启动/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @retval None
 */ 
void PWM_Cmd(FunctionalState NewState)
{
  if(NewState != DISABLE)
  {
    PWMCON0 |= 0X80;
  }
  else
  {
    PWMCON0 &= ~0X80;
  }
}

/**
 * @brief  PWM中断初始化
 * @param  NewState[in]: 中断使能/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @param  Priority[in]: 中断优先级选择
 *          - LOW:低
 *          - HIGH:高
 * @retval None
 */ 
void PWM_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority)
{
  if(NewState != DISABLE)
  {
    IE1 |= 0X02;
  }
  else
  {
    IE1 &= 0XFD;
  }

  if(Priority == LOW)
  {
    IP1 &= 0XFD;
  }
  else
  {
    IP1 |= 0X02;
  }
}

/**
 * @brief  获得PWM中断标志状态
 * @param  None
 * @retval PWM中断标志状态
 *              - RESET:置零
 *              - SET:置起
 */
FlagStatus PWM_GetFlagStatus(void)
{
  return (bool)(PWMCON0 & 0X40);
}

/**
 * @brief  清除PWM中断标志状态
 * @param  None
 * @retval None
 */
void PWM_ClearFlag(void)
{
  PWMCON0 &= 0XBF;
}
#endif

#if defined (SC92F742x) || defined (SC92F730x) || defined (SC92F725X) || defined(SC92F735X) || defined(SC92F730x_2) || defined(SC92F720x) ||defined(SC92F7308B)
/**
 * @brief  PWM相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */
void PWM_DeInit(void)
{
  PWMCFG0 = 0X00;
  PWMCON  = 0X00;
  PWMPRD  = 0X00;
  PWMCFG1 = 0X00;
  PWMDTY0 = 0X00;
  PWMDTY1 = 0X00;
  PWMDTY2 = 0X00;
#if !defined (SC92F730x) &&! defined(SC92F7308B)
  PWMDTY3 = 0X00;
#endif
  PWMDTY4 = 0X00;
  PWMDTY5 = 0X00;
  IE1 &= ~0X02;
  IP1 &= ~0X02;
}

/**
 * @brief  PWM初始化配置函数
 * @param  PWM_PresSel[in]:预分频选择
 *          - PWM0_PRESSEL_FOSC_D1:PWM0预分频为Fosc/1
 *          - PWM0_PRESSEL_FOSC_D2:PWM0预分频为Fosc/2
 *          - PWM0_PRESSEL_FOSC_D4:PWM0预分频为Fosc/4
 *          - PWM0_PRESSEL_FOSC_D8:PWM0预分频为Fosc/8
 * @param  PWM_Period:PWM周期配置
 * @retval None
 */ 
void PWM_Init(PWM_PresSel_TypeDef PWM_PresSel,
              uint16_t PWM_Period)
{
  PWM_Period -= 1;
  PWMCON = (PWMCON & 0XF8) | PWM_PresSel;	//预分频
  PWMPRD = PWM_Period;					//周期配置
}

/**
 * @brief  PWMx输出使能/失能配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 * @param  PWM_OutputState[in]:PWM输出状态配置
 *          - PWM_OUTPUTSTATE_DISABLE:该PIN脚作为GPIO
 *          - PWM_OUTPUTSTATE_ENABLE:该PIN脚作为PWM
 * @retval None
 */ 
void PWM_OutputStateConfig(uint8_t PWM_OutputPin,
                           PWM_OutputState_TypeDef PWM_OutputState)
{
  if(PWM_OutputState == PWM_OUTPUTSTATE_DISABLE)
  {
    PWMCON = PWMCON & (~((PWM_OutputPin & 0x07) << 3));
    PWMCFG0 = PWMCFG0 & (~((PWM_OutputPin & 0x38) >> 3));
  }
  else
  {
    PWMCON = PWMCON | (PWM_OutputPin & 0x07) << 3;
    PWMCFG0 = PWMCFG0 | (PWM_OutputPin & 0x38) >> 3;
  }
}

/**
 * @brief  PWMx正/反向输出配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 * @param  PWM_Polarity[in]:PWM输出状态配置
 *          - PWM_POLARITY_NON_INVERT:PWM输出不反向
 *          - PWM_POLARITY_INVERT:PWM输出反向
 * @retval None
 */ 
void PWM_PolarityConfig(uint8_t PWM_OutputPin,
                        PWM_Polarity_TypeDef PWM_Polarity)
{
  if(PWM_Polarity == PWM_POLARITY_NON_INVERT)
  {
    PWMCFG0 = PWMCFG0 & ~((PWM_OutputPin & 0x07) << 3);
    PWMCFG1 = PWMCFG1 & ~((PWM_OutputPin & 0x38));
  }
  else
  {
    PWMCFG0 = PWMCFG0 | (PWM_OutputPin & 0x07) << 3;
    PWMCFG1 = PWMCFG1 | (PWM_OutputPin & 0x38);
  }

}

/**
 * @brief  PWMx独立工作模式配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  PWM_DutyCycle[in]:PWM占空比配置
 * @retval None
 */ 
void PWM_IndependentModeConfig(
  PWM_OutputPin_TypeDef PWM_OutputPin,
  uint16_t PWM_DutyCycle)
{
  switch(PWM_OutputPin)	//设置占空比
  {
    case PWM0:
      PWMDTY0 = PWM_DutyCycle;
      break;

    case PWM1:
      PWMDTY1 = PWM_DutyCycle;
      break;

    case PWM2:
      PWMDTY2 = PWM_DutyCycle;
      break;

#if !defined (SC92F730x) &&! defined(SC92F7308B)
    case PWM3:
      PWMDTY3 = PWM_DutyCycle;
      break;
#endif

    case PWM4:
      PWMDTY4 = PWM_DutyCycle;
      break;

    case PWM5:
      PWMDTY5 = PWM_DutyCycle;
      break;

    default:
      break;
  }
}

/**
 * @brief  PWM独立模式占空比修改
 * @param  PWM_OutputPin[in]:待修改的PWM独立通道
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  Change_Direction[in]:PWM修改方向
 *          - PWM_DutyChange_Up:PWM占空比增加
 *          - PWM_DutyChange_Dowm:PWM占空比减少
 * @param  DutyIncremental[in]:修改的增量
 * @retval 返回修改成功状态位
 *          - ERROR:失败
 *          - SUCCESS:成功
 */ 
ErrorStatus PWM_IndependentMode_DutyChange(PWM_OutputPin_TypeDef PWM_OutputPin,
    PWM_DutyChange_TypeDef Change_Direction,
    uint16_t DutyIncremental)
{
  uint16_t tmpRegValue;
  uint16_t tmpPolarity = PWMPRD;
	int16_t DutychangeValue = 0;
  ErrorStatus Result = ERROR;

	if(Change_Direction == PWM_DutyChange_Up)
  {
    DutychangeValue += DutyIncremental;				//占空比增加
  }
  else
  {
    DutychangeValue -= DutyIncremental;				//占空比减少
  } 
	
  switch(PWM_OutputPin)	//设置占空比
  {
    case PWM0:
      tmpRegValue = PWMDTY0;          //读取原来的占空比
		  tmpRegValue += DutychangeValue; //设置新的占空比
		 
      if(tmpRegValue <= tmpPolarity)  //计数器没有发生溢出
			{
				PWMDTY0 = tmpRegValue;
			  Result = SUCCESS;				
			}	
      break;

    case PWM1:
      tmpRegValue = PWMDTY1;
	  	tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  
			{
				PWMDTY1 = tmpRegValue;
			  Result = SUCCESS;				
			}	
      break;

    case PWM2:
      tmpRegValue = PWMDTY2;
		  tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  
			{
				PWMDTY2 = tmpRegValue;
			  Result = SUCCESS;				
			}
      break;

#if !defined (SC92F730x) &&!defined(SC92F7308B)
    case PWM3:
      tmpRegValue = PWMDTY3;
		  tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  
			{
				PWMDTY3 = tmpRegValue;
			  Result = SUCCESS;				
			}
      break;
#endif

    case PWM4:
      tmpRegValue = PWMDTY4;
		  tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  
			{
				PWMDTY4 = tmpRegValue;
			  Result = SUCCESS;				
			}
      break;

    case PWM5:
      tmpRegValue = PWMDTY5;
		  tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  
			{
				PWMDTY5 = tmpRegValue;
			  Result = SUCCESS;				
			}
      break;

    default:
      break;
  }
  return Result;
}

/**
 * @brief  PWM功能开关函数
 * @param  NewState[in]: 功能启动/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @retval None
 */ 
void PWM_Cmd(FunctionalState NewState)
{
  if(NewState != DISABLE)
  {
    PWMCON |= 0X80;
  }
  else
  {
    PWMCON &= ~0X80;
  }
}

/**
 * @brief  PWM中断初始化
 * @param  NewState[in]: 中断使能/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @param  Priority[in]: 中断优先级选择
 *          - LOW:低
 *          - HIGH:高
 * @retval None
 */ 
void PWM_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority)
{
  if(NewState != DISABLE)
  {
    IE1 |= 0X02;
  }
  else
  {
    IE1 &= ~0X02;
  }

  if(Priority == LOW)
  {
    IP1 &= ~0X02;
  }
  else
  {
    IP1 |= 0X02;
  }
}

/**
 * @brief  获得PWM中断标志状态
 * @param  None
 * @retval PWM中断标志状态
 *              - RESET:置零
 *              - SET:置起
 */
FlagStatus PWM_GetFlagStatus(void)
{
  return (bool)(PWMCON & 0X40);
}

/**
 * @brief  清除PWM中断标志状态
 * @param  None
 * @retval None
 */
void PWM_ClearFlag(void)
{
  PWMCON &= 0XBF;
}
#endif

#if defined (SC92F827X) || defined (SC92F837X)
/**
 * @brief  PWM相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */
void PWM_DeInit(void)
{
  PWMCFG = 0X00;
  PWMCON = 0X00;
  PWMPRD = 0X00;
  PWMDTY0 = 0X00;
  PWMDTY1 = 0X00;
#if !defined (SC92F827X)
  PWMDTY2 = 0X00;
  PWMDTY3 = 0X00;
#if !defined (SC92F837X)
  PWMDTY4 = 0X00;
  PWMDTY5 = 0X00;
#endif
#endif
  IE1 &= ~0X02;
  IP1 &= ~0X02;
}

/**
 * @brief  PWM初始化配置函数
 * @param  PWM_PresSel[in]:预分频选择
 *          - PWM0_PRESSEL_FOSC_D1:PWM0预分频为Fosc/1
 *          - PWM0_PRESSEL_FOSC_D2:PWM0预分频为Fosc/2
 *          - PWM0_PRESSEL_FOSC_D4:PWM0预分频为Fosc/4
 *          - PWM0_PRESSEL_FOSC_D8:PWM0预分频为Fosc/8
 * @param  PWM_Period:PWM周期配置
 * @retval None
 */ 
void PWM_Init(PWM_PresSel_TypeDef PWM_PresSel,
              uint16_t PWM_Period)
{
  PWM_Period -= 1;
  PWMCON = (PWMCON & 0XF8) | PWM_PresSel;	//预分频
  PWMPRD = PWM_Period;					//周期配置
}

/**
 * @brief  PWMx输出使能/失能配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 * @param  PWM_OutputState[in]:PWM输出状态配置
 *          - PWM_OUTPUTSTATE_DISABLE:该PIN脚作为GPIO
 *          - PWM_OUTPUTSTATE_ENABLE:该PIN脚作为PWM
 * @retval None
 */ 
void PWM_OutputStateConfig(uint8_t PWM_OutputPin,
                           PWM_OutputState_TypeDef PWM_OutputState)
{
  if(PWM_OutputState == PWM_OUTPUTSTATE_ENABLE)
  {
    PWMCON |= PWM_OutputPin;
  }
  else
  {
    PWMCON &= (~PWM_OutputPin);
  }
}

/**
 * @brief  PWMx正/反向输出配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 * @param  PWM_Polarity[in]:PWM输出状态配置
 *          - PWM_POLARITY_NON_INVERT:PWM输出不反向
 *          - PWM_POLARITY_INVERT:PWM输出反向
 * @retval None
 */ 
void PWM_PolarityConfig(uint8_t PWM_OutputPin,
                        PWM_Polarity_TypeDef PWM_Polarity)
{
  if(PWM_Polarity == PWM_POLARITY_INVERT)
  {
    PWMCFG |= PWM_OutputPin;
  }
  else
  {
    PWMCFG &= (~PWM_OutputPin);
  }
}

/**
 * @brief  PWMx独立工作模式配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  PWM_DutyCycle[in]:PWM占空比配置
 * @retval None
 */ 
void PWM_IndependentModeConfig(
  PWM_OutputPin_TypeDef PWM_OutputPin,
  uint16_t PWM_DutyCycle)
{
  switch(PWM_OutputPin)	//设置占空比
  {
    case PWM0:
      PWMDTY0 = PWM_DutyCycle;
      break;

    case PWM1:
      PWMDTY1 = PWM_DutyCycle;
      break;
#if !defined (SC92F827X)

    case PWM2:
      PWMDTY2 = PWM_DutyCycle;
      break;

    case PWM3:
      PWMDTY3 = PWM_DutyCycle;
      break;
#if !defined (SC92F837X)

    case PWM4:
      PWMDTY4 = PWM_DutyCycle;
      break;

    case PWM5:
      PWMDTY5 = PWM_DutyCycle;
      break;
#endif
#endif

    default:
      break;
  }
}

/**
 * @brief  PWM独立模式占空比修改
 * @param  PWM_OutputPin[in]:待修改的PWM独立通道
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  Change_Direction[in]:PWM修改方向
 *          - PWM_DutyChange_Up:PWM占空比增加
 *          - PWM_DutyChange_Dowm:PWM占空比减少
 * @param  DutyIncremental[in]:修改的增量
 * @retval 返回修改成功状态位
 *          - ERROR:失败
 *          - SUCCESS:成功
 */
ErrorStatus PWM_IndependentMode_DutyChange(PWM_OutputPin_TypeDef PWM_OutputPin,
    PWM_DutyChange_TypeDef Change_Direction,
    uint16_t DutyIncremental)
{
  uint16_t tmpRegValue;
  uint16_t tmpPolarity = PWMPRD;
  int16_t DutychangeValue = 0;
  ErrorStatus Result = ERROR;
	
	if(Change_Direction == PWM_DutyChange_Up)
  {
    DutychangeValue += DutyIncremental;				//占空比增加
  }
  else
  {
    DutychangeValue -= DutyIncremental;				//占空比减少
  }
	
  switch(PWM_OutputPin)	
  {
    case PWM0:
      tmpRegValue = PWMDTY0;          //读取原来的占空比
		  tmpRegValue += DutychangeValue; //设置新的占空比
		 
      if(tmpRegValue <= tmpPolarity)  //计数器没有发生溢出
			{
				PWMDTY0 = tmpRegValue;
			  Result = SUCCESS;				
			}	
      break;

    case PWM1:
      tmpRegValue = PWMDTY1;
		  tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  
			{
				PWMDTY1 = tmpRegValue;
			  Result = SUCCESS;				
			}	
      break;

#if !defined (SC92F827X)
    case PWM2:
      tmpRegValue = PWMDTY2;
		  tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  
			{
				PWMDTY2 = tmpRegValue;
			  Result = SUCCESS;				
			}	
      break;

    case PWM3:
      tmpRegValue = PWMDTY3;
		  tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  
			{
				PWMDTY3 = tmpRegValue;
			  Result = SUCCESS;				
			}	
      break;

#if !defined (SC92F837X)
    case PWM4:
      tmpRegValue = PWMDTY4;
		  tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  
			{
				PWMDTY4 = tmpRegValue;
			  Result = SUCCESS;				
			}	
      break;

    case PWM5:
      tmpRegValue = PWMDTY5;
		  tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  
			{
				PWMDTY5 = tmpRegValue;
			  Result = SUCCESS;				
			}	
      break;
#endif
#endif
    default:
      break;
  }
	return Result;
}

/**
 * @brief  PWM功能开关函数
 * @param  NewState[in]: 功能启动/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @retval None
 */ 
void PWM_Cmd(FunctionalState NewState)
{
  if(NewState != DISABLE)
  {
    PWMCON |= 0X80;
  }
  else
  {
    PWMCON &= ~0X80;
  }
}

/**
 * @brief  PWM中断初始化
 * @param  NewState[in]: 中断使能/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @param  Priority[in]: 中断优先级选择
 *          - LOW:低
 *          - HIGH:高
 * @retval None
 */ 
void PWM_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority)
{
  if(NewState != DISABLE)
  {
    IE1 |= 0X02;
  }
  else
  {
    IE1 &= 0XFD;
  }

  if(Priority == LOW)
  {
    IP1 &= 0XFD;
  }
  else
  {
    IP1 |= 0X02;
  }
}

/**
 * @brief  获得PWM中断标志状态
 * @param  None
 * @retval PWM中断标志状态
 *              - RESET:置零
 *              - SET:置起
 */
FlagStatus PWM_GetFlagStatus(void)
{
  return (bool)(PWMCON & 0X40);
}

/**
 * @brief  清除PWM中断标志状态
 * @param  None
 * @retval None
 */
void PWM_ClearFlag(void)
{
  PWMCON &= 0XBF;
}

#endif

#if defined (SC92F732X) || defined (SC93F833x) || defined (SC93F843x) || defined (SC93F743x)
/**
 * @brief  PWM相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */
void PWM_DeInit(void)
{
  PWMCFG = 0X00;
  PWMCON = 0X00;
  PWMPRD = 0X00;
  PWMDTYA = 0X00;
  PWMDTY0 = 0X00;
  PWMDTY1 = 0X00;
  PWMDTY2 = 0X00;
  IE1 &= ~0X02;
  IP1 &= ~0X02;
}

/**
 * @brief  PWM初始化配置函数
 * @param  PWM_PresSel[in]:预分频选择
 *          - PWM0_PRESSEL_FOSC_D1:PWM0预分频为Fosc/1
 *          - PWM0_PRESSEL_FOSC_D2:PWM0预分频为Fosc/2
 *          - PWM0_PRESSEL_FOSC_D4:PWM0预分频为Fosc/4
 *          - PWM0_PRESSEL_FOSC_D8:PWM0预分频为Fosc/8
 * @param  PWM_Period:PWM周期配置
 * @retval None
 */ 
void PWM_Init(PWM_PresSel_TypeDef PWM_PresSel,
              uint16_t PWM_Period)
{
  PWM_Period -= 1;
  PWMCON = (PWMCON & 0XF8) | PWM_PresSel;	//预分频
  PWMPRD = PWM_Period;					//周期配置
}

/**
 * @brief  PWMx输出使能/失能配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 * @param  PWM_OutputState[in]:PWM输出状态配置
 *          - PWM_OUTPUTSTATE_DISABLE:该PIN脚作为GPIO
 *          - PWM_OUTPUTSTATE_ENABLE:该PIN脚作为PWM
 * @retval None
 */ 
void PWM_OutputStateConfig(uint8_t PWM_OutputPin,
                           PWM_OutputState_TypeDef PWM_OutputState)
{
  if(PWM_OutputState == PWM_OUTPUTSTATE_DISABLE)
  {
    PWMCON = PWMCON & (~(PWM_OutputPin << 3));
  }
  else
  {
    PWMCON = PWMCON | (PWM_OutputPin << 3);
  }
}

/**
 * @brief  PWMx正/反向输出配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 * @param  PWM_Polarity[in]:PWM输出状态配置
 *          - PWM_POLARITY_NON_INVERT:PWM输出不反向
 *          - PWM_POLARITY_INVERT:PWM输出反向
 * @retval None
 */ 
void PWM_PolarityConfig(uint8_t PWM_OutputPin,
                        PWM_Polarity_TypeDef PWM_Polarity)
{
  if(PWM_Polarity == PWM_POLARITY_NON_INVERT)
  {
    PWMCFG = PWMCFG & (~PWM_OutputPin << 3);
  }
  else
  {
    PWMCFG = PWMCFG | (PWM_OutputPin << 3);
  }
}

/**
 * @brief  PWMx独立工作模式配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  PWM_DutyCycle[in]:PWM占空比配置
 * @retval None
 */ 
void PWM_IndependentModeConfig(
  PWM_OutputPin_TypeDef PWM_OutputPin,
  uint16_t PWM_DutyCycle)
{
  switch(PWM_OutputPin)	//设置占空比
  {
    case PWM0:
      PWMDTY0 = PWM_DutyCycle;
      break;

    case PWM1:
      PWMDTY1 = PWM_DutyCycle;
      break;

    case PWM2:
      PWMDTY2 = PWM_DutyCycle;
      break;

    default:
      break;
  }
}

/**
 * @brief  PWM独立模式占空比修改
 * @param  PWM_OutputPin[in]:待修改的PWM独立通道
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  Change_Direction[in]:PWM修改方向
 *          - PWM_DutyChange_Up:PWM占空比增加
 *          - PWM_DutyChange_Dowm:PWM占空比减少
 * @param  DutyIncremental[in]:修改的增量
 * @retval 返回修改成功状态位
 *          - ERROR:失败
 *          - SUCCESS:成功
 */
ErrorStatus PWM_IndependentMode_DutyChange(PWM_OutputPin_TypeDef PWM_OutputPin,
    PWM_DutyChange_TypeDef Change_Direction,
    uint16_t DutyIncremental)
{
  uint16_t tmpRegValue;
  uint16_t tmpPolarity = PWMPRD;
  int16_t DutychangeValue = 0;
  ErrorStatus Result = ERROR;
	
	if(Change_Direction == PWM_DutyChange_Up)
  {
    DutychangeValue += DutyIncremental;				//占空比增加
  }
  else
  {
    DutychangeValue -= DutyIncremental;				//占空比减少
  }
	
  switch(PWM_OutputPin)	//设置占空比
  {
    case PWM0:
      tmpRegValue = PWMDTY0;          //读取原来的占空比
		  tmpRegValue += DutychangeValue; //设置新的占空比
		 
      if(tmpRegValue <= tmpPolarity)  //计数器没有发生溢出
			{
				PWMDTY0 = tmpRegValue;
			  Result = SUCCESS;				
			}
      break;

    case PWM1:
      tmpRegValue = PWMDTY1;
		  tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  
			{
				PWMDTY1 = tmpRegValue;
			  Result = SUCCESS;				
			}
      break;

    case PWM2:
      tmpRegValue = PWMDTY2;
		  tmpRegValue += DutychangeValue;
		
		  if(tmpRegValue <= tmpPolarity)  
			{
				PWMDTY2 = tmpRegValue;
			  Result = SUCCESS;				
			}	
      break;

    default:
      break;
  }
  return Result;
}

/**
 * @brief  PWM功能开关函数
 * @param  NewState[in]: 功能启动/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @retval None
 */ 
void PWM_Cmd(FunctionalState NewState)
{
  if(NewState != DISABLE)
  {
    PWMCON |= 0X80;
  }
  else
  {
    PWMCON &= ~0X80;
  }
}

/**
 * @brief  PWM中断初始化
 * @param  NewState[in]: 中断使能/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @param  Priority[in]: 中断优先级选择
 *          - LOW:低
 *          - HIGH:高
 * @retval None
 */ 
void PWM_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority)
{
  if(NewState != DISABLE)
  {
    IE1 |= 0X02;
  }
  else
  {
    IE1 &= ~0X02;
  }

  if(Priority == LOW)
  {
    IP1 &= ~0X02;
  }
  else
  {
    IP1 |= 0X02;
  }
}

/**
 * @brief  获得PWM中断标志状态
 * @param  None
 * @retval PWM中断标志状态
 *              - RESET:置零
 *              - SET:置起
 */
FlagStatus PWM_GetFlagStatus(void)
{
  return (bool)(PWMCON & 0X40);
}

/**
 * @brief  清除PWM中断标志状态
 * @param  None
 * @retval None
 */
void PWM_ClearFlag(void)
{
  PWMCON &= 0XBF;
}

/**
 * @brief  PWM0管脚选择函数
 * @param  PWM0_OutputPin[in]:PWM0管脚选择函数
 *          - PWM0_OutputPin_P00:PWM0输出口选择P00
 *          - PWM0_OutputPin_P25:PWM0输出口选择P25
 * @retval None
 */
void PWM_PWM0Selection(PWM0_OutputPin_TypeDef
                       PWM0_OutputPin)
{
  PWMCFG = PWMCFG & 0XFE | PWM0_OutputPin;
}

/**
 * @brief  PWM1管脚选择函数
 * @param  PWM1_OutputPin[in]:PWM1管脚选择函数
 *          - PWM1_OutputPin_P01:PWM1输出口选择P01
 *          - PWM1_OutputPin_P26:PWM1输出口选择P26
 * @retval None
 */
void PWM_PWM1Selection(PWM1_OutputPin_TypeDef
                       PWM1_OutputPin)
{
  PWMCFG = PWMCFG & 0XFD | PWM1_OutputPin;
}

/**
 * @brief  PWM2管脚选择函数
 * @param  PWM2_OutputPin[in]:PWM2管脚选择函数
 *          - PWM2_OutputPin_P26:PWM2输出口选择P26
 *          - PWM2_OutputPin_P14:PWM2输出口选择P14
 * @retval None
 */ 
void PWM_PWM2Selection(PWM2_OutputPin_TypeDef
                       PWM2_OutputPin)
{
  PWMCFG = PWMCFG & 0XFB | PWM2_OutputPin;
}

/**
 * @brief  PWM占空比微调模式选择
 * @param  PWM_OutputPin[in]:PWM通道
 *          - PWM0:PWM输出通道选择:PWM0
 *          - PWM1:PWM输出通道选择:PWM1
 *          - PWM2:PWM输出通道选择:PWM2
 * @param  PWM_DutyMode[in]:PWM微调模式
 *          - PWM_DutyMode0:00:四个PWM2输出的duty均为PDT2设定值；(D、D、D、D)
 *          - PWM_DutyMode1:01:第一个PWM2输出的duty为PDT2设定值加1，其余三个PWM2输出的duty均为PDT2设定值；(D+1、D、D、D)
 *          - PWM_DutyMode2:10:第一和第二个PWM2输出的duty为PDT2设定值加1，其余二个PWM2输出的duty均为PDT2设定值；(D+1、D+1、D、D)
 *          - PWM_DutyMode3:11:第一、第二和第三个PWM2输出的duty为PDT2设定值加1，第四个PWM2输出的Duty为PDT2设定值； (D+1、D+1、D+1、D)
 * @retval None
 */ 
void PMM_DutyModeSelection(PWM_OutputPin_TypeDef
                           PWM_OutputPin, PWM_DutyMode_TypeDef PWM_DutyMode)
{
  PWMDTYA = PWMDTYA & (~(0x03 << (PWM_OutputPin -
                                  1))) | (PWM_DutyMode << (PWM_OutputPin - 1));
}
#endif

#if defined (SC92FWxx)

uint8_t xdata PWMREG[80] _at_ 0x700;	//PWM占空比调节寄存器
uint8_t PWMREG_Status[10];

/**
 * @brief  PWM相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */
void PWM_DeInit(void)
{
  static uint8_t i;
  PWMCFG0 = 0X00;
  PWMCON0 = 0X00;
  PWMCFG1 = 0X00;
  PWMCON1 = 0X00;
  IE1 &= 0XFD;
  IP1 &= 0XFD;

  for(i = 0; i < 80; i++)
  {
    PWMREG[i] = 0;
  }
}

/**
 * @brief  PWM初始化配置函数
 * @param  PWM_PresSel[in]:预分频选择
 *          - PWM0_PRESSEL_FOSC_D1:PWM0预分频为Fosc/1
 *          - PWM0_PRESSEL_FOSC_D2:PWM0预分频为Fosc/2
 *          - PWM0_PRESSEL_FOSC_D4:PWM0预分频为Fosc/4
 *          - PWM0_PRESSEL_FOSC_D8:PWM0预分频为Fosc/8
 * @param  PWM_Period:PWM周期配置
 * @retval None
 */ 
void PWM_Init(PWM_PresSel_TypeDef PWM_PresSel,
              uint16_t PWM_Period)
{
  if((PWM_PresSel & 0X0F) == PWM0_Type)
  {
    PWM_Period -= 1;
    PWMCFG0 = (PWMCFG0 & 0XCF) | (PWM_PresSel &
                                  0XF0);					//预分频
    PWMCFG0 = (PWMCFG0 & 0XF0) | (uint8_t)(
                PWM_Period / 256);	//周期高4位
    PWMCON0 = (uint8_t)(PWM_Period &
                        0X00FF);				//周期低8位
  }
  else if((PWM_PresSel & 0X0F) == PWM1_Type)
  {
    PWM_Period -= 1;
    PWMCFG1 = (PWMCFG1 & 0XCF) | (PWM_PresSel &
                                  0XF0);					//预分频
    PWMCFG1 = (PWMCFG1 & 0XF0) | (uint8_t)(
                PWM_Period / 256);	//周期高4位
    PWMCON1 = (uint8_t)(PWM_Period &
                        0X00FF);				//周期低8位
  }
}

/**
 * @brief  PWMx输出使能/失能配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 * @param  PWM_OutputState[in]:PWM输出状态配置
 *          - PWM_OUTPUTSTATE_DISABLE:该PIN脚作为GPIO
 *          - PWM_OUTPUTSTATE_ENABLE:该PIN脚作为PWM
 * @retval None
 */ 
void PWM_OutputStateConfig(uint8_t PWM_OutputPin,
                           PWM_OutputState_TypeDef PWM_OutputState)
{
  if(PWM_OutputState == ENABLE)
  {
    PWMREG[PWM_OutputPin] |= 0x80;
  }
  else
  {
    PWMREG[PWM_OutputPin] &= 0x7F;
  }
}

/**
 * @brief  PWMx正/反向输出配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 * @param  PWM_Polarity[in]:PWM输出状态配置
 *          - PWM_POLARITY_NON_INVERT:PWM输出不反向
 *          - PWM_POLARITY_INVERT:PWM输出反向
 * @retval None
 */ 
void PWM_PolarityConfig(uint8_t PWM_OutputPin,
                        PWM_Polarity_TypeDef PWM_Polarity)
{
  if(PWM_Polarity == PWM_POLARITY_INVERT)
  {
    PWMREG[PWM_OutputPin] |= 0x40;
  }
  else
  {
    PWMREG[PWM_OutputPin] &= 0xBF;
  }
}

/**
 * @brief  PWMx独立工作模式配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  PWM_DutyCycle[in]:PWM占空比配置
 * @retval None
 */ 
void PWM_IndependentModeConfig(PWM_OutputPin_TypeDef PWM_OutputPin,
                               uint16_t PWM_DutyCycle)
{
  PWMREG[PWM_OutputPin + 1] = PWM_DutyCycle;
  PWMREG[PWM_OutputPin] = (PWMREG[PWM_OutputPin] & 0xF0) | (PWM_DutyCycle / 256);
}

/**
 * @brief  PWM独立模式占空比修改
 * @param  PWM_OutputPin[in]:待修改的PWM独立通道
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  Change_Direction[in]:PWM修改方向
 *          - PWM_DutyChange_Up:PWM占空比增加
 *          - PWM_DutyChange_Dowm:PWM占空比减少
 * @param  DutyIncremental[in]:修改的增量
 * @retval 返回修改成功状态位
 *          - ERROR:失败
 *          - SUCCESS:成功
 */
ErrorStatus PWM_IndependentMode_DutyChange(PWM_OutputPin_TypeDef PWM_OutputPin,
    PWM_DutyChange_TypeDef Change_Direction, uint16_t DutyIncremental)
{
  uint16_t tmpRegValue;
  uint16_t tmpPolarity;
  if(PWM_OutputPin < 0x40)
  {
    tmpPolarity = (((PWMCFG0 & 0XF0) << 8) | PWMCON0);
  }
  else
  {

    tmpPolarity = (((PWMCFG1 & 0XF0) << 8) | PWMCON1);
  }


  tmpRegValue = (((PWMREG[PWM_OutputPin] & 0XF0) << 8) | PWMREG[PWM_OutputPin + 1]);

  if(Change_Direction == PWM_DutyChange_Up)
  {
    tmpRegValue += DutyIncremental;				//占空比增加
  }
  else
  {
    tmpRegValue -= DutyIncremental;				//占空比减少
  }
  /* 计数器发生了溢出 */
  if(tmpRegValue > tmpPolarity)
    return ERROR;

  PWMREG[PWM_OutputPin + 1] = tmpRegValue;
  PWMREG[PWM_OutputPin] = (PWMREG[PWM_OutputPin] & 0xF0) | (tmpRegValue / 256);

  return SUCCESS;
}

/**
 * @brief  PWM功能开关函数
 * @param  NewState[in]: 功能启动/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @retval None
 */ 
void PWM_CmdEX(PWM_Type_TypeDef PWM_Type,
               FunctionalState NewState)
{
  if(PWM_Type == PWM0_Type)
  {
    if(NewState != DISABLE)
    {
      PWMCFG0 |= 0X80;
    }
    else
    {
      PWMCFG0 &= 0X7F;
    }
  }
  else
  {
    if(NewState != DISABLE)
    {
      PWMCFG1 |= 0X80;
    }
    else
    {
      PWMCFG1 &= 0X7F;
    }
  }
}

/**
 * @brief  PWM中断初始化
 * @param  NewState[in]: 中断使能/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @param  Priority[in]: 中断优先级选择
 *          - LOW:低
 *          - HIGH:高
 * @retval None
 */ 
void PWM_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority)
{
  if(NewState != DISABLE)
  {
    IE1 |= 0X02;
  }
  else
  {
    IE1 &= 0XFD;
  }

  if(Priority == LOW)
  {
    IP1 &= ~0X02;
  }
  else
  {
    IP1 |= 0X02;
  }
}

/**
 * @brief  获得PWM中断标志状态
 * @param  None
 * @retval PWM中断标志状态
 *              - RESET:置零
 *              - SET:置起
 */
FlagStatus PWM_GetFlagStatusEX(PWM_Type_TypeDef
                               PWM_Type)
{
  if(PWM_Type == PWM0_Type)
  {
    return (bool)(PWMCFG0 & 0X40);
  }
  else
  {
    return (bool)(PWMCFG1 & 0X40);
  }
}

/**
 * @brief  清除PWM中断标志状态
 * @param  PWM_Type[in]: PWM源选择
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @retval None
 */ 
void PWM_ClearFlagEX(PWM_Type_TypeDef PWM_Type)
{
  if(PWM_Type == PWM0_Type)
  {
    PWMCFG0 &= 0XBF;
  }
  else
  {
    PWMCFG1 &= 0XBF;
  }
}

/**
 * @brief  PWM互补模式占空比修改
 * @param  PWM_OutputPin[in]: 待修改的PWM互补通道
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @param  PWM_DutyCycle[in]:PWM占空比配置
 * @param  PWM_OutputState[in]: 修改的增量
 *          - PWM_OUTPUTSTATE_DISABLE:该PIN脚作为GPIO
 *          - PWM_OUTPUTSTATE_ENABLE:该PIN脚作为PWM
 * @retval None
 */ 
void PWM_IndependentModeConfigEX(PWM_OutputPin_TypeDef PWM_OutputPin,
                                 uint16_t PWM_DutyCycle,
                                 PWM_OutputState_TypeDef PWM_OutputState)
{
  if(PWM_OutputState == ENABLE)
  {
    PWMREG[PWM_OutputPin] = (PWMREG[PWM_OutputPin] * 0xF0) | (0x80 | (PWM_DutyCycle /
                            256));
    PWMREG[PWM_OutputPin + 1] = PWM_DutyCycle;
  }
  else
  {
    PWMREG[PWM_OutputPin] &= 0x7F;
  }
}

#endif

#if defined (SC92L853x) || defined (SC92L753x) || defined (SC92L840x)
#if defined (SC92L853x) || defined (SC92L753x)
uint8_t xdata PWMREG[28] _at_ 0x0F40; //PWM占空比调节寄存器
#elif defined (SC92L840x)
uint8_t xdata PWMREG[12] _at_ 0x0300; //PWM占空比调节寄存器
#endif
/**
 * @brief  PWM相关寄存器复位至缺省值
 * @param  None
 * @retval None
 */ 
void PWM_DeInit(void)
{
  static uint8_t i;

  //PWM0相关寄存器清零
  PWMCON0 = 0X00;
  PWMCFG = 0X00;
  PWMCON1 = 0X00;
  PWMPDL = 0x00;
  PWMPDH = 0x00;
  IE1 &= 0XFD;
  IP1 &= 0XFD;

  //占空比寄存器
  for(i = 0; i < 14; i++)
  {
    PWMREG[i] = 0;
  }
}

/**
 * @brief  PWM初始化配置函数
 * @param  PWM_PresSel[in]:预分频选择
 *          - PWM0_PRESSEL_FOSC_D1:PWM0预分频为Fosc/1
 *          - PWM0_PRESSEL_FOSC_D2:PWM0预分频为Fosc/2
 *          - PWM0_PRESSEL_FOSC_D4:PWM0预分频为Fosc/4
 *          - PWM0_PRESSEL_FOSC_D8:PWM0预分频为Fosc/8
 * @param  PWM_Period:PWM周期配置
 * @retval None
 */ 
void PWM_Init(PWM_PresSel_TypeDef PWM_PresSel, uint16_t PWM_Period)
{
  /* PWM0时基初始化 */
  PWM_Period -= 1;
  PWMCON0 = ((PWMCON0 & 0XCF) | PWM_PresSel); //预分频
  PWMPDH = (uint8_t)(PWM_Period >> 8);               //周期高8位
  PWMPDL = (uint8_t)(PWM_Period & 0X00FF);           //周期低8位
}

/**
 * @brief  选择PWM的对齐模式
 * @param  PWM_Aligned_Mode[in]:选择对齐模式
 *          - PWM0_Edge_Aligned_Mode:PWM边沿对齐模式
 *          - PWM0_Center_Alignment_Mode:PWM中心对齐模式
 * @retval None
 */ 
void PWM_Aligned_Mode_Select(PWM_Aligned_Mode_TypeDef PWM_Aligned_Mode)
{
  PWMCON0 &= ~0x01;	//清除PWM对齐模式配置
  PWMCON0 |= (PWM_Aligned_Mode );	//设置PWM对齐模式
}

/**
 * @brief  PWMx输出使能/失能配置函数
 * @param  PWM_OutputPin[in]:PWMx选择（uint8_t作为入参，方便进行位或操作）
 * @param  PWM_OutputState[in]:PWM输出状态配置
 *          - PWM_OUTPUTSTATE_DISABLE:该PIN脚作为GPIO
 *          - PWM_OUTPUTSTATE_ENABLE:该PIN脚作为PWM
 * @retval None
 */ 
void PWM_OutputStateConfig(uint8_t PWM_OutputPin,
                           PWM_OutputState_TypeDef PWM_OutputState)
{
  /* PWM0输出通道使能配置 */
  if(PWM_OutputState == PWM_OUTPUTSTATE_ENABLE)
  {
    PWMCON1 |=PWM_OutputPin;
  }
  else
  {
    PWMCON1 &= ~PWM_OutputPin;
  }
}

/**
 * @brief  PWMx正/反向输出配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 * @param  PWM_Polarity[in]: PWM输出正/反向配置
 *              - PWM_POLARITY_NON_INVERT:PWM输出不反向
 *              - PWM_POLARITY_INVERT:PWM输出反向
 * @retval None
 */ 
void PWM_PolarityConfig(uint8_t PWM_OutputPin,
                        PWM_Polarity_TypeDef PWM_Polarity)
{
  if(PWM_Polarity == PWM_POLARITY_INVERT)
  {
    PWMCFG |= PWM_OutputPin;
  }
  else
  {
    PWMCFG &= ~PWM_OutputPin;
  }
}

/**
 * @brief  PWMx独立工作模式配置函数
 * @param  PWM_OutputPin[in]:PWMx选择
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  PWM_DutyCycle[in]: PWM占空比配置
 * @retval None
 */ 
void PWM_IndependentModeConfig(PWM_OutputPin_TypeDef PWM_OutputPin, uint16_t PWM_DutyCycle)
{
  uint8_t Output;
#if defined (SC92L853x) || defined (SC92L753x) 
  switch (PWM_OutputPin)
  {
  case PWM0:
    Output = 0x00;
    break;
  case PWM1:
    Output = 0x02;
    break;
  case PWM2:
    Output = 0x04;
    break;
  case PWM3:
    Output = 0x06;
    break;
  case PWM4:
    Output = 0x08;
    break;
  case PWM5:
    Output = 0x0A;
    break;
  case PWM6:
    Output = 0x0C;
    break;
  case PWM7:
    Output = 0x0E;
    break;
  default:
    Output = PWM_OutputPin;
    break;
  }
#elif defined (SC92L840x)
  switch (PWM_OutputPin)
  {
  case PWM0:
    Output = 0x00;
    break;
  case PWM1:
    Output = 0x02;
    break;
  case PWM2:
    Output = 0x04;
    break;
  case PWM3:
    Output = 0x06;
    break;
  case PWM4:
    Output = 0x08;
    break;
  case PWM5:
    Output = 0x0A;
    break;
  default:
    Output = PWM_OutputPin;
    break;
  }	
#endif
  PWMCON0 &= ~0x02;	//设置PWM为独立模式
  /* 设置PWM周期 */
  PWMREG[ Output + 1] = PWM_DutyCycle;
  PWMREG[ Output ] = PWM_DutyCycle >> 8;
}

/**
 * @brief  PWMxPWMy互补工作模式配置函数
 * @param  PWM_ComplementaryOutputPin[in]:PWMxPWMy互补通道选择
 *          - PWM0PWM3:PWM输出通道选择:PWM互补模式通道选择:PWM0、PWM3
 *          - PWM1PWM4:PWM输出通道选择:PWM互补模式通道选择:PWM1、PWM4
 *          - PWM2PWM5:PWM输出通道选择:PWM互补模式通道选择:PWM2、PWM5
 * @param  PWM_DutyCycle[in]: PWM占空比配置
 * @retval None
 */ 
void PWM_ComplementaryModeConfig(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
                                 uint16_t PWM_DutyCycle)
{
  PWMCON0 |= 0x02;
  PWMREG[ PWM_ComplementaryOutputPin] = PWM_DutyCycle >> 8;
  PWMREG[ PWM_ComplementaryOutputPin + 1] = PWM_DutyCycle;
}

/**
 * @brief  PWM互补工作模式下死区时间配置函数
 * @param  PWM_RisingDeadTime[in]:PWM_RisingDeadTime:PWM死区上升时间00-FF
 * @param  PWM_RisingDeadTime[in]: PWM_FallingDeadTime:PWM死区下降时间00-FF
 * @retval None
 */ 
void PWM_DeadTimeConfigEX(PWM_Type_TypeDef PWM_Type, uint8_t PWM_RisingDeadTime, uint8_t PWM_FallingDeadTime)
{
  if(PWM_Type == PWM0_Type)
  {
    PWMDFR = (PWM_RisingDeadTime | (PWM_FallingDeadTime << 4));
  }
}
#if defined (SC92L853x) || defined (SC92L753x) || defined (SC92L840x) 
/**
 * @brief  PWM功能开关函数-扩展版
 * @param  PWM_Type[in]:PWM类型
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @param  NewState[in]: 功能启动/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @retval None
 */ 
void PWM_CmdEX(PWM_Type_TypeDef PWM_Type,
               FunctionalState NewState)
{
  if(PWM_Type == PWM0_Type)
  {
    if(NewState != DISABLE)
    {
      PWMCON0 |= 0X80;
    }
    else
    {
      PWMCON0 &= 0X7F;
    }
  }
#if !defined (SC92L840x) 
  else
  {
    TXINX = PWM_Type;
    if(NewState != DISABLE)
    {
      TXCON |= 0X04;
    }
    else
    {
      TXCON &= ~0X04;
    }
  }
#endif
}

/**
 * @brief  PWM中断初始化
 * @param  NewState[in]: 中断使能/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @param  Priority[in]: 中断优先级选择
 *          - LOW:低
 *          - HIGH:高
 * @retval None
 */ 
#endif
void PWM_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority)
{
  if(NewState != DISABLE)
  {
    IE1 |= 0X02;
  }
  else
  {
    IE1 &= 0XFD;
  }

  if(Priority == LOW)
  {
    IP1 &= ~0X02;
  }
  else
  {
    IP1 |= 0X02;
  }
}
#if defined (SC92L853x) || defined (SC92L753x) 
/**
 * @brief  PWM独立模式配置-扩展版
 * @param  PWM_OutputPin[in]: PWM通道
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  PWM_DutyCycle[in]: PWM占空比配置
 * @param  PWM_OutputState[in]: 功能启动/关闭选择
 *          - PWM_OUTPUTSTATE_DISABLE:该PIN脚作为GPIO
 *          - PWM_OUTPUTSTATE_ENABLE:该PIN脚作为PWM
 * @retval None
 */
void PWM_IndependentModeConfigEX(PWM_OutputPin_TypeDef PWM_ComplementaryOutputPin,
                                 uint16_t PWM_DutyCycle,
                                 PWM_OutputState_TypeDef PWM_OutputState)
{
  PWM_IndependentModeConfig(PWM_ComplementaryOutputPin, PWM_DutyCycle); //配置占空比
  PWM_OutputStateConfig(PWM_ComplementaryOutputPin, PWM_OutputState);   //IO复用PWM配置函数
  if(PWM_OutputState == ENABLE)
  {
    PWM_CmdEX(PWM_ComplementaryOutputPin >> 4, ENABLE); //开启PWM
  }
}

/**
 * @brief  PWM互补模式配置-扩展版
 * @param  PWM_ComplementaryOutputPin[in]:PWM通道
 *          - PWM0PWM1:PWM互补模式通道选择:PWM00、PWM01
 *          - PWM2PWM3:PWM互补模式通道选择:PWM02、PWM03
 *          - PWM4PWM5:PWM互补模式通道选择:PWM04、PWM05
 *          - PWM6PWM7:PWM互补模式通道选择:PWM06、PWM07
 * @param  PWM_DutyCycle[in]: PWM占空比配置
 * @param  PWM_OutputState[in]: 功能启动/关闭选择
 * @retval None
 */
void PWM_ComplementaryModeConfigEX(PWM_ComplementaryOutputPin_TypeDef PWM_OutputPin,
                                   uint16_t PWM_DutyCycle,
                                   PWM_OutputState_TypeDef PWM_OutputState)
{
  PWM_ComplementaryModeConfig(PWM_OutputPin, PWM_DutyCycle); //配置占空比
  PWM_OutputStateConfig(PWM_OutputPin, PWM_OutputState);     //IO复用PWM配置函数
  PWM_OutputStateConfig(PWM_OutputPin + 1, PWM_OutputState); //IO复用PWM配置函数
  if(PWM_OutputState == ENABLE)
  {
    PWM_CmdEX(PWM_OutputPin >> 4, ENABLE); //开启PWM
  }
}
#endif
/**
 * @brief  PWM独立模式占空比修改
 * @param  PWM_ComplementaryOutputPin[in]:PWM通道
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  Change_Direction[in]:PWM修改方向
 *          - PWM_DutyChange_Up:PWM占空比增加
 *          - PWM_DutyChange_Dowm:PWM占空比减少
 * @retval 返回修改成功状态位
 *          - ERROR:失败
 *          - SUCCESS:成功
 */
ErrorStatus PWM_IndependentMode_DutyChange(PWM_OutputPin_TypeDef PWM_OutputPin,
    PWM_DutyChange_TypeDef Change_Direction, uint16_t DutyIncremental)
{
  uint8_t i;
  uint8_t tmpRegValue;

  for(i = 0; i < 8; i++)
  {
    if(PWM_OutputPin & (0x01 << i))
    {
      tmpRegValue = PWMREG[i];			//把当前占空比寄存器放进临时变量
      if(Change_Direction == PWM_DutyChange_Up)
      {
        tmpRegValue += DutyIncremental;				//占空比增加

        /* 计数器发生了向上溢出 */
        if(tmpRegValue < PWMREG[i])
          return ERROR;
      }
      else
      {
        tmpRegValue -= DutyIncremental;				//占空比减少

        /* 计数器发生了向下溢出 */
        if(tmpRegValue < PWMREG[i])
          return ERROR;
      }
      PWMREG[i] = tmpRegValue;		//占空比寄存器赋值
    }
  }
  return SUCCESS;
}

/**
 * @brief  PWM互补模式占空比修改
 * @param  PWM_OutputPin[in]: 待修改的PWM互补通道
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @param  Change_Direction[in]:PWM修改方向
 *          - PWM_DutyChange_Up:PWM占空比增加
 *          - PWM_DutyChange_Dowm:PWM占空比减少
 * @param  DutyIncremental[in]: 修改的增量
 * @retval 返回修改成功状态位
 *          - ERROR:失败
 *          - SUCCESS:成功
 */ 
ErrorStatus PWM_ComplementaryMode_DutyChange(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin,
    PWM_DutyChange_TypeDef Change_Direction, uint16_t DutyIncremental)
{
  uint8_t tmpRegValue;
  uint16_t tmpPolarity = PWMPDL + (PWMPDH << 8);

  tmpRegValue = PWMREG[PWM_ComplementaryOutputPin * 2];			//把当前占空比寄存器放进临时变量
  if(Change_Direction == PWM_DutyChange_Up)
  {
    tmpRegValue += DutyIncremental;				//占空比增加
  }
  else
  {
    tmpRegValue -= DutyIncremental;				//占空比减少
  }

  /* 计数器发生了向上溢出 */
  if(tmpRegValue > tmpPolarity)
    return ERROR;
  PWMREG[PWM_ComplementaryOutputPin] = tmpRegValue;		//占空比寄存器赋值
  return SUCCESS;
}

/**
 * @brief  获取PWM中断标志位-扩展版
 * @param  PWM_Type[in]:PWM源选择
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @param  PWM_DutyCycle[in]: PWM占空比配置
 * @param  PWM_OutputState[in]: 功能启动/关闭选择
 * @retval PWM中断标志位状态
 *              - RESET:置零
 *              - SET:置起
 */ 
FlagStatus PWM_GetFlagStatusEX(PWM_Type_TypeDef PWM_Type)
{
  if((PWM_Type == PWM0_Type))
  {
    return (bool)(PWMCON0 & 0X40);
  }

  return RESET;
}

/**
 * @brief  清除PWM中断标志位-扩展版
 * @param  PWM_Type[in]:PWM源选择
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @retval None
 */ 
void PWM_ClearFlagEX(PWM_Type_TypeDef PWM_Type)
{
  if((PWM_Type == PWM0_Type))
  {
    PWMCON0 &= ~0X40;
  }
}
#if defined (SC92L853x) || defined (SC92L753x) 
/**
 * @brief  获得PWM故障检测标志位状态
 * @param  PWM_Type[in]:PWM选择类型
 *          - PWM40:PWM输出通道选择:PWM40
 *          - PWM41:PWM输出通道选择:PWM41
 *          - PWM42:PWM输出通道选择:PWM42
 *          - PWM43:PWM输出通道选择:PWM43
 *          - PWM50:PWM输出通道选择:PWM50
 *          - PWM51:PWM输出通道选择:PWM51
 *          - PWM52:PWM输出通道选择:PWM52
 *          - PWM53:PWM输出通道选择:PWM53
 * @retval PWM故障检测标志位状态
 *              - RESET:置零
 *              - SET:置起
 */ 
FlagStatus PWM_GetFaultDetectionFlagStatusEX(PWM_Type_TypeDef PWM_Type)
{
  if(PWM_Type == PWM0_Type)
  {
    return (bool)(PWMFLT & 0X40);
  }
  return RESET;
}

/**
 * @brief  清除PWM故障检测标志位状态   // ！注意,处于锁存模式下，此位可软件清除
 * @param  PWM_Type[in]:PWM源选择
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @retval None
 */ 
void PWM_ClearFaultDetectionFlagEX(PWM_Type_TypeDef PWM_Type)
{
  if(PWM_Type == PWM0_Type)
  {
    PWMFLT &= 0XBF;
  }
}

/**
 * @brief  PWM故障检测功能开启/关闭-扩展版
 * @param  PWM_Type[in]: PWM源选择
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @param  NewState[in]: 中断使能/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @retval None
 */ 
void PWM_FaultDetectionConfigEX(PWM_Type_TypeDef PWM_Type, FunctionalState NewState)
{
  if(PWM_Type == PWM0_Type)
  {
    if(NewState != DISABLE)
    {
      PWMFLT |= 0X80;
    }
    else
    {
      PWMFLT &= 0X7F;
    }
  }
}

/**
 * @brief  PWM故障检测模式设置
 * @param  PWM_Type[in]: PWM源选择
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @param  FaultDetectionMode[in]: 故障检测功能模式设置:立即模式/锁存模式
 *          - PWM0_Latch_Mode:PWM故障检测模式:锁存模式
 *          - PWM0_Immediate_Mode:PWM故障检测模式:立即模式
 * @param  FaultDetectionVoltageSelect[in]: 故障检测电平选择
 *          - PWM_FaultDetectionVoltage_Low:PWM故障检测低电平选择
 *          - PWM_FaultDetectionVoltage_high:PWM故障检测高电平选择
 * @param  FaultDetectionWaveFilteringTime[in]: 故障检测输入信号滤波时间选择
 *          - PWM_WaveFilteringTime_0us:PWM故障检测输入信号滤波时间0us
 *          - PWM_WaveFilteringTime_1us:PWM故障检测输入信号滤波时间1us
 *          - PWM_WaveFilteringTime_4us:PWM故障检测输入信号滤波时间4us
 *          - PWM_WaveFilteringTime_16us:PWM故障检测输入信号滤波时间16us
 * @retval None
 */ 
void PWM_FaultDetectionModeConfigEX(PWM_Type_TypeDef PWM_Type,
                                    PWM_FaultDetectionMode_TypeDef FaultDetectionMode,
                                    PWM_FaultDetectionVoltageSelect_TypeDef FaultDetectionVoltageSelect,
                                    PWM_FaultDetectionWaveFilteringTime_TypeDef FaultDetectionWaveFilteringTime)
{
  if(PWM_Type == PWM0_Type)
  {
    PWMFLT = (PWMFLT & 0XC0) | FaultDetectionMode | FaultDetectionVoltageSelect |
             FaultDetectionWaveFilteringTime;
  }
}

/**
 * @brief  PWM中断配置函数-扩展版
 * @param  PWM_Type[in]: PWM源选择
 *          - PWM0_Type:操作PWM0
 *          - PWM1_Type:操作PWM1
 *          - PWM2_Type:操作PWM2
 *          - PWM3_Type:操作PWM3
 *          - PWM4_Type:操作PWM4
 * @param  NewState[in]: 中断使能/关闭选择
 *          - DISABLE:关闭
 *          - ENABLE:开启
 * @param  Priority[in]: 中断优先级选择
 *          - LOW:低
 *          - HIGH:高
 * @retval None
 */ 
void PWM_ITConfigEX(PWM_Type_TypeDef PWM_Type, FunctionalState NewState, PriorityStatus Priority)
{

  if((PWM_Type == PWM0_Type))
  {
    PWM_ITConfig(NewState, Priority);
  }
  else
  {
    TXINX = PWM_Type;

    if(NewState == DISABLE)
    {
      ET2 = 0;
    }
    else
    {
      ET2 = 1;
    }

    if(Priority == LOW)
    {
      IPT2 = 0;
    }
    else
    {
      IPT2 = 1;
    }
  }
}
#endif
/**
 * @}
 */
/* End of PWM_Group5.	*/

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */
#endif
/******************* (C) COPYRIGHT 2026 SinOne Microelectronics *****END OF FILE****/