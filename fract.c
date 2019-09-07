#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{

	int iNum,iDen;
	
}FRACTION_TYPE;

void fnReadFraction(FRACTION_TYPE *);
void fnShowFraction(FRACTION_TYPE);
void fnReduceFraction(FRACTION_TYPE *);
int gcd(int,int);
FRACTION_TYPE fnAddFraction(FRACTION_TYPE,FRACTION_TYPE);

int main()
{
	FRACTION_TYPE f1,f2,f3,f4={7,4};
	
	fnReadFraction(&f1);
	
	fnShowFraction(f1);
	
	fnReadFraction(&f2);
	
	fnShowFraction(f2);
	
	f3=fnAddFraction(f1,f2);
	
	fnReduceFraction(&f3);
	
	printf("\nResult=");
	fnShowFraction(f3);
	
	f4=f3;
	
	return 0;
}

void fnReadFraction(FRACTION_TYPE *f)
{
	printf("\nEnter numerator and denominator in order\n");
	scanf("%d%d",&f->iNum,&f->iDen);
	
}

void fnShowFraction(FRACTION_TYPE f)
{
	printf("\nNumerator/Denominator=(%d/%d)\n",f.iNum,f.iDen);	
	return;
}

void fnReduceFraction(FRACTION_TYPE *f)
{
	int common=gcd(f->iNum,f->iDen);
	f->iNum/=common;
	f->iDen/=common;
}

FRACTION_TYPE fnAddFraction(FRACTION_TYPE f1,FRACTION_TYPE f2)
{
	FRACTION_TYPE f3;
	f3.iNum=f1.iNum*f2.iDen+f2.iNum*f1.iDen;
	f3.iDen=f1.iDen*f2.iDen;
	fnReduceFraction(&f3);
	return (f3);
}

int gcd(int m,int n)
{
	 if(n==0)
	 	return m;
	 else
		return gcd(n,m%n);
}





