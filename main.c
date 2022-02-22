#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/algorithms.h"


void test_swapRows_changeFirstAndSecondRows() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    swapRows(m, 0, 1);
    matrix expectedMatrix = createMatrixFromArray((int[]) {4, 5, 6,
                                                           1, 2, 3,
                                                           7, 8, 9}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_swapRows_changeFirstAndThirdRows() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    swapRows(m, 0, 2);
    matrix expectedMatrix = createMatrixFromArray((int[]) {7, 8, 9,
                                                           4, 5, 6,
                                                           1, 2, 3}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_swapRows() {
    test_swapRows_changeFirstAndSecondRows();
    test_swapRows_changeFirstAndThirdRows();
}

void test_swapCols_changeFirstAndThirdCols() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    swapColumns(m, 0, 2);
    matrix expectedMatrix = createMatrixFromArray((int[]) {3, 2, 1,
                                                           6, 5, 4,
                                                           9, 8, 7}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_swapCols_changeFirstAndSecondCols() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    swapColumns(m, 0, 1);
    matrix expectedMatrix = createMatrixFromArray((int[]) {2, 1, 3,
                                                           5, 4, 6,
                                                           8, 7, 9}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_swapCols() {
    test_swapCols_changeFirstAndSecondCols();
    test_swapCols_changeFirstAndThirdCols();
}

void test_insertionSortRowsMatrixByRowCriteria_Sort1() {
    matrix m = createMatrixFromArray((int[]) {4, 5, 6,
                                              7, 8, 9,
                                              1, 2, 3}, 3, 3);
    insertionSortRowsMatrixByRowCriteria(m, maxInRow);
    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 2, 3,
                                                           4, 5, 6,
                                                           7, 8, 9}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_insertionSortRowsMatrixByRowCriteria_Sort2() {
    matrix m = createMatrixFromArray((int[]) {7, 8, 9,
                                              13, 12, 4,
                                              7, 5, 8}, 3, 3);
    insertionSortRowsMatrixByRowCriteria(m, maxInRow);
    matrix expectedMatrix = createMatrixFromArray((int[]) {7, 5, 8,
                                                           7, 8, 9,
                                                           13, 12, 4}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_insertionSortRowsMatrixByRowCriteria_Sort3() {
    matrix m = createMatrixFromArray((int[]) {7, 8, 9, 4,
                                              13, 12, 4, 19,
                                              7, 5, 8, 1}, 3, 4);
    insertionSortRowsMatrixByRowCriteria(m, maxInRow);
    matrix expectedMatrix = createMatrixFromArray((int[]) {7, 5, 8, 1,
                                                           7, 8, 9, 4,
                                                           13, 12, 4, 19}, 3, 4);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_insertionSortRowsMatrixByRowCriteria() {
    test_insertionSortRowsMatrixByRowCriteria_Sort1();
    test_insertionSortRowsMatrixByRowCriteria_Sort2();
    test_insertionSortRowsMatrixByRowCriteria_Sort3();
}

void test_insertionSortColsMatrixByColCriteria1() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4, 5,
                                              2, 9, 5, 6,
                                              3, 10, 6, 11}, 3, 4);
    insertionSortColsMatrixByColCriteria(m, maxInRow);

    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 4, 8, 5,
                                                           2, 5, 9, 6,
                                                           3, 6, 10, 11}, 3, 4);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_insertionSortColsMatrixByColCriteria2() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4, 5,
                                              10, 9, 8, 6,
                                              3, 11, 2, 7}, 3, 4);
    insertionSortColsMatrixByColCriteria(m, maxInRow);

    matrix expectedMatrix = createMatrixFromArray((int[]) {5, 4, 1, 8,
                                                           6, 8, 10, 9,
                                                           7, 2, 3, 11}, 3, 4);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_insertionSortColsMatrixByColCriteria3() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4,
                                              10, 9, 8,
                                              3, 11, 2}, 3, 3);
    insertionSortColsMatrixByColCriteria(m, maxInRow);

    matrix expectedMatrix = createMatrixFromArray((int[]) {4, 1, 8,
                                                           8, 10, 9,
                                                           2, 3, 11}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_insertionSortColsMatrixByColCriteria() {
    test_insertionSortColsMatrixByColCriteria1();
    test_insertionSortColsMatrixByColCriteria2();
    test_insertionSortColsMatrixByColCriteria3();
}

void test_twoMatricesEqual_NotEqualnCols() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                               5, 6, 7, 8,
                                               9, 10, 11, 12}, 3, 4);
    assert(!twoMatricesEqual(m1, m2));
}

