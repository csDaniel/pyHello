#include <stdio.h>
#include <stdlib.h>
#include <assert.h>





/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *return_array;
    return_array = (int *)malloc(sizeof(int)*numsSize);

    int a = 0;
    // loop through each value
    for (a = 0; a < numsSize; a++) {
    	int b = 0;
    	return_array[a] = 1;
    	// multiply based on all others
    	for (b = 0; b < numsSize; b++) {
    		if (b != a) {
    			return_array[a] = nums[b] * return_array[a];
    		}
    	}

    }

    return return_array;
}

void print_results(int* nums, int num_length) {
	int a = 0;
	printf("Results: ");
	for (a = 0; a < num_length; a++) {
		printf("%i \t",nums[a]);
	}
	printf("\n");
}

int main() {
	int *return_size, *r;

	int t1[] = {1,2,3,4};
	int t1_length = 4;
	r = productExceptSelf(t1, t1_length, return_size);
	print_results(r, t1_length);

	int t2[] = {0,0};
	int t2_l = 2;
	r = productExceptSelf(t2, t2_l, return_size);
	print_results(r, t2_l);


	return 0;
}
