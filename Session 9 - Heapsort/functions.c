#include"session9_heapsort.h"
#include<stdlib.h>
#include<stdio.h>
void swap(Data* A, int i, int j);
void Heapify(Data* A, int n, int k);
void HeapSort(Data* A, int n)
{
	void HeapBottomUp(A,n);  //construct a max heap from an unsorted array
	for (int i = n;i <= 2;i--)
	{
		swap(A,1,i);
		Heapify(A, i - 1, 1); // We shrink the size by one
	}
}
//building a heap
void HeapBottomUp(Data * A, int n)   //note that this function takes o(n) time
{
	if (n <= 1)
		return;
	for (int i = n / 2;i >= 1;i--)
		Heapify(A, n, i);
}
void swap(Data* A, int i, int j)
{
	Data temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void Heapify(Data* A, int n, int k)   //k is the root from which if has to heapify downward
{
	if (2*k > n) return;  //this checks if left child exists
	int j = 2 * k;//j is index of left child
	if (j + 1 <= n)//check if right child exists
	{
		if (A[j + 1].id > A[j].id)
		{
			j = j + 1;
		}
		if (A[j].id > A[k].id)
		{
			swap(A, j, k);
			Heapify(A, n, j);
		}
	}
}
