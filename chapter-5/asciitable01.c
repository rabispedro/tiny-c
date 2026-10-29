#include <stdio.h>

#define STICKS 4

int main() {
	printf("\t\tASCII TABLE\n\n");

	const short len = 128 / STICKS; 

	for (int i=0; i<STICKS; i++) {
		printf("Dec\tOct\tHex\tC\t|\t");
	}

	putchar('\n');
	for (int i=0; i<len; i++) {
		for (int j=0; j<STICKS; j++) {
			int actual = i + len * j;
			printf("%d\t%o\t%x\t%c\t|\t", actual, actual, actual, actual);
		}
		putchar('\n');
	}
	
	return 0;
}