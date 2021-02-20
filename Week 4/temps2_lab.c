//==============================================
// Name:           Gerred Gruenspan
// Student Number: 155315195
// Email:          ggruenspan@myseneca.ca
// Section:        NVV
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_NUM 100

// Put your code below:

int main(void) {
	int amountDays;
	int days;
	int size;
	int tempHigh[MAX_NUM], tempLow[MAX_NUM];

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

	return 0;
}