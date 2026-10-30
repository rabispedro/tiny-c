#include <stdio.h>

int main() {
	char password[] = { "password" };
	short found = 0;
	long long tries=0;

	printf("BRUTE FORCE PASSWORD GUESSER v1.0\n");
	for(int i=0; i<26 && !found; i++) {
		for(int j=0; j<26 && !found; j++) {
			for(int k=0; k<26 && !found; k++) {
				for(int l=0; l<26 && !found; l++) {
					for(int m=0; m<26 && !found; m++) {
						for(int n=0; n<26 && !found; n++) {
							for(int o=0; o<26 && !found; o++) {
								for(int p=0; p<26 && !found; p++) {
									tries++;
									if (password[7] == (i + 'a')
										&& password[6] == (j + 'a')
										&& password[5] == (k + 'a')
										&& password[4] == (l + 'a')
										&& password[3] == (m + 'a')
										&& password[2] == (n + 'a')
										&& password[1] == (o + 'a')
										&& password[0] == (p + 'a')
									) {
										printf("Password guessed: '%c%c%c%c%c%c%c%c' (in %lld tries)\n",
											(p + 'a'), (o+ 'a'), (n + 'a'), (m + 'a'), (l + 'a'), (k + 'a'), (j + 'a'), (i + 'a'), tries);
										found = 1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	return 0;
}