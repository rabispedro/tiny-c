#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "mystring.h"

/* Return a string from the append of two strings */
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

/* Display a string to its capitalization */
void strcaps(char *string) {
	const int upper_mask = 0xdf;
	short is_capitalizable = 1;
	
	while(*string) {
		if (is_capitalizable) {
			if (*string >= 'a' && *string <= 'z') {
				// *string -= 32;
				*string &= upper_mask;
				is_capitalizable = 0;
			}
		}

		if (*string == ' ' || *string == '\n' || *string == '\t') {
			is_capitalizable = 1;
		}

		string++;
	}
}

/* Return a string based in an insertion of strings, using offset */
char *strinsert(char *org, char *ins, int offset) {
	unsigned int original_size = 0, inserted_size = 0;

	while(org[original_size] != '\0') {
		original_size++;
	}

	while(ins[inserted_size] != '\0') {
		inserted_size++;
	}

	if (offset < 0) {
		offset = 0;
	} else if (offset > original_size) {
		offset = original_size;
	}

	char *new = (char *) malloc(sizeof(char) * (original_size + inserted_size) + 1);
	if (new == NULL) {
		fprintf(stderr, "Unable to allocate %d bytes of memory for the new string\n", (original_size + inserted_size + 1));
		exit(1);
	}

	// Inserting the first part of original string
	for (int i=0; i<offset; i++) {
		new[i] = org[i];
	}

	// Inserting the in-between string
	for (int i=0; i<inserted_size; i++) {
		new[i+offset] = ins[i];
	}

	// Inserting the rest part of original string
	for (int i=0; i<(original_size-offset); i++) {
		new[i+offset+inserted_size] = org[i+offset];
	}
	new[original_size+inserted_size] = '\0';

	return new;
}

/* Transform a string to its lowercase */
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

/* Return a new string with reversed content */
char *strrev(char *string) {
	unsigned int size = 0;

	if (string != NULL) {
		while(string[size] != '\0') {
			size++;
		}
	}

	char *new_string = (char *) malloc(sizeof(char) * (size+1));
	if (new_string == NULL) {
		fprintf(stderr, "Unable to allocate %d bytes of memory for the new string\n", (size+1));
		exit(1);
	}

	for (unsigned int i=0; i<size; i++) {
		new_string[i] = string[size-i-1];
	}
	new_string[size] = '\0';

	return new_string;
}

/* Split a string into two other strings, based in the offset */
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
	strncpy(*s2, (org+offset), (size-offset));

	return 1;
}

/* Display a string with tabulation */
void strtabs(char *str, int tab) {
	int column = 0, spaces = 0;

	while(*str) {
		if (*str == '\t') {
			spaces = tab - (column % tab);
			while(spaces--) {
				putchar(' ');
				column++;
			}
		} else {
			putchar(*str);

			if (*str == '\n') {
				column = 0;
			} else {
				column++;
			}
		}

		str++;
	}
}

/* Transform a string to its uppercase */
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

/* Return numbers of separated words in a string */
int strwords(char *str) {
	short has_started = 0;
	int words = 0;

	int size = 0;
	while(str[size] != '\0') {
		size++;
	}
	
	for(int i=0; i<size; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| str[i] == '\''
			|| str[i] == '-') {

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

/* Return the left portion of a string */
char *left(char *source, int count) {
	return mid(source, count, 0);
}

/* Return the middle portion of a string */
char *mid(char *source, int count, int offset) {
	char *str = (char *) malloc(sizeof(char) * (count+1));
	if (str == NULL) {
		fprintf(stderr, "Unable to allocate %d bytes of memory for the new string\n", (count+1));
		exit(1);
	}

	for(unsigned int i=0; i<count; i++) {
		if (source[offset + i] == '\0') {
			count = i;
			break;
		}
		str[i] = source[offset + i];
	}
	str[count] = '\0';

	return str;
}

/* Return the right portion of a string */
char *right(char *source, int count) {
	unsigned int size = 0;

	if (source != NULL) {
		while(source[size] != '\0') {
			size++;
		}
	}

	return mid(source, count, (size-count));
}
