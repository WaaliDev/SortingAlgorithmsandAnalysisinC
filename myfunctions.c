#pragma once
#include"supportingfunctions.h"
int less(int i, int j) {
	if (i < j)
		return TRUE;
	else
		return FALSE;
}
void swap(int array[], int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/*void merge(int left[], int right[], int parent[]) {    // helper function for mergeSort
	int halfSize = MAX_SIZE/ 2; 
	int i=0, j=0, k = 0; // iterators for 3 arrays
	while (i < halfSize && j < halfSize) {
		if (left[i] < right[j]) {     // first case elements from left array to parent array
			parent[k] = left[i];
			i++; 
		}
		else {                        // 2nd case elements from right array to parent array
			right[j] = parent[k];
			j++;
		}
		k++; 
	}
	// leftover elements, most of the times one array will get finished first
	while (i < halfSize) {     // as the elements are already sorted in sub arrays 
		parent[k] = left[i]; 
		k++; 
		i++; 
	}
	while (j < halfSize) {
		parent[k] = right[i]; 
		k++; 
		j++; 
	}

}
*/
void basicSort(int array[], int k) {
	for (int i = 0; i < (MAX_SIZE - k); i++) {
		for (int j = i; j > 0; j--) {
			if (less(array[j], array[j - 1]) == TRUE) {
				swap(array, j, j-1);
			}
			else
				break;
		}
	}
}

void initArray(int* array, int k) {
	for (int i = 0; i < MAX_SIZE; i++) {    //initializing the array from 1 to Max_size
		array[i] = i + 1;
	}
	int randomIndex;
	int temp = 0;
	for (int i = MAX_SIZE - k; i < MAX_SIZE; i++) {    // k many elements randomly at the end of array
		randomIndex = rand() % (MAX_SIZE-1)+1;
		int temp = array[i];
		array[i] = array[randomIndex];
		array[randomIndex] = temp;
	}
	basicSort(array, k); 
}

void printArray(int array[]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d  ", array[i]);
	}
}
int miOfIterator=-1; 
int S_comparisons = 0, S_exchanges = 0;
int minOf(int array[], int startingPosition) {
	int comparison=0, exchanges=0; 
	miOfIterator++; 
	int i;
	for (i = (MAX_SIZE - 1); i > startingPosition; i--) {      //we are swapping and pusing the smallest element to go to end
		S_comparisons++; 
		if (array[i] < array[i - 1]) {
			swap(array, i, i-1); 
			S_exchanges++; 
		}
	}
	return array[miOfIterator];
}

void selectionSort(int array[]) {
	for (int i = 0 ; i < MAX_SIZE ; i++) {
		array[i] = minOf(array, i);
	}
	printf("\n*****Selection Sort*****\n");
	printf("Comparisons: %d\n", S_comparisons);
	printf("Exchanges: %d\n", S_exchanges);
	
}

void insertionSort(int array[]) {
	int comparisons = 0, exchanges = 0;
	int j; 
	for (int i = 0; i < MAX_SIZE; i++) {
		j = i; 
		while (j > 0) {
			comparisons++; 
			if (array[j] < array[j - 1]) {
				swap(array, j - 1, j);
				exchanges++;
			}
			j--; 
		}
	}
	printf("******Insertion Sort******\n");
	printf("Comparisons: %d", comparisons); 
	printf("Exchanges: %d", exchanges); 
}


void shellSort(int array[]) {
	/*I have used seperate blocks so that I don't need to use different variables because the scope is limited witin the block*/
	// block for the gap of even iterations from 0,2,4,6.....
	int comparisons = 0, exchanges = 0; 
	{
		int j;
		for (int i = 0; i < MAX_SIZE; i=i+2) {
			j = i;
			while (j > 0) {
				comparisons++;
				if (array[j] < array[j - 2]) {
					swap(array, j - 2, j);
					exchanges++; 
				}
				j = j - 2;
			}
		}
	}
	// block for the gap of odd from 1,3,5,7.....
	{
		int j;
		for (int i = 1; i < MAX_SIZE; i=i+2) {
			j = i;
			while (j > 0) {
				comparisons++; 
				if (array[j] < array[j - 2]) {
					swap(array, j - 2, j);
					exchanges++;
				}
				j= j-2;
			}
		}
	}
	// block for the comparison of the rest of elements
	{
		int j;
		for (int i = 0; i < MAX_SIZE; i++) {
			j = i;
			comparisons++; 
			while (j > 0) {
				if (array[j] < array[j - 1]) {
					swap(array, j - 1, j);
					exchanges++;
				}
				j--;
			}
		}
	}
	printf("\n*****Shell Sort*****\n");
	printf("Comparisons: %d\n", comparisons);
	printf("Exchanges: %d\n", exchanges);

}

