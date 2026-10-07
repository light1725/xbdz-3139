/**
 ******************************************************************************
 * @file    sc92f_gpio.c
 * @author  SOC AE Team
 * @version V1.2.5
 * @date    2026-5-15
 * @brief   GPIO function module
 *          -This document is for the SinOne 92F/93F/92L series microcontrollers.
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
#include "sc92f_gpio.h"

/** @addtogroup sc92fxxx_StdPeriph_Driver
 * @{
 */
 
 /** @defgroup GPIO
 * @brief GPIO driver modules
 * @{
 */
 
 /** @defgroup GPIO_Functions
 * @{
 */
 
 /** @defgroup GPIO_Group1 Initialization and Configuration
 *  @brief   Initialization and Configuration
 *
 
 @verbatim
 ===============================================================================
                    ##### Initialization and Configuration #####
 ===============================================================================
 
 @endverbatim
  * @{
  */
  
  /**
 * @brief  Deinitializes the GPIOx peripheral registers to their default reset
 *         values.
 * @param  None
 * @retval None
 */
void GPIO_DeInit(void)
{
  /* Deinitializes the PXCON,PXPH,and PX register to their default reset values. */
  P0CON = 0x00;
  P0PH = 0x00;
  P0 = 0;
  P1CON = 0x00;
  P1PH = 0x00;
  P1 = 0;
  P2CON = 0x00;
  P2PH = 0x00;
  P2 = 0;
  /* Deinitializes the P4CON,P4PH,and P4 register to their default reset values for the partial model. */
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
	|| defined(SC92FWxx) || defined(SC92F859x) || defined(SC92F759x) || defined (SC92R511x) || defined (SC92F663x) || defined(SC92F563x)
  P3CON = 0x00;
  P3PH = 0x00;
  P3 = 0;
  P4CON = 0x00;
  P4PH = 0x00;
  P4 = 0;
#endif
  /* Deinitializes the P5CON,P5PH,and P5 register to their default reset values for the partial model. */
#if !defined(SC92F730x) && !defined(SC92F725X) && !defined(SC92F735X) && !defined(SC92F7003) && !defined(SC92F8003) && !defined(SC92F8003B) && !defined(SC92F740x) && !defined(SC92F827X) && !defined(SC92F837X)\
	&& !defined(SC92F730x_2) && !defined(SC92F720x)&&!defined(SC92F7308B)&&!defined(SC92F5x5x)&&!defined(SC92F531x)&&!defined(SC92F637x)
  P5CON = 0x00;
  P5PH = 0x00;
  P5 = 0;
#endif
}

/**
 * @brief  Initializes the peripheral GPIOx register with the parameters specified in GPIO_InitStruct.
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral. 
 *  SC92F854x,SC92F754x,SC92F844xB,SC92F744xB,SC92F84Ax_2,SC92F74Ax_2,SC92FWxx,SC92F859x,SC92F759x,SC92R511x,SC92F663x/
 *  SC92F563x
 *               Selection range(GPIO0 - GPIO5)   
 *  SC92F730x,SC92F725X,SC92F735X,SC92F8003,SC92F8003B,SC92F740x,SC92F827X,SC92F837X,SC92F7003,SC92F730x_2,SC92F720x/
 *  SC92F7308B,SC92F5x5x,SC92F531x,SC92F637x
 *               Selection range(GPIO0 - GPIO2)
 *  else model  
 *               Selection range(GPIO0 - GPIO2,GPIO5)
 *               - GPIO0: select the GPIO0 peripheral
 *               - GPIO1: select the GPIO1 peripheral
 *               - GPIO2: select the GPIO2 peripheral
 *               - GPIO3: select the GPIO3 peripheral
 *               - GPIO4: select the GPIO4 peripheral
 *               - GPIO5: select the GPIO5 peripheral
 * @param  PortPins[in]: The input port pin value.
 *                   - GPIO_PIN_0:Pin 0 selected  
 *                   - GPIO_PIN_1:Pin 1 selected  
 *                   - GPIO_PIN_2:Pin 2 selected   
 *                   - GPIO_PIN_3:Pin 3 selected    
 *                   - GPIO_PIN_4:Pin 4 selected    
 *                   - GPIO_PIN_5:Pin 5 selected    
 *                   - GPIO_PIN_6:Pin 6 selected    
 *                   - GPIO_PIN_7:Pin 7 selected   
 *                   - GPIO_PIN_LNIB:Pin Low 4 Bits selected		 
 *                   - GPIO_PIN_HNIB:Pin High 4 Bits selected
 *                   - GPIO_PIN_All:All pins selected 
 * @param  GPIO_Mode[in]: Specifies the operating mode for the selected pins. 
 *                   - GPIO_MODE_IN_HI:GPIO High-resistance Input Mode
 *                   - GPIO_MODE_IN_PU:GPIO Pull-up Input Mode
 *                   - GPIO_MODE_OUT_PP:GPIO Strong push-pull Output Mode
 * @retval None
 */
