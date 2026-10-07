#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand((unsigned) time(NULL));

	int ch;

	printf("SaRcAsTiC Stream Filter (Ctrl+D to finish)\n");
	while((ch = getchar()) != EOF) {
		int decision = rand() % 2;
		putchar(decision ? toupper(ch) : tolower(ch));
	}

	return 0;
}
