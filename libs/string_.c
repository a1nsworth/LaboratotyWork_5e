//
// Created by xed22 on 07.03.2022.
//

#include "string_.h"

void printExitIfNullptr(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

size_t strlen_(char *begin) {
    printExitIfNullptr(begin);

    register char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    printExitIfNullptr(begin);

    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char *findNonSpace(char *begin) {
    printExitIfNullptr(begin);

    while (*begin++ != '\0')
        if (!isspace(*begin))
            return begin;
    return begin;
}

char *findSpace(char *begin) {
    printExitIfNullptr(begin);

    while (*begin++ != '\0')
        if (isspace(*begin))
            return begin;
    return begin;
}

char *findNonSpaceReverse(char *rbegin, char *rend) {
    printExitIfNullptr(rbegin);

    while (rbegin-- != rend)
        if (!isspace(*rbegin))
            return rbegin;
    return rend;
}

char *findSpaceReverse(char *rbegin, char *rend) {
    printExitIfNullptr(rbegin);

    while (rbegin-- != rend)
        if (isspace(*rbegin))
            return rbegin;
    return rend;
}

int strcmp__(char *lhs, char *rhs) {
    printExitIfNullptr(lhs);
    printExitIfNullptr(rhs);

    for (; *lhs != '\0' || *rhs != '\0'; lhs++, rhs++) {
        int differenceAddress = lhs - rhs;
        if (differenceAddress != 0)
            return differenceAddress;
    }

    return 0;
}

char *copy(char *beginSource, char *endSource, char *beginDestination) {
    printExitIfNullptr(beginDestination);

    memcpy(beginDestination, beginSource, (beginSource - endSource) * sizeof(char));

    return beginDestination + 1;
}

char *copyIf(char *beginSource, char *endSource, char *beginDestination, int (*condition)(int)) {
    printExitIfNullptr(beginDestination);

    while (beginSource++ != endSource)
        if (condition(*beginSource))
            *beginDestination++ = *beginSource;
    return ++beginDestination + 1;
}

char *
copyIfReverse(char *rbeginSource, char *rendSource, char *beginDestination, int (*condition)(int)) {
    printExitIfNullptr(beginDestination);

    while (rbeginSource-- != rendSource)
        if (condition(*rbeginSource))
            *beginDestination++ = *rbeginSource;
    return beginDestination + 1;
}

bool getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return false;
    word->end = findSpace(word->begin);

    return true;
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend) + 1;
    if (word->end == rend)
        return false;
    word->begin = findSpaceReverse(word->end - 1, rend) + 1;

    return true;
}

char *getEndOfString(char *begin) {
    while (*begin != '\0')
        begin++;

    return begin;
}

char *searchWordInSource(char *source, char *word) {
    while (*source++ != '\0') {
        if (!(*source - *word)) {
            bool isFound = true;
            char *beginSource = source;
            char *beginWord = word;
            while (*beginWord && isFound) {
                isFound = *beginWord == *beginSource;
                beginWord++;
                beginSource++;
            }

            if (isFound)
                return source;
        }
    }
    return source;
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    char *beginW1 = w1.begin;
    char *beginW2 = w2.begin;
    while (*beginW1 == *beginW2 && beginW1 != w1.end - 1) {
        beginW1++;
        beginW2++;
    }

    return *beginW1 - *beginW2;
}

bool isPalindrome(WordDescriptor word) {
    word.end--;
    while (word.begin < word.end) {
        if (*word.begin != *word.end)
            return false;

        word.begin++;
        word.end--;
    }

    return true;
}



