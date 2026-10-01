#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define WORD_SIZE 64
#define SIMPLE_DELIMITERS " ,.!?=()[]'\""

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
	FILE *f;
	
	char word[WORD_SIZE];
	int ch;

	if (argc < 2) {
		fprintf(stderr, "Please supply a text file argument\n");
		exit(1);
	}

	f = fopen(argv[1], "r");

	if (f == NULL) {
		fprintf(stderr, "Unable to open file '%s'", argv[1]);
		exit(1);
	}

	int offset = 0;
	while ((ch = fgetc(f)) != EOF) {
		if (isalpha(ch)) {
			word[offset] = ch;
			offset++;

			if (offset >= WORD_SIZE) {
				fprintf(stderr, "Buffer overflow\n");
				exit(1);
			}
		} else {
			if (offset > 0) {
				word[offset] = '\0';
				offset = 0;

				char letter = is_term_on_one_word(word);
				putchar((letter == '\0') ? ' ' : letter);
			}
		}
	}

	putchar('\n');

	fclose(f);

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