#define _CRT_SECURE_NO_WARNINGS
#define MAXCONTACTS 5

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contactHelpers.h"


//--------------------------------
// Function Definitions
//--------------------------------

// clearKeyboard
void clearKeyboard(void) {

	while (getchar() != '\n'); // clears the buffer
}

// pause
void pause(void) {

	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt
int pos = 0;
int getInt(void) {

	int value;
	char Char;

	scanf("%d%c", &value, &Char);
	if (Char != '\n') {
		clearKeyboard(); // clear the input
	}

	while (Char != '\n' || value < 0) {
		if (Char != '\n') {
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			scanf("%d%c", &value, &Char);
			if (Char != '\n'){
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

// getIntInRange
int getIntInRange(int min, int max) {

	int number = getInt();

	while ((number < min) || (number > max)) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		number = getInt();
	}

	return number;
}

// yes
int yes(void) {

	char Char = 'x', Char2 = 'x';
	int response = -1;

	scanf("%c%c", &Char, &Char2);

	while (!((Char2 == '\n') && ((Char == 'Y') || (Char == 'y') || (Char == 'n') || (Char == 'N')))) {
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
int menu(void){

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

// contactManagerSystem
void contactManagerSystem(void) {

	struct Contact contacts[MAXCONTACTS] = {
	{
		{ "Rick", {'\0'}, "Grimes" },
		{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
		{ "4161112222", "4162223333", "4163334444" } },
	{
		{ "Maggie", "R.", "Greene" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9051112222", "9052223333", "9053334444" } },
	{
		{ "Morgan", "A.", "Jones" },
		{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
		{ "7051112222", "7052223333", "7053334444" } },
	{
		{ "Sasha", {'\0'}, "Williams" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9052223333", "9052223333", "9054445555" } },
	};

	int done = 0;

	while (!done) {
		int opt = menu();
		switch (opt) {
		case 0:
			printf("\n");
			printf("Exit the program? (Y)es/(N)o: ");
			if (yes() == 1) {
				printf("\nContact Management System: terminated\n");
				done = 1;
				break;
			}
			printf("\n");
			break;
		case 1:
			displayContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			addContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:
			searchContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 6:
			sortContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		default:
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6> ");
			break;
		}
	}
}

// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[]) {

	int i, run = 1;

	while (run == 1) {

		int alphaCheck = 0;

		scanf("%10s", phoneNum);
		clearKeyboard();

		//checking if every character is a number or not
		for (i = 0; i < 10; i++) {
			if (!isdigit((unsigned char)phoneNum[i])) {
				alphaCheck++;
			}
		}

		// (String Length Function: validate entry of 10 characters)
		if (strlen(phoneNum) == 10 && alphaCheck == 0) {
			run = 0;
		}
		else{
			printf("Enter a 10-digit phone number: ");
		}
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) {

	int i, pos = -1;

	for (i = 0; i < size; i++) {

		if (strcmp(cellNum, contacts[i].numbers.cell) == 0) {
			pos = i;
		}
	}
	return pos;
}

// displayContactHeader
void displayContactHeader() {

	printf("\n");
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");

}

// displayContactFooter
void displayContactFooter(int size) {

	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", size);
}

// displayContact
void displayContact(const struct Contact* contact) {

	if (strcmp(contact->name.middleInitial, "") == 0) {
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	}
	else {
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	}

	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s,", contact->address.streetNumber, contact->address.street);

	if (contact->address.apartmentNumber == 0) {
		printf(" ");
	}
	else {
		printf(" Apt# %d, ", contact->address.apartmentNumber);
	}
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts
void displayContacts(const struct Contact contacts[], int size) {

	int i, num = 0;    //num is the running count of all contacts

	displayContactHeader();

	//checks to see if number field has anything in it, if yes, display the contact
	for (i = 0; i < size; i++) {
		if (*contacts[i].numbers.cell > 0) {
			displayContact(&contacts[i]);
			num++;
		}
	}
	displayContactFooter(num);
}

// addContact
void addContact(struct Contact contact[], int size) {
	int i, empty = 0, full = 0;

	for (i = 0; i < size; i++) {
		if (strlen(contact[i].numbers.cell) == 0) {     //if empty, you can add a contact in that space
			empty = i;
			break;
		}
		else {
			full++;     // if not empty, adds to number of contacts until it can see that its full
		}
	}

	if (full == size) {
		printf("\n");
		printf("*** ERROR: The contact list is full! ***\n\n");
	}
	else {
		printf("\n");
		getContact(&contact[empty]);
		printf("--- New contact added! ---\n\n");
	}
}

// updateContact
void updateContact(struct Contact contacts[], int size) {
	char cellNum[11];
	int pos;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	pos = findContactIndex(contacts, size, cellNum);     //checks cell number against current database

	if (pos != -1) {
		printf("\nContact found:\n");
		displayContact(&contacts[pos]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		if (yes() == 1) {
			getName(&contacts[pos].name);
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1) {
			getAddress(&contacts[pos].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1) {
			getNumbers(&contacts[pos].numbers);
		}
		printf("--- Contact Updated! ---\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}
	printf("\n");
}

// deleteContact
void deleteContact(struct Contact contacts[], int size) {
	char cellNum[11];
	int pos;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	pos = findContactIndex(contacts, size, cellNum);     //checks cell number against current database

	if (pos != -1) {
		printf("\nContact found:\n");
		displayContact(&contacts[pos]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
 		if (yes() == 1) {
			strcpy(contacts[pos].numbers.cell, "\0");
			printf("--- Contact deleted! ---\n");
		}
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}
	printf("\n");
}

// searchContacts
void searchContacts(const struct Contact contacts[], int size) {
	char cellNum[11];
	int pos;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	pos = findContactIndex(contacts, size, cellNum);     //checks cell number against current database

	if (pos != -1) {
		printf("\n");
		displayContact(&contacts[pos]);
		printf("\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n\n");
	}
}

// sortContacts
void sortContacts(struct Contact contacts[], int size) {
	int i, j;
	struct Contact temp;

	//code is copied from ipc notes website (bubble sort)
	for (i = size - 1; i > 0; i--) {
		for (j = 0; j < size - 1; j++) {
			if (strcmp(contacts[j].numbers.cell, contacts[j + 1].numbers.cell) > 0) {
				temp = contacts[j];
				contacts[j] = contacts[j + 1];
				contacts[j + 1] = temp;
			}
		}
	}
	printf("\n--- Contacts sorted! ---\n\n");
}
