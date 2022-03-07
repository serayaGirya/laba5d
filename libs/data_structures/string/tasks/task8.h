//
// Created by serge on 02.03.2022.
//

#ifndef LIBRARY1_TASK8_H
#define LIBRARY1_TASK8_H

bool isPalindromeWord(char *begin, char *end) {
    end--;
    while (end - begin > 0) {
        if (*begin != *end)
            false;
        begin++;
        end--;
    }
    return true;
}

int numOfPalindromeWords(char *s) {
    char *endS = getEndOfString(s);
    char *beginSearch = findNonSpace(s);
    int countPalindromes = 0;

    char *commaPos = find(beginSearch, endS, ',');
    bool lastComma = *commaPos == '\0' && endS - beginSearch != 0;
    while (*commaPos != '\0' || lastComma) {
        beginSearch = findNonSpace(beginSearch);
        countPalindromes += isPalindromeWord(beginSearch, commaPos);
        beginSearch = commaPos + 1;

        if (lastComma)
            break;

        commaPos = find(beginSearch, endS, ',');
        lastComma = *commaPos == '\0';
    }

    return countPalindromes;
}

void test_numOfPalindromeWords_stringIsEmpty() {
    char s[] = "";
    assert(numOfPalindromeWords(s) == 0);
}

void test_numOfPalindromeWords_oneWOrdIsPalindrome() {
    char s[] = "abcba";
    assert(numOfPalindromeWords(s) == 1);
}

void test_numOfPalindromeWords_twoWordsIsPalindrome() {
    char s[] = "abcba,bacab";
    assert(numOfPalindromeWords(s) == 2);
}

void test_numOfPalindromeWords_onePallAndOneNot() {
    char s[] = "abcba,abcd";
    assert(numOfPalindromeWords(s) == 1);
}

void test_numOfPalindromeWords_OneSymbol() {
    char s[] = "a";
    assert(numOfPalindromeWords(s) == 1);
}

void test_numOfPalindromeWords_8() {
    test_numOfPalindromeWords_stringIsEmpty();
    test_numOfPalindromeWords_oneWOrdIsPalindrome();
    test_numOfPalindromeWords_twoWordsIsPalindrome();
    test_numOfPalindromeWords_onePallAndOneNot();
    test_numOfPalindromeWords_OneSymbol();
}

#endif //LIBRARY1_TASK8_H
