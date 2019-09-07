#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int info;
	struct node *llink,*rlink;
};

typedef struct node* NODEPTR;

NODEPTR fnInsertFront(NODEPTR,int);
NODEPTR fnDeleteFront(NODEPTR);
NODEPTR fnInsertRear(NODEPTR,int);
NODEPTR fnDeleteRear(NODEPTR);
NODEPTR fnGetNode();
void fnFreeNode(NODEPTR);
void fnDisplay(NODEPTR);

int main()
{
	NODEPTR first;
	first=NULL;
	
	int iElem,iPos,iChoice;
	
	for(;;)
	{
		printf("\n1.Insert Rear\n2.Delete Front\n3.Insert Front\n4.Delete Rear\n5.Display\n6.Exit\n");
		printf("\nEnter your choice\t");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:printf("\nEnter the element to insert\n");
					scanf("%d",&iElem);
					first=fnInsertRear(first,iElem);
					break;
			case 2:first=fnDeleteFront(first);
					break;
			case 3:printf("\nEnter the element to insert\n");
					scanf("%d",&iElem);
					first=fnInsertFront(first,iElem);
					break;
			case 4:first=fnDeleteRear(first);
					break;
			case 5:fnDisplay(first);
					break;
			case 6:exit(0);
			default:printf("\nInvalid choice\n");
					break;
		}
	}
	return 0;	
} 

NODEPTR fnInsertRear(NODEPTR first,int elem)
{
	NODEPTR temp;
	NODEPTR cur,prev;
	
	temp=fnGetNode();
	temp->info=elem;
	temp->rlink=temp->llink=NULL;
	if(first->rlink==first)
	{
		first=temp;
		return first;
	}
	cur=first;
	while(cur->rlink!=first)
	{
		cur=cur->rlink;
	}
	if(cur->rlink==first)
	{
		cur->rlink=temp;
		temp->llink=cur;
		temp->rlink=first;
		return first;
	}
	return first;
}
NODEPTR fnDeleteFront(NODEPTR first)
{
	NODEPTR cur,prev;
	
	if(first->rlink==first)
	{
		printf("\nCannot delete from an empty Queue\n");
		return first;
	}
	
	cur=first;
	printf("\nElement deleted is %d\n",cur->info);
	
	first=cur->rlink;
	first->llink=cur->llink;
	fnFreeNode(cur);
	return first;
	
}

NODEPTR fnGetNode()
{
	NODEPTR newNode;
	
	newNode=(NODEPTR)malloc(sizeof(struct node));
	
	if(newNode==NULL)
	{
		printf("\nFailed to allocate heap memory\n");
		return NULL;
	}
	return newNode;
}

void fnFreeNode(NODEPTR ptr)
{
	free(ptr);
}


void fnDisplay(NODEPTR first)
{
	NODEPTR cur;
	if(first==NULL)
	{
		printf("\nQueue is empty\n");
		return;
	}
	printf("\nElements of the Queue are\n");
	for(cur=first;cur->rlink!=first;cur=cur->rlink)
	{
		printf("%d\t",cur->info);
	}
	printf("%d\t\n",cur->info);
	return;	
}

