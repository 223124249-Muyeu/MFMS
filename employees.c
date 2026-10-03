#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "validation.h"

void addEmployee(Employee employees[], int *count)
{
    int id;
    int duplicate;
    int i;

    if (*count >= MAX_EMPLOYEES)
    {
        printf("\nEmployee storage is full.\n");
        pauseScreen();
        return;
    }

    printf("\n===== ADD EMPLOYEE =====\n");

    do
    {
        duplicate = 0;
        id = readInt("Enter employee ID: ", 1, 999999);

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

    readString("Enter employee name: ", newEmployee.name, 50);
    readString("Enter department: ", newEmployee.department, 50);

    newEmployee.basicSalary        = (float)readDouble("Enter basic salary: ", 0);
    newEmployee.housingAllowance   = (float)readDouble("Enter housing allowance: ", 0);
    newEmployee.transportAllowance = (float)readDouble("Enter transport allowance: ", 0);

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
        pauseScreen();
        return;
    }

    searchID = readInt("\nEnter employee ID to search: ", 1, 999999);

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

void searchEmployeeByName(Employee employees[], int count)
{
    char searchName[50];
    int i;
    int found = 0;

    if (count == 0)
    {
        printf("\nNo employees have been added yet.\n");
        pauseScreen();
        return;
    }

    readString("Enter employee name to search: ", searchName, 50);

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
        pauseScreen();
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