#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *add_noun();
const char *add_verb();
const char *add_adjective();

const char *nouns[] = {
	"orange", "grape", "apple", "banana",
	"coffee", "tea", "juice", "beverage"
};

const char *verbs[] = {
	"drink", "water", "sleep", "act",
	"think", "talk", "clear", "revenge"
};

const char *adjectives[] = {
	"handsome", "beautiful", "green", "little",
	"yellow", "talkative", "orange", "big"
};

int main() {
	srand((unsigned) time(NULL));

	printf("Will you please take the %s %s ", add_adjective(), add_noun());
	printf("and %s the %s?\n", add_verb(), add_noun());

	return 0;
}

const char *add_noun() {
	int r = rand() % (sizeof(nouns) / sizeof(char *));
	return nouns[r];
}

const char *add_verb() {
	int r = rand() % (sizeof(verbs) / sizeof(char *));
	return verbs[r];
}

const char *add_adjective() {
	int r = rand() % (sizeof(adjectives) / sizeof(char *));
	return adjectives[r];
}

