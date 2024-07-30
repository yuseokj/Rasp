#include <stdio.h>
#include <wiringPi.h>

#define trig 1
#define echo 9

#define CLK 19200000
#define PSC 19
#define RANGE 66660 //for 15Hz
#define VAL 10

void TriggerEx() //function
{
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(PSC*2);
	pwmSetRange(RANGE/2); //30Hz
	pwmWrite(trig, VAL/2);

	/*
	pinMode(wPi_Pin, OUTPUT);
	
	pwmSetMode(PWM_MODE_MS); //ms==mark&space, bal==balance==variable frequency
	softPwmCreate(wPi_Pin, drh, period);//(wpi_pin, pulse with, time)
	//softPwmWrite(wPi_Pin, 70);
	
	delay(50);
	softPwmStop(wPi_Pin);
	*/
}

void Trigger()
{
	digitalWrite(trig, 1);
	delayMicroseconds(10);
	digitalWrite(trig, 0);
	delayMicroseconds(200); //delay for burst
}

