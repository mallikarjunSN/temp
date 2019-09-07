#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int info;
	struct node *link;
};

typedef struct node* NODEPTR;

NODEPTR fnEnque(NODEPTR,int);
NODEPTR fnDeque(NODEPTR);
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
		printf("\n1.Enque\n2.Deque\n3.Display\n4.Exit\n");
		printf("\nEnter your choice\t");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:printf("\nEnter the element to insert\n");
					scanf("%d",&iElem);
					first=fnEnque(first,iElem);
					break;
			case 2:first=fnDeque(first);
					break;
			case 3:fnDisplay(first);
					break;
			case 4:exit(100);
			
			default:printf("\nInvalid choice\n");
					break;
		}
	}
	return 0;	
} 

NODEPTR fnEnque(NODEPTR first,int elem)
{
	NODEPTR temp;
	NODEPTR cur,prev;
	
	temp=fnGetNode();
	temp->info=elem;
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
NODEPTR fnDeque(NODEPTR first)
{
	NODEPTR cur,prev;
	
	if(first==NULL)
	{
		printf("\nCannot delete from an empty Queue\n");
		return first;
	}
	
	cur=first;
	printf("\nElement deleted is %d\n",cur->info);
	
	first=cur->link;
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
	for(cur=first;cur!=NULL;cur=cur->link)
	{
		printf("%d\t",cur->info);
	}
	return;	
}

