//#include "../catch.hpp"
//
//#include "../C++/LinkList/LinkList.hpp"
//
//TEST_CASE("NodeConstructor", "") {
//    Node validNode;
//    CHECK(validNode.getData() == 0);
//}
//
//TEST_CASE("SetData", ""){
//    Node validNode(8);
//    CHECK(validNode.getData() == 8);
//}
//
//TEST_CASE("NodeCopyConstructor", ""){
//    Node validNode(10);
//    Node nodeCopy(validNode);
//    CHECK(nodeCopy.getData() == 10);
//}
//
//TEST_CASE("Destructor", "") {
//    Node *newNode = new Node;
//    newNode->setData(2);
//    CHECK(newNode->getData() == 2);
//    delete(newNode);
//}
//
//TEST_CASE("SetPNext", "") {
//    Node *pNextNode = new Node(10);
//    Node checkNode;
//    checkNode.setData(4);
//    checkNode.setPNext(pNextNode);
//    CHECK(checkNode.getPNext().getData() == 10);
//}