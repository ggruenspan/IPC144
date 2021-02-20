#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"
#include <string.h> //adds the use of strlen

//--------------------------------
// Function Definitions
//--------------------------------

// getName:
void getName(struct Name* name)
{
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
        clearKeyboard(); // clears the input
    }
    

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
}

// getAddress:
void getAddress(struct Address* address)
{
    int opt;

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

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]%*c", address->postalCode);
    clearKeyboard(); // clears the input

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    int opt;

    //CELL
    printf("Please enter the contact's cell phone number: ");
    scanf("%10[^\n]%*c", numbers->cell);

    //HOME
    printf("Do you want to enter a home phone number? (y or n): ");
    opt = yes();

    if (opt == 0) {
        numbers->home[0] = '\0';
    }
    else {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]%*c", numbers->home);
    }

    //BUSINESS
    printf("Do you want to enter a business phone number? (y or n): ");
    opt = yes();

    if (opt == 0) {
        numbers->business[0] = '\0';
    }
    else {

        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]%*c", numbers->business);
    }
}

// getContact:
void getContact(struct Contact* contact) 
{
    struct Contact Contact;

    getName(&Contact.name);
    getAddress(&Contact.address);
    getNumbers(&Contact.numbers);

    *contact = Contact;
}
