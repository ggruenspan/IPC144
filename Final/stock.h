//==============================================
// Name:           Gerred Gruenspan
// Student Number: 155315195
// Email:          ggruenspan@myseneca.ca
// Group Members:  N/A
// Section:        NVV
// Date:           2020/12/07
//==============================================
// Final Assignment
//==============================================

//--------------------------------
// Function Prototypes
//--------------------------------
void amountCheck(int amount, struct StockRecord storeStock[], int id, struct SalesRecord saleItems[]);

void centreText(int fieldWidth, char specialChar, char* text);

int readStockItems(struct StockRecord storeStock[], int entries, int placeHolder);

void printStockReport(const struct StockRecord storeStock[], int stockItems);

int readSale(struct StockRecord storeStock[], int stockItems, struct SalesRecord saleItems[]);

double printSalesReport(const struct StockRecord storeStock[], struct SalesRecord saleItems[], int stockItems);

void getTopSellers(struct StockRecord storeStock[], int stockItems, struct SalesRecord topSellers[], int num, int cat);

void printTopSellers(const struct StockRecord storeStock[], struct SalesRecord topSellers[], int num, int cat);

//--------------------------------
// Structure Types
//--------------------------------

#define NAME_SIZE 30
#define MAX_ITEMS_IN_SALE 100
#define NUM_CATS 7

struct Item
{
    double amount;
    int category;
    double price;
    int byWeight;
};

struct StockRecord
{
    struct Item items;
    char name[NAME_SIZE + 1];
    double amountSold;
};

struct SalesRecord
{
    int id;
};