void GPIO_Init(GPIO_TypeDef GPIOx,
               uint8_t PortPins, GPIO_Mode_TypeDef GPIO_Mode)
{
  if(GPIOx == GPIO0)
  {
    if(GPIO_Mode == GPIO_MODE_IN_HI)
    {
      /* Configure Pins to High-resistance output mode */
      P0CON &= ~PortPins;
      P0PH &= ~PortPins;
    }

    if(GPIO_Mode == GPIO_MODE_IN_PU)
    {
      /* Configure Pins to Pull-up input mode */  
      P0CON &= ~PortPins;
      P0PH |= PortPins;
    }

    if(GPIO_Mode == GPIO_MODE_OUT_PP)
    {
      /* Configure Pins to Strong push-pull output mode */  
      P0CON |= PortPins;
    }
  }
  else if(GPIOx == GPIO1)
  {
    if(GPIO_Mode == GPIO_MODE_IN_HI)
    {
      /* Configure Pins to High-resistance output mode */
      P1CON &= ~PortPins;
      P1PH &= ~PortPins;
    }

    if(GPIO_Mode == GPIO_MODE_IN_PU)
    {
      /* Configure Pins to Pull-up input mode */  
      P1CON &= ~PortPins;
      P1PH |= PortPins;
    }

    if(GPIO_Mode == GPIO_MODE_OUT_PP)
    {
      /* Configure Pins to Strong push-pull output mode */    
      P1CON |= PortPins;
    }
  }
  else if(GPIOx == GPIO2)
  {
    if(GPIO_Mode == GPIO_MODE_IN_HI)
    {
      /* Configure Pins to High-resistance output mode */
      P2CON &= ~PortPins;
      P2PH &= ~PortPins;
    }

    if(GPIO_Mode == GPIO_MODE_IN_PU)
    {
      /* Configure Pins to Pull-up input mode */  
      P2CON &= ~PortPins;
      P2PH |= PortPins;
    }

    if(GPIO_Mode == GPIO_MODE_OUT_PP)
    {
      /* Configure Pins to Strong push-pull output mode */    
      P2CON |= PortPins;
    }
  }

#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
	|| defined(SC92FWxx) || defined(SC92F859x) || defined(SC92F759x) || defined (SC92R511x) || defined (SC92F663x) || defined(SC92F563x)
  else if(GPIOx == GPIO3)
  {
    if(GPIO_Mode == GPIO_MODE_IN_HI)
    {
      /* Configure Pins to High-resistance output mode */  
      P3CON &= ~PortPins;
      P3PH &= ~PortPins;
    }

    if(GPIO_Mode == GPIO_MODE_IN_PU)
    {
      /* Configure Pins to Pull-up input mode */  
      P3CON &= ~PortPins;
      P3PH |= PortPins;
    }

    if(GPIO_Mode == GPIO_MODE_OUT_PP)
    {
      /* Configure Pins to Strong push-pull output mode */    
      P3CON |= PortPins;
    }
  }
  else if(GPIOx == GPIO4)
  {
    if(GPIO_Mode == GPIO_MODE_IN_HI)
    {
      /* Configure Pins to High-resistance output mode */  
      P4CON &= ~PortPins;
      P4PH &= ~PortPins;
    }

    if(GPIO_Mode == GPIO_MODE_IN_PU)
    {
      /* Configure Pins to Pull-up input mode */  
      P4CON &= ~PortPins;
      P4PH |= PortPins;
    }

    if(GPIO_Mode == GPIO_MODE_OUT_PP)
    {
      /* Configure Pins to Strong push-pull output mode */    
      P4CON |= PortPins;
    }
  }

#endif
#if !defined(SC92F730x) && !defined(SC92F725X) && !defined(SC92F735X) && !defined(SC92F7003) && !defined(SC92F8003) && !defined(SC92F8003B) && !defined(SC92F740x) && !defined(SC92F827X) && !defined(SC92F837X)\
	 && !defined(SC92F730x_2) && !defined(SC92F720x) &&!defined(SC92F7308B) &&!defined(SC92F5x5x) &&!defined(SC92F531x)&&!defined(SC92F637x)
  else if(GPIOx == GPIO5)
  {
    if(GPIO_Mode == GPIO_MODE_IN_HI)
    {
      /* Configure Pins to High-resistance output mode */  
      P5CON &= ~PortPins;
      P5PH &= ~PortPins;
    }

    if(GPIO_Mode == GPIO_MODE_IN_PU)
    {
      /* Configure Pins to Pull-up input mode */  
      P5CON &= ~PortPins;
      P5PH |= PortPins;
    }

    if(GPIO_Mode == GPIO_MODE_OUT_PP)
    {
      /* Configure Pins to Strong push-pull output mode */    
      P5CON |= PortPins;
    }
  }

#endif
}


 /**
 * @}
 */
 /* End of GPIO_Group1.	*/

/** @defgroup GPIO_Group2 IO operation functions
  *  @brief   GPIO Read and Write
  *
@verbatim
 ===============================================================================
                       ##### IO operation functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
 * @brief  Sets the selected data port bits.
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral. 
 *  SC92F854x,SC92F754x,SC92F844xB,SC92F744xB,SC92F84Ax_2,SC92F74Ax_2,SC92FWxx,SC92F859x,SC92F759x,SC92R511x,SC92F663x/
 *  SC92F563x
 *               Selection range(GPIO0 - GPIO5)   
 *  SC92F730x,SC92F725X,SC92F735X,SC92F8003,SC92F8003B,SC92F740x,SC92F827X,SC92F837X,SC92F7003,SC92F730x_2,SC92F720x/
 *  SC92F7308B,SC92F5x5x,SC92F531x,SC92F637x
 *               Selection range(GPIO0 - GPIO2)
 *  else model  
 *               Selection range(GPIO0 - GPIO2,GPIO5)
 *               - GPIO0: select the GPIO0 peripheral
 *               - GPIO1: select the GPIO1 peripheral
 *               - GPIO2: select the GPIO2 peripheral
 *               - GPIO3: select the GPIO3 peripheral
 *               - GPIO4: select the GPIO4 peripheral
 *               - GPIO5: select the GPIO5 peripheral
 * @param  PortVal[in]: The value of the port data register to be written.
 * @retval None
 */
