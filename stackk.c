#include <stdio.h>
#include <stdlib.h>

int STACK_SIZE = 5;



int push(int stack[STACK_SIZE],int iTop, int iNum)
{
    if(iTop == STACK_SIZE)
    {
        printf("\nStack Overflow!!");
        return iTop;
    }
    stack[iTop] = iNum;
    return iTop+1;
}

int pop(int stack[STACK_SIZE],int iTop)
{
    if(iTop == 0)
    {
        printf("\nStack Underflow!!");
        return iTop;
    }
    return iTop-1;
}

void peek(int stack[STACK_SIZE], int iTop)
{
    for(int i=0;i<iTop;i++)
    {
        printf("%d\t",stack[i]);
    }
    printf("\n");
}

int main(){
    printf("**** Stack implementation ****\n");

    int iChoice = 0;
    int iTop = 0;
    int stack[STACK_SIZE];
    while(iChoice != 4)
    {
        printf("select from below menu\n");
        printf("1.Push 2.Pop 3.Peek 4.Exit\n");
        scanf("%d",&iChoice);
        int iNum;
        switch (iChoice)
        {
            case 1:
            printf("enter a number : ");scanf("%d",&iNum);
            iTop = push(stack,iTop,iNum);
            break;
            case 2:
            iTop = pop(stack,iTop);
            break;
            case 3:
            peek(stack,iTop);
            break;
            case 4:
            return 0;
            break;
            default:printf("Invalid choice!!!\n");

        }
    }

    return 0;
}
