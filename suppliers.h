#ifndef SUPPLIER_H
#define SUPPLIER_H

void addSupplier(int ids[], char names[][120], char emails[][120], char phones[][25], char towns[][40], int *count);
void displaySupplier(int ids[], char names[][120], char emails[][120], char phones[][25], char towns[][40], int count);
void searchSupplier(int ids[], char names[][120], char emails[][120], char phones[][25], char towns[][40], int count);

#endif