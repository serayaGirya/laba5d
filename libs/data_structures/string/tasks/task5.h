//
// Created by serge on 02.03.2022.
//

#ifndef LIBRARY1_TASK5_H
#define LIBRARY1_TASK5_H

#include <stdbool.h>
#include "../string_.h"

bool compareWords(char *s, char *word) {
    char *copyS = s;
    char *copyWord = word;

    while (*copyS != ' ') {
        if (*copyS != *copyWord)
            return false;
        copyS++;
        copyWord++;
    }

    return true;
}

void replaceWord(char *source, WordDescriptor *word2, WordDescriptor word1, char *w2Size) {
    while (*w2Size != 0) {
        *source = *word2->begin;
        w2Size--;
    }
    while (word1.end - 1 - word2->begin != 0) {
        *source = ' ';
        word2->begin++;
    }
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), stringBuffer);
        readPtr = stringBuffer;
        recPtr = source;
    }
    char *copySource = source;
    size_t copyw2Size = w2Size;
    if (compareWords(copySource, w1)) {
        replaceWord(copySource,&w2, word1, copyw2Size);
    }
}

#endif //LIBRARY1_TASK5_H
