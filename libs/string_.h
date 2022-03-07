//
// Created by xed22 on 07.03.2022.
//

#ifndef LABA5E_STRING__H
#define LABA5E_STRING__H

#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>

void printExitIfNullptr(const void *ptr);

size_t strlen_(const char *begin);

char *find(const char *begin, const char *const end, int ch);

char *findNonSpace(const char *begin);

char *findSpace(const char *begin);

char *findNonSpaceReverse(const char *rbegin, const char *rend);

char *findSpaceReverse(const char *rbegin, const char *rend);

int strcmp_(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

char *copyIf(const char *beginSource, const char *endSource, char *beginDestination, bool (*condition)(int));

char *
copyIfReverse(const char *rbeginSource, const char *rendSource, char *beginDestination, bool (*condition)(int));

#endif //LABA5E_STRING__H
