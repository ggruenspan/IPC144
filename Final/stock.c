//--------------------------------
// Function Definitions
//--------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stock.h"

// AmountCheck
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ Start
void amountCheck(double amount, struct StockRecord storeStock[], int id, struct SalesRecord saleItems[]) {
    // Checks if the amount entered is a decimal or a whole number
    if (amount != (int)amount) {
        if (storeStock[id - 1].items.byWeight == 1) {
        }
        else {
            amount = 1;
        }
    }

    // Checks if amount is greater than the available amount 
    if(amount > storeStock[id - 1].items.amount) {
        storeStock[id - 1].amountSold += storeStock[id - 1].items.amount; // sets the remaining amount to amountSold
        storeStock[id - 1].items.amount = 0;
        saleItems[id - 1].id = id;
    }

    // Runs if amount is less than the available amount
    else {
        storeStock[id - 1].items.amount -= amount;
        storeStock[id - 1].amountSold += amount;
        saleItems[id - 1].id = id;
    }
}
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- End

// CentreText
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ Start
void centreText(int fieldWidth, char specialChar, char* text) {
    if (strlen(text) == 0) { // Chceks if text is 0("")
        for (int i = 0; i < fieldWidth; i++) { // Prints out the specialChar fieldWidth amount of times
            printf("%c", specialChar);
        }
    }
    else {
        double charAmount = fieldWidth - strlen(text);
        charAmount /= 2;

        int j = 1;
        while (j <= 3) { // Runs until j is greater then or equal to 3
            if (j == 1 || j == 3) {
                if (charAmount != (int)charAmount && j == 3) { // Checks if charAmount is a decimal
                    for (int i = 0; i <= charAmount; i++) { // Prints out the specialChar charAmount amount of times
                        printf("%c", specialChar);
                    }
                    j++;
                }
                else {
                    for (int i = 0; i <= charAmount - 1; i++) { // Prints out the specialChar charAmount - 1 amount of times
                        printf("%c", specialChar);
                    }
                    j++;
                }
            }
            else {
                printf("%s", text); // Prints out the text
                j++;
            }
        }
    }
}
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- End

// ReadStockItems
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ Start
int readStockItems(struct StockRecord storeStock[], int entries, int placeHolder) {
    printf("\nImporting stock from file...\n"); // Tells the user that stock is being read from a file

    const char filename[] = "stock.txt"; // Name of the file

    int i = 0, id = 1;
    char ch;

    FILE* fp = fopen(filename, "r"); // Read

    if (fp != NULL) {
        // Formant of the file
        while (i < entries && fscanf(fp, "%lf,%d,%lf,%d,%30[^\n]%c", &storeStock[i].items.amount, &storeStock[i].items.category, &storeStock[i].items.price, &storeStock[i].items.byWeight, &storeStock[i].name, &ch) == 6) {

            if (ch != '\n') { // Cuts off any char's after there are more then 30
                while (fgetc(fp) != '\n');
            }

            i++;
            id++;
        }

        fclose(fp);
        fp = NULL;
    }
    else {
        printf("ERROR: Unable to open file.\n"); // prints error if file cant be found or cant be opened
    }

    return i;
}
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- End

