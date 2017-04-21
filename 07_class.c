#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAXBUF 512
#define MINBUF 16


typedef struct newClass {
	char name[MINBUF];
	int value;

	void (*assign_name)(const char *input); 

} NC;



int main(int argv, char* argc[]) {
	printf("Working with a class but it's not really a class!\n");

	NC *item = (NC *) malloc( sizeof(NC));

	strcpy(item->name, "Banana");
	printf("item name: %s\n", item->name);

	item->assign_name("Cheese");

	printf("item name: %s\n", item->name);





	free(item);

	return 0;
}

void assign_name(const NC *obj, const char *input) {
	strcpy(obj->name, input);
}




































































