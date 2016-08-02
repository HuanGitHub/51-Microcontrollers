#include <reg52.h>
/* L298N */
sbit IN1=P2^0;
sbit IN2=P2^1;
sbit IN3=P2^2;
sbit IN4=P2^3;
/* PWM */

sbit ENA=P2^4;
sbit ENB=P3^7;
/* LDC1000 */
sbit SDO =P1^1;     
sbit SDI =P1^2;   
sbit SCLK =P1^0;  
sbit CS =P1^3;  

/* LCD */
sbit LCD_RS = P2^6; //1602 control define
sbit RW = P2^5;
sbit LCD_E = P2^7;