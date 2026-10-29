#include <stdio.h>

int to_hex(int c);

int main() {
	int ch, a, b;

	printf("URL DECODER v1.0 (Ctrl+D to finish)\n");

	while ((ch = getchar()) != EOF) {
		if (ch == '%') {
			ch = getchar();
			if (ch == EOF) {
				break;
			}
			a = to_hex(ch);

			ch = getchar();
			if (ch == EOF) {
				break;
			}
			b = to_hex(ch);

			putchar((a<<4)+b);
		} else {
			putchar(ch);
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