void GPIO_Write(GPIO_TypeDef GPIOx,uint8_t PortVal)
{
  if(GPIOx == GPIO0)
  {
    /* Set written value to P0 port data register */  
    P0 = PortVal;
  }

  if(GPIOx == GPIO1)
  {
    /* Set written value to P1 port data register */  
    P1 = PortVal;
  }

  if(GPIOx == GPIO2)
  {
    /* Set written value to P2 port data register */    
    P2 = PortVal;
  }

#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
	|| defined(SC92FWxx) || defined(SC92F859x) || defined(SC92F759x) || defined (SC92R511x) || defined (SC92F663x) || defined(SC92F563x)

  if(GPIOx == GPIO3)
  {
    /* Set written value to P3 port data register */    
    P3 = PortVal;
  }

  if(GPIOx == GPIO4)
  {
    /* Set written value to P4 port data register */    
    P4 = PortVal;
  }

#endif
#if !defined(SC92F730x) && !defined(SC92F725X) && !defined(SC92F735X) && !defined(SC92F8003) && !defined(SC92F8003B) && !defined(SC92F740x) && !defined(SC92F827X) && !defined(SC92F837X) && !defined(SC92F7003)\
	&& !defined(SC92F730x_2) && !defined(SC92F720x) &&!defined(SC92F7308B)&&!defined(SC92F5x5x)&&!defined(SC92F531x)&&!defined(SC92F637x)

  if(GPIOx == GPIO5)
  {
    /* Set written value to P5 port data register */    
    P5 = PortVal;
  }

#endif
}

/**
 * @brief  Sets the selected data port bits.
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral. 
 *  SC92F854x,SC92F754x,SC92F844xB,SC92F744xB,SC92F84Ax_2,SC92F74Ax_2,SC92FWxx,SC92F859x,SC92F759x,SC92R511x,SC92F663x/
 *  SC92F563x
 *               Selection range(GPIO0 - GPIO5)   
 *  SC92F730x,SC92F725X,SC92F735X,SC92F8003,SC92F8003B,SC92F740x,SC92F827X,SC92F837X,SC92F7003,SC92F730x_2,SC92F720x/
 *  SC92F7308B,SC92F5x5x,SC92F531x,SC92F637x
 *               Selection range(GPIO0 - GPIO2)
 *  else model  
 *               Selection range(GPIO0 - GPIO2,GPIO5)
 *               - GPIO0: select the GPIO0 peripheral
 *               - GPIO1: select the GPIO1 peripheral
 *               - GPIO2: select the GPIO2 peripheral
 *               - GPIO3: select the GPIO3 peripheral
 *               - GPIO4: select the GPIO4 peripheral
 *               - GPIO5: select the GPIO5 peripheral
 * @param  GPIO_Pin[in]: specifies the port bit to be written.
 *                   - GPIO_PIN_0:Pin 0 selected  
 *                   - GPIO_PIN_1:Pin 1 selected  
 *                   - GPIO_PIN_2:Pin 2 selected   
 *                   - GPIO_PIN_3:Pin 3 selected    
 *                   - GPIO_PIN_4:Pin 4 selected    
 *                   - GPIO_PIN_5:Pin 5 selected    
 *                   - GPIO_PIN_6:Pin 6 selected    
 *                   - GPIO_PIN_7:Pin 7 selected 
 *                   - GPIO_PIN_LNIB:Pin Low 4 Bits selected		 
 *                   - GPIO_PIN_HNIB:Pin High 4 Bits selected
 *                   - GPIO_PIN_All:All pins selected 
 * @retval None
 */
void GPIO_WriteHigh(GPIO_TypeDef GPIOx,
                    uint8_t PortPins)
{
  if(GPIOx == GPIO0)
  {
          if((PortPins&0x01))
          {   
            IO00 = 1;
          }
				  if((PortPins&0x02))
	        {   
            IO01 = 1;
          }	
				  if((PortPins&0x04))
	        {   
            IO02 = 1;
          }	
				  if((PortPins&0x08))
	        {   
            IO03 = 1;
          }	
					if((PortPins&0x10))
	        {   
            IO04 = 1;
          }	
				  if((PortPins&0x20))
	        {   
            IO05 = 1;
          }	
					if((PortPins&0x40))
	        {   
            IO06 = 1;
          }
					if((PortPins&0x80))
	        {   
            IO07 = 1;
          }	
  }

  if(GPIOx == GPIO1)
  {
          if((PortPins&0x01))
          {   
            IO10 = 1;
          }
				  if((PortPins&0x02))
	        {   
            IO11 = 1;
          }	
				  if((PortPins&0x04))
	        {   
            IO12 = 1;
          }	
				  if((PortPins&0x08))
	        {   
            IO13 = 1;
          }	
					if((PortPins&0x10))
	        {   
            IO14 = 1;
          }	
				  if((PortPins&0x20))
	        {   
            IO15 = 1;
          }	
					if((PortPins&0x40))
	        {   
            IO16 = 1;
          }
					if((PortPins&0x80))
	        {   
            IO17 = 1;
          }	
  }

  if(GPIOx == GPIO2)
  {
          if((PortPins&0x01))
          {   
            IO20 = 1;
          }
				  if((PortPins&0x02))
	        {   
            IO21 = 1;
          }	
				  if((PortPins&0x04))
	        {   
            IO22 = 1;
          }	
				  if((PortPins&0x08))
	        {   
            IO23 = 1;
          }	
					if((PortPins&0x10))
	        {   
            IO24 = 1;
          }	
				  if((PortPins&0x20))
	        {   
            IO25 = 1;
          }	
					if((PortPins&0x40))
	        {   
            IO26 = 1;
          }
					if((PortPins&0x80))
	        {   
            IO27 = 1;
          }	
  }

#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
	|| defined(SC92FWxx) || defined(SC92F859x) || defined(SC92F759x) || defined (SC92R511x) || defined(SC92F663x) || defined(SC92F563x)

  if(GPIOx == GPIO3)
  {
          if((PortPins&0x01))
          {   
            IO30 = 1;
          }
				  if((PortPins&0x02))
	        {   
            IO31 = 1;
          }	
				  if((PortPins&0x04))
	        {   
            IO32 = 1;
          }	
				  if((PortPins&0x08))
	        {   
            IO33 = 1;
          }	
					if((PortPins&0x10))
	        {   
            IO34 = 1;
          }	
				  if((PortPins&0x20))
	        {   
            IO35 = 1;
          }	
					if((PortPins&0x40))
	        {   
            IO36 = 1;
          }
					if((PortPins&0x80))
	        {   
            IO37 = 1;
          }	
  }

  if(GPIOx == GPIO4)
  {
          if((PortPins&0x01))
          {   
            IO40 = 1;
          }
				  if((PortPins&0x02))
	        {   
            IO41 = 1;
          }	
				  if((PortPins&0x04))
	        {   
            IO42 = 1;
          }	
				  if((PortPins&0x08))
	        {   
            IO43 = 1;
          }	
					if((PortPins&0x10))
	        {   
            IO44 = 1;
          }	
				  if((PortPins&0x20))
	        {   
            IO45 = 1;
          }	
					if((PortPins&0x40))
	        {   
            IO46 = 1;
          }
					if((PortPins&0x80))
	        {   
            IO47 = 1;
          }
  }

#endif
#if !defined(SC92F730x) && !defined(SC92F725X) && !defined(SC92F735X) && !defined(SC92F8003) && !defined(SC92F8003B) && !defined(SC92F740x) && !defined(SC92F827X) && !defined(SC92F837X) && !defined(SC92F7003)\
	&& !defined(SC92F730x_2) && !defined(SC92F720x) && !defined(SC92F7308B) && !defined(SC92F5x5x) && !defined(SC92F531x) && !defined(SC92F637x)

  if(GPIOx == GPIO5)
  {
          if((PortPins&0x01))
          {   
            IO50 = 1;
          }
				  if((PortPins&0x02))
	        {   
            IO51 = 1;
          }	
				  if((PortPins&0x04))
	        {   
            IO52 = 1;
          }	
				  if((PortPins&0x08))
	        {   
            IO53 = 1;
          }	
					if((PortPins&0x10))
	        {   
            IO54 = 1;
          }	
				  if((PortPins&0x20))
	        {   
            IO55 = 1;
          }	
  }

#endif
}

