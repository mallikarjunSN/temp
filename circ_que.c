#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


#define QUEUE_SIZE 5

typedef struct{
	int myQ[QUEUE_SIZE];
	int iFront,iRear;
}QUEUE_TYPE;


void fnInsertRear(QUEUE_TYPE *,int);
int fnDeleteFront(QUEUE_TYPE *);
void fnDisplay(QUEUE_TYPE);
bool fnQueueFull(QUEUE_TYPE);
bool fnQueueEmpty(QUEUE_TYPE);

int main()
{
	
	QUEUE_TYPE queue;
	
	queue.iFront=-1;
	queue.iRear=-1;
	
	int iChoice,iElem;
	
	for(;;)
	{
		printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.exit\n");
		printf("\nEnter a choice\t:");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:if(!fnQueueFull(queue))
					{
						printf("\nEnter an element you want to insert\n");
						scanf("%d",&iElem);
						fnInsertRear(&queue,iElem);
					}
					else 
					{
						printf("\nQueue is full\n");
					}
					break;
					
			case 2:if(!fnQueueEmpty(queue))
					{
						iElem=fnDeleteFront(&queue);
						printf("\nElement removed is %d\n",iElem);
					}
					else 
					{
						printf("\nQueue is Empty\n");
					}
					break;
					
			case 3:if(!fnQueueEmpty(queue))
					{
						fnDisplay(queue);
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

void fnInsertRear(QUEUE_TYPE *queue,int elem)
{
	
	
	if(queue->iRear==-1)
	{
		queue->iFront=queue->iFront+1;
		queue->iRear=queue->iRear+1;
	}	
	else
	{
		queue->iRear=(queue->iRear+1)%QUEUE_SIZE;
	}
	queue->myQ[queue->iRear]=elem;	
}

int fnDeleteFront(QUEUE_TYPE *queue)
{
	int iElem;
	iElem=queue->myQ[queue->iFront];
	
	if(queue->iRear==queue->iFront)
	{
		queue->iFront=-1;
		queue->iRear=-1;
	}
	else
	{
		queue->iFront=(queue->iFront+1)%QUEUE_SIZE;
	}
	return iElem;
}

void fnDisplay(QUEUE_TYPE queue)
{
	int i;
	if(queue.iFront<=queue.iRear)
	{
		for(i=queue.iFront;i<=queue.iRear;i++)
		{
			printf("%d\t",queue.myQ[i]);
		}
		printf("\n");
	}
	
	else
	{
		for(i=queue.iFront;i<=QUEUE_SIZE-1;i++)
		{
			printf("%d\t",queue.myQ[i]);
		}
		for(i=0;i<=queue.iRear;i++)
		{
			printf("%d\t",queue.myQ[i]);
		}
		printf("\n");
	}
}

bool fnQueueFull(QUEUE_TYPE queue)
{
	if((queue.iFront)==(queue.iRear+1)%QUEUE_SIZE)
		return true;
	else
		return false;
	
}
bool fnQueueEmpty(QUEUE_TYPE queue)
{
	if((queue.iFront==-1))
		return true;
	else
		return false;
}
