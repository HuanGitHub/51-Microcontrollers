#include "Config.c"
#include "MY_LCD.h"
void LCD_Delay()
{
	int x,y;
	for(x=0;x<10;x++)
		for(y=0;y<200;y++);
}
void Write_com(char x)
{
	LCD_RS=0;
	RW=0;
	LCD_E=0;
	LCD_Delay();
	P0=x;
	LCD_E=1;
	LCD_Delay();
	LCD_E=0;
}
void Write_dat(char x)
{
	LCD_RS=1;
	RW=0;
	LCD_E=0;
	LCD_Delay();
	P0=x;
	LCD_E=1;
	LCD_Delay();
	LCD_E=0;

}
void LCD_init()
{
	LCD_RS=0;
	RW=0;
	LCD_E=0;
    Write_com(0x38);
	Write_com(0x0e);
	Write_com(0x06);
	Write_com(0x01);
}
void LCD_test()
{	char ch[]="LCD_test success";
	int i;
	 	LCD_init();
	
	for(i=0;i<16;i++)
	{
		Write_dat(ch[i]);
	}
	while(1);
}