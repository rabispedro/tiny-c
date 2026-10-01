#include <stdio.h>
#include <string.h>

#define TEXT_SIZE 64

int main() {
	char some_text[TEXT_SIZE];
	char *match;

	printf("Type some text (up to %d characters): ", TEXT_SIZE);
	fgets(some_text, TEXT_SIZE, stdin);

	match = strtok(some_text, " ");

	while(match) {
		printf("%s\n", match);
		match = strtok(NULL, " ");
	}

	return 0;
}
