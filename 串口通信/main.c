#include <reg52.h>
sbit LCD_rs=P2^6;
sbit LCD_rw=P2^5;
sbit LCD_e=P2^7;									 
sbit T=P2^0;
sbit E=P2^1;	  // π”√∆’Õ®IO
sbit led=P1^5;
void delay_20us();
#define uchar unsigned char
unsigned int time,timeH,timeL,dist,flag,temp,ge,shi,bai,k;
void Write_com(char x);
void Write_dat(char x);
void LCD_init();
void LCD_Delay();
uchar ch[]="0123456789";
void Time0_Config();
void Count();
void main()
{  	
	LCD_init();
	Time0_Config();
	T=0;
	while(1){	
		T=1;
		delay_20us();
		T=0;
		while(!E);
		TR0=1;
		while(E);
		TR0=0;	
		Count();
	
		LCD_Delay();LCD_Delay();LCD_Delay();LCD_Delay();LCD_Delay();LCD_Delay();LCD_Delay();LCD_Delay();LCD_Delay();LCD_Delay();	
					
						LCD_Delay();LCD_Delay();LCD_Delay();LCD_Delay();LCD_Delay();LCD_Delay();LCD_Delay();LCD_Delay();LCD_Delay();LCD_Delay();	
	}

		

}
void Count()
{
	Write_com(0x01);
   time=TH0*256+TL0;
   dist=time*0.019;
   bai=dist/100;
   shi=dist%100/10;
   ge=dist%100%10;
   Write_dat(ch[bai]);
   Write_dat(ch[shi]);
	Write_dat(ch[ge]);
	TH0=0;
	TL0=0;

}
void Time0_Config()
{
	TMOD=0X01;
	TH0=0;
	TL0=0;
	ET0=1;
}
void Time0() interrupt 1
{
	TH0=0;
	TL0=0;
	led=~led;
}



void delay_20us()
{ 
    uchar a ;
    for(a=0;a<100;a++);
}
void Write_com(char x)
{
	LCD_rs=0;
	LCD_rw=0;
	LCD_e=0;
	LCD_Delay();
	P0=x;
	LCD_e=1;
	LCD_Delay();
	LCD_e=0;
}
void Write_dat(char x)
{
	
	LCD_rs=1;
	LCD_rw=0;
	LCD_e=0;
	LCD_Delay();
	P0=x;
	LCD_e=1;
	LCD_Delay();
	LCD_e=0;

}
void LCD_init()
{
	LCD_rs=0;
	LCD_rw=0;
	LCD_e=0;
    Write_com(0x38);
	Write_com(0x0e);
	Write_com(0x06);
	Write_com(0x01);
}
void LCD_Delay()
{
	int x,y;
	for(x=0;x<10;x++)
		for(y=0;y<200;y++);
}


