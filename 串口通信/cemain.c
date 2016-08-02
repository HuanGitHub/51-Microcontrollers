#include <reg52.h>
sbit IN1=P1^0;
sbit IN2=P1^1;
sbit OUT1=P2^0;
int i;
void main()
{	while(1){
	if(IN2==1){
		i++;
		}
	}

}

