#include <stdio.h>
#include <wiringPi.h>

#define trig 8
#define echo 9

extern void Trigger();

double Dist() //function
{
		//Trigger signal
		Trigger();
		
		//while(digitalRead(echo) != 0); // Wait for burst start
		// Wait for echo siganl
		while(digitalRead(echo) != 1); // Wait for Echo HIGH
		int t1 = micros(); // Get strt time (in micro-second)
		while(digitalRead(echo) != 0); // Wait for Echo LOW
		int t2 = micros(); //Get end time
		//double dist = ((t2-t1))*(340/1000000/2*100); //ms->us
		//double dist = (t2 - t1) * 0.017;
		return (t2 - t1) * 0.017;
}


