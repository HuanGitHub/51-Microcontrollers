#include "Config.c"
#include "LCD.h"
#include "Ultrasound.h"
int Count()
{
	int ge,shi,bai,dist,time;
	Write_com(0x01);
    time=TH1*256+TL1;
    dist=time*0.019;
    bai=dist/100;
    shi=dist%100/10;
    ge=dist%100%10;
    Write_dat(bai+48);
    Write_dat(shi+48);
	Write_dat(ge+48);
	TH1=0;			    //计时器1 清零
	TL1=0;
	return dist;
}
void Time1_Config()		//没有TR1 控制；
{
	TMOD|=0X10;
	TH1=0;
	TL1=0;
	ET1=1;
}
void Delay20us()		   //用于发送信号延时
{ 
    char a ;
    for(a=0;a<100;a++);
}
void Send()
{
	T=0;
	T=1;
	Delay20us();
	T=0;
}
void Ultrasound_test()
{
 	T=0;
	Time1_Config();
	LCD_init();

		Send();
		while(!E);
		TR1=1;
		while(E);
		TR1=0;
		Count();
	Delay250ms();			
	
}
void Delay250ms()		//@11.0592MHz  //用于刷新显示
{
	char i, j, k;
	
	i = 11;
	j = 130;
	k = 111;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
void Ultrasound_Time1()
{
	TH1=0;
	TL1=0;
}
