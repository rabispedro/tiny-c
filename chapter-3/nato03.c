#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

char is_term(char *term);
char is_term_on_one_word(char *term);

int main(int argc, char *argv[]) {
	char phrase[PHRASE_SIZE];
	char *match;
	char ch;

	printf("NATO Decoder\n");
	printf("NATO word or phrase (up to %d characters): ", PHRASE_SIZE);

	fgets(phrase, PHRASE_SIZE, stdin);

	match = strtok(phrase, " ");

	while (match) {
		if ((ch = is_term_on_one_word(match)) != '\0') {
			putchar(ch);
		}

		match = strtok(NULL, " ");
	}

	putchar('\n');

	return 0;
}

char is_term(char *term) {
	char *t;

	for (int x=0; x<26; x++) {
		const char* n = nato[x];
		t = term;

		while (*n != '\0') {
			if ((*n | 0x20) != (*t | 0x20))
				break;

			n++;
			t++;
		}

		if (*n == '\0')
			return *nato[x];
	}

	return '\0';
}

char is_term_on_one_word(char *term) {
	int index = toupper(term[0]) - 'A';
	char *t;

	const char* n = nato[index];
	t = term;

	while (*n != '\0') {
		if ((*n | 0x20) != (*t | 0x20))
			break;

		n++;
		t++;
	}

	if (*n == '\0')
		return *nato[index];

	return '\0';
}