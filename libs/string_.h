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

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
char _stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

void printExitIfNullptr(const void *ptr);

size_t strlen_(const char *begin);

char *find(const char *begin, const char *const end, int ch);

char *findNonSpace(const char *begin);

char *findSpace(const char *begin);

char *findNonSpaceReverse(const char *rbegin, const char *rend);

char *findSpaceReverse(const char *rbegin, const char *rend);

int strcmp_(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

char *copyIf(const char *beginSource, const char *endSource, char *beginDestination, int (*condition)(int));

char *
copyIfReverse(const char *rbeginSource, const char *rendSource, char *beginDestination, int (*condition)(int));

bool getWord(char *beginSearch, WordDescriptor *word);

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

char *getEndOfString(char *begin);

char *searchWordInSource(char *source, char *word);

int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

bool isPalindrome(WordDescriptor word);

#endif //LABA5E_STRING__H
