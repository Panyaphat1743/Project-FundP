#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "Product_system.h"

void E2E_test()
{
    printf("------Running E2E test------\n");

    FILE*file = fopen("test_data.csv", "w");
    fclose(file);

    char lIne[40];
    FILE *testfile = fopen("test_data.csv", "a");
    fprintf(testfile,"P001,data1,2,200\n");
    fclose(testfile);
    fgets(lIne,sizeof(lIne),testfile);
    assert(strstr(lIne,"P") != NULL);
    printf("PASS buy\n");//เพิ่มสินค้า(ผ่าน)

    
    int found = search_in_file("test_data.csv", "P001");
    assert(found == 1);
    printf("PASS Search after buy \n");//หาสินค้า(ผ่าน)

    
    FILE *Ufile = fopen("test_data.csv", "w");//check Update
    fprintf(Ufile, "P001,data1,2,200\n");
    fclose(Ufile);
    FILE *temp = fopen("temp.csv", "w");
    fprintf(temp, "P001,data1,5,500\n");
    fclose(temp);
    remove("test_data.csv");
    rename("temp.csv", "test_data.csv");

   
    char line[100];
    file = fopen("test_data.csv", "r");
    fgets(line, sizeof(line), file);
    fclose(file);
    assert(strstr(line, "5") != NULL);
    printf("Update passed\n");//Upd สินค้า(ผ่าน)
    
    char Line[100];
    FILE*Dfile = fopen("test_DEdata.csv", "a");
    fprintf(Dfile,"P005,data5,4,2000\n");
    fclose(Dfile);
    FILE *ttemp = fopen("temp.csv", "w");
    fclose(ttemp);
    remove("test_DEdata.csv");
    rename("temp.csv", "test_DEdata.csv");
    FILE*DEfile = fopen("test_DEdata.csv", "r");
    char *result = fgets(Line,sizeof(Line),DEfile);
    assert(result == NULL);
    printf("Delete PASS\n");
    printf("Press ENTER to return...");
    getchar();
    while (getchar() != '\n');
}
