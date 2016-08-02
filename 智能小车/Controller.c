#include "Config.c"
#include "Controller.h"
#include "LCD.h"
#include "L298N.h"
unsigned char Value[6];
void Controller_Out0_Config()
{
	EA|=1;
	IT0=1;
	EX0=1;
}
void De()		//@11.0592MHz  //用于刷新显示
{
	char i, j, k;
	i = 6;
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

void Red_line()
{
	unsigned char j,k;
	unsigned int err,Time;
	Time=0;					 
	DelayMs(70);
		if(IN==0)		//确认是否真的接收到正确的信号
		{	 
			err=1000;				//1000*10us=10ms,超过说明接收到错误的信号
			while((IN==0)&&(err>0))	//等待前面9ms的低电平过去  		
			{			
				DelayMs(1);
				err--;
			} 
			if(IN==1)			//如果正确等到9ms低电平
			{
				err=500;
				while((IN==1)&&(err>0))		 //等待4.5ms的起始高电平过去
				{
					DelayMs(1);
					err--;
				}
				for(k=0;k<4;k++)		//共有4组数据
				{				
					for(j=0;j<8;j++)	//接收一组数据
					{
	
						err=60;		
						while((IN==0)&&(err>0))//等待信号前面的560us低电平过去
						{
							DelayMs(1);
							err--;
						}
						err=500;
						while((IN==1)&&(err>0))	 //计算高电平的时间长度。
						{
							DelayMs(1);//0.14ms
							Time++;
							err--;
							if(Time>30)
							{
								EX0=1;
								return;
							}
						}
						Value[k]>>=1;	     //k表示第几组数据
						if(Time>=8)			//如果高电平出现大于565us，那么是1
						{
							Value[k]|=0x80;
						}
						Time=0;		//用完时间要重新赋值							
					}
				}
			}
			if(Value[2]!=~Value[3])
			{
				for(j=0;j<4;j++)
				{
					Value[j]=0;
				}
				return;
			}
		}
}
void Controller_out()
{	int i,t;
	LCD_init();
    	for(i=0;i<8;i++){
			 	t=Value[2]&0x01;
				Write_dat(t+48);	
				Value[2]>>=1;	
		    }		 
		De();
		Write_com(0x01); 	
}
void  Controller_test()			   //用于LCD1602 显示键值；
{
    Controller_Out0_Config();
	while(1){
		Controller_out();
	}
}
int Controller_Com(){    //带出 Value[2] 的值 
	return Value[2];
}

void DelayMs(unsigned int x)   //0.14ms误差 0us
{
	unsigned char i;
	while(x--)
	{
		for (i = 0; i<13; i++);	
	}
}
