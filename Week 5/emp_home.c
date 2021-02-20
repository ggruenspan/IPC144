#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h> 
#define SIZE 4

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
	int idNumber;
	bool run = true;
	int j;
	int pos;
	static int i;
	struct emp empData[SIZE] = { {0} };

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		// Print the option 
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
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
				if (empData[i].id != 0) {
					printf("%6d%9d%11.2lf\n", empData[i].id, empData[i].age, empData[i].salary);
				}
			}

			printf("\n");

			break;

		case 2:	// Adding Employee

			printf("Adding Employee\n");
			printf("===============\n");

			for (i = 0; i < SIZE; i++) {
				if (empData[i].id == 0) {
					printf("Enter Employee ID: ");
					scanf("%d", &empData[i].id);
					printf("Enter Employee Age: ");
					scanf("%d", &empData[i].age);
					printf("Enter Employee Salary: ");
					scanf("%lf", &empData[i].salary);
					printf("\n");
					while (empData[i].id < 0 || empData[i].age < 0 || empData[i].salary < 0) {
						printf("ERROR!!! Id, Age or Salary cannot be zero\n");
						printf("Enter Employee ID: ");
						scanf("%d", &empData[i].id);
						printf("Enter Employee Age: ");
						scanf("%d", &empData[i].age);
						printf("Enter Employee Salary: ");
						scanf("%lf", &empData[i].salary);
						printf("\n");
					}
					break;
				}
			}

			if (i >= SIZE) {
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}

			break;

		case 3: // Update Employee Salary

			printf("Update Employee Salary\n");
			printf("======================\n");

			idNumber = 0;
			run = true;
			pos = 0;

			do
			{
				printf("Enter Employee ID: ");
				scanf("%d", &idNumber);

				for (j = 0; j < SIZE; j++) {

					if (idNumber == empData[j].id) {
						pos = j;
						run = false;
						break;
					}
					pos = j;
				}

				if (idNumber != empData[j].id) {
					printf("*** ERROR: Employee ID not found! ***\n");
				}

			} while (run == true);

			printf("The current salary is %.2lf\n", empData[pos].salary);
			printf("Enter Employee New Salary: ");
			scanf("%lf", &empData[pos].salary);
			printf("\n");
			while (empData[pos].salary < 0) {
				printf("ERROR!!! Salary cannot be zero\n");
				printf("Enter Employee New Salary: ");
				scanf("%lf", &empData[pos].salary);
				printf("\n");
			}
			break;

		case 4: // Remove Employee

			printf("Remove Employee\n");
			printf("===============\n");

			idNumber = 0;
			run = true;
			pos = 0;

			do
			{
				printf("Enter Employee ID: ");
				scanf("%d", &idNumber);

				for (j = 0; j < SIZE; j++) {

					if (idNumber == empData[j].id) {
						pos = j;
						run = false;
						break;
					}
					pos = j;
				}

				if (idNumber != empData[j].id) {
					printf("*** ERROR: Employee ID not found! ***\n");
				}

			} while (run == true);

			printf("Employee %d will be removed\n", idNumber);
			printf("\n");

			empData[j].id = 0;
			empData[j].age = 0;
			empData[j].salary = 0;

			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0;
}
