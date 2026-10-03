#ifndef BUDGET_H
#define BUDGET_H
#define MAX_DEPTS 100

struct Budget {
    char deptName[50];
    float allocated;
    float expenditure;
    float remaining;
    char status[25]; //Within limit/ exceeded
};

void enterBudget();
void enterExpenditure();
void calculateBudget(int index);
void displayBudgets();
void listOverBudget();

//report
float getRemainingByDept(char* dept);
float getTotalAllocated();
float getTotalExpenditure();
int getBudgetCount();
void saveBudgetsToFile();
void loadBudgetsFromFile();

#endif
