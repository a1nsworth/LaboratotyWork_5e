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
void replace(char *source, char *w1, char *w2);

// Задание 6
bool isWordsOrdered(char *s);

// Задание 7
void getBagOfWords(BagOfWords *bag, char *s);

// Задание 8
size_t countPalindromes(char *s) {
    unsigned counterPal = 0;
    char *begin = s;
    size_t len = strlen_(s);
    WordDescriptor word;
    char *end;
    while (*(end = find(begin, s + len, ',')) != '\0') {
        getWordReverse(begin - 1, end - 1, &word);
        counterPal += isPalindrome(word);
        begin = end + 1;
    }
    getWordReverse(begin - 1, end - 1, &word);
    counterPal += isPalindrome(word);

    return counterPal;
}

#endif //LABA5E_STRING_TUSK_H
