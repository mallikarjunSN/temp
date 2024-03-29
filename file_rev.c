#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc,char **argv)
{
	int offset=0;
	char ch;
	FILE *fp1,*fp2;
	if(argc<2)
	{
		printf("\nIncomplete no of arguments\n");
		exit(100);
	}
	fp1=fopen(argv[1],"r");
	if(fp1==NULL)
	{
		printf("\nCannot open the file\n");
		exit(100);
	}
	char name[30];
	strcpy(name,"Reverse_of_");
	strcat(name,argv[1]);
	fp2=fopen(name,"w");
	
	while(!fseek(fp1,-offset,SEEK_END))
	{
		fputc(fgetc(fp1),fp2);
		offset++;
	}
	
	fseek(fp2,2L,SEEK_CUR);
	while((ch=fgetc(fp2))!=EOF)
	{
		printf("%c",ch);
	}
	fclose(fp1);
	fclose(fp2);
	
	printf("\n");
	return 0;
	
}
