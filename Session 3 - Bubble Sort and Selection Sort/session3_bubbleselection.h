//Header file for session3_bubbleselection.c

typedef struct Data {
	int id;
	int value;
} Data;

//Bubble Sort
//Use Bubble Sort algorithm to sort the array of length with respect to their values.
//Return a copy of the array of objects of struct data after k passes.
Data* BubbleSort(Data* A, int n, int k);

//Selection Sort
//Use Selection Sort algorithm to sort the array of length with respect to their values.
//Return a copy of the array of objects of struct data after k passes.
Data* SelectionSort(Data * A, int n, int k);

void display(Data* A,int n);
void swap(Data* a, int i,int j);
void copy(Data* array1,Data* array2,int n);
