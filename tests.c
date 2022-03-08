#include "libs/string_tusk.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__ , __FUNCTION__ , __LINE__ )

void assertString(char *expected, char *got,
                  char const *fileName, char *funcName,
                  int line) {
    int x = strcmp__(expected, got);
    if (x) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}


void test_strlen_zeroLen() {
    // Arrange
    char a[] = "";

    // Act
    size_t len = strlen_(a);

    // Assert
    assert(!len);
}

void test_strlen_allLen() {
    // Arrange
    char a[] = "abcd";

    // Act
    size_t len = strlen_(a);

    // Assert
    assert(len == 4);
}

void test_strlen_largeLen() {
    // Arrange
    char a[] = "123456789012345678901234567890123456789012345678901234567890";

    // Act
    size_t len = strlen_(a);

    // Assert
    assert(len == 60);
}

void test_strlen_oneElem() {
    // Arrange
    char a[] = " ";

    // Act
    size_t len = strlen_(a);

    // Assert
    assert(len == 1);
}

void test_strlen() {
    test_strlen_zeroLen();
    test_strlen_allLen();
    test_strlen_largeLen();
    test_strlen_oneElem();
}

void test_removeExtraSpaces_spacesBetweenBeforeAfterWords() {
    char s[] = "    Hello  World   42    ";
    removeExtraSpaces(s);
    ASSERT_STRING("Hello World 42", s);
}

void test_removeExtraSpaces_oneWord() {
    char s[] = "   Hello  ";
    removeExtraSpaces(s);
    ASSERT_STRING("Hello", s);
}

void test_removeExtraSpaces_spacesBeforeWords() {
    char s[] = "   Hello  ";
    removeExtraSpaces(s);
    ASSERT_STRING("Hello", s);
}

