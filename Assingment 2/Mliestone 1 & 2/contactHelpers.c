//==============================================
// Name:           Gerred Gruenspan
// Student Number: 155315195
// Email:          ggruenspan@myseneca.ca
// Section:        NVV
// Date:           2020/11/
//==============================================
// Assignment:     2
// Milestone:      1&2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contactHelpers.h"
#include <string.h>

//--------------------------------
// Function Definitions
//--------------------------------

// clearKeyboard:
void clearKeyboard(void)
{
    while (getchar() != '\n'); // clears the buffer
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

int pos = 0;
// getInt:
int getInt(void)
{
	int value;
	char Char;

	scanf("%d%c", &value, &Char);
	if (Char != '\n')
	{
		clearKeyboard(); // clear the input
	}

	while (Char != '\n' || value < 0)
	{
		if(Char != '\n'){
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			scanf("%d%c", &value, &Char);
			if (Char != '\n')
			{
				clearKeyboard(); // clear the input
			}
		}
		else if (value < 0 && pos == 0) {
			printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
			scanf("%d%c", &value, &Char);
			if (value > 0) {
				pos = 1;
				break;
			}
			else {
				Char = 'x';
				clearKeyboard(); // clear the input
			}
		}
		else if (value < 0 && pos == 1) {
			printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
			scanf("%d%c", &value, &Char);
			if (Char != '\n') {
				Char = 'x';
			}
		}
	}

	return value;
}

// getIntInRange:
int getIntInRange(int min, int max)
{
	int number = getInt();

	while ((number < min) || (number > max))
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		number = getInt();
	}

	return number;
}

// yes:
int yes(void)
{
	char Char = 'x';
	char Char2 = 'x';
	int response = -1;

	scanf("%c%c", &Char, &Char2);

	while (!((Char2 == '\n') && ((Char == 'Y') || (Char == 'y') || (Char == 'n') || (Char == 'N'))))
	{
		clearKeyboard(); // clear the input
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf("%c%c", &Char, &Char2);
	}

	if ((Char == 'Y') || (Char == 'y')) {
		response = 1;
	}
	else if ((Char == 'N') || (Char == 'n')) {
		response = 0;
	}

	return response;
}

// menu:
int menu(void)
{
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");

	return getIntInRange(0, 6);
	printf("\n");
}

// contactManagerSystem:
void contactManagerSystem(void)
{
	int iSelection;

	do {
		iSelection = menu();
		//For selections between 1 and 6, the application should 
		//pause and then return to displaying the menu. 
		switch (iSelection)
		{
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			int opt = yes();
			if (opt == 1) {
				printf("\nContact Management System: terminated\n");
				return;
			}
			else { printf("\n"); }

			break;
		case 1:
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 3:
			printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 5:
			printf("\n<<< Feature 5 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		default:
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6> ");
			break;
		}

	} while ((iSelection >= 0) || (iSelection <= 6));

	return;
}
