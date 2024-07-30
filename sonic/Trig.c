#include <stdio.h>
#include <wiringPi.h>

#define trig 8
#define echo 9

void Trigger() //function
{
		//initial for 0
		digitalWrite(TRIG, 0);
		delayMicroseconds(10);
		// Trigger signal
		digitalWrite(trig, 1);
		delayMicroseconds(10); //delay->ms, delayMicroseconds->us
		digitalWrite(trig, 0);
		delayMicroseconds(200); //wait for burst end
}