void test_removeExtraSpaces_noSpaces() {
    char s[] = "Hi123";
    removeExtraSpaces(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeExtraSpaces_emptyString() {
    char s[] = "";
    removeExtraSpaces(s);
    ASSERT_STRING("", s);
}

void test_removeExtraSpaces_allSpaces() {
    char s[] = "            ";
    removeExtraSpaces(s);
    ASSERT_STRING("            ", s);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_spacesBeforeWords();
    test_removeExtraSpaces_spacesBetweenBeforeAfterWords();
    test_removeExtraSpaces_noSpaces();
    test_removeExtraSpaces_emptyString();
    test_removeExtraSpaces_oneWord();
    test_removeExtraSpaces_allSpaces();

}

void test_digitToStartForEveryWord_digitsInEnd() {
    char s[] = "ABC123  FCF312";
    digitToStartForEveryWord(s);
    ASSERT_STRING("123ABC  312FCF", s);
}

void test_digitToStartForEveryWord_digitsInWord() {
    char s[] = "A3B2C1       F42C42F42";
    digitToStartForEveryWord(s);
    ASSERT_STRING("321ABC       424242FCF", s);
}

void test_digitToStartForEveryWord_digitsInStart() {
    char s[] = "321ABC       424242FCF";
    digitToStartForEveryWord(s);
    ASSERT_STRING("321ABC       424242FCF", s);
}

void test_digitToStartForEveryWord_noDigits() {
    char s[] = "ABC FCF";
    digitToStartForEveryWord(s);
    ASSERT_STRING("ABC FCF", s);
}

void test_digitToStartForEveryWord_noLetters() {
    char s[] = "123 4 56";
    digitToStartForEveryWord(s);
    ASSERT_STRING("123 4 56", s);
}

void test_digitToStartForEveryWord_allSpaces() {
    char s[] = "\n   \t \n";
    digitToStartForEveryWord(s);
    ASSERT_STRING("\n   \t \n", s);
}

void test_digitToStartForEveryWord_emptyString() {
    char s[] = "";
    digitToStartForEveryWord(s);
    ASSERT_STRING("", s);
}

void test_digitToStartForEveryWord() {
    test_digitToStartForEveryWord_digitsInEnd();
    test_digitToStartForEveryWord_digitsInWord();
    test_digitToStartForEveryWord_digitsInStart();
    test_digitToStartForEveryWord_noDigits();
    test_digitToStartForEveryWord_noLetters();
    test_digitToStartForEveryWord_allSpaces();
    test_digitToStartForEveryWord_emptyString();

}

void test_replaceDigitsByEqualSpaces_figuresInWord() {
    char s[MAX_STRING_SIZE] = "A3B0C1";
    replaceDigitsByEqualSpaces(s);
    ASSERT_STRING("A   BC ", s);
}

void test_replaceDigitsByEqualSpaces_AfterBeforeWord() {
    char s[MAX_STRING_SIZE] = "4A3B12E0C1\t";
    replaceDigitsByEqualSpaces(s);
    ASSERT_STRING("    A   B   EC \t", s);
}

void test_replaceDigitsByEqualSpaces_noFigures() {
    char s[MAX_STRING_SIZE] = "ABEC";
    replaceDigitsByEqualSpaces(s);
    ASSERT_STRING("ABEC", s);
}

void test_replaceDigitsByEqualSpaces_noLetters() {
    char s[MAX_STRING_SIZE] = "1234";
    replaceDigitsByEqualSpaces(s);
    ASSERT_STRING("          ", s);
}

void test_replaceDigitsByEqualSpaces_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    replaceDigitsByEqualSpaces(s);
    ASSERT_STRING("", s);
}

void test_replaceDigitsByEqualSpaces() {
    test_replaceDigitsByEqualSpaces_figuresInWord();
    test_replaceDigitsByEqualSpaces_AfterBeforeWord();
    test_replaceDigitsByEqualSpaces_noFigures();
    test_replaceDigitsByEqualSpaces_noLetters();
    test_replaceDigitsByEqualSpaces_emptyString();
}

void test_isWordsOrdered_oneLetterOrdered() {
    char s[] = "a b c d e";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_oneLetterUnordered() {
    char s[] = "a b a d e";
    assert(!isWordsOrdered(s));
}

void test_isWordsOrdered_ordered() {
    char s[] = "c c++ java javaScript python ruby";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_unorderedLastLetterAreDifferent() {
    char s[] = "bananz bananf";
    assert(!isWordsOrdered(s));
}

void test_isWordsOrdered_orderedLastLetterAreDifferent() {
    char s[] = "bananf bananz";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_oneWord() {
    char s[] = "banana banana";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_emptyString() {
    char s[] = "";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered() {
    test_isWordsOrdered_unorderedLastLetterAreDifferent();
    test_isWordsOrdered_oneLetterOrdered();
    test_isWordsOrdered_oneLetterUnordered();
    test_isWordsOrdered_ordered();
    test_isWordsOrdered_orderedLastLetterAreDifferent();
    test_isWordsOrdered_oneWord();
    test_isWordsOrdered_emptyString();
}

void test_countPalindromes_hasPalindromes() {
    char s[] = "radar, tot, noon, redder, stats, apple, poop";
    assert(countPalindromes(s) == 6);
}

void test_countPalindromes_oneWord() {
    char s[] = "radar";
    assert(countPalindromes(s) == 1);
}

void test_countPalindromes_noSpaces() {
    char s[] = "radar,tot,noon,redder,stats,apple,poop";
    assert(countPalindromes(s) == 6);
}

void test_countPalindromes_oneLetter() {
    char s[] = "a,b,c,d,e,f,g";
    assert(countPalindromes(s) == 7);
}

void test_countPalindromes() {
    test_countPalindromes_hasPalindromes();
    test_countPalindromes_noSpaces();
    test_countPalindromes_oneLetter();
    test_countPalindromes_oneWord();
}

void test_getAlternatingWordLines_equalWordCount() {
    char s[MAX_STRING_SIZE];
    getAlternatingWordLines(s, "Hello World", "Wow Beautiful");
    ASSERT_STRING("Hello Wow World Beautiful", s);
}

void test_getAlternatingWordLines_moreWordInFirstString() {
    char s[MAX_STRING_SIZE];
    getAlternatingWordLines(s, "Hello World Beautiful", "Wow");
    ASSERT_STRING("Hello Wow World Beautiful", s);
}

void test_getAlternatingWordLines_moreWordInSecondString() {
    char s[MAX_STRING_SIZE];
    getAlternatingWordLines(s, "Wow", "Hello World Beautiful");
    ASSERT_STRING("Wow Hello World Beautiful", s);
}

void test_getAlternatingWordLines_firstStringIsEmpty() {
    char s[MAX_STRING_SIZE];
    getAlternatingWordLines(s, "", "Hello World Beautiful");
    ASSERT_STRING("Hello World Beautiful", s);
}

void test_getAlternatingWordLines_secondStringIsEmpty() {
    char s[MAX_STRING_SIZE];
    getAlternatingWordLines(s, "Hello World Beautiful", "");
    ASSERT_STRING("Hello World Beautiful", s);
}

void test_getAlternatingWordLines_stringsAreEmpty() {
    char s[MAX_STRING_SIZE];
    getAlternatingWordLines(s, " ", " ");
    ASSERT_STRING("", s);
}

void test_getAlternatingWordLines() {
    test_getAlternatingWordLines_equalWordCount();
    test_getAlternatingWordLines_moreWordInFirstString();
    test_getAlternatingWordLines_moreWordInSecondString();
    test_getAlternatingWordLines_firstStringIsEmpty();
    test_getAlternatingWordLines_secondStringIsEmpty();
    test_getAlternatingWordLines_stringsAreEmpty();
}

void test_reverseWordsOrder_empty() {
    char str[] = "";
    reverseWordsOrder(str);
    ASSERT_STRING("", str);
}

void test_reverseWordsOrder_oneWord() {
    char str[] = "asd";
    reverseWordsOrder(str);
    ASSERT_STRING("asd", str);
}

void test_reverseWordsOrder_someWords() {
    char str[] = "death   is  near";
    reverseWordsOrder(str);
    ASSERT_STRING("near is death", str);
}

void test_reverseWordsOrder() {
    test_reverseWordsOrder_empty();
    test_reverseWordsOrder_oneWord();
    test_reverseWordsOrder_someWords();
}

void test_string() {
    test_strlen();
    test_removeExtraSpaces();
    test_digitToStartForEveryWord();
    test_replaceDigitsByEqualSpaces();
    test_replaceDigitsByEqualSpaces();
    test_isWordsOrdered();
    test_countPalindromes();
    test_getAlternatingWordLines();
    test_reverseWordsOrder();
}

int main() {
    test_string();

    return 0;
}