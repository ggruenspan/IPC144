#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include <string.h> //adds the use of strlen

void getName(struct Name *name) {

    char yesNo;

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", name->firstName);

    do {
        printf("Do you want to enter a middle initial(s)? (y or n): ");
        scanf("%c%*c", &yesNo); //cahnged %s to %c
    } while (yesNo != 'y' && yesNo != 'Y' && yesNo != 'n' && yesNo != 'N'); //added a check

    if (yesNo == 'y' || yesNo == 'Y') {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%7[^\n]%*c", name->middleInitial);
    }

    printf("Please enter the contact's last name: ");
    scanf("%36[^\n]%*c", name->lastName);
}

void getAddress(struct Address *address)
{
    char yesNo;

    do {
        printf("Please enter the contact's street number: ");
        scanf("%d%*c", &address->streetNumber);
    } while (address->streetNumber < 1);

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);

    do {
        printf("Do you want to enter an apartment number? (y or n): ");
        scanf("%c%*c", &yesNo);
    } while (yesNo != 'y' && yesNo != 'Y' && yesNo != 'n' && yesNo != 'N'); //added a check

    if (yesNo == 'y' || yesNo == 'Y') { //changed "y" and "Y" to 'y' and 'Y'
        do {
            printf("Please enter the contact's apartment number: ");
            scanf("%d%*c", &address->apartmentNumber);
        } while (address->apartmentNumber < 1);
    }

    do {
        printf("Please enter the contact's postal code: ");
        scanf("%7[^\n]%*c", address->postalCode);
    } while (strlen(address->postalCode) != 7); //added a check

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}

void getNumbers(struct Numbers* numbers)
{
    char yesNo;

    do {
        printf("Do you want to enter a cell phone number? (y or n): ");
        scanf("%c%*c", &yesNo);
    } while (yesNo != 'y' && yesNo != 'Y' && yesNo != 'n' && yesNo != 'N'); //added a check

    if (yesNo == 'y' || yesNo == 'Y') {
        printf("Please enter the contact's cell phone number: ");
        scanf("%10[^\n]%*c", numbers->cell);
    }

    do {
        printf("Do you want to enter a home phone number? (y or n): ");
        scanf("%c%*c", &yesNo);
    } while (yesNo != 'y' && yesNo != 'Y' && yesNo != 'n' && yesNo != 'N'); //added a check

    if (yesNo == 'y' || yesNo == 'Y') { //changed && to ||
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]%*c", numbers->home);
    }

    do {
        printf("Do you want to enter a business phone number? (y or n): ");
        scanf("%c%*c", &yesNo);
    } while (yesNo != 'y' && yesNo != 'Y' && yesNo != 'n' && yesNo != 'N'); //added a check

    if (yesNo == 'y' || yesNo == 'Y') {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]%*c", numbers->business);
    }
}
