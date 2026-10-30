#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 11

char gen_upper();
char gen_lower();
char gen_number();
char gen_symbol();

int main() {
	int idx=0, option;
	char password[LENGTH];
	
	srand((unsigned) time(NULL));
	printf("SILLY PASSWORD GENERATOR V1.4\n");
	
	for(int i=0; i<LENGTH; i++) {
		option = rand() % 4;

		switch (option) {
			case 0:
				password[idx] = gen_upper();
				break;
			case 1:
				password[idx] = gen_lower();
				break;
			case 2:
				password[idx] = gen_number();
				break;
			case 3:
				password[idx] = gen_symbol();
			default:
				break;
		}
	
		idx++;
	}

	password[idx] = '\0';
	printf("%s\n", password);

	return 0;
}

char gen_upper() {
	return 'A' + rand() % 26;
}

char gen_lower() {
	return 'a' + rand() % 26;
}

char gen_number() {
	return '0' + rand() % 10;
}

char gen_symbol() {
	char ch = ' ';

	while (ch != '!' && ch != '@' && ch != '#' && ch != '-'
		&& ch != '$' && ch != '%' && ch != '*' && ch != '_') {
		ch = '!' + rand() % ('/' - '!' + 1);
	}

	return ch;
}

