#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Product_system.h"

void test_find_product_index(){
    assert(find_product_index("P001") == 0);
    printf("PASS test_P001\n");
    assert(find_product_index("P002") == 1);
    printf("PASS test_P002\n");
    assert(find_product_index("P008") == 7);
    printf("PASS test_P008\n");
    assert(find_product_index("P015") == 14);
    printf("PASS test_P015\n");
    assert(find_product_index("P000") == -1);
    printf("PASS test_P000\n");
    assert(find_product_index("/P001") == -1);
    printf("PASS test_/P001\n");
    assert(find_product_index("@") == -1);
    printf("PASS test_@\n");
    assert(find_product_index("p001") == 0);
    printf("PASS test_p001\n\n");
}

void test_already_added(){
    FILE *R_file = fopen("data.csv", "r");
    assert(already_added(R_file,"P001") == 1);
    printf("PASS test_ID_P001\n");
    assert(already_added(R_file,"P009") == 1);
    printf("PASS test_ID_P009\n");
    assert(already_added(R_file,"P015") == 1);
    printf("PASS test_ID_P015\n");
    assert(already_added(R_file,"P025") == 0);
    printf("PASS test_ID_P025\n");
    assert(already_added(R_file,"P005") == 0);
    printf("PASS test_ID_P005\n");
}

void test_search_in_file(){

    FILE*file = fopen("test_data.csv","w");
    fprintf(file,"P001,data1,1,100\n");
    fclose(file);
    
    assert(search_in_file("test_data.csv","P001") == 1);
    printf("PASS test_P001 have and in file\n");
    assert(search_in_file("test_data.csv","P000") == 0);
    printf("PASS test_P000 have file but not in file\n");
    assert(search_in_file("no_data.csv","P001") == -1);
    printf("PASS test_P001 with no file\n");
    printf("Press ENTER to return...");
    getchar();
    while (getchar() != '\n');
}

void run(){
    printf("-------------TEST BUY_DATA-------------\n");
    test_find_product_index();
    test_already_added();
    printf("-------------TEST SEARCH-------------\n");
    test_search_in_file();
}