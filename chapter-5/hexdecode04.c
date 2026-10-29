#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_LINE 18
#define LENGTH (BYTES_PER_LINE*3+1)

void handle_encode_v1();
void handle_encode_v2();

int main() {
	char *r, line[LENGTH];

	r = fgets(line, LENGTH, stdin);
	if (r == NULL) {
		fprintf(stderr, "Invalid HEX ENCODE data\n");
		exit(1);
	}

	if (strncmp(line, "HEX ENCODE v1.", 14) == 0) {
		handle_encode_v1();
	} else if (strncmp(line, "HEX ENCODE v2.", 14) == 0) {
		handle_encode_v2();
	} else {
		fprintf(stderr, "Invalid HEX ENCODE data\n");
		exit(1);
	}
	
	return 0;
}

void handle_encode_v1() {
	char *r, line[LENGTH];
	int hex, ch, x=0;

	printf("HEX DECODE v2.0 Filter (Ctrl+D to finish)\n");
	while((ch = getchar()) != EOF) {
		line[x] = ch;
		x++;

		if (ch == '\n' || x == LENGTH) {
			if(line[x-1] == '\n') {
				line[x-1] = '\0';
			} else {
				line[x] = '\0';
			}

			if (strncmp(line, "HEX ENCODE END", 13) == 0) {
				break;
			}
			

			r = strtok(line, " ");
			while(r) {
				sscanf(r, "%02X", &hex);
				printf("%c", hex);
				r = strtok(NULL," ");
			}
			
			x = 0;
		}
	}

	printf("\nHEX DECODE END\n");
}

void handle_encode_v2() {
	char *r, line[LENGTH];
	int checksum, hex, ch, x=0;

	printf("HEX DECODE v2.0 Filter (Ctrl+D to finish)\n");
	while((ch = getchar()) != EOF) {
		line[x] = ch;
		x++;

		if (ch == '\n' || x == LENGTH) {
			if(line[x-1] == '\n') {
				line[x-1] = '\0';
			} else {
				line[x] = '\0';
			}

			if (strncmp(line, "HEX ENCODE END", 13) == 0) {
				break;
			}
			
			checksum = 0;
			r = strtok(line, " ");
			while(r) {
				sscanf(r, "%02X", &hex);
				printf("%c", hex);
				checksum += hex;
				r = strtok(NULL," ");
			}
			printf(" %02X\n", (checksum % 0x100));
			
			x = 0;
		}
	}

	if (x > 0) {
		checksum = 0;
		r = strtok(line, " ");
		while(r) {
			sscanf(r, "%02X", &hex);
			checksum += hex;
			r = strtok(NULL," ");
		}
		printf(" %02X\n", (checksum % 0x100));
	}

	printf("\nHEX DECODE END\n");
}