#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct ExpTree
{
		char value;
		struct ExpTree *lbranch,*rbranch;
};
typedef struct ExpTree* NODEPTR;

bool isOperator(char);
void fnInOrder(NODEPTR);
NODEPTR newNode(int);
NODEPTR constructTree(char postfix[]);
void push(NODEPTR [],NODEPTR,int *);
NODEPTR pop(NODEPTR [],int *);
float evalPost(NODEPTR);

int main()
{
	char postfix[30];
	float fResult;
	
	printf("\nEnter a postfix expression\n");
	scanf("%s",postfix);
	
	NODEPTR et=constructTree(postfix);
	
	printf("\nInfix expression is \n");
	fnInOrder(et);
	
	printf("\n");
	fResult=evalPost(et);
	
	printf("\nValue of postfix expression is %f\n",fResult);
	return 0;
	
}

bool isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
		return true;
	else 
		return false;	
}


void fnInOrder(NODEPTR t)
{
	if(t!=NULL)
	{
		fnInOrder(t->lbranch);
		printf("%c",t->value);
		fnInOrder(t->rbranch);
	}
}

NODEPTR newNode(int v)
{
	NODEPTR temp=(NODEPTR)malloc(sizeof(struct ExpTree));
	temp->lbranch=temp->rbranch=NULL;
	temp->value=v;
	return temp;
}

NODEPTR constructTree(char postfix[])
{
	NODEPTR stack[100];
	int i,iTop=-1;
	NODEPTR t,t1,t2;
	
	for(i=0;i<strlen(postfix);i++)
	{
		if(!isOperator(postfix[i]))
		{
			t=newNode(postfix[i]);
			push(stack,t,&iTop);
		}
		else
		{
			t=newNode(postfix[i]);
			t1=pop(stack,&iTop);
			t2=pop(stack,&iTop);
			t->rbranch=t1;
			t->lbranch=t2;
			push(stack,t,&iTop);
		}
	}
	
	t=pop(stack,&iTop);
	return t;
}

void push(NODEPTR stack[],NODEPTR p,int *t)
{
	*t=*t+1;
	stack[*t]=p;
}

NODEPTR pop(NODEPTR stack[],int *t)
{
	NODEPTR temp;
	temp=stack[*t];
	*t=*t-1;
	return temp;
}

float evalPost(NODEPTR root)
{
	float fNum;
	switch(root->value)
	{
		case '+':return(evalPost(root->lbranch)+evalPost(root->rbranch));
		case '-':return(evalPost(root->lbranch)-evalPost(root->rbranch));
		case '*':return(evalPost(root->lbranch)*evalPost(root->rbranch));
		case '/':return(evalPost(root->lbranch)/evalPost(root->rbranch));
		case '^':return(pow(evalPost(root->lbranch),evalPost(root->rbranch)));
		
		default: if(isalpha(root->value))
					{
						printf("\n%c=",root->value);
						scanf("%f",&fNum);
						return fNum;
					}
					else 
					return root->value-'0';
	}
	
	
}



