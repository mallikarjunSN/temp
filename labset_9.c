#include<stdio.h>
#include<stdlib.h>


struct node 
{
	int info;
	struct node *link;
};
int main()
{
	NODEPTR first;
	first=NULL;
	first=fnGetNode();
	
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
