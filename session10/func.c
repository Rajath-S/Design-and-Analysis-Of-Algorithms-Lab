#include "session10_dcs.h"
#include<stdlib.h>
#include<stdio.h>
void Merge(int* A,int m,int n);
int largest(int* A, int n);
int smallest(int* A, int n);
int* DistributionCountingSorting(int* A, int n)
{
	int u=largest(A,n);
	int l=smallest(A,n);
	int* S=(int*)malloc(sizeof(int)*n);
	int* D=(int*)malloc(sizeof(int)*(u-l+1));
	int j=0,i=0;
	for(j=0;j<=u-l;j++)
		D[j]=0;          //initializing the frequency array
	for(i=0;i<n;i++)
		D[A[i]-l]=D[A[i]-l]+1;   //assigning frequencies
	for(j=1;j<=u-l;j++)
		D[j]=D[j-1]+D[j];      //getting cumulative frequencies
	for(i=n-1;i>=0;i--)
	{
		j=A[i]-l;        
		S[D[j]-1]=A[i];
		D[j]=D[j]-1;      //decrementing the cumulative frequency
	}
	return S;
}

void MergeSort(int* A, int n)
{
	if(n<=1) return;
	int m=n/2;
	
	MergeSort(A,m);
	MergeSort(A+m,n-m);
	Merge(A,m,n);
}

void Merge(int* A,int m,int n)
{
	int* B=(int*)malloc(n*sizeof(int));
	int i=0,j=m,x=0,p=0;
	while(i < m && j < n)
	{
		if(A[i] <= A[j])
		{
			B[x]=A[i];
			i++;
		}
		else
		{
			B[x]=A[j];
			j++;
		}
		x++;
	}
	if(j == n)
	{
		while(i<m)
		{
			B[x]=A[i];
			x++;i++;
		}
	}
	else
	{
		while(j<n)
		{
			B[x]=A[j];
			x++;j++;
		}
	}
	for(p=0;p<n;p++)
		A[p]=B[p];
	free(B);
}


int largest(int* A, int n)
{
    int i;
    int max = A[0];
    for (i = 1; i < n; i++)
        if (A[i] > max)
            max = A[i];
 
    return max;
}

int smallest(int* A, int n)
{
    int i;
    int min = A[0];
    for (i = 1; i < n; i++)
        if (A[i] < min)
            min = A[i];
 
    return min;
}
