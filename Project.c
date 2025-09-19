#include <stdio.h>

void Buy_data(){

	char Incart[100];
	FILE*file = fopen("data.csv","a");
	int choice;
	int Quantity;
	char next;
	
	printf("data1 price\n");
	printf("data2 price\n");
	printf("data3 price\n");	
	printf("data4 price\n");
	printf("data5 price\n");
	printf("data6 price\n");
	printf("data7 price\n");
	printf("data8 price\n");
	printf("data9 price\n");
	printf("data10 price\n");
	printf("data11 price\n");
	printf("data12 price\n");
	printf("data13 price\n");
	printf("data14 price\n");
	printf("data15 price\n");
	printf("Want something?: ");
	scanf("%s",&Incart);
	printf("How many? :");
	scanf("%d",&Quantity);
	printf("You want more?\n[1]Yes\n[2]No\n");
	scanf("%d",&choice);

	while(choice == 1){
		printf("And you want:");
		scanf("%s",&Incart);
		printf("How many? :");
		scanf("%d",&Quantity);
		printf("You want more?\n[1]Yes\n[2]No\n");
		scanf("%d",&choice);
	}
}
//void update_data()
//void read_csv()

int main(){

	int choice;
	printf("--------------------------------------------------\n");
	printf("\t  Welcome to Best Item shop XD\n");
	printf("choose your choice\n");
	printf("(1)Let Buy\n");
	printf("(2)Update\n");
	printf("(3)Delete\n");
	printf("(4)Search\n");
	printf("(5)Exit\n");
	printf("--------------------------------------------------\n");

	printf("Choose: ");
	scanf("%d",&choice);

	switch(choice){
		case 1: //buy
		Buy_data();
		break;

		case 2: //Update
		printf("Update");
		break;

		case 3: //Delete
		printf("delete");
		break;

		case 4: //Search
		
		break;

		case 5: //Exit
		printf("Thank for Buying");
		break;

		default:
		printf("Error!!!! What do you select?");
		break;
	}
}
