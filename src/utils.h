#ifndef UTILS_H
#define UTILS_H

typedef int* (*sortingFunction)(int*, int);

int* randomArray(int n, int min, int max, char type='r'); /* generates new array */
void printArray(int * A, int n); /* prints array to the console */
int* copyArray(int* A, int n);

void swap(int* a, int * b);
bool compare(int* A, int* B, int n);

float measureAlg(sortingFunction f, int* A, int n);

#endif