

#include <stdio.h>
#include <stdlib.h>


int recursive_hello(int val);


int main( int arc, char *argv[]) {


	int i = recursive_hello(10);	

	printf("Val = %d\n",i);

	
	return 0;

}

int recursive_hello(int val) {

	if (val < 1) {
		return 0;
	} else {
		printf("Hello World from rpi3: %d\n", val);

		return ( val + (recursive_hello( val - 1)));

	}

}











































































