#include <stdio.h>
#include <stdlib.h>

char *strrev(char *string);

int main () {
	char string[] = "A string dwelling in memory";

	printf("Original string: %s\n", string);
	
	char *reversed = strrev(string);
	printf("Reversed string: %s\n", reversed);
	
	return 0;
}

char *strrev(char *string) {
	unsigned int size = 0;

	if (string != NULL) {
		while(string[size] != '\0') {
			size++;
		}
	}

	char *new_string = (char *) malloc(sizeof(char) * (size+1));
	if (new_string == NULL) {
		fprintf(stderr, "Unable to allocate %d bytes of memory for the new string\n", (size+1));
		exit(1);
	}

	for (unsigned int i=0; i<size; i++) {
		new_string[i] = string[size-i-1];
	}
	new_string[size] = '\0';

	return new_string;
}
