#include<stdio.h>
#include<stdlib.h>
#include"session6_quicksort.h"

//Quick Sort
//Use Quick Sort algorithm to sort the array an of records by their id.
void QuickSort(Data* A, int n)
{
	if(n<=1)                      //base case
		return ;
	//printf("into quick");
	int s=Partition(A, n);// s contains the index
	//printf("%d",s);
	QuickSort(A,s-1);
	QuickSort(A+s+1,n-s-1);
	return;
}



//Hoare Partition
//Partitions the array on a pivot element and returns the index of the 
// pivot element in the partitioned array of records
int Partition(Data * A, int n)
{
	int p=A[0].id;// pivot is first element
	int i=1;
	int j=n-1;
	while(i<=j)   //i goes from left to right, j goes from right to left
	{
		while(i<=j && A[i].id<p)
			i++;
		while(i<=j && A[j].id>=p)
			j--;
		if(i<j)
		{
			swap(A,i,j);
			i++;
			j--;
		}
	}
	swap(A,j,0);
	return j;
}

void swap(Data* A,int i,int j)
{
  Data temp;
  temp=A[i];
  A[i]=A[j];
  A[j]=temp;
}
