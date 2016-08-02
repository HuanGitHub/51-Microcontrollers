#include <reg52.h>
#include "Lcd_1602.h"
#define TRUE 1
#define FALSE 0
#define TEST_RPMAX_MAX 	0x1f			  /**< maximum calibration value for RPMAX */
#define TEST_RPMAX_MIN 	0x15			  /**< minimum calibration value for RPMAX */
#define TEST_RPMAX_INIT TEST_RPMAX_MIN+1  /**< RPMAX initial value */
#define TEST_RPMIN_MAX 	0x3D   			  /**< maximum calibration value for RPMIN */
#define TEST_RPMIN_MIN 	0x3A    		  /**< minimum calibration value for RPMIN */
#define TEST_RPMIN_INIT TEST_RPMIN_MIN+1  /**< RPMIN initial value */
// Final Test Range
#define TEST_RP_MSB_MAX 0x12	/**< maximum value for proximity data */
#define TEST_RP_MSB_MIN 0x0A	/**< minimum value for proximity data */
#define TEST_FC_MAX 0x0D5D		/**< maximum value for frequency counter */
#define TEST_FC_MIN 0x0D39		/**< minimum value for frequency counter */
#define LDC1000_CMD_REVID 	0x00
#define LDC1000_CMD_RPMAX 	0x01
#define LDC1000_CMD_RPMIN 	0x02
#define LDC1000_CMD_SENSORFREQ 	0x03
#define LDC1000_CMD_LDCCONFIG 	0x04
#define LDC1000_CMD_CLKCONFIG 	0x05
#define LDC1000_CMD_THRESHILSB 	0x06
#define LDC1000_CMD_THRESHIMSB 	0x07
#define LDC1000_CMD_THRESLOLSB 	0x08
#define LDC1000_CMD_THRESLOMSB 	0x09
#define LDC1000_CMD_INTCONFIG 	0x0A
#define LDC1000_CMD_PWRCONFIG 	0x0B
#define LDC1000_CMD_STATUS		0x20
#define LDC1000_CMD_PROXLSB 	0x21	
#define LDC1000_CMD_PROXMSB 	0x22
#define LDC1000_CMD_FREQCTRLSB	0x23
#define LDC1000_CMD_FREQCTRMID	0x24
#define LDC1000_CMD_FREQCTRMSB	0x25

#define uint8_t unsigned char
#define uint16_t unsigned int
#define uint32_t unsigned long

void delay(uint16_t xx);                        
uint8_t read_spi(uint8_t add);                  
void write_spi(uint8_t add,uint8_t w_data);  
void ldc1000_int(void);                                      
uint16_t Rp_Sample();                 
