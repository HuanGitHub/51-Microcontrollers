#include <reg52.h>
sbit IO=P3^7;

void Time1_Config();
int Angle=1;
void main()
{
	IO=0;
	Time1_Config();
	while(1);		
}
void Time1_Config()
{
	TMOD|=0X10;
	EA=1;
	TH1=0Xfe;
	TL1=0X35;
	ET1=1;
	TR1=1;
}

void Time1() interrupt 3
{
	int temp,k,t;
	static int ko;
	int ch[]={1,2,3,2};
	TH1=0Xfe;
	TL1=0X35;
	k++;
	if(k==800){
		k=0;
		t++;
		if(t==2){
			t=0;
		
			Angle=ch[ko];
			if(ko==3){
				ko=-1;
			}
				ko++;	
		  }
	}
	if(temp<=Angle){
		IO=1;
	}else{
		IO=0;
	}
	temp++;
	if(temp==40){
		temp=0;	
	}	
}