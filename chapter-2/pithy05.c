#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define L_SIZE 32 
#define B_SIZE 256

int main() {
	const char* filename =  "pithy.txt";
	FILE* fp;

	char buffer[B_SIZE];
	char* r;
	char* entry;
	unsigned int items = 0, index = 0;

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

		if (items % L_SIZE == 0) {
			list_base = (char**) realloc(list_base, sizeof(char*) * (items + L_SIZE));

			if (list_base == NULL) {
				fprintf(stderr, "Unable to reallocate memory to %d strings\n", (items + L_SIZE));
				exit(1);
			}
		}
	}

	srand((unsigned) time(NULL));
	index = rand() % (items-1);

	printf("Today's fortune:\n");

	// Same as printf("%s", list_base[index]);
	printf("\t%s", *(list_base+index));

	fclose(fp);

	free(r);
	free(entry);
	free(list_base);
	
	return 0;
}
