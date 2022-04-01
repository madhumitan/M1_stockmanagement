#include<stdio.h>
#include<string.h>
#include "Storeitem.h"
//#include<conio.h>



char filename[] ="./storeitem.dat"; //binary file
char filename1[] ="./tempitem.dat";



int main()
{
	Menu();
	WriteRecord();
	ListRecords();
	delete();
	return 0;

}
