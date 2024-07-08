#include <stdio.h>
#include <wiringPi.h>

#define wPi_PWM1 23
int PSC = 19;
int RANGE = 100;
//int DUTY = RANGE/2;

enum {DO=0, Do, RE, Re, MI, FA, Fa, SL, Sl, LA, La, CI};
int pitch[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
int range[12];
int song[] = {SL,SL,LA,LA,SL,SL,MI,SL,SL,MI,MI,RE,
				SL,SL,LA,LA,SL,SL,MI,SL,MI,RE,MI,DO,-1};
int rythm[] = {4,4,4,4,4,4,2,4,4,4,4,1,
			   4,4,4,4,4,4,2,4,4,4,4,1,-1};
void calcrange() // calc Range values using pitch data
{
	for (int i = 0; i<12; i++)
	range[i] = 19.2*1000000/(PSC*pitch[i]);
}
void playsound(int um, int len) // um : pitch, len : rythm
{
	pwmSetClock(PSC); //Prescaler : ~ 1MHz
	pwmSetRange(range[um]); //10KHz = 19.2M/(19*x), about x=100 , x=range
	pwmWrite(wPi_PWM1, range[um]/200);
	//delay(len*150);
	delay(2000/len);
	pwmWrite(wPi_PWM1, 0);
	delay(50);
}
int main()
{
	wiringPiSetup();
	pinMode(wPi_PWM1, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	calcrange();

	for(int i = 0; song[i]!=-1; i++)
	{
		playsound(song[i], rythm[i]);
	}

	return 0;
}
