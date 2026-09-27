#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define B_SIZE 256

int main() {
	const char* filename =  "pithy.txt";
	FILE* fp;

	char buffer[B_SIZE];
	char* r;

	fp = fopen(filename, "r");

	if (fp == NULL) {
		fprintf(stderr, "Unable to open file %s\n", filename);
		exit(1);
	}

	while(!feof(fp)) {
		r = fgets(buffer, B_SIZE, fp);
		if (r == NULL)
			break;

		printf("%s", buffer);
	}

	fclose(fp);
	
	return 0;
}
