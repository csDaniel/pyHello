#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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





















