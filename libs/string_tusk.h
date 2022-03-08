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
void removeSpaces(char *s);

// Задание 2
void removeExtraSpaces(char *s);

// Задание 3
void digitToStart(WordDescriptor word);

// Задание 3.1
void digitToStartWithoutChangeOrder(WordDescriptor word);

// Задание 4
void replaceDigitsByEqualSpaces(char *s);

// Задание 5
void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *pRead, *pWrite;
    if (w1Size >= w2Size) {
        pRead = source;
        pWrite = source;
    } else {
        *copy(source, getEndOfString(source), _stringBuffer) = '\0';
        pRead = _stringBuffer;
        pWrite = source;
    }

    while (*pRead != '\0') {
        char *beginWord = searchWordInSource(pRead, word1.begin);
        pWrite = copy(pRead, beginWord, pWrite);
        pRead = beginWord + w1Size;
        if (*beginWord == '\0') {
            *pWrite = '\0';
            return;
        }
        memcpy(pWrite, word2.begin, w2Size);

        pWrite += w2Size;
    }
    *pWrite = '\0';
}


#endif //LABA5E_STRING_TUSK_H
