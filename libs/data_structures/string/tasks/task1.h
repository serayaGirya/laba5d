//
// Created by serge on 01.03.2022.
//

#ifndef LIBRARY1_TASK1_H
#define LIBRARY1_TASK1_H
#include "libs/data_structures/string/string.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}


#endif //LIBRARY1_TASK1_H
