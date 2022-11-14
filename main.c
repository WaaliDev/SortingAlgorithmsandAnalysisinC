#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"supportingfunctions.h"

int main() {
	int myarray[MAX_SIZE];
	initArray(myarray, 5);
	printArray(myarray);

	selectionSort(myarray);
	printArray(myarray);
	initArray(myarray, 5);

	shellSort(myarray); 
	printArray(myarray);
	initArray(myarray, 5);

	mergesort(myarray, 0, MAX_SIZE-1);
	showMergeCandM();
	printArray(myarray);
	initArray(myarray, 5);

	quicksort(myarray, 0, MAX_SIZE - 1); 
	showQuickSortCandS();
	printArray(myarray);
	
	initArray(myarray, 5);

	mergesortBU(myarray, MAX_SIZE);
	showMBU();
	printArray(myarray);
	initArray(myarray, 5);
	
	return 0; 
}