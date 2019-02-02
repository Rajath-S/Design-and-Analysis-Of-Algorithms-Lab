#include<stdio.h>
#include<stdlib.h>
#include"session5_mergesort_binsearch.h"
#include<time.h>
#define nano 1000000000L
int main()
{
  int n,key;
  //struct timespec start1,end1;
  //double time1;
  scanf("%d\n",&n);
  Data* arr=(Data*)malloc(sizeof(Data)*n);
  //printf("enter elements\n");
  for(int i=0;i<n;i++)       //take input
  {
    scanf("%d",&arr[i].id);
    scanf("%d",&arr[i].value);
  }

  // printf("enter key\n");
  scanf("%d\n",&key);
  //clock_gettime(CLOCK_REALTIME,&start1);
  mergeSort(arr,0,n-1);
  int result=BinarySearch(arr,0,n,key);
  //clock_gettime(CLOCK_REALTIME,&end1);
  display(arr,n);
  if(result)
  {
    printf("%d %d",arr[result].id,arr[result].value);
  }
  else
    printf("NOT FOUND");
  // time1=(end1.tv_sec-start1.tv_sec)+(double)(end1.tv_nsec-start1.tv_nsec)/nano;
  // printf("%lf\n",time1);
  free(arr);

}
