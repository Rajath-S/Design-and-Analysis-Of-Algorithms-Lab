#include"session3_bubbleselection.h"

//Bubble Sort
//Use Bubble Sort algorithm to sort the array of length with respect to their values.
//Return a copy of the array of objects of struct data after k passes.
Data* BubbleSort(Data* A, int n, int k)
{
  int noSwaps;
  Data* arr_k=malloc()
  for(int i=0;i<n-1;i++)
  {
    noSwaps=1;
    for(j=0;j<n-1-i;j++)
    {
      if(A[j]>A[j+1])
      {
      swap(A,j,j+1);
      noSwaps=0;
      }
    }
    if(noSwaps==1)
      return
  }
}


//Selection Sort
//Use Selection Sort algorithm to sort the array of length with respect to their values.
//Return a copy of the array of objects of struct data after k passes.
Data* SelectionSort(Data * A, int n, int k)
{
  int min;
  for(int i=0;i<n-1;i++)
  {
    min=i;
    for(int j=i+1;j<n;j++)
    {
      if(A[j]->value<A[min]->value)
        min=j;
      swap(A,i,min);
    }
    return A;
  }

}
