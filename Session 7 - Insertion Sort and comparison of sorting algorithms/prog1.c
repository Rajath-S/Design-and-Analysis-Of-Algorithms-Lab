#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

/*typedef struct Record {
	long int serialnumber;
	int score;
} Record;*/

typedef struct Record {
	long int sno;
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
		while((j>=0) && (++count && A[j].sno >= temp.sno))
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = temp;
	}
	return count;
}

/*long int InsertionSort(record* a, int n)
{
	long int cnt = 0;
	for(int i=1;i<n;i++)
	{
		record temp = a[i];
		int j = i-1;
		while(j>=0 && (++cnt && a[j].sno >= temp.sno))
		{
			
			a[j+1] = a[j];
			j=j-1;
		
		}
		a[j+1] = temp;
	}
	return cnt;
}*/


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
			if(++count && (a[j].sno > a[j+1].sno))
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
/*			if(++cnt && a[j].sno < a[min].sno){
				min = j;}*/
			if(a[j].sno < a[min].sno)
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
		if(++(*cnt) && (A[i].sno)<=(A[j].sno))
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
	if(((a[n/2].sno>a[0].sno) && (a[n/2].sno<a[n-1].sno))||((a[n/2].sno<a[0].sno) && (a[n/2].sno>a[n-1].sno)))
	{
		temp=a[0];
		a[0]=a[n/2];
		a[n/2]=temp;
	}
	if(((a[n-1].sno>a[0].sno) && (a[n-1].sno<a[n/2].sno))||((a[n-1].sno<a[0].sno) && (a[n-1].sno>a[n/2].sno)))
	{
		temp=a[0];
		a[0]=a[n-1];
		a[n-1]=temp;
	}
	
	int i=1,j=n-1;
	while(i<=j)
	{

		while( i<=j && (++(*cnt) && a[i].sno<a[0].sno))
		{

			i=i+1;
		}
		while(  i<=j  && (++(*cnt)  && a[j].sno>a[0].sno ))
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

int main()
{
	struct timespec istart,iend,bstart,bend,sstart,send,mstart,mend,qstart,qend;
	int n;
	scanf("%d",&n);
	record *A=(record*)malloc(n*sizeof(record));
	record *B=(record*)malloc(n*sizeof(record));
	record *C=(record*)malloc(n*sizeof(record));
	record *D=(record*)malloc(n*sizeof(record));
	record *E=(record*)malloc(n*sizeof(record));
	for(int i=0;i<n;i++)
	{
		scanf("%ld",&A[i].sno);
		scanf("%d",&A[i].score);
		B[i]=A[i];
		C[i]=A[i];
		D[i]=A[i];
		E[i]=A[i];
	}
	
	clock_gettime(CLOCK_REALTIME,&istart);
	long int i_count=InsertionSort(A,n);
	clock_gettime(CLOCK_REALTIME,&iend);
	double time_i=(iend.tv_sec-istart.tv_sec)+(iend.tv_nsec-istart.tv_nsec)*pow(10, -9);
	
	clock_gettime(CLOCK_REALTIME,&bstart);
	long int b_count=BubbleSort(B,n);
	clock_gettime(CLOCK_REALTIME,&bend);
	double time_b=(bend.tv_sec-bstart.tv_sec)+(bend.tv_nsec-bstart.tv_nsec)*pow(10, -9);
	
	clock_gettime(CLOCK_REALTIME,&sstart);
	long int s_count=SelectionSort(C,n);
	clock_gettime(CLOCK_REALTIME,&send);
	double time_s=(send.tv_sec-sstart.tv_sec)+(send.tv_nsec-sstart.tv_nsec)*pow(10, -9);
		
	clock_gettime(CLOCK_REALTIME,&mstart);
	long int m_count=MergeSort(D,n);
	clock_gettime(CLOCK_REALTIME,&mend);
	double time_m=(mend.tv_sec-mstart.tv_sec)+(mend.tv_nsec-mstart.tv_nsec)*pow(10, -9);
		
	clock_gettime(CLOCK_REALTIME,&qstart);
	long int q_count=QuickSort(E,n);
	clock_gettime(CLOCK_REALTIME,&qend);
	double time_q=(qend.tv_sec-qstart.tv_sec)+(qend.tv_nsec-qstart.tv_nsec)*pow(10, -9);	
	
	printf("Insertion Sort: %ld %lf \n",i_count,time_i);
	printf("Bubble Sort: %ld %lf \n",b_count,time_b);
	printf("Selection Sort: %ld %lf \n",s_count,time_s);
	printf("Merge Sort: %ld %lf \n",m_count,time_m);
	printf("Quick Sort: %ld %lf \n",q_count,time_q);
	
	return 0;
}
