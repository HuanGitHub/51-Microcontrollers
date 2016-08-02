#include "Config.c"
void Write_com(char x)
{
	LCD_rs=0;
	LCD_rw=0;
	LCD_e=0;
	LCD_Delay();
	P0=x;
	LCD_e=1;
	LCD_Delay();
	LCD_e=0;

}
void Write_dat(char x)
{
	LCD_rs=1;
	LCD_rw=0;
	LCD_e=0;
	LCD_Delay();
	P0=x;
	LCD_e=1;
	LCD_Delay();
	LCD_e=0;

}
void LCD_init()
{
	LCD_rs=0;
	LCD_rw=0;
	LCD_e=0;
    Write_com(0x38);
	Write_com(0x0e);
	Write_com(0x06);
	Write_com(0x01);
}
void LCD_Delay()
{
	int x,y;
	for(x=0;x<10;x++)
		for(y=0;y<200;y++);
}