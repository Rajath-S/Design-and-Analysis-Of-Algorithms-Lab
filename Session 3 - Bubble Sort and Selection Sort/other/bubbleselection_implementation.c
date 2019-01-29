#include "session3_bubbleselection.h"
#include <stdlib.h>

Data* BubbleSort(Data* A, int n, int k)
{
	int swap  = 1;
	int copyK = 0;
	Data * copyA = (Data *)malloc(sizeof(Data)*n);
	for(int i = 0;i<n;i++)
	{
		copyA[i].value = A[i].value;
		copyA[i].id = A[i].id;
	}
	Data t;
	for(int i = n-1 ;(i>=0)&&(swap)&&(copyK<k);i--,copyK++)
	{
		swap = 0;
		for(int j = 0;j<i;j++)
		{
			if(copyA[j].value>copyA[j+1].value)
			{
				swap = 1;
				t = copyA[j];
				copyA[j] = copyA[j+1];
				copyA[j+1] = t;
			} 
		}
	}
	return copyA;
}


Data* SelectionSort(Data * A, int n, int k)
{
	int copyK = 0;
	Data * copyA = (Data *)malloc(sizeof(Data)*n);
	for(int i = 0;i<n;i++)
	{
		copyA[i].value = A[i].value;
		copyA[i].id = A[i].id;
	}
	int min;
	Data temp;
	for(int i = 0;i<n-1 && copyK<k;i++,copyK++)
	{
		//temp = i;
		min = i;
		for(int j = i+1;j<n;j++)
		{
			if(copyA[j].value<copyA[min].value)
			{
				min = j;
			}
		}
		temp = copyA[i];
		copyA[i] = copyA[min];
		copyA[min] = temp;
	}
	return copyA;
}
