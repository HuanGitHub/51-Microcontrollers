#include <reg52.h>
#include <intrins.h>
#ifndef uchar
#define uchar unsigned char 
#endif

#ifndef uint
#define uint unsigned int
#endif
sbit SCLK=P3^6;
sbit IO=P3^4;
sbit CE=P3^5;
void DS_Write_data(uchar addr,uchar date);
uchar DS_Read_date(uchar addr);
extern uchar TIME[7];
void DS_Read_time();
void DS_init();