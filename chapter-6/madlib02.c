#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FILENAME_SIZE 32
#define WORD_SIZE 64
#define VOCABULARY_SIZE 16

struct term {
	char filename[FILENAME_SIZE];
	int size;
	char **words;
} typedef Term;

void build_vocabulary(Term *t);
char *add_word(Term t);

int main() {
	srand((unsigned) time(NULL));

	Term nouns = { "nouns.txt", 0, NULL };
	Term verbs = { "verbs.txt", 0, NULL };
	Term adjectives = { "adjectives.txt", 0, NULL };

	build_vocabulary(&nouns);
	build_vocabulary(&verbs);
	build_vocabulary(&adjectives);

	printf("Will you please take the %s %s ", add_word(adjectives), add_word(nouns));
	printf("and %s the %s?\n", add_word(verbs), add_word(nouns));

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
