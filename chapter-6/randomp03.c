#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER 1
#define LOWER 6
#define NUM 1
#define SYM 2
#define LEN (UPPER + LOWER + NUM + SYM + 1)

void uppercase(char *password, int *idx);
void lowercase(char *password, int *idx);
void number(char *password, int *idx);
void symbol(char *password, int *idx);
void scramble(char *password);

int main() {
	int idx=0;
	char password[LEN];

	srand((unsigned) time(NULL));
	printf("SILLY PASSWORD GENERATOR V1.3\n");
	
	uppercase(password, &idx);
	lowercase(password, &idx);
	number(password, &idx);
	symbol(password, &idx);

	scramble(password);
	printf("%s\n", password);

	return 0;
}

void uppercase(char *password, int *idx) {
	for (int i=0; i<UPPER; i++) {
		password[*idx] = 'A' + rand() % 26;
		(*idx)++;
	}
}

void lowercase(char *password, int *idx) {
	for (int i=0; i<LOWER; i++) {
		password[*idx] = 'a' + rand() % 26;
		(*idx)++;
	}
}

void number(char *password, int *idx) {
	for (int i=0; i<NUM; i++) {
		password[*idx] = '0' + rand() % 10;
		(*idx)++;
	}
}

void symbol(char *password, int *idx) {
	char ch;

	for (int i=0; i<SYM; i++) {
		while (ch != '!' && ch != '@' && ch != '#' && ch != '-'
			&& ch != '$' && ch != '%' && ch != '*' && ch != '_') {
			ch = '!' + rand() % ('/' - '!' + 1);
		}

		password[*idx] = ch;
		(*idx)++;
	}
}

void scramble(char *password) {
	int idx=0, aux;
	char temp[LEN];
	
	for (int i=0; i<LEN; i++) {
		temp[i] = '\0';
	}

	while(idx < LEN-1) {
		aux = rand() % (LEN-1);

		if (!temp[aux]) {
			temp[aux] = password[idx];
			idx++;
		}
	}

	for (int i=0; i<LEN; i++) {
		password[i] = temp[i];
	}
}

