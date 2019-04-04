//Insertion Sort
//Sorts the array of Records on the serialnumber field using the Insertion Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int InsertionSort(Record* A, int n)
{
	int temp;
	long int count=0;
	for(int i=1;i<n;i++)
	{
		temp=A[i].serialnumber;
		j=i-1;
		while(j>=0 && ++count &&A[j].serialnumber>temp)
		{

			A[j+1].serialnumber=A[j].serialnumber;
			j=j-1;
		}
		A[j+1].serialnumber=temp;
	}
}

//Bubble Sort
//Sorts the array of Records on the serialnumber field using the Bubble Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int BubbleSort(Record* A, int n);

//Selection Sort
//Sorts the array of Records on the serialnumber field using the Selection Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int SelectionSort(Record* A, int n);

//Merge Sort
//Sorts the array of Records on the serialnumber field using the Merge Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int MergeSort(Record* A, int n);

//Quick Sort
//Sorts the array of Records on the serialnumber field using the Quick Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int QuickSort(Record* A, int n);