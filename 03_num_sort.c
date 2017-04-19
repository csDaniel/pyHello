// Doing a num sort through merge sort

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAXBUFFER 256
#define MINBUFFER 32

// load file into array
int *build_array(char *filename);
void _parse_into_arr(int *arr, char *input);

// sort array
void sort_array_lazy(int *arr);

// save newly sorted array
void store_array(char *filename, int *arr);



int main(int argc, char *argv[]) {
	printf("Opening file: %s\n", argv[1]);


	int *arr = NULL;
	arr = build_array(argv[1]);

	for (int i = 0; i < MAXBUFFER; i++) {
		printf("%i,", arr[i]);

//		printf("array val: %i,", arr[i]);
	}

	printf("\n\n");

	sort_array_lazy(arr);
	for (int i = 0; i < MAXBUFFER; i++) {
		printf("%i,", arr[i]);

//		printf("array val: %i,", arr[i]);
	}
	printf("\n\n");

	free(arr);
	return 0;
} 

int *build_array(char *filename) {
	printf("Building the array now~\n");

	int *arr = (int *) malloc (sizeof(int) * MAXBUFFER);
	int fd;
	int nread = 1;
	int container_size = MAXBUFFER;
	char buffer[MINBUFFER];
	char *container = (char *) malloc (sizeof(int) * MAXBUFFER);



	fd = open(filename, O_RDONLY);
	if (fd < 0) {
		printf("Error reading %s \n", filename);
		perror("Error opening file");
		exit(-1);
	}

	// file opens successfully
	while (nread > 0) {
		nread = read(fd, buffer, MINBUFFER);

		// read the bufer into a larger container
		strcat(container, buffer);
		memset(buffer,0, MINBUFFER);

		if (strlen(container) > container_size/2) {
			printf("reallocating size of container from %d\n", container_size);
			container_size = container_size * 2;
			container = (char *) realloc(container, container_size);
		}

	}

	_parse_into_arr(arr, container);

	free(container);
	return &(*arr);
}

void _parse_into_arr(int *arr, char *input) {

	int current_size = sizeof(arr) / sizeof(int);
	int max_size = MAXBUFFER;
	static int current_loc;

	//printf("Parsing: %s into array \n", input);
	if (!arr) {
		current_loc = 0;
	}


	char *token = strtok(input, ",");
	while (token) {
		//printf("current_loc %d \n", current_loc);
		arr[current_loc] = atoi(token);
		current_loc++;
		printf("Current loc: %d, current val: %d\n", (current_loc - 1), arr[current_loc - 1]);

		if (current_loc > max_size * 2) {
			max_size = max_size * 2;
			arr = (int *) realloc(arr, max_size);
		}

		token = strtok(NULL, ",");
	}
}

void sort_array_lazy(int *arr) {

	int last = 0;
	while (arr[last]) {
		last++;
	}

	int temp;


	for (int i = 0; i < (last - 1); i++) {
		for (int m = 0; m < (last -i -1); m++) {
			//printf("%d numer\n", arr[m]);

			if ( arr[m] > arr[m+1] ) {
				temp = arr[m];
				arr[m] = arr[m+1];
				arr[m+1] = temp;
			}
		}
	}

}

void store_array(char *filename, int *arr) {

}









































