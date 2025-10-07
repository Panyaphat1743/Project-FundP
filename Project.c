#include <stdio.h>
#include <string.h>

int Buy_data(){ //ซื้อของ

	char Incart[100];
	char line[25];
	FILE*file = fopen("data.csv","a");
	FILE*R_file = fopen("data.csv","r");
	int choice;
	int Quantity;
	char next;
	char ALL_ID[] = "P001P002P003P004P005P006P007P008P009P0010P011P012P013P014P015";
	char ALL_PD[] = "data1data2data3data4data5data6data7data8data9data10data11data12data13data14data15";
	char ID[10];
	int check;

	printf("P001 data1 price1\n");
	printf("P002 data2 price2\n");
	printf("P003 data3 price3\n");
	printf("P004 data4 price4\n");
	printf("P005 data5 price5\n");
	printf("P006 data6 price6\n");
	printf("P007 data7 price7\n");
	printf("P008 data8 price8\n");
	printf("P009 data9 price9\n");
	printf("P010 data10 price10\n");
	printf("P011 data11 price11\n");
	printf("P012 data12 price12\n");
	printf("P013 data13 price13\n");
	printf("P014 data14 price14\n");
	printf("P015 data15 price15\n");
	printf("have ID?: ");
	scanf("%s",&ID);
	while(fgets(line,sizeof(line),R_file)){//check ว่ามียัง
		while(strstr(line,ID) != NULL){
			printf("You already add try another: ");
			scanf("%s",&ID);
		}
	}

	fclose(R_file);

	if(ID[0] == 'p'){
		ID[0] = ID[0] - 32;
	}

	while(strstr(ALL_ID,ID) == NULL || ID[0] != 'P' || strlen(ID) != 4){
		printf("You didnt see my list?\n");
		printf("Type new ID: ");
		scanf("%s",&ID);
		R_file = fopen("data.csv","r");
		while(fgets(line,sizeof(line),R_file)){
			while(strstr(line,ID) != NULL){
				printf("You already add try another: ");
				scanf("%s",&ID);
				fclose(R_file);
				R_file = fopen("data.csv","r");
	}
		}
	}
	printf("Name: ");
	scanf("%s",&Incart);
	while(strstr(ALL_PD,Incart) == NULL || Incart[0] != 'd' || strlen(Incart) < 5 || Incart[5] == 'd'){
		printf("Open your eye and see again\n");
		printf("Type new Name: ");
		scanf("%s",&Incart);
	}

	printf("How many? :");
	check = scanf("%d",&Quantity);
	while(Quantity <= 0 || check == 0){
		printf("Type only positive integer: ");
		while(getchar() != '\n');
		check = scanf("%d",&Quantity);
	}
	fprintf(file,"%s,%s,%d\n",ID,Incart,Quantity);
	printf("You want more?\n[1]Yes\n[2]No\n");
	scanf("%d",&choice);

	while(choice == 1){
		printf("have ID?: ");
	scanf("%s",&ID);
	while(fgets(line,sizeof(line),R_file)){//check ว่ามียัง
		while(strstr(line,ID) != NULL){
			printf("You already add try another: ");
			scanf("%s",&ID);
		}
	}

	fclose(R_file);

	if(ID[0] == 'p'){
		ID[0] = ID[0] - 32;
	}

	while(strstr(ALL_ID,ID) == NULL || ID[0] != 'P' || strlen(ID) != 4){
		printf("You didnt see my list?\n");
		printf("Type new ID: ");
		scanf("%s",&ID);
		R_file = fopen("data.csv","r");
		while(fgets(line,sizeof(line),R_file)){
			while(strstr(line,ID) != NULL){
				printf("You already add try another: ");
				scanf("%s",&ID);
				fclose(R_file);
				R_file = fopen("data.csv","r");
	}
		}
	}
		printf("Name: ");
	scanf("%s",&Incart);
	while(strstr(ALL_PD,Incart) == NULL || Incart[0] != 'd' || strlen(Incart) < 5 || Incart[5] == 'd'){
		printf("Open your eye and see again\n");
		printf("Type new Name: ");
		scanf("%s",&Incart);
	}
		printf("How many? :");
	check = scanf("%d",&Quantity);
	while(Quantity <= 0 || check == 0){
		printf("Type only positive integer: ");
		while(getchar() != '\n');
		check = scanf("%d",&Quantity);
	}
		printf("You want more?\n[1]Yes\n[2]No\n");
		fprintf(file,"%s,%s,%d,\n",ID,Incart,Quantity);
		scanf("%d",&choice);
	}
	printf("Go back to Menu?(1/0)\n");
	scanf("%d",&choice);
	fclose(file);
	return choice;
}

void update_data(){ // เปลี่ยนจำนวนสินค้าที่ซื้อ
	char line[100];
    char name[50];
    int newQty;
    int found = 0;
	char ID[10];

	printf("Enter product ID to update: ");
    scanf("%s", ID);

    printf("Enter product name to update: ");
    scanf("%s", name);

    printf("Enter new quantity: ");
    scanf("%d", &newQty);

    FILE *file = fopen("data.csv", "r");
    FILE *temp = fopen("temp.csv", "w");

    if (file == NULL || temp == NULL) {/////////////////////////////////////////////แก้
        printf("Error opening file!\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        char item[50];
		char ID [10];
        int qty;

        sscanf(line, "%[^,],%[^,],%d",&ID ,&item, &qty);

        if (strcmp(item, name) == 0) {
            fprintf(temp, "%s,%s,%d\n",ID, item, newQty);
        } else {
            fprintf(temp, "%s,%s,%d\n", ID, item, qty);
        }
    }

    fclose(file);
    fclose(temp);

    remove("data.csv");
    rename("temp.csv", "data.csv");
}

void search(){ //ค้นหา//////////////////////////////////////////////////////////////////////////////////แก้(P,p)
	char name[15];
	char Refile[25];
	FILE*file = fopen("data.csv","r");
	printf("Name : ");
	scanf("%s",&name);
	while(fgets(Refile,sizeof(Refile),file) != NULL){
		if(strstr(Refile,name) != NULL){
			printf("You already add in your cart");
		}else{
			printf("Hmmmmmmmm YOU NOT ADD :( \n");
			break;
		}

	}
	fclose(file);
}

void Delete(){

	char line[40];
	char DeleteID[10];
	char ID[10];
	char name[10];
	int Q;

	printf("ID: ");
	scanf("%s",DeleteID);
	FILE *file = fopen("data.csv","r");
	FILE *temp = fopen("temp.csv", "w");
	while(fgets(line,sizeof(line),file) != NULL){
		sscanf(line, "%[^,],%[^,],%d" ,&ID,&name,&Q);
		if(strcmp(DeleteID,ID) != 0){
			fprintf(temp,"%s,%s,%d",ID,name,Q);
		}
	}

	fclose(file);
    fclose(temp);

    remove("data.csv");
    rename("temp.csv", "data.csv");

}

int main(){

	int choice;
do{

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
	scanf("%d",&choice);

	switch(choice){
		case 1: //buy
		choice = Buy_data();
		break;

		case 2: //Update
		update_data();
		break;

		case 3: //Delete
		Delete();
		break;

		case 4: //Search
		search();
		break;

		case 0: //Exit
		printf("Thank for Buying\n");
		break;

		default:
		printf("Error!!!! What do you select?\n");
		break;
		}
	}while(choice != 0);
	printf("Now you exit Go!!!");
}
