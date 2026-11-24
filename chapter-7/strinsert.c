#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strinsert(char *org, char *ins, int offset);

int main() {
	char str[] = "Well, this is another mess!";
	char inserted[] = "fine ";
	
	char *res = strinsert(str, inserted, 22);

	printf("str: '%s'\ninserted: '%s'\nres: '%s'\n", str, inserted, res);

	return 0;
}

char *strinsert(char *org, char *ins, int offset) {
	unsigned int original_size = 0, inserted_size = 0;

	while(org[original_size] != '\0') {
		original_size++;
	}

	while(ins[inserted_size] != '\0') {
		inserted_size++;
	}

	if (offset < 0) {
		offset = 0;
	} else if (offset > original_size) {
		offset = original_size;
	}

	char *new = (char *) malloc(sizeof(char) * (original_size + inserted_size) + 1);
	if (new == NULL) {
		fprintf(stderr, "Unable to allocate %d bytes of memory for the new string\n", (original_size + inserted_size + 1));
		exit(1);
	}

	// Inserting the first part of original string
	for (int i=0; i<offset; i++) {
		new[i] = org[i];
	}

	// Inserting the in-between string
	for (int i=0; i<inserted_size; i++) {
		new[i+offset] = ins[i];
	}

	// Inserting the rest part of original string
	for (int i=0; i<(original_size-offset); i++) {
		new[i+offset+inserted_size] = org[i+offset];
	}
	new[original_size+inserted_size] = '\0';

	return new;
}
