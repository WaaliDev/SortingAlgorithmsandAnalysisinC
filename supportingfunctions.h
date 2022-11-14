#pragma once
#include<stdio.h>
#define MAX_SIZE 20
#define TRUE 1
#define FALSE 0

int less(int i, int j); 
void swap(int array[], int i, int j); 
void initArray(int* array, int k);
void printArray(int array[]); 
void basicSort(int array[], int k); 
void selectionSort(int array[]);
void insertionSort(int array[]);
void shellSort(int array[]);
void mergesort(int array[], int l, int r);
void quicksort(int array[], int l, int r);
void merge(int array[], int l, int m, int r);
int partition(int array[], int l, int r);
void mergeBU(int array[], int l, int m, int r);
void mergesortBU(int array[], int arraySize);
void showMergeCandM();
void showQuickSortCandS();
void showMBU(); 