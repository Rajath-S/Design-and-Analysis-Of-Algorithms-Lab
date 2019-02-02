#include"session5_mergesort_binsearch.h"
#include<stdio.h>
#include<stdlib.h>
void display(Data* A,int n)
{
  for(int i=0;i<n;i++)
  {
    printf("%d ",A[i].id);
    printf("%d\n",A[i].value);
  }
}
void merge(Data* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    Data L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i].value <= R[j].value)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(Data* arr, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
/*
//Merge Sort
//Use Merge Sort algorithm to sort the array of length with respect to their values.
void MergeSort(Data* A, int l,int r,int n)
{
  int n=r-l+1;
  if(n<1)
    return;
  int m=(l+r)/2;   //this automaticlaly floors the value
  MergeSort(A,l,m-1);
  MergeSort(A,m,n-1);
  Merge(A,l,r,m);
}
void Merge(Data* A, int l,int r,int m)
{
    int i=l;
    int j=m;
    int k=0; //index of the third array
    int n=r-l+1;
    Data B[n];
    while(i<m && j<n)   //merging two arrays
    {
      if(A[i].value<A[j].value)
      {
        B[k]=A[i];
        i+=1;
      }
      else
      {  B[k]=A[j];
        j+=1;
      }
      k+=1;
    }
    if(j==n)//if the second array elements are all done
    {
      for(int ele=i;ele<m;ele++,k++)
      {
        B[k]=A[ele];
      }
    }
    else
    {
      for(int ele=j;ele<n;ele++,k++)
      {
        B[k]=A[ele];
      }
    }
    for(int ele=0,k=0;ele<n;ele++,k++) // in the end copy all elements to original array after arranging
    {
      A[ele]=B[k];
    }
}

*/
//Binary Search
//Returns the index of one of the records of A which matches key_value with 'value'

int BinarySearch(Data* arr, int l, int r, int x)
{
    if (l<=r) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid].value == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid].value > x)
            return BinarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return BinarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}
