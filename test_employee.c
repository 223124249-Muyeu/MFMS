
#include <stdio.h>
#include "employees.h"

int main(void)
{
    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    do
    {
        printf("\n===== EMPLOYEE MANAGEMENT =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                addEmployee(employees, &count);
                break;

            case 2:
                displayEmployees(employees, count);
                break;

            case 3:
                searchEmployee(employees, count);
                break;

            case 4:
                printf("\nExiting employee management...\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}