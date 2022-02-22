//
// Created by serge on 13.02.2022.
//

#ifndef LIBRARY1_ALGORITHMS_H
#define LIBRARY1_ALGORITHMS_H
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
void swap(void *a, void *b, size_t size);
int maxInRow(const int *a, int nCols);
int minInCol(int *a, int size);
int min2(int a, int b);
bool isUnique(int *a, size_t size);
int sumInArray(int *a, size_t size);
int max2(int a, int b);
long long getSum(int *a, int n);
int minInRow(int *a, int n);
#endif //LIBRARY1_ALGORITHMS_H
