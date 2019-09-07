#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 5

typedef struct{
	int iaStack[STACK_SIZE];
	int iTop;
}STACK_TYPE;

void fnPush(STACK_TYPE *,int);
int fnPop(STACK_TYPE *);
int fnPeek(STACK_TYPE);
void fnDisplay(STACK_TYPE);
bool fnCheckFull(int);
bool fnCheckEmpty(int);

int main()
{
	STACK_TYPE myStack;
	int i,iElem,iChoice;
	
	myStack.iTop=-1;
	
	for(;;)
	{
		printf("\nPlease enter your choice\n");
		
		printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:if(fnCheckFull(myStack.iTop))
					{
						printf("\nStack Overflow\n");
						exit(100);
					}
					printf("\nEnter the element to be pushed int the stack\n");
					scanf("%d",&iElem);
					fnPush(&myStack,iElem);
					break;
					
			case 2:if(fnCheckEmpty(myStack.iTop))
					{
						printf("\nStack UnderFlow\n");
						exit(100);
					}
					iElem=fnPop(&myStack);
					printf("\nPopped element is %d\n",iElem);
					break;
			case 3:if(fnCheckEmpty(myStack.iTop))
					{
						printf("\nStack is Empty\n");
						exit(100);
					}
					iElem=fnPeek(myStack);
					printf("\nElement at the top of stack is %d\n",iElem);
					break;
					
			case 4:if(fnCheckEmpty(myStack.iTop))
					{
						printf("\nStack is Empty\n");
						exit(100);
					}
					fnDisplay(myStack);
					break;
					
			case 5:exit(100);
					break;
		}
	}
	return 0;
}

void fnPush(STACK_TYPE *stack,int elem)
{
	stack->iTop=stack->iTop+1;
	stack->iaStack[stack->iTop]=elem;
}

int fnPop(STACK_TYPE *stack)
{
	int elem;
	elem=stack->iaStack[stack->iTop];
	stack->iTop=stack->iTop-1;
	return elem;
}

int fnPeek(STACK_TYPE stack)
{
	return(stack.iaStack[stack.iTop]);
}

void fnDisplay(STACK_TYPE stack)
{
	int i;
	for(i=0;i<=stack.iTop;i++)
		printf("\n%d",stack.iaStack[i]);
}

bool fnCheckFull(int top)
{
	if(top==STACK_SIZE-1)
		return true;
	else
		return false;
}

bool fnCheckEmpty(int top)
{
	if(top==-1)
		return true;
	else
		return false;
}








