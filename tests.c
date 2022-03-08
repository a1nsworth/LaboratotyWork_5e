#include "libs/string_tusk.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__ , __FUNCTION__ , __LINE__ )

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    int x = strcmp_(expected, got);
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

void test_digitToStartWithoutChangeOrder_digitsInEnd() {
    char s[] = "ABC123  FCF312";
    digitToStartWithoutChangeOrder(s);
    ASSERT_STRING("123ABC  312FCF", s);
}

void test_digitToStartWithoutChangeOrder_digitsInWord() {
    char s[] = "A3B2C1       F42C42F42";
    digitToStartWithoutChangeOrder(s);
    ASSERT_STRING("321ABC       424242FCF", s);
}

void test_digitToStartWithoutChangeOrder_digitsInStart() {
    char s[] = "321ABC       424242FCF";
    digitToStartWithoutChangeOrder(s);
    ASSERT_STRING("321ABC       424242FCF", s);
}

void test_digitToStartWithoutChangeOrder_noDigits() {
    char s[] = "ABC FCF";
    digitToStartWithoutChangeOrder(s);
    ASSERT_STRING("ABC FCF", s);
}

void test_digitToStartWithoutChangeOrder_noLetters() {
    char s[] = "123 4 56";
    digitToStartWithoutChangeOrder(s);
    ASSERT_STRING("123 4 56", s);
}

void test_digitToStartWithoutChangeOrder_allSpaces() {
    char s[] = "\n   \t \n";
    digitToStartWithoutChangeOrder(s);
    ASSERT_STRING("\n   \t \n", s);
}

void test_digitToStartWithoutChangeOrder_emptyString() {
    char s[] = "";
    digitToStartWithoutChangeOrder(s);
    ASSERT_STRING("", s);
}

void test_digitToStartWithoutChangeOrder() {
    test_digitToStartWithoutChangeOrder_digitsInEnd();
    test_digitToStartWithoutChangeOrder_digitsInWord();
    test_digitToStartWithoutChangeOrder_digitsInStart();
    test_digitToStartWithoutChangeOrder_noDigits();
    test_digitToStartWithoutChangeOrder_noLetters();
    test_digitToStartWithoutChangeOrder_allSpaces();
    test_digitToStartWithoutChangeOrder_emptyString();

}



void test_string_() {
    test_strlen_zeroLen();
    test_strlen_allLen();
    test_strlen_largeLen();
    test_strlen_oneElem();
}

int main() {
    test_string_();

    return 0;
}