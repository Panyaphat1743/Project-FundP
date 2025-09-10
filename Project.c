#include <stdio.h>



void data(){
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
}
//void update_data()
//void read_csv()

int main(){
	char Incart[100];
	FILE*file = fopen("data.csv","w");
	int next;
	int Quantity;


	printf("--------------------------------------------------\n");
	printf("\t  Welcome to Best Item shop XD\n");
	printf("Let Buy (Press 1)\n");
	printf("Exit (Press 0)\n");
	printf("--------------------------------------------------\n");

	printf("1 or 0?: ");
	scanf("%d",&next);

	while(next == 1){
		data();
		printf("Want something?: ");
		scanf("%s",&Incart);
		printf("How many? ");
		scanf("%d",&Quantity);
		fprintf(file,"%s,%d",Incart,Quantity);
		printf("Want more?(choose 1/0): ");
		scanf("%d",&next);
		//press ... to update_data()
		//press ... to read_csv()
	}

}