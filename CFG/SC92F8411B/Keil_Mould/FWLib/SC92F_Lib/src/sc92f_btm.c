/**
 ******************************************************************************
 * @file    sc92f_btm.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   BTM function module
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
#include "sc92f_btm.h"

/** @addtogroup sc92f_StdPeriph_Driver
 * @{
 */

/** @defgroup BTM
 * @brief BTM driver modules
 * @{
 */

/** @defgroup BTM_Exported_Functions
 * @{
 */
 
#if defined(SC92F663x)
uint16_t xdata BTMCNT _at_ 0x102C; //BTM定时设置寄存器
#elif defined(SC92F563x)
uint16_t xdata BTMCNT _at_ 0x1038; //BTM定时设置寄存器
#endif

/** @defgroup BTM_Exported_Functions_Group1 Configuration of the BTM computation unit functions
 *  @brief   Configuration of the BTM computation unit functions
 *
 
@verbatim
 ===============================================================================
                     ##### BTM configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  Initialize the BTMx peripheral registers.
 * @param  BTM_Timebase[in]: BTM overflow time selection
 *              SC92F748x,SC92F848x,SC92F859x,SC92F759x,SC92L853x,SC92R511x,SC92F6x1x,SC92F5x1x,
 *              SC92R436,SC92R439,SC92R422A,SC92F652x,SC92F637x
 *                   Selection range(BTM_TIMEBASE_15_625MS - BTM_TIMEBASE_32S)
 *              SC92F84Hx,SC92F83Hx
 *                   Selection range(BTM_TIMEBASE_15_625MS - BTM_TIMEBASE_256S)
 *              SC92F732X
 *                   Selection range(BTM_TIMEBASE_15_625MS - BTM_TIMEBASE_2S)
 *              SC92F663x
 *                   Selection range(0 - 65535, Converted to time, it is 3.125 ms - 204.8 s)
 *              SC92F563x
 *                   Selection range(clock source LRC, 0 - 65535, Converted to time, it is 3.125 ms - 204.8 s)
 *                   Selection range(clock source LXT, 0 - 65535, Converted to time, it is 3.9 ms - 256 s)
 *              else
 *                   Selection range(BTM_TIMEBASE_15_625MS - BTM_TIMEBASE_4S)
 *                   - BTM_TIMEBASE_15_625MS:Every 15.625 milliseconds generates one interrupt.
 *                   - BTM_TIMEBASE_31_25MS:Every 31.25 milliseconds generates one interrupt.
 *                   - BTM_TIMEBASE_62_5MS:Every 62.5 milliseconds generates one interrupt.
 *                   - BTM_TIMEBASE_125MS:Every 125 milliseconds generates one interrupt.
 *                   - BTM_TIMEBASE_250MS:Every 250 milliseconds generates one interrupt.
 *                   - BTM_TIMEBASE_500MS:Every 500 milliseconds generates one interrupt.
 *                   - BTM_TIMEBASE_1S:Every 1 seconds generates one interrupt.
 *                   - BTM_TIMEBASE_2S:Every 2 seconds generates one interrupt.
 *                   - BTM_TIMEBASE_8S:Every 8 seconds generates one interrupt.
 *                   - BTM_TIMEBASE_16S:Every 16 seconds generates one interrupt.
 *                   - BTM_TIMEBASE_32S:Every 32 seconds generates one interrupt.
 *                   - BTM_TIMEBASE_64S:Every 64 seconds generates one interrupt.
 *                   - BTM_TIMEBASE_128S:Every 128 seconds generates one interrupt.
 *                   - BTM_TIMEBASE_256S:Every 256 seconds generates one interrupt.
 * @retval None
 */
#if defined(SC92F663x) || defined(SC92F563x)
void BTM_Init(uint16_t BTM_Timebase)
{
  BTMCNT = BTM_Timebase;			//configure overflow time
}
#else
void BTM_Init(BTM_Timebase_TypeDef BTM_Timebase)
{
  BTMCON = (BTMCON & 0xF0) | BTM_Timebase;			//configure overflow time
}
#endif

/**
 * @brief  Enables or disables the specified BTM peripheral.
 * @param  NewState[in]: new state of the BTMx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable 
 * @retval None
 */
void BTM_Cmd(FunctionalState NewState)
{
  if(NewState == DISABLE)
  {
    BTMCON &= 0x7f;			//Disable BTM
  }
  else
  {
    BTMCON |= 0x80;			//Enable BTM
  }
}

/**
 * @}
 */
/* End of BTM_Group1.	*/

/** @defgroup BTM_Group2 Interrupts management functions
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
 * @brief  Enables or disables the specified BTM interrupts.
 * @param  NewState[in]: new state of the BTM interrupts.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable 
 * @param  Priority[in]: priority of the BTM interrupts.
 *                  - LOW:Low priority
 *                  - HIGH:High priority
 * @retval None
 */
void BTM_ITConfig(FunctionalState NewState,
                  PriorityStatus Priority)
{
  //Interrupt configuration
  if(NewState == DISABLE)
  {
    IE1 &= 0xfb;
  }
  else
  {
    IE1 |= 0x04;
  }

  //Interrupt Priority Setting
  if(Priority == LOW)
  {
    IP1 &= 0xfb;
  }
  else
  {
    IP1 |= 0x04;
  }
}
/**
 * @}
 */
/* End of BTM_Group2.	*/

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