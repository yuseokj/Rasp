#include <stdio.h>
#include <wiringPi.h>

#define trig 1
#define echo 9

extern void Trigger();

int t1;
double dist;
void usISR() //ISR : no arg no return
{
	int tt = micros();
	int s1 = digitalRead(echo); //read current Pin status
	if(s1 == 1) t1 = tt;		//Rising Edge : Start counter
	else  //Falling Edge : Calc distance
	{
		dist = (tt -t1) * 0.017; //cm unit
	}
}


double Dist() //function
{
		//Trigger signal
		Trigger();
		
		//while(digitalRead(echo) != 0); // Wait for burst start
		// Wait for echo siganl
		while(digitalRead(echo) != 1); // Wait for Echo HIGH
		int t1 = micros(); // Get start time (in micro-second)
		while(digitalRead(echo) != 0); // Wait for Echo LOW
		int t2 = micros(); //Get end time
		//double dist = ((t2-t1))*(340/1000000/2*100); //ms->us
		double dist = (t2 - t1) * 0.017;
		return dist; //(t2 - t1) * 0.017;
}



