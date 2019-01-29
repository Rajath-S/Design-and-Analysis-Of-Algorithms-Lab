#include"session3_bubbleselection.h"
#include<stdlib.h>
#include<stdio.h>
//Bubble Sort
//Use Bubble Sort algorithm to sort the array of length with respect to their values.
//Return a copy of the array of objects of struct data after k passes.
Data* BubbleSort(Data* A, int n, int k)
{
  int noSwaps;
  Data* copyatk=(Data*)malloc(n*sizeof(Data));
  //note that even if k is greater than n it has to print out the sorted array after
  if(n==1)
  {
    copy(A,copyatk,1);
    return copyatk;
  }

  for(int i=0;i<n-1;i++)
  {
    //printf("iteration %d in bubble sort\n",i);


    if(i==k)
    {
      copy(A,copyatk,n);
    }
    noSwaps=1;
               //note that we use noswaps here to stop iterations if everything is aldready sorted
    for(int j=0;j<n-1-i;j++)
    {
      if(A[j].value>A[j+1].value)
      {
      swap(A,j,j+1);
      noSwaps=0;
      }
    }
    if(noSwaps==1)
      return copyatk;
  }

}
//displays the array
void display(Data* A,int n)
{
  for(int i=0;i<n;i++)
  {
    printf("%d ",A[i].id);
    printf("%d\n",A[i].value);
  }
  //printf("\n");
}
void swap(Data* A,int i,int j)
{
  Data temp;
  temp=A[i];
  A[i]=A[j];
  A[j]=temp;
}
//copy array1 to array2
void copy(Data* array1,Data* array2,int n)
{
  for(int i=0;i<n;i++)
  {
    array2[i]=array1[i];
  }
}


//Selection Sort
//Use Selection Sort algorithm to sort the array of length with respect to their values.
//Return a copy of the array of objects of struct data after k passes.
Data* SelectionSort(Data * A, int n, int k)
{
  int min;
  Data* copya=(Data*)malloc(n*sizeof(Data));
  if(n==1)
  {
    copy(A,copya,1);
    return copya;
  }

  for(int i=0;i<n-1;i++)
  {
    printf("iteration %d in selection sort",i);
    if(i==k)
    {
      copy(A,copya,n);
    }
    min=i;
    for(int j=i+1;j<n;j++)
    {
      if(A[j].value<A[min].value)
        min=j;

    }
    swap(A,i,min);
  }
  return copya;
}
