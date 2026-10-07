						 /*--------------------------------------------------------------------------
SC92F8003_C.H

C Header file for SC92F8003 microcontroller.
Copyright (c) 2025 Shenzhen SinOne Microelectronics CO., Ltd.
All rights reserved.
深圳市赛元微电子股份有限公司
版本号:  V1.0    
日期  :  2025/9/12
--------------------------------------------------------------------------*/
#ifndef _SC92F8003_H_
#define _SC92F8003_H_

/* ------------------- 字节寄存器-------------------- */
///*CPU*/
///累加器Ａ
sfr   ACC	  = 0xE0;		
///通用寄存器B		
sfr   B	      = 0xF0;		
///程序状态字		
sfr   PSW	  = 0xD0;		
///数据指针高8位		
sfr   DPH	  = 0x83;		
///数据指针低8位		
sfr   DPL	  = 0x82;		
///堆栈指针	
sfr   SP	  = 0x81;		
		

/*system*/
///电源管理控制寄存器
sfr   PCON    = 0x87;		

/*interrupt*/
///中断优先级控制寄存器1
sfr   IP1     = 0XB9;       
///中断优先权控制寄存器
sfr   IP	  = 0xB8;		
///中断控制寄存器
sfr   IE	  = 0xA8;		
///中断控制寄存器1
sfr   IE1     = 0XA9;  	    

/*PORT*/
///P2口模式控制寄存器		
sfr   P2PH	  = 0xA2;		
///P2口模式控制寄存器		
sfr	  P2CON	  = 0xA1;		
///P2口数据寄存器
sfr   P2	  = 0xA0;		
///P1口模式控制寄存器		
sfr   P1PH    = 0x92;		
///P1口模式控制寄存器	
sfr	  P1CON	  = 0x91;		
///P1口数据寄存器
sfr   P1	  = 0x90;		
///P0口模式控制寄存器		
sfr	  P0PH	  = 0x9B;		
///P0口模式控制寄存器		
sfr	  P0CON	  = 0x9A;		
///P0口数据寄存器
sfr   P0	  = 0x80;		

/*TIMER*/
///定时器频率控制寄存器
sfr   TMCON	  = 0x8E;		
///定时器1高8位
sfr   TH1	  = 0x8D;		
///定时器0高8位
sfr   TH0	  = 0x8C;		
///定时器1低8位
sfr   TL1	  = 0x8B;		
///定时器0低8位
sfr   TL0	  = 0x8A;		
///定时器工作模式寄存器
sfr   TMOD	  = 0x89;		
///定时器控制寄存器
sfr   TCON	  = 0x88;		
///定时器2控制寄存器
sfr   T2CON   = 0xC8;       
///定时器2工作模式寄存器
sfr   T2MOD   = 0xC9; 	    
///定时器2重载/捕捉低8位
sfr   RCAP2L  = 0xCA;       
///定时器2重载/捕捉高8位
sfr   RCAP2H  = 0xCB;       
///定时器2低8位
sfr   TL2     = 0xCC;       
///定时器2高8位
sfr   TH2     = 0xCD;       


/*ADC*/
///ADC功能配置寄存器0
sfr	  ADCCFG1 = 0xAA;		
///ADC功能配置寄存器1
sfr	  ADCCFG0 = 0xAB;		
///ADC控制寄存器
sfr   ADCCON  = 0XAD;       
///ADC 结果寄存器
sfr   ADCVL	  = 0xAE;		
///ADC 结果寄存器
sfr   ADCVH	  = 0xAF;		

