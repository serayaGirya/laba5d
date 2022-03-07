//
// Created by serge on 01.03.2022.
//

#ifndef LIBRARY1_TASK2_H
#define LIBRARY1_TASK2_H

#include <stdio.h>
#include <ctype.h>

char findFirstNonSpaceSymbol(char *s) {
    char nonSpaceSymbol;
    while (*s != '\0') {
        if (!isspace(*s)){
            nonSpaceSymbol = *s;
            break;
        } else
            s++;
    }
    return nonSpaceSymbol;
}

void removeExtraSpaces(char *s) {
    char nonSpaceSymbol = findFirstNonSpaceSymbol(s);
    char* nowElement = s;
    char* nextElement = s + 1;
    while (*s != '\0') {
        if (*nowElement == ' ' && *nextElement == ' ') {
            *nowElement = nonSpaceSymbol;
            nowElement++;
            nextElement++;
            s++;
        } else {
            nowElement++;
            nextElement++;
            s++;
        }
    }
}

void test_removeExtraSpaces_() {
    char s[100] = " ab   c  d e ";
    removeExtraSpaces(s);
    ASSERT_STRING("ab c d e", s);
}

void test_removeExtraSpaces_allSpaces() {
    char s[100] = "    ";
    removeExtraSpaces(s);
    ASSERT_STRING("    ", s);
}

void test_removeExtraSpaces_stringIsEmpty() {
    char s[100] = "";
    removeExtraSpaces(s);
    ASSERT_STRING("", s);
}

void test_removeExtraSpaces_2() {
    test_removeExtraSpaces_();
    test_removeExtraSpaces_allSpaces();
    test_removeExtraSpaces_stringIsEmpty();
}

#endif //LIBRARY1_TASK2_H
