#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER 1
#define LOWER 6
#define NUM 1
#define SYM 2

void uppercase();
void lowercase();
void number();
void symbol();

int main() {
	srand((unsigned) time(NULL));
	printf("SILLY PASSWORD GENERATOR V1.2\n");
	
	uppercase();
	lowercase();
	number();
	symbol();

	putchar('\n');

	return 0;
}

void uppercase() {
	char ch;

	for (int i=0; i<UPPER; i++) {
		ch = 'A' + rand() % 26;
		putchar(ch);
	}
}

void lowercase() {
	char ch;
	
	for (int i=0; i<LOWER; i++) {
		ch = 'a' + rand() % 26;
		putchar(ch);
	}
}

void number() {
	char ch;
	
	for (int i=0; i<NUM; i++) {
		ch = '0' + rand() % 10;
		putchar(ch);
	}
}

void symbol() {
	char ch;

	for (int i=0; i<SYM; i++) {
		while (ch != '!' && ch != '@' && ch != '#' && ch != '-'
			&& ch != '$' && ch != '%' && ch != '*' && ch != '_') {
			ch = '!' + rand() % ('/' - '!' + 1);
		}
		putchar(ch);
	}
}

