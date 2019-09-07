#include <stdio.h>
#include <stdlib.h>

void towers(int,char,char,char);

int main()
{
	int num;
	printf("\nEnter the no of disks\n");
	scanf("%d",&num);
	printf("\nThe sequence of moves involved in the tower of hanoi are\n");
	towers(num,'A','C','B');
	printf("\n");
	return 0;
}

void towers(int num,char frompeg,char topeg,char auxpeg)
{
	int count=0;
	
	if(num==1)
	{
		printf("\nMove disk 1 from peg %c to peg %c\n",frompeg,topeg);
		count++;
		return;
	}
	
	towers(num-1,frompeg,auxpeg,topeg);
	printf("\nMove disk %d from peg %c to peg %c\n",num,frompeg,topeg);
	towers(num-1,auxpeg,topeg,frompeg);
}
