#include <stdio.h>
#include <string.h>
#include "employees.h"

/* clear the input buffer */
static void clearInput(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/* read a string safely */
static void readLine(const char *prompt, char *buffer, int size)
{
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL)
    {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';
    }
}

/* read a number and re-ask if invalid */
static int readIntSafe(const char *prompt)
{
    int value;
    int result;

    while (1)
    {
        printf("%s", prompt);
        result = scanf("%d", &value);

        if (result == 1)
        {
            clearInput();
            return value;
        }

        printf("Invalid input. Please enter a number.\n");
        clearInput();
    }
}

/* read a positive float */
static float readFloatSafe(const char *prompt)
{
    float value;
    int result;

    while (1)
    {
        printf("%s", prompt);
        result = scanf("%f", &value);

        if (result == 1 && value >= 0)
        {
            clearInput();
            return value;
        }

        printf("Invalid input. Enter a non-negative number.\n");
        clearInput();
    }
}

void addEmployee(Employee employees[], int *count)
{
    int id;
    int duplicate;
    int i;

    if (*count >= MAX_EMPLOYEES)
    {
        printf("\nEmployee storage is full.\n");
        return;
    }

    printf("\n===== ADD EMPLOYEE =====\n");

    /* keep asking until a unique ID is given */
    do
    {
        duplicate = 0;
        id = readIntSafe("Enter employee ID: ");

        for (i = 0; i < *count; i++)
        {
            if (employees[i].id == id)
            {
                duplicate = 1;
                printf("ID %d is already used. Please enter a different ID.\n", id);
                break;
            }
        }
    } while (duplicate);

    Employee newEmployee;
    newEmployee.id = id;

    readLine("Enter employee name: ", newEmployee.name, 50);
    readLine("Enter department: ", newEmployee.department, 50);

    newEmployee.basicSalary        = readFloatSafe("Enter basic salary: ");
    newEmployee.housingAllowance   = readFloatSafe("Enter housing allowance: ");
    newEmployee.transportAllowance = readFloatSafe("Enter transport allowance: ");

    employees[*count] = newEmployee;
    (*count)++;

    printf("Employee added successfully.\n");
}

void searchEmployee(Employee employees[], int count)
{
    int searchID;
    int i;
    int found = 0;

    if (count == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    searchID = readIntSafe("\nEnter employee ID to search: ");

    for (i = 0; i < count; i++)
    {
        if (employees[i].id == searchID)
        {
            printf("\nEmployee found:\n");
            printf("  ID:                 %d\n", employees[i].id);
            printf("  Name:               %s\n", employees[i].name);
            printf("  Department:         %s\n", employees[i].department);
            printf("  Basic Salary:       %.2f\n", employees[i].basicSalary);
            printf("  Housing Allowance:  %.2f\n", employees[i].housingAllowance);
            printf("  Transport Allowance:%.2f\n", employees[i].transportAllowance);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No employee found with ID %d.\n", searchID);
    }
}

/* search by name - uses strcmp */
void searchEmployeeByName(Employee employees[], int count)
{
    char searchName[50];
    int i;
    int found = 0;

    if (count == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("Enter employee name to search: ");
    if (fgets(searchName, 50, stdin) != NULL)
    {
        size_t len = strlen(searchName);
        if (len > 0 && searchName[len - 1] == '\n')
            searchName[len - 1] = '\0';
    }

    for (i = 0; i < count; i++)
    {
        if (strcmp(employees[i].name, searchName) == 0)
        {
            printf("\nEmployee found:\n");
            printf("  ID:         %d\n", employees[i].id);
            printf("  Name:       %s\n", employees[i].name);
            printf("  Department: %s\n", employees[i].department);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No employee found with name '%s'.\n", searchName);
    }
}

void displayEmployees(Employee employees[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n===== EMPLOYEE LIST =====\n");
    printf("%-6s %-20s %-15s %-12s\n", "ID", "Name", "Department", "Basic");
    printf("------------------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%-6d %-20s %-15s %-12.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].basicSalary);
    }
}

float calculateSalary(Employee employee)
{
    float total = employee.basicSalary
                + employee.housingAllowance
                + employee.transportAllowance;
    return total;
}