// PrintStockReport
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ Start
void printStockReport(const struct StockRecord storeStock[], int stockItems) {
    printf("%4s%31s%16s%8s%9s\n", "ID", "Product", "Category", "Price", "Quantity");

    // Prints out a specific line for each category
    // Runs stockItem(14), just in case there are more then 14 items in the stock
    // Has to possible outputs, in the case that an item is sold by weight and the amount is a decimal number
    for (int i = 0; i < stockItems; i++) {
        int opt = storeStock[i].items.category;
        switch (opt)
        {
        case 1:
            if (storeStock[i].items.amount != (int)storeStock[i].items.amount) {
                printf("%4d%31s%16s%8.2lf%9.2lf\n", i + 1, storeStock[i].name, "produce", storeStock[i].items.price, storeStock[i].items.amount);
            }
            else {
                printf("%4d%31s%16s%8.2lf%9.lf\n", i + 1, storeStock[i].name, "produce", storeStock[i].items.price, storeStock[i].items.amount);
            }
            break;
        case 2:
            if (storeStock[i].items.amount != (int)storeStock[i].items.amount) {
                printf("%4d%31s%16s%8.2lf%9.2lf\n", i + 1, storeStock[i].name, "bakery", storeStock[i].items.price, storeStock[i].items.amount);
            }
            else {
                printf("%4d%31s%16s%8.2lf%9.lf\n", i + 1, storeStock[i].name, "bakery", storeStock[i].items.price, storeStock[i].items.amount);
            }
            break;
        case 3:
            if (storeStock[i].items.amount != (int)storeStock[i].items.amount) {
                printf("%4d%31s%16s%8.2lf%9.2lf\n", i + 1, storeStock[i].name, "meat", storeStock[i].items.price, storeStock[i].items.amount);
            }
            else {
                printf("%4d%31s%16s%8.2lf%9.lf\n", i + 1, storeStock[i].name, "meat", storeStock[i].items.price, storeStock[i].items.amount);
            }
            break;
        case 4:
            if (storeStock[i].items.amount != (int)storeStock[i].items.amount) {
                printf("%4d%31s%16s%8.2lf%9.2lf\n", i + 1, storeStock[i].name, "dairy", storeStock[i].items.price, storeStock[i].items.amount);
            }
            else {
                printf("%4d%31s%16s%8.2lf%9.lf\n", i + 1, storeStock[i].name, "dairy", storeStock[i].items.price, storeStock[i].items.amount);
            }
            break;
        case 5:
            if (storeStock[i].items.amount != (int)storeStock[i].items.amount) {
                printf("%4d%31s%16s%8.2lf%9.2lf\n", i + 1, storeStock[i].name, "baking", storeStock[i].items.price, storeStock[i].items.amount);
            }
            else {
                printf("%4d%31s%16s%8.2lf%9.lf\n", i + 1, storeStock[i].name, "baking", storeStock[i].items.price, storeStock[i].items.amount);
            }
            break;
        case 6:
            if (storeStock[i].items.amount != (int)storeStock[i].items.amount) {
                printf("%4d%31s%16s%8.2lf%9.2lf\n", i + 1, storeStock[i].name, "house wares", storeStock[i].items.price, storeStock[i].items.amount);
            }
            else {
                printf("%4d%31s%16s%8.2lf%9.lf\n", i + 1, storeStock[i].name, "house wares", storeStock[i].items.price, storeStock[i].items.amount);
            }
            break;
        case 7:
            if (storeStock[i].items.amount != (int)storeStock[i].items.amount) {
                printf("%4d%31s%16s%8.2lf%9.2lf\n", i + 1, storeStock[i].name, "miscellaneous", storeStock[i].items.price, storeStock[i].items.amount);
            }
            else {
                printf("%4d%31s%16s%8.2lf%9.lf\n", i + 1, storeStock[i].name, "miscellaneous", storeStock[i].items.price, storeStock[i].items.amount);
            }
            break;
        default:
            break;
        }
    }
}
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- End

// ReadSale
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ Start
int readSale(struct StockRecord storeStock[], int stockItems, struct SalesRecord saleItems[]) {
    int id, run = 0, items = 0;
    double amount;

    // Clears the ids of the last sale
    for (int i = 0; i < stockItems; i++) {
        saleItems[i].id = 0;
    }

    // Runs until run = 1 or until broken out off
    do {
        printf("Enter a product ID to purchase, and the quantity (0 to stop): ");
        scanf("%d,%lf", &id, &amount);
        if (id == 0) {
            break;
        }

        // Validates id
        if (id < 0 || id > stockItems) {
            printf("Invalid Product - Enter a number between 0 and %d: ", stockItems);
            scanf("%d,%lf", &id, &amount);
        }
        else {
            run = 1;
        }

        // Validates quantity
        while (amount < 0.10 || amount > 100.00) { // Runs until amount is within range
            printf("Invalid quantity - Enter a number between 0.10 and 100.00: ");
            scanf("%d,%lf", &id, &amount);
        }
        amountCheck(amount, storeStock, id, saleItems); // Calls amountCheck function

        items++;
    } while (run != 0);

    return items;
}
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- End

