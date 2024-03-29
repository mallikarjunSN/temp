#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union{
	unsigned char cDotAddress[4];
	unsigned int i32Address;
}ipAddress_t;

int main()
{
	ipAddress_t myIp;
	char acAddrstr[16];
	char *token;
	int iVal,i=3;
	printf("\nEnter your IP address : ");
	scanf("%s",acAddrstr);
	
	token=strtok(acAddrstr,".");
	
	while(token!=NULL)
	{
		iVal=atoi(token);
		myIp.cDotAddress[i--]=iVal;
		token=strtok(NULL,".");
	}
	printf("\nThe adress in Dot format is\n");
	printf("%d",myIp.cDotAddress[3]);
	
	for(i=2;i>=0;i--)
		printf(".%d",myIp.cDotAddress[i]);
		
	printf("\nThe 32 bit address is : \n%u\n",myIp.i32Address);
	printf("\nThe 32 bit address is : \n%0x\n",myIp.i32Address);
	return 0;	
}
