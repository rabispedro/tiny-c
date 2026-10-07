#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LETTERS_SIZE 26

int main(int argc, char *argv[]) {
	if (argc < 3) {
		fprintf(stderr, "Missing %d argument(s).\n", (3 - argc));
		exit(1);
	}

	int ch;
	int shift = argv[1][0] - argv[2][0];

	printf("%d Shift Stream Filter (Ctrl+D to finish)\n", shift);
	while ((ch = getchar()) != EOF) {
		if (isupper(ch)) {
			ch += shift;

			if (ch > 'Z') {
				ch -= LETTERS_SIZE;
			}

			if (ch < 'A') {
				ch += LETTERS_SIZE;
			}
		} else if (islower(ch)) {
			ch += shift;

			if (ch > 'z') {
				ch -= LETTERS_SIZE;
			}

			if (ch < 'a') {
				ch += LETTERS_SIZE;
			}
		}
		
		putchar(ch);
	}

	return 0;
}
