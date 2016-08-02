#include <reg52.h>
void init(); 
char k;
void delay(int z);
void main()
{
	init();
	while(1)
	{
		delay(200);
		delay(200);
		delay(200);
		delay(200);
		SBUF=0XFF;

	}
}
void init()
{
	SM0=0;
	SM1=1;
	REN=1;
	TI=0;
	RI=0;
	TMOD=0X20;
	TH1=0Xfd;
	TL1=0Xfd;
	ET1=0;
	TR1=1;
	EA=1;
	ES=1;
}
void chuankou() interrupt 4
{
  if(RI)
  {
  RI=0;
  if(SBUF==0Xff)
  		P2=0X00;
  if(SBUF==0Xfe)
  		P2=0X0f;
  if(SBUF==0Xfc)
  		P2=0Xf0;
  if(SBUF==0Xf0)
  		P2=0X66;
  SBUF=SBUF;

 
  }
  if(TI)
  {
  	TI=0;
  }

}
void delay(int z)
{
	int x,y;
	for(x=0;x<z;x++)
		for(y=0;y<200;y++);
}