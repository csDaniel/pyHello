#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 256
#define MINSIZE 16


typedef struct DLL {
	int value;
	struct DLL *next;
	struct DLL *prev;

} dll;

// initialize the DLL
dll *init_dll();

// add a value to the DLL
void add_node(dll *node, int val);

// turn the array into a linked list, because why not
void make_ll(int *arr);

void arr_to_dll(dll *node, int *val);

void print_dll(dll *node);

void print_dll_reverse(dll *node);

// remove the node if found
void remove_node(dll* node, int val);

int main(int argv, char *argc[]) {

	printf("starting...\n");
	dll *start = init_dll();


	int arr[MAXSIZE];

	// make an array of random numbers
	srand(time(NULL));
	int i;
	for (i = 0; i < MAXSIZE; i++) {
		arr[i] = rand() % MAXSIZE + 1;
		//printf("%d \n", arr[i]);
	}

	arr_to_dll(start, arr);
	print_dll(start);

	printf("Removing values 100-200\n");
	for (i = 100; i <= 200; i++) {
		remove_node(start, i);
	}

	printf("REVERSE\n");
	print_dll_reverse(start);

	return 0;
}

dll *init_dll() {

	dll *start = (dll *) malloc(sizeof(dll));

	start->next = start;
	start->prev = start;
	start->value = 0;

	return start;
}

void add_node(dll *node, int val) {

	dll *current = node;
	dll *base = node;

	while (current->next->value < val && current->next != base) {
		current = current->next;
	}

	dll *new_node = init_dll();
	new_node->value = val;

	// insert after current
	new_node->next = current->next;
	new_node->prev = current;
	current->next->prev = new_node;
	current->next = new_node;

}

void arr_to_dll(dll *node, int *arr) {
	int i;
	for (i = 0; i < MAXSIZE; i++) {
		add_node(node, arr[i]);
	}
}

void print_dll(dll *node) {
	dll *base = node;
	dll *current = node;

	while( current->next != base) {
		printf("%d->",current->value);
		current = current->next;
	}

	printf("\n");
}

void print_dll_reverse(dll *node) {
	dll *base = node;
	dll *current = node;

	while (current->prev != base) {
		printf("%d->",current->value);
		current = current->prev;

	}
	printf("\n");

}


void remove_node(dll* node, int val) {
	printf("Attempting to remove node value %d\n", val);

	dll *current = node;
	dll *base = node;

	while (current->value != val) {
		current = current->next;
		if (current->next == base) {
			printf("Value not found!\n");
			break;
		}
	}

	// value found
	base = current;
	current->next->prev = current->prev;
	current->prev->next = current->next;
	printf("Value removed from tree\n");
	free(current);

}
































