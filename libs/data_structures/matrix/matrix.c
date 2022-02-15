//
// Created by serge on 13.02.2022.
//

#include "matrix.h"
#include <stdio.h>
#include <malloc.h>
#include "../../algorithms/algorithms.h"


matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; ++i) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix));
    for (int i = 0; i < nMatrices; ++i) {
        ms[i] = getMemMatrix(nRows, nCols);
    }
    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; ++i) {
        free(m->values[i]);
    }
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        freeMemMatrix(&ms[i]);
    }
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            scanf("%d", &m.values[i][j]);
        }
    }
}


void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        inputMatrix(ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            printf("%d", m.values[i][j]);
            printf("\n");
        }
        printf("\n");
    }
}

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

matrix multiplicationMatrices(matrix m1, matrix m2) {
    assert(m1.nCols == m2.nRows);
    matrix newMatrix = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; ++i) {
        for (int j = 0; j < m2.nCols; ++j) {
            newMatrix.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; ++k) {
                newMatrix.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    }
    return (matrix) newMatrix;
}

void task1(matrix m) {
    position maxIndex = getMaxValuePos(m);
    position minIndex = getMinValuePos(m);
    swapRows(m, maxIndex.rowIndex, minIndex.rowIndex);
}

void task2(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, maxInRow);
}

void task3(matrix m) {
    insertionSortColsMatrixByColCriteria(m, minInCol);
}

matrix task4(matrix m) {
    if (isSymmetricMatrix(m))
        return multiplicationMatrices(m, m);
    else
        return m;
}

matrix task5(matrix m) {
    int sumArray[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        sumArray[i] = sumInArray(m.values[i], m.nCols);
    }
    if (isUnique(sumArray, m.nRows))
        transposeSquareMatrix(m);
    return m;
}

bool task6(matrix m1, matrix m2) {
    return isEMatrix((multiplicationMatrices(m1, m2)));
}

int task7(matrix m) {
    int sumArray[m.nCols + m.nRows - 2];
    int k = 0;
    for (int i = 1, j = 0; i < m.nRows; ++i, ++j) {
        int max = m.values[i][0];
        int duplicate = i;
        while (i + 1 < m.nRows && j + 1 < m.nCols) {
            j++;
            i++;
            max = max2(max, m.values[i][j]);
        }
        sumArray[k++] = max;
        j = 0;
        i = duplicate;
    }
    for (int i = 1, j = 0; i < m.nCols; i++, j++) {
        int max = m.values[0][i];
        int duplicate = i;
        while (i + 1 < m.nCols && j + 1 < m.nRows) {
            j++;
            i++;
            max = max2(max, m.values[j][i]);
        }
        sumArray[k++] = max;
        j = 0;
        i = duplicate;
    }
    int sum = sumInArray(sumArray, m.nRows + m.nCols - 2);
    return sum;
}

int task8(matrix m) {
    position p = getMaxValuePos(m);
    int min = m.values[p.rowIndex][p.colIndex];
    int left = p.colIndex;
    int right = p.colIndex;
    for (int i = p.rowIndex - 1; i >= 0; --i) {
        if (left - 1 >= 0)
            left--;
        if (right + 1 < m.nCols)
            right++;
        int duplicate = right;
        while (duplicate >= left) {
            min = min2(min, m.values[i][duplicate]);
            right--;
        }
    }
    return min;
}
