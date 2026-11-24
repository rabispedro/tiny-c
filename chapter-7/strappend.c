#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strappend(char *dest, char* src);

int main() {
	char s1[] = "This is another ";
	char s2[] = "fine mess!";
	char *s3 = strappend(s1, s2);

	printf("S1: '%s'\nS2: '%s'\nS3: '%s'\n",  s1, s2, s3);
	
	return 0;
}

char *strappend(char *dest, char* src) {
	unsigned int dest_size = 0, src_size = 0;

	if (dest != NULL) {
		while (dest[dest_size] != '\0') {
			dest_size++;
		}
	}

	if (src != NULL) {
		while (src[src_size] != '\0') {
			src_size++;
		}
	}

	char *str = (char *) malloc(sizeof(char) * (dest_size + src_size));
	if (str == NULL) {
		fprintf(stderr, "Unable to allocate %d bytes of memory for the new string\n", (dest_size + src_size));
		exit(1);
	}

	for(unsigned int i=0; i<dest_size; i++) {
		str[i] = dest[i];
	}

	for(unsigned int i=0; i<src_size; i++) {
		str[dest_size+i] = src[i];
	}

	return str;
}
