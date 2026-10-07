#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LETTERS_SIZE 26

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Missing %d argument(s).\n", (2 - argc));
		exit(1);
	}

	if (strlen(argv[1]) != 2) {
		fprintf(stderr, "Shift parameter must be 2 characters.\n");
		exit(1);
	}

	if (!isalpha(argv[1][0]) || !isalpha(argv[1][1])) {
		fprintf(stderr, "Shift parameters must be alphabetic.\n");
		exit(1);
	}

	int ch;
	int shift = toupper(argv[1][0]) - toupper(argv[1][1]);

	// printf("%d Stream Filter (Ctrl+D to finish)\n", shift);
	while ((ch = getchar()) != EOF) {
		if (isupper(ch)) {
			ch = 'A' + abs(ch + shift - 'A') % LETTERS_SIZE;
		} else if (islower(ch)) {
			ch = 'a' + abs(ch + shift - 'a') % LETTERS_SIZE;
		}
		putchar(ch);
	}

	return 0;
}
