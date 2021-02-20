#define _CRT_SECURE_NO_WARNINGS
#define NUMS 3
#include <stdio.h>

// Put your code below:

int main(void)
{
	float averageLow = 0, averageHigh = 0, average = 0;
	int days, dayH, dayL, tempHigh, tempLow, highest = 0, lowest = 0;

	printf("---=== IPC Temperature Analyzer ===---");

	for (days = 1; days <= 4; days++)
	{
		printf("\nEnter the high value for day %d: ", days);
		scanf("%d", &tempHigh);

		printf("\nEnter the low value for day %d: ", days);
		scanf("%d", &tempLow);

		while (tempLow > 40 || tempLow < (-40) || tempHigh > 40 || tempHigh < (-40) || tempLow > tempHigh) {
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\nEnter the high value for day %d: ", days);
			scanf("%d", &tempHigh);

			printf("\nEnter the low value for day %d: ", days);
			scanf("%d", &tempLow);
		}

		averageLow = averageLow + tempLow;
		averageHigh = averageHigh + tempHigh;
		average = average + tempHigh + tempLow;

		if (tempHigh > highest) {
			highest = tempHigh;
			dayH = days;
		}
		if (tempLow < lowest) {
			lowest = tempLow;
			dayL = days;
		}
	}
	averageLow = averageLow / 4;
	printf("\nThe average (mean) LOW temperature was: %.2f\n", averageLow);
	averageHigh = averageHigh / 4;
	printf("The average (mean) HIGH temperature was: %.2f\n", averageHigh);
	average = average / 8;
	printf("The average (mean) temperature was: %.2f\n", average);

	printf("The highest temperature was %d, on day %d\n", highest, dayH);

	printf("The lowest temperature was %d, on day %d\n", lowest, dayL);

	return 0;
}
