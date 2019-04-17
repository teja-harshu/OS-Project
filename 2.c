#include<stdio.h>

int main()
{
// For Storing cylinder numbers being requested
int cCurr,cReq[5000],cQLen,i,dist[20];

//Total Distance
int sum = 0;

//Taking Values of Cylinder requesting from user
printf("Enter the number of Cylinders in Queue\n");
scanf("%d",&cQLen);
printf("Enter the Cylinder value in Queue\n");
for(i=1; i<=cQLen; i++)
{
	scanf("%d",&cReq[i]);
	printf("\n");
}

//Taking current req cylinder no
printf("Enter the Current serving Request Cylinder Number\n");
scanf("%d",&cCurr);

//Calculating total distance

for(i=1; i<=cQLen; i++)
{
	dist[i]=cCurr-cReq[i];
	if(dist[i]<0)
	{
		dist[i] = cReq[i] - cCurr;
	}
	cCurr = cReq[i];
	sum += dist[i];
}
printf("Total Distance is %d",sum);

}








