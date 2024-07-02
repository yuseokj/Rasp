#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main()
{

	printf("\033[2J");
	int fd = wiringPiI2CSetup(0x48);
	while(1)
	{
		wiringPiI2CWrite(fd, 1);
 		wiringPiI2CRead(fd);
 		int x = (wiringPiI2CRead(fd)*80)/255; //wiringPiI2CRead=0~255
 		
 		
 		wiringPiI2CWrite(fd, 0);
 		wiringPiI2CRead(fd);
 		int y = (wiringPiI2CRead(fd)*24)/255;
 		
 		
 		/*
 		x2 = ((80*x)/255); // type caculation warning
 		y2 = ((24*y)/255);
 		*/
		//printf("\033[%d;%dH", y2, x2); //[y;xH
		//delay(50);
		//printf("\033[%d;%dH(%d,%d)\n", y, x, x, y);
		printf("\033[%d;%dH*", y, x);
	}
	return 0;
}