// PrintSalesReport
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ Start
double printSalesReport(struct StockRecord storeStock[], struct SalesRecord saleItems[], int stockItems) {
    double subTotal = 0.0, taxes = 0.0, total = 0.0, totalPrice = 0.0;

    printf("\n");
    centreText(64, '*', " Seneca Groceries "); // calls centreText function
    printf("\n");
    centreText(64, '=', "");  // Calls centreText function
    printf("\n");

    // Loops MAX_ITEMS_IN_SALE(100) times, just in case there are more then 14 items in the stock 
    for (int i = 0; i < MAX_ITEMS_IN_SALE; i++) {
        if (saleItems[i].id > 0) { // Checks if the sold item id is greater than 0
            totalPrice = storeStock[i].amountSold * storeStock[i].items.price;
            printf("%30s%9.2lf%8.2lf\n", storeStock[i].name, storeStock[i].items.price, totalPrice);
            subTotal += totalPrice;
            if (storeStock[i].items.category == 6 || storeStock[i].items.category == 7) { // Checks if the items category is 6 or 7, then it calculates the taxes for that item
                taxes = storeStock[i].items.price * 0.13;
            }
        }
    }

    total = subTotal + taxes;
    printf("%s%33.2lf\n", "Purchase Total", subTotal);
    printf("%s%44.2lf\n", "Tax", taxes);
    printf("%s%42.2lf\n", "Total", total);
    printf("%s\n\n", "Thank you for shopping at Seneca!");

    return subTotal;
}
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- End

// GetTopSellers
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ Start
void getTopSellers(struct StockRecord storeStock[], int stockItems, struct SalesRecord* topSellers[], int num, int cat) {
    int j = 0; 
    struct SalesRecord* temp;

    // Populates the topSellers array
    for (int i = 0; i < stockItems; i++) {
        if (cat+1 == storeStock[i].items.category && storeStock[i].amountSold > 0.00) { // Checks if cat + 1 is equal to the items category and if the items amountSold is greater than 0.00 
            topSellers[j] = i;
            j++;
        }
    }

    // Atttempt to sort topSellers
    for (int i = num - 1; i >= 0; i--) {
        for (int j = 0; j < num; j++) {
            int index = topSellers[j];
            if (storeStock[index].amountSold < storeStock[index + 1].amountSold) {

                // Test to see which ones need to move
                //printf("%.2lf > %.2lf\n", storeStock[index].amountSold, storeStock[index + 1].amountSold);

                // Works until here
                //temp = topSellers[index];
                //topSellers[index] = topSellers[index + 1];
                //topSellers[index + 1] = temp;
            }
        }
    }
}
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- End

// PrintTopSellers
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ Start
void printTopSellers(struct StockRecord storeStock[], struct SalesRecord* topSellers[], int num, int cat) {
    int pos = 1, index;

    // Prints out a specific line for each category
    switch (cat)
    {
    case 0:
        printf("------------ Top %d sellers %s ------------\n", num, "produce");
        break;
    case 1:
        printf("------------ Top %d sellers %s -------------\n", num, "bakery");
        break;
    case 2:
        printf("------------- Top %d sellers %s --------------\n", num, "meat");
        break;
    case 3:
        printf("------------- Top %d sellers %s -------------\n", num, "dairy");
        break;
    case 4:
        printf("------------ Top %d sellers %s -------------\n", num, "baking");
        break;
    case 5:
        printf("---------- Top %d sellers %s ----------\n", num, "house wares");
        break;
    case 6:
        printf("--------- Top %d sellers %s ---------\n", num, "miscellaneous");
        break;
    }

    printf("%s%27s%8s\n", "Rank", "Product", "Sales");

    for (int i = 0; i < num; i++) {
        index = topSellers[i];

        if (index < 0) {
            printf("%d%30s%8.2lf\n", pos, "<none>", 0.00);
        }
        else {
            printf("%d%30s%8.2lf\n", pos, storeStock[index].name, storeStock[index].amountSold);
        }
        pos++;
    }

    // Clears the topSellers array
    for (int i = 0; i < sizeof(topSellers) + 1; i++) {
        topSellers[i] = -1;
    }
}
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- End















