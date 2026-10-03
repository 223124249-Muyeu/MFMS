
#include <stdio.h>
#include "validation.h"

void displayMenu(void);

int main(void)
{
    int choice;

    do
    {
        displayMenu();
        choice = readInt("Enter your choice: ", 1, 6);

        switch (choice)
        {
            case 1: printf("\n[Employee Management - coming soon]\n"); break;
            case 2: printf("\n[Budget Management - coming soon]\n");   break;
            case 3: printf("\n[Supplier Management - coming soon]\n"); break;
            case 4: printf("\n[Asset Management - coming soon]\n");    break;
            case 5: printf("\n[Reports - coming soon]\n");             break;
            case 6: printf("\nGoodbye!\n");                            break;
        }
    } while (choice != 6);

    return 0;
}

void displayMenu(void)
{
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("========================================\n");
}





