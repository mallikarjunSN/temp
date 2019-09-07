#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int iPos,iReadPos;
	char ch;
	fp=fopen("alphabets.txt","r");
	
	if(fp==NULL)
	{
		printf("\nFile not found\n");
		exit(100);
	}
	printf("\nEnter the characters position that you want to read\n");
	scanf("%d",&iPos);
	fseek(fp,iPos,SEEK_SET);
	ch=fgetc(fp);
	iPos=ftell(fp);
	printf("\nCharacter at positon %d is %c\n",iPos,ch);
	
	fseek(fp,0L,SEEK_SET);
	iReadPos=ftell(fp);
	printf("\nThe read position is %d\n",iReadPos);
	ch=fgetc(fp);
	printf("\nThe character read is %c\n",ch);
	
	fseek(fp,-1L,SEEK_END);
	iReadPos=ftell(fp);
	printf("\nThe read position is %d\n",iReadPos);
	ch=fgetc(fp);
	printf("\nThe character read is %c\n",ch);
	
	fseek(fp,-5L,SEEK_CUR);
	iReadPos=ftell(fp);
	printf("\nThe read position is %d\n",iReadPos);
	ch=fgetc(fp);
	printf("\nThe character read is %c\n",ch);
	
	
	fclose(fp);
	return 0;
	
}
