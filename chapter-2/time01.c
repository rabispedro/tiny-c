#import <stdio.h>
#import <time.h>

int main(int argc, char** argv) {
	time_t now;

	time(&now);
	printf("The computer think it's %ld\n", now);
	printf("%s\n", ctime(&now));
	

	return 0;
}