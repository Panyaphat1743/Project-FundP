#include <stdio.h>
#include <string.h>

int Buy_data(){

	char Incart[100];
	FILE*file = fopen("data.csv","a");
	int choice;
	int Quantity;
	char next;
	int ans;

	printf("P001 data1 price\n");
	printf("P002 data2 price\n");
	printf("P003 data3 price\n");	
	printf("P004 data4 price\n");
	printf("P005 data5 price\n");
	printf("P006 data6 price\n");
	printf("P007 data7 price\n");
	printf("P008 data8 price\n");
	printf("P009 data9 price\n");
	printf("P010 data10 price\n");
	printf("P011 data11 price\n");
	printf("P012 data12 price\n");
	printf("P013 data13 price\n");
	printf("P014 data14 price\n");
	printf("P015 data15 price\n");
	printf("Want something?: ");
	scanf("%s",&Incart);
	printf("How many? :");
	scanf("%d",&Quantity);
	fprintf(file,"%s,%d\n",Incart,Quantity);
	printf("You want more?\n[1]Yes\n[2]No\n");
	scanf("%d",&choice);

	while(choice == 1){
		printf("And you want:");
		scanf("%s",&Incart);
		printf("How many? :");
		scanf("%d",&Quantity);
		printf("You want more?\n[1]Yes\n[2]No\n");
		scanf("%d",&choice);
		fprintf(file,"%s,%d\n",Incart,Quantity);
	}
	printf("Go back to Menu?(1/0)\n");
	scanf("%d",&choice);
	fclose(file);
	return choice;
}

void update_data(){
	char line[100];
    char name[50];
    int newQty;
    int found = 0;

    printf("Enter product name to update: ");
    scanf("%s", name);

    printf("Enter new quantity: ");
    scanf("%d", &newQty);

    FILE *file = fopen("data.csv", "r");
    FILE *temp = fopen("temp.csv", "w");

    if (!file || !temp) {
        printf("Error opening file!\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        char item[50];
        int qty;

        sscanf(line, "%[^,],%d", item, &qty);

        if (strcmp(item, name) == 0) {
            fprintf(temp, "%s,%d\n", item, newQty);
            found = 1;
        } else {
            fprintf(temp, "%s,%d\n", item, qty);
        }
    }

    fclose(file);
    fclose(temp);

    remove("data.csv");
    rename("temp.csv", "data.csv");

    if (found) {
        printf("Update success!\n");
    } else {
        printf("Product not found!\n");
    }
}

void search(){
	char name[15];
	char Refile[25];
	FILE*file = fopen("data.csv","r");
	printf("Name : ");
	scanf("%s",&name);
	while(fgets(Refile,sizeof(Refile),file) != NULL){
		if(strstr(Refile,name) != NULL){
			printf("You already add in your cart");
		}
	}
	fclose(file);
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
		printf("delete");
		break;

		case 4: //Search
		search();
		break;

		case 0: //Exit
		printf("Thank for Buying\n");
		break;

		default:
		printf("Error!!!! What do you select?");
		break;
		}
	}while(choice != 0);
	printf("Now you exit Go!!!");
}
