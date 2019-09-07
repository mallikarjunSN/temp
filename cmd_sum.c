#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv)
{
	int iVal2,iVal1,iSum;
	if(argc!=3)
	{
		printf("\nInvalid input.enter 3 valid command line arguments\n");
		return -1;
	}
	
	iVal1=atoi(argv[1]);
	iVal2=atoi(argv[2]);
	
	iSum=iVal1+iVal2;
	
	printf("\nSum of %d and %d id %d\n",iVal1,iVal2,iSum);
	return 0;
}
