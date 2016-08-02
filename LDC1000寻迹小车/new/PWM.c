#include "Config.c"
#include "PWM.h"
#include "ldc1000_51.h"
#include "Lcd_1602.h"
void RP_Time0_Config()
{
	TMOD|=0X01;
	TH0=0;
	TL0=0;
	EA|=1;
	ET0=1;
	TR0=1;
}
void PWM_Time1_Config()
{	
	TMOD|=0X10;
	TH1=0XFF;
	TL1=0XFE;
	EA|=1;
	ET1=1;
	TR1=1;

	ENA=1;
	ENB=1;	 
}
void PWM_Left(int y,int z)
{  	
	ENA=0;
	if(y<=z)
	{
		ENB=1;
	}
	if(y>z)
	{
		ENB=0;
	}
}
void PWM_Right(int y,int z)
{
	ENB=0;
	if(y<=z)
	{
		ENA=1;
	}
	if(y>z)
	{
		ENA=0;
	}
}

void PWM_time1()
{
	static int ti;
	TH1=0XFF;
	TL1=0XFE;
	if(PWM_flag!=0){
		PWM_flag>0?PWM_Right(ti,100):PWM_Left(ti,100);  //当PWM_flag不为0  >0为Left <0为Right；
	}else{
		PWM_Low(ti,30);
	}  
	ti++;
	if(ti==200){
		ti=0;
	}	
}
void PWM_Low(int y,int z)
{
/*	unsigned int x,x1;
	x=y+20;
	x1=y-20;
	if(y<10){
		ENA=1;
		ENB=1;
	}else{	 */
		if(y<=z)
		{
			ENB=1;
		}
		if(y>z)
		{
			ENB=0;
		}
		if(y<=z)
		{
			ENA=1;
		}
		if(y>z)
		{
			ENA=0;
	}
	}
/*	if(x1<=z)
	{
		ENB=1;
	}
	if(x>z)
	{
		ENB=0;
	}
	if(x1<=z)
	{
		ENA=1;
	}
	if(x>z)
	{
		ENA=0;
	}		   */
