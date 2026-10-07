/*--------------------------------------------------------------------------
SC92F637X_C.H

C Header file for SC92F637X microcontroller.
Copyright (c) 2025 Shenzhen SinOne Microelectronics Co., Ltd.
All rights reserved.
深圳市赛元微电子股份有限公司
版本号:  V1.0    
日期  :  2025/8/20
--------------------------------------------------------------------------*/
#ifndef _SC92F637X_H_
#define _SC92F637X_H_

///* ------------------- 字节寄存器-------------------- */
/*CPU*/
sfr   SP       = 0X81;  //堆栈指针
sfr   DPL      = 0X82;  //DPTR数据指针低位
sfr   DPH      = 0X83;  //DPTR数据指针高位
sfr   PSW      = 0XD0;  //程序状态字寄存器	
sfr   ACC      = 0XE0;  //累加器Ａ	
sfr   B        = 0XF0;  //B寄存器	

/*system*/
sfr   PCON     = 0X87;  //电源管理控制寄存器

/*Interrupt*/
sfr   IE       = 0XA8;  //中断控制寄存器
sfr   IE1      = 0XA9;  //中断控制寄存器1
sfr   IP       = 0XB8;  //中断优先权控制寄存器
sfr   IP1      = 0XB9;  //中断优先级控制寄存器1

/*PORT*/
sfr   P0       = 0X80;  //P0口数据寄存器
sfr   P1       = 0X90;  //P1口数据寄存器
sfr	  P1CON	   = 0X91;  //P1口输入/输出控制寄存器
sfr   P1PH	   = 0X92;  //P1口上拉电阻控制寄存器	
sfr	  P0CON	   = 0X9A;  //P0口输入/输出控制寄存器	
sfr	  P0PH	   = 0X9B;  //P0口上拉电阻控制寄存器
sfr   P2       = 0XA0;  //P2口数据寄存器
sfr	  P2CON	   = 0XA1;  //P2口输入/输出控制寄存器	
sfr   P2PH	   = 0XA2;  //P2口上拉电阻控制寄存器	

/*TIMER*/	
sfr   TCON     = 0X88;  //定时器控制寄存器
sfr   TMOD     = 0X89;  //定时器工作模式寄存器
sfr   TL0      = 0X8A;  //定时器0低8位
sfr   TL1      = 0X8B;  //定时器1低8位
sfr   TH0      = 0X8C;  //定时器0高8位
sfr   TH1      = 0X8D;  //定时器1高8位
sfr   TMCON    = 0X8E;  //定时器频率控制寄存器
sfr   TXINX    = 0XCE;  //定时器X控制寄存器指针
sfr   TXCON    = 0XC8;  //定时器X控制寄存器
sfr   TXMOD    = 0XC9;  //定时器X工作模式寄存器
sfr   RCAPXL   = 0XCA;  //定时器X重载/捕捉低8位
sfr   RCAPXH   = 0XCB;  //定时器X重载/捕捉高8位
sfr   TLX      = 0XCC;  //定时器X低8位
sfr   THX      = 0XCD;  //定时器X高8位

/*WatchDog*/
sfr   WDTCON   = 0XCF;  //WDT控制寄存器

/*BTM*/
sfr	  BTMCON   = 0XFB;  //低频定时器控制寄存器

/*INT*/
sfr   INT0F    = 0XBA;  //INT0 下降沿中断控制寄存器
sfr   INT0R    = 0XBB;  //INT0 上降沿中断控制寄存器
sfr   INT1F    = 0XBC;  //INT1 下降沿中断控制寄存器
sfr   INT1R    = 0XBD;  //INT1 上降沿中断控制寄存器

/*IAP */
sfr   IAPKEY   = 0XF1;  //IAP保护寄存器
sfr   IAPAD    = 0XF2;  //IAP写入地址寄存器
sfr   IAPADE   = 0XF4;  //IAP扩展地址寄存器
sfr   IAPDAT   = 0XF5;  //IAP数据寄存器
sfr   IAPCTL   = 0XF6;  //IAP控制寄存器

/*SSI*/
sfr   OTCON    = 0X8F;  //输出控制寄存器
sfr   SSCON2   = 0X95;  //SSI控制寄存器2
sfr   SSCON0   = 0X9D;  //SSI控制寄存器0
sfr   SSCON1   = 0X9E;  //SSI控制寄存器1
sfr   SSDAT    = 0X9F;  //SSI数据寄存器

/*OPTION*/
sfr   OPINX    = 0XFE;  //Customer Option指针 
sfr   OPREG    = 0XFF;  //Customer Option寄存器

/*CHECKSUM*/
sfr   OPERCON   = 0XEF;  //运算控制寄存器
sfr   CHKSUML   = 0XFC;  //结果寄存器低位
sfr   CHKSUMH   = 0XFD;  //结果寄存器高位


///* ------------------- 位寄存器-------------------- */
/*PSW*/
sbit  CY     = PSW^7;  //标志位          0:加法运算最高位无进位，或者减法运算最高位无借位时	1:加法运算最高位有进位，或者减法运算最高位有借位时
sbit  AC     = PSW^6;  //进位辅助标志位  0:无借位、进位	1:加法运算时在bit3位有进位，或减法运算在bit3位有借位时
sbit  F0     = PSW^5;  //用户标志位
sbit  RS1    = PSW^4;  //工作寄存器组选择位
sbit  RS0    = PSW^3;  //工作寄存器组选择位
sbit  OV     = PSW^2;  //溢出标志位
sbit  F1     = PSW^1;  //F1标志
sbit  P      = PSW^0;  //奇偶标志位      0:ACC中1的个数为偶数（包括0个）		1:ACC中1的个数为奇数

