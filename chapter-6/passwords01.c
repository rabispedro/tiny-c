#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASS_SIZE 32

char *add_word();
char *add_number();
char *add_symbol();

int main() {
	srand((unsigned) time(NULL));

	char password[PASS_SIZE];
	password[0] = '\0';

	printf("WORDLY PASSWORD GENERATOR V1.0\n");

	strcpy(password, add_word());
	strcat(password, add_number());
	strcat(password, add_word());
	strcat(password, add_symbol());
	strcat(password, add_word());

	printf("%s\n", password);

	return 0;
}

char *add_word() {
	char *vocabulary[] = {
		"Orange", "Grape", "Apple", "Banana",
		"coffee", "tea", "juice", "beverage",
		"happY", "grumpY", "bashfuL", "sleepY"
	};

	int r = rand() % (sizeof(vocabulary) / sizeof(char *));
	return vocabulary[r];
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
