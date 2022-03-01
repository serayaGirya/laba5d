//
// Created by serge on 27.02.2022.
//

#include "string_.h"


size_t strlen_(char *begin) {
    char *end = begin;
    while (*end != '\0') {
        end++;
    }

    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (isspace(*begin) && *begin != '\0')
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (!isspace(*begin) && *begin != '\0')
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (isspace(*rbegin) && *rbegin > *rend) {
        rbegin--;
    }

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (!isspace(*rbegin) && *rbegin > *rend) {
        rbegin--;
    }

    return rbegin;
}

////TODO переделать стрКомпаре
int strcmp(const char *lhs, const char *rhs) {
    while (*rhs == *lhs && *rhs != 0 && *lhs != 0) {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);
    return beginDestination + (endSource - beginSource + 1);
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }
        rbeginSource--;
    }
    return beginDestination;
}

//testFunction

int countSpaces(char *s) {
    int countSpace = 0;
    while (*s != '\0') {
        if (isspace(*s)) {
            countSpace++;
            s++;
        } else
            s++;
    }

    return countSpace;
}

char getFirstNonSpaceSymbol(const char *s) {
    char nonSpaceSymbol = 0;
    while (*s != '\0') {
        if (*s == ' ') {
            s++;
        } else {
            nonSpaceSymbol = *s;
            break;
        }
    }

    return nonSpaceSymbol;
}

void removeExtraSpaces(char *s) {
    int countSpace = countSpaces(s);
    char nonSpaceSymbol = getFirstNonSpaceSymbol(s);
    while (countSpace != 1 && *s != '\0') {
        if (isspace(*s)) {
            *s = nonSpaceSymbol;
            s++;
            countSpace--;
        } else
            s++;
    }
}

