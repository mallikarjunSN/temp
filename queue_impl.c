#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUE_SIZE 5

void fnEnqueue(int [],int *,int);
int fnDequeue(int [],int *);
void fnDisplay(int [],int,int);
bool fnQueueFull(int [],int);
bool fnQueueEmpty(int [],int,int);

int main()
{
	int iQueue[QUE_SIZE];
	int iRear=-1,iFront=0;
	int iChoice,iElem;
	
	for(;;)
	{
		printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.exit\n");
		printf("\nEnter a choice\t:");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:if(!fnQueueFull(iQueue,iRear))
					{
						printf("\nEnter an element you want to insert\n");
						scanf("%d",&iElem);
						fnEnqueue(iQueue,&iRear,iElem);
					}
					else 
					{
						printf("\nQueue is full\n");
					}
					break;
					
			case 2:if(!fnQueueEmpty(iQueue,iRear,iFront))
					{
						iElem=fnDequeue(iQueue,&iFront);
						printf("\nElement removed is %d\n",iElem);
					}
					else 
					{
						printf("\nQueue is Empty\n");
					}
					break;
					
			case 3:if(!fnQueueEmpty(iQueue,iRear,iFront))
					{
						fnDisplay(iQueue,iRear,iFront);
					}
					else 
					{
						printf("\nQueue is Empty\n");
					}
					break;
					
			case 4:exit(0);
					
					
		}
		
	}
	return 0;
}

void fnEnqueue(int queue[QUE_SIZE],int *rear,int elem)
{
	*rear=*rear+1;
	queue[*rear]=elem;	
}

int fnDequeue(int queue[QUE_SIZE],int *front)
{
	int elem;
	elem=queue[*front];
	*front=*front+1;
	return elem;
}


void fnDisplay(int queue[QUE_SIZE],int rear,int front)
{
	int i;
	printf("\nElements of the queue are\n");
	for(i=front;i<=rear;i++)
	{
		printf("%d\t",queue[i]);
	}
}
bool fnQueueFull(int queue[QUE_SIZE],int rear)
{
	if(rear==QUE_SIZE-1)
		return true;
	else 
		return false;
}

bool fnQueueEmpty(int queue[QUE_SIZE],int rear,int front)
{
	if(front>rear)
		return true;
	else 
		return false;
}
