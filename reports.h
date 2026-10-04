#ifndef REPORTS_H
#define REPORTS_H

#include "employees.h"
#include "assets.h"

void employeeReport(Employee employees[], int count);
void supplierReport(char names[][120], char towns[][40], int count);
void assetReport(Asset assets[], int count);
void budgetReport(void);

#endif
