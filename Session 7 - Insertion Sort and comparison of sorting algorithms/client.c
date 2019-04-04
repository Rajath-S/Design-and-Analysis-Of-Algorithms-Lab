#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"session7_sort.h"
#define nano 1000000000L
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
	for(int i=0;i<n;i++)                               //make 4 copies of original arrays
	{
		scanf("%ld",&A[i].serialnumber);
		scanf("%d",&A[i].score);
		B[i]=A[i];
		C[i]=A[i];
		D[i]=A[i];
		E[i]=A[i];
	}
	//here we have 4 sorting functions and we measure the time of each
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
	
	//We are going to print both the number of comparisons along with the time taken
	printf("Insertion Sort: %ld %lf \n",i_count,time_i);
	printf("Bubble Sort: %ld %lf \n",b_count,time_b);
	printf("Selection Sort: %ld %lf \n",s_count,time_s);
	printf("Merge Sort: %ld %lf \n",m_count,time_m);
	printf("Quick Sort: %ld %lf \n",q_count,time_q);
	
	return 0;
}
