#include <stdio.h>
#include <ctype.h>

int main() {
	int ch;

	printf("URL Encoder (Ctrl+D to finish)\n");

	while ((ch = getchar()) != EOF) {
		if (ch == '-' || ch == '.' || ch == '_' || ch == '*') {
			putchar(ch);
		} else if (ch == ' ') {
			putchar('+');
		} else if (isalnum(ch)) {
			putchar(ch);
		} else {
			printf("%%%02X", ch);
		}
	}
	
	return 0;
}