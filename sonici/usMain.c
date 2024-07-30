#include <stdio.h>
#include <wiringPi.h>
#include <pthread.h>
#include <string.h>

#define trig 1
#define echo 9

extern void Trigger();
extern void usisr();
extern double Dist();
extern double dist;
extern void TriggerEx();
extern int t1;

void *usThread(void *a)
{
	while(1)
	{
		Dist(); delay(70);
	}
}
int main(int n, char *v[])
{
	//clock/(psc*range) = freqency
	
	pthread_t th;
	wiringPiSetup();
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
	
	if((n>1) && (strcmp(v[1], "-i") ==0))
	{
		pinMode(trig, PWM_OUTPUT);
		TriggerEx();
		wiringPiISR(echo, INT_EDGE_BOTH, usisr);
	}
	else
	{
		pinMode(trig, OUTPUT);
		pthread_create(&th, NULL, usThread, NULL);
	}
	//wiringPiISR(trig, INT_EDGE_BOTH, usisr);
	//TriggerEx();
	
	//wiringPiISR(echo, INT_EDGE_BOTH, usisr); //Regist ISR
	//Trigger();
	
	while(1)
	{
		printf("Distance : %.2f		\r", dist);
	}
}
