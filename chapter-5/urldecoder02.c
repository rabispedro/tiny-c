#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int to_hex(int c);

int main() {
	int ch, a, b;

	printf("URL DECODER v2.0 (Ctrl+D to finish)\n");

	while ((ch = getchar()) != EOF) {
		if (ch == '-' || ch == '.' || ch == '_' || ch == '*' || ch == '\n') {
			putchar(ch);
		} else if (ch == '+') {
			putchar(' ');
		} else if (isalnum(ch)) {
			putchar(ch);
		} else if (ch == '%') {
			ch = getchar();
			if (ch == EOF) {
				break;
			}
			a = to_hex(ch);

			if (a == -1) {
				fprintf(stderr, "Invalid hex character\n");
				exit(1);
			}

			ch = getchar();
			if (ch == EOF) {
				break;
			}
			b = to_hex(ch);

			if (b == -1) {
				fprintf(stderr, "Invalid hex character\n");
				exit(1);
			}

			putchar((a<<4)+b);
		} else {
			fprintf(stderr, "Invalid hex character\n");
			exit(1);
		}
	}
	
	return 0;
}

int to_hex(int c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}

	if (c >= 'A' && c <= 'F') {
		return c - 'A' + 0xA;
	}

	if (c >= 'a' && c <= 'f') {
		return c - 'a' + 0xA;
	}

	return -1;
}