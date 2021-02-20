#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_NUM 100

// Put your code below:

int main(void) {
	int amountDays, days, size, dayH, dayL, tempHigh[MAX_NUM], tempLow[MAX_NUM], averageDay;
	int highest = 0, lowest = 0;
	float average;

	printf("---=== IPC Temperature Calculator V2.0 ===---");

	printf("\nPlease enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &amountDays);

	while (amountDays < 3 || amountDays > 10) {
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &amountDays);
	}

	printf("\n");

	for (days = 1; days <= amountDays; days++) {


		printf("Day %d - High: ", days);
		scanf("%d", &tempHigh[days - 1]);
		printf("Day %d - Low: ", days);
		scanf("%d", &tempLow[days - 1]);

		while (tempLow[days - 1] > 40 || tempLow[days - 1] < (-40) || tempHigh[days - 1] > 40 || tempHigh[days - 1] < (-40) || tempLow[days - 1]> tempHigh[days - 1]) {
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("Day %d - High: ", days);
			scanf("%d", &tempHigh[days - 1]);
			printf("Day %d - Low: ", days);
			scanf("%d", &tempLow[days - 1]);
		}

		if (tempHigh[days - 1] > highest) {
			highest = tempHigh[days - 1];
			dayH = days;
		}
		if (tempLow[days - 1] < lowest) {
			lowest = tempLow[days - 1];
			dayL = days;
		}

	}

	printf("\nDay  Hi  Low");
	int day = 1;
	for (size = 0; size < amountDays; size++) {
		printf("\n%d", day);
		printf("    %d", tempHigh[size]);
		printf("    %d", tempLow[size]);
		day++;
	}
	printf("\n");
	printf("\nThe highest temperature was %d, on day %d\n", highest, dayH);
	printf("The lowest temperature was %d, on day %d", lowest, dayL);

	do {
		average = 0;
		printf("\nEnter a between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", amountDays);
		scanf("%d", &averageDay);

		while (averageDay == 0 || averageDay > amountDays) {
			printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", amountDays);
			scanf("%d", &averageDay);
		}

		if (averageDay >= 1 && averageDay <= amountDays) {
			for (size = 0; size < averageDay; size++) {
				average = (average) + (tempHigh[size]) + (tempLow[size]);
			}
			average = average / (size*2);
			printf("\nThe average temperature up to day %d is: %.2f\n", averageDay, average);
		}

	} while (averageDay > 0);

	printf("\nGoodbye !\n");

	return 0;
}
