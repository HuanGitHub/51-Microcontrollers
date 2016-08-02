#include "Config.c"
int temp,e;
int PWM_flag;
unsigned char Value[6];
void DelayMs(unsigned int x);
int i,t;
void main()
{	
	LCD_init();
	Time0_Config();
	T=0;
Write_dat('5');		Write_dat('5');

}


void Time0() interrupt 1
{
	TH0=0XFF;
	TL0=0XFE;
	PWM_flag==1?PWM_Left(30):PWM_Right(30);  //当PWM_flag为1是左转  0右转
	temp++;
	if(temp==200){
		temp=0;
	}	
}
void Chao_Time0() interrupt 3	  
{
	TH1=0;
	TL1=0;
}

void res() interrupt 0
{
		unsigned char j,k;
		unsigned int err;
		e=0;					 
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
							e++;
							err--;
							if(e>30)
							{
								EX0=1;
								return;
							}
						}
						Value[k]>>=1;	     //k表示第几组数据
						if(e>=8)			//如果高电平出现大于565us，那么是1
						{
							Value[k]|=0x80;
						}
						e=0;		//用完时间要重新赋值							
					}
				}
			}
			if(Value[2]!=~Value[3])
			{
				Write_dat('x');
				return;
			}
		}			
	}







