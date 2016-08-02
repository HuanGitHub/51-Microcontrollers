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