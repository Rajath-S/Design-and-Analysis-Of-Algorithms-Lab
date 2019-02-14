#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"session6_quicksort.h"
#define nano 1000000000L
int main()
{
  int n,key;
  struct timespec start1,end1;
   double time1;
 // printf("enter n\n");
  scanf("%d",&n);
  Data* arr=(Data*)malloc(sizeof(Data)*n);
 // printf("enter elementsall\n");
  /*
  int* a=(int*)malloc(sizeof(int)*n);
   for(int i=0;i<n;i++)   
   {
   	  scanf("%d",&a[i]);	
   	  }*/	
  for(int i=0;i<n;i++)       //take input
  {
    scanf("%d",&(arr[i].id));
    //printf("%d",arr[i].id);
    scanf("%d",&arr[i].value);
    //printf("%d",arr[i].value);
  }
clock_gettime(CLOCK_REALTIME,&start1);
 QuickSort(arr, n);
 clock_gettime(CLOCK_REALTIME,&end1);
   for(int i=0;i<n;i++)       //print sorted array
  {
    printf("%d ",arr[i].id);
    printf("%d\n",arr[i].value);
  }
  printf("\n");
  time1=(end1.tv_sec-start1.tv_sec)+(double)(end1.tv_nsec-start1.tv_nsec)/nano;
  printf("%lf\n",time1);
  
  free(arr);
  
}
