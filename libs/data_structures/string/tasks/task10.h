//
// Created by serge on 07.03.2022.
//

#ifndef LIBRARY1_TASK10_H
#define LIBRARY1_TASK10_H

#include "../string_.h"

void reverseSentence(char *string) {
    *copy(string, getEndOfString(string), stringBuffer) = '\0';
    getBagOfWords(&_bag, stringBuffer);
    char *copyS = string;
    for (int i = _bag.size - 1; i >= 0; --i) {
        string = copy(_bag.words[i].begin, _bag.words[i].end, string);
        *string++ = ' ';
    }
    if (string != copyS)
        string--;
    *string = '\0';
}

void test_reverseSentence_stringIsEmpty() {
    char s[MAX_STRING_SIZE] = "";
    reverseSentence(s);
    ASSERT_STRING("", s);
}

void test_reverseSentence_oneWord() {
    char s[MAX_STRING_SIZE] = "hello";
    reverseSentence(s);
    ASSERT_STRING("hello", s);
}

void test_reverseSentence_manyWords() {
    char s[MAX_STRING_SIZE] = "hello world!";
    reverseSentence(s);
    ASSERT_STRING("world! hello", s);
}

void test_reverseSentence_veryVeryVeryManyWords() {
    char s[MAX_STRING_SIZE] = "hello world! Buy word";
    reverseSentence(s);
    ASSERT_STRING("word Buy world! hello", s);
}

void test_reverseSentence_10() {
    test_reverseSentence_stringIsEmpty();
    test_reverseSentence_oneWord();
    test_reverseSentence_manyWords();
    test_reverseSentence_veryVeryVeryManyWords();

}

#endif //LIBRARY1_TASK10_H
