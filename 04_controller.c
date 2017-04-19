#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>

#define		MAX_COUNT	20
#define		BUF_SIZE	100
#define		BUFFER		128

/*sources: 
http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html



*/

//fork to run 01_num_array.c
//fork to run 03_num_array.c

void fork_something();
void parent_process();
void child_process();
void parent_child();

//parse what the user types 
void controller();

// ls command
void print_folder_contents();

// cat command
void cat_file_contents();
// cd command


int main(int argv, char *argc[]) {
	printf("Hello World\n");


	//fork_something();
	//parent_child();

	controller();
	printf("asdf\n");

	return 0;
}

void controller() {
	int running = 1;
	char input[BUFFER];
	while (running) {
		//memset(input, 0, BUFFER);
		printf("Action command: ");
		//fgets(input, BUFFER, stdin);
		scanf("%s", input);
		printf("You typed: %s\n", input);
		if (strcmp(input, "exit") == 0) {
			printf("Exiting the program\n");
			break;
		}


	}
	printf("asdf\n");
}

void fork_something() {
	pid_t pid;
	int i;
	char buf[BUF_SIZE];

	fork();
	fork();
	fork(); 
	pid = getpid();

	for (i = 1; i <= MAX_COUNT; i++) {
		sprintf(buf, "This lne is from pid %d, value = %d\n", pid, i);
		write(1, buf, strlen(buf));
	}
}


void parent_child() {
	pid_t pid;

	pid = fork();
	if (pid == 0) {
		child_process();
	} else {
		parent_process();
	}
	
}

void parent_process() {
	int i;
	for (i = 0; i < MAX_COUNT; i++) {
		printf("This line is from the parent, value: %d\n", i);
	}
	printf("\t*** the parent is done ***\n");
}

void child_process() {
	int i;
	for (i = 0; i < MAX_COUNT; i++) {
		printf("\tThis line is from the child, value: %d\n", i);
	}
	printf("\t*** the child is done ***\n");
}

void print_folder_contents() {
	
	
}












































































