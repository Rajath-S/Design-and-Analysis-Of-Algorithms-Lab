#include<stdlib.h>
#include<stdio.h>
#include"session9_heapsort.h"
int main()
{
	int n;
	/*struct timespec start1, end1;
	double time1;*/
	scanf("%d\n", &n);
	Data* arr = (Data*)malloc(sizeof(Data)*(n+1));
	//printf("enter elements\n");
	for (int i = 1;i <=n;i++)       //take input
	{
		scanf("%d", &arr[i].id);
		scanf("%d", &arr[i].value);
	}
	//we have to sort by id
	HeapSort(arr,n);
	for (int i = 1;i <=n;i++)       //print sorted array
	{
		printf("%d ", arr[i].id);
		printf("%d\n", arr[i].value);
	}
	
	free(arr);

}