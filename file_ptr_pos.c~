#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int iPos ;
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
	
	printf("\nSEEK_CUR=%d\tSEEK_END=%d\tSEEK_SET=%d\n",SEEK_CUR,SEEK_END,SEEK_SET);
	
	
	fseek(fp,0L,SEEK_SET);
	ch=fgetc(fp);
	iPos=ftell(fp);
	printf("\nCharacter at positon %d is %c\n",iPos,ch);
	
	
	fseek(fp,-1L,SEEK_END);
	ch=fgetc(fp);
	iPos=ftell(fp);
	printf("\nCharacter at positon %d is %c\n",iPos,ch);
	
	
	fseek(fp,-5L,SEEK_END);
	ch=fgetc(fp);
	iPos=ftell(fp);
	printf("\nCharacter at positon %d is %c\n",iPos,ch);
	
	
	fseek(fp,0L,SEEK_CUR);
	ch=fgetc(fp);
	iPos=ftell(fp);
	printf("\nCharacter at positon %d is %c\n",iPos,ch);
	
	return 0;
	
}
