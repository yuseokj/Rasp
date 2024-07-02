#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
int main()
{
	int fd = wiringPiI2CSetup(0x48);
 	int x, y, x2, y2;
 	printf("\033[2J"); //clear
	printf("\033[12;40H"); //cursor point 1;1
 	
 	while(1)
 	{
 		wiringPiI2CWrite(fd, 0);
 		wiringPiI2CRead(fd);
 		x = wiringPiI2CRead(fd);
 		wiringPiI2CRead(fd);
 		y = wiringPiI2CRead(fd);
 		x2 = ((80*x)/255);
 		y2 = ((24*y)/255);
		printf("\033[%d;%dH", y2, x2); //[x;yH
		delay(50);
	}
	
	return 0;
}
