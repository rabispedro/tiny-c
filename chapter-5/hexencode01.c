#include <stdio.h>

#define BYTES_PER_LINE 18

int main() {
	int ch, bytes = 0;

	printf("HEX ENCODE v1.0 Filter (Ctrl+D to finish)\n");

	while((ch = getchar()) != EOF) {
		printf("%02X", ch);
		bytes++;

		if (bytes == BYTES_PER_LINE) {
			bytes = 0;
			putchar('\n');
		} else {
			putchar(' ');
		}
	}

	printf("\nHEX ENCODE END\n");

	return 0;
}
