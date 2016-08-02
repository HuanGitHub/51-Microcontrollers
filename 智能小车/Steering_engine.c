#include "Config.c"
#include "LCD.h"
#include "Steering_engine.h"
void Steering_Time0_Config()
{
	TMOD|=0X01;
	EA|=1;
	TH0=0Xfe;
	TL0=0X35;
	ET0=1;
	TR0=1;
}
void Steering_Time0()
{
	int temp,k;
	static int Angle=1,f;
	int ar[]={1,2,3,2};
	TH0=0Xfe;
	TL0=0X35;
	k++;
	if(k==1500){
		k=0;
		Angle=ar[f];
		if(f==3){
			f=-1;
		}	
		f++;	  
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
void Steering_test()
{
	IO=0;
	Steering_Time0_Config();
	while(1);
}