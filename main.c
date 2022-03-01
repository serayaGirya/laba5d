//#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/algorithms.h"
#include <assert.h>
#include "libs/data_structures/string/string_.h"



//5e tests

void test_strlen__length1() {
    char word[] = "H";
    assert(strlen_(word) == 1);
}

void test_strlen__length5() {
    char word[] = "Hello";
    assert(strlen_(word) == 5);
}

void test_strlen__() {
    test_strlen__length1();
    test_strlen__length5();
}

void test_findNonSpaceReverse_beginWord() {
    char word[] = "olleH\n";
}

void test_findNonSpaceReverse_middleWord() {
    char word[] = "ol\nleH";
}

void test_findNonSpaceReverse_endWord() {
    char word[] = "\nolleH";
}

void test_findNonSpaceReverse_lastSpaceSymbol() {
    char word[] = "\n\n\n";
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_beginWord();
    test_findNonSpaceReverse_middleWord();
    test_findNonSpaceReverse_endWord();
    test_findNonSpaceReverse_lastSpaceSymbol();
}

void test_findNonSpace_beginWord() {
    char word[] = "\nHello";
    assert(findNonSpace(word) == word + 1);
}

void test_findNonSpace_middleWord() {
    char word[] = "\n\tH\n\t\0";
    assert(findNonSpace(word) == word + 2);
}

void test_findNonSpace_endWord() {
    char word[] = "\n\n\nH";
    assert(findNonSpace(word) == word + 3);
}

void test_findNonSpace_lastSpaceSymbol() {
    char word[] = "\n\n\n\n";
    assert(findNonSpace(word) == word + 4);
}

void test_findNonSpace() {
    test_findNonSpace_beginWord();
    test_findNonSpace_middleWord();
    test_findNonSpace_endWord();
    test_findNonSpace_lastSpaceSymbol();
}

void test_findSpace_beginWord() {
    char word[] = "\nHello";
    assert(findSpace(word) == word);
}

void test_findSpace_middleWord() {
    char word[] = "Hel\tlo";
    assert(findSpace(word) == word + 3);
}

void test_findSpace_endWord() {
    char word[] = "Hello\0";
    assert(findSpace(word) == word + 5);
}

void test_findSpace() {
    test_findSpace_beginWord();
    test_findSpace_middleWord();
    test_findSpace_endWord();
}

void test_task2_noSpace() {
    char word[] = "dddddd";
    removeExtraSpaces(word);
    assert(word == "");
}

void test_task2_spaces1() {
    char word[] = " abcdef";
    removeExtraSpaces(word);
    assert(word == "a abcdef");
}

void test_task2_spaces2() {
    char word[] = " a  b  cd";
    removeExtraSpaces(word);
    assert(word == "aaaaba cd");
}

void test_task2_allSpaces() {
    char word[] = "    ";
    removeExtraSpaces(word);
    assert(word == "");
}

void test_task2() {
    test_task2_noSpace();
    test_task2_spaces1();
    test_task2_spaces2();
    test_task2_allSpaces();
}

int main() {

    test_task2();
    test_strlen__();
    test_findNonSpaceReverse();
    test_findNonSpace();
    test_findSpace();

    return 0;
}
