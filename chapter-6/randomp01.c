#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	char ch;
	const int length = 10;
	
	srand((unsigned) time(NULL));
	
	printf("SILLY PASSWORD GENERATOR V1.0\n");
	for (int i=0; i<length; i++) {
		ch = rand() % ('~' - '!' + 1);
		putchar(ch+'!');
	}
	putchar('\n');

	return 0;
}
