#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int info;
	struct node *llink;
	struct node *rlink;
};

typedef struct node* NODEPTR;

NODEPTR fnInsertRear(NODEPTR,int);
NODEPTR fnInsertAfter(NODEPTR,int);
NODEPTR fnDeleteFirst(NODEPTR);
NODEPTR fnDeletePos(NODEPTR,int);
NODEPTR fnSwapNodes(NODEPTR,int,int);
void fnDisplay(NODEPTR);
void fnFreeNode(NODEPTR);
NODEPTR fnGetNode(void);

int main()
{
	NODEPTR head,last;
	
	head=fnGetNode();
	head->info=0;
	head->llink=head->rlink=head;
	
	int iElem,iChoice,key,iM,iN,iPos;
	
	for(;;)
	{
		printf("\n1.Insert rear\n2.Insert after an element\n3.Delete the first\n4.Delete at position\n5.Display\n6.Swap\n7.Exit\n");
		printf("\nEnter your choice\t");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:printf("\nEnter the element to insert\n");
					scanf("%d",&iElem);
					head=fnInsertRear(head,iElem);
					break;
			case 2:printf("\nEnter the key element after which you want to insert\n");
					scanf("%d",&key);
					head=fnInsertAfter(head,key);
					break;
			case 3:last=head->llink;
					head=fnDeleteFirst(last);
					break;
			case 4:printf("\nEnter the position at which you want to delete\n");
					scanf("%d",&iPos);
					head=fnDeletePos(head,iPos);
					break;
			case 5:fnDisplay(head);
					break;
			case 6:printf("\nEnter the positions m and n of nodes you want to swap(m<n)\n");
					scanf("%d%d",&iM,&iN);
					if(iM<iN)
					{
						head=fnSwapNodes(head,iM,iN);
					}
					else
					{
						printf("\nInvalid input\n");
						break;
					}
					break;
			case 7:exit(100);
			
			default:printf("\nInvalid choice\n");
					break;
		}
	}
	return 0;	
}


NODEPTR fnInsertRear(NODEPTR head,int elem)
{
	NODEPTR temp;
	NODEPTR cur;
	
	temp=fnGetNode();
	temp->info=elem;
	temp->llink=temp->rlink=NULL;
	
	
	if(head->rlink==head)
	{
		head->rlink=temp;
		head->llink=temp;
		temp->llink=head;
		temp->rlink=head;
		head->info++;
		return head;
	}
	
	
	
	cur=head;
	while(cur->rlink!=head)
	{
		cur=cur->rlink;
	}
	if(cur->rlink==head)
	{
		cur->rlink=temp;
		temp->llink=cur;
		temp->rlink=head;
		head->llink=cur;
		head->info++;
		return head;
	}
	return head;
}


NODEPTR fnInsertAfter(NODEPTR head,int key)
{

	int item;
	NODEPTR temp,cur,next;
	if(head->rlink==head)
	{
		printf("\nList is empty\n");
		return head;
	}
	
	cur=head->rlink;
	while(cur!=head&&key!=cur->info)
	{
		cur=cur->rlink;
	}
	
	if(cur==head)
	{
		printf("\nSpecified element is not found\n");
		return head;
	}
	
	next=cur->rlink;
	
	printf("\nEnter the item to be inserted\n");
	scanf("%d",&item);
	temp=fnGetNode();
	temp->info=item;
	
	cur->rlink=temp;
	temp->llink=cur;
	next->llink=temp;
	temp->rlink=next;
	head->info++;
	return head;
}




NODEPTR fnDeleteFirst(NODEPTR last)
{
	NODEPTR head,first,second;
	
	if(last->rlink==last)
	{
		printf("\nCannot delete from an empty list\n");
		return last;
	}
	
	head=last->rlink;
	first=head->rlink;
	second=first->rlink;
	head->rlink=second;
	second->llink=head;
	
	printf("\nElement deleted is %d\n",first->info);
	
	
	head->info--;
	
	fnFreeNode(first);
	return head;	
}


NODEPTR fnDeletePos(NODEPTR head,int pos)
{
	NODEPTR next,cur,prev;
	int count=1;
	
	if(head->rlink==head)
	{
		printf("\nCannot delete from an empty list\n");
		return head;
	}
	
	
	cur=head->rlink;
	prev=NULL;
	
	while((cur!=head)&&(count!=pos))
	{
		prev=cur;
		cur=cur->rlink;
		count++;
	}
	if(cur==head)
	{
		printf("\nInvalid position\n");
		return head;
	}
	if(count==pos)
	{
		next=cur->rlink;
		printf("\nDeleted element is %d",cur->info);
		prev->rlink=next;
		next->llink=prev;
		fnFreeNode(cur);
		return head;
	}
	printf("\nInvalid position\n");
	return head;
}




NODEPTR fnSwapNodes(NODEPTR head,int m,int n)
{
	int temp,count=1;
	NODEPTR cur,mpos,npos;
	cur=head->rlink;
	while(cur!=head&&count!=m)
	{
		cur=cur->rlink;
		count++;
	}
	
	if(cur!=head)
	{
		mpos=cur;
	}
	else
	{
		printf("\nNode %d not exist\n",m);
		return head;
	}
	
	
	while(cur!=head&&count!=n)
	{
		cur=cur->rlink;
		count++;
	}
	
	if(cur!=head)
	{
		npos=cur;
	}
	else
	{
		printf("\nNode %d not exist\n",n);
		return head;
	}
	
	temp=mpos->info;
	mpos->info=npos->info;
	npos->info=temp;
	return head;
}




void fnDisplay(NODEPTR head)
{
	NODEPTR cur;
	int i=0;
	if(head->rlink==head)
	{
		printf("\nList is empty\n");
		return;
	}
	printf("\nNo of elements in list is %d",head->info);
	for(cur=head->rlink;cur!=head;cur=cur->rlink)
	{
		printf("\nNode %d\tElement %d",++i,cur->info);
	}
	return;	
}


void fnFreeNode(NODEPTR temp)
{
	free(temp);
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




