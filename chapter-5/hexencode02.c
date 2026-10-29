#include <stdio.h>

#define BYTES_PER_LINE 18

int main() {
	int ch, bytes=0, checksum;
	int hexbytes[BYTES_PER_LINE];

	printf("HEX ENCODE v2.0 Filter (Ctrl+D to finish)\n");

	while((ch = getchar()) != EOF) {
		printf("%02X", ch);
		hexbytes[bytes] = ch;
		bytes++;

		if (bytes == BYTES_PER_LINE) {
			checksum = 0;
			bytes = 0;
			
			for(int i=0; i<BYTES_PER_LINE; i++) {
				checksum += hexbytes[i];
			}

			printf(" %02X\n", (checksum % 0x100));
		} else {
			putchar(' ');
		}
	}

	if (bytes > 0) {
		checksum = 0;

		for(int i=0; i<bytes; i++) {
			checksum += hexbytes[i];
		}

		printf("%02X\n", (checksum % 0x100));
	}

	printf("\nHEX ENCODE END\n");

	return 0;
}
