#include <stdio.h>
#include <wiringPi.h>

#define trig 8
#define echo 9

extern double Dist(); //function

int main(int argc, char **argv)
{
	wiringPiSetup(); //Pin numbering method : wPi
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
	
	for(;;)
	{
		printf("Distance : %f(cm) \n", Dist());
		delay(500);
	}
	return 0;
}

