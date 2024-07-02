#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

 main()
 {
 	int fd = wiringPiI2CSetup(0x48); //디바이스 아이디를 열어주고, 디바이스 핸들을 돌려줌
 	int v0, v1, v3;
 	float f0, f1, f3;
 	while(1)
 	{
 		
 		wiringPiI2CWrite(fd, 0);// 채널03 (VR)가변저항, ch00=temper, ch01=light
 		wiringPiI2CRead(fd);
 		v0 = wiringPiI2CRead(fd);
 		f0 = (float)((v0/255.0)*5); //형변환 주의
 		delay(100);//값을읽고 디지털변환하는데 여유 시간 필요
 		
 		wiringPiI2CWrite(fd, 1); // 채널03 (VR)가변저항, ch00=temper, ch01=light
 		wiringPiI2CRead(fd);
 		v1 = wiringPiI2CRead(fd);
 		f1 = (float)((v1/255.0)*5); //형변환 주의
 		delay(100);//값을읽고 디지털변환하는데 여유 시간 필요
		
 		wiringPiI2CWrite(fd, 3); // 채널03 (VR)가변저항, ch00=temper, ch01=light
 		wiringPiI2CRead(fd);
 		v3 = wiringPiI2CRead(fd);
 		f3 = (float)((v3/255.0)*5); //형변환 주의
		/*
 		printf("v0 input level = %d (%4.1f)\n", v0, f0);
 		printf("v1 input level = %d (%4.1f)\n", v1, f1);
 		printf("v3 input level = %d (%4.1f)\n", v3, f3);
		*/
 		printf("ADC input level = %d %d %d(%4.1f,  %4.1f,  %4.1f)\n", v0, v1, v3, f0, f1, f3);
 		delay(1000);//값을읽고 디지털변환하는데 여유 시간 필요
 	}
 }

/*
int main() {
    int fd = wiringPiI2CSetup(0x48); // Open device with address 0x48
    int v0;
    float f0;
	wiringPiSetup();

	for(int i = 0; i<4; i++){
		for(int j=0; j<4; j++){
			wiringPiI2CWrite(fd, j);
			v0 = wiringPiI2CRead(fd);
			f0 = (float)((v0 / 255.0) * 5);
			printf("ch%d = %d (%4.1f)\n",j, v0, f0);
			printf("\n");
		}
		delay(1000);
	}
    return 0;
}
*/

// #include <wiringPi.h>
// #include <pcf8591.h>
// #include <stdio.h>

// #define Address 0x48
// #define BASE 64
// #define A0 BASE+0
// #define A1 BASE+1
// #define A2 BASE+2
// #define A3 BASE+3

// int main(void)
// {
//     int value;
//     wiringPiSetup();
//     pcf8591Setup(BASE,Address);

//     while(1)
//     {
// 		value = analogRead(A0);
// 		printf("a0: %d\n",value*3300/255);
// 		value = analogRead(A1);
// 		printf("a1: %d\n",value*3300/255);
// 		value = analogRead(A3);
//         printf("a3: %d\n",value*3300/255);
//         delay(3000);
//     }
// }
