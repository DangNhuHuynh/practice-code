#include "../C++/String/String.hpp"
#include "../catch.hpp"
using namespace dtnh;

TEST_CASE("StringDefaultConstructor", "") {
    String validString("Huynh");
    size_t expect = 5;
    size_t result = validString.getSize();

    // Check valid string default constructor - Should equals
    CHECK(result == expect);
}

TEST_CASE("StringConstructorWithElement", "") {
    // Default valid String with element is a characters chain and compare size - Should equals
    String validString("Huynh");
    size_t expectSize = 5;
    size_t expectCapacity = 10;
    size_t resultSize = validString.getSize();
    size_t resultCapacity = validString.getCapacity();

    // Check valid String constructor with element - Should equals
    CHECK(resultSize == expectSize);
    CHECK(resultCapacity == expectCapacity);
}

TEST_CASE("StringConstuctorWithTwoElement", "") {
    // Give valid String with first element is character, second element is size of chain created
    String validString('a', 4);
    size_t expectSize = 4;
    size_t expectCapacity = 8;

    // Check valid String constructor with two element
    CHECK(validString.getSize() == expectSize);
    CHECK(validString.getCapacity() == expectCapacity);
}

TEST_CASE("StringCopyConstructor", "") {
    String validString("Huynh");
    String validCopyString(validString);
    size_t expectSize = 5;
    size_t expectCapacity = 10;
    size_t resultSize = validString.getSize();
    size_t resultCapacity = validString.getCapacity();

    // Check valid String constructor copy - Should equals
    CHECK(resultSize == expectSize);
    CHECK( resultCapacity == expectCapacity);
}

TEST_CASE("StringDestructor", "") {
    String *validString = new String;
    delete validString;
}

TEST_CASE("StringAppend", "") {
    // Give a valid String then append a new string to this and compare size - Should equals
    String validString = "1234";
    String validAppendString(validString);
    size_t result = validAppendString.getSize();
    size_t expect = 4;
    
    CHECK(expect == result);
}