/*TXCON*/
sbit  TFX    = TXCON^7;  //定时器2/3溢出标志位
sbit  EXFX   = TXCON^6;  //TnEX引脚外部事件输入(下降沿)被检测到的标志位
sbit  EXENX  = TXCON^3;  //TnEX引脚上的外部事件输入(下降沿)用作重载/捕获触发器允许/禁止控制
sbit  TRX    = TXCON^2;  //定时器2/3开始/停止控制位 0: 停止定时器2/3            1: 开始定时器2/3
sbit  TX     = TXCON^1;  //定时器2/3定时器/计数器方式选定位2
sbit  CP     = TXCON^0;  //捕获/重载方式选定位

/*IP*/
sbit  IPT2   = IP^5;  //Timer2中断优先权选择      0:设定 Timer 2的中断优先权是 “低”	 1:设定 Timer 2的中断优先权是 “高”
sbit  IPT1   = IP^3;  //Timer1中断优先权选择      0:设定 Timer 1的中断优先权是 “低”	 1:设定 Timer 1的中断优先权是 “高”
sbit  IPINT1 = IP^2;  //INT1计数器中断优先权选择  0:设定 INT1的中断优先权是 “低”     1:设定 INT1的中断优先权是 “高”
sbit  IPT0   = IP^1;  //Timer0中断优先权选择      0:设定 Timer 0的中断优先权是 “低”	 1:设定 Timer 0的中断优先权是 “高”
sbit  IPINT0 = IP^0;  //INT0计数器中断优先权选择  0:设定 INT0的中断优先权为 “低”     1: INT0中断优先权为高

/*IE*/
sbit  EA     = IE^7;  //中断使能的总控制       0:关闭所有的中断      1:打开所有的中断
sbit  ET2    = IE^5;  //Timer2中断使能控制     0:关闭TIMER2中断      1:打开TIMER2中断
sbit  ET1    = IE^3;  //Timer1中断使能控制     0:关闭TIMER1中断      1:打开TIMER1中断
sbit  EINT1  = IE^2;  //外部中断1中断使能控制  0:关闭外部中断1中断   1:打开外部中断1中断	
sbit  ET0    = IE^1;  //Timer0中断使能控制     0:关闭TIMER0中断      1:打开TIMER0中断
sbit  EINT0  = IE^0;  //外部中断0中断使能控制  0:关闭外部中断0中断   1:打开外部中断0中断

/*TCON*/
sbit  TF1    = TCON^7;  //T1溢出中断请求标志位	T1产生溢出，发生中断时，硬件将TF1置为“1”，申请中断，CPU响应时，硬件清“0”。
sbit  TR1    = TCON^6;  //定时器T1的运行控制位	0:Timer1禁止计数		1:Timer1开始计数
sbit  TF0    = TCON^5;  //T0溢出中断请求标志位	T0产生溢出，发生中断时，硬件将TF0置为“1”，申请中断，CPU响应时，硬件清“0”。
sbit  TR0    = TCON^4;  //定时器T0的运行控制位	0:Timer0禁止计数		1:Timer0开始计数


/******************* P0 **************************
SC92F6372未引出引脚：无
SC92F6371未引出引脚：P02/P03/P04
SC92F6378未引出引脚：P00/P01/P04/P05
SC92F6370未引出引脚：P00/P02/P03/P04/P05
*************************************************/
sbit  P05    = P0^5;
sbit  P04    = P0^4;
sbit  P03    = P0^3;
sbit  P02    = P0^2;
sbit  P01    = P0^1;
sbit  P00    = P0^0;

/******************* P1 ***************************
SC92F6372未引出引脚：无
SC92F6371未引出引脚：无
SC92F6378未引出引脚：P11/P15
SC92F6370未引出引脚：P11/P14/P15
*************************************************/
sbit  P15    = P1^5;
sbit  P14    = P1^4;
sbit  P13    = P1^3;
sbit  P12    = P1^2;
sbit  P11    = P1^1;
sbit  P10    = P1^0;

/******************* P2 ***************************
SC92F6372未引出引脚：无
SC92F6371未引出引脚：P27
SC92F6378未引出引脚：P24/P25/P26/P27
SC92F6370未引出引脚：P24/P25/P26/P27
*************************************************/
sbit  P27    = P2^7;
sbit  P26    = P2^6;
sbit  P25    = P2^5;
sbit  P24    = P2^4;
sbit  P21    = P2^1;
sbit  P20    = P2^0;


/****************************************************************************
*注意：封装未引出的管脚，需设置为强推挽输出模式
*IC选型：请根据所使用的IC型号,在初始化完IO口后，调用相对应的未引出管脚的IO口配置;
*****************************************************************************/
#define  SC92F6371_NIO_Init()   {P0CON|=0x1C,P2CON|=0x80;}  //SC92F6371的未引出来的IO口配置
#define  SC92F6378_NIO_Init()   {P0CON|=0x33,P1CON|=0x22,P2CON|=0xF0;}  //SC92F6378的未引出来的IO口配置
#define  SC92F6370_NIO_Init()   {P0CON|=0x3D,P1CON|=0x32,P2CON|=0xF0;}  //SC92F6370的未引出来的IO口配置

#endif
