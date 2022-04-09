#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "includes.h"

#define MAX_VALUE 100

int* IS(int* A, int n); /* Insertion Sort */

int* SS(int* A, int n); /* Selection Sort */

int* BS(int* A, int n); /* Bubble Sort */

int* HS(int* A, int n); /* Heap Sort */
void maxHeapify(int* A, int n, int i);
int* heapify(int* A, int n);

int* QS(int* A, int n); /* Quick Sort */
int* QSR(int* A, int l, int r);
int partition(int* A, int l, int n);

int* MS(int* A, int n); /* Merge Sort */
int* MSR(int* A, int n, int l = 0);
void merge(int* A, int l, int m, int r);

int* ShS(int* A, int n); /* Shell Sort */

int* CS(int* A, int n); /* Counting Sort */

#endif