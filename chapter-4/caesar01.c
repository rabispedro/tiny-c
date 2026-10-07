#include <stdio.h>
#include <ctype.h>

#define ROT_FACTOR 13

int main() {
	int ch;

	printf("Caesar rot13 Stream Filter (Ctrl+D to finish)\n");
	while ((ch = getchar()) != EOF) {
		if (isalpha(ch)) {
			if (toupper(ch) >= 'A' && toupper(ch) <= 'M') {
				ch += ROT_FACTOR;
			} else {
				ch -= ROT_FACTOR;
			}
		}
		putchar(ch);
	}

	return 0;
}
