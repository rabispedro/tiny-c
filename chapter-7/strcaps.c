#include <stdio.h>

void strcaps(char *string);

int main () {
	char string[] = "random String o sample 123!@#";

	printf("Original string: %s\n", string);

	strcaps(string);
	printf("Capitalized string: %s\n", string);
	
	return 0;
}

void strcaps(char *string) {
	const int upper_mask = 0xdf;
	short is_capitalizable = 1;
	
	while(*string) {
		if (is_capitalizable) {
			if (*string >= 'a' && *string <= 'z') {
				// *string -= 32;
				*string &= upper_mask;
			}
			is_capitalizable = 0;
		}

		if (*string == ' ') {
			is_capitalizable = 1;
		}

		string++;
	}
}
