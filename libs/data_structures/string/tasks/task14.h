//
// Created by serge on 07.03.2022.
//

#ifndef LIBRARY1_TASK14_H
#define LIBRARY1_TASK14_H

#include "../string_.h"

int cmp(const void *a, const void *b) {
    return *(const char *) a - *(const char *) b;
}

bool areWordsWithSameLetters(char *s) {
    *copy(s, getEndOfString(s), stringBuffer) = '\0';
    getBagOfWords(&_bag,stringBuffer);

    for (int i = 0; i < _bag.size; ++i) {
        qsort(_bag.words[i].begin, _bag.words[i].end - _bag.words->begin, sizeof(char), cmp);
    }

    return equalWordsInStrings(stringBuffer);
}

void test_areWordsWithSameLetters_hasThisWords() {
    char s[MAX_STRING_SIZE] = "ababab bababa zxzxzx";
    assert(areWordsWithSameLetters(s));
}

void test_areWordsWithSameLetters_hasThisWords2() {
    char s[MAX_STRING_SIZE] = "abcdefg gfedcba";
    assert(areWordsWithSameLetters(s));
}

void test_areWordsWithSameLetters_hasNotThisWords() {
    char s[MAX_STRING_SIZE] = "zxczxc abcabc";
    assert(!areWordsWithSameLetters(s));
}

void test_areWordsWithSameLetters_empty() {
    char s[MAX_STRING_SIZE] = "";
    assert(!areWordsWithSameLetters(s));
}

void test_wordsFromSameLetters_14() {
    test_areWordsWithSameLetters_empty();
    test_areWordsWithSameLetters_hasThisWords();
    test_areWordsWithSameLetters_hasThisWords2();
    test_areWordsWithSameLetters_hasNotThisWords();
}

#endif //LIBRARY1_TASK14_H
