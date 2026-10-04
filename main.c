#include <stdio.h>
#include "validation.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

#define MAX_SUPPLIERS 10
#define MAX_ASSETS    100

void displayMenu(void);
void employeeMenu(Employee employees[], int *employeeCount);
void budgetMenu(void);
void supplierMenu(int ids[], char names[][120], char emails[][120],
                  char phones[][25], char towns[][40], int *supplierCount);
void assetMenu(Asset assets[], int *assetCount);
void reportsMenu(Employee employees[], int employeeCount,
                 char supplierNames[][120], char supplierTowns[][40],
                 int supplierCount, Asset assets[], int assetCount);

int main(void)
{
    int choice;

    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;

    int  supplierIds[MAX_SUPPLIERS];
    char supplierNames[MAX_SUPPLIERS][120];
    char supplierEmails[MAX_SUPPLIERS][120];
    char supplierPhones[MAX_SUPPLIERS][25];
    char supplierTowns[MAX_SUPPLIERS][40];
    int  supplierCount = 0;

    Asset assets[MAX_ASSETS];
    int assetCount = 0;

    do
    {
        displayMenu();
        choice = readInt("Enter your choice: ", 1, 6);

        switch (choice)
        {
            case 1:
                employeeMenu(employees, &employeeCount);
                break;
            case 2:
                budgetMenu();
                break;
            case 3:
                supplierMenu(supplierIds, supplierNames, supplierEmails,
                             supplierPhones, supplierTowns, &supplierCount);
                break;
            case 4:
                assetMenu(assets, &assetCount);
                break;
            case 5:
                reportsMenu(employees, employeeCount, supplierNames,
                            supplierTowns, supplierCount, assets, assetCount);
                break;
            case 6:
                printf("\nGoodbye!\n");
                break;
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

void employeeMenu(Employee employees[], int *employeeCount)
{
    int choice;

    do
    {
        printf("\n---------- EMPLOYEE MANAGEMENT ----------\n");
        printf("1. Add employee\n");
        printf("2. Display employees\n");
        printf("3. Search employee\n");
        printf("4. Back to main menu\n");
        printf("-----------------------------------------\n");

        choice = readInt("Enter your choice: ", 1, 4);

        switch (choice)
        {
            case 1: addEmployee(employees, employeeCount);        break;
            case 2: displayEmployees(employees, *employeeCount);  break;
            case 3: searchEmployee(employees, *employeeCount);    break;
            case 4: break;
        }

        if (choice != 4)
        {
            pauseScreen();
        }
    } while (choice != 4);
}

void budgetMenu(void)
{
    int choice;

    do
    {
        printf("\n---------- BUDGET MANAGEMENT ----------\n");
        printf("1. Enter department budget\n");
        printf("2. Enter expenditure\n");
        printf("3. Display budgets\n");
        printf("4. List departments over budget\n");
        printf("5. Back to main menu\n");
        printf("---------------------------------------\n");

        choice = readInt("Enter your choice: ", 1, 5);

        switch (choice)
        {
            case 1: enterBudget();      break;
            case 2: enterExpenditure(); break;
            case 3: displayBudgets();   break;
            case 4: listOverBudget();   break;
            case 5: break;
        }

        if (choice != 5)
        {
            pauseScreen();
        }
    } while (choice != 5);
}

void supplierMenu(int ids[], char names[][120], char emails[][120],
                  char phones[][25], char towns[][40], int *supplierCount)
{
    int choice;

    do
    {
        printf("\n---------- SUPPLIER MANAGEMENT ----------\n");
        printf("1. Add supplier\n");
        printf("2. Display suppliers\n");
        printf("3. Search supplier\n");
        printf("4. Back to main menu\n");
        printf("-----------------------------------------\n");

        choice = readInt("Enter your choice: ", 1, 4);

        switch (choice)
        {
            case 1:
                addSupplier(ids, names, emails, phones, towns, supplierCount);
                break;
            case 2:
                displaySupplier(ids, names, emails, phones, towns, *supplierCount);
                break;
            case 3:
                searchSupplier(ids, names, emails, phones, towns, *supplierCount);
                break;
            case 4:
                break;
        }

        if (choice != 4)
        {
            pauseScreen();
        }
    } while (choice != 4);
}

void assetMenu(Asset assets[], int *assetCount)
{
    int choice;

    do
    {
        printf("\n---------- ASSET MANAGEMENT ----------\n");
        printf("1. Add asset\n");
        printf("2. Display assets\n");
        printf("3. Search asset\n");
        printf("4. Back to main menu\n");
        printf("--------------------------------------\n");

        choice = readInt("Enter your choice: ", 1, 4);

        switch (choice)
        {
            case 1: addAsset(assets, assetCount);        break;
            case 2: displayAssets(assets, *assetCount);  break;
            case 3: searchAsset(assets, *assetCount);    break;
            case 4: break;
        }

        if (choice != 4)
        {
            pauseScreen();
        }
    } while (choice != 4);
}

void reportsMenu(Employee employees[], int employeeCount,
                 char supplierNames[][120], char supplierTowns[][40],
                 int supplierCount, Asset assets[], int assetCount)
{
    int choice;

    do
    {
        printf("\n---------- REPORTS ----------\n");
        printf("1. Employee report\n");
        printf("2. Budget report\n");
        printf("3. Supplier report\n");
        printf("4. Asset report\n");
        printf("5. Back to main menu\n");
        printf("-----------------------------\n");

        choice = readInt("Enter your choice: ", 1, 5);

        switch (choice)
        {
            case 1: employeeReport(employees, employeeCount);                    break;
            case 2: budgetReport();                                              break;
            case 3: supplierReport(supplierNames, supplierTowns, supplierCount); break;
            case 4: assetReport(assets, assetCount);                             break;
            case 5: break;
        }

        if (choice != 5)
        {
            pauseScreen();
        }
    } while (choice != 5);
}





