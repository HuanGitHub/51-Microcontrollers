#include <reg52.h>
#include <intrins.h>

#include "L298N.h"
#include "PWM.h"
#ifndef uchar
#define uchar unsigned char
#endif
#ifndef uint 
#define uint unsigned int
#endif



 /* L298N */
sbit IN1=P1^0;
sbit IN2=P1^1;
sbit IN3=P1^2;
sbit IN4=P1^3;
sbit ENA=P1^4;
sbit ENB=P1^5;

extern int temp;
  /*LCD*/
sbit LCD_rs=P2^6;
sbit LCD_rw=P2^5;
sbit LCD_e=P2^7;
void Write_com(char x);
void Write_dat(char x);
void LCD_init();
void LCD_Delay();

/*³¬Éù²¨*/
sbit T=P2^0;
sbit E=P2^1;
void delay_20us();
void Chao_Time0_Config();
int Count();	
void Delay250ms();


/*Ñ°¼£*/
sbit Red1=P2^3;
sbit Red2=P2^2;
sbit Red3=P2^1;
sbit Red4=P2^0;

/*Controller*/
void Delay500ms();
sbit IN=P3^2;
void DelayMs(unsigned int x);









