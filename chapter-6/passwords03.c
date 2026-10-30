#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FILENAME_SIZE 32
#define WORD_SIZE 64
#define VOCABULARY_SIZE 16
#define PASSWORD_SIZE 32

struct term {
	char filename[FILENAME_SIZE];
	int size;
	char **words;
} typedef Term;

void build_vocabulary(Term *t);
char *add_word(Term t);
char *add_number();
char *add_symbol();
void check_caps(char *word);

int main() {
	srand((unsigned) time(NULL));

	Term nouns = { "nouns.txt", 0, NULL };
	Term verbs = { "verbs.txt", 0, NULL };
	Term adjectives = { "adjectives.txt", 0, NULL };

	build_vocabulary(&nouns);
	build_vocabulary(&verbs);
	build_vocabulary(&adjectives);

	char password[PASSWORD_SIZE];
	password[0] = '\0';

	printf("WORDLY PASSWORD GENERATOR V1.2\n");

	strcpy(password, add_word(adjectives));
	strcat(password, add_number());
	strcat(password, add_word(nouns));
	strcat(password, add_symbol());
	strcat(password, add_word(verbs));
	check_caps(password);

	printf("%s\n", password);

	return 0;
}

void build_vocabulary(Term *t) {
	t->words = (char **) malloc(sizeof(char *) * VOCABULARY_SIZE);
	if (t->words == NULL) {
		fprintf(stderr, "Unable to allocate memory for the vocabulary\n");
		exit(1);
	}

	char buffer[WORD_SIZE];
	char *word, *entry;

	FILE *f = fopen(t->filename, "r");
	if (f == NULL) {
		fprintf(stderr, "Unable to open file: '%s'\n", t->filename);
		exit(1);
	}

	while(!feof(f)) {
		word = fgets(buffer, WORD_SIZE, f);
		if (word == NULL) {
			break;
		}
		// Trimming the endline
		word[strlen(word) - 1] = '\0';

		entry = (char *) malloc(sizeof(char) * strlen(buffer) + 1);
		if (entry == NULL) {
			fprintf(stderr, "Unable to allocate memory for entry string\n");
			exit(1);
		}

		strcpy(entry, buffer);
		t->words[t->size] = entry;
		t->size++;

		if (t->size % VOCABULARY_SIZE == 0) {
			t->words = (char **) realloc(t->words, sizeof(char *) * (t->size + VOCABULARY_SIZE));
			if (t->words == NULL) {
				fprintf(stderr, "Unable to reallocate memory to %d strings\n", (t->size + VOCABULARY_SIZE));
				exit(1);
			}
		}
	}

	fclose(f);
}

char *add_word(Term t) {
	int r = rand() % t.size;
	return t.words[r];
}

char *add_number() {
	static char n[2];

	n[0] = '0' + rand() % 10;
	n[1] = '\0';

	return n;
}

char *add_symbol() {
	char symbols[8] = "!@#$%*_-";
	static char s[2];

	s[0] = symbols[rand() % 8];
	s[1] = '\0';

	return s;
}

void check_caps(char *word) {
	const int size = strlen(word);
	unsigned short hasUpper = 0;

	for(int i=0; i < size && !hasUpper; i++) {
		if (word[i] >= 'A' && word[i] <= 'Z') {
			hasUpper = 1;
		}
	}

	while (!hasUpper) {
		int r = rand() % size;
		if (word[r] >= 'a' && word[r] <= 'z') {
			hasUpper = 1;
			word[r] -= ('a' - 'A');
		}
	}
}