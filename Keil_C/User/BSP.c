/*****************************************************************************************************
 * @file    BSP.c
 * @brief   0010903139 触控板底层板级支持包实现 (芯片: SC92F8461B)
 * @details 硬件GPIO与Timer0硬件延时实现
 *****************************************************************************************************/
#include <intrins.h>
#include "BSP.h"

/**
  * @brief  设置指定端口引脚为强推挽输出
  */
void Set_GPIO_Output(uint8_t port, uint8_t pin)
{
    switch(port)
    {
        case 0:
            P0CON |= (1 << pin);
            P0PH  &= ~(1 << pin);
            break;
        case 1:
            P1CON |= (1 << pin);
            P1PH  &= ~(1 << pin);
            break;
        case 2:
            P2CON |= (1 << pin);
            P2PH  &= ~(1 << pin);
            break;
        default:
            break;
    }
}

/**
  * @brief  初始化硬件定时器 Timer0 为硬件延时模式 (16位定时器, 1T模式, Fsys=12MHz)
  */
void BSP_Timer0_Init(void)
{
    TMOD &= 0xF0;
    TMOD |= 0x01; // Timer0 Mode 1: 16位定时器
    TMCON |= 0x01; // Timer0 1T 模式 (计数时钟为 Fsys = 12MHz)
    ET0 = 0;       // 关闭中断，采用硬件查询
    TR0 = 0;
    TF0 = 0;
}

/**
  * @brief  3139 硬件引脚初始化
  *         - P0.0 (DAT): 强推挽输出，默认空闲高电平
  *         - P1.3 (L2):  强推挽输出，默认熄灭 (高电平)
  *         - P1.5 (L4):  强推挽输出，默认熄灭 (高电平)
  *         - P2.0 (TK8): 高阻输入，关闭上拉
  *         - P2.5 (TK13): 高阻输入，关闭上拉
  */
void BSP_GPIO_Init(void)
{
    // 1. P0.0 强推挽输出 (DAT 通信线)
    Set_GPIO_Output(0, 0);
    P00 = 1;

    // 2. P1.3 强推挽输出 (L2 风机/延时指示灯，低电平点亮)
    Set_GPIO_Output(1, 3);
    P13 = 1;

    // 3. P1.5 强推挽输出 (L4 照明指示灯，低电平点亮)
    Set_GPIO_Output(1, 5);
    P15 = 1;

    // 4. P2.0 (K2 / TK8) 与 P2.5 (K4 / TK13) 触摸键引脚：高阻输入，禁用内部上拉
    P2CON &= ~((1 << 0) | (1 << 5));
    P2PH  &= ~((1 << 0) | (1 << 5));
}

/**
  * @brief  精确 10us 微秒级轻量延时
  */
void Delay_10us(void)
{
    uint8_t i;
    for (i = 0; i < 24; i++)
    {
        _nop_();
    }
}

/**
  * @brief  基于 Timer0 的微秒级硬件延时 (Fsys = 12MHz, 1us = 12 ticks)
  */
void Delay_us(uint16_t us)
{
    uint16_t count;
    if (us == 0) return;

    while (us > 5000)
    {
        TL0 = (uint8_t)(65536 - 60000);
        TH0 = (uint8_t)((65536 - 60000) >> 8);
        TF0 = 0;
        TR0 = 1;
        while (!TF0);
        TR0 = 0;
        TF0 = 0;
        us -= 5000;
    }

    count = us * 12;
    if (count > 15) count -= 15;

    TL0 = (uint8_t)(65536 - count);
    TH0 = (uint8_t)((65536 - count) >> 8);
    TF0 = 0;
    TR0 = 1;
    while (!TF0);
    TR0 = 0;
    TF0 = 0;
}

/**
  * @brief  基于 Timer0 的毫秒级硬件延时 (1ms @ 12MHz = 12000 ticks)
  */
void Delay_ms(uint16_t ms)
{
    while (ms--)
    {
        // 65536 - 12000 = 53536 = 0xD120
        TL0 = 0x20;
        TH0 = 0xD1;
        TF0 = 0;
        TR0 = 1;
        while (!TF0);
        TR0 = 0;
        TF0 = 0;
    }
}