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

float getDistance(int *a, int n) {
    float distance = 0;
    for (int i = 0; i < n; i++)
        distance += (float) (a[i] * a[i]);

    return sqrtf(distance);
}

void insertionSortRowsMatrixByRowCriteria_float(matrix m, float (*criteria)(int *, int)) {
    float rowsCriteria[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        rowsCriteria[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++)
        for (int j = i; j > 0 && rowsCriteria[j - 1] > rowsCriteria[j]; j--) {
            swap(&rowsCriteria[j - 1], &rowsCriteria[j], sizeof(float));
            swapRows(m, j, j - 1);
        }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteria_float(m, getDistance);
}

//TODO: selectionSort
void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *criteriaArray = (int *) malloc(sizeof(int) * m.nCols);
    int *additionalArray = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nCols; ++i) {
        for (int j = 0; j < m.nRows; ++j)
            additionalArray[j] = m.values[j][i];
        criteriaArray[i] = criteria(additionalArray, m.nRows);
    }
    for (int i = 0; i < m.nCols - 1; ++i) {
        int minPos = i;
        for (int j = i + 1; j < m.nCols; j++)
            if (criteriaArray[j] < criteriaArray[minPos])
                minPos = j;
        swap(&criteriaArray[i], &criteriaArray[minPos], sizeof(int));
        swapColumns(m, i, minPos);
    }
    free(criteriaArray);
    free(additionalArray);
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows && m1.nCols != m2.nCols)
        return false;

    for (int i = 0; i < m2.nRows; ++i)
        if (memcmp(m1.values[i], m2.values[i], sizeof(int) * m1.nCols) != 0)
            return false;

    return true;
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
        for (int j = i + 1; j < m.nCols; ++j) {
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
    matrix m = multiplicationMatrices(m1, m2);
    bool result = isEMatrix(m);
    freeMemMatrix(&m);
    return result;
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
        if (left - 1 >= 0) {
            left--;
        }
        if (right + 1 < m.nCols) {
            right++;
        }
        int duplicate = right;
        while (duplicate >= left) {
            min = min2(min, m.values[i][duplicate]);
            duplicate--;
        }
    }
    return min;
}

//task 10
int cmp_long_long(const void *pa, const void *pb) {
    long long parameter1 = *(const long long *) pa;
    long long parameter2 = *(const long long *) pb;

    if (parameter1 < parameter2)
        return -1;
    else if (parameter1 > parameter2)
        return 1;
    else
        return 0;
}

int countNUnique(long long *a, const int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);
    int uniqueCounter = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1])
            uniqueCounter += 1;
    }
    return uniqueCounter;
}

int countEqClassesByRowsSum(matrix m) {
    long long rowSums[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        rowSums[i] = getSum(m.values, m.nRows);
    }
    return countNUnique(rowSums, m.nRows);
}

//task 11
int getNSpecialElement(matrix m) {
    int countSpecial = 0;
    for (int j = 0; j < m.nCols; ++j) {
        int specialElement = m.values[0][j];
        int sumInCol = 0;
        for (int i = 0; i < m.nRows; ++i) {
            if (m.values[i][j] > specialElement) {
                sumInCol += specialElement;
                specialElement = m.values[i][j];
            } else
                sumInCol += m.values[i][j];
        }
        if (specialElement > sumInCol)
            countSpecial += 1;
    }
    return countSpecial;
}