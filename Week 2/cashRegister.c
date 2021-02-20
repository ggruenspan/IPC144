#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>    // C language module providing Input/Output facilities

// Start your code below:

int main(void)     //  main() is automatically called to start a C program
{

    double cost;
    //double gstCal;
    double GST;
    int loonies, quarters, dimes, nickels, pennies;
    float loonreq;
    float balance;

    printf("Please enter the amount to be paid: $");
    scanf("%lf", &cost);

    GST = (cost * .13) + .005;
    printf("GST: %.2f\n", GST);
    cost = cost + GST;
    printf("Balance owing: $%.2f\n", cost);

    loonies = cost;
    printf("Loonies required: %d, ", loonies);
    loonreq = cost - loonies;
    printf("balance owing $%.2f\n", loonreq);

    quarters = (int)(((int)(100 * loonreq)) / 25);
    printf("Quarters required: %d, ", quarters);
    balance = loonreq - (quarters * .25);
    printf("balance owing $%.2f\n", balance);

    dimes = (int)(((int)(100 * balance)) / 10);
    printf("Dimes required: %d, ", dimes);
    balance = balance - (dimes * .1);
    printf("balance owing $%.2f\n", balance);

    nickels = (int)(((int)(100 * balance)) / 5);
    printf("Nickels required: %d, ", nickels);
    balance = balance - (nickels * .05);
    printf("balance owing $%.2f\n", balance);

    pennies = (int)(balance * 100);
    printf("Pennies required: %d, ", pennies);
    balance = balance - (pennies * .01);
    printf("balance owing $%.2f\n", balance);

    return 0; // return to operating system

}
