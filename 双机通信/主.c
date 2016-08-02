#include <reg52.h>
#include "LCD.h"
void UartInit(void);
char res;
void main()
{
	UartInit();
	LCD_init();
	while(1){

	}


}
void UartInit(void)		//9600bps@11.0592MHz
{
	SM0=0;
	SM1=1;
	REN=1;

	TMOD &= 0x0F;		//设定定时器1为16位自动重装方式
	TL1 = 0xEd;		//设定定时初值
	TH1 = 0xFd;		//设定定时初值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	ES=1;
	EA=1;
}
void Time1() interrupt 4
{
	TL1 = 0xEd;		
	TH1 = 0xFd;
	RI=0;
	if(RI){
		res=SBUF;
		RI=0;
		Write_dat('');	
	}
		

}