/*--------------------------------------------------------------------------
SC92F8003B_C.H

C Header file for SC92F8003B microcontroller.
Copyright (c) 2025 Shenzhen SinOne Chip Electronic CO., Ltd.
All rights reserved.
深圳市赛元微电子股份有限公司
版本号:  V1.0    
日期  :  2025/9/12
--------------------------------------------------------------------------*/
#ifndef _SC92F8003B_H_
#define _SC92F8003B_H_

///* ------------------- 字节寄存器-------------------- */
/*CPU*/
///累加器Ａ
sfr   ACC = 0XE0;  
///B寄存器		
sfr   B   = 0XF0;  
///程序状态字寄存器		
sfr   PSW = 0XD0;  
///DPTR数据指针高位		
sfr   DPH = 0X83;  
///DPTR数据指针低位		
sfr   DPL = 0X82;  
///堆栈指针	
sfr   SP  = 0X81;  

/*SRAM*/
///外部SRAM操作地址高位
sfr   EXADH = 0XF7;  

/*system*/
///电源管理控制寄存器
sfr   PCON = 0X87;  

/*interrupt*/
///中断优先级控制寄存器1
sfr   IP1 = 0XB9;  
///中断优先权控制寄存器
sfr   IP  = 0XB8;  
///中断控制寄存器
sfr   IE  = 0XA8;  
///中断控制寄存器1
sfr   IE1 = 0XA9;  

/*PORT*/
///P2口上拉电阻控制寄存器		
sfr   P2PH	= 0XA2;  
///P2口输入/输出控制寄存器	
sfr	  P2CON	= 0XA1;  
///P2口数据寄存器
sfr   P2    = 0XA0;  
///P1口上拉电阻控制寄存器		
sfr   P1PH	= 0X92;  
///P1口输入/输出控制寄存器
sfr	  P1CON	= 0X91;  
///P1口数据寄存器
sfr   P1    = 0X90;  
///P0口上拉电阻控制寄存器		
sfr	  P0PH	= 0X9B;  
///P0口输入/输出控制寄存器	
sfr	  P0CON	= 0X9A;  
///P0口数据寄存器
sfr   P0    = 0X80;  

/*TIMER*/	
///定时器频率控制寄存器
sfr   TMCON  = 0X8E;  
///定时器1高8位
sfr   TH1    = 0X8D;  
///定时器0高8位
sfr   TH0    = 0X8C;  
///定时器1低8位
sfr   TL1    = 0X8B;  
///定时器0低8位
sfr   TL0    = 0X8A;  
///定时器工作模式寄存器
sfr   TMOD   = 0X89;  
///定时器控制寄存器
sfr   TCON   = 0X88;  
///定时器2控制寄存器
sfr   T2CON  = 0XC8;  
///定时器2工作模式寄存器
sfr   T2MOD  = 0XC9;  
///定时器2重载/捕捉低8位
sfr   RCAP2L = 0XCA;  
///定时器2重载/捕捉高8位
sfr   RCAP2H = 0XCB;  
///定时器2低8位
sfr   TL2    = 0XCC;  
///定时器2高8位
sfr   TH2    = 0XCD;  

/*ADC*/
///ADC功能配置寄存器1
sfr	  ADCCFG1 = 0XAA;  
///ADC功能配置寄存器0
sfr	  ADCCFG0 = 0XAB;  
///ADC控制寄存器
sfr   ADCCON  = 0XAD;  
///ADC 结果寄存器
sfr   ADCVL   = 0XAE;  
///ADC 结果寄存器
sfr   ADCVH   = 0XAF;  

/*PWM*/
///PWM设置寄存器
sfr   PWMCFG  = 0XD1;  
///PWM0占空比控制寄存器
sfr   PWMCON0 = 0XD2;  
///PWM周期设置寄存器
sfr   PWMPRD  = 0XD3;  
///PWM占空比设置寄存器A
sfr   PWMDTYA = 0XD4;  
///PWM0设置寄存器
sfr   PWMDTY0 = 0XD5;  
///PWM1占空比设置寄存器
sfr   PWMDTY1 = 0XD6;  
///PWM2占空比设置寄存器
sfr   PWMDTY2 = 0XD7;  
///PWM控制寄存器1
sfr   PWMCON1 = 0XDA;  
///PWM占空比设置寄存器B
sfr   PWMDTYB = 0XDB;  
///PWM3占空比设置寄存器/PWM死区时间配置寄存器
sfr   PWMDTY3 = 0XDC;  
///PWM4占空比设置寄存器
sfr   PWMDTY4 = 0XDD;  
///PWM5占空比设置寄存器
sfr   PWMDTY5 = 0XDE;  
///PWM6占空比设置寄存器
sfr   PWMDTY6 = 0XDF;  

