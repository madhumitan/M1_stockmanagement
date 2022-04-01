#include "main.c"
void WriteRecord()
{
		FILE *f;
		Storeitem item;

		//item.itemcode=1;
		//strcpy(item.itemname ,"Pencil");
		printf("\nEnter Item Code : ");
		scanf("%d",&item.itemcode);
		printf("enter item name:");
		fflush(stdin);
		scanf("%[^\n]s",item.itemname);
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
				printf("\n3. Delete Item");
				printf("\n4. exit");
				printf("\n\nEnter your Choice (1-3): ");
				scanf("%d",&opt);
		//fflush to remove \n in i/p
		//fflush(stdin);

		switch(opt){
		case 1:
			WriteRecord();
			break;
		case 2:
			ListRecords();
			break;
		case 3:
			delete();
			break;			
			
		case 4:
			exit(0);
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

		
		printf("\n-------------------------------------------\n"); 
		printf("Item_code \t Item_Name");
		printf("\n-------------------------------------------\n"); 
		//read content
		while(fread(&item,sizeof(Storeitem),1,f))
		{
			
			printf("\n%3d \t\t %-30s",item.itemcode,item.itemname);
		

		}
		printf("\n-------------------------------------------\n");
		fclose(f);



}

void delete()
{
	Storeitem item;
	FILE *f, *f1;
	
	f = fopen(filename,"rb");
	f1 = fopen(filename1,"wb");
	int j,itemcode,found = 0;
	printf("Enter itemcode to delete");
	scanf("%d",&itemcode);
	while(fread(&item,sizeof(Storeitem),1,f))
	{
		if(item.itemcode == itemcode)
		{
			found =1;
		}
		else
		    fwrite(&item,sizeof(Storeitem),1,f1); //write in temp file
	}
	fclose(f);
		fclose(f1);
	
	if(found){ //if found replace original file with temp file
			f1 = fopen(filename1,"rb");
			f = fopen(filename,"wb");
			while(fread(&item,sizeof(Storeitem),1,f1))
			{
				fwrite(&item,sizeof(Storeitem),1,f);
			}
			fclose(f);
			fclose(f1);
		}
}
			
	
 


