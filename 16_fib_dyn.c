/* *********************************************
*
*	today on r/cscareerquestions, I saw this:
*	https://www.reddit.com/r/cscareerquestions/comments/6a3rmn/do_you_get_insulted_when_you_get_asked_certain/
*	Someone was like "a dynamic fibonacci is SUPER easy"
*
*	Time to find out!
* ********************************************* */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

	printf("argv1 = %s\n", argv[1]);


	// long data type because fibonacci get crazy after around 70.
	long *arr = (long*) malloc(sizeof(long) * atoi(argv[1]));

	// stuff values @ [0] and [1] to prevent seg fault in the for loop
	arr[0] = 0;
	arr[1] = 1;

	int i;
	for (i = 2; i < (atoi(argv[1])+2); i++) {
		arr[i] = arr[i-1] + arr[i-2];
	}

	printf("Fibonacci @ %d = %ld\n",atoi(argv[1]), arr[i-1]);

	free (arr);

	return 0;
}






















