#include <stdio.h>
#include <ctype.h>

#define LETTERS_SIZE 26

int main() {
	int ch;
	int shift = 'A' - 'D';

	printf("D-to-A Stream Filter (Ctrl+D to finish)\n");
	while ((ch = getchar()) != EOF) {
		if (isalpha(ch)) {
			ch += shift;

			if (ch < 'A' || (ch > 'Z' && ch < 'a')) {
				ch += 26;
			}
		}
		
		putchar(ch);
	}

	return 0;
}
