#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	FILE *fp1,*fp2;
	int i=0;
	char line[20],ch;
	
	fp1=fopen("file.dat","w");
	
	if(fp1==NULL)
	{
		printf("\nFailed to open a file\n");
		exit(0);
	}
	printf("\nEnter 5 lines of text \n");
	
	while(i++!=5)
	{
		gets(line);
		fprintf(fp1,"%s\n",line);
	}
	fclose(fp1);
	
	fp2=fopen("file.dat","r");
	printf("\n\n");
	
	
	while(fscanf(fp2,"%[^\n]s",line)!=EOF)
	{
		ch=fgetc(fp2);
		printf("%s\n",line);
	}
	fclose(fp2);
	return 0;
	
}
