#include <stdio.h>
#include <stdlib.h>

typedef union{
	char c;
	int i;
	double d;
}mytype_t;

int main()
{
	mytype_t x,y,z;
	
	x.c='l';
	y.i=65;
	z.d=254.3;
	printf("\n%c",x.c);
	printf("\n%d",y.i);
	printf("\n%lf",z.d);
	printf("\n\\\\\\\\\\\\\\\\\\\\  \n");
	y.d=234.4556;
	printf("\n%d",x.i);
	printf("\n%d",y.i);
	printf("\n%d",z.i);
	printf("\n\\\\\\\\\\\\\\\\\\\\  \n");
	printf("\n%lf",x.d);
	printf("\n%lf",y.d);
	printf("\n%lf",z.d);
	printf("\n\\\\\\\\\\\\\\\\\\\\  \n");
	return 0;
}
