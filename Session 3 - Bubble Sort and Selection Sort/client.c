#include<stdio.h>
#include<stdlib.h>
#include"session3_bubbleselection.h"

int main()
{
  int n,k;
  //printf("enter number of entries\n");
  scanf("%d",&n);
  Data arr1[n];
  Data arr2[n];
  for(int i=0;i<n;i++)       //take input and make a copy of the same array
  {
    scanf("%d",&arr1[i].id);
    scanf("%d",&arr1[i].value);
  }
  copy(arr1,arr2,n);
  //printf("enter k\n");
  scanf("%d",&k);        //position at which the sorting should should make a copy and return
  Data* ptrToArrayK1,*ptrToArrayK2;
  ptrToArrayK1=BubbleSort(arr1,n,k);//returns copy of arr after k iterations
  display(ptrToArrayK1,n);
  display(arr1,n);    //displays bubble sorted array
  // for( int i = 0 ; i < n; i++){
  //       free(&ptrToArrayK1[i]);}
    //printf("%p",ptrToArrayK1);
     free(ptrToArrayK1);
//free(ptrToArrayK1);

  ptrToArrayK2=SelectionSort(arr2,n,k);//returns copy of arr after k iterations
  display(ptrToArrayK2,n);
  display(arr2,n);

  // for(int i = 0 ; i < n; i++){
  //       free(&ptrToArrayK2[i]);}
     free(ptrToArrayK2);
}