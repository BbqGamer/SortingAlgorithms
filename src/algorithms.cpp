#include "algorithms.h"
#include "utils.h"
#include "includes.h"

int* IS(int* A, int n) {
    for (int i = 0; i < n; i++) {
        int j = i;
        while(j > 0 && A[j-1] > A[j]) {
            swap(&A[j], &A[j-1]);
            j--;
        }
    }
    return A;
}


int * SS(int * A, int n) {
    for(int i = 0; i < n; i++) {
        int minI = i;
        for(int j = i; j < n; j++) {
            if (A[j] < A[minI]) {
                minI = j;
            }
        }
        swap(&A[minI], &A[i]);
    }
    return A;
}


int * BS(int* A, int n) {
    for(int i = 0; i < n; i++) {
        bool swapped = 0;
        for(int j = 0; j < n-i-1; j++) {
            if(A[j] >= A[j+1]) {
                swap(&A[j], &A[j+1]);
                swapped = 1;
            }
        }
        if(!swapped) {
            return A;
        }
    }
    return A;
}


int* HS(int* A, int n) {
    heapify(A, n);
    for(int i = n-1; i > 0; i--) {
        swap(&A[i], &A[0]);
        n -= 1;
        maxHeapify(A, n, 0);
    }
    return A;
}

int* heapify(int* A, int n) {
    for(int i = n/2; i >= 0; i--) {
        maxHeapify(A, n, i);
    }
    return A;
}

void maxHeapify(int* A, int n, int current) {
    int left = 2 * current + 1;
    int right = 2 * current + 2;
    int max = current;
    if(left < n && A[left] > A[max]) {
        max = left;
    }
    if(right < n && A[right] > A[max]) {
        max = right;
    }
    if (max != current) {
        swap(&A[current], &A[max]);
        maxHeapify(A, n, max);
    }
}

int* QS(int* A, int n) {
    return QSR(A, 0, n-1);
}

int* QSR(int* A, int l, int r) {
    if (l >= 0 && r >= 0 && l < r) {
        int p = partition(A, l, r);
        QSR(A, l, p);
        QSR(A, p+1, r);
    }
    return A;
}

int partition(int* A, int l, int r) {
    int pivot = A[(l + r) / 2];
    int i = l - 1;
    int j = r + 1;
    while(1) {
        do {
            i += 1;
        } while (A[i] < pivot);
        do {
            j -= 1;
        } while(A[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(&A[i], &A[j]);
    }
}

int* MS(int* A, int n) {
    return MSR(A, n, 0);
}

int* MSR(int* A, int n, int l) {
    if (l < n - 1) {
        int m = (l + n) / 2;
        MSR(A, m, l);
        MSR(A, n, m);
        merge(A, l, m, n);
    }
    return A;
}

void merge(int* A, int l, int m, int r) {
    int n1 = m - l;
    int n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];
    for(int i = 0; i < n1; i++) {
        L[i] = A[l+i];
    }
    for(int i = 0; i < n2; i++) {
        R[i] = A[m+i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i += 1;
        } else {
            A[k] = R[j];
            j += 1;
        }
        k += 1;
    }
    while(i < n1) {
        A[k] = L[i];
        i += 1;
        k += 1;
    }
    while(j < n2) {
        A[k] = R[j];
        j += 1;
        k += 1;
    }
    delete[] L;
    delete[] R;
}

void mergeK(int* A, int l, int m, int r) {
    int i = l, j = m;
    std::vector<int> sorted;
    while(i < m && j < r) {
        if(A[i] <= A[j]) {
            sorted.push_back(A[i]);
            i++;
        } else if (A[j] <= A[i]) {
            sorted.push_back(A[j]);
            j++;
        }
    }
    while(i < m) {
        sorted.push_back(A[i]);
        i++;
    }
    while(j < r) {
        sorted.push_back(A[j]);
        j++;
    }
    for(int i = 0; i < sorted.size(); i++) {
        A[l+i] = sorted[i];
    }
}


int* ShS(int* A, int n) {
    std::vector<int> gaps = {701, 301, 132, 57, 23, 10, 4, 1};
    for(int gap: gaps) {
        for(int offset = 0; offset < gap; offset++) {
            for(int i = offset; i < n; i += gap) {
                int c = A[i];
                int j = i;
                for (; j >= gap && A[j-gap] > c; j -= gap) {
                    A[j] = A[j-gap];
                }
                A[j] = c;
            }
        }
    }
    return A;
}


int* CS(int* A, int n) {
    int* counts = new int[MAX_VALUE+1];
    for(int i = 0; i <= MAX_VALUE; i++) {
        counts[i] = 0;
    } 

    for(int i = 0; i < n; i++) {
        counts[A[i]] += 1;
    }

    for(int i = 1; i <= MAX_VALUE; i++) {
        counts[i] += counts[i-1];
    }

    int * sorted = new int[n];
    for(int i = n-1; i >= 0; i--) {
        counts[A[i]] -= 1;
        sorted[counts[A[i]]] = A[i];
    }

    for (int i = 0; i < n; i++) {
        A[i] = sorted[i];
    }

    delete[] counts;
    delete[] sorted;
    
    return A;
}