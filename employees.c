
#include <stdio.h>
#include <string.h>
#include "employees.h"

void addEmployee(Employee employees[], int *count)
{
    Employee newEmployee;

    if (*count >= MAX_EMPLOYEES)
    {
        printf("\nEmployee storage is full.\n");
        return;
    }

    printf("\n===== ADD EMPLOYEE =====\n");

    printf("Enter employee ID: ");
    scanf("%d", &newEmployee.id);

    getchar();

    printf("Enter employee name: ");
    fgets(newEmployee.name, sizeof(newEmployee.name), stdin);
    newEmployee.name[strcspn(newEmployee.name, "\n")] = '\0';

    while (strlen(newEmployee.name) == 0)
    {
        printf("Name cannot be empty. Enter employee name: ");
        fgets(newEmployee.name, sizeof(newEmployee.name), stdin);
        newEmployee.name[strcspn(newEmployee.name, "\n")] = '\0';
    }

    printf("Enter department: ");
    fgets(newEmployee.department, sizeof(newEmployee.department), stdin);
    newEmployee.department[strcspn(newEmployee.department, "\n")] = '\0';

    printf("Enter basic salary: ");
    scanf("%f", &newEmployee.basicSalary);

    while (newEmployee.basicSalary < 0)
    {
        printf("Salary cannot be negative. Enter basic salary again: ");
        scanf("%f", &newEmployee.basicSalary);
    }

    printf("Enter housing allowance: ");
    scanf("%f", &newEmployee.housingAllowance);

    while (newEmployee.housingAllowance < 0)
    {
        printf("Allowance cannot be negative. Enter housing allowance again: ");
        scanf("%f", &newEmployee.housingAllowance);
    }

    printf("Enter transport allowance: ");
    scanf("%f", &newEmployee.transportAllowance);

    while (newEmployee.transportAllowance < 0)
    {
        printf("Allowance cannot be negative. Enter transport allowance again: ");
        scanf("%f", &newEmployee.transportAllowance);
    }

    employees[*count] = newEmployee;
    (*count)++;

    printf("\nEmployee added successfully.\n");
}

void displayEmployees(Employee employees[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n========== EMPLOYEE LIST ==========\n");

    for (i = 0; i < count; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Department: %s\n", employees[i].department);
        printf("Basic Salary: N$%.2f\n", employees[i].basicSalary);
        printf("Housing Allowance: N$%.2f\n",
               employees[i].housingAllowance);
        printf("Transport Allowance: N$%.2f\n",
               employees[i].transportAllowance);
        printf("Total Salary: N$%.2f\n",
               calculateSalary(employees[i]));
    }
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

    printf("\nEnter employee ID to search: ");
    scanf("%d", &searchID);

    for (i = 0; i < count; i++)
    {
        if (employees[i].id == searchID)
        {
            printf("\n===== EMPLOYEE FOUND =====\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Basic Salary: N$%.2f\n", employees[i].basicSalary);
            printf("Housing Allowance: N$%.2f\n",
                   employees[i].housingAllowance);
            printf("Transport Allowance: N$%.2f\n",
                   employees[i].transportAllowance);
            printf("Total Salary: N$%.2f\n",
                   calculateSalary(employees[i]));

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nEmployee with ID %d was not found.\n", searchID);
    }
}

float calculateSalary(Employee employee)
{
    return employee.basicSalary
           + employee.housingAllowance
           + employee.transportAllowance;
}