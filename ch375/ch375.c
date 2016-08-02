#include <reg52.h>
sbit CH_WR=P1^0;
sbit CH_RD=P1^1;
sbit CH_CS=P1^2;
sbit CH_A0=P1^3;
sbit CH_INT=P1^4;

void Delay(int z);
CH_Write_Com();

void main()
{
	CH_Write_Com();
	while(1);
}
void CH_Write_Com()
{
	Delay(50);
	P0=0X15;
	CH_RD=1;
	CH_WR=1;
	CH_A0=0;
	CH_A0=1;
	CH_WR=0;
	CH_WR=1;
	CH_A0=0;
	P0=0XFF;
	Delay(50);



}
void Delay(int z)
{
	int x,y;
	for(x=0;x<z;x++)
		for(y=0;y<200;y++);
	
}