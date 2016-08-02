#include "L298N.h"
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
	ENA=1;
	ENB=1;
}
void Stop()
{	IN1=0;
	IN2=0;
	IN3=0;
	IN4=0;
	ENA=1;
	ENB=1;
}
