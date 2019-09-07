#include <stdio.h>
#include <stdlib.h>


typedef struct{

	char cName[20];
	char cNationality[20];
	int iMatches;
	int iRuns;
	int iWickets;
	int iOvers
	
	
}BOWLER_TYPE;

int main()
{
	BOWLER_TYPE bowlers[10];
	int i,n,iPosEco=0,iPosStr=0;
	float dStrRate[10],dEco[10];
	
	printf("\nEnter no of bowlers(max.10)\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		getchar();
		printf("\nEnter the details of bowler %d\n",i+1);
		printf("\nName\t:");
		gets(bowlers[i].cName);
		printf("\nNationality\t:");
		gets(bowlers[i].cNationality);
		printf("\nNo of matches:\nWickets taken:\nNo of overs:\nRuns conceeded:\n");
		scanf("%d%d%d%d",&bowlers[i].iMatches,&bowlers[i].iWickets,&bowlers[i].iOvers,&bowlers[i].iRuns);
	
	}
	
	for(i=0;i<n;i++)
	{
		dEco[i]=(bowlers[i].iRuns)/(bowlers[i].iOvers);
		dStrRate[i]=(bowlers[i].iWickets)/(bowlers[i].iMatches);
		
		printf("\nBowler %d details\n",i+1);
		printf("\nName\t:%s",bowlers[i].cName);
		printf("\nNationality\t:%s",bowlers[i].cNationality);
		printf("\nNo of matches\t:%d\nWickets taken\t:%d\nNo of overs\t:%d\nRuns conceeded\t:%d\n",bowlers[i].iMatches,bowlers[i].iWickets,bowlers[i].iOvers,bowlers[i].iRuns);		
		
		printf("\nEconomy\t:%f\nStrike rate\t:%f\n",dEco[i],dStrRate[i]);
		
		
		if(dEco[i]>dEco[iPosEco])
			iPosEco=i;
			
		if(dStrRate[i]>dStrRate[iPosStr])
			iPosStr=i;		
	
	}
	
	
	printf("\nBowler with best economy %s\n",bowlers[iPosEco].cName);
	printf("\nBowler with best strike rate %s\n",bowlers[iPosStr].cName);	

	return 0;
}







