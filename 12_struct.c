#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


typedef struct new_struct{ 
	int *arr;
	int arr_size;
} dyn_arr;

// returns a random number
int get_rand();
void dyn_practice();
dyn_arr *dyn_init();
void resize_dyn(dyn_arr *d);
void dyn_delete(dyn_arr *d);

int main(int argc, char *argv[]) {
	srand(time(NULL));


	int arr_size = 100;
	int arr[arr_size];

	int i;

	for (i = 0; i < arr_size; i++) {
		arr[i] = get_rand();
	}


	for (i = 0; i < arr_size; i++) {
		printf("%d ,",arr[i]);
		if (i % 13 == 0) {
			printf("\n");
		}
	}
			printf("\n");

	dyn_practice();

	return 0;
}

int get_rand() {
	int i = rand() % 100 + 1;
	return i;
}

void dyn_practice() {
	dyn_arr *d = (dyn_arr*)malloc(sizeof(dyn_arr));
	d->arr_size = 25;
	printf("%d\n",d->arr_size);
	free(d);

	dyn_arr *a = dyn_init();
	printf("%d\n",a->arr_size);

	resize_dyn(a);
	printf("%d\n",a->arr_size);

	a->arr[0] = 33;

	dyn_delete(a);

	try:
		printf("%d\n",a->arr[0]);
	except:
		printf("errorrrororororo\n");
	//free(a);
}



void resize_dyn(dyn_arr *d) {
	int new_size = d->arr_size * 2;
	int *arr = (int*) malloc (sizeof(int) * new_size);
	
	int i;
	for (i = 0; i < d->arr_size; i++) {
		arr[i] = d->arr[i];
	}

	int *del = d->arr;
	d->arr = arr;
	d->arr_size = new_size;
	free(del);
}

dyn_arr *dyn_init() {
	dyn_arr *d = (dyn_arr*)malloc(sizeof(dyn_arr));
	d->arr_size = 16;
	d->arr = (int*)malloc(sizeof(int) * d->arr_size);

	return d;
}


void dyn_delete(dyn_arr *d) {
	// delete the int arr first!
	int *a = d->arr;
	free(a);

	dyn_arr *b = d;
	free(d);



}












