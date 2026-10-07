#include <stdio.h>
#include <ctype.h>

int main() {
	int ch;

	printf("UPPERCASE Stream Filter (Ctrl+D to finish)\n");
	while((ch = getchar()) != EOF) {
		putchar(toupper(ch));
	}

	return 0;
}