/**
 * @brief  Clears the specified data port bit.
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral. 
 *  SC92F854x,SC92F754x,SC92F844xB,SC92F744xB,SC92F84Ax_2,SC92F74Ax_2,SC92FWxx,SC92F859x,SC92F759x,SC92R511x,SC92F663x/
 *  SC92F563x
 *               Selection range(GPIO0 - GPIO5)   
 *  SC92F730x,SC92F725X,SC92F735X,SC92F8003,SC92F8003B,SC92F740x,SC92F827X,SC92F837X,SC92F7003,SC92F730x_2,SC92F720x/
 *  SC92F7308B,SC92F5x5x,SC92F531x,SC92F637x
 *               Selection range(GPIO0 - GPIO2)
 *  else model  
 *               Selection range(GPIO0 - GPIO2,GPIO5)
 *               - GPIO0: select the GPIO0 peripheral
 *               - GPIO1: select the GPIO1 peripheral
 *               - GPIO2: select the GPIO2 peripheral
 *               - GPIO3: select the GPIO3 peripheral
 *               - GPIO4: select the GPIO4 peripheral
 *               - GPIO5: select the GPIO5 peripheral
 * @param  PortPins[in]: specifies the port bit to be written.
 *                   - GPIO_PIN_0:Pin 0 selected  
 *                   - GPIO_PIN_1:Pin 1 selected  
 *                   - GPIO_PIN_2:Pin 2 selected   
 *                   - GPIO_PIN_3:Pin 3 selected    
 *                   - GPIO_PIN_4:Pin 4 selected    
 *                   - GPIO_PIN_5:Pin 5 selected    
 *                   - GPIO_PIN_6:Pin 6 selected    
 *                   - GPIO_PIN_7:Pin 7 selected 
 *                   - GPIO_PIN_LNIB:Pin Low 4 Bits selected		 
 *                   - GPIO_PIN_HNIB:Pin High 4 Bits selected
 *                   - GPIO_PIN_All:All pins selected 
 * @retval None
 */
