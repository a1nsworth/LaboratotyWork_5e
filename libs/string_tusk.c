//
// Created by xed22 on 07.03.2022.
//

#include "string_tusk.h"

void removeSpaces(char *s) {
    char *destination = copyIf(s, s + strlen_(s), s, isNotSpace);
    *destination = '\0';
}

void removeExtraSpaces(char *s) {
    printExitIfNullptr(s);

    register char *iRead = s;
    char *iWrite = s;
    char lastVal = *iRead;
    while (*iRead != '\0') {
        if (*iRead != lastVal || !isspace(lastVal)) {
            *iWrite = *iRead;
            iWrite++;
        }
        lastVal = *iRead++;
    }

    iWrite = isspace(lastVal) ? iWrite - 1 : iWrite;
    *iWrite = '\0';
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,_stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,_stringBuffer - 1,word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartWithoutChangeOrder(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,_stringBuffer);
    char *recPosition = copyIf(_stringBuffer,endStringBuffer,word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void replaceDigitsByEqualSpaces(char *s) {
    char *begin = _stringBuffer;
    char *end = copy(s, getEndOfString(s), begin);

    while (begin++ < end) {
        if (isdigit(*begin)) {
            int a = *begin - '0';
            while (a--)
                *s++ = ' ';
        } else
            *s++ = *begin;
    }
    *s = '\0';
}

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

bool isWordsOrdered(char *s) {
    char *begin = s;
    WordDescriptor currentWord;
    if (!getWord(begin, &currentWord))
        return true;

    WordDescriptor lastWord = currentWord;
    begin = lastWord.end;
    while (getWord(begin, &currentWord)) {
        if (areWordsEqual(currentWord, lastWord) < 0)
            return false;
        lastWord = currentWord;
        begin = currentWord.end;
    }
    return true;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    char *beginSearch = s;
    bag->size = 0;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        bag->words[bag->size] = word;
        bag->size++;
        beginSearch = word.end;
    }
}

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

void getAlternatingWordLines(char *s1, char *s2, char *mergeS1S2) {
    WordDescriptor w1, w2;
    bool isW1found, isW2found;
    char* beginSearch1 = s1;
    char* beginSearch2 = s2;
    char* dst = mergeS1S2;
    while ((isW1found = getWord(beginSearch1, &w1)),
            (isW2found = getWord(beginSearch2, &w2)),
            isW1found || isW2found) {
        if (isW1found) {
            dst = copy(w1.begin, w1.end, dst);
            *dst++ = ' ';
            beginSearch1 = w1.end;
        }
        if (isW2found) {
            dst = copy(w2.begin, w2.end, dst);
            *dst++ = ' ';
            beginSearch2 = w2.end;
        }
    }
    *(dst - (dst != mergeS1S2)) = '\0';
}

void reverseWordsOrder(char *s) {
    char *rbegin = s + strlen_(s) - 1;
    char *rend = s - 1;
    char *beginDst = _stringBuffer;
    WordDescriptor word;
    while (getWordReverse(rend, rbegin, &word)) {
        beginDst = copy(word.begin, word.end, beginDst);
        *beginDst++ = ' ';
        rbegin = word.begin - 1;
    }

    *copy(_stringBuffer, beginDst - (beginDst != _stringBuffer), s) = '\0';
}

void digitToStartForEveryWord(char *s) {
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStartWithoutChangeOrder(word);

        beginSearch = word.end;
    }
}
