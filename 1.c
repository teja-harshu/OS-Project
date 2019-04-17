#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	printf("\t***************************************************************************\n\n");
    int brstTym[20],arvlTym[20],np,tempi,startTym[10],finishTym[10],wytngTym[10],trnArndTym[10],i,j;
    int totalWT=0;
    int totalTA=0;
    float avgWT,avgTA;
    char processName[5][10],temps[10];
   
    printf("Enter the number of process:");
    scanf("%d",&np);
    printf("\n");
    for(i=0; i<np; i++)
    {
        printf("Enter Process Name , Arrival Time and Burst Time\n");
        scanf("%s %d %d",processName[i],&arvlTym[i],&brstTym[i]);
    }
    for(i=0; i<np; i++)
    {
    	for(j=0; j<np; j++)
        {
            if(brstTym[i]<brstTym[j])
            {
                tempi=arvlTym[i];
                arvlTym[i]=arvlTym[j];
                arvlTym[j]=tempi;
                
                tempi=brstTym[i];
                brstTym[i]=brstTym[j];
                brstTym[j]=tempi;
                
                strcpy(temps,processName[i]);
                strcpy(processName[i],processName[j]);
                strcpy(processName[j],temps);
            }
        }
    }
   	for(i=0; i<np; i++)
    {
		if(i==0)
            startTym[i]=arvlTym[i];
        else
            startTym[i] = finishTym[i-1];
        	wytngTym[i] = startTym[i] - arvlTym[i];
        	
        	finishTym[i] = startTym[i] + brstTym[i];
        	trnArndTym[i] = finishTym[i]-arvlTym[i];
        	
        	totalWT += wytngTym[i];
        	totalTA += trnArndTym[i];
    }
    avgWT = (float)totalWT/np;
    avgTA = (float)totalTA/np;
    printf("\n\t***************************************************************************\n");
    printf("\n\tProcess Name \tArrival Time\t Burst Time\t Waiting Time\t Turn Around Time");
    for(i=0; i<np; i++)
        printf("\n \t%5s \t%15d \t%7d \t\t%d \t\t%d",processName[i],arvlTym[i],brstTym[i],wytngTym[i],trnArndTym[i]);
    printf("\n\t-----------------------------------------------------------------------------\n");
    printf("\n\tAverage waiting time is:%f",avgWT);
    printf("\n\tAverage turnaroundtime is:%f",avgTA);
    getch();
}
