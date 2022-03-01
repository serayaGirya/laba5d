////
//// Created by serge on 01.03.2022.
////
//
//#ifndef LIBRARY1_TASK2_H
//#define LIBRARY1_TASK2_H
//
//#include <stdio.h>
//#include <ctype.h>
//
//void removeExtraSpaces(char *s) {
//    int countSpace = 0;
//    while (*s != '\0' && isspace(*s)) {
//        countSpace++;
//    }
//    char nonSpaceSymbol;
//    while (*s != '\0') {
//        if (!isspace(*s)) {
//            nonSpaceSymbol = *s;
//            break;
//        }
//    }
//    while (countSpace != 1 && *s != '\0') {
//        if (isspace(*s)) {
//            *s = nonSpaceSymbol;
//            s++;
//            countSpace--;
//        }
//    }
//}
//
//#endif //LIBRARY1_TASK2_H
