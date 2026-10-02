#include <stdio.h>
#include "assets.h"

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

    printf("\nEnter Asset ID to search: ");
    scanf("%d", &searchID);

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