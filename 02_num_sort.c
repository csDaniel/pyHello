#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>	// for close#
#include <string.h>
#define BUFFER 256
#define SHORT_BUFFER 16


typedef struct Node {
	struct Node *left;
	struct Node *right;
	int value;
} node;


// read the contents of the file
void read_file();
struct Node *create_tree();
struct Node *create_node(int val);
void add_node(struct Node *root, int value);
void parse_chunk(char *raw_input, struct Node *root);
void destroy_tree(struct Node *leaf);
void insert_node(int val, struct Node **root);


void play_with_tree();


// seperate the contents of the file into a data structure
// re-sort the cotents of the file into a binary tree
// sort the binary tree using some algorithm 

int main(int argv, char *argc[] ) {
	printf("The number of arguments passed are: %d\n", argv);

	int i;
	for (i = 0; i < argv; i++) {
		printf("ARGV #%d: %s\n",i,argc[i]);
	}

	struct Node *node = create_tree();
	read_file(argc[1], node);

	//play_with_tree();

	struct Node *search = node;
	while (search->left != NULL) {
		printf("Current lefty val: %d\n",search->value);
		search = search->left;
	}
	printf("Left most value = %d\n", search->value);

	return 0;
}


void read_file(char *filename, struct Node *root) {
	//char *filename = "rand_arr";
	int fd;
	int nread = 1;
	char read_out[BUFFER];

	fd = open(filename, O_RDONLY);
	if (fd < 0) {
		perror("Error opening file\n");
		exit(-1);
	}

	while (nread > 0) {
		memset(read_out,0,strlen(read_out));
		nread = read(fd, read_out, SHORT_BUFFER);
		printf("output: %s\n",read_out);

		// here is where I would input shit into the BST
		parse_chunk(read_out, &(*root));

	}
	close(fd);
}

void parse_chunk(char *raw_input, struct Node **root) {
	// theres a string as raw_input as "2, 45, 12, 46,"
	char *token = strtok(raw_input, ",");
	while (token) {
		insert_node(atoi(token), &root);

		printf("Current input value: %d\n", atoi(token));
		token = strtok(NULL, ",");
	}

}

struct Node *create_tree() {
	struct Node *temp_node;
	temp_node = malloc(sizeof(struct Node));
	temp_node->value = 0;
	temp_node->left = NULL;
	temp_node->right = NULL;
	return temp_node;
}

struct Node *create_node(int val) {
	struct Node *temp_node;
	temp_node = malloc(sizeof(struct Node));
	temp_node->value = 0;
	temp_node->left = NULL;
	temp_node->right = NULL;
	return temp_node;
}

void destroy_tree(struct Node *leaf) {
	if ( leaf != 0) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		free(leaf);
	}
}


void play_with_tree() {
	int num_set[10]= {5,25,10,4,2,39,12,44,1,3};
	struct Node *root = 0;

	int i;
	for (i = 0; i < 10; i++) {
		insert_node(num_set[i], &root);
	}
	struct Node *search = root;
	while (search->left != NULL) {
		printf("Current lefty val: %d\n",search->value);
		search = search->left;
	}
	printf("Left most value = %d\n", search->value);

}

void insert_node(int val, struct Node **root) {
	if ( *root == 0) {
		*root = (struct Node*) malloc( sizeof (struct Node));
		(*root)->value = val;
		// init children to 0
		(*root)->left = 0;
		(*root)->right = 0;
	} else if (val < (*root)->value) {
		insert_node( val, &(*root)->left);
	} else if (val > (*root)->value) {
		insert_node( val, &(*root)->right);
	}
}

struct Node *search(int value, struct Node **root) {
	if (*root != 0) {
		if (value == (*root)->value) {
			return *root;
		} else if (value < (*root)->value) {
			return search(value, &((*root)->left));
		} else if (value > (*root)->value) {
			return search(value, &((*root)->right));
		}
	}
	else return 0;
}
