void GPIO_WriteLow(GPIO_TypeDef GPIOx,
                   uint8_t PortPins)
{
  if(GPIOx == GPIO0)
  {
		      if((PortPins&0x01))
          {   
            IO00 = 0;
          }
				  if((PortPins&0x02))
	        {   
            IO01 = 0;
          }	
				  if((PortPins&0x04))
	        {   
            IO02 = 0;
          }	
				  if((PortPins&0x08))
	        {   
            IO03 = 0;
          }	
					if((PortPins&0x10))
	        {   
            IO04 = 0;
          }	
				  if((PortPins&0x20))
	        {   
            IO05 = 0;
          }	
					if((PortPins&0x40))
	        {   
            IO06 = 0;
          }
					if((PortPins&0x80))
	        {   
            IO07 = 0;
          }
  }

  if(GPIOx == GPIO1)
  {
		      if((PortPins&0x01))
          {   
            IO10 = 0;
          }
				  if((PortPins&0x02))
	        {   
            IO11 = 0;
          }	
				  if((PortPins&0x04))
	        {   
            IO12 = 0;
          }	
				  if((PortPins&0x08))
	        {   
            IO13 = 0;
          }	
					if((PortPins&0x10))
	        {   
            IO14 = 0;
          }	
				  if((PortPins&0x20))
	        {   
            IO15 = 0;
          }	
					if((PortPins&0x40))
	        {   
            IO16 = 0;
          }
					if((PortPins&0x80))
	        {   
            IO17 = 0;
          }
  }

  if(GPIOx == GPIO2)
  {
		 		 if((PortPins&0x01))
          {   
            IO20 = 0;
          }
				  if((PortPins&0x02))
	        {   
            IO21 = 0;
          }	
				  if((PortPins&0x04))
	        {   
            IO22 = 0;
          }	
				  if((PortPins&0x08))
	        {   
            IO23 = 0;
          }	
					if((PortPins&0x10))
	        {   
            IO24 = 0;
          }	
				  if((PortPins&0x20))
	        {   
            IO25 = 0;
          }	
					if((PortPins&0x40))
	        {   
            IO26 = 0;
          }
					if((PortPins&0x80))
	        {   
            IO27 = 0;
          }
  }

#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
	|| defined(SC92FWxx) || defined(SC92F859x) || defined(SC92F759x) || defined (SC92R511x) || defined(SC92F663x) || defined(SC92F563x)

  if(GPIOx == GPIO3)
  {
		      if((PortPins&0x01))
          {   
            IO30 = 0;
          }
				  if((PortPins&0x02))
	        {   
            IO31 = 0;
          }	
				  if((PortPins&0x04))
	        {   
            IO32 = 0;
          }	
				  if((PortPins&0x08))
	        {   
            IO33 = 0;
          }	
					if((PortPins&0x10))
	        {   
            IO34 = 0;
          }	
				  if((PortPins&0x20))
	        {   
            IO35 = 0;
          }	
					if((PortPins&0x40))
	        {   
            IO36 = 0;
          }
					if((PortPins&0x80))
	        {   
            IO37 = 0;
          }
  }

  if(GPIOx == GPIO4)
  {
		      if((PortPins&0x01))
          {   
            IO40 = 0;
          }
				  if((PortPins&0x02))
	        {   
            IO41 = 0;
          }	
				  if((PortPins&0x04))
	        {   
            IO42 = 0;
          }	
				  if((PortPins&0x08))
	        {   
            IO43 = 0;
          }	
					if((PortPins&0x10))
	        {   
            IO44 = 0;
          }	
				  if((PortPins&0x20))
	        {   
            IO45 = 0;
          }	
					if((PortPins&0x40))
	        {   
            IO46 = 0;
          }
					if((PortPins&0x80))
	        {   
            IO47 = 0;
          }
  }

#endif
#if !defined(SC92F730x) && !defined(SC92F725X) && !defined(SC92F735X) && !defined(SC92F8003) && !defined(SC92F8003B) && !defined(SC92F740x) && !defined(SC92F827X) && !defined(SC92F837X) && !defined(SC92F7003)\
  	&& !defined(SC92F730x_2) && !defined(SC92F720x)&&!defined(SC92F7308B)&&!defined(SC92F5x5x)&&!defined(SC92F531x) && !defined(SC92F637x)

  if(GPIOx == GPIO5)
  {
		      if((PortPins&0x01))
          {   
            IO50 = 0;
          }
				  if((PortPins&0x02))
	        {   
            IO51 = 0;
          }	
				  if((PortPins&0x04))
	        {   
            IO52 = 0;
          }	
				  if((PortPins&0x08))
	        {   
            IO53 = 0;
          }	
					if((PortPins&0x10))
	        {   
            IO54 = 0;
          }	
				  if((PortPins&0x20))
	        {   
            IO55 = 0;
          }
  }

#endif
}

/**
 * @brief  Reads the specified input port pin.
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral. 
 *  SC92F854x,SC92F754x,SC92F844xB,SC92F744xB,SC92F84Ax_2,SC92F74Ax_2,SC92FWxx,SC92F859x,SC92F759x,SC92R511x,SC92F663x/
 *  SC92F563x
 *               Selection range(GPIO0 - GPIO5)   
 *  SC92F730x,SC92F725X,SC92F735X,SC92F8003,SC92F8003B,SC92F740x,SC92F827X,SC92F837X,SC92F7003,SC92F730x_2,SC92F720x/
 *  SC92F7308B,SC92F5x5x,SC92F531x,SC92F637x
 *               Selection range(GPIO0 - GPIO2)
 *  else model  
 *               Selection range(GPIO0 - GPIO2,GPIO5)
 *               - GPIO0: select the GPIO0 peripheral
 *               - GPIO1: select the GPIO1 peripheral
 *               - GPIO2: select the GPIO2 peripheral
 *               - GPIO3: select the GPIO3 peripheral
 *               - GPIO4: select the GPIO4 peripheral
 *               - GPIO5: select the GPIO5 peripheral
 * @retval The input port pin value.
 */
uint8_t GPIO_ReadPort(GPIO_TypeDef GPIOx)
{
  if(GPIOx == GPIO0)
  {
    return P0;
  }
  else if(GPIOx == GPIO1)
  {
    return P1;
  }
  else if(GPIOx == GPIO2)
  {
    return P2;
  }

#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
	|| defined(SC92FWxx) || defined(SC92F859x) || defined(SC92F759x) || defined (SC92R511x) || defined(SC92F663x) || defined(SC92F563x)
  else if(GPIOx == GPIO3)
  {
    return P3;
  }
  else if(GPIOx == GPIO4)
  {
    return P4;
  }

#endif
#if !defined(SC92F730x) && !defined(SC92F725X) && !defined(SC92F735X) && !defined(SC92F8003) && !defined(SC92F8003B) && !defined(SC92F740x) && !defined(SC92F827X) && !defined(SC92F837X) && !defined(SC92F7003)\
	&& !defined(SC92F730x_2) && !defined(SC92F720x) &&!defined(SC92F7308B) &&!defined(SC92F5x5x) &&!defined(SC92F531x) && !defined(SC92F637x)
  else if(GPIOx == GPIO5)
  {
    return P5;
  }

#endif
  else
  {
    return 0;
  }
}


