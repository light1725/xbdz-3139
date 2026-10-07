/*--------------------------------------------------------------------------
SC92L840x_C.H

C Header file for SC92L840x microcontroller.
Copyright (c) 2025 Shenzhen SinOne Chip Electronic CO., Ltd.
All rights reserved.
深圳市赛元微电子股份有限公司
版本号:  V1.0    
日期  :  2025/9/12
--------------------------------------------------------------------------*/
#ifndef _SC92L840x_H_
#define _SC92L840x_H_

/* ------------------- 字节寄存器-------------------- */
/*CPU*/
///累加器Ａ
sfr 	ACC	   = 0xE0;		
///通用寄存器B		
sfr 	B	     = 0xF0;		
///程序状态字
sfr 	PSW	   = 0xD0;		
///DPH数据指针高8位		
sfr 	DPH	   = 0x83;		
///DPL数据指针低8位		
sfr 	DPL	   = 0x82;		
///堆栈指针	
sfr 	SP	   = 0x81;		
		
/*system*/
///电源管理控制寄存器
sfr		PCON   = 0x87;		

/*interrupt*/
///中断优先级控制寄存器2
sfr		IP2    = 0xBA;      
///中断优先级控制寄存器1
sfr		IP1    = 0xB9;      
///中断优先权控制寄存器
sfr		IP	   = 0xB8;		
///中断控制寄存器
sfr		IE	   = 0xA8;		
///中断控制寄存器1
sfr		IE1    = 0xA9;  	
///中断控制寄存器2
sfr		IE2    = 0xAA;      

/*PORT*/
///P5口模式控制寄存器		
sfr 	P5PH    = 0xDA;		
///P5口模式控制寄存器		
sfr	  P5CON	  = 0xD9;		
///P5口数据寄存器
sfr   P5	    = 0xD8;		
///P2口模式控制寄存器		
sfr 	P2PH    = 0xA2;		
///P2口模式控制寄存器		
sfr	  P2CON	  = 0xA1;		
///P2口数据寄存器
sfr   P2	    = 0xA0;		
///P1口模式控制寄存器		
sfr   P1PH    = 0x92;		
///P1口模式控制寄存器	
sfr	  P1CON   = 0x91;		
///P1口数据寄存器
sfr   P1	    = 0x90;		
///P0口模式控制寄存器		
sfr	  P0PH    = 0x9B;		
///P0口模式控制寄存器		
sfr	 	P0CON   = 0x9A;		
///P0口数据寄存器
sfr 	P0	    = 0x80;		

/*TIMER*/
///定时器频率控制寄存器
sfr 	TMCON   = 0x8E;		
///定时器1高8位
sfr 	TH1	    = 0x8D;		
///定时器0高8位
sfr 	TH0	    = 0x8C;		
///定时器1低8位
sfr 	TL1	    = 0x8B;		
///定时器0低8位
sfr 	TL0	    = 0x8A;		
///定时器工作模式寄存器
sfr 	TMOD	  = 0x89;		
///定时器控制寄存器
sfr 	TCON	  = 0x88;		
///定时器2/3/4控制寄存器
sfr   T2CON   = 0xC8;   
///定时器2/3/4重载/捕捉低8位
sfr   T2MOD   = 0xC9;   
///定时器2/3/4重载/捕捉高8位
sfr   RCAP2L  = 0xCA;   
///定时器2/3/4重载/捕捉高8位
sfr   RCAP2H  = 0xCB;   
///定时器2/3/4低8位
sfr   TL2     = 0xCC;   
///定时器2/3/4高8位
sfr   TH2     = 0xCD;   

/*ADC*/
///ADC功能配置寄存器0
sfr	  ADCCFG0 = 0xAB;	
///ADC功能配置寄存器1
sfr	  ADCCFG1 = 0xAC;	
///ADC功能配置寄存器2
sfr	  ADCCFG2 = 0xB5;	
///ADC控制寄存器
sfr   ADCCON  = 0xAD;   
///ADC 结果寄存器
sfr   ADCVL	  = 0xAE;	
///ADC 结果寄存器
sfr   ADCVH	  = 0xAF;	

