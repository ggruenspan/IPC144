#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"
#include <string.h> //adds the use of strlen

//--------------------------------
// Function Definitions
//--------------------------------

// getName
void getName(struct Name* name) {

    int opt;

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    opt = yes();

    if (opt == 0) {
        name->middleInitial[0] = '\0';
    }
    else {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]%*c", name->middleInitial);
    }


    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
}

// getAddress
void getAddress(struct Address* address) {

    int opt, i, incorrect;

    printf("Please enter the contact's street number: ");
    address->streetNumber = getInt();

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);

    printf("Do you want to enter an apartment number? (y or n): ");
    opt = yes();

    if (opt == 0) {
        address->apartmentNumber = 0;
    }
    else {
        printf("Please enter the contact's apartment number: ");
        address->apartmentNumber = getInt();
    }   

    do {
        incorrect = 0;

        printf("Please enter the contact's postal code: ");
        scanf(" %7[^\n]", address->postalCode);

        //checks if postal code it longer than 6 digits
        if (strlen(address->postalCode) != 6) {
            clearKeyboard(); // clear the input
            incorrect++;
            break;
        }
        else {
            for (i = 0; i <= 7; i++) {
                //check if char at i is a letter
                if (i == 0 || i == 2 || i == 5) {
                    if (address->postalCode[i] >= 65 && address->postalCode[i] <= 90) {
                        ;
                    }
                    else {
                        incorrect++;
                    }
                }

                //check if char at i is a number
                if (i == 1 || i == 4 || i == 6) {
                    if (address->postalCode[i] >= 48 && address->postalCode[i] <= 57) {
                        ;
                    }
                    else {
                        incorrect++;
                    }
                }
            }
        }
    } while (incorrect > 0);

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}

// getNumbers
void getNumbers(struct Numbers* numbers) {

    int opt;

    //CELL
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);

    //HOME
    printf("Do you want to enter a home phone number? (y or n): ");
    opt = yes();
    if (opt == 1) {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
    }
    else {
        strcpy(numbers->home, "\0");
    }

    //BUSINESS
    printf("Do you want to enter a business phone number? (y or n): ");
    opt = yes();
    if (opt == 1) {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
    }
    else {
        strcpy(numbers->business, "\0");
    }
}

// getContact
void getContact(struct Contact* contact) {

    struct Contact Contact;

    getName(&Contact.name);
    getAddress(&Contact.address);
    getNumbers(&Contact.numbers);

    *contact = Contact;
}
