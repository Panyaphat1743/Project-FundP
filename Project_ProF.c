#include <stdio.h>
#include <string.h>
#include "Product_system.h"

#define PRODUCT_COUNT 15

char *ALL_ID[] = {
    "P001", "P002", "P003", "P004", "P005",
    "P006", "P007", "P008", "P009", "P010",
    "P011", "P012", "P013", "P014", "P015"};

char *ALL_PD[] = {
    "data1", "data2", "data3", "data4", "data5",
    "data6", "data7", "data8", "data9", "data10",
    "data11", "data12", "data13", "data14", "data15"};

int ALL_Price[] = {
    100, 200, 300, 400, 500,
    600, 700, 800, 900, 1000,
    1100, 1200, 1300, 1400, 1500};


void show_product_list() {
    printf("Available products:\n");
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        printf("%s %s %d\n", ALL_ID[i], ALL_PD[i], ALL_Price[i]);
    }
}

int find_product_index(const char *id) {
    char temp[10];
    strcpy(temp, id);

    if (temp[0] == 'p') {
        temp[0] = temp[0] - 32;
    }

    for (int i = 0; i < PRODUCT_COUNT; i++) {
        if (strcmp(ALL_ID[i], temp) == 0) {
            return i;
        }
    }
    return -1;
}


int already_added(FILE *file, const char *id) {
    char line[100];
    rewind(file);
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, id) != NULL) {
            return 1;
        }
    }
    return 0;
}

int get_quantity() {//จำนวน
    int q, check;
    printf("How many?: ");
    check = scanf("%d", &q);
    while (q <= 0 || check == 0 || q >= 6000) {
        printf("Type only positive integer or too much?: ");
        while (getchar() != '\n');
        return -1;
        check = scanf("%d", &q);
    }
    return q;
}

void write_to_file(FILE *file, const char *id, const char *name, int quantity, int total_cost) {
    fprintf(file, "%s,%s,%d,%d\n", id, name, quantity, total_cost);
}

int Buy_data() {//ซื้อ
    FILE *file = fopen("data.csv", "a");
    FILE *R_file = fopen("data.csv", "r");
    if (!file || !R_file) {
        printf("Error opening file.\n");
        return 0;
    }

    show_product_list();

    char ID[10];
    char Incart[100];
    int Quantity, cost, choice = 1;

    while (choice == 1) {
        printf("Have ID?: ");
        scanf("%s", ID);
        if (ID[0] == 'p'){
        ID[0] = ID[0]-32;
    }

        int valid = 0;
        while (!valid) {
            int found_index = find_product_index(ID);
            if (found_index == -1) {
                printf("You didnt see my list? Try again: ");
                scanf("%s", ID);
                continue;
            }

            if (already_added(R_file, ID)) {
                printf("You already add try another: ");
                scanf("%s", ID);
                continue;
            }

            strcpy(Incart, ALL_PD[found_index]);
            cost = ALL_Price[found_index];
            valid = 1;
        }

        Quantity = get_quantity();
        write_to_file(file, ID, Incart, Quantity, cost * Quantity);

        printf("You want more?\n[1]Yes\n[2]No\n");
        scanf("%d", &choice);
    }

    printf("Go back to Menu?(1/0)\n");
    scanf("%d", &choice);

    fclose(file);
    fclose(R_file);
    return choice;
}


void update_data(){ // เปลี่ยนจำนวนสินค้าที่ซื้อ

	char line[100];
	char name[50];
	int newQty;
	int found = 0;
	char IDU[10];
	int cost;

	char *ALL_ID[] = {
		"P001", "P002", "P003", "P004", "P005",
		"P006", "P007", "P008", "P009", "P010",
		"P011", "P012", "P013", "P014", "P015"};
	char *ALL_PD[] = {
		"data1", "data2", "data3", "data4", "data5",
		"data6", "data7", "data8", "data9", "data10",
		"data11", "data12", "data13", "data14", "data15"};
	int ALL_Price[] = {
		100, 200, 300, 400, 500,
		600, 700, 800, 900, 1000,
		1100, 1200, 1300, 1400, 1500};

	printf("Enter product ID to update: ");
	scanf("%s", IDU);

	printf("Enter new quantity: ");
	scanf("%d", &newQty);

	for(int i=0;i<15;i++){
		if(strcmp(ALL_ID[i],IDU) == 0){
			strcpy(name,ALL_PD[i]);
			cost = ALL_Price[i];
		}
	}

	FILE *file = fopen("data.csv", "r");
	FILE *temp = fopen("temp.csv", "w");

	if (file == NULL || temp == NULL)
	{ /////////////////////////////////////////////แก้
		printf("Error opening file!\n");
		return;
	}

	while (fgets(line, sizeof(line), file))
	{
		char item[50];
		char ID[10];
		int qty;
		int fcost;

		sscanf(line, "%[^,],%[^,],%d,%d", &ID, &item, &qty,&fcost);

		if (strcmp(item, name) == 0)
		{
			fprintf(temp, "%s,%s,%d,%d\n", IDU, name, newQty,cost*newQty);
		}
		else
		{
			fprintf(temp, "%s,%s,%d,%d\n", ID, item, qty,fcost);
		}
	}

	fclose(file);
	fclose(temp);

	remove("data.csv");
	rename("temp.csv", "data.csv");
}

void search()
{ // ค้นหา//////////////////////////////////////////////////////////////////////////////////แก้(P,p)
	char name[50];
	char Refile[50];
	int found;
	FILE *file = fopen("data.csv", "r");
	printf("Name : ");
	scanf("%s", &name);
	while (fgets(Refile, sizeof(Refile), file) != NULL)
	{
		found = 0;
		if (strstr(Refile, name) != NULL)
		{
			printf("You already add in your cart\n");
			found = 1;
			break;
		}
	}
	if(found == 0){
		printf("You not add yet\n");
	}

	fclose(file);
}

void Delete()
{

	char line[40];
	char DeleteID[10];
	char ID[10];
	char name[10];
	int Q;
	int cost;

	printf("ID: ");
	scanf("%s", DeleteID);
	FILE *file = fopen("data.csv", "r");
	FILE *temp = fopen("temp.csv", "w");
	while (fgets(line, sizeof(line), file) != NULL)
	{
		sscanf(line, "%[^,],%[^,],%d,%d", &ID, &name, &Q,&cost);
		if (strcmp(DeleteID, ID) != 0)
		{
			fprintf(temp, "%s,%s,%d,%d\n", ID, name, Q,cost);
		}
	}

	fclose(file);
	fclose(temp);

	remove("data.csv");
	rename("temp.csv", "data.csv");
}

int main()
{

	int choice;
	do
	{

		printf("--------------------------------------------------\n");
		printf("\t  Welcome to Best Item shop XD\n");
		printf("choose your choice\n");
		printf("(1)Let Buy\n");
		printf("(2)Update\n");
		printf("(3)Delete\n");
		printf("(4)Search\n");
        printf("(5)Unit test\n");
        printf("(6)E2E test\n");
		printf("(0)Exit\n");
		printf("--------------------------------------------------\n");

		printf("Choose: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1: // buy
			choice = Buy_data();
			break;

		case 2: // Update
			update_data();
			break;

		case 3: // Delete
			Delete();
			break;

		case 4: // Search
			search();
			break;

		case 5: // Unit test
			run();
			break;

		case 6: // E2E test
			printf("E2E");
			break;

		case 0: // Exit
			printf("Thank for Buying\n");
			break;

		default:
			printf("Error!!!! What do you select?\n");
			break;
		}
	} while (choice != 0);
	printf("Now you exit Go!!!");
}
