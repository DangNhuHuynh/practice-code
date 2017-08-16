#include "../C++/String/String.hpp"
#include "../catch.hpp"
using namespace dtnh;
//
//TEST_CASE("StringDefaultConstructor", "") {
//    String validString("Huynh");
//    size_t expect = 5;
//    size_t result = validString.getSize();
//
//    // Check valid string default constructor - Should equals
//    CHECK(result == expect);
//}
//
//TEST_CASE("StringConstructorWithElement", "") {
//    // Default valid String with element is a characters chain and compare size - Should equals
//    String validString("Huynh");
//    size_t expectSize = 5;
//    size_t expectCapacity = 10;
//    size_t resultSize = validString.getSize();
//    size_t resultCapacity = validString.getCapacity();
//
//    // Check valid String constructor with element - Should equals
//    CHECK(resultSize == expectSize);
//    CHECK(resultCapacity == expectCapacity);
//}
//
//TEST_CASE("StringConstructorWithTwoElement", "") {
//    // Give valid String with first element is character, second element is size of chain created
//    String validString('a', 4);
//    size_t expectSize = 4;
//    size_t expectCapacity = 8;
//    size_t resultSize = validString.getSize();
//    size_t resultCapacity = validString.getCapacity();
//
//    // Check valid String constructor with two element
//    CHECK(resultSize == expectSize);
//    CHECK(resultCapacity == expectCapacity);
//}
//
//TEST_CASE("StringCopyConstructor", "") {
//    String validString("Huynh");
//    String validCopyString(validString);
//    size_t expectSize = 5;
//    size_t expectCapacity = 10;
//    size_t resultSize = validString.getSize();
//    size_t resultCapacity = validString.getCapacity();
//
//    // Check valid String constructor copy - Should equals
//    CHECK(resultSize == expectSize);
//    CHECK( resultCapacity == expectCapacity);
//}
//
//TEST_CASE("StringDestructor", "") {
//    String *validString = new String("UniversityOfScience");
//    delete validString;
//}
//
// //FIXME: danghuynh please fix this test case
//TEST_CASE("StringAppend", "") {
//    // Give a valid String then append a new string to this and compare size - Should equals
//    String validString = "1234";
//    validString.append("anhkhoa");
//    String expect = "1234anhkhoa";
//    size_t result = 11;
//    CHECK(expect.getSize() == result);
//}
//
//TEST_CASE("StringCompare") {
//    String validString = "Huynh";
//    String target = "Huynh";
//    CHECK(validString.getSize() == target.getSize());
//}
//
//// FIXME: danghuynh please fix this test case
//TEST_CASE("StringInsert", "") {
//    String validString = "1345";
//    String target = "2";
//    validString.insert(1, target);
//    size_t result = 5;
//    String expect = "12345";
//    CHECK(expect.getSize() == result);
//}
//
//TEST_CASE("StringTotal", "") {
//    // Give two valid String to join two strings into a new string - Should equals
//    String firstValidString = "123";
//    String secondValidString = "456";
//    String totalString = firstValidString + secondValidString;
//    size_t result = totalString.getSize();
//    size_t expect = 6;
//
//    // Check totalString size with total size of firstValidString and secondValidString.
//    CHECK(expect == result);
//}
//
//TEST_CASE("StringAssignmentConstructor", "") {
//    String validString("Huynh");
//    String resultString = validString;
//    size_t expect = 5;
//    size_t resultSize = resultString.getSize();
//
//    CHECK(resultSize == expect);
//}

TEST_CASE("StringReplace", "") {
    String validString("1225678");
    validString.replace(6, 1, "234");
    std::cout << validString << std::endl;
}