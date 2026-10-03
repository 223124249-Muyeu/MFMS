#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "validation.h"

void addAsset(Asset assets[], int *assetCount)
{
    int newID;
    int i;

    if (*assetCount >= 100)
    {
        printf("Asset register is full.\n");
        return;
    }

    newID = readInt("Enter Asset ID: ", 1, 9999);

    for (i = 0; i < *assetCount; i++)
    {
        if (assets[i].assetID == newID)
        {
            printf("Asset ID already exists.\n");
            return;
        }
    }

    assets[*assetCount].assetID = newID;

    readString("Enter Asset Name: ", assets[*assetCount].assetName, 50);
    readString("Enter Asset Type: ", assets[*assetCount].assetType, 30);

    assets[*assetCount].purchaseValue =
        readDouble("Enter Purchase Value: ", 0.0);

    readString("Enter Department: ", assets[*assetCount].department, 30);
    readString("Enter Condition: ", assets[*assetCount].condition, 30);

    *assetCount = *assetCount + 1;

    printf("Asset added successfully.\n");
}

void displayAssets(Asset assets[], int assetCount)
{
    int i;

    printf("\n--- Asset Information ---\n");

    for (i = 0; i < assetCount; i++)
    {
        printf("Asset ID: %d\n", assets[i].assetID);
        printf("Asset Name: %s\n", assets[i].assetName);
        printf("Asset Type: %s\n", assets[i].assetType);
        printf("Purchase Value: %.2f\n", assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
        printf("\n");
    }
}

void searchAsset(Asset assets[], int assetCount)
{
    int searchID;
    int i;

    searchID = readInt("Enter Asset ID to search: ", 1, 9999);

    for (i = 0; i < assetCount; i++)
    {
        if (searchID == assets[i].assetID)
        {
            printf("\nAsset found!\n");
            printf("Asset ID: %d\n", assets[i].assetID);
            printf("Asset Name: %s\n", assets[i].assetName);
            printf("Asset Type: %s\n", assets[i].assetType);
            printf("Purchase Value: %.2f\n", assets[i].purchaseValue);
            printf("Department: %s\n", assets[i].department);
            printf("Condition: %s\n", assets[i].condition);

            return;
        }
    }

    printf("Asset not found.\n");
}