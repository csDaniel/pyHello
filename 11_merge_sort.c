#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void merge(int arr[], int low, int mid, int high);
void merge_sort(int arr[], int left, int right);

int main( int argc, char *argv[]) {
	int arr[] = { 9,12,44,65,32,98,3,5,6,8 };

	int i;
	printf("Pre-sort:\t[ ");
	for (i =0; i < 10; i++) {
		printf("%d ",arr[i]);
	}
	printf(" ]\n\n");
	// SORTING FUNCTION GOES HERE //
	int arr_size = 10;
	merge_sort(arr, 0, arr_size-1);

	printf("Sorted:\t\t[ ");
	for (i = 0; i < 10; i++) {
		printf("%d ",arr[i]);
	}
	printf(" ]\n\n");

	return 0;
}

void merge(int arr[], int low, int mid, int high) {
	int i, j, k;
	int n1 = mid - low + 1;
	int n2 = high - mid;

	int left_arr[n1], right_arr[n2];

	// copy data into temp arrays
	for (i = 0; i < n1; i++) {
		left_arr[i] = arr[low+i];
	}
	for (j = 0; j < n2; j++) {
		right_arr[j] = arr[mid + 1 + j];

	}
	// merge the temp arrays
	i = 0;
	j = 0;
	k = low;
	while (i < n1 && j < n2) {
		if (left_arr[i] <= right_arr[j]) {
			arr[k] = left_arr[i];
			i++;
		} else {
			arr[k] = right_arr[j];
			j++;
		}
		k++;
	}
    // add back in the left and right sides
	while (i < n1) {
		arr[k] = left_arr[i];
		i++;
		k++;	
	}
	while (j < n2) {
		arr[k] = right_arr[j];
		j++;
		k++;
	}
}

void merge_sort(int arr[], int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;


		merge_sort(arr, left, middle);
		merge_sort(arr, middle+1, right);

		merge(arr, left, middle, right);
	}
}

