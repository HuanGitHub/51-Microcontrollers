#include "LCD.h"



void delay(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}

void Lcd_Write_com(uint x)
{
	rs=0;
	rw=0;
	P0=x;
	delay(1);
	lecde=1;
	delay(1);
	lecde=0;
}

void Lcd_Write_data(uchar da)
{
	rs=1;
	rw=0;
	delay(1);
	P0=da;
	lecde=1;
	delay(1);
	lecde=0;	
}

void Lcd_init()
{
	Lcd_Write_com(0x38);
	delay(1);
	Lcd_Write_com(0x0F);
	delay(1);
	Lcd_Write_com(0x01);
	delay(1);
	Lcd_Write_com(0x06);
	delay(1);
	Lcd_Write_com(0x80);
	delay(1);
	Lcd_Write_com(0x01);
	delay(1);
	
}
