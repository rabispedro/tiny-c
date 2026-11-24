#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strsplit(char *org, int offset, char **s1, char **s2);

int main() {
	char str[] = "Slice me, dice me, make julienne fries!";
	char *s1, *s2;

	printf("Original String: %s\n", str);
	if (strsplit(str, 10, &s1, &s2)) {
		puts("Split string sucess!");
		printf("S1: '%s'\nS2: '%s'\n", s1, s2);
	} else {
		puts("Split string error");
	}

	return 0;
}

int strsplit(char *org, int offset, char **s1, char **s2) {
	if (org == NULL) {
		return 0;
	}
	
	unsigned int size = 0;
	while(org[size] != '\0') {
		size++;
	}

	*s1 = (char *) malloc(sizeof(char) * (offset+1));
	*s2 = (char *) malloc(sizeof(char) * (size-offset+1));
	if (s1 == NULL || s2 == NULL) {
		return 0;
	}
	
	strncpy(*s1, org, offset);
	strncpy(*s2, org+offset, (size-offset));

	return 1;
}
