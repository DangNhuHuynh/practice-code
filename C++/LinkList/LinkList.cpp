//#include "LinkList.hpp"
//
//Node::Node() {
//    this->pNext = NULL;
//    this->data = 0;
//}
//
//Node::Node(int data) {
//    this->data = data;
//    this->pNext = NULL;
//}
//
//Node::Node(const Node &node) {
//    this->data = node.data;
//    this->pNext = node.pNext;
//}
//
//Node::~Node() {
//
//}
//
//int Node::getData() {
//    return this->data;
//}
//
//Node Node::setData(int data) {
//    this->data = data;
//    return *this;
//}
//
//Node Node::setPNext(Node *target) {
//    this->pNext = target;
//    return *this;
//}
//
//Node Node::getPNext() {
//    return *this->pNext;
//}
//
//LinkList::LinkList() {
//    this->pHead = this->pTail = NULL;
//    this->size = 0;
//}
//
//LinkList::LinkList(const LinkList &list) {
//    this->pHead = list.pHead;
//    this->pTail = list.pTail;
//    this->capacity = list.capacity;
//}
//
//LinkList::~LinkList() {
//
//}
//
//int LinkList::getSize() const {
//    return this->size;
//}
//
//int LinkList::getValueHead() const {
//    return this->pHead->getData();
//}
//
//int LinkList::getValueTail() const {
//    return this->pTail->getData();
//}
//
//bool LinkList::find(int target) {
//    if(this->pHead == NULL){
//        return false;
//    }
//
//    Node *index;
//    for (index = this->pHead; this->pHead; index->setPNext(&index->getPNext()))
//}
//
//bool LinkList::addHead(int data) {
//    Node *newNode = new Node(data);
//    if (this->pHead == NULL) {
//        this->pHead = this->pTail = newNode;
//    } else {
//        newNode->setPNext(this->pHead);
//        this->pHead = newNode;
//    }
//    return true;
//}
//
//bool LinkList::addTail(int data) {
//    Node *newNode = new Node(data);
//    if(this->pHead == NULL) {
//        this->pHead = this->pTail = newNode;
//    } else {
//        this->pTail->= newNode;
//    }
//}
//
//