/*int mergeSort(int array[], int size) {
	printf("Size %d\n", size);
	if (size < 2) {       // recurisve condition
		return 0; 
	}
	else {
		/* >> Divide the array into two parts - left part and the right part
		   >> By recursion keep dividing the array until the sub arrays have only one element remaining 
		   >> Call the merge function
		
		
		int halfSize = size / 2; 
		printf("HalfSize %d", halfSize);
		int* left = (int*)malloc(halfSize*sizeof(int));                         // because normal array needs constant size we are using dynamic memory allocation
		int* right = (int*)malloc((size-halfSize) * sizeof(int));
		mergeSort(left,halfSize);
		mergeSort(right,size-halfSize);
		merge(array, left, right);
			
		free(left);
		free(right);
		}
		
}
*/
int mComparisons = 0, mMerges = 0; 
void mergesort(int array[], int l, int r) {
	// End of recursion reached?
	if (l >= r)
		return;
	int m = l + (r - l) / 2;
	mergesort(array, l, m);
	mergesort(array, m + 1, r);
	merge(array, l, m, r);
}
void merge(int array[], int l, int m, int r) {
	int i, j, k;
	int leftSize = m - l + 1;
	int rightSize = r - m;

	/* create temp arrays */
	int leftArray[MAX_SIZE], rightArray[MAX_SIZE];

	/* Copy data to temp arrays leftArray[] and rightArray[] */
	for (i = 0; i < leftSize; i++)
		leftArray[i] = array[l + i];
	for (j = 0; j < rightSize; j++)
		rightArray[j] = array[m + 1 + j];

	/* Merge the temp arrays back into array[l..r]*/
	// Initial index of first subarray
	i = 0;
	// Initial index of second subarray
	j = 0;
	// Initial index of merged subarray
	k = l;

	while ((i < leftSize) && (j < rightSize)) {
		mComparisons++; 
		if (leftArray[i] <= rightArray[j]) {
			array[k] = leftArray[i];
			i++;
		}
		else {
			array[k] = rightArray[j];
			j++;
		}
		k++;
		mMerges++;
	}

	/* Copy the remaining elements of left side[], if there	are any */
	while (i < leftSize) {
		array[k] = leftArray[i];
		i++;
		k++;
		mMerges++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < rightSize) {
		array[k] = rightArray[j];
		mMerges++; 
		j++;
		k++;
	}
}
void showMergeCandM() {
	printf("\n*****Merge Sort*****"); 
	printf("\nComparsions: %d\n", mComparisons); 
	printf("Merges: %d\n", mMerges); 
}


/*int partition(int array[], int start, int end) {
	int pivot = array[end];     //selecting the end element as pivot
	int	pivot_index = start;
	for (int i = 0; i < end; i++) {
		if (array[i] <= pivot) {                          //pusing the element on left side which are less than pivot 
			swap(array, i, pivot_index);
			pivot_index++; 
		}
	}
	swap(array, pivot_index,end); 
	return pivot_index;
}

void quickSort(int array[], int start, int  end) {
	if (start < end) {
		int pivot_index = partition(array, start, end);          
		quickSort(array, start, pivot_index - 1);          
		quickSort(array, pivot_index + 1, end);
	}
}
*/
int qComparisons = 0; 
int qSwaps = 0;
void quicksort(int array[], int l, int r) {
	if (r - l <= 0)
		return;
	int m = partition(array, l, r);
	quicksort(array, l, m - 1);
	quicksort(array, m + 1, r);
}

int partition(int array[], int l, int r) {
	int i = l - 1;
	int j = r;
	while (TRUE) {
		// find item on left
		qComparisons++;
		while (less(array[++i], array[r]))
			if (i == r)
				// to swap
				break;
		// find item on right
		while (less(array[r], array[--j]))
			// to swap
			if (j == l)
				break;
		// do pointers cross ?
		if (i >= j)
			break;
		// otherwise do swap
		qSwaps++;
		swap(array, i, j);
	}
	// final swap
	swap(array, i, r);
	qSwaps++;
	// return index of cross point
	return i;
}
void showQuickSortCandS() {
	printf("\n*****Quick Sort*****");
	printf("\nComparsions: %d\n", qComparisons);
	printf("Merges: %d\n", qSwaps);
}

int minimum(int x, int y) {
	return (x < y) ? x : y;
}

int mBUComparisons=0; 
int mBUMerges=0; 
/* Iterative mergesort function to sort arr[0...n-1] */
void mergesortBU(int array[], int arraySize) {
	// For current size of subarrays to be merged
	// curr_size varies from 1 to n/2
	int currSize;
	// For picking starting index of left subarray
	// to be merged
	int leftStart;

	// Merge subarrays in bottom up manner. First merge subarrays of
	// size 1 to create sorted subarrays of size 2, then merge subarrays
	// of size 2 to create sorted subarrays of size 4, and so on.
	for (currSize = 1; currSize <= arraySize - 1; currSize = 2 * currSize) {
		// Pick starting point of different subarrays of current size
		for (leftStart = 0; leftStart < arraySize - 1; leftStart += 2 * currSize) {
			// Find ending point of left subarray. mid+1 is starting
			// point of right
			int mid = minimum(leftStart + currSize - 1, arraySize - 1);

			int right_end = minimum(leftStart + 2 * currSize - 1, arraySize - 1);

			// Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
			mergeBU(array, leftStart, mid, right_end);
		}
	}
}

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */

void mergeBU(int array[], int l, int m, int r) {
	int i, j, k;
	int leftSize = m - l + 1;
	int rightSize = r - m;

	/* create temp arrays */
	int leftPart[MAX_SIZE], rightPart[MAX_SIZE];

	/* Copy data to temp arrays L[] and R[] */
	
	for (i = 0; i < leftSize; i++) {
		leftPart[i] = array[l + i];
	}
	for (j = 0; j < rightSize; j++) {
		rightPart[j] = array[m + 1 + j];
	}

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
	while (i < leftSize && j < rightSize) {
		mBUComparisons++;
		if (leftPart[i] <= rightPart[j]) {
			array[k] = leftPart[i];
			mBUMerges++;
			i++;
		}
		else {
			array[k] = rightPart[j];
			mBUMerges++;
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < leftSize) {
		array[k] = leftPart[i];
		mBUMerges++;
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < rightSize) {
		array[k] = rightPart[j];
		mBUMerges++;
		j++;
		k++;
	}
}
void showMBU() {
	printf("\n*****Merge Bottom up*****");
	printf("\nComparsions: %d\n", mBUComparisons);
	printf("Merges: %d\n", mBUMerges);

}








