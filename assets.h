#ifndef ASSETS_H
#define ASSETS_H

typedef struct
{
    int assetID;
    char assetName[50];
    char assetType[30];
    double purchaseValue;
    char department[30];
    char condition[30];
} Asset;

void displayAssets(Asset assets[], int assetCount);
void searchAssets(Asset assets[], int assetCount);

#endif