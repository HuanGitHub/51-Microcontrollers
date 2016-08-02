#include "Config.c"

void Time0_Config()
{
	TMOD|=0X01;
	TH0=0XFF;
	TL0=0XFE;
	EA=1;
	ET0=1;
	TR0=1;
}
void PWM_Left(int z)
{
	if(temp<z)
	{
		ENB=1;
	}
	if(temp>z)
	{
		ENB=0;
	}

}
void PWM_Right(int z)
{
	if(temp<z)
	{
		ENA=1;
	}
	if(temp>z)
	{
		ENA=0;
	}

}