/*WatchDog*/
///低频定时器控制寄存器
sfr	  BTMCON = 0XCE;  
///WDT控制寄存器
sfr   WDTCON = 0XCF;  

/*INT*/
///INT0 下降沿中断控制寄存器
sfr   INT0F = 0XBA;  
///INT0 上降沿中断控制寄存器
sfr   INT0R = 0XBB;  
///INT1 下降沿中断控制寄存器
sfr   INT1F = 0XBC;  
///INT1 上降沿中断控制寄存器
sfr   INT1R = 0XBD;  
///INT2 下降沿中断控制寄存器
sfr   INT2F = 0XC6;  
///INT2 上降沿中断控制寄存器
sfr   INT2R = 0XC7;  

/*IAP */
///IAP控制寄存器
sfr   IAPCTL = 0XF6;  
///IAP数据寄存器
sfr   IAPDAT = 0XF5;  
///IAP扩展地址寄存器
sfr   IAPADE = 0XF4;  
///IAP写入地址高位寄存器
sfr   IAPADH = 0XF3;  
///IAP写入地址低位寄存器
sfr   IAPADL = 0XF2;  
///IAP保护寄存器
sfr   IAPKEY = 0XF1;  

/*uart0*/
///串口控制寄存器
sfr   SCON  = 0X98;  
///串口数据缓存寄存器
sfr   SBUF  = 0X99;  
///输出控制寄存器
sfr   OTCON = 0X8F;  

/*三合一*/
///SSI控制寄存器0
sfr   SSCON0 = 0X9D;  
///SSI控制寄存器1
sfr   SSCON1 = 0X9E;  
///SSI控制寄存器2
sfr   SSCON2 = 0X95;  
///SSI数据寄存器
sfr   SSDAT  = 0X9F;  

/*OPTION*/
///Customer Option指针 
sfr   OPINX = 0XFE;  
///Customer Option寄存器
sfr   OPREG = 0XFF;  

/*Check Sum*/
///Check Sum结果寄存器低位
sfr   CHKSUML = 0XFC;  
///Check Sum结果寄存器高位
sfr   CHKSUMH = 0XFD;  
///运算控制寄存器
sfr   OPERCON = 0XEF;  

///* ------------------- 位寄存器-------------------- */
/*PSW*/
///标志位          0:加法运算最高位无进位，或者减法运算最高位无借位时	1:加法运算最高位有进位，或者减法运算最高位有借位时
sbit  CY  = PSW^7;  
///进位辅助标志位  0:无借位、进位	1:加法运算时在bit3位有进位，或减法运算在bit3位有借位时
sbit  AC  = PSW^6;  
///用户标志位
sbit  F0  = PSW^5;  
///工作寄存器组选择位
sbit  RS1 = PSW^4;  
///工作寄存器组选择位
sbit  RS0 = PSW^3;  
///溢出标志位
sbit  OV  = PSW^2;  
///F1标志
sbit  F1  = PSW^1;  
///奇偶标志位      0:ACC中1的个数为偶数（包括0个）		1:ACC中1的个数为奇数
sbit  P   = PSW^0;  

/*T2CON*/
///定时器2溢出标志位
sbit  TF2   = T2CON^7;  
///T2EX引脚外部事件输入(下降沿)被检测到的标志位
sbit  EXF2  = T2CON^6;  
///UART0接收时钟控制位    0: 定时器1产生接收波特率	1: 定时器2产生接收波特率
sbit  RCLK  = T2CON^5;  
///UART0发送时钟控制位    0: 定时器1产生发送波特率	1: 定时器2产生发送波特率
sbit  TCLK  = T2CON^4;  
///T2EX引脚上的外部事件输入(下降沿)用作重载/捕获触发器允许/禁止控制
sbit  EXEN2 = T2CON^3;  
///定时器2开始/停止控制位 0: 停止定时器2             1: 开始定时器2
sbit  TR2   = T2CON^2;  
///定时器2定时器/计数器方式选定位2
sbit  T2    = T2CON^1;  
///捕获/重载方式选定位
sbit  CP    = T2CON^0;  

