//
// Created by xed22 on 07.03.2022.
//

#ifndef LABA5E_STRING_TUSK_H
#define LABA5E_STRING_TUSK_H

#include "string_.h"

bool isNotSpace(const int a) {
    return !isspace(a);
}

// Задание 1
void removeSpaces(char *s) {
    char *destination = copyIf(s, s + strlen_(s), s, isNotSpace);
    *destination = '\0';
}

// Задание 2


#endif //LABA5E_STRING_TUSK_H
