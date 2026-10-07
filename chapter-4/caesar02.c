#include <ctype.h>
#include <stdio.h>

#define LETTERS_SIZE 26

int main() {
	int ch;
	int shift = 'D' - 'A';

	printf("A-to-D Stream Filter (Ctrl+D to finish)\n");
	while ((ch = getchar()) != EOF) {
		if (isalpha(ch)) {
			ch += shift;

			if ((ch > 'Z' && ch < 'a') || ch > 'z') {
				ch -= LETTERS_SIZE;
			}
		}
		
		putchar(ch);
	}

	return 0;
}
