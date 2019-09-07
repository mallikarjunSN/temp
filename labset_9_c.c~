#include<stdio.h>
#include<stdlib.h>
#include <math.h>

struct polynomial 
{
	int coef;
	int expo;
	struct polynomial *link;
};

typedef struct polynomial* NODEPTR;

NODEPTR fnInsertRear(NODEPTR,int,int);
NODEPTR fnGetNode();
void fnFreeNode(NODEPTR);
void fnDisplay(NODEPTR);
NODEPTR fnAddPoly(NODEPTR,NODEPTR);
int fnEvalPoly(NODEPTR,int);


int main()
{
	NODEPTR poly1,poly2,poly3;
	poly1=poly2=poly3=NULL;
	int iDegree,i,iX,iRes,iaCoeff[10];
	
	printf("\nEnter the degree of polynomial 1\n");
	scanf("%d",&iDegree);
	printf("\nEnter the coeffients of polynomial 1\n");
	for(i=iDegree;i>=0;i--)
	{
		scanf("%d",&iaCoeff[i]);
		poly1=fnInsertRear(poly1,i,iaCoeff[i]);
	}
	
	printf("\nEnter the degree of polynomial 2\n");
	scanf("%d",&iDegree);
	printf("\nEnter the coeffients of polynomial 2\n");
	for(i=iDegree;i>=0;i--)
	{
		scanf("%d",&iaCoeff[i]);
		poly2=fnInsertRear(poly2,i,iaCoeff[i]);
	}
	poly3=fnAddPoly(poly1,poly2);
	
	printf("\npolynomial 1\n");
	fnDisplay(poly1);
	printf("\npolynomial 2\n");
	fnDisplay(poly2);
	printf("\npolynomial sum\n");
	fnDisplay(poly3);
	
	printf("\nEnter the value of x\n");
	scanf("%d",&iX);
	iRes=fnEvalPoly(poly3,iX);
	
	printf("\nThe value of polynomial for x=%d is %d\n",iX,iRes);
	
	return 0;	
} 

NODEPTR fnInsertRear(NODEPTR first,int expo,int coef)
{
	NODEPTR temp;
	NODEPTR cur;
	
	temp=fnGetNode();
	temp->expo=expo;
	temp->coef=coef;
	temp->link=NULL;
	if(first==NULL)
	{
		first=temp;
		return first;
	}
	cur=first;
	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	if(cur->link==NULL)
	{
		cur->link=temp;
		return first;
	}
	return first;
}

NODEPTR fnAddPoly(NODEPTR poly1,NODEPTR poly2)
{
	NODEPTR tracker1,tracker2,poly3=NULL;
	tracker1=poly1;
	tracker2=poly2;
	while((tracker1!=NULL)&&(tracker2!=NULL))
	{
		if(tracker1->expo>tracker2->expo)
		{
			poly3=fnInsertRear(poly3,tracker1->expo,tracker1->coef);
			tracker1=tracker1->link;
		}
		else if(tracker1->expo==tracker2->expo)
		{
			poly3=fnInsertRear(poly3,tracker1->expo,((tracker1->coef)+(tracker2->coef)));
			tracker1=tracker1->link;
			tracker2=tracker2->link;
		}
		else
		{
			poly3=fnInsertRear(poly3,tracker2->expo,tracker2->coef);
			tracker2=tracker2->link;
		}
	}
	return poly3;
}
int fnEvalPoly(NODEPTR list,int x)
{
	int iSum=0;
	NODEPTR cur=list;
	
	while(cur!=NULL)
	{
		iSum+=(cur->coef*(int)pow(x,cur->expo));
		cur=cur->link;
	}
	return iSum;
}
NODEPTR fnGetNode()
{
	NODEPTR newNode;
	
	newNode=(NODEPTR)malloc(sizeof(struct polynomial));
	
	if(newNode==NULL)
	{
		printf("\nFailed to allocate heap memory\n");
		return NULL;
	}
	return newNode;
}

void fnFreeNode(NODEPTR node)
{
	free(node);
}

void fnDisplay(NODEPTR first)
{
	NODEPTR cur;
	if(first==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	for(cur=first;cur->link!=NULL;cur=cur->link)
	{
		printf("%dx^%d + ",cur->coef,cur->expo);
	}
	printf("%dx^%d\n",cur->coef,cur->expo);
	return;	
}

