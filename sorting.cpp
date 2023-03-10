//Name: David Adeyeye
//ID: 0680640
// Assignment 4

#include<stdio.h>
#include <time.h>
#include <stdlib.h>



//declare functions

int read(int[], char[]);

int bubbleSort(int[], int);

void swap(int *, int *);

void write(int[], int, int);

int selectionSort(int[], int);

int heapSort(int[], int);

void heapify(int[], int, int);

//main function

int main()
{
	int i;
	int	j;
	int	c,
	int	arr[50000];
	int	num;
	int	l;
	int	bubbleCount;
	int s;
	int	selectionCount;
	int	heapCount;

	//initiate array to hold characters
	char n[6];
	//create file object & open file in write mode
	FILE *fp;

	fp = fopen("file.txt", "w");



	// Random number generator

	srand(time(0));
	for (i = 0; i < 50000; i++)
	{

		//Random numbers between 1 and 50000
	j = rand() % 10000;
		//save the number into a txt file
		fprintf(fp, "%d\n", j);

	}

	//copy numbers from txt file into the array

	l = read(arr, n);

	//bubble sort the array

	bubbleCount = bubbleSort(arr, l);

	//put result into an array

	write(arr, l, 1);

	//obtain random number from the txt file

	l = read(arr, n);

	//apply selection sort 

	selectionCount = selectionSort(arr, l);

	//write result into another file

	write(arr, l, 2);

	//as array is sorted, so we have to read again random numbers

	l = read(arr, n);

	//this time heapsort

	heapCount = heapSort(arr, l);

	//write result back to the file

	write(arr, l, 3);

	//print the result in tabular formate

	printf("%20s", "BubbleSort");

	printf("%20s", "SelectionSort");

	printf("%20s", "HeapSort");

	printf("\n");

	printf("%20d%20d%20d", bubbleCount, selectionCount, heapCount);

	printf("\n\n");

	//create a comparision file and write result into that

	fp = fopen("comparision.txt", "w");

	fprintf(fp, "%s %s %s\n", "BubbleSort", "SelectionSort", "HeapSort");

	fprintf(fp, "%d %d %d\n", bubbleCount, selectionCount, heapCount);

	fclose(fp);

}

//read function, to read values from the file to array

int read(int arr[], char n[])

{

	int k = 0, l = 0, num, c;

	//open file, (file of random numbers)

	FILE *fp = fopen("file.txt", "r");

	k = 0;

	l = 0;

	//loop

	while (1) {

		//get character

		c = fgetc(fp);



		//if end of file reached , then break loop

		if (feof(fp)) {

			break;

		}

		//if character is newline

		if (c == '\n')

		{

			//atoi converts char* to int.

			num = atoi(n);

			//assing number to array

			arr[l] = num;

			//increase index

			l++;

			k = 0;

		}

		//make string from characters

		n[k] = c;

		k++;

	}

	fclose(fp);

	//return length of array

	return l;

}

//bubble sort

int bubbleSort(int arr[], int n)

{

	int i, j, bubleCount = 0;

	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place

		for (j = 0; j < n - i - 1; j++)

		{

			if (arr[j] > arr[j + 1])

				swap(&arr[j], &arr[j + 1]);

			bubleCount++;

		}

	return bubleCount;

}

//swap by taking reference of variables

void swap(int *x, int *y)

{

	int temp = *x;

	*x = *y;

	*y = temp;

}

//write function, writes the result back into the file

void write(int arr[], int n, int val)

{

	int i;

	//create file object

	FILE *fp;



	//create file according to the value passed

	if (val == 1)

		fp = fopen("bubbleSort.txt", "w");

	else if (val == 2)

		fp = fopen("selectionSort.txt", "w");

	else

		fp = fopen("heapSort.txt", "w");

	//write all the values of sorted array into the file

	for (i = 0; i < n; i++)

	{

		fprintf(fp, "%d\n", arr[i]);

	}

}

//selection sort algorithm

int selectionSort(int arr[], int n)

{

	int i, j, min_idx, cnt = 0;

	// One by one move boundary of unsorted subarray

	for (i = 0; i < n - 1; i++)

	{

		// Find the minimum element in unsorted array

		min_idx = i;

		for (j = i + 1; j < n; j++)

		{

			if (arr[j] < arr[min_idx])

				min_idx = j;

			cnt++;

		}

		// Swap the found minimum element with the first element

		swap(&arr[min_idx], &arr[i]);

	}

	return cnt;

}

int heapSort(int arr[], int n)

{

	int i, hcnt = 0;

	// Build heap (rearrange array)

	for (i = n / 2 - 1; i >= 0; i--)

		heapify(arr, n, i);

	// One by one extract an element from heap

	for (i = n - 1; i >= 0; i--)

	{

		// Move current root to end

		swap(&arr[0], &arr[i]);

		// call max heapify on the reduced heap

		heapify(arr, i, 0);

		hcnt++;

	}

	return hcnt;

}

void heapify(int arr[], int n, int i)

{

	int largest = i; // Initialize largest as root

	int l = 2 * i + 1;

	int r = 2 * i + 2;

	// If left element is larger than root

	if (l < n && arr[l] > arr[largest])

		largest = l;

	// If right element is larger than largest so far

	if (r < n && arr[r] > arr[largest])

		largest = r;

	// If largest is not root

	if (largest != i)

	{

		swap(&arr[i], &arr[largest]);

		heapify(arr, n, largest);

	}

}