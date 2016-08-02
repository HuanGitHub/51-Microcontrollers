#include <reg52.h>
sbit LCD_rs=P2^6;
sbit LCD_rw=P2^5;
sbit LCD_e=P2^7;									 
sbit T=P2^1;
sbit E=P3^2;
sbit led=P1^5;
void delay_20us();
#define uchar unsigned char
void delayms(unsigned int ms);
unsigned int time,timeH,timeL,dist,flag;
void Time1_Config();
void jisuan();
