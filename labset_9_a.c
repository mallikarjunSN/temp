#include<stdio.h>
#include<stdlib.h>


struct node 
{
	int info;
	struct node *link;
};

typedef struct node* NODEPTR;

NODEPTR fnPush(NODEPTR,int);
NODEPTR fnPop(NODEPTR);
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
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
		printf("\nEnter your choice\t");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:printf("\nEnter the element to insert\n");
					scanf("%d",&iElem);
					first=fnPush(first,iElem);
					break;
			case 2:first=fnPop(first);
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


NODEPTR fnPush(NODEPTR first,int elem)
{
	NODEPTR temp;
	NODEPTR cur,prev;
	
	temp=fnGetNode();
	temp->info=elem;
	temp->link=NULL;
	if(first==NULL)
	{
		return temp;
	}
	temp->link=first;
	return temp;
}

NODEPTR fnPop(NODEPTR first)
{
	NODEPTR cur,prev;
	
	if(first==NULL)
	{
		printf("\nStack underflow\n");
		return first;
	}
	
	cur=first;
	printf("\nElement popped is %d\n",cur->info);
	
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
	int i=0;
	if(first==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	for(cur=first;cur!=NULL;cur=cur->link)
	{
		printf("\nNode %d\nElement %d",++i,cur->info);
	}
	return;	
}

