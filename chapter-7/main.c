#include <stdio.h>

#include "headers/mystring.h"

int main() {
	char *texts[4] = {
		"Hello\tHi\tHowdy\n",
		"\tLa\tLa\n",
		"Constantinople\tConstantinople\n",
		"Pope is\na rockstar\n",
	};
	
	printf("Original:\n");
	for (int i=0; i<4; i++) {
		printf("%s\n", texts[i]);
	}

	for (int i=1; i<5; i++) {
		int spaces = (1 << i);
		printf("\nTab Width: %d\n", spaces);

		for (int j=0; j<4; j++) {
			strtabs(texts[j], spaces);
		}
	}

	printf("With 'aaa' inserted:\n");
	for (int i=0; i<4; i++) {
		printf("%s", strinsert(texts[i], "aaa", 4));
	}

	printf("Capitalizing:\n");
	for (int i=0; i<4; i++) {
		strcaps(texts[i]);
		printf("%s", texts[i]);
	}

	return 0;
}
