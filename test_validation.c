#include <stdio.h>
#include "validation.h"

int main(void)
{
    int number;
    double amount;
    char name[20];

    number = readInt("Enter a number (1-10): ", 1, 10);
    printf("You entered: %d\n", number);

    amount = readDouble("Enter an amount (0 or more): ", 0);
    printf("You entered: %.2f\n", amount);

    readString("Enter a name: ", name, sizeof(name));
    printf("You entered: %s\n", name);

    return 0;
}