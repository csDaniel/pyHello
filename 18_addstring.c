/* ************************************************************
*
*	The idea is to take a string, such as "some_string##"
*	Next, an int, such as 1234, will be added. 
*	The end result should be "some_string1234"
*
*
************************************************************ */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define COUNT 10
#define SIZE 500

void concat_str(char target[][SIZE], char *phrase);

void concat_num(char *target, int val);

void test_str(char *target, char *original, int val);

int main(int argc, char *argv[]){

	int num = 1234;
	char *target_phrase = "some_string##";
	char arr_strings[COUNT][SIZE];

	// populate all the strings within the matrix with the target_phrase
	concat_str(arr_strings, target_phrase);


	int i;
	for (i = 0; i < COUNT; i++) {
		printf("%s + %i\n",arr_strings[i], i);

		concat_num(arr_strings[i], i);

		printf("%s\n",arr_strings[i]);
	}


	return 0;
}


void concat_str(char target[][SIZE], char *phrase) {
	int i;
	for (i = 0; i < COUNT; i++) {
		strcpy(target[i], phrase);
	}

}

void concat_num(char *target, int val) {
	int insertion_point;
	char val_string[10];

	// locate the end of null_terminator
	insertion_point = (strlen(target) - 2);
	target[insertion_point] = '\0';

	// change the int to str
	sprintf(val_string, "%d", val);

	// use strcat to append string to target
	strcat(target, val_string);
}




