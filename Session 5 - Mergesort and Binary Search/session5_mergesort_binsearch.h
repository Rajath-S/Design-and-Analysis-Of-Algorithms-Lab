//Header file for session5_mergesort_binsearch.c

typedef struct Data {
	int id;
	int value;
} Data;

//Merge Sort
//Use Merge Sort algorithm to sort the array of length with respect to their values.
//void MergeSort(Data* A,int l,int r);
//void Merge(Data* A, int l,int r,int n);
void merge(Data* arr, int l, int m, int r);
void mergeSort(Data* arr, int l, int r);
//Binary Search
//Returns the index of one of the records of A which matches key_value with 'value'
int BinarySearch(Data * A, int l,int r,int key_value);

void display(Data* A,int n);
