#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h> 	

typedef struct Record {
	long int serialnumber;
	int score;
} record;


long int InsertionSort(record* A, int n)
{
	record temp;
	long int count = 0;
	int j;
	for(int i=1; i<n; i++)
	{
		temp = A[i];
		j = i-1;
		while((j>=0) && (++count && A[j].serialnumber >= temp.serialnumber))
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = temp;
	}
	return count;
}


void Merge(record* A,int n, int m,long int *cnt);
int Partition(record * a, int n,long int *cnt);


long int BubbleSort(record* a, int n)
{
	int swap;
	long int count = 0;
	for(int i=0;i<=n-2;i++)
	{
		swap = 0;
		for(int j=0;j<=(n-2-i);j++)
		{
			if(++count && (a[j].serialnumber > a[j+1].serialnumber))
			{
				record temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				swap=1;
			}	
		}
			if(swap==0)
				return count;	
	}
		return count;
}
		
long int  SelectionSort(record *a, int n)
{
	int min;
	long int cnt=0;
	for(int i=0;i<=n-2;i++)
	{
		min=i;
		for(int j=i+1;j<=n-1;j++)
		{
/*			if(++cnt && a[j].serialnumber < a[min].serialnumber){
				min = j;}*/
			if(a[j].serialnumber < a[min].serialnumber)
			{
				min = j;
			}
			cnt++;
		}
		record temp= a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	return cnt;	
}
long int MergeSort(record* A, int n)
{
	long int cnt = 0;
	if(n<=1)
		return 0;
	int mid = (n/2);
	cnt+=MergeSort(A,mid);
	cnt+=MergeSort(A+mid,n-mid);
	Merge(A,n,mid,&cnt);
	return cnt;
}

void Merge(record* A,int n, int m,long int *cnt)
{
	int i=0;
	int j=m;
	int k=0;
	record *B=(record*)malloc(n*sizeof(record));
	while((i<m)&&(j<n))
	{
		if(++(*cnt) && (A[i].serialnumber)<=(A[j].serialnumber))
		{
			B[k]=A[i];
			i++;
		}
		else
		{
			B[k]=A[j];
			j++;
		}
		k++;
	}
	if(j==n)
	{
		while(i!=m)
		{
			B[k]=A[i];
			i++;
			k++;
		}
	}
	else
	{
		while(j!=n)
		{
			B[k]=A[j];j++;
			k++;
			
		}
	}
	for(int i=0;i<n;i++){
		A[i]=B[i];
	}
}

long int QuickSort(record* a, int n)
{
	
	if(n<=1)
		return 0;
	long int cnt = 0;
	int s = Partition(a,n,&cnt);
	cnt+=QuickSort(a,s);
	cnt+=QuickSort(a+s+1,n-s-1);
	return cnt;
}


int Partition(record * a, int n,long int *cnt)
{
	
	record temp;
	if(((a[n/2].serialnumber>a[0].serialnumber) && (a[n/2].serialnumber<a[n-1].serialnumber))||((a[n/2].serialnumber<a[0].serialnumber) && (a[n/2].serialnumber>a[n-1].serialnumber)))
	{
		temp=a[0];
		a[0]=a[n/2];
		a[n/2]=temp;
	}
	if(((a[n-1].serialnumber>a[0].serialnumber) && (a[n-1].serialnumber<a[n/2].serialnumber))||((a[n-1].serialnumber<a[0].serialnumber) && (a[n-1].serialnumber>a[n/2].serialnumber)))
	{
		temp=a[0];
		a[0]=a[n-1];
		a[n-1]=temp;
	}
	
	int i=1,j=n-1;
	while(i<=j)
	{

		while( i<=j && (++(*cnt) && a[i].serialnumber<a[0].serialnumber))
		{

			i=i+1;
		}
		while(  i<=j  && (++(*cnt)  && a[j].serialnumber>a[0].serialnumber ))
		{

			j=j-1;
		}
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i=i+1;
			j=j-1;
		}
	}
	temp=a[j];
	a[j]=a[0];
	a[0]=temp;
	return j;
}

