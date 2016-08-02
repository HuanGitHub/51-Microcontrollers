#include <reg52.h>
#include "Lcd_1602.h"
#include "ldc1000_51.h"
#include "Config.c"
#include "L298N.h"
#include "PWM.h"
void init();
long int value;
int PWM_FLAG,sp;
void ddd(int z);
void main()
{
	init();
	Init_Lcd();
	PS=1;
	PWM_Time1_Config();
	Go();	
	PWM_FLAG=0;
	//LCD_value(0,0,PWM_FLAG);	
	while(1);  
		   	 	
}
void init()
{
	SM0=0;
	SM1=1;
	REN=1;
	TI=0;
	RI=0;
	TMOD=0X20;
	TH1=0Xfd;
	TL1=0Xfd;
	ET1=0;
	TR1=1;
	EA=1;
	ES=1;
}
void Trans() interrupt 4
{

  if(RI)					//接收结束 标志符
  { 			   //接收的SBUF
	  RI=0;				   //接收的SBUF
	  PWM_FLAG=SBUF; 
	  LCD_value(0,0,PWM_FLAG);	
  }
  if(TI)				 //发送结束表示符号
  {	
  	TI=0;
  }
  TR1=1;
}
void Time1() interrupt 1
{
	int i;
	TR0=0;
	i++;
	TH0=0XFF;
	TL0=0XFE;
	switch(PWM_FLAG)
	{
	//	case 1: PWM_Right(i,100);PWM_FLAG=0;		break;
		case 2: ENA=0;PWM_Left(i,100); 	break;		
		case 0: PWM_Low(i,30);		break;
		default: PWM_Low(i,30);
	}

	if(i==200){
		i=0;
		PWM_FLAG=0;
		}
	TR0=1;

}
void ddd(int z)
{
	int x,y;
	for(x=0;x<z;x++)
		for(y=0;y<150;y++);
}









