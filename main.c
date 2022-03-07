#include <assert.h>
#include "libs/data_structures/string/string_.h"
#include "libs/data_structures/string/tasks/task1.h"
#include "libs/data_structures/string/tasks/task2.h"
#include "libs/data_structures/string/tasks/task3.h"
#include "libs/data_structures/string/tasks/task4.h"
#include "libs/data_structures/string/tasks/task5.h"
#include "libs/data_structures/string/tasks/task6.h"
#include "libs/data_structures/string/tasks/task7.h"
#include "libs/data_structures/string/tasks/task8.h"
#include "libs/data_structures/string/tasks/task9.h"
#include "libs/data_structures/string/tasks/task10.h"
#include "libs/data_structures/string/tasks/task11.h"
#include "libs/data_structures/string/tasks/task12.h"
#include "libs/data_structures/string/tasks/task13.h"
#include "libs/data_structures/string/tasks/task14.h"
#include "libs/data_structures/string/tasks/task15.h"
#include "libs/data_structures/string/tasks/task16.h"
#include "libs/data_structures/string/tasks/task17.h"
#include "libs/data_structures/string/tasks/task18.h"
#include "libs/data_structures/string/tasks/task19.h"


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


int main() {

    test_strlen__();
    test_findNonSpaceReverse();
    test_findNonSpace();
    test_findSpace();
    test_removeNonLetters_1();
    test_removeExtraSpaces_2();
    test_digitToStartString_3();
    test_replacesNumbersWithSpaces_4();
    //test_5
    test_areWordsOrdered_6();
    //test_6
    test_numOfPalindromeWords_8();
    test_alternatingWords_9();
    test_reverseSentence_10();
    testAll_getWordBeforeFirstWordWithA();
    test_lastWordInFirstStringIsInSecondString_12();
    test_equalWordsInStrings_13();
    test_wordsFromSameLetters_14();
    //test_15
    //test_16
    //test_17
    //test_18
    //test_19

    return 0;
}
