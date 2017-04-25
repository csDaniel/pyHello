#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define MINBUF	15
#define MAXBUF	32


int *read_array_file();
char *resize_container(char *container, int new_size);
int *char_to_int(char *content);
int *resize_t(int *content, ssize_t new_size);
void quicksort(int *arr, int low, int high);
void swap(int *a, int *b);
int partition(int *arr, int low, int high);
void quicksort(int *arr, int low, int high);


int main(int argc, char *argv[]) {

	printf("Hello World\n");


	int *arr;
	arr = read_array_file();

	int i = 0;
	while (arr[i]) {
		printf("number: %d,",arr[i]);
		i++;
	}
	printf("\n");


	quicksort(arr, 0, i);

	i = 0;
	while (arr[i]) {
		printf("number: %d,",arr[i]);
		i++;
	}
	printf("\n");

	return 0;
}

int *read_array_file() {
	char *filename = "rand_arr";

	int fd = open(filename, O_RDONLY);
	int stream = 1;
	int temp_size = MAXBUF;

	char buffer[MINBUF];
			printf("MALLOC TIME\n");


	char *content = (char*)malloc(sizeof(char) * temp_size);

			printf("MALLOC TIME\n");


	while (stream > 0) {
		memset(buffer, 0, MINBUF);
		stream = read(fd, buffer, MINBUF-1);
		strcat(content, buffer);

		if ((strlen(content) / temp_size) >  0.7) {
			temp_size = temp_size * 2;
			printf("MALLOC TIME\n");
			content = resize_container(content, temp_size);
		}

	}


	/* BIG OLD PRINT STATEMENT */
	//printf("Content: %s\n",content);

	int *t = char_to_int(content);
	printf("ASDF");
	//free(content);
	close(fd);
	return t;
}

int *char_to_int(char *content) {
	int cur_size = MAXBUF;
	int *t = (int*)malloc(sizeof(int) * cur_size);

	int loc = 0;
	char *token;

	printf("CHAR TO INT\n");

	token = strtok(content, ",");
	while (token != NULL) {
		t[loc] = atoi(token);

		if (sizeof(t)/sizeof(int) > cur_size * 0.7) {
			cur_size = cur_size * 2;
			t = resize_t(t, cur_size);
		}

		loc++;
		token = strtok(NULL, ",");
	}

	return t;
}

int *resize_t(int *content, ssize_t new_size){
	int *new_arr = (int*)malloc(sizeof(int) * new_size);
	int i = 0;

	printf("RESIZING %zd\n",new_size);

	while (content[i]) {
	//for (i = 0; i < (sizeof(content)/sizeof(int)/2); i++) {
		new_arr[i] = content[i];
		i++;
	}

	free(content);
	return (new_arr);
}

char *resize_container(char *container, int new_size) {

	printf("resizing char array to %i\n",new_size);
	//char *content = (char*)malloc(sizeof(char) * temp_size);

	char *new_cont = (char*)malloc(sizeof(char) * new_size);
	printf("resizing char array to %i\n",new_size);

	int i;
	for (i =0; i < strlen(container); i++) {
		new_cont[i] = container[i];
	}
	free(container);
	return (new_cont);
}


void quicksort(int *arr, int low, int high) {
	//printf("Sorting the array...\n");

	if (low < high) {
		int pi = partition(arr, low, high);

		quicksort(arr, low, pi-1);
		quicksort(arr, pi+1, high);
	}

}

int partition(int *arr, int low, int high) {
	int pivot = arr[high];
	int i = (low-1);

	int j;
	for (j = low; j <= high -1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[j]);
	return (i + 1);
}



void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}






























































