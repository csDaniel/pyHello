#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAXBUF	512
#define MINBUF	8



// return an array of random numbers of unspecified length
int *make_array(int length);

// generate a temporary file to store them in
int generate_file(char *name);

int cleanup_file(char *name);

int store_info(char *filename, int *arr, int arr_len);

int read_info(char *filename); 


int main(int argc, char *argv[]) {
	printf("Hello World\n");
	int result;
	int *arr;

	if (argc != 3) {
		perror("./08_temp_files {filename} {size}\n");
		exit(-1);
	}

	result = generate_file(argv[1]);
	if (result) {
		printf("Error! Could not generate file!\n");
		exit(1);
	}

	arr = make_array(atoi(argv[2]));

	result = store_info(argv[1], arr, atoi(argv[2]));
	if (result) {
		printf("Error! Could not write to file!\n");
		exit(1);
	}	

	result = read_info(argv[1]);
	if (result) {
		printf("Error! Could not read the file!\n");
		exit(1);
	}


	result = cleanup_file(argv[1]);
	if (result) {
		printf("Error: Could not delete file!\n");
		exit(1);
	}

	return 0;

}

int store_info(char *filename, int *arr, int arr_len) {
	int fd;
	fd = open(filename, O_RDWR);
	if (fd < 0) {
		return 1;
	}

	char input[MINBUF];
	int res = 1;

		int i;
		for (i = 0; i < arr_len; i ++) {
			sprintf(input, "%d,", arr[i]);
			//strcat(input, ",");
			res = write(fd, input, MINBUF);
			memset(input, 0, MINBUF);
		}
	close(fd);
	return 0;
}

int generate_file(char *filename) {
	int fd;
	fd = open(filename, O_CREAT, 0666);
	if (fd < 0) {
		return 1;
	}

	close(fd);
	return 0;
}

int cleanup_file(char *filename) {
	int rmv;

	rmv = remove(filename);

	return rmv;
}

int *make_array(int size) {
	int *arr = (int*) malloc (sizeof(int) * size);

	int i;
	for (i = 0; i < size; i++) {
		arr[i] = (i+1);
	}

	return arr;
}

int read_info(char *filename) {
	int fd, res; 
	char *buffer = (char *) malloc (sizeof(char) * MINBUF);
	//char *buffer = (char *) malloc (sizeof(char) * MAXBUF);

	fd = open(filename, O_RDONLY);
	if (fd < 0) {
		return 1;
	}

	res = 1;
	while (res) {
		//res = read(fd, buffer, MIN);
		res = read(fd, buffer, MINBUF);
		printf("ContentS: %s \n", buffer);

		//memset(buffer, 0, MAXBUF);
		memset(buffer, 0, MINBUF);
	}

	free(buffer);
	close(fd);
	return 0;

}





















































