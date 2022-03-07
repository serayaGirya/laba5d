//
// Created by serge on 01.03.2022.
//

#ifndef LIBRARY1_TASK1_H
#define LIBRARY1_TASK1_H

#include "../string_.h"

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;
    return s;
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_spacesBetweenEachCharacter() {
    char s[] = " H i 1 2 3 ";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeNonLetters_NoSpacesBetweenCharacter() {
    char s[] = "Hi123";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeNonLetters_AllCharactersAreSpaces() {
    char s[] = "      ";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters_1() {
    test_removeNonLetters_spacesBetweenEachCharacter();
    test_removeNonLetters_NoSpacesBetweenCharacter();
    test_removeNonLetters_AllCharactersAreSpaces();
}

#endif //LIBRARY1_TASK1_H
