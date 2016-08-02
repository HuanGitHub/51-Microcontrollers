#include <reg52.h>
sbit led=P0^7;
sbit IN1=P1^0;
sbit IN2=P1^1;
sbit IN3=P1^2;
sbit IN4=P1^3;
void Time0_Config();
int i,temp,dc,flag;
void main()
{
	flag=0;
	IN1=1;
	IN2=0;
	IN3=1;
	IN4=0;
	dc=50;
	Time0_Config();
	while(1);

}

void Time0_Config()
{
	TMOD=0x01;
	TH0=0xb8;
	TL0=0x0f;
	EA=1;
	ET0=1;
	TR0=1;
}
void time() interrupt 1
{
	TH0=0xb8;
	TL0=0x0f;
	temp++;
	if(temp<=dc){
		 led=1;

	}
	if(temp>dc){
		 led=0;
	}
	if(temp==100){
		temp=0;
	}
	if(temp==50){
		temp=0;
		led=~led;
	}
}
