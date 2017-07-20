#include "../C++/String/String.hpp"
#include "../catch.hpp"
using namespace dtnh;

TEST_CASE("StringDefaultConstructor", "") {
    String validString;
    size_t expect = 0;
    size_t expectCapacity = 8;

    // Check valid string default constructor - Should equals
    CHECK(validString.getSize() == expect);
}

TEST_CASE("StringConstructorWithElement", "") {
    // Default valid String
    String validString("Huynh");
    size_t expectSize = 5;
    size_t expectCapacity = 8;

    // Check valid String constructor with element and compare size - Should equals
    CHECK(validString.getSize() == expect);
}

//TEST_CASE("StringAppend", "") {
//    // Give a valid String then append a new string to this and compare size - Should equals
//    String validString = "1234";
//    validString.append("5678");
//    int expect = 8;
//    int result = validString.size();
//    CHECK(expect == result);
//
//    // Check valid String toString - Should equals
//    char *stringExpect = "12345678";
//    char *stringResult = validString.toString();
//    CHECK(stringExpect == stringResult);
//}


