#include <stdio.h>
#include <stdlib.h>
#include "session3_bubbleselection.h"
#include <time.h>

int main()
{
	struct timespec start,end;
	 int n;
	scanf("%d",&n);
	Data * A = (Data *)malloc(sizeof(Data)*n);
	int v,i;
	for(int i = 0;i<n;i++)
	{
		scanf("%d%d",&(A[i].id),&(A[i].value));
	}
	int k;
	scanf("%d",&k);
	clock_gettime(CLOCK_REALTIME, &start);
	
	Data * BafterK = BubbleSort(A,n,k);
	
	clock_gettime(CLOCK_REALTIME, &end);
	
	//Data * Bfullysorted = BubbleSort(A,n,n);
	
	//clock_gettime(CLOCK_REALTIME, &start);
	double timeBAfterK= end.tv_sec - start.tv_sec;
	
	clock_gettime(CLOCK_REALTIME, &start);
	
	Data * Bfullysorted = BubbleSort(A,n,n);
	
	clock_gettime(CLOCK_REALTIME, &end);
	
	double timeBfullySorted = end.tv_sec - start.tv_sec;
	
	
	//double timeinsecondsB= end.tv_sec - start.tv_sec;
	clock_gettime(CLOCK_REALTIME, &start);
	
	Data * SafterK = SelectionSort(A,n,k);
	
	clock_gettime(CLOCK_REALTIME, &end);
	double timeSK= end.tv_sec - start.tv_sec;
	
	clock_gettime(CLOCK_REALTIME, &start);
	
	Data * Sfullysorted = SelectionSort(A,n,n);
	
	clock_gettime(CLOCK_REALTIME, &end);
	double timeSsorted = end.tv_sec - start.tv_sec;
	
	
	
	
	
	
	
	
	
	
	//double timeinsecondsS= end.tv_sec - start.tv_sec;
	for(int i = 0;i<n;i++)
	{
		printf("%d %d\n",BafterK[i].id,BafterK[i].value);
	}
	for(int i = 0;i<n;i++)
	{
		printf("%d %d\n",Bfullysorted[i].id,Bfullysorted[i].value);
	}
	for(int i = 0;i<n;i++)
	{
		printf("%d %d\n",SafterK[i].id,SafterK[i].value);
	}
	for(int i = 0;i<n;i++)
	{
		printf("%d %d\n",Sfullysorted[i].id,Sfullysorted[i].value);
	}
	printf("%lf\n%lf\n%lf\n%lf\n",timeBAfterK,timeBfullySorted,timeSK,timeSsorted);
}
