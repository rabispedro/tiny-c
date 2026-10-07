#include <ctype.h>
#include <stdio.h>

#define TERMINAL_SCREEN_SIZE 80

const char *nato[] = {
	"Alfa", "Bravo", "Charlie", "Delta",
	"Echo", "Foxtrot","Golf", "Hotel",
	"India", "Juliett", "Kilo", "Lima",
	"Mike", "November", "Oscar", "Papa",
	"Quebec", "Romeo", "Sierra", "Tango",
	"Uniform", "Victor", "Whiskey", "Xray",
	"Yankee", "Zulu"
};

int main() {
	int ch;

	while ((ch = getchar()) != EOF) {
		if (isalpha(ch)) {
			printf("%s ", nato[toupper(ch) - 'A']);
		}
		if (ch == '\n') {
			putchar(ch);
		}
	}
	putchar('\n');

	return 0;
}