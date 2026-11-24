#include <stdio.h>

void strtabs(char *str, int tab);

int main() {
	char *texts[4] = {
		"Hello\tHi\tHowdy\n",
		"\tLa\tLa\n",
		"Constantinople\tConstantinople\n",
		"Pope is\na rockstar\n"
	};
	
	printf("Original:\n");
	for (int i=0; i<4; i++) {
		printf("%s\n", texts[i]);
	}

	for (int i=1; i<5; i++) {
		int spaces = (1 << i);
		printf("\nTab Width: %d\n", spaces);

		for (int j=0; j<4; j++) {
			strtabs(texts[j], spaces);
		}
	}
	
	return 0;
}

void strtabs(char *str, int tab) {
	int column = 0, spaces = 0;

	while(*str) {
		if (*str == '\t') {
			spaces = tab - (column % tab);
			while(spaces--) {
				putchar(' ');
				column++;
			}
		} else {
			putchar(*str);

			if (*str == '\n') {
				column = 0;
			} else {
				column++;
			}
		}

		str++;
	}
}
