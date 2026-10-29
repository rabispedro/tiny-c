#include <stdio.h>

int tohex(char c);

int main() {
	int a, b, ch;
	
	printf("Hex De-Filter (Ctrl+D to finish): ");
	while(1) {
		ch = getchar();
		
		if (ch == EOF) {
			break;
		}

		a = tohex(ch);

		if (a < 0) {
			break;
		}

		a <<= 4;

		ch = getchar();
		
		if (ch == EOF) {
			break;
		}

		b = tohex(ch);

		if (b < 0) {
			break;
		}
		
		putchar(a+b);
	}
	putchar('\n');
	
	return 0;
};

int tohex(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}

	if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 0xA;
	}

	return -1;
}