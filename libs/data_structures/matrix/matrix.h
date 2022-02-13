//
// Created by serge on 13.02.2022.
//

#ifndef LIBRARY1_MATRIX_H
#define LIBRARY1_MATRIX_H

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


typedef struct matrix{
   int **values;
   int nRows;
   int nCols;
}matrix;

typedef struct position{
    int rowIndex;
    int colIndex;
}position;

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix *m);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix m);

void inputMatrices(matrix *ms, int nMatrices);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, int nMatrices);

void swapRows(matrix m, int i1, int i2);

void swapColumns(matrix m, int j1, int j2);

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));

bool isEMatrix(matrix m);

bool isSymmetricMatrix(matrix m);

bool twoMatricesEqual(matrix m1, matrix m2);

void transposeSquareMatrix(matrix m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

matrix createMatrixFromArray(const int *a, size_t nRows,
                             size_t nCols);

#endif //LIBRARY1_MATRIX_H