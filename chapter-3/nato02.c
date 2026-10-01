#include <stdio.h>
#include <stdlib.h>
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

int main(int argc, char *argv[]) {
	FILE *f;
	int ch;

	if (argc < 2) {
		fprintf(stderr, "Please supply a text file argument\n");
		exit(1);
	}

	f = fopen(argv[1], "r");

	if (f == NULL) {
		fprintf(stderr, "Unable to open file '%s'\n", argv[1]);
		exit(1);
	}

	while((ch = fgetc(f)) != EOF) {
		if (isalpha(ch)) {
			printf("%s ", nato[toupper(ch) - 'A']);
		} else if ((char) ch == '\n') {
			printf("\n");
		}
	}
	
	putchar('\n');

	fclose(f);

	return 0;
}