/**
 * @brief  Reads the selected data port bits.
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral. 
 *  SC92F854x,SC92F754x,SC92F844xB,SC92F744xB,SC92F84Ax_2,SC92F74Ax_2,SC92FWxx,SC92F859x,SC92F759x,SC92R511x,SC92F663x/
 *  SC92F563x
 *               Selection range(GPIO0 - GPIO5)   
 *  SC92F730x,SC92F725X,SC92F735X,SC92F8003,SC92F8003B,SC92F740x,SC92F827X,SC92F837X,SC92F7003,SC92F730x_2,SC92F720x/
 *  SC92F7308B,SC92F5x5x,SC92F531x,SC92F637x
 *               Selection range(GPIO0 - GPIO2)
 *  else model  
 *               Selection range(GPIO0 - GPIO2,GPIO5)
 *               - GPIO0: select the GPIO0 peripheral
 *               - GPIO1: select the GPIO1 peripheral
 *               - GPIO2: select the GPIO2 peripheral
 *               - GPIO3: select the GPIO3 peripheral
 *               - GPIO4: select the GPIO4 peripheral
 *               - GPIO5: select the GPIO5 peripheral
 * @param  PortPins[in]: specifies the port bit to be written.
 *                   - GPIO_PIN_0:Pin 0 selected  
 *                   - GPIO_PIN_1:Pin 1 selected  
 *                   - GPIO_PIN_2:Pin 2 selected   
 *                   - GPIO_PIN_3:Pin 3 selected    
 *                   - GPIO_PIN_4:Pin 4 selected    
 *                   - GPIO_PIN_5:Pin 5 selected    
 *                   - GPIO_PIN_6:Pin 6 selected    
 *                   - GPIO_PIN_7:Pin 7 selected 
 *                   - GPIO_PIN_LNIB:Pin Low 4 Bits selected		 
 *                   - GPIO_PIN_HNIB:Pin High 4 Bits selected
 *                   - GPIO_PIN_All:All pins selected 
 * @retval Bit state
 *              - Bit_RESET 
 *              - Bit_SET
 */
BitStatus GPIO_ReadPin(GPIO_TypeDef GPIOx,
                       uint8_t PortPins)
{
  BitStatus TempBitstatus;
  switch(GPIOx)
  {
    case GPIO0:
      TempBitstatus = (P0 & PortPins);
		  break;
    case GPIO1:
      TempBitstatus = (P1 & PortPins);
		  break;
    case GPIO2:
      TempBitstatus = (P2 & PortPins);
		  break;
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
	|| defined(SC92FWxx) || defined(SC92F859x) || defined(SC92F759x) || defined (SC92R511x) || defined(SC92F663x) || defined(SC92F563x)
    case GPIO3:
      TempBitstatus = (P3 & PortPins);
		  break;
    case GPIO4:
      TempBitstatus = (P4 & PortPins);
		  break;
#endif
#if !defined(SC92F730x) && !defined(SC92F725X) && !defined(SC92F735X) && !defined(SC92F8003) && !defined(SC92F8003B) && !defined(SC92F740x) && !defined(SC92F827X) && !defined(SC92F837X) && !defined(SC92F7003)\
		&& !defined(SC92F730x_2) && !defined(SC92F720x) &&! defined(SC92F7308B) &&!defined(SC92F5x5x) &&!defined(SC92F531x) && !defined(SC92F637x)
    case GPIO5:
      TempBitstatus = (P5 & PortPins);
		  break;
#endif
    default:
      TempBitstatus = RESET;
		  break;
  }

  if(TempBitstatus != RESET)
    return SET;
  else
    return RESET;
}

/**
 * @brief  Toggles the specified GPIO pins.
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral. 
 *  SC92F854x,SC92F754x,SC92F844xB,SC92F744xB,SC92F84Ax_2,SC92F74Ax_2,SC92FWxx,SC92F859x,SC92F759x,SC92R511x,SC92F663x/
 *  SC92F563x
 *               Selection range(GPIO0 - GPIO5)   
 *  SC92F730x,SC92F725X,SC92F735X,SC92F8003,SC92F8003B,SC92F740x,SC92F827X,SC92F837X,SC92F7003,SC92F730x_2,SC92F720x/
 *  SC92F7308B,SC92F5x5x,SC92F531x,SC92F637x
 *               Selection range(GPIO0 - GPIO2)
 *  else model  
 *               Selection range(GPIO0 - GPIO2,GPIO5)
 *               - GPIO0: select the GPIO0 peripheral
 *               - GPIO1: select the GPIO1 peripheral
 *               - GPIO2: select the GPIO2 peripheral
 *               - GPIO3: select the GPIO3 peripheral
 *               - GPIO4: select the GPIO4 peripheral
 *               - GPIO5: select the GPIO5 peripheral
 * @param  PortPins[in]: specifies the port bit to be written.
 *                   - GPIO_PIN_0:Pin 0 selected  
 *                   - GPIO_PIN_1:Pin 1 selected  
 *                   - GPIO_PIN_2:Pin 2 selected   
 *                   - GPIO_PIN_3:Pin 3 selected    
 *                   - GPIO_PIN_4:Pin 4 selected    
 *                   - GPIO_PIN_5:Pin 5 selected    
 *                   - GPIO_PIN_6:Pin 6 selected    
 *                   - GPIO_PIN_7:Pin 7 selected 
 *                   - GPIO_PIN_LNIB:Pin Low 4 Bits selected		 
 *                   - GPIO_PIN_HNIB:Pin High 4 Bits selected
 *                   - GPIO_PIN_All:All pins selected 
 * @retval None
 */
