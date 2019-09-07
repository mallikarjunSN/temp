#include <stdio.h>
#include <stdlib.h>

typedef union{
	char c;
	int i;
	double d;
	
}mytype_t;

int main()
{
	mytype_t GenArr[10];
	int iaIndexArr[10];
	int iNum,i,iChoice;
	
	printf("\nEnter no of elements\n");
	scanf("%d",&iNum);
	printf("\nEnter %d elements\n",iNum);
	for(i=0;i<iNum;i++)
	{
		printf("\n1.Character\n2.Integer\n3.Double\n");
		printf("\nEnter your choice\n");
		scanf("%d",&iChoice);
		getchar();
		switch(iChoice)
		{
			case 1:printf("\nEnter a character\n");
					scanf("%c",&GenArr[i].c);
					iaIndexArr[i]=1;
					break;
			
			case 2:printf("\nEnter an Integer\n");
					scanf("%d",&GenArr[i].i);
					iaIndexArr[i]=2;
					break;
					
			case 3:printf("\nEnter a double No\n");
					scanf("%lf",&GenArr[i].d);
					iaIndexArr[i]=3;
					break;
		}
			
	}
	printf("\nContents of the generic array\n");
	for(i=0;i<iNum;i++)
	{
		if(iaIndexArr[i]==1)
			printf("\nCharacter:%c\n",GenArr[i].c);
		else if(iaIndexArr[i]==2)
			printf("\nInteger:%d\n",GenArr[i].i);
		else if(iaIndexArr[i]=32)
			printf("\nDouble:%lf\n",GenArr[i].d);
	}
	
	printf("\nSize of gen Arr=%d\n",sizeof(mytype_t));
	
	return 0;
}