void test_twoMatricesEqual_NotEqualnRows() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9,
                                               10, 11, 12}, 4, 3);
    assert(twoMatricesEqual(m1, m2));
}

void test_twoMatricesEqual_Equal() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    assert(twoMatricesEqual(m1, m2));
}

void test_twoMatricesEqual_NotEqual() {
    matrix m1 = createMatrixFromArray((int[]) {5, 2, 3,
                                               4, 7, 6,
                                               7, 3, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    assert(!twoMatricesEqual(m1, m2));
}

void test_twoMatricesEqual() {
    test_twoMatricesEqual_NotEqualnCols();
    test_twoMatricesEqual_NotEqualnRows();
    test_twoMatricesEqual_Equal();
    test_twoMatricesEqual_NotEqual();
}

void test_isEMatrix_EMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1}, 3, 3);
    assert(isEMatrix(m));
}

void test_isEMatrix_NotEMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 6, 0,
                                              0, 1, 0,
                                              0, 0, 1}, 3, 3);
    assert(!isEMatrix(m));
}

void test_isEMatrix() {
    test_isEMatrix_EMatrix();
    test_isEMatrix_NotEMatrix();
}

void test_isSymmetricMatrix_isSymmetric() {
    matrix m = createMatrixFromArray((int[]) {1, 6, 10,
                                              6, 1, 3,
                                              10, 3, 1}, 3, 3);
    assert(isSymmetricMatrix(m));
}

void test_isSymmetricMatrix_isNotSymmetric() {
    matrix m = createMatrixFromArray((int[]) {1, 3, 10,
                                              6, 1, 3,
                                              10, 6, 1}, 3, 3);
    assert(!isSymmetricMatrix(m));
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_isSymmetric();
    test_isSymmetricMatrix_isNotSymmetric();
}

void test_transposeSquareMatrix_isTransposeTrue() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4,
                                              10, 9, 8,
                                              3, 11, 2}, 3, 3);
    transposeSquareMatrix(m);

    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 10, 3,
                                                           8, 9, 11,
                                                           4, 8, 2}, 3, 3);
    assert(twoMatricesEqual(m, expectedMatrix));
}

void test_transposeSquareMatrix_isTransposeFalse() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4,
                                              10, 9, 8,
                                              3, 11, 2}, 3, 3);
    transposeSquareMatrix(m);

    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 8, 3,
                                                           10, 9, 11,
                                                           4, 8, 2}, 3, 3);
    assert(!twoMatricesEqual(m, expectedMatrix));
}

void test_transposeSquareMatrix() {
    test_transposeSquareMatrix_isTransposeTrue();
    test_transposeSquareMatrix_isTransposeFalse();
}

void test_getMinValuePos() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4,
                                              10, 9, 8,
                                              3, 11, 2}, 3, 3);
    position expectedMinPos = (position) {0, 0};
    position minPos = getMinValuePos(m);
    assert(minPos.rowIndex == expectedMinPos.rowIndex);
    assert(minPos.colIndex == expectedMinPos.colIndex);
}

void test_getMaxValuePos() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4,
                                              10, 9, 8,
                                              3, 11, 2}, 3, 3);
    position expectedMaxPos = (position) {2, 1};
    position maxPos = getMaxValuePos(m);
    assert(maxPos.rowIndex == expectedMaxPos.rowIndex);
    assert(maxPos.colIndex == expectedMaxPos.colIndex);
}

void testFunction() {
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
    test_isEMatrix();
    test_twoMatricesEqual();
    test_insertionSortColsMatrixByColCriteria();
    test_insertionSortRowsMatrixByRowCriteria();
    test_swapCols();
    test_swapRows();
}

void task1(matrix m) {
    position maxIndex = getMaxValuePos(m);
    position minIndex = getMinValuePos(m);
    swapRows(m, maxIndex.rowIndex, minIndex.rowIndex);
}

void test_task1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    task1(m);
    matrix expectedMatrix = createMatrixFromArray((int[]) {7, 8, 9,
                                                           4, 5, 6,
                                                           1, 2, 3}, 3, 3);
    assert(twoMatricesEqual(m, expectedMatrix));
}

