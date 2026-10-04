#include <stdio.h>
#include "reports.h"
#include "budget.h"

void employeeReport(Employee employees[], int count)
{
    float total = 0, highest, lowest, salary;

    printf("\n========== EMPLOYEE REPORT ==========\n");

    if (count == 0)
    {
        printf("No employees registered.\n");
        return;
    }

    highest = lowest = calculateSalary(employees[0]);

    for (int i = 0; i < count; i++)
    {
        salary = calculateSalary(employees[i]);
        total += salary;

        if (salary > highest)
        {
            highest = salary;
        }
        if (salary < lowest)
        {
            lowest = salary;
        }
    }

    printf("Total Employees: %d\n", count);
    printf("Average Salary:  N$%.2f\n", total / count);
    printf("Highest Salary:  N$%.2f\n", highest);
    printf("Lowest Salary:   N$%.2f\n", lowest);
}

void supplierReport(char names[][120], char towns[][40], int count)
{
    printf("\n========== SUPPLIER REPORT ==========\n");

    if (count == 0)
    {
        printf("No suppliers registered.\n");
        return;
    }

    printf("Total Suppliers: %d\n\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s (%s)\n", i + 1, names[i], towns[i]);
    }
}

void assetReport(Asset assets[], int count)
{
    double totalValue = 0;

    printf("\n========== ASSET REPORT ==========\n");

    if (count == 0)
    {
        printf("No assets registered.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d. [%d] %s | %s | %s | N$%.2f | %s\n",
               i + 1, assets[i].assetID, assets[i].assetName,
               assets[i].assetType, assets[i].department,
               assets[i].purchaseValue, assets[i].condition);
        totalValue += assets[i].purchaseValue;
    }

    printf("\nTotal Assets: %d\n", count);
    printf("Total Value:  N$%.2f\n", totalValue);
}

void budgetReport(void)
{
    float allocated = getTotalAllocated();
    float spent = getTotalExpenditure();

    printf("\n========== BUDGET REPORT ==========\n");
    printf("Total Allocated Budget: N$%.2f\n", allocated);
    printf("Total Expenditure:      N$%.2f\n", spent);
    printf("Remaining Budget:       N$%.2f\n", allocated - spent);

    printf("\nDepartments exceeding budget:\n");
    listOverBudget();
}
