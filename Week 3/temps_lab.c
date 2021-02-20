//==============================================
// Name:           Gerred Gruenspan
// Student Number: 155315195
// Email:          ggruenspan@myseneca.ca
// Section:        NVV
// Workshop:       3 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#define NUMS 3
#include <stdio.h>

// Put your code below:

int main(void) 
{
	float average = 0;
	int days;
	int tempHigh, tempLow;

	printf("---=== IPC Temperature Analyzer ===---");

	for (days = 1; days <= 3; days++)
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

		average = average + tempHigh + tempLow;
	}
	average = average / 6;
	printf("\nThe average (mean) temperature was: %.2f\n", average);
	return 0;
}