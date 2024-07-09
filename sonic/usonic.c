#include <stdio.h>
#include <wiringPi.h>

#define trig 8
#define echo 9

extern double Dist(); //function
extern void play(double r);

int main(int argc, char **argv)
{
	wiringPiSetup(); //Pin numbering method : wPi
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
	
	
	for(;;)
	{
		double d = Dist();
		printf("Distance : %.2f(cm) \n", d);
		double r = (d > 100) ? 1.0 : (d < 50)? 2.0 : 1.5;
		play(r);
		delay(500);
	}
	
	return 0;
}

