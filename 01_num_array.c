/*
	create an array of 100 random numbers to play with. 
	output the numbers to a file:

	arr_output.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>	// for open
#include <unistd.h> // for close

#include <sys/types.h>
#include <sys/stat.h>

#define MAXSIZE 256
#define MINSIZE 0

void fill_array(int *arr);
void print_array(int *arr);
void print_to_file(int *arr);
void print_to_file_open(int* arr);

int main() {

	int arr[MAXSIZE];

	printf("Hello World\n");

	fill_array(arr);
	print_array(arr);

	//print_to_file(arr);

	print_to_file_open(arr);

	return 0;
}

void fill_array(int *arr) {

	srand(time(NULL));

	int i = 0;
	for (i = MINSIZE; i < MAXSIZE; i++) {
		arr[i] = (rand() % 100) + 1;
	}

}

void print_array(int *arr) {
	int i = 0;
	for (i = MINSIZE; i < MAXSIZE; i++) {
		printf("%d \t",arr[i]);
		if (i % 10 == 0) {
			printf("\n");
		}
	}
	printf("\n");
}

void print_to_file(int *arr) {

	char *filename = "rand_arr";
	int i;
	FILE *p;
	p = fopen(filename, "w");

	for (i = 0; i < MAXSIZE; i++) {

		fprintf(p, "%d,",arr[i]);

	}
	fclose(p);
}

void print_to_file_open(int* arr) {
	printf("isnide open file\n");

	int fd; 
	char *filename = "rand_arr";
	fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0666); 

	int i;
	char int_data[256];
	//char writestring[256];
	int buffer, nwritten;
	for (i = 0; i < MAXSIZE; i++) {
			memset(int_data,0,strlen(int_data));
			sprintf(int_data, "%i,",arr[i]);

			buffer = strlen(int_data);
			nwritten = write(fd, int_data, buffer);
	}

	close(fd);
}








