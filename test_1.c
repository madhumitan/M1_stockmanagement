/*
 * test_1.c
 *
 *  Created on: 16 Mar 2022
 *      Author: madhu
 */
#include<stdio.h>
#include<string.h>
#include<conio.h>
typedef struct storeitem{
	int itemcode;
	char itemname[31];
}Storeitem;


char filename[] ="./storeitem.dat"; //binary file
void Menu();
void WriteRecord();
void ListRecords();
int main()
{
	Menu();
	WriteRecord();
	ListRecords();
	return 0;
}

void WriteRecord()
{
		FILE *f;
		Storeitem item;

		//item.itemcode=1;
		//strcpy(item.itemname ,"Pencil");
		printf("\nEnter Item Code : ");
		scanf("%d",&item.itemcode);
		gets(item.itemname);

		//append
		f = fopen(filename,"ab");

		//write content
		fwrite(&item,sizeof(Storeitem),1,f);
		fclose(f);
}


void Menu(){

	int opt;



	while(1){
		//clrscr();
		//enter in loop
				printf("\n1.Add Item");
				printf("\n2.List Items");
				printf("\n3. Exit");
				printf("\n\nEnter your Choice (1-3): ");
				scanf("%d",&opt);
		//fflush to remove \n in i/p
		//fflush(stdin);

		switch(opt){
		case 1:
			printf("\n Add Items");
			break;
		case 2:
			printf("\n List Items");
			break;
		case 3:
			return;
			break;
		default:
			printf("\nInvalid option selected");
			break;
		}
		printf("\nPress a key to continue...");
		//getch();
	}
}

void ListRecords()
{

		FILE *f;
		Storeitem item;

		item.itemcode=1;
		strcpy(item.itemname ,"Pencil");
		f = fopen(filename,"rb");

		//read content
		fread(&item,sizeof(Storeitem),1,f);
		fclose(f);

		//display

		printf("\nItem code : %d",item.itemcode);
		printf("\nItem name : %s",item.itemname);

}