/*IP*/
///ADC中断优先权选择         0:设定 ADC的中断优先权是 “低”      1:设定 ADC的中断优先权是 “高”
sbit  IPADC  = IP^6;  
///Timer2中断优先权选择      0:设定 Timer 2的中断优先权是 “低”	 1:设定 Timer 2的中断优先权是 “高”
sbit  IPT2   = IP^5;  
///UART中断优先权选择        0:设定 UART的中断优先权是 “低”     1:设定 UART的中断优先权是 “高”
sbit  IPUART = IP^4;  
///Timer1中断优先权选择      0:设定 Timer 1的中断优先权是 “低”	 1:设定 Timer 1的中断优先权是 “高”
sbit  IPT1   = IP^3;  
///INT1计数器中断优先权选择  0:设定 INT1的中断优先权是 “低”     1:设定 INT1的中断优先权是 “高”
sbit  IPINT1 = IP^2;  
///Timer0中断优先权选择      0:设定 Timer 0的中断优先权是 “低”	 1:设定 Timer 0的中断优先权是 “高”
sbit  IPT0   = IP^1;  
///INT0计数器中断优先权选择  0:设定 INT0的中断优先权为 “低”     1: INT0中断优先权为高
sbit  IPINT0 = IP^0;  

/*IE*/
///中断使能的总控制       0:关闭所有的中断      1:打开所有的中断
sbit  EA    = IE^7;  
///ADC中断使能控制        0:关闭ADC中断         1:打开ADC中断
sbit  EADC  = IE^6;  
///Timer2中断使能控制     0:关闭TIMER2中断      1:打开TIMER2中断
sbit  ET2   = IE^5;  
///UART中断使能控制       0:关闭SIF中断         1:打开SIF中断
sbit  EUART = IE^4;  
///Timer1中断使能控制     0:关闭TIMER1中断      1:打开TIMER1中断
sbit  ET1   = IE^3;  
///外部中断1中断使能控制  0:关闭外部中断1中断   1:打开外部中断1中断	
sbit  EINT1 = IE^2;  
///Timer0中断使能控制     0:关闭TIMER0中断      1:打开TIMER0中断
sbit  ET0   = IE^1;  
///外部中断0中断使能控制  0:关闭外部中断0中断   1:打开外部中断0中断
sbit  EINT0 = IE^0;  

/*TCON*/
///T1溢出中断请求标志位	T1产生溢出，发生中断时，硬件将TF1置为“1”，申请中断，CPU响应时，硬件清“0”。
sbit  TF1 = TCON^7;      
///定时器T1的运行控制位	0:Timer1禁止计数		1:Timer1开始计数
sbit  TR1 = TCON^6;      
///T0溢出中断请求标志位	T0产生溢出，发生中断时，硬件将TF0置为“1”，申请中断，CPU响应时，硬件清“0”。
sbit  TF0 = TCON^5;      
///定时器T0的运行控制位	0:Timer0禁止计数		1:Timer0开始计数
sbit  TR0 = TCON^4;      
///INT1溢出中断请求标志	INT1产生溢出，发生中断时，硬件将IE1置为“1”，申请中断，CPU响应时，硬件清“0”。 
sbit  IE1_BIT = TCON^3;  
///INT0溢出中断请求标志	INT0产生溢出，发生中断时，硬件将IE0置为“1”，申请中断，CPU响应时，硬件清“0”。
sbit  IE0_BIT = TCON^1;  

/*SCON*/
///串行通信模式控制位:与SM1配合使用 00: 模式0，8位半双工同步通信模式 01: 模式1，10位全双工异步通信 11: 模式3，11位全双工异步通信
sbit  SM0 = SCON^7;  
///串行通信模式控制位
sbit  SM1 = SCON^6;  
///串行通信模式控制位2，此控制位只对模式3有效   0：每收到一个完整数据帧就置位RI产生中断请求   1：收到一个完整的数据帧时，只有当RB8=1时才会置位RI产生中断请求
sbit  SM2 = SCON^5;  
///接收允许控制位  0:不允许接受数据   1：允许接受数据
sbit  REN = SCON^4;  
///只对模式3有效，为发送数据的第9位
sbit  TB8 = SCON^3;  
///只对模式3有效，为接收数据的第9位
sbit  RB8 = SCON^2;  
///发送中断标志位
sbit  TI  = SCON^1;  
///接收中断标志位
sbit  RI  = SCON^0;  

/* P0 */
sbit  P01 = P0^1;
sbit  P00 = P0^0;

/* P1 */
sbit  P17 = P1^7;
sbit  P16 = P1^6;
sbit  P15 = P1^5;
sbit  P14 = P1^4;
sbit  P13 = P1^3;
sbit  P12 = P1^2;
sbit  P11 = P1^1;
sbit  P10 = P1^0;

/* P2 */
sbit  P27 = P2^7;
sbit  P26 = P2^6;
sbit  P25 = P2^5;
sbit  P24 = P2^4;
sbit  P23 = P2^3;
sbit  P22 = P2^2;
sbit  P21 = P2^1;
sbit  P20 = P2^0;

#endif
