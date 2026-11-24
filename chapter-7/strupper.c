#include <stdio.h>

void strupper(char *string);

int main () {
	char string[] = "Random STRING sample 123!@#";

	printf("Original string: %s\n", string);

	strupper(string);
	printf("Uppercase string: %s\n", string);
	
	return 0;
}

void strupper(char *string) {
	const int upper_mask = 0xdf;
	
	while(*string) {
		if (*string >= 'a' && *string <= 'z') {
			// *string -= 32;
			*string &= upper_mask;
		}

		string++;
	}
}
