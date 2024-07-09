#include <stdio.h>
#include <wiringPi.h>

#define wPi_PWM1 23
#define trig 8
#define echo 9

extern double Dist(); //function
extern void calcrange();
extern void playmusic();

int main(int argc, char **argv)
{
	wiringPiSetup(); //Pin numbering method : wPi
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
	
	pinMode(wPi_PWM1, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	calcrange();
	

	for(;;)
	{
		double d = Dist();
		printf("Distance : %.2f(cm) \n", d);
		if(d<5)
		{
			playmusic(3);
		}
		else if(d<10)
		{
			playmusic(2);
		}
		else
		{
			playmusic(1);
		}
		delay(500);
	}
	
	return 0;
}

