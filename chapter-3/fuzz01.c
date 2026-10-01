#include <stdio.h>
#include <ctype.h>

#define PHRASE_SIZE 64

const char *fuzz[] = {
	"Adam", "Boy", "Charles", "David", "Edward", "Frank",
	"George", "Henry", "Ida", "John", "King", "Lincoln",
	"Mary", "Nora", "Ocean", "Paul", "Queen", "Robert",
	"Sam", "Tom", "Union", "Victor", "William", "X-ray",
	"Young", "Zebra"
};

int main() {
	char phrase[PHRASE_SIZE];
	char ch;
	int i=0;


	printf("Law Enforcement Phonetic Alphabet Translator\n");
	printf("Enter a word or phase (up to %d characters): ", PHRASE_SIZE);

	fgets(phrase, PHRASE_SIZE, stdin);

	while(i < PHRASE_SIZE && phrase[i]) {
		ch = toupper(phrase[i]);

		if (isalpha(ch)){
			printf("%s ", fuzz[ch - 'A']);
		}

		i++;
	}

	printf("\n");
	
	return 0;
}