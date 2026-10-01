#include <stdio.h>
#include <ctype.h>

#define PHRASE_SIZE 64

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
	char phrase[PHRASE_SIZE];
	char ch;
	int i = 0;

	printf("NATO Translator\n");
	printf("Enter a word or phase (up to %d characters): ", PHRASE_SIZE);
	fgets(phrase, PHRASE_SIZE, stdin);

	while(i < PHRASE_SIZE && phrase[i]) {
		ch = toupper(phrase[i]);

		if (isalpha(ch))
			printf("%s ", nato[ch - 'A']);

		i++;
	}

	putchar('\n');

	return 0;
}