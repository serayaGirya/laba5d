//
// Created by serge on 27.02.2022.
//

#ifndef LIBRARY1_STRING__H
#define LIBRARY1_STRING__H

#include <ctype.h>
#include <memory.h>
#include <stdio.h>

size_t strlen_(char *begin);

char *find(char *begin, char *end, int ch);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

char *findNonSpace(char *begin);

char *findSpace(char *begin);


void removeExtraSpaces(char *s);

#endif //LIBRARY1_STRING__H