/*PWM*/
///PWM设置寄存器
sfr   PWMCFG  = 0xD1;		
///PWM控制寄存器
sfr   PWMCON0 = 0xD2;		
///PWM周期设置寄存器
sfr   PWMPRD  = 0xD3;		
///PWM占空比设置寄存器A
sfr   PWMDTYA = 0xD4;		
///PWM0设置寄存器
sfr   PWMDTY0 = 0xD5;		
///PWM1设置寄存器
sfr   PWMDTY1 = 0xD6;		
///PWM2设置寄存器
sfr   PWMDTY2 = 0xD7;		
///PWM控制寄存器
sfr   PWMCON1 = 0xDA;		
///PWM占空比设置寄存器B
sfr   PWMDTYB = 0xDB;		
///PWM3设置寄存器
sfr   PWMDTY3 = 0xDC;		
///PWM4设置寄存器
sfr   PWMDTY4 = 0xDD;		
///PWM5设置寄存器
sfr   PWMDTY5 = 0xDE;		
///PWM6设置寄存器
sfr   PWMDTY6 = 0xDF;		


//
///*WatchDog*/
///低频定时器控制寄存器
sfr	  BTMCON  = 0XCE;       
///WDT控制寄存器
sfr   WDTCON  = 0xCF;		


///输出控制寄存器
sfr   OTCON   = 0X8F;		

/*INT*/
///INT0 下降沿中断控制寄存器
sfr   INT0F   = 0XBA; 	    
///INT0 上降沿中断控制寄存器
sfr   INT0R   = 0XBB; 	    
///INT1 下降沿中断控制寄存器
sfr   INT1F   = 0XBC; 	    
///INT1 上降沿中断控制寄存器
sfr   INT1R   = 0XBD; 	    
///INT2 下降沿中断控制寄存器
sfr   INT2F   = 0XC6; 	    
///INT2 上降沿中断控制寄存器
sfr   INT2R   = 0XC7; 	    

/*IAP */
///IAP控制寄存器
sfr   IAPCTL  = 0xF6;		
///IAP数据寄存器
sfr   IAPDAT  = 0xF5;		
///IAP扩展地址寄存器
sfr   IAPADE  = 0xF4;       
///IAP写入地址高位寄存器
sfr   IAPADH  = 0xF3;		
///IAP写入地址低8位寄存器
sfr   IAPADL  = 0xF2;		
///IAP保护寄存器
sfr   IAPKEY  = 0xF1;		

/*uart0*/
///uart控制寄存器
sfr   SCON    = 0X98;       
///uart0数据寄存器
sfr   SBUF    = 0X99;       

/*三合一*/
///SSI控制寄存器0
sfr   SSCON0  = 0X9D;       
///SSI控制寄存器1
sfr   SSCON1  = 0X9E;       
///SSI控制寄存器2
sfr   SSCON2  = 0X95;       
///SSI数据寄存器
sfr   SSDAT   = 0X9F;       

sfr   OPINX   = 0XFE; 
sfr   OPREG   = 0XFF;

/*Check Sum*/
///Check Sum结果寄存器低位
sfr   CHKSUML = 0XFC;       
///Check Sum结果寄存器高位
sfr   CHKSUMH = 0XFD;	    

///运算控制寄存器
sfr   OPERCON = 0xEF;       

///* ------------------- 位寄存器-------------------- */
/*PSW*/
///标志位		0:加法运算最高位无进位，或者减法运算最高位无借位时		1:加法运算最高位有进位，或者减法运算最高位有借位时
sbit 	CY	  = PSW^7;	    
///进位辅助标志位	0:无借位、进位		1:加法运算时在bit3位有进位，或减法运算在bit3位有借位时
sbit 	AC	  = PSW^6;	    
///用户标志位
sbit 	F0	  = PSW^5;	    
///工作寄存器组选择位
sbit 	RS1	  = PSW^4;	    
///工作寄存器组选择位
sbit 	RS0	  = PSW^3;	    
///溢出标志位
sbit 	OV	  = PSW^2;	    
///F1标志
sbit 	F1	  = PSW^1;	    
///奇偶标志位		0:ACC中1的个数为偶数（包括0个）		1:ACC中1的个数为奇数
sbit 	P	  = PSW^0;	    

/*T2CON*/
sbit  TF2     = T2CON^7;
sbit  EXF2	  = T2CON^6;
sbit  RCLK    = T2CON^5;
sbit  TCLK	  = T2CON^4;
sbit  EXEN2	  = T2CON^3;
sbit  TR2	  = T2CON^2;
sbit  T2      = T2CON^1;
sbit  CP	  = T2CON^0;


