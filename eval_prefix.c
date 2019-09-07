#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void fnPush(int [],int *,int);
int fnPop(int [],int *);

int main()
{
	int iOp1,iOp2,iRes=0;
	int i,iaStack[10],iTop=-1;
	char acPrefix[10],cSymb;
	
	printf("\nEnter a valid prefix expression\n");
	scanf("%s",acPrefix);
	
	for(i=strlen(acPrefix)-1;i>=0;i--)
	{
		cSymb=acPrefix[i];
		if(isdigit(cSymb))
		{
			fnPush(iaStack,&iTop,(cSymb-'0'));
		}
		else
		{
			iOp1=fnPop(iaStack,&iTop);
			iOp2=fnPop(iaStack,&iTop);
			
			switch(cSymb)
			{
				case '+':iRes=iOp1+iOp2;
							break;
				case '-':iRes=iOp1-iOp2;
							break;
				case '*':iRes=iOp1*iOp2;
							break;
				case '/':iRes=iOp1/iOp2;
							break;
			}
			fnPush(iaStack,&iTop,iRes);
		}
	}
	
	iRes=fnPop(iaStack,&iTop);
	printf("\nResult=%d\n",iRes);
	return 0;
}

void fnPush(int iaStack[],int *iTop,int symb)
{
	*iTop=*iTop+1;
	iaStack[*iTop]=symb;
}
int fnPop(int iaStack[],int *iTop)
{
	int elem;
	elem=iaStack[*iTop];
	*iTop=*iTop-1;
	return elem;
}


