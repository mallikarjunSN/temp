#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int info;
	struct node *link;
};

typedef struct node* NODEPTR;

NODEPTR fnGetNode(void);
NODEPTR fnInsertOrder(NODEPTR,int);
NODEPTR fnInsertRear(NODEPTR,int);
NODEPTR fnIntersection(NODEPTR,NODEPTR);
NODEPTR fnUnion(NODEPTR,NODEPTR);
void fnDisplay(NODEPTR);


int main()
{
	NODEPTR list1,list2,inter,unio;
	list1=fnGetNode();
	list2=fnGetNode();
	inter=unio=NULL;
	list1=NULL;
	list2=NULL;
	
	int iElem,iChoice;
	
	for(;;)
	{
		printf("\n1.Insert to list 1\n2.Insert to list 2\n3.Perform union\n4.Perform intersection\n5.Exit\n");
		printf("\nEnter your choice\t");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:printf("\nEnter the element to insert\n");
					scanf("%d",&iElem);
					list1=fnInsertOrder(list1,iElem);
					break;
			case 2:printf("\nEnter the element to insert\n");
					scanf("%d",&iElem);
					list2=fnInsertOrder(list2,iElem);
					break;
			case 3:unio=fnUnion(list1,list2);
					printf("\nList 1\n");
					fnDisplay(list1);
					printf("\nList 2\n");
					fnDisplay(list2);
					printf("\nUnoin of list 1 and list 2 is\n");
					fnDisplay(unio);
					break;
			case 4:inter=fnIntersection(list1,list2);
					printf("\nIntersection of list 1 and list 2 is\n");
					fnDisplay(inter);
					break;
					
			case 6:fnDisplay(unio);
					break;
			case 5:exit(100);
			
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

NODEPTR fnInsertOrder(NODEPTR first,int elem)
{
	NODEPTR temp,prev,cur;
	
	temp=fnGetNode();
	temp->info=elem;
	temp->link=NULL;
	
	if(first==NULL)
	{
		return temp;
	}
	if(elem<=first->info)
	{
		temp->link=first;
		return temp;
	}
	prev=NULL;
	cur=first;
	while((cur!=NULL)&&(elem>cur->info))
	{
		prev=cur;
		cur=cur->link;
	}
	
	prev->link=temp;
	temp->link=cur;
	
	return first;
}
NODEPTR fnIntersection(NODEPTR l1,NODEPTR l2)
{
	NODEPTR t1,t2,t3;
	t3=fnGetNode();
	t3=NULL;
	t1=l1;
	while(t1!=NULL)
	{
		t2=l2;
		while(t2!=NULL)
		{
			if(t1->info==t2->info)
			{
				t3=fnInsertOrder(t3,t1->info);
			}
			t2=t2->link;
		}
		t1=t1->link;
	}
	
	printf("\nList 1\n");
	fnDisplay(l1);
	printf("\nList 2\n");
	fnDisplay(l2);
	return t3;
}
NODEPTR fnUnion(NODEPTR l1,NODEPTR l2)
{
	NODEPTR t1,t2,t3;
	t3=NULL;
	t1=l1;
	t2=l2;
	
	while((t1!=NULL)&&(t2!=NULL))
	{
		if(t1->info<t2->info)
		{
			t3=fnInsertRear(t3,t1->info);
			t1=t1->link;
		}
		else if(t1->info>t2->info)
		{
			t3=fnInsertRear(t3,t2->info);
			t2=t2->link;
		}
		else
		{
			t3=fnInsertRear(t3,t1->info);
			t1=t1->link;
			t2=t2->link;
			
		}
	}
	
	while(t1!=NULL)
	{
		t3=fnInsertRear(t3,t1->info);
		t1=t1->link;
	}
	while(t2!=NULL)
	{
		t3=fnInsertRear(t3,t2->info);
		t2=t2->link;
	}
	return t3;
}

void fnDisplay(NODEPTR first)
{
	NODEPTR cur;
	if(first==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	for(cur=first;cur!=NULL;cur=cur->link)
	{
		printf("%d\t",cur->info);
	}
	printf("\n");
	return;	
}

NODEPTR fnInsertRear(NODEPTR first,int elem)
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

