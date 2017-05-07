/* **********************************
*
*	Daniel OFarrell
*	Practicing with bytes
*
* **********************************/

// http://denniskubes.com/2012/08/17/basics-of-memory-addresses-in-c/
// http://stackoverflow.com/questions/8680220/how-to-get-the-value-of-individual-bytes-of-a-variable


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void play_with_bytes(long val);

void play_bytes_two(long val);

int main(int argc, char *argv[]) {

	play_with_bytes(34512364);
	play_bytes_two(34512364);	

	return 0;
}


void play_with_bytes(long val) {

	char *pt, each;
	pt = &val;
	int k;

	printf("val is %ld\n",val);
	printf("address is %p\n",(void*)(&val));
	int i = 4;
	for (i = 0; i < 4; i++) {
		printf("char is %p\n",(void*)(pt));

		pt++;
	}



	pt = &val;
	for (i = 0; i < 4; i++) {
		printf("Char is %c\n",(void*)(pt));
		pt++;
	}


}

void play_bytes_two(long val) {
	size_t i;
	for (i = 0; i < sizeof(val); i++) {
		// convert to unsigned char* because a char is 1 byte
		unsigned char byte = *((unsigned char *)&val + i);
		printf("Byte %d = %u\n", i, (unsigned)byte);
	}




}