void GPIO_TogglePin(GPIO_TypeDef GPIOx, uint8_t PortPins)
{
  switch(GPIOx)
  {
    case GPIO0:
		{
			 if((PortPins&0x01))
          {   
            IO00 = ~IO00;
          }
				  if((PortPins&0x02))
	        {   
            IO01 = ~IO01;
          }	
				  if((PortPins&0x04))
	        {   
            IO02 = ~IO02;
          }	
				  if((PortPins&0x08))
	        {   
            IO03 = ~IO03;
          }	
					if((PortPins&0x10))
	        {   
            IO04 = ~IO04;
          }	
				  if((PortPins&0x20))
	        {   
            IO05 = ~IO05;
          }	
					if((PortPins&0x40))
	        {   
            IO06 = ~IO06;
          }
					if((PortPins&0x80))
	        {   
            IO07 = ~IO07;
          }	
		}
      break;
    case GPIO1:
		{
			 if((PortPins&0x01))
          {   
            IO10 = ~IO10;
          }
				  if((PortPins&0x02))
	        {   
            IO11 = ~IO11;
          }	
				  if((PortPins&0x04))
	        {   
            IO12 = ~IO12;
          }	
				  if((PortPins&0x08))
	        {   
            IO13 = ~IO13;
          }	
					if((PortPins&0x10))
	        {   
            IO14 = ~IO14;
          }	
				  if((PortPins&0x20))
	        {   
            IO15 = ~IO15;
          }	
					if((PortPins&0x40))
	        {   
            IO16 = ~IO16;
          }
					if((PortPins&0x80))
	        {   
            IO17 = ~IO17;
          }	
		}
      break;
    case GPIO2:
		{
			 if((PortPins&0x01))
          {   
            IO20 = ~IO20;
          }
				  if((PortPins&0x02))
	        {   
            IO21 = ~IO21;
          }	
				  if((PortPins&0x04))
	        {   
            IO22 = ~IO22;
          }	
				  if((PortPins&0x08))
	        {   
            IO23 = ~IO23;
          }	
					if((PortPins&0x10))
	        {   
            IO24 = ~IO24;
          }	
				  if((PortPins&0x20))
	        {   
            IO25 = ~IO25;
          }	
					if((PortPins&0x40))
	        {   
            IO26 = ~IO26;
          }
					if((PortPins&0x80))
	        {   
           IO27 = ~IO27;
          }	
		}
      break;
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
	|| defined(SC92FWxx) || defined(SC92F859x) || defined(SC92F759x) || defined (SC92R511x) || defined(SC92F663x) || defined(SC92F563x)
    case GPIO3:
    		{
			 if((PortPins&0x01))
          {   
            IO30 = ~IO30;
          }
				  if((PortPins&0x02))
	        {   
            IO31 = ~IO31;
          }	
				  if((PortPins&0x04))
	        {   
            IO32 = ~IO32;
          }	
				  if((PortPins&0x08))
	        {   
            IO33 = ~IO33;
          }	
					if((PortPins&0x10))
	        {   
            IO34 = ~IO34;
          }	
				  if((PortPins&0x20))
	        {   
            IO35 = ~IO35;
          }	
					if((PortPins&0x40))
	        {   
            IO36 = ~IO36;
          }
					if((PortPins&0x80))
	        {   
            IO37 = ~IO37;
          }	
		}
      break;
    case GPIO4:
    {
			 if((PortPins&0x01))
          {   
            IO40 = ~IO40;
          }
				  if((PortPins&0x02))
	        {   
            IO41 = ~IO41;
          }	
				  if((PortPins&0x04))
	        {   
            IO42 = ~IO42;
          }	
				  if((PortPins&0x08))
	        {   
            IO43 = ~IO43;
          }	
					if((PortPins&0x10))
	        {   
            IO44 = ~IO44;
          }	
				  if((PortPins&0x20))
	        {   
            IO45 = ~IO45;
          }	
					if((PortPins&0x40))
	        {   
            IO46 = ~IO46;
          }
					if((PortPins&0x80))
	        {   
            IO47 = ~IO47;
          }	
		}
      break;
#endif
#if !defined(SC92F730x) && !defined(SC92F725X) && !defined(SC92F735X) && !defined(SC92F8003) && !defined(SC92F8003B) && !defined(SC92F7003) && !defined(SC92F740x)\
		&& !defined(SC92F730x_2) && !defined(SC92F720x) && !defined(SC92F827X) && !defined(SC92F837X)&& !defined(SC92F7308B) &&!defined(SC92F5x5x) &&!defined(SC92F531x)\
		&& !defined(SC92F637x)
    case GPIO5:
      {
			 if((PortPins&0x01))
          {   
            IO50 = ~IO50;
          }
				  if((PortPins&0x02))
	        {   
            IO51 = ~IO51;
          }	
				  if((PortPins&0x04))
	        {   
            IO52 = ~IO52;
          }	
				  if((PortPins&0x08))
	        {   
            IO53 = ~IO53;
          }	
					if((PortPins&0x10))
	        {   
            IO54 = ~IO54;
          }	
				  if((PortPins&0x20))
	        {   
            IO55 = ~IO55;
          }	

		}
      break;
#endif
    default:
      break;
  }
}


