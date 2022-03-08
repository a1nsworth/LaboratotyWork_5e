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
static char stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

void printExitIfNullptr(void *ptr);

size_t strlen_(char *begin);

char *find(char *begin, char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, char *rend);

char *findSpaceReverse(char *rbegin, char *rend);

int strcmp__(char *lhs, char *rhs);

char *copy(char *beginSource, char *endSource, char *beginDestination);

char *copyIf(char *beginSource, char *endSource, char *beginDestination, int (*condition)(int));

char *
copyIfReverse(char *rbeginSource, char *rendSource, char *beginDestination, int (*condition)(int));

bool getWord(char *beginSearch, WordDescriptor *word);

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

char *getEndOfString(char *begin);

char *searchWordInSource(char *source, char *word);

int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

bool isPalindrome(WordDescriptor word);

#endif //LABA5E_STRING__H
