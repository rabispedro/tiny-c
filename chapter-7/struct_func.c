#include <stdio.h>

struct string {
	char *value;
	unsigned long (*length)(char *str);
} typedef String;

unsigned long len(char *str);

int main() {
	String s = { "Teste 1, 2, 3 da Silva!\0", &len };

	printf("Value: '%s', Length: %lu\n", s.value, s.length(s.value));

	return 0;
}

unsigned long len(char *str) {
	unsigned long size = 0;

	while(*str) {
		size++;
		str++;
	}

	return size;
}