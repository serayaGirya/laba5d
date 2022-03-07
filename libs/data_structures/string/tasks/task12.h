//
// Created by serge on 07.03.2022.
//

#ifndef LIBRARY1_TASK12_H
#define LIBRARY1_TASK12_H

#include "../string_.h"

void wordDescriptorToString(WordDescriptor word, char *destination) {
   *copy(word.begin, word.end, destination) = '\0';
}

WordDescriptor lastWordInFirstStringIsInSecondString(char *string1, char *string2) {
    getBagOfWords(&_bag,string1);
    getBagOfWords(&_bag,string2);
    for(int i = _bag.size - 1; i >= 0; i++) {
        for (int j = 0; j < _bag2.size; ++j) {
            if (areWordsEqual(_bag.words[i], _bag2.words[j]))
                return _bag.words[i];
        }
    }
    WordDescriptor word = {NULL, NULL};
    return word;
}

void test_lastWordInFirstStringIsInSecondString_StringsIsEmpty() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";
    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(lastWordInFirstStringIsInSecondString(s1, s2), s3);
    ASSERT_STRING("", s3);
}

void test_lastWordInFirstStringIsInSecondString_WordIsFound() {
    char s1[MAX_STRING_SIZE] = "touch in the night";
    char s2[MAX_STRING_SIZE] = "bla b night";
    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(lastWordInFirstStringIsInSecondString(s1, s2), s3);
    ASSERT_STRING("night", s3);
}

void test_lastWordInFirstStringIsInSecondString_WordIsNotFound() {
    char s1[MAX_STRING_SIZE] = "touch in the night";
    char s2[MAX_STRING_SIZE] = "bla b b";
    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(lastWordInFirstStringIsInSecondString(s1, s2), s3);
    ASSERT_STRING("\0", s3);
}
void test_lastWordInFirstStringIsInSecondString_firstFromTheEndIsFound() {
    char s1[MAX_STRING_SIZE] = "love in the night";
    char s2[MAX_STRING_SIZE] = "love b night";
    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(lastWordInFirstStringIsInSecondString(s1, s2), s3);
    ASSERT_STRING("night", s3);
}

void test_lastWordInFirstStringIsInSecondString_12() {
    test_lastWordInFirstStringIsInSecondString_StringsIsEmpty();
    test_lastWordInFirstStringIsInSecondString_WordIsFound();
    test_lastWordInFirstStringIsInSecondString_WordIsNotFound();
    test_lastWordInFirstStringIsInSecondString_firstFromTheEndIsFound();
}

#endif //LIBRARY1_TASK12_H
