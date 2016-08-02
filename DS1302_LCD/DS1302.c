#include <DS1302.h>
uchar TIME[7] = {0, 0, 0x12, 0x02, 0x02, 0x05, 0x16};
uchar code READ_RTC_ADDR[7] = {0x81, 0x83, 0x85, 0x87, 0x89, 0x8b, 0x8f}; 
uchar code WRITE_RTC_ADDR[7] = {0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c};
void DS_Write_data(uchar addr,uchar date)
{
	uchar i;
	CE=0;
	_nop_();
	CE=1;
	SCLK=0;
	for(i=0;i<8;i++)
	{
		IO=addr&0x01;
		addr>>=1;
		SCLK=1;
		_nop_();
		SCLK=0;
		_nop_();
	}
	for(i=0;i<8;i++)
	{
		IO=date&0x01;
		date>>=1;
		SCLK=1;
		_nop_();
		SCLK=0;
		nop_();
	}	
}

uchar DS_Read_date(uchar addr)
{
	uchar n,dat,dat1;
	CE = 0;
	_nop_();
	SCLK = 0;
	_nop_();
	CE = 1;
	_nop_();

	for(n=0; n<8; n++)
	{
		IO =  addr&0x01 ;
		addr >>= 1;
		SCLK = 1;
		_nop_();
		SCLK = 0;
		_nop_();
	}
	_nop_();
	for(n=0; n<8; n++)
	{
		dat1 = IO;
		dat = (dat>>1) | (dat1<<7);
		SCLK = 1;
		_nop_();
		SCLK = 0;
		_nop_();
	}

	CE = 0;
	_nop_();
	SCLK = 1;
 	_nop_();
	IO = 0;
	_nop_();
	IO = 1;
	_nop_();
	return dat;
}

void DS_Read_time()
{
	uchar n;
	for (n=0; n<7; n++)
	{
		TIME[n] = DS_Read_date(READ_RTC_ADDR[n]);
	}	
}

void DS_init()
{
	uint i;
	DS_Write_data(0x8E,0X00);
	for(i=0;i<7;i++)
	{	
		DS_Write_data(WRITE_RTC_ADDR[i],TIME[i]);
	}
	DS_Write_data(0x8E,0X80);	
}