void task2(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, maxInRow);
}

void test_task2() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2,
                                              1, 8, 1,
                                              3, 2, 3}, 3, 3);
    task2(m);
    matrix expectedMatrix = createMatrixFromArray((int[]) {3, 2, 3,
                                                           7, 1, 2,
                                                           1, 8, 1}, 3, 3);
    assert(twoMatricesEqual(m, expectedMatrix));
}

void task3(matrix m) {
    insertionSortColsMatrixByColCriteria(m, minInRow);
}

void test_task3() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 2, 4, 3, 3,
                                              2, 5, 1, 8, 2, 7,
                                              6, 1, 4, 4, 8, 3}, 3, 6);
    task3(m);
    matrix expectedMatrix = createMatrixFromArray((int[]) {5, 2, 3, 3, 3, 4,
                                                           5, 1, 2, 2, 7, 8,
                                                           1, 4, 6, 8, 3, 4}, 3, 6);
    assert(twoMatricesEqual(m, expectedMatrix));
}

matrix task4(matrix m) {
    if (isSymmetricMatrix(m))
        return multiplicationMatrices(m, m);
    else
        return m;
}

void test_task4_MatrixIsSymmetric() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2,
                                              1, 8, 17,
                                              2, 17, 3}, 3, 3);
    m = task4(m);
    matrix expectedMatrix = createMatrixFromArray((int[]) {54, 49, 37,
                                                           49, 354, 189,
                                                           37, 189, 302}, 3, 3);

    assert(twoMatricesEqual(m, expectedMatrix));
}

void test_task4_MatrixIsNotSymmetric() {
    matrix m = createMatrixFromArray((int[]) {7, 3, 2,
                                              1, 8, 17,
                                              8, 17, 3}, 3, 3);
    m = task4(m);
    matrix expectedMatrix = createMatrixFromArray((int[]) {7, 3, 2,
                                                           1, 8, 17,
                                                           8, 17, 3}, 3, 3);

    assert(twoMatricesEqual(m, expectedMatrix));
}

void test_task4() {
    test_task4_MatrixIsSymmetric();
    test_task4_MatrixIsNotSymmetric();
}

int sumInArray(int *a, size_t size) {
    int sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += a[i];
    }
    return sum;
}

bool isUnique(int *a, size_t size) {
    for (size_t i = 1; i < size; i++) {
        if (a[i - 1] == a[i])
            return false;
    }
    return true;
}

matrix task5(matrix m) {
    int sumArray[m.nRows];
    for (size_t i = 0; i < m.nRows; i++) {
        sumArray[i] = sumInArray(m.values[i], m.nCols);
    }
    if (isUnique(sumArray, m.nRows))
        transposeSquareMatrix(m);
    return m;
}

void test_task5_SumsNotEqual() {
    matrix m = createMatrixFromArray((int[]) {2, 13, 4,
                                              1, 8, 17,
                                              23, 47, 3}, 3, 3);
    task5(m);
    matrix expectedMatrix = createMatrixFromArray((int[]) {2, 1, 23,
                                                           13, 8, 47,
                                                           4, 17, 3}, 3, 3);

    assert(twoMatricesEqual(m, expectedMatrix));
}

void test_task5_SumsEqual() {
    matrix m = createMatrixFromArray((int[]) {10, 13, 3,
                                              1, 8, 17,
                                              23, 47, 3}, 3, 3);
    task5(m);
    matrix expectedMatrix = createMatrixFromArray((int[]) {10, 13, 3,
                                                           1, 8, 17,
                                                           23, 47, 3}, 3, 3);

    assert(twoMatricesEqual(m, expectedMatrix));
}

void test_task5() {
    test_task5_SumsNotEqual();
    test_task5_SumsEqual();
}

bool task6(matrix m1, matrix m2) {
    matrix mulMatrix = multiplicationMatrices(m1, m2);
    bool EMatrix = isEMatrix(mulMatrix);
    freeMemMatrix(&mulMatrix);
    return EMatrix;
}

void test_task6_IsEMatrix() {
    matrix m1 = createMatrixFromArray((int[]) {2, 5, 7,
                                               6, 3, 4,
                                               5, -2, -3}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, -1, 1,
                                               -38, 41, -34,
                                               27, -29, 24}, 3, 3);

    assert(task6(m1, m2) == true);
}

