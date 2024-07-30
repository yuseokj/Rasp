usi : usMain.o Trig.o usisr.o
	gcc -o usi usMain.o Trig.o usisr.o -lwiringPi
usMain.o : usMain.c
	gcc -c -o usMain.o usMain.c	
Trig.o : Trig.c
	gcc -c -o Trig.o Trig.c
usisr.o : usisr.c
	gcc -c -o usisr.o usisr.c

