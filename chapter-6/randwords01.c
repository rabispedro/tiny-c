#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *add_word();

const char *vocabulary[] = {
	"orange", "grape", "apple", "banana",
	"coffee", "tea", "juice", "beverage",
	"happy", "grumpy", "bashful", "sleepy",
	"java", "cplusplus", "lua", "rust"
};

int main() {
	srand((unsigned) time(NULL));

	for(int i=0; i<3; i++) {
		printf("%s ", add_word());
	}
	putchar('\n');

	return 0;
}

const char *add_word() {
	int r = rand() % (sizeof(vocabulary) / sizeof(char *));
	return vocabulary[r];
}
