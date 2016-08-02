#include <reg52.h>
#include "Lcd_1602.h"
#include "ldc1000_51.h"
#include "Config.c"			//主机
void Port_init();
void Speed_IN1();
void Time1_init();
int sp,Sdata,bb;
void DE(int z);
unsigned int va,va1,va2;
void main()
{	
	ldc1000_int();
	Port_init();
	Init_Lcd();
	//Speed_IN1();
	//Time1_init();
	PT0=1;
	while(1)
	{
		Sdata=Rp_Sample();
		va=Sdata;
		DE(1);
		Sdata=Rp_Sample();
		va1=Sdata;
		va2=va1-va;
		LCD_value(0,0,va);
		if(va>1000){
			DE(200);
			SBUF=2;
		}else{
				DE(200);	DE(200);	DE(200);	DE(200);
			SBUF=0;
		}
		
		
	}
}
void DE(int z)
{
	int x,y;
	for(x=0;x<z;x++)
		for(y=0;y<150;y++);
}


void Port_init()
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
  {  //接收的SBUF
	  RI=0;				   //接收的SBUF	
  }
  if(TI)				 //发送结束表示符号
  {	
  	TI=0;
  }
}
void Speed_IN1()
{
	EX1=1;
	EA=1;
	IT1=1;
}
void Speed() interrupt 2
{
	sp++;
//	LCD_write_str(0,0,"Distances:");
	//LCD_value(10,0,sp);
}

void Time1() interrupt 1
{	  
	
	int time,ttt,tt;
	TR0=0;
	
		//De(1);
	time++;	
	TH0=0X00;
	TL0=0X4C;
	if(time==20){
		time=0;
		ttt++;
		if(tt==0){
			LCD_value0(1,1,0);
		}
		LCD_value0(3,1,ttt);
		LCD_write_str(2,1,":");
		if(ttt==60){
			  ttt=0;
			  tt++;
			  LCD_value0(1,1,tt);
			  if(tt==10){
			  		tt=0;
			  	}		  
		}
	}
	TR0=1;
	
}
void Time1_init()
{
	TMOD|=0X01;
	TH0=0X00;
	TL0=0X4C;
	ET0=1;
	TR0=1;
	EA=1;


}