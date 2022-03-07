//
// Created by serge on 02.03.2022.
//

#ifndef LIBRARY1_TASK6_H
#define LIBRARY1_TASK6_H

#include "../string_.h"
#include <stdbool.h>


bool areWordsOrdered(char *s) {
    WordDescriptor word1;
    WordDescriptor word2;
    if (getWord(s, &word1)) {
        word2 = word1;
        while (getWord(s, &word1)) {
            if (areWordsEqual(word1, word2) < 0)
                return false;
            word2 = word1;
            s = word1.end;
        }
        return true;
    } else
        return true;
}



void test_areWordsOrdered_stringIsEmpty() {
    char s[] = "";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered_oneWordInString() {
    char s[] = "dream";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered_NotOrderedString() {
    char s[] = "pass op";
    assert(areWordsOrdered(s) == false);
}

void test_areWordsOrdered_orderedString() {
    char s[] = "a ab baaa ca cd";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered_TwoEqualWords() {
    char s[] = "pass pass";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered_6() {
    test_areWordsOrdered_stringIsEmpty();
    test_areWordsOrdered_oneWordInString();
    test_areWordsOrdered_NotOrderedString();
    test_areWordsOrdered_orderedString();
    test_areWordsOrdered_TwoEqualWords();
}




#endif //LIBRARY1_TASK6_H
