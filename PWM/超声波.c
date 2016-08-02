#include <reg52.h>
sbit T=P2^1;
sbit E=P3^2;
void Write_com(char x);
 void Write_dat(char x);
 void Time0_Config();
 void LCD_init();
 void LCD_Delay();
	 sbit LCD_rs=P2^6;
	sbit LCD_rw=P2^5;
	sbit LCD_e=P2^7;									 
	sbit led=P1^5;
#define uchar unsigned char
void Time1_Config();
uchar ch[]="0123456789";
unsigned int time,timeH,timeL,dist,flag;
uchar che,bai,shi,ge;
void Write_dat(char x);
void delay_20us()
 { 
    uchar a ;
    for(a=0;a<100;a++);
 }
void main()
{
	LCD_init();


	while(1);
						
}

void Time1_Config()
{
	TMOD|=0x10;
	TH1=0xff;
	TL1=0xff;
	ET1=1;
	TR1=1;
}
void Waibu() interrupt 0
{
	  	

}

void Time1() interrupt 3
{
	TH1=0xff;
	TL1=0xff;
	TR1=0;
	Write_dat('9');
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