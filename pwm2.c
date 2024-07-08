#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define wPi_Pin 7
int main(int n, char *s[])
{
	if(n<2)
	{
		printf("usage : pwm1 [duty_rate(%)] [[period]] \n\n");
		printf("		period = 10 ms if empty\n\n");
		printf("default value : period = 10 ms, DR = 50%%\n\n");
		//return 1;
	}

	int dr, drh, drl, period = 10;
	if(n>1)
	{
	sscanf(s[1], "%d", &dr);
	}
	if(n>2)
	{
		sscanf(s[2], "%d", &period);
	}
	drh = (dr*period)/100; //Mark time
	drl = period - drh; //Space time
	wiringPiSetup();
	pinMode(wPi_Pin, OUTPUT);
	
	pwmSetMode(PWM_MODE_MS); //ms==mark&space, bal==balance==variable frequency
	softPwmCreate(wPi_Pin, drh, period);//(wpi_pin, pulse with, time)
	//softPwmWrite(wPi_Pin, 70);
	
	delay(50);
	softPwmStop(wPi_Pin);
	return 0;
}
