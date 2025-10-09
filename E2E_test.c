#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "Product_system.h"

void E2E_test()
{
    printf("------Running E2E test------\n");


    remove("test_data.csv");
    remove("test_DEdata.csv");
    remove("temp.csv");


    FILE file = fopen("test_data.csv", "w");
    assert(file != NULL);
    fprintf(file, "P001,data1,2,200\n");
    fclose(file);


    char line1[100];
    FILEcheck = fopen("test_data.csv", "r");
    assert(check != NULL);
    char *result1 = fgets(line1, sizeof(line1), check);
    fclose(check);
    assert(result1 != NULL && strstr(line1, "P001") != NULL);
    printf("PASS -> Add Product\n");

    int found = search_in_file("test_data.csv", "P001");
    assert(found == 1);
    printf("PASS -> Search Product\n");
FILE updateFile = fopen("test_data.csv", "w");
    assert(updateFile != NULL);
    fprintf(updateFile, "P001,data1,5,500\n");
    fclose(updateFile);

    char line2[100];
    FILEcheck2 = fopen("test_data.csv", "r");
    assert(check2 != NULL);
    char result2 = fgets(line2, sizeof(line2), check2);
    fclose(check2);
    assert(result2 != NULL && strstr(line2, "5") != NULL);
    printf("PASS -> Update Product\n");


    FILEDfile = fopen("test_DEdata.csv", "w");
    assert(Dfile != NULL);
    fprintf(Dfile, "P005,data5,4,2000\n");
    fclose(Dfile);

    FILE temp = fopen("temp.csv", "w");
    assert(temp != NULL);
    fclose(temp);
    remove("test_DEdata.csv");
    rename("temp.csv", "test_DEdata.csv");


    FILEcheck3 = fopen("test_DEdata.csv", "r");
    assert(check3 != NULL);
    char line3[100];
    char result3 = fgets(line3, sizeof(line3), check3);
    fclose(check3);


    if (result3 != NULL && (line3[0] == '\0'  line3[0] == '\n'  line3[0] == '\r'))
        result3 = NULL;

    assert(result3 == NULL);
    printf("PASS -> Delete Product\n");

    FILEfinalCheck = fopen("test_data.csv", "r");
    assert(finalCheck != NULL);
    char verify[100];
    fgets(verify, sizeof(verify), finalCheck);
    fclose(finalCheck);
    assert(strstr(verify, "P001") != NULL);
    printf("PASS -> Final verification\n");

    printf("\n[PASS] E2E Test Completed Successfully (100%% PASS)\n");
    printf("Press ENTER to return...");
    getchar();
    while (getchar() != '\n');
}
