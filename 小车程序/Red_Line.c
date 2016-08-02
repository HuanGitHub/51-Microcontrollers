#include "Config.c"
void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;
	_nop_();
	_nop_();
	i = 22;
	j = 3;
	k = 227;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
void DelayMs(unsigned int x)   //0.14msÎó²î 0us
{
	unsigned char i;
	while(x--)
	{
		for (i = 0; i<13; i++);
		
	}
}