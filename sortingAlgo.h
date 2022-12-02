#pragma once
#include "commands.h"

void countBubbleSort(int arr[], int n, long long& countCmp);
void bubbleSort(int arr[], int n);
void shellSort(int a[], int n);
void countShellSort(int a[], int n, long long& c);
void insertionSort(int a[], int n);
void countInsertionSort(int a[], int n, long long& c);
void countShakerSort(int a[], int n, long long& c);
void shakerSort(int a[], int n);
int findIndexofLargest(int a[], int size);
int countFindIndexofLargest(int a[], int size, long long& countCmp);
void selectionSort(int a[], int n);
void countSelectionSort(int a[], int n, long long& countCmp);
int countGetMax(int* a, int n, long long& countCmp);
int getMax(int* a, int n);
void countSortDigit(int*& a, int n, int d, long long& countCmp);
void SortDigit(int*& a, int n, int d);
void countRadixSort(int*& a, int n, int d, long long& countCmp);
void radixSort(int*& a, int n, int d);
int Median(int a[], int l, int r);
int countMedian(int a[], int l, int r, long long& countCmp);
int patrition(int a[], int l, int r);
int countPatrition(int a[], int l, int r, long long& c);
void quickSort(int a[], int l, int r);
void countQuickSort(int a[], int l, int r, long long& c);
void countMerge(int*& a, int left, int mid, int right, long long& countCmp);
void Merge(int*& a, int left, int mid, int right);
void countMergeSort(int*& a, int left, int right, long long& countCmp);
void mergeSort(int*& a, int left, int right);
void swap(int& a, int& b);
void countHeapRebuild(int*& a, int k, int n, long long& countCmp);
void heapRebuild(int*& a, int k, int n);
void countHeapConstruct(int*& a, int n, long long& countCmp);
void heapConstruct(int*& a, int n);
void countHeapSort(int*& a, int n, long long& countCmp);
void heapSort(int*& a, int n);
void flashSort(int a[], int n);
void countFlashSort(int a[], int n, long long& c);
int getMin(int a[], int n);
int countGetMin(int a[], int n, long long& countCmp);
void countingSort(int a[], int n, int min, int max);
void countCountingSort(int a[], int n, int min, int max, long long& countCmp);