void test_task6_IsNotEMatrix() {
    matrix m1 = createMatrixFromArray((int[]) {2, 5, 7,
                                               6, 3, 4,
                                               5, -2, -3}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, 4, 1,
                                               -38, 35, -34,
                                               27, -27, 24}, 3, 3);

    assert(task6(m1, m2) == false);
}

void test_task6() {
    test_task6_IsEMatrix();
    test_task6_IsNotEMatrix();
}

int max2(int a, int b) {
    return a > b ? a : b;
}

int task7(matrix m) {
    int sizeSumArray = m.nCols + m.nRows - 1;
    int sumArray[sizeSumArray];
    for (size_t i = 0; i < sizeSumArray; i++) {
        sumArray[i] = 0;
    }
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            if (i == j)
                continue;
            sumArray[j - i + 2] = max2(sumArray[j - i + 2], m.values[i][j]);
        }
    }
    int sum = sumInArray(sumArray, m.nRows + m.nCols - 1);
    return sum;
}

void test_task7() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                              1, 3, 6, 3,
                                              3, 2, 1, 2}, 3, 4);
    assert(task7(m) == 20);
}

int min2(int a, int b) {
    return a < b ? a : b;
}

int task8(matrix m) {
    position p = getMaxValuePos(m);
    int min = m.values[p.rowIndex][p.colIndex];
    int left = p.colIndex;
    int right = p.colIndex;
    for (int i = p.rowIndex - 1; i >= 0; i--) {
        if (left - 1 >= 0)
            left--;
        if (right + 1 < m.nCols)
            right++;
        int duplicate = right;
        while (duplicate >= left) {
            min = min2(min, m.values[i][duplicate]);
            duplicate--;
        }
    }
    return min;
}

void test_task8_NormArea() {
    matrix m = createMatrixFromArray((int[]) {6, 8, 9, 2,
                                              7, 12, 3, 4,
                                              10, 11, 5, 1}, 3, 4);

    assert(task8(m) == 6);
}

void test_task8_singleElementArea() {
    matrix m = createMatrixFromArray((int[]) {17, 7, 5, 6,
                                              3, 11, 8, 9,
                                              4, 1, 12, 2}, 3, 4);

    assert(task8(m) == 17);
}

void test_task8() {
    test_task8_NormArea();
    test_task8_singleElementArea();
}

float getDistance(int *a, int size) {
    int distance = 0;
    for (size_t i = 0; i < size; i++) {
        distance += a[i];
    }
    return sqrtf(distance);
}

void sortByDistance(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getDistance);
}

void test_task9() {
    matrix m = createMatrixFromArray((int[]) {17, 7, 5, 6,
                                              3, 11, 8, 9,
                                              4, 1, 12, 2}, 3, 4);
    sortByDistance(m);
    matrix expectedMatrix = createMatrixFromArray((int[]) {4, 1, 12, 2,
                                                           3, 11, 8, 9,
                                                           17, 7, 5, 6}, 3, 4);
    assert(twoMatricesEqual(m, expectedMatrix));

}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2)
        return -1;
    else if (arg1 > arg2)
        return 1;
    else
        return 0;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);
    int count;
    if (n != 0) {
        count = 1;
    }
    int i = 1;
    while (i < n) {
        if (a[i - 1] != a[i])
            count++;
        i++;
    }
    return count;
}

int countEqClassesByRowsSum(matrix m) {
    long long rowsSum[m.nRows];
    for (size_t i = 0; i < m.nRows; i++) {
        rowsSum[i] = sumInArray(m.values[i], m.nCols);
    }
    return countNUnique(rowsSum, m.nRows);
}

void test_task10_() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                              2, 7,
                                              5, 4,
                                              4, 3,
                                              1, 6,
                                              8, 0}, 6, 2);

    assert(countEqClassesByRowsSum(m) == 3);

}

void test_task10_allSumsIsEqual() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                              3, 5,
                                              4, 4,
                                              2, 6,
                                              1, 7,
                                              8, 0}, 6, 2);

    assert(countEqClassesByRowsSum(m) == 1);

}

void test_task10() {
    test_task10_();
    test_task10_allSumsIsEqual();
}

