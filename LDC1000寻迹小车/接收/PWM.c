#include "Config.c"
#include "PWM.h"
#include "ldc1000_51.h"
#include "Lcd_1602.h"
void PWM_Time1_Config()
{	
	TMOD|=0X01;
	TH0=0X00;
	TL0=0X00;
	EA|=1;
	ET0=1;
	TR0=1;

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


void PWM_Low(int y,int z)
{
		int x=y;
		if(y>20){
			x=y-2;
		}
		if(y<=z)
		{
			ENB=1;
		}
		if(y>z)
		{
			ENB=0;
		}
		if(x<=z)
		{
			ENA=1;
		}
		if(x>z)
		{
			ENA=0;
	}
}
