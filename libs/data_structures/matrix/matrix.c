//
// Created by serge on 13.02.2022.
//

#include "matrix.h"
#include <stdio.h>
#include <malloc.h>
#include "../../algorithms/algorithms.h"

//возвращает матрицу, размещает в динамической памяти матрицу размером nRows на nCols
matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; ++i) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }
    return (matrix) {values, nRows, nCols};
}

//возвращает указатель на нулевую матрицу, размещает в динамической памяти массив из nMаtrices матриц размером nRows на nCols
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix));
    for (int i = 0; i < nMatrices; ++i) {
        ms[i] = getMemMatrix(nRows, nCols);
    }
    return ms;
}

//освобождает память, выделенную под хранение матрицы m
void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; ++i) {
        free(m->values[i]);
    }
}

//освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        freeMemMatrix(&ms[i]);
    }
}

//вводит матрицу m
void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            scanf("%d", &m.values[i][j]);
        }
    }
}

//
void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        inputMatrix(ms[i]);
    }
}

//
void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            printf("%d", m.values[i][j]);
            printf("\n");
        }
        printf("\n");
    }
}

//
void outputMatrices(matrix *ms, const int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        outputMatrix(ms[i]);
    }
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

//
void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; ++i) {
        swap(m.values[j1], m.values[j2], sizeof(int *));
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *a = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; ++i) {
        a[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 1; i < m.nRows; ++i) {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        a[j] = t;
    }
    free(a);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *criteriaArray = (int *) malloc(sizeof(int) * m.nCols);
    int *additionalArray = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nCols; ++i) {
        for (int j = 0; j < m.nRows; ++j)
            additionalArray[j] = m.values[j][i];
        criteriaArray[i] = criteria(additionalArray, m.nRows);
    }
    for (int i = 0; i < m.nCols; ++i) {
        for (int j = i; j > 0 && criteriaArray[j - 1] > criteriaArray[j]; j--) {
            swap(&criteriaArray[j - 1], &criteriaArray[j], sizeof(int));
            swapColumns(m, j, j - 1);
        }
    }
    free(criteriaArray);
    free(additionalArray);
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows)
        return false;
    else {
        bool isEqual = false;
        for (int i = 0; i < m1.nRows; ++i) {
            for (int j = 0; j < m1.nCols; ++j) {
                isEqual = (m1.values[i][j] == m2.values[i][j]);
            }
        }
        return isEqual;
    }
}

bool isEMatrix(matrix m) {
    bool isE = false;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; ++j) {
            if (i == j && m.values[i][j] == 1 || i != j && m.values[i][j] == 0)
                isE = true;
            else
                return false;

        }
    }
    return isE;
}

bool isSymmetricMatrix(matrix m) {
    bool isSymmetric = false;
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            isSymmetric = (m.values[j][i] == m.values[i][j]);
        }
    }
    return isSymmetric;
}

void transposeSquareMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = i + 1; j < m.nCols; ++j) {
            swap(&m.values[i][j], &m.values[j][i], sizeof(int));
        }
    }
}

position getMinValuePos(matrix m) {
    position min = (position) {0, 0};
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            position positionNow = (position) {i, j};
            if ((m.values[positionNow.rowIndex][positionNow.colIndex]) < m.values[min.rowIndex][min.colIndex])
                min = positionNow;
        }
    }
    return min;
}

position getMaxValuePos(matrix m) {
    position maxIndex = {0, 0};
    int max = m.values[0][0];
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] > max) {
                max = m.values[i][j];
                maxIndex = (position) {i, j};
            }
        }
    }
    return maxIndex;
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

matrix createMatrixFromArray(const int *a, size_t nRows,
                             size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}
