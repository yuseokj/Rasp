#include <wiringPi.h>
#include <stdio.h>

#define RED 8
#define GREEN 9
#define YELLOW 7
#define SW 2
#define SB 3

int mode = 0;
int intv = 0; // 0 ~ 8
int tim;		  // delay time interval (ms)
int ps[40]; // pin갯수 : 40, pin상태 : defalt 0
int flag=0;

void Toggle(int pin)
{
	ps[pin] = !ps[pin];
	digitalWrite(pin, ps[pin]);
}

void gpioisr()
{
	//if(digitalRead(SW)==0) // pushed (인터럽트안에 들어왔기때문에 의미없음, 이미 인터럽트안에 들어왔기때문에 실행됨)
	
	if(++intv > 8) intv = 0;
	printf("GPIO interrupt occured...%dms\n", tim);
		
}

void gpiostop()
{
	printf("LED TURN OFF\nSTOP\n");
	digitalWrite(RED, 0);
	digitalWrite(GREEN, 0);
	digitalWrite(YELLOW, 0);
	flag=1; 
}

int main()
{
	wiringPiSetup(); //Pin number use case (wPi)
	pinMode(RED, OUTPUT); // 8,9,7 : OUT  2 : IN
	pinMode(GREEN, OUTPUT);
	pinMode(YELLOW, OUTPUT);
	pinMode(SW, INPUT);
	wiringPiISR(SW, INT_EDGE_FALLING, gpioisr); // registration GPIO ISR
	wiringPiISR(SB, INT_EDGE_FALLING, gpiostop); 
	
	for(;;) //while(1)
	{
		tim = (9-intv)*100;
		if(mode)
		{
			Toggle(RED);	delay(tim);
			Toggle(GREEN);	delay(tim);
			Toggle(YELLOW);	delay(tim);
		}
		else
		{
			Toggle(YELLOW);	delay(tim);
			Toggle(GREEN);	delay(tim);
			Toggle(RED);	delay(tim);
		}
		if(flag==1)
		break;
		
	}	
	return 0;
}
