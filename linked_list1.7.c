#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int info;
	struct node *link;
};

typedef struct node* NODEPTR;

NODEPTR fnGetNode(void);
NODEPTR fnInsertRear(NODEPTR,int);
NODEPTR fnDeleteFront(NODEPTR);
NODEPTR fnInsertPos(NODEPTR,int,int);
void fnDisplay(NODEPTR);
NODEPTR fnReverse(NODEPTR);
void fnFreeNode(NODEPTR);

int main()
{
	NODEPTR first;
	first=fnGetNode();
	first=NULL;
	
	int iElem,iPos,iChoice;
	
	for(;;)
	{
		printf("\n1.Insert at the end\n2.Delete the first\n3.Insert at position\n4.Display\n5.Reverse\n6.Exit\n");
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
			case 3:printf("\nEnter the position at which you want to insert\n");
					scanf("%d",&iPos);
					printf("\nEnter the element to insert\n");
					scanf("%d",&iElem);
					first=fnInsertPos(first,iElem,iPos);
					break;
			case 4:fnDisplay(first);
					break;
			case 5:first=fnReverse(first);
					break;
			case 6:exit(100);
			
			default:printf("\nInvalid choice\n");
					break;
		}
	}
	return 0;	
} 

NODEPTR fnGetNode(void)
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

NODEPTR fnInsertRear(NODEPTR first,int elem)
{
	NODEPTR temp;
	NODEPTR cur;
	
	temp=fnGetNode();
	temp->info=elem;
	if(first==NULL)
	{
		temp->info=elem;
		temp->link=NULL;
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
		temp->link=NULL;
		return first;
	}
	return first;
}
NODEPTR fnDeleteFront(NODEPTR first)
{
	NODEPTR cur;
	
	if(first==NULL)
	{
		printf("\nCannot delete fro an empty list\n");
		return first;
	}
	
	cur=first;
	printf("\nElement deleted is %d\n",cur->info);
	
	first=cur->link;
	fnFreeNode(cur);
	return first;
	
}
NODEPTR fnInsertPos(NODEPTR first,int elem,int pos)
{
	NODEPTR temp,cur,prev;
	temp=fnGetNode();
	temp->info=elem;
	int count=1;
	
	if(first==NULL&&pos==1)
	{
		temp->link=NULL;
		temp=first;
		return first;
	}
	if(first==NULL&&pos!=1)
	{
		printf("\nInvalid position\n");
		return first;
	}
	cur=first;
	prev=NULL;
	
	while((cur!=NULL)&&(count!=pos))
	{
		prev=cur;
		cur=cur->link;
		count++;
	}
	if(cur==NULL)
	{
		printf("\nInvalid position\n");
		return first;
	}
	if(count==pos)
	{
		prev->link=temp;
		temp->link=cur;
		return first;
	}
	printf("\nInvalid position\n");
	return first;
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
		printf("\nNode %d\tElement %d",++i,cur->info);
	}
	return;	
}
NODEPTR fnReverse(NODEPTR first)
{
	NODEPTR cur,prev,next;
	
	if(first==NULL)
	{
		printf("\ncannot reverse a empty list\n");
		return first;
	}
	
	if(first->link==NULL)
	{
		return first;
	}
	prev=first;
	cur=first->link;
	next=cur->link;
	prev->link=NULL;
	
	while(cur->link!=NULL)
	{
		cur->link=prev;
		prev=cur;
		cur=next;
		next=next->link;
	}
	cur->link=prev;
	return cur;
}
void fnFreeNode(NODEPTR ptr)
{
	free(ptr);
}



