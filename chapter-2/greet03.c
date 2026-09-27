#include <stdio.h>
#include <time.h>

int main(int argc, char** argv) {
	time_t now;
	time(&now);

	struct tm* clock = localtime(&now);
	int hour = clock->tm_hour;

	printf("Good ");

	if (hour < 4)
		printf("super duper early morning. How are you still up?");
	else if (hour < 12)
		printf("morning. Did you sleep well?");
	else if (hour < 17)
		printf("afternoon. The bed starts to seems nice...");
	else
		printf("evening. Oh, such a night owl we have here!");

	if (argc > 1)
		printf(" %s", argv[1]);

	printf("\n");
	
	return 0;
}