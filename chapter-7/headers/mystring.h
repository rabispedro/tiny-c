#ifndef MY_STRING

#define MY_STRING_VERSION "1.0"
#define MY_STRING_VERSION_MAJOR 1
#define MY_STRING_VERSION_MINOR 0

char *strappend(char *dest, char* src);
void strcaps(char *string);
char *strinsert(char *org, char *ins, int offset);
void strlower(char *string);
char *strrev(char *string);
int strsplit(char *org, int offset, char **s1, char **s2);
void strtabs(char *str, int tab);
char *left(char *source, int count);
char *mid(char *source, int count, int offset);
char *right(char *source, int count);
void strupper(char *string);
int strwords(char *str);

#endif