/**
 * @brief  Sets the I/O driver level 
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral. 
 *  SC92F854x,SC92F754x,SC92F844xB,SC92F744xB,SC92F84Ax_2,SC92F74Ax_2,SC92FWxx,SC92F859x,SC92F759x,SC92R511x
 *               Selection range(GPIO0 - GPIO5)   
 *  SC92F730x,SC92F725X,SC92F735X,SC92F8003,SC92F8003B,SC92F740x,SC92F827X,SC92F837X,SC92F7003,SC92F730x_2,SC92F720x/
 *  SC92F7308B
 *               Selection range(GPIO0 - GPIO2)
 *  else model  
 *               Selection range(GPIO0 - GPIO2,GPIO5)
 *               - GPIO0: select the GPIO0 peripheral
 *               - GPIO1: select the GPIO1 peripheral
 *               - GPIO2: select the GPIO2 peripheral
 *               - GPIO3: select the GPIO3 peripheral
 *               - GPIO4: select the GPIO4 peripheral
 *               - GPIO5: select the GPIO5 peripheral
 * @param  PortPins[in]: The input port pin value.
 *                   - GPIO_PIN_0:Pin 0 selected  
 *                   - GPIO_PIN_1:Pin 1 selected  
 *                   - GPIO_PIN_2:Pin 2 selected   
 *                   - GPIO_PIN_3:Pin 3 selected    
 *                   - GPIO_PIN_4:Pin 4 selected    
 *                   - GPIO_PIN_5:Pin 5 selected    
 *                   - GPIO_PIN_6:Pin 6 selected    
 *                   - GPIO_PIN_7:Pin 7 selected  
 *                   - GPIO_PIN_LNIB:Pin Low 4 Bits selected		 
 *                   - GPIO_PIN_HNIB:Pin High 4 Bits selected
 *                   - GPIO_PIN_All:All pins selected 
 * @param  GPIO_DriveLevel[in]: specifies the operating Drive Level for the selected pins.
 *                  - IOH_Grade_0:I/O output Drive: Level 0(Max) 
 *                  - IOH_Grade_1:I/O output Drive: Level 1 
 *                  - IOH_Grade_2:I/O output Drive: Level 2 
 *                  - IOH_Grade_3:I/O output Drive: Level 3    
 * @retval None
 */
#if !defined(SC92F7003) && !defined(SC92F8003) && !defined(SC92F8003B) && !defined(SC92F740x)&& !defined(SC92F6x1x) && !defined(SC92F5x1x)&& !defined(SC92R436)&& !defined(SC92R439)&& !defined(SC92R438)\
     && !defined(SC92L840x)&& !defined(SC92R422A)&& !defined(SC92F652x)&& !defined(SC92R51x_R52x) && !defined(SC92F552x)&& !defined(SC92F5x5x)&& !defined(SC92F531x)&& !defined(SC92F637x)\
		 && !defined(SC92F663x) && !defined(SC92F563x)
void GPIO_IOH_Config(GPIO_TypeDef GPIOx, GPIO_Pin_TypeDef PortPins, GPIO_IOH_Grade_TypeDef GPIO_IOH_Grade)
{
#if defined(SC92F854x) || defined(SC92F754x) || defined(SC92F844xB) || defined(SC92F744xB) || defined(SC92F84Ax_2) || defined(SC92F74Ax_2)\
		|| defined(SC92FWxx) || defined(SC92F859x) || defined(SC92F759x)  || defined (SC92L853x) || defined (SC92L753x) || defined (SC92R511x)\
	  || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)
  switch(GPIOx)
  {
    case GPIO0:
      if(PortPins == GPIO_PIN_LNIB)
      {
        IOHCON0 &= 0xFC;
        IOHCON0 |= GPIO_IOH_Grade;
      }
      else if(PortPins == GPIO_PIN_HNIB)
      {
        IOHCON0 &= 0xF3;
        IOHCON0 |= GPIO_IOH_Grade << 2;
      }
      break;
    case GPIO1:
      if(PortPins == GPIO_PIN_LNIB)
      {
        IOHCON0 &= 0xCF;
        IOHCON0 |= GPIO_IOH_Grade << 4;
      }
      else if(PortPins == GPIO_PIN_HNIB)
      {
        IOHCON0 &= 0x3F;
        IOHCON0 |= GPIO_IOH_Grade << 6;
      }
      break;
    case GPIO2:
      if(PortPins == GPIO_PIN_LNIB)
      {
        IOHCON1 &= 0xFC;
        IOHCON1 |= GPIO_IOH_Grade;
      }
      else if(PortPins == GPIO_PIN_HNIB)
      {
        IOHCON1 &= 0xF3;
        IOHCON1 |= GPIO_IOH_Grade << 2;
      }
      break;
#if defined (SC92L853x) || defined (SC92L753x) || defined(SC92F646x) || defined(SC92F546x) || defined(SC92F542x)
    case GPIO5:
      if(PortPins == GPIO_PIN_LNIB)
      {
        IOHCON1 &= 0xCF;
        IOHCON1 |= GPIO_IOH_Grade << 4;
      }
      else if(PortPins == GPIO_PIN_HNIB)
      {
        IOHCON1 &= 0x3f;
        IOHCON1 |= GPIO_IOH_Grade << 6;
      }
      break;
#else
    case GPIO3:
      if(PortPins == GPIO_PIN_LNIB)
      {
        IOHCON1 &= 0xCF;
        IOHCON1 |= GPIO_IOH_Grade << 4;
      }
      break;
#endif
    default:
      break;
  }
#else
  switch(GPIOx)
  {
    case GPIO0:
      if(PortPins == GPIO_PIN_LNIB)
      {
        IOHCON &= 0xFC;
        IOHCON |= GPIO_IOH_Grade;
      }
      else if(PortPins == GPIO_PIN_HNIB)
      {
        IOHCON &= 0xF3;
        IOHCON |= GPIO_IOH_Grade << 2;
      }
      break;
    case GPIO2:
      if(PortPins == GPIO_PIN_LNIB)
      {
        IOHCON &= 0xCF;
        IOHCON |= GPIO_IOH_Grade << 4;
      }
      else if(PortPins == GPIO_PIN_HNIB)
      {
        IOHCON &= 0x3F;
        IOHCON |= GPIO_IOH_Grade << 6;
      }
      break;
    default:
      break;
  }
#endif
}
#endif
/**
 * @}
 */
/* End of GPIO_Group2.	*/


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
