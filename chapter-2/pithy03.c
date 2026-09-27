#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L_SIZE 32 
#define B_SIZE 256

int main() {
	const char* filename =  "pithy.txt";
	FILE* fp;

	char buffer[B_SIZE];
	char* r;
	char* entry;
	unsigned int items = 0;

	char** list_base = (char**) malloc(sizeof(char*) * L_SIZE);
	if (list_base == NULL) {
		fprintf(stderr, "Unable to allocate memory for the string list\n");
		exit(1);
	}
	

	fp = fopen(filename, "r");

	if (fp == NULL) {
		fprintf(stderr, "Unable to open file %s\n", filename);
		exit(1);
	}

	while(!feof(fp)) {
		r = fgets(buffer, B_SIZE, fp);
		if (r == NULL)
			break;

		entry = (char*) malloc(sizeof(char) * strlen(buffer) + 1);
		if (entry == NULL) {
			fprintf(stderr, "Unable to allocate memory for the entry string\n");
			exit(1);
		}

		strcpy(entry, buffer);

		// Same as list_base[items] = entry
		*(list_base + items) = entry;
		
		items++;

		if (items % L_SIZE == 0 && !feof(fp)) {
			fprintf(stderr, "Buffer size too short to read the entire file\n");
			exit(1);
		}
	}

	for (int i=0; i<items; i++) {
		// Same as printf("%d: %s", i, list_base[i]);
		printf("%d: %s", i, *(list_base+i));
	}

	fclose(fp);
	
	return 0;
}
