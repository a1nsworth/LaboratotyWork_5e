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

void printExitIfNullptr(const void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

size_t strlen_(const char *begin) {
    printExitIfNullptr(begin);

    register char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char *find(const char *begin, const char *const end, const int ch) {
    printExitIfNullptr(begin);

    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char *findNonSpace(const char *begin) {
    printExitIfNullptr(begin);

    while (*begin++ != '\0')
        if (!isspace(*begin))
            return begin;
    return begin;
}

char *findSpace(const char *begin) {
    printExitIfNullptr(begin);

    while (*begin++ != '\0')
        if (isspace(*begin))
            return begin;
    return begin;
}

char *findNonSpaceReverse(const char *rbegin, const char *rend) {
    printExitIfNullptr(rbegin);

    while (rbegin-- != rend)
        if (!isspace(*rbegin))
            return rbegin;
    return rend;
}

char *findSpaceReverse(const char *rbegin, const char *rend) {
    printExitIfNullptr(rbegin);

    while (rbegin-- != rend)
        if (isspace(*rbegin))
            return rbegin;
    return rend;
}

int strcmp_(const char *lhs, const char *rhs) {
    printExitIfNullptr(lhs);
    printExitIfNullptr(rhs);

    for (; *lhs != '\0' || *rhs != '\0'; lhs++, rhs++) {
        int differenceAddress = lhs - rhs;
        if (differenceAddress != 0)
            return differenceAddress;
    }

    return 0;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    printExitIfNullptr(beginDestination);

    memcpy(beginDestination, beginSource, (beginSource - endSource) * sizeof(char));

    return beginDestination++;
}

#endif //LABA5E_STRING__H
