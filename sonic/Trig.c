#include <stdio.h>
#include <wiringPi.h>

#define trig 8
#define echo 9

void Trigger() //function
{
		// Trigger signal
		digitalWrite(trig, 1);
		delayMicroseconds(10); //delay->ms, delayMicroseconds->us
		digitalWrite(trig, 0);
		delayMicroseconds(200);
}

