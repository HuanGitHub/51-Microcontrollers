#include "Config.c"

void Go()
{
    IN1=0;
	IN2=1;
	IN3=0;
	IN4=1;
}
void Back()
{
	IN1=1;
	IN2=0;
	IN3=1;
	IN4=0;
}
void Stop()
{
	ENA=0;
	ENB=0;
}

