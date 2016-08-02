#include "Config.c"
#include "PWM.h"
#include "L298N.h"
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
	if(y<z)
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
	if(y<z)
	{
		ENA=1;
	}
	if(y>z)
	{
		ENA=0;
	}
}
void PWM_test()
{	Go();
	PWM_Time1_Config();	
}
void PWM_time1()
{
	static int ti;
	TH1=0XFF;
	TL1=0XFE;
	if(PWM_flag!=0){
		PWM_flag>0?PWM_Left(ti,20):PWM_Right(ti,20);  //当PWM_flag不为0  >0为Left <0为Right；
	}else{
		ENA=1;ENB=1;
	}  
	ti++;
	if(ti==200){
		ti=0;
	}	
}
void PWM_Low(int y,int z)
{
	if(y<z)
	{
		ENB=1;
	}
	if(y>z)
	{
		ENB=0;
	}
	if(y<z)
	{
		ENA=1;
	}
	if(y>z)
	{
		ENA=0;
	}

}