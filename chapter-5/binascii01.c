#include <stdio.h>

#define STICKS 4

char *char_to_binary(int c);

int main() {
	printf("\t\tASCII TABLE\n\n");

	const short len = 128 / STICKS; 

	for (int i=0; i<STICKS; i++) {
		printf("Bin\tC\t|\t");
	}

	putchar('\n');
	for (int i=0; i<len; i++) {
		for (int j=0; j<STICKS; j++) {
			int actual = i + len * j;
			printf("%s\t%c\t|\t", char_to_binary(actual), actual);
		}
		putchar('\n');
	}
	
	return 0;
}

char *char_to_binary(int c) {
	static char bin[9];

	int i=7;
	while(i>=0) {
		bin[i] = c & 1 ? '1' : '0';
		c >>= 1;
		i--;
	}
	bin[8] = '\0';

	return bin;
}
