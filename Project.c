#include <stdio.h>
#include <string.h>

int Buy_data(){

	char Incart[100];
	FILE*file = fopen("data.csv","a");
	int choice;
	int Quantity;
	char next;
	int ans;

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
	scanf("%d",&ans);
	fclose(file);
	return ans;
}
//void read_csv()
void update_data(){
	char Refile[25];
	FILE*file = fopen("data.csv","r");
	while(fgets(Refile,sizeof(Refile),file) != NULL){
		printf("%s",Refile);
	}
	fclose(file);
}
//void delete()

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

	int ans = 0;
	int choice;
do{

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
		update_data();
		break;

		case 3: //Delete
		printf("delete");
		break;

		case 4: //Search
		search();
		break;

		case 5: //Exit
		printf("Thank for Buying\n");
		break;

		default:
		printf("Error!!!! What do you select?");
		break;
		}
	}while(ans != 0);
	printf("Now you exit Go!!!");
}
