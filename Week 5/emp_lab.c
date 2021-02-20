//==============================================
// Name:           Gerred Gruenspan
// Student Number: 155315195
// Email:          ggruenspan@myseneca.ca
// Section:        NVV
// Workshop:       5 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 2

struct emp
{
	int	id;
	int age;
	double salary;
};

/* main program */
int main(void)
{
	int option;
	static int i;
	struct emp empData[SIZE] = { {0} };

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		// Print the option 
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option)
		{
		case 0:	// Exit the program

			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;

		case 1: // Display Employee Data

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for (i = 0; i < SIZE; i++)
			{
				if (empData[i].id == 0) {
					break;
				}
				printf("%6d%9d%11.2lf\n", empData[i].id, empData[i].age, empData[i].salary);
			}

			printf("\n");

			break;

		case 2:	// Adding Employee

			printf("Adding Employee\n");
			printf("===============\n");

			while (empData[i].id == 0) {
				printf("Enter Employee ID: ");
				scanf("%d", &empData[i].id);
				printf("Enter Employee Age: ");
				scanf("%d", &empData[i].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &empData[i].salary);
				printf("\n");
				i++;
				break;
			}

			if (i >= SIZE) {
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}

			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0;
}
