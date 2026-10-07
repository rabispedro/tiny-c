#include <stdio.h>

#define TERMINAL_SCREEN_SIZE 80

int main() {
	int ch, cont=0;

	while ((ch = getchar()) != EOF) {
		if (ch == '\n') {
			printf("\n");
		} else {
			if (cont + 3 > TERMINAL_SCREEN_SIZE) {
				printf("\n%02X ", ch);
				cont = 0;
			} else {
				printf("%02X ", ch);
				cont += 3;
			}
		}
	}

	return 0;
}