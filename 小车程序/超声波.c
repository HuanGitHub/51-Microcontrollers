#include "Config.c"
uint time,timeH,timeL;
uchar ch[]="0123456789";
void delay_20us()
{ 
    uchar a ;
    for(a=0;a<100;a++);
}
void Chao_Time0_Config()
{
	TMOD=0X11;
	TH1=0;
	TL1=0;
	ET1=1;
}
int Count()
{
	uint dist,bai,shi,ge;
	Write_com(0x01);
   	time=TH0*256+TL0;
  	dist=time*0.019;
    bai=dist/100;
    shi=dist%100/10;
    ge=dist%100%10;
   	Write_dat(ch[bai]);
    Write_dat(ch[shi]);
	Write_dat(ch[ge]);
	TH1=0;
	TL1=0;
	return dist;
}
void Delay250ms()		//@11.0592MHz
{
	uchar i, j, k;
	_nop_();
	_nop_();
	i = 11;
	j = 130;
	k = 111;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
