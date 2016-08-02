#include <reg52.h>
sbit CH_WR=P1^0;
sbit CH_RD=P1^1;
sbit CH_CS=P1^2;
sbit CH_A0=P1^3;
sbit CH_INT=P1^4;
void CH_Write_Com();
void writecom();
void CH_Write_dat();
void main()
{
	CH_Write_Com();
	CH_Write_dat();
	while(1);
}
void CH_Write_Com()
{
	CH_CS=0;
	P0=0X15;
	CH_RD=1;
	CH_WR=1;
	CH_A0=0;
	CH_A0=1;
	CH_WR=0;
	CH_WR=1;
	CH_A0=0;
	CH_CS=1;
	P0=0XFF;
}
void CH_Write_dat()
{

	CH_CS=0;
	CH_A0=0;
	P0=0x02;
	CH_WR=1;
	CH_WR=0;
	CH_WR=1;
	CH_CS=1;
	P0=0XFF;
}
