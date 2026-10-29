#include <stdio.h>

#define BYTES_PER_LINE 18
#define LENGTH (BYTES_PER_LINE*3+1)

int main() {
	char line[LENGTH];
	int ch, x=0;

	printf("HEX DECODE v1.0 Filter (Ctrl+D to finish)\n");
	
	while((ch = getchar()) != EOF) {
		line[x] = ch;
		x++;

		if (ch == '\n' || x == LENGTH) {
			if(line[x-1] == '\n') {
				line[x-1] = '\0';
			} else {
				line[x] = '\0';
			}

			printf("%s\n", line);
			x = 0;
		}
	}
	
	printf("\nHEX DECODE END\n");
	
	return 0;
}