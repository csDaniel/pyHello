#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argv, char *argc[]) {

	int i;
	for (i = 1; i <= 100; i++) {
		if ((i % 5 == 0) && (i % 3 == 0)) {
			printf ("fizzbuzz\n");
		} else if (i % 5 == 0) {
			printf ("fizz\n");
		} else if (i % 3 == 0) {
			printf ("buzz\n");
		} else {
			printf ("%d\n", i);
		}
	}

	return 0;
}