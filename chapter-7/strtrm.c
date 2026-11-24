#include <stdio.h>
#include <stdlib.h>

char *left(char *source, int count);
char *mid(char *source, int count, int offset);
char *right(char *source, int count);

int main() {
	char str[] = "Slice me, dice me, make julienne fries!";
	char *l_str = left(str, 9);
	char *m_str = mid(str, 8, 10);
	char *r_str = right(str, 17);

	printf("Original String: %s\n", str);
	printf("Left String: %s\n", l_str);
	printf("Mid String: %s\n", m_str);
	printf("Right String: %s\n", r_str);

	return 0;
}

char *left(char *source, int count) {
	char *str = (char *) malloc(sizeof(char) * (count+1));
	if (str == NULL) {
		fprintf(stderr, "Unable to allocate %d bytes of memory for the new string\n", (count+1));
		exit(1);
	}

	for (unsigned int i=0; i<count; i++) {
		if (source[i] == '\0') {
			count = i;
			break;
		}
		str[i] = source[i];
	}
	str[count] = '\0';

	return str;
}

char *mid(char *source, int count, int offset) {
	char *str = (char *) malloc(sizeof(char) * (offset+1));
	if (str == NULL) {
		fprintf(stderr, "Unable to allocate %d bytes of memory for the new string\n", (offset+1));
		exit(1);
	}

	for(unsigned int i=0; i<offset; i++) {
		if (source[count + i] == '\0') {
			offset = i;
			break;
		}
		str[i] = source[count + i];
	}
	str[offset] = '\0';

	return str;
}


char *right(char *source, int count) {
	unsigned int size = 0;

	if (source != NULL) {
		while(source[count + size] != '\0') {
			size++;
		}
	}

	char *str = (char *) malloc(sizeof(char) * (size+1));
	if (str == NULL) {
		fprintf(stderr, "Unable to allocate %d bytes of memory for the new string\n", (size+1));
		exit(1);
	}

	for(unsigned int i=0; i<size; i++) {
		if (source[count+i] == '\0') {
			size = i;
			break;
		}
		str[i] = source[count+i];
	}
	str[size] = '\0';

	return str;
}