#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b);
int partition( int arr[], int low, int high);
void quick_sort( int arr[], int l, int r);



int main(int argc, char *argv[]) {
	int arr[] = { 9,12,44,65,32,98,3,5,6,8 };


	int i;
	printf("Pre-sort:\t[ ");
	for (i =0; i < 10; i++) {
		printf("%d ",arr[i]);
	}
	printf(" ]\n\n");

	quick_sort(arr, 0, 9);

	printf("Sorted:\t\t[ ");
	for (i = 0; i < 10; i++) {
		printf("%d ",arr[i]);
	}
	printf(" ]\n\n");

	return 0;
}




void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition( int arr[], int low, int high) {
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

void quick_sort( int arr[], int l, int r) {
	int j;

	if (l < r) {
		// divide and conquer
		j = partition(arr, l, r);
		quick_sort(arr, l, j-1);
		quick_sort(arr, j+1, r);
	}
}














