#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string {
	char *value;
	unsigned long length;
} typedef String;

int string_create(String *s, char *value);
int string_destroy(String *s);

int main() {
	String s;
	
	string_create(&s, "Hihihihi\0");
	printf("Value: '%s', Length: %lu\n", s.value, s.length);
	string_destroy(&s);

	return 0;
}

int string_create(String *s, char *value) {
	if (s == NULL || value == NULL) {
		return 0;
	}

	s->length = strlen(value);
	s->value = (char *) malloc(sizeof(char) * s->length + 1);

	strcpy(s->value, value);
	return 1;
}

int string_destroy(String *s) {
	if (s == NULL) {
		return 0;
	}
	
	free(s->value);
	s->value = NULL;
	s->length = 0;

	return 1;
}