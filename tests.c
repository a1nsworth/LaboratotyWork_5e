#define ASSERT_STRING ( expected , got ) assertString ( expected , got , __FILE__ , __FUNCTION__ , __LINE__ )

#include "libs/string_tusk.h"

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