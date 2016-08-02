/*
	Òý½Å¶¨Òå
*/

#include <reg52.h>

sbit Test_Led=P2^3;
/* L298N */
sbit IN1=P1^0;
sbit IN2=P1^1;
sbit IN3=P1^2;
sbit IN4=P1^3;

/* LCD */
sbit LCD_rs=P2^6;
sbit LCD_rw=P2^5;
sbit LCD_e=P2^7;

/* PWM */
sbit ENA=P1^4;
sbit ENB=P1^5;
/* Ultrasound */
sbit T=P2^0;
sbit E=P2^1;
/* Steering_enginc */
sbit IO=P3^7;


/* Controller */
sbit IN=P3^2;
