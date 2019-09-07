#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void fnPush(char [],int *,char cSymb);
char fnPop(char [],int *);
int fnPrcdnc(char);

int main()
{
	int i,j=0;
	char cSymb,cInfix[30],cStack[30];
	char cPostfix[30];
	
	int iTop=-1;
	fnPush(cStack,&iTop,'#');
	
	printf("\nEnter a valid Infix expression with single digit operand\n");
	
	scanf("%s",cInfix);
	printf("\nEntered expression : %s\n",cInfix);
	
	for(i=0;i<strlen(cInfix);i++)
	{
		cSymb=cInfix[i];
		if(cSymb=='(')
		{
			fnPush(cStack,&iTop,cSymb);	
		}
		else if(isalnum(cSymb))
		{
			cPostfix[j++]=cSymb;
		}
		else if(cSymb==')')
		{
			while(cStack[iTop]!='(')
				{
					cPostfix[j++]=fnPop(cStack,&iTop);
				}
					
			fnPop(cStack,&iTop);
		}
		
		else 
		{
			while((fnPrcdnc(cStack[iTop])) >= (fnPrcdnc(cSymb)))
			{
				if(cSymb=='^'&&cStack[iTop]=='^')
					break;
				cPostfix[j++]=fnPop(cStack,&iTop);
			}
			fnPush(cStack,&iTop,cSymb);	
		}
			
	}
	while(cStack[iTop]!='#')
	{
		cPostfix[j++]=fnPop(cStack,&iTop);
	}
	cPostfix[j]='\0';
	
	printf("\nThe equivalent postfix expression is %s\n\n",cPostfix);
	return 0;
	
}

void fnPush(char stack[30],int *iTop,char cSymb)
{
	*iTop=*iTop+1;
	stack[*iTop]=cSymb;
}

char fnPop(char stack[30],int *iTop)
{
	char ch;
	ch=stack[*iTop];
	*iTop=*iTop-1;
	return ch;	
}


int fnPrcdnc(char cSymb)
{
	int iPrecd=4;
	switch(cSymb)
	{
		case '#':
					return -1;
	
		case '(':
					return 0;
		
		case '+':
		case '-':
					return 1;
 
		case '*':
		case '%':
		case '/':
					return 2;
		
		case '$':
					return 3;
		
		default: break;
	}
	return iPrecd;
}
