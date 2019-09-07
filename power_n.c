#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef union {
	float fExp;
	int iExp;
}exp_t;

typedef struct {
	float x;
	char flag;
	exp_t expo;
}value_t;

float power(value_t);

int main()
{
	value_t a;
	int i;
	float y,n;
	
	printf("\n\nEnter a value for x :");
	scanf("%f",&a.x);
	printf("\nEnter a value for n :");
	scanf("%f",&n);
	i=(int)n;
	a.flag=((i==n)?'i':'f');
	
	if(a.flag=='i')
		a.expo.iExp=i;
	else 
		a.expo.fExp=n;
	
	if(a.flag=='f'&&a.x==0.0)
	{
		printf("\nError cannot raise a non positive number power\n");
	}
	else
	{
		y=power(a);
		printf("\ny=%.4f\n",y);
	} 
	return 0;
}

float power(value_t a)
{
	int i;
	float y=a.x;
	if(a.flag=='i')
	{
		if(a.expo.iExp==0)
		{
			y=1.0;
		}
		else 
		{
			for(i=1;i<abs(a.expo.iExp);i++)
				y*=a.x;
			
			if(a.expo.iExp<0)
				y=1.0/y;
		}
	}
	else 
	{
		y=exp(a.expo.fExp*logf(a.x));
	}
	return y;
}
