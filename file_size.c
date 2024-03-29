#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
	int count=0;
	char ch;
	FILE *fp;
	if(argc<2)
	{
		printf("\nIncomplete no of arguments\n");
		exit(100);
	}
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("\nCannot open the file\n");
		exit(100);
	}
	while(ch=fgetc(fp)!=EOF)
	{
		count++;
	}
	printf("\nSize of file %s is %d bytes\n",argv[1],count);
	
	if(fp!=NULL)
	{
		fseek(fp,0L,SEEK_END);
		printf("\nSize of file %s is %d bytes\n",argv[1],ftell(fp));
	}
	return 0;
}
