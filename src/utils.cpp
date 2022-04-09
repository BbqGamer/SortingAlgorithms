#include "utils.h"
#include <iostream>

int * randomArray(int n, int min = 0, int max = 100, char type)
{
    srand(time(0));
    int * A = new int[n];

    switch (type) {
    case 'r': {
        for(int i = 0; i < n; i++) {
            A[i] = (rand()%max+1-min)+min;
        }
        break;
    }
    case 'c': {
        int c = (rand()%max+1-min)+min;
        for(int i = 0; i < n; i++) {
            A[i] = c;
        }
        break;
    }
    case 'i': {
        int num = max - n + 1;
        for(int i = 0; i < n; i++) {
            A[i] = num;
            num += 1;
        }
        break;
    }
    case 'd': {
        int num = max;
        for(int i = 0; i < n; i++) {
            A[i] = num;
            num -= 1;
        }
        break;
    }
    case 'A': {
        for(int i = 0; i < n/2; i++) {
            A[i] = (i+1) * 2 + 1;
        }
        for(int i = n/2; i < n; i++) {
            A[i] = (n-i)*2;
        }
        break;
    }
    case 'V': {
        for(int i = 0; i < n/2; i++) {
            A[i] = (n/2-i)*2+1;
        }
        for(int i = n/2; i < n; i++) {
            A[i] = (i-n/2)*2;
        }
        break;
    }
    default:
        break;
    }

    return A;
}

void printArray(int * A, int n) {
    for(int i = 0; i < n; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

int* copyArray(int* A, int n) {
    int * B = new int[n];
    for(int i = 0; i < n; i++) {
        B[i] = A[i];
    }
    return B;
}


void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c; 
}

bool compare(int* A, int* B, int n) {
    for(int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            return 0;
        } 
    }
    return 1;
}


float measureAlg(sortingFunction f, int* A, int n) {
    clock_t start, end;
    double cpu_time_used;
     
    start = clock();
    
    f(A, n);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}