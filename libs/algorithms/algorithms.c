//
// Created by serge on 13.02.2022.
//

#include "algorithms.h"


void swap(void *a, void *b, size_t size) {
    char *pa = a;
    char *pb = b;
    for (int i = 0; i < size; ++i) {
        char t = *pa;
        *pa = *pb;
        *pb = t;
        pa++;
        pb++;
    }
}

size_t linearSearch(const int *a, const size_t n, int x) {
    for (size_t i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return n;
}

void insertionSort(int *a, const size_t size) {
    for (size_t i = 1; i < size; i++) {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

int maxInRow(const int *a, int nCols) {
    int max = a[0];
    for (int i = 1; i < nCols; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