/*PWM*/
///PWM设置寄存器
sfr 	PWMCFG  = 0xD1;		
///PWM设置寄存器
sfr 	PWMCON0	= 0xD2;		
///PWM控制寄存器
sfr 	PWMCON1	= 0xD3;		
///PWM周期设置寄存器低8位
sfr 	PWMPDL	= 0xD4;		
///PWM周期设置寄存器低8位
sfr 	PWMPDH	= 0xD5;		
///PWM0死区设置寄存器
sfr 	PWMDFR	= 0xD6;		
				
/*WatchDog*/
///低频定时器控制寄存器
sfr	  BTMCON  = 0xFB;   
///WDT控制寄存器
sfr 	WDTCON	= 0xCF;		

///输出控制寄存器
sfr   OTCON   = 0X8F;	

/*INT*/
///INT0 下降沿中断控制寄存器
sfr   INT0F   = 0xB4; 	
///INT0 上降沿中断控制寄存器
sfr   INT0R   = 0xBB; 	
///INT2 下降沿中断控制寄存器
sfr   INT1F   = 0xBC; 	
///INT2 上降沿中断控制寄存器
sfr   INT1R   = 0xBD; 	
///INT2 下降沿中断控制寄存器
sfr   INT2F   = 0xBE; 	
///INT2 上降沿中断控制寄存器
sfr   INT2R   = 0xBF; 	

/*IAP */
///IAP控制寄存器
sfr   IAPCTL	= 0xF6;		
///IAP数据寄存器
sfr   IAPDAT	= 0xF5;		
///IAP扩展地址寄存器
sfr   IAPADE  = 0xF4;     
///IAP写入地址高位寄存器
sfr   IAPADH	= 0xF3;		
///IAP写入地址低8位寄存器
sfr   IAPADL	= 0xF2;		
///IAP保护寄存器
sfr   IAPKEY	= 0xF1;		

/*UART*/
///串口控制寄存器
sfr   SCON    = 0x98;   
///串口数据缓存寄存器
sfr   SBUF    = 0x99;  	


/*USCI0*/
///SPI0控制寄存器0
sfr   US0CON0  = 0x9C;   
///SPI0控制寄存器1
sfr   US0CON1  = 0x9D;   
///SP10控制寄存器2
sfr   US0CON2  = 0x9E;   
///SPI0数据寄存器
sfr   US0CON3  = 0x9F;  


///LPD控制寄存器
sfr   LPDCFG   = 0xB7;  

/*USCI1*/
///SPI1控制寄存器0
sfr   US1CON0  = 0xA4;   
///SPI1控制寄存器1
sfr   US1CON1  = 0xA5;   
///SPI1控制寄存器2
sfr   US1CON2  = 0xA6;   
///SPI1数据寄存器
sfr   US1CON3  = 0xA7;  

/*USCI2*/
///SPI2控制寄存器0
sfr   US2CON0  = 0xC4;   
///SPI2控制寄存器1
sfr   US2CON1  = 0xC5;   
///SPI2控制寄存器2
sfr   US2CON2  = 0xC6;   
///SPI2数据寄存器
sfr   US2CON3  = 0xC7;   

/*乘除法器*/
///扩展累加器0
sfr   EXA0    = 0xE9;   
///扩展累加器1
sfr   EXA1    = 0xEA;   
///扩展累加器2
sfr   EXA2    = 0xEB;   
///扩展累加器3
sfr   EXA3    = 0xEC;   
///扩展B寄存器0
sfr   EXBL    = 0xED;   
///扩展B寄存器1
sfr   EXBH    = 0xEE;   
///运算控制寄存器
sfr   OPERCON = 0xEF;   

/*CRC*/
///Check Sum结果寄存器低位
sfr   CRCINX = 0xFC;	  
///Check Sum结果寄存器高位
sfr   CRCREG = 0xFD;	  

/*Option*/
sfr   OPINX   = 0xFE; 
sfr   OPREG   = 0xFF; 

///* ------------------- 位寄存器-------------------- */
/*PSW*/
///标志位		0:加法运算最高位无进位，或者减法运算最高位无借位时		1:加法运算最高位有进位，或者减法运算最高位有借位时
sbit 	CY	= PSW^7;	   
///进位辅助标志位	0:无借位、进位		1:加法运算时在bit3位有进位，或减法运算在bit3位有借位时
sbit 	AC	= PSW^6;	   
///用户标志位
sbit 	F0	= PSW^5;	   
///工作寄存器组选择位
sbit 	RS1	= PSW^4;	   
///工作寄存器组选择位
sbit 	RS0	= PSW^3;	   
///溢出标志位
sbit 	OV	= PSW^2;	   
///F1标志
sbit 	F1	= PSW^1;	   
///奇偶标志位		0:ACC中1的个数为偶数（包括0个）		1:ACC中1的个数为奇数
sbit 	P	  = PSW^0;	   

/*T2CON*/
sbit  TF2   = T2CON^7;
sbit  EXF2	= T2CON^6;
sbit  RCLK  = T2CON^5;
sbit  TCLK 	= T2CON^4;
sbit  EXEN2	= T2CON^3;
sbit  TR2	  = T2CON^2;
sbit  T2    = T2CON^1;
sbit  CP	  = T2CON^0;

/*IP*/
///ADC中断优先控制位	0:设定 ADC的中断优先权是 “低”		1:设定 ADC的中断优先权是 “高”
sbit 	IPADC  = IP^6;		
///PWM中断优先控制位	0:设定 PWM的中断优先权是 “低”		1:设定 PWM 的中断优先权是 “高”
sbit	IPT2   = IP^5;		
///SIF中断优先控制位	0:设定 SIF的中断优先权是 “低”		1:设定 SIF的中断优先权是 “高”
sbit 	IPUART = IP^4;		
///Timer1中断优先控制位	0:设定 Timer 1的中断优先权是 “低”	1:设定 Timer 1的中断优先权是 “高”
sbit 	IPT1   = IP^3;		
///32K Base Timer中断优先控制位		0:设定 32K的中断优先权是 “低”		1:设定 32K的中断优先权是 “高”
sbit	IPINT1 = IP^2;		
///Timer0中断优先控制位	0:设定 Timer 0的中断优先权是 “低”	1:设定 Timer 0的中断优先权是 “高”
sbit 	IPT0   = IP^1;		
sbit	IPINT0 = IP^0;

/*IE*/
///中断使能的总控制	0:关闭所有的中断	1:打开所有的中断
sbit 	EA	   = IE^7;		
///ADC中断使能控制	0:关闭ADC中断		1:打开ADC中断
sbit 	EADC   = IE^6;		
///PWM中断使能控制	0:关闭PWM中断		1:打开PWM中断
sbit 	ET2    = IE^5;		
///UART中断使能控制	0:关闭SIF中断		1:打开SIF中断
sbit	EUART  = IE^4;		
///Timer1中断使能控制	0:关闭TIMER1中断	1:打开TIMER1中断
sbit 	ET1    = IE^3;		
///32K Base Timer中断使能控制	0:关闭32K中断		1:打开32K中断	
sbit	EINT1  = IE^2;		
///Timer0中断使能控制	0:关闭TIMER0中断	1:打开TIMER0中断
sbit 	ET0	   = IE^1;		
///TouchKey的中断使能控制	0:关闭TouchKey中断  1:打开TouchKey中断
sbit	EINT0  = IE^0;		

/*TCON*/
///T1溢出中断请求标志位	T1产生溢出，发生中断时，硬件将TF1置为“1”，申请中断，CPU响应时，硬件清“0”。
sbit 	TF1	   = TCON^7;	
///定时器T1的运行控制位	0:Timer1禁止计数		1:Timer1开始计数
sbit 	TR1	   = TCON^6;	
///T0溢出中断请求标志位	T0产生溢出，发生中断时，硬件将TF0置为“1”，申请中断，CPU响应时，硬件清“0”。
sbit 	TF0	   = TCON^5;	
///定时器T0的运行控制位	0:Timer0禁止计数		1:Timer0开始计数
sbit 	TR0	   = TCON^4;	
///INT1标志位
sbit 	Bit_IE1	   = TCON^3;	
///INT0标志位
sbit 	Bit_IE0	   = TCON^1;	

/*SCON*/
sbit 	SM0    = SCON^7;
sbit 	SM1	   = SCON^6;
sbit 	SM2	   = SCON^5;
sbit 	REN	   = SCON^4;
sbit 	TB8	   = SCON^3;
sbit 	RB8	   = SCON^2;
sbit 	TI	   = SCON^1;
sbit 	RI	   = SCON^0;

/******************* P0 ******************
*SC92L8403封装未引出的管脚：无
*SC92L8402封装未引出的管脚：P06/P07
*SC92L8401封装未引出的管脚: P03/P04/P06/P07
*SC92L8400封装未引出的管脚: P00/P01/P02/P03/P04/P06/P07
******************************************/
sbit 	P07 = P0^7;
sbit 	P06 = P0^6;
sbit 	P05	= P0^5;
sbit 	P04	= P0^4;
sbit 	P03	= P0^3;
sbit 	P02	= P0^2;
sbit 	P01	= P0^1;
sbit 	P00	= P0^0;

/******************* P1 ******************
*SC92L8403封装未引出的管脚：无
*SC92L8402封装未引出的管脚：P10/P16/P17
*SC92L8401封装未引出的管脚：P10/P16/P17
*SC92L8400封装未引出的管脚：P10/P11/P14/P16/P17
******************************************/
sbit 	P17	= P1^7;
sbit 	P16	= P1^6;
sbit 	P15	= P1^5;
sbit 	P14	= P1^4;
sbit 	P13	= P1^3;
sbit 	P12	= P1^2;
sbit 	P11	= P1^1;
sbit 	P10	= P1^0;

/******************* P2 ******************
*SC92L8403封装未引出的管脚：无
*SC92L8402封装未引出的管脚：P22/P23/P27
*SC92L8401封装未引出的管脚：P22/P23/P27
*SC92L8400封装未引出的管脚：P22/P23/P26/P27
******************************************/
sbit 	P27	= P2^7;
sbit 	P26	= P2^6;
sbit 	P25	= P2^5;
sbit 	P24	= P2^4;
sbit 	P23	= P2^3;
sbit 	P22	= P2^2;
sbit 	P21	= P2^1;
sbit 	P20	= P2^0;

/******************* P5 ******************
*SC92L8403封装未引出的管脚：无
*SC92L8402封装未引出的管脚：无
*SC92L8401封装未引出的管脚：P50/P51
*SC92L8400封装未引出的管脚：P50/P51
******************************************/
sbit 	P55	= P5^5;
sbit 	P54	= P5^4;
sbit 	P53	= P5^3;
sbit 	P52	= P5^2;
sbit 	P51	= P5^1;
sbit 	P50	= P5^0;

/****************************************************************************
*注意：封装未引出的管脚，需设置为强推挽输出模式
*IC选型：请根据所使用的IC型号,在初始化完IO口后，调用相对应的未引出管脚的IO口配置;
*如若选择SC92L8403，则不用调用宏定义。
*****************************************************************************/
/// SC92L8402的未引出来的IO口配置
#define  SC92L8402_NIO_Init()   {P0CON|=0xC0,P1CON|=0xC1,P2CON|=0x8C;}              
/// SC92L8401的未引出来的IO口配置
#define  SC92L8401_NIO_Init()   {P0CON|=0xD8,P1CON|=0xC1,P2CON|=0x8C,P5CON|=0x03;}  
/// SC92L8400的未引出来的IO口配置
#define  SC92L8400_NIO_Init()   {P0CON|=0xDF,P1CON|=0xD3,P2CON|=0xCC,P5CON|=0x03;}  

#endif
