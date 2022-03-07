//
// Created by serge on 02.03.2022.
//

#ifndef LIBRARY1_TASK7_H
#define LIBRARY1_TASK7_H

#include "../string_.h"

void reverseWord(char *s) {
    *copy(s, getEndOfString(s), stringBuffer) = '\0';
    getBagOfWords(&_bag, stringBuffer);
    char *begin = s;
    for (int i = 0; i < _bag.size; ++i) {
        *copyReverse(_bag.words[i].end - 1, _bag[i].begin - 1, begin) = '\0';
        printf("%s\n", begin);
    }
}

void test_reverseWord() {
    char s[] = "hello world!";
    reverseWord(s);
}

#endif //LIBRARY1_TASK7_H
