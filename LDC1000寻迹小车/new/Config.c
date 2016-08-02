#include <reg52.h>

/* LDC1000 */
sbit SDO =P1^1;     
sbit SDI =P1^2;   
sbit SCLK =P1^0;  
sbit CS =P1^3;  

/* LCD */
sbit LCD_RS = P2^6; //1602 control define
sbit RW = P2^5;
sbit LCD_E = P2^7;