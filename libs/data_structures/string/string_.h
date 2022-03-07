//
// Created by serge on 27.02.2022.
//

#ifndef LIBRARY1_STRING__H
#define LIBRARY1_STRING__H
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__ , __LINE__)

#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 100
# define MAX_N_WORDS_IN_STRING 100
# define MAX_WORD_SIZE 20
char stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

BagOfWords _bag;
BagOfWords _bag2;

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

size_t strlen_(char *begin);

char *find(char *begin, char *end, int ch);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp_(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

char *findNonSpace(char *begin);

char *findSpace(char *begin);

bool getWord(char *beginSearch, WordDescriptor *word);

void removeExtraSpaces(char *s);

void getBagOfWords(BagOfWords *bag, char *s);

int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

bool equalWordsInStrings(char *string1);

#endif //LIBRARY1_STRING__H
