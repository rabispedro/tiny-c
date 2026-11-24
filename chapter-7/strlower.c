#include <stdio.h>

void strlower(char *string);

int main () {
	char string[] = "Random STRING sample 123!@#";

	printf("Original string: %s\n", string);

	strlower(string);
	printf("Lowercase string: %s\n", string);
	
	return 0;
}

void strlower(char *string) {
	const int lower_mask = 0x20;
	
	while(*string) {
		if (*string >= 'A' && *string <= 'Z') {
			// *string += 32;
			*string |= lower_mask;
		}

		string++;
	}
}
