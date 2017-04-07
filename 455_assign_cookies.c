
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
Assume you are an awesome parent and want to give your children some cookies. But, you should 
give each child at most one cookie. Each child i has a greed factor gi, which is the minimum 
size of a cookie that the child will be content with; and each cookie j has a size sj. 
If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. Your 
goal is to maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive. 
You cannot assign more than one cookie to one child.

Input: [1,2,3], [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.


Input: [1,2], [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
*/


int get_key(int hash_val, int table_size) {
	//int hash_key = hash_val % table_size;
	return (hash_val % table_size);

}

int find_content_children(int *g, int gSize, int *s, int sSize) {

	int jar_size = 0;
	int hash_key;
	if (gSize > sSize) {
		jar_size = gSize;
	} else { 
		jar_size = sSize; 
	}

	int **cookie_jar = (int *)malloc(sizeof(int *) * jar_size);
	int i;
	for (i = 0; i < jar_size; i++) {
		cookie_jar[i] = (int *)malloc(sizeof(int) * 2);
	}

	//
	if (gSize > sSize) {
		for (i = 0; i < jar_size; i++) {
			// proccess g[i]
			hash_key = get_key(g[i], jar_size)
			if (cookie_jar[i][0] == g[i]) {
				cookie_jar[i][1]++;
			} else if (cookie_jar[i][0] == NULL) {
				cookie_jar[i][0] = g[i];
				cookie_jar[i][1]++;
			} else {
				// current position is taken~
				int next = i;
				while (cookie_jar[next][0] != NULL) {
					next++;
					if (next >= jar_size) {
						next = 0;
					}
				}
				cookie_jar[next][0] = g[i];
				cookie_jar[next][1]++;
			}
	}


	cookie_jar[1][1] = 445;	
	printf(" %i \n", cookie_jar[1][1]);

	for (i = 0; i < jar_size; i++) {
		free(cookie_jar[i]);	
	}
	free(cookie_jar);
	return 0;
}




int main() {
	printf("Hello World \n");
	int children[] = {1,2,3};
	int cookies[] = {1,1};

	int r = 0;
	r = find_content_children(children, 3, cookies, 2);



	return 0;
}





















