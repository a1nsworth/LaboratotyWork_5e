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