int getNSpecialElement(matrix m) {
    int nSpecial = 0;
    for (size_t j = 0; j < m.nCols; j++) {
        int specialElement = m.values[0][j];
        int sumOfElementInCol = 0;
        for (size_t i = 1; i < m.nRows; i++) {
            if (m.values[i][j] > specialElement) {
                sumOfElementInCol += specialElement;
                specialElement = m.values[i][j];
            } else
                sumOfElementInCol += m.values[i][j];
        }
        if (specialElement > sumOfElementInCol)
            nSpecial++;
    }
    return nSpecial;
}

void test_task11_thereElements() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                              2, 3, 6, 7,
                                              12, 2, 1, 2}, 3, 4);

    assert(getNSpecialElement(m) == 2);

}

void test_task11_zeroSpecialElements() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 5,
                                              2, 3, 6, 7,
                                              4, 2, 1, 2}, 3, 4);

    assert(getNSpecialElement(m) == 0);

}

void test_task11() {
    test_task11_thereElements();
    test_task11_zeroSpecialElements();
}

position getLeftMin(matrix m) {
    int min = m.values[0][0];
    position minPosition = {0, 0};
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] < min) {
                min = m.values[i][j];
                minPosition = (position) {i, j};
            }
        }
    }
    return minPosition;
}

void swapPenultimateRow(matrix m) {
    if (m.nRows < 2)
        printf("badCase");
    position min = getLeftMin(m);
    int col[m.nRows];
    for (size_t i = 0; i < m.nRows; i++) {
        col[i] = m.values[i][min.colIndex];
    }
    memcpy(m.values[m.nRows - 2], col, sizeof(int) * m.nCols);
}

void test_task12() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 1}, 3, 3);
    swapPenultimateRow(m);
    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 2, 3,
                                                           1, 4, 7,
                                                           7, 8, 1}, 3, 3);
    assert(twoMatricesEqual(m, expectedMatrix));

}

bool isNonDescendingSorted(int *a, size_t size) {
    for (size_t i = 1; i < size; i++) {
        if (a[i] < a[i - 1])
            return false;
    }
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (size_t i = 0; i < m.nRows; i++) {
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;
    }
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int numberRightMatrix = 0;
    for (size_t i = 0; i < nMatrix; i++) {
        numberRightMatrix += hasAllNonDescendingRows(ms[i]);
    }
    return numberRightMatrix;
}

void test_task13() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    7, 9
            },
            4, 2, 2);

    assert(countNonDescendingRowsMatrices(ms, 4) == 2);
}

int countValues(const int *a, size_t size, int value) {
    int countValues = 0;
    for (size_t i = 0; i < size; i++) {
        if (a[i] == value)
            countValues++;
    }
    return countValues;
}

int countZeroRows(matrix m) {
    int countZeroRows = 0;
    for (size_t i = 0; i < m.nRows; i++) {
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            countZeroRows++;
    }
    return countZeroRows;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int maxZeroInMatrix[nMatrix];
    for (size_t i = 0; i < nMatrix; i++) {
        maxZeroInMatrix[i] = countZeroRows(ms[i]);
    }
    int max = maxInRow(maxZeroInMatrix, nMatrix);
    for (int i = 0; i < nMatrix; i++)
        if (maxZeroInMatrix[i] == max)
            outputMatrix(ms[i]);
}

void test_countZeroRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0,
                    1, 0,
                    0, 0,
            },
            3, 2);

    assert(countZeroRows(m) == 2);
}

int maxInMatrix(matrix m) {
    int norm = abs(m.values[0][0]);
    for (size_t i = 0; i < m.nRows; i++) {
        int max = abs(maxInRow(m.values[i], m.nCols));
        if (norm < max)
            norm = max;
    }
    return norm;
}

void printMatricesWithMinNorm(matrix *ms, int nMatrix) {
    int normInMatrices[nMatrix];
    for (size_t i = 0; i < nMatrix; i++) {
        normInMatrices[i] = maxInMatrix(ms[i]);
    }
    int min = minInRow(normInMatrices, nMatrix);
    for (size_t i = 0; i < nMatrix; i++) {
        if (normInMatrices[i] == min)
            outputMatrix(ms[i]);
    }
}

void test_tasks() {
    test_task1();
    test_task2();
    test_task3();
    test_task4();
    test_task5();
    test_task6();
    test_task7();
    test_task8();
    test_task9();
    test_task10();
    test_task11();
    test_task12();
    test_task13();
    test_countZeroRows();
}

int main() {
    testFunction();
    test_tasks();
    return 0;
}