/*IP*/
///ADC中断优先控制位	0:设定 ADC的中断优先权是 “低”		1:设定 ADC的中断优先权是 “高”
sbit  IPADC   = IP^6;		
///PWM中断优先控制位	0:设定 PWM的中断优先权是 “低”		1:设定 PWM 的中断优先权是 “高”
sbit  IPT2    = IP^5;		
///SIF中断优先控制位	0:设定 SIF的中断优先权是 “低”		1:设定 SIF的中断优先权是 “高”
sbit  IPUART  = IP^4;		
///Timer1中断优先控制位	0:设定 Timer 1的中断优先权是 “低”	1:设定 Timer 1的中断优先权是 “高”
sbit  IPT1	  = IP^3;		
///32K Base Timer中断优先控制位		0:设定 32K的中断优先权是 “低”		1:设定 32K的中断优先权是 “高”
sbit  IPINT1  = IP^2;		
///Timer0中断优先控制位	0:设定 Timer 0的中断优先权是 “低”	1:设定 Timer 0的中断优先权是 “高”
sbit  IPT0	  = IP^1;		
sbit  IPINT0  = IP^0;

/*IE*/
///中断使能的总控制	0:关闭所有的中断	1:打开所有的中断
sbit  EA	  = IE^7;		
///ADC中断使能控制	0:关闭ADC中断		1:打开ADC中断
sbit  EADC    = IE^6;		
///PWM中断使能控制	0:关闭PWM中断		1:打开PWM中断
sbit  ET2     = IE^5;		
///UART中断使能控制	0:关闭SIF中断		1:打开SIF中断
sbit  EUART   = IE^4;		
///Timer1中断使能控制	0:关闭TIMER1中断	1:打开TIMER1中断
sbit  ET1     = IE^3;		
///32K Base Timer中断使能控制	0:关闭32K中断		1:打开32K中断	
sbit  EINT1   = IE^2;		
///Timer0中断使能控制	0:关闭TIMER0中断	1:打开TIMER0中断
sbit  ET0	  = IE^1;		
///TouchKey的中断使能控制	0:关闭TouchKey中断  1:打开TouchKey中断
sbit  EINT0   = IE^0;		

/*TCON*/
///T1溢出中断请求标志位	T1产生溢出，发生中断时，硬件将TF1置为“1”，申请中断，CPU响应时，硬件清“0”。
sbit  TF1	  = TCON^7;	    
///定时器T1的运行控制位	0:Timer1禁止计数		1:Timer1开始计数
sbit  TR1	  = TCON^6;	    
///T0溢出中断请求标志位	T0产生溢出，发生中断时，硬件将TF0置为“1”，申请中断，CPU响应时，硬件清“0”。
sbit  TF0	  = TCON^5;	    
///定时器T0的运行控制位	0:Timer0禁止计数		1:Timer0开始计数
sbit  TR0	  = TCON^4;	    

/*SCON*/
sbit  SM0	  = SCON^7;
sbit  SM1	  = SCON^6;
sbit  SM2	  = SCON^5;
sbit  REN	  = SCON^4;
sbit  TB8	  = SCON^3;
sbit  RB8	  = SCON^2;
sbit  TI	  = SCON^1;
sbit  RI	  = SCON^0;

/* P0 */
sbit  P01	  = P0^1;
sbit  P00	  = P0^0;

/* P1 */
sbit  P17	  = P1^7;
sbit  P16	  = P1^6;
sbit  P15	  = P1^5;
sbit  P14	  = P1^4;
sbit  P13	  = P1^3;
sbit  P12	  = P1^2;
sbit  P11	  = P1^1;
sbit  P10	  = P1^0;

/* P2 */
sbit  P27	  = P2^7;
sbit  P26	  = P2^6;
sbit  P25	  = P2^5;
sbit  P24	  = P2^4;
sbit  P23	  = P2^3;
sbit  P22	  = P2^2;
sbit  P21	  = P2^1;
sbit  P20	  = P2^0;

#endif
