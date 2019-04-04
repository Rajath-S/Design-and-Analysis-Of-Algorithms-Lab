#include "session10_dcs.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double time_elapsed(struct timespec* start,struct timespec* end);

int main()
{

	struct timespec start,end,s2,e2;
	
	int n,i;
	scanf("%d",&n);
	
	int* A=(int*)malloc(sizeof(int)*n);
	int* C_A=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<n;i++){
		C_A[i]=A[i];
	}
	clock_gettime(CLOCK_REALTIME,&start);
	A=DistributionCountingSorting(A,n);
	clock_gettime(CLOCK_REALTIME,&end);
	
	clock_gettime(CLOCK_REALTIME,&s2);
	MergeSort(C_A,n);
	clock_gettime(CLOCK_REALTIME,&e2);
	
	for(i=0;i<n;i++){
		printf("%d\n",C_A[i]);
	}
	
	printf("%lf\n",time_elapsed(&start,&end));
	printf("%lf\n",time_elapsed(&s2,&e2));
	free(A);
	free(C_A);
	return 0;
}

double time_elapsed(struct timespec* start,struct timespec* end)
{
	double t;
	t=end->tv_sec-start->tv_sec;
	t+=(end->tv_nsec-start->tv_nsec)*0.000000001;
	return t;
}
