#include <stdio.h>

int strwords(char *str);

int main() {
	char str[] = "This isn't a sample string";

	printf("'%s' (%d words)\n", str, strwords(str));

	return 0;
}

int strwords(char *str) {
	short has_started = 0;
	int words = 0;

	int size = 0;
	while(str[size] != '\0') {
		size++;
	}
	
	for(int i=0; i<size; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			if (!has_started) {
				has_started = 1;
				words++;
			}
		} else {
			if (has_started) {
				has_started = 0;
			}
		}
	}

	return words;
}