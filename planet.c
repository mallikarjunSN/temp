#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZ 10

typedef struct{
	char name[STRSIZ];
	double diameter_m;
	int moons;
	double orbit_time_d;
	double rotation_time_h;
	double mass;
	
}planet_t;

int main()
{
	 planet_t p1;
	 planet_t p[2];
	 
	 printf("\nMemory allocated to p1 is %lu bytes \n",sizeof(p1));
	 
	 printf("\nMemory allocated to planet_t is %lu bytes \n",sizeof(planet_t));
	 	 
	 printf("\nMemory allocated to double is %lu bytes \n",sizeof(double));
	 	 	 
	 printf("\nMemory allocated to int is %lu bytes \n",sizeof(int));
	 
	 printf("\nMember1:%u\n",&p1.name);
	 printf("\nMember2:%u\n",&p1.diameter_m);	 	 	 	 
	 printf("\nMember3:%u\n",&p1.moons);	 	 	 	 
	 printf("\nMember4:%u\n",&p1.orbit_time_d);
	 printf("\nMember5:%u\n",&p1.rotation_time_h);	 
	 printf("\nMember6:%u\n",&p1.mass);
	 
	 printf("\nAddress of p[0]=%p",&p[0]);
	 printf("\nAddress of p[1]=%p",&p[1]);
	 
	 return 0;	 
}
