#include <reg52.h>
#ifndef uint
#define uint unsigned int
#endif
#ifndef uchar
#define uchar unsigned char
#endif
void Lcd_Write_com(uint x);
void Lcd_Write_data(uchar da);
void delay(uint z);
void Lcd_init();
sbit rs=P2^6;
sbit rw=P2^5;
sbit lecde=P2^7;
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
void main()
{
	 Lcd_init();

	Lcd_Write_com(0x80+0X40);
	Lcd_Write_data('0');				// ±
	Lcd_Write_data('0');				 
	Lcd_Write_data('-');
	Lcd_Write_data('0');				//∑÷
	Lcd_Write_data('0');	
	Lcd_Write_data('-');
	Lcd_Write_data('0');				//√Î
	Lcd_Write_data('0');

}