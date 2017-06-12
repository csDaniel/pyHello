/*
*		Name:	Daniel OFarrell
*		Date:		11 June 2017
*		Filename:	19_deskfun.c
*
*		Summary:
*				Desk Fun is just another practice program to get comfortabe in yet another new programming
*				environment.
*
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>


void fun_func(int count);

int main(int argc, char *argv[]) {
	
	printf("Hello World\n");

	srand(time(NULL));

	int i = 0;
	for (i = 0; i < atoi(argv[1]); i++) {
		printf("Random Numer =\t %d\n",(rand() % 100));
		fun_func(i);
	}
	
	

	
	return 0;
}


void fun_func(int count) {
	while (count > 0) {
		printf("Countdown: %d\n",count);
		count--;
	}
}