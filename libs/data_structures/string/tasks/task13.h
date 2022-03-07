//
// Created by serge on 07.03.2022.
//

#ifndef LIBRARY1_TASK13_H
#define LIBRARY1_TASK13_H

#include "../string_.h"

bool equalWordsInStrings(char *string1) {
    getBagOfWords(&_bag,string1);
    for(int i = 0; i <_bag.size; i++) {
        for (int j = i + 1; j < _bag2.size; ++j) {
            if (areWordsEqual(_bag.words[i], _bag2.words[j]))
                return true;
        }
    }
    return false;
}

void test_equalWordsInStrings_1() {
    char s[MAX_STRING_SIZE] = "Dumplings Dumplings Big russian cat";
    assert(equalWordsInStrings(s) == true);
}

void test_equalWordsInStrings_2() {
    char s[MAX_STRING_SIZE] = "Dumplings Big russian cat Dumplings";
    assert(equalWordsInStrings(s) == true);
}

void test_equalWordsInStrings_3() {
    char s[MAX_STRING_SIZE] = "Big russian cat Dumplings Dumplings";
    assert(equalWordsInStrings(s) == true);
}

void test_equalWordsInStrings_4() {
    char s[MAX_STRING_SIZE] = "Big russian cat";
    assert(equalWordsInStrings(s) == true);
}

void test_equalWordsInStrings_13() {
    test_equalWordsInStrings_1();
    test_equalWordsInStrings_2();
    test_equalWordsInStrings_3();
    test_equalWordsInStrings_4();
}

#endif //LIBRARY1_TASK13_H
