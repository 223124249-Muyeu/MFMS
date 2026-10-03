#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "budget.h"
#include "validation.h"

struct Budget budgets[MAX_DEPTS];
int budgetCount = 0;

void calculateBudget(int index) {
    budgets[index].remaining = budgets[index].allocated - budgets[index].expenditure;
    if(budgets[index].remaining < 0)
        strcpy(budgets[index].status, "EXCEEDED");
    else
        strcpy(budgets[index].status, "WITHIN BUDGET");
}

void enterBudget() {
    if(budgetCount >= MAX_DEPTS) {
        printf("Limit reached!\n"); return;
    }
    struct Budget b;
    readString("\nDept Name: ", b.deptName, sizeof(b.deptName));
   
    for(int i=0; i<budgetCount; i++) {
        if(strcmp(budgets[i].deptName, b.deptName)==0) {
            printf("Error: Duplicate department! Use Expenditure.\n"); return;
        }
    }
    b.allocated = (float)readDouble("Allocated Budget: ", 0.01);
    b.expenditure = 0;
    b.remaining = b.allocated;
    strcpy(b.status, "WITHIN BUDGET");
    budgets[budgetCount++] = b;
    printf("Added!\n");
}

void enterExpenditure() {
    char name[50];
    float amt;
    readString("\nDept Name: ", name, sizeof(name));

    int found = -1;
    for(int i=0; i<budgetCount; i++) {
        if(strcmp(budgets[i].deptName, name)==0) { found=i; break; }
    }
    if(found==-1) { printf("Not found! Add budget first.\n"); return; }

    amt = (float)readDouble("Expenditure Amount: ", 0.01);

    budgets[found].expenditure += amt;
    calculateBudget(found);
    printf("Remaining: %.2f Status: %s\n", budgets[found].remaining, budgets[found].status);
}

void displayBudgets() {
    if(budgetCount==0) { printf("No budgets yet!\n"); return; }
    printf("\n%-15s %-12s %-12s %-12s %s\n","Department","Allocated","Spent","Remaining","Status");
    printf("------------------------------------------------------------------\n");
    for(int i=0; i<budgetCount; i++) {
        printf("%-15s %-12.2f %-12.2f %-12.2f %s\n",
            budgets[i].deptName, budgets[i].allocated,
            budgets[i].expenditure, budgets[i].remaining, budgets[i].status);
    }
}

void listOverBudget() {
    int c=0;
    printf("\n--- OVER BUDGET ---\n");
    for(int i=0; i<budgetCount; i++) {
        if(strcmp(budgets[i].status, "EXCEEDED")==0) {
            printf("%s exceeded by %.2f\n", budgets[i].deptName, -budgets[i].remaining);
            c++;
        }
    }
    if(c==0) printf("All WITHIN BUDGET\n");
}


float getRemainingByDept(char* dept) {
    for(int i=0; i<budgetCount; i++)
        if(strcmp(budgets[i].deptName, dept)==0) return budgets[i].remaining;
    return 0;
}
float getTotalAllocated() {
    float t=0; for(int i=0; i<budgetCount; i++) t+=budgets[i].allocated; return t;
}
float getTotalExpenditure() {
    float t=0; for(int i=0; i<budgetCount; i++) t+=budgets[i].expenditure; return t;
}
int getBudgetCount() { return budgetCount; }


void saveBudgetsToFile() {
    FILE *f = fopen("data/budget.txt","w");
    if(!f) return;
    for(int i=0; i<budgetCount; i++)
        fprintf(f,"%s %.2f %.2f\n", budgets[i].deptName, budgets[i].allocated, budgets[i].expenditure);
    fclose(f);
}
void loadBudgetsFromFile() {
    FILE *f = fopen("data/budget.txt","r");
    if(!f) return;
    budgetCount=0;
    while(fscanf(f,"%s %f %f", budgets[budgetCount].deptName, &budgets[budgetCount].allocated, &budgets[budgetCount].expenditure)==3) {
        calculateBudget(budgetCount);
        budgetCount++;
    }
    fclose(f);
}
