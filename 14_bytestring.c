#include <stdio.h>
#include <stdlib.h>

#define MK 		0xF1
#define AB 		0x20
#define END 	0x06



// float = 4 bytes, char = 1byte. 32bytes + 2 + 2
#define contSize	36
typedef struct {
	float valA;
	float valB;
	float valC;
	float valD;
}Con;

// set the Container to any value
void init_pkg(Con *pkg) {
	char *loc = &pkg;
	int pkg_size = ( sizeof(pkg) / sizeof(char));

	int i;
	for (i = 0; i < pkg_size; i++) {
		loc = MK;
		*loc++;
	}


}


int build_pkg(Con *pkg, char *prepared_pkg) {
	prepared_pkg[0] = MK;
	prepared_pkg[1] = AB;
	int complete_pkg = 2;

	int i;
	for (i = 0; i < (sizeof(pkg) / sizeof(char)); i++) {
		prepared_pkg[complete_pkg++] = pkg[i];
		if (pkg[i] == MK) {
			prepared_pkg[complete_pkg++] = pkg[i];
		}
	}

	prepared_pkg[complete_pkg++] = MK;
	prepared_pkg[complete_pkg++] = END;

	return complete_pkg;
}

void print_package(char *prepared_pkg, int buf) {
	int i;
	for (i = 0; i < buf; i++) {
		printf( "0x%c ",prepared_pkg[i]);
	}

	printf("\n");
}

int main(int argc, char *argv[]) {
	Con pkg;
	char prepared_pkg[36];
	int buf;

	init_pkg(&pkg);
	buf = build_pkg(&pkg, prepared_pkg);

	return 0;
}

