#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef union{
	bool hasPhone;
	char phNo[12];
}telephone_t;

typedef struct{
	 int iDNo;
	 char st_name[20];
	 char city[20];
	 int iPIN;
	 telephone_t ph;
	 
}address_t;

int main()
{
	address_t addr1,addr2;
	char option;
	printf("\nEnter the first address :\t ");
	printf("\nDoor No  :\t");
	scanf("%d",&addr1.iDNo);
	printf("\nEnter the street name :\t ");
	scanf("%s",addr1.st_name);
	printf("\nEnter city name :\t");
	scanf("%s",addr1.city);
	printf("\nEnter PIN : ");
	scanf("%d",&addr1.iPIN);
	
	getchar();
	printf("\nPhone (Y/N)\t");
	scanf("%c",&option);
	if(option=='y'||option=='Y')
	{
		printf("\nEnter phone no \t");
		scanf("%s",addr1.ph.phNo);
	}
	else 
	{
		addr1.ph.hasPhone=false;
	}
	
	
	printf("\nAddress details:\n");
	printf("\nDoor No    :\t%d",addr1.iDNo);
	printf("\nSteet Name :\t%s",addr1.st_name);
	printf("\nCity Name  :\t%s",addr1.city);
	printf("\nPIN        :\t%d",addr1.iPIN);
	if(addr1.ph.hasPhone!=false)
		printf("\nPhone no :\t%s",addr1.ph.phNo);
		
	printf("\n");
	
	return 0;
}
