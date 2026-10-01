#include <stdio.h>
#include <string.h>
#include "supplier.h"

int main() {
    int supplierIds[10];
    char supplierNames[10][120];
    char emails[10][120];
    char phones[10][25];
    char towns[10][40];
    int count = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch(choice) {
            case 1:
                addSupplier(supplierIds, supplierNames, emails, phones, towns, &count);
                break;
            case 2:
                displaySupplier(supplierIds, supplierNames, emails, phones, towns, count);
                break;
            case 3:
                searchSupplier(supplierIds, supplierNames, emails, phones, towns, count);
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void displayMenu() {
    printf("\n=================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("=================================\n");
    printf("1. Add a supplier\n");
    printf("2. Display suppliers\n");
    printf("3. Search for supplier\n");
    printf("4. Exit\n");
    printf("Enter choice (1-4): ");
}

void addSupplier(int ids[], char names[][120], char emails[][120], char phones[][25], char towns[][40], int *count) {
    if (*count >= 10) {
        printf("\nSupplier list is full! Cannot add more suppliers.\n");
        return;
    }
    
    printf("\nEnter supplier ID: ");
    scanf("%d", &ids[*count]);
    while (getchar() != '\n');

    do {
        printf("Enter supplier's name: ");
        fgets(names[*count], 120, stdin);
        names[*count][strcspn(names[*count], "\n")] = '\0';

        if (strlen(names[*count]) == 0) {
            printf("Error: Supplier name cannot be empty. Try again.\n");
        }
    } while (strlen(names[*count]) == 0);

    printf("Enter email: ");
    fgets(emails[*count], 120, stdin);
    emails[*count][strcspn(emails[*count], "\n")] = '\0';

    printf("Enter phone number: ");
    fgets(phones[*count], 25, stdin);
    phones[*count][strcspn(phones[*count], "\n")] = '\0';

    printf("Enter town: ");
    fgets(towns[*count], 40, stdin);
    towns[*count][strcspn(towns[*count], "\n")] = '\0';

    (*count)++;
    printf("\nSupplier added successfully!\n");
}

void displaySupplier(int ids[], char names[][120], char emails[][120], char phones[][25], char towns[][40], int count) {
    if (count == 0) {
        printf("\nNo suppliers recorded yet.\n");
        return;
    }
    
    printf("\n--- SUPPLIER DETAILS ---\n");
    for (int i = 0; i < count; i++) {
        printf("Supplier %d:\n", i + 1);
        printf("  ID:    %d\n", ids[i]);
        printf("  Name:  %s\n", names[i]);
        printf("  Email: %s\n", emails[i]);
        printf("  Phone: %s\n", phones[i]);
        printf("  Town:  %s\n", towns[i]);
        printf("------------------------\n");
    }
}

void searchSupplier(int ids[], char names[][120], char emails[][120], char phones[][25], char towns[][40], int count) {
    char searchName[120];
    int found = 0;

    if (count == 0) {
        printf("\nNo suppliers available to search.\n");
        return;
    }
    
    printf("\nEnter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], searchName) == 0) {
            printf("\nSupplier found:\n");
            printf("  ID:    %d\n", ids[i]);
            printf("  Name:  %s\n", names[i]);
            printf("  Email: %s\n", emails[i]);
            printf("  Phone: %s\n", phones[i]);
            printf("  Town:  %s\n", towns[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("\nSupplier not found.\n");
    }
}