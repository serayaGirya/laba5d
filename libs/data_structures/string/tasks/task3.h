//
// Created by serge on 01.03.2022.
//

#ifndef LIBRARY1_TASK3_H
#define LIBRARY1_TASK3_H

#include "../string_.h"

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, stringBuffer);
    char *recPosition = copyIf(stringBuffer, endStringBuffer, word.begin, isdigit);
    copyIf(stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartString(char *s) {
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }
}

void test_digitToStartString_stringIsEmpty() {
    char s[MAX_STRING_SIZE] = "";
    digitToStartString(s);
    ASSERT_STRING("", s);
}

void test_digitToStartString_numberByWord() {
    char s[MAX_STRING_SIZE] = "Hi123";
    digitToStartString(s);
    ASSERT_STRING("123Hi", s);
}

void test_digitToStartString_numberByWordTwo() {
    char s[MAX_STRING_SIZE] = "Hi123 Rand456";
    digitToStartString(s);
    ASSERT_STRING("123Hi 456Rand", s);
}

void test_digitToStartString_numbersAtBeginningAndEndOfWord() {
    char s[MAX_STRING_SIZE] = "Hi123 4Rand56";
    digitToStartString(s);
    ASSERT_STRING("123Hi 456Rand", s);
}

void test_digitToStartString_numbersAndLettersSeparately() {
    char s[MAX_STRING_SIZE] = "123 Rand";
    digitToStartString(s);
    ASSERT_STRING("123 Rand", s);
}

void test_digitToStartString_3() {
    test_digitToStartString_stringIsEmpty();
    test_digitToStartString_numberByWord();
    test_digitToStartString_numberByWordTwo();
    test_digitToStartString_numbersAtBeginningAndEndOfWord();
    test_digitToStartString_numbersAndLettersSeparately();
}

#endif //LIBRARY1_TASK3_H
