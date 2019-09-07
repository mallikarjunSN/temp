/*************Documentation section******************/
/*Name of program:                 */
/*Author:          */
/*date:             */
/*Class:          */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint;

typedef struct{
	uint iD;
	char cName[25];
	char cDept[25];
	uint iSal;
	uint iAge;
}employee_t;

void fnDisplayRecord(void);
void fnAddRecord(void);
void fnSearchiD(int);
void fnSearchDept(char *);
void fnSearchSal(int);
void fnSearchAge(int);

int main()
{
	int id,sal,age,iChoice;
	char dept[25];
	employee_t emp;
	
/*	FILE *fp;*/
/*	*/
/*	fp=fopen("emp.dat","r+");*/
/*	if(fp==NULL)*/
/*	{*/
/*		printf("\nFailed to create file\n");*/
/*		exit(100);*/
/*	}*/
	
	for(;;)
	{
		printf("\nPlease Enter your choice\n");
		printf("\n1.Add record\n2.Display all the records\n3.Search by ID\n4.Search by Dept\n5.Search by salary\n6.Search by age\n7.Exit\n");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:fnAddRecord();
					break;
			
			case 2:fnDisplayRecord();
					break;
			
			case 3:printf("\nPlease enter the employee ID you want to search\n");
					scanf("%d",&emp.iD);
					fnSearchiD(emp.iD);
					break;
			case 4:printf("\nPlease enter the employee dept you want to search\n");
					scanf("%s",emp.cDept);
					fnSearchDept(emp.cDept);
					break;
			case 5:printf("\nPlease enter the employee salary you want to search\n");
					scanf("%d",&emp.iSal);
					fnSearchSal(emp.iSal);
					break;
			case 6:printf("\nPlease enter the employee age you want to search\n");
					scanf("%d",&emp.iAge);
					fnSearchAge(emp.iAge);
					break;
			case 7:exit(0);
					break;
		}
	
	}
	return 0;

}

void fnAddRecord(void)
{
	FILE *fp;
	employee_t emp;
	
	fp=fopen("emp.dat","a");
	if(fp==NULL)
	{
		printf("\nFailed to append file\n");
		exit(100);
	}
	
	printf("\nEnter Employee details\n");
	printf("\nID :\t");
	scanf("%d",&emp.iD);
	getchar();
	printf("\nName :\t");
	gets(emp.cName);
	printf("\nDept :\t");
	gets(emp.cDept);
	printf("\nSalary :\t");
	scanf("%d",&emp.iSal);
	printf("\nAge :\t");
	scanf("%d",&emp.iAge);
	
	fprintf(fp,"%d\t%s\t%s\t%d\t%d\n",emp.iD,emp.cName,emp.cDept,emp.iSal,emp.iAge);	
	fclose(fp);
	return;
}

void fnDisplayRecord(void)
{
	int iCount=0;
	FILE *fp;
	
	employee_t emp;
	
	fp=fopen("emp.dat","r");
	if(fp==NULL)
	{
		printf("\nFailed to open file\n");
		exit(0);
	}
	printf("\nID\tName\tDept\tSalary\tAge\n");
	getchar();
	while(fscanf(fp,"%d%s%s%d%d",&emp.iD,emp.cName,emp.cDept,&emp.iSal,&emp.iAge)!=EOF)
	{
		printf("%d\t%s\t%s\t%d\t%d\n",emp.iD,emp.cName,emp.cDept,emp.iSal,emp.iAge);
		iCount++;
	}
	
	if(iCount==0)
		printf("\nNo Records found\n");
	fclose(fp);	
	return;
}

void fnSearchDept(char dept[25])
{
	int iCount=0;
	FILE *fp;
	
	employee_t emp;
	
	fp=fopen("emp.dat","r");
	if(fp==NULL)
	{
		printf("\nFailed to open file\n");
		exit(0);
	}
	printf("\nID\tName\tDept\tSalary\tAge\n");
	

		while(fscanf(fp,"%d%s%s%d%d",&emp.iD,emp.cName,emp.cDept,&emp.iSal,&emp.iAge)!=EOF)
		{
			if(!strcmp(emp.cDept,dept))
			{
				printf("%d\t%s\t%s\t%d\t%d\n",emp.iD,emp.cName,emp.cDept,emp.iSal,emp.iAge);
				iCount++;
			}
		}
	if(iCount==0)
		printf("\nNo Records found\n");
	
	fclose(fp);
	return;
	
}

void fnSearchiD(int id)
{
	int iCount=0;
	FILE *fp;
	
	employee_t emp;
	
	fp=fopen("emp.dat","r");
	if(fp==NULL)
	{
		printf("\nFailed to open file\n");
		exit(0);
	}
	printf("\nID\tName\tDept\tSalary\tAge\n");
	
		while(fscanf(fp,"%d%s%s%d%d",&emp.iD,emp.cName,emp.cDept,&emp.iSal,&emp.iAge)!=EOF)
		{
			if(emp.iD==id)
			{
				printf("%d\t%s\t%s\t%d\t%d\n",emp.iD,emp.cName,emp.cDept,emp.iSal,emp.iAge);
				iCount++;
			}		
		}
	if(iCount==0)
		printf("\nNo Records found\n");
		
	fclose(fp);
		
	return;
	
}

void fnSearchSal(int sal)
{
	int iCount=0;
	FILE *fp;
	
	employee_t emp;
	
	fp=fopen("emp.dat","r");
	if(fp==NULL)
	{
		printf("\nFailed to open file\n");
		exit(0);
	}
	printf("\nID\tName\tDept\tSalary\tAge\n");
	
		while(fscanf(fp,"%d%s%s%d%d",&emp.iD,emp.cName,emp.cDept,&emp.iSal,&emp.iAge)!=EOF)
		{
			if(emp.iSal==sal)
			{
				printf("%d\t%s\t%s\t%d\t%d\n",emp.iD,emp.cName,emp.cDept,emp.iSal,emp.iAge);
				iCount++;
			}		
		}
	if(iCount==0)
		printf("\nNo Records found\n");
		
	fclose(fp);
		
	return;
}

void fnSearchAge(int age)
{
	int iCount=0;
	FILE *fp;
	
	employee_t emp;
	
	fp=fopen("emp.dat","r");
	if(fp==NULL)
	{
		printf("\nFailed to open file\n");
		exit(0);
	}
	printf("\nID\tName\tDept\tSalary\tAge\n");
	
		while(fscanf(fp,"%d%s%s%d%d",&emp.iD,emp.cName,emp.cDept,&emp.iSal,&emp.iAge)!=EOF)
		{
			if(emp.iAge==age)
			{
				printf("%d\t%s\t%s\t%d\t%d\n",emp.iD,emp.cName,emp.cDept,emp.iSal,emp.iAge);
				iCount++;
			}		
		}
	if(iCount==0)
		printf("\nNo Records found\n");
		
	fclose(fp);
		
	return;
	
}

