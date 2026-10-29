#include <stdio.h>

int main() {
	int ch;
	
	printf("Hexen Filter (Ctrl+D to finish): ");
	while((ch = getchar()) != EOF) {
		printf("%02X", ch);
	}
	putchar('\n');
	
	return 0;
};
