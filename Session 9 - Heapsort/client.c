#include<stdlib.h>
#include<stdio.h>
#include"session9_heapsort.h"
#include<time.h>
double time_elapsed(struct timespec* start,struct timespec* end);

int main()
{
	int n;
	struct timespec start,end;
	/*struct timespec start1, end1;
	double time1;*/
	scanf("%d\n", &n);
	Data* arr = (Data*)malloc(sizeof(Data)*(n+1));  //array indices ranges from 1 to n
	//printf("enter elements\n");
	for (int i = 1;i <=n;i++)       //take input
	{
		scanf("%d", &arr[i].id);
		scanf("%d", &arr[i].value);
	}
	//we have to sort by id
	clock_gettime(CLOCK_REALTIME,&start);
	HeapSort(arr,n);
	clock_gettime(CLOCK_REALTIME,&end);
	for (int i = 1;i <=n;i++)       //print sorted array
	{
		printf("%d ", arr[i].id);
		printf("%d\n", arr[i].value);
	}
	printf("%lf\n",time_elapsed(&start,&end));
	free(arr);
}
	double time_elapsed(struct timespec* start,struct timespec* end)
{
	double t;
	t=end->tv_sec-start->tv_sec;
	t+=(end->tv_nsec-start->tv_nsec)*0.000000001;
	return t;
}

