#include "ldc1000_51.h"                  
#include "Config.c"
uint16_t Rp_value;                                            
void write_spi(uint8_t add,uint8_t w_data)
{
  uint8_t ss;
  SCLK=0;  //SCLK=0;
  CS=0; //CS=0
  for(ss=0;ss<8;ss++)
  {
    SCLK=0;  //SCLK=0;
    if((add&0x80)==0x80)
    {
      SDI=1; //SDI=1
    }
    else
    {
      SDI=0;//SDI=0
    }
    add=add<<1;
    SCLK=1;   //sclk=1
  }

  for(ss=0;ss<8;ss++)
  {
    SCLK=0;  //SCLK=0;
    if((w_data&0x80)==0x80)
     {
       SDI=1; //SDI=1
     }
    else
     {
       SDI=0;//SDI=0
     }
    w_data=w_data<<1;
    SCLK=1;   //sclk=1
   }
  SCLK=0;  //SCLK=0;
  CS=1; //CS=1

}
uint8_t read_spi(uint8_t add)				  
{
  uint8_t ss;
  uint8_t sss=0;
  SCLK=0;  //SCLK=0;
  CS=0; //CS=0
  add=add|0x80;
  for(ss=0;ss<8;ss++)
  {
    SCLK=0;  //SCLK=0;
    if((add&0x80)==0x80)
    {
      SDI=1; //SDI=1
    }
    else
    {
      SDI=0;//SDI=0
    }
    add=add<<1;
    SCLK=1;   //sclk=1
  }

  for(ss=0;ss<8;ss++)
  {
    SCLK=0;  //SCLK=0;
    sss=sss<<1;
    if(SDO==1)  //sdo
    {
      sss=sss|0x01;
    }
    else
    {
      sss=sss&0xfe;
    }
    SCLK=1;//sclk=1
  }
  SCLK=0;  //SCLK=0;
  CS=1; //CS=1
  return sss;
}

void ldc1000_int(void)
{
  write_spi(LDC1000_CMD_RPMAX,       TEST_RPMAX_INIT);  
  write_spi(LDC1000_CMD_RPMIN,       TEST_RPMIN_INIT);  
  write_spi(LDC1000_CMD_SENSORFREQ,  0x94);             
  write_spi(LDC1000_CMD_LDCCONFIG,   0x17);             
  write_spi(LDC1000_CMD_CLKCONFIG,   0x00);            
  write_spi(LDC1000_CMD_INTCONFIG,   0x02);             
  write_spi(LDC1000_CMD_THRESHILSB,  0x50);              
  write_spi(LDC1000_CMD_THRESHIMSB,  0x14);
  write_spi(LDC1000_CMD_THRESLOLSB,  0xC0);             
  write_spi(LDC1000_CMD_THRESLOMSB,  0x12);
  write_spi(LDC1000_CMD_PWRCONFIG,   0x01);           
}


uint16_t Rp_Sample()					  //¼ÆËã
{
   uint8_t m,l;	   //h
    CS=1;							
    ldc1000_int();                 
    Init_Lcd();                                         
  l=read_spi(LDC1000_CMD_PROXLSB); 
  m=read_spi(LDC1000_CMD_PROXMSB);  
  Rp_value=m*256+l;
  	return Rp_value;

}


void delay(uint16_t xx)
{
  uint16_t xxx;
  for(xxx=0;xxx<xx;xxx++)
  {
   ;
  }
}


