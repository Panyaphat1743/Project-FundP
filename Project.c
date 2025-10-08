#include <stdio.h>
#include <string.h>

int Buy_data(){ // ซื้อของ

	char Incart[100];
	char line[100];
	FILE *file = fopen("data.csv", "a");
	FILE *R_file = fopen("data.csv", "r");
	int choice;
	int Quantity;
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
	char ID[10];
	int check;

	printf("P001 data1 100\n");
	printf("P002 data2 200\n");
	printf("P003 data3 300\n");
	printf("P004 data4 400\n");
	printf("P005 data5 500\n");
	printf("P006 data6 600\n");
	printf("P007 data7 700\n");
	printf("P008 data8 800\n");
	printf("P009 data9 900\n");
	printf("P010 data10 1000\n");
	printf("P011 data11 1100\n");
	printf("P012 data12 1200\n");
	printf("P013 data13 1300\n");
	printf("P014 data14 1400\n");
	printf("P015 data15 1500\n");

	printf("Have ID?: ");
	scanf("%s",ID);

	int valid = 0;

	while(!valid){//มีไหม
		int found = 0;
		int Aladd = 0;

		for(int i=0;i<15;i++){
			if(strcmp(ALL_ID[i],ID) == 0){
				found = 1;
				cost = ALL_Price[i];
				strcpy(Incart,ALL_PD[i]);
				break;
			}
		}
		if(!found) {//มีไหม
       		printf("You didnt see my list? Try again: ");
        	scanf("%s",ID);
        	continue;
    	}
		rewind(R_file);
		while(fgets(line,sizeof(line),R_file)){//เคยซื้อไหม
			if(strstr(line,ID) != NULL){
				Aladd = 1;
				break;
			}
		}
		if(Aladd){
			printf("You already add try another: ");
			scanf("%s",ID);
			continue;
		}
		valid = 1;
	}

	printf("How many? :");
	check = scanf("%d", &Quantity);
	while (Quantity <= 0 || check == 0||Quantity>=6000)
	{
		printf("Type only positive integer or you add too much?: ");
		while (getchar() != '\n');
		check = scanf("%d", &Quantity);
	}

	fprintf(file, "%s,%s,%d,%d\n", ID, Incart, Quantity,cost*Quantity);
	printf("You want more?\n[1]Yes\n[2]No\n");
	scanf("%d", &choice);

	while (choice == 1)//;วนถาม
	{
		printf("Have ID?: ");
		scanf("%s",ID);

		int valid = 0;

	while(!valid){//มีไหม
		int found = 0;
		int Aladd = 0;

		for(int i=0;i<15;i++){
			if(strcmp(ALL_ID[i],ID) == 0){
				found = 1;
				cost = ALL_Price[i];
				strcpy(Incart,ALL_PD[i]);
				break;
			}
		}
		if(!found) {//มีไหม
       		printf("You didnt see my list? Try again: ");
        	scanf("%s",ID);
        	continue;
    	}
		rewind(R_file);
		while(fgets(line,sizeof(line),R_file)){//เคยซื้อไหม
			if(strstr(line,ID) != NULL){
				Aladd = 1;
				break;
			}
		}
		if(Aladd){
			printf("You already add try another: ");
			scanf("%s",ID);
			continue;
		}
		valid = 1;
	}

	printf("How many? :");
	check = scanf("%d", &Quantity);
	while (Quantity <= 0 || check == 0)
	{
		printf("Type only positive integer: ");
		while (getchar() != '\n')
			;
		check = scanf("%d", &Quantity);
	}
	fprintf(file, "%s,%s,%d,%d\n", ID, Incart, Quantity,cost*Quantity);
	printf("You want more?\n[1]Yes\n[2]No\n");
	scanf("%d", &choice);
	}
	printf("Go back to Menu?(1/0)\n");
	scanf("%d", &choice);
	fclose(file);
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
	char name[15];
	char Refile[25];
	FILE *file = fopen("data.csv", "r");
	printf("Name : ");
	scanf("%s", &name);
	while (fgets(Refile, sizeof(Refile), file) != NULL)
	{
		if (strstr(Refile, name) != NULL)
		{
			printf("You already add in your cart");
		}
		else
		{
			printf("Hmmmmmmmm YOU NOT ADD :( \n");
			break;
		}
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
