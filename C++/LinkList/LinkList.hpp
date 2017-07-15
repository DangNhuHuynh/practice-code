#ifndef PRACTICE_CODE_LINKLIST_HPP
#define PRACTICE_CODE_LINKLIST_HPP

#include <iostream>

class Node {
private:
    int data;
    Node *pNext;

public:
    Node();
    Node(const Node &node);
    Node(int data);
    ~Node();

    int getData();
    Node setData();
    Node setPNext();
};

class LinkList {
private:
    Node *pHead;
    Node *pTail;
    int size;

public:
    LinkList();
    LinkList(const LinkList &list);
    ~LinkList();

    int getSize() const;
    int getValueHead() const;
    int getValueTail() const;
    bool addHead(int data);
    bool addTail(int data);
    bool addAtIndex(int data, int index);
    void removeAll();
    bool removeHead();
    bool removeTail();
    bool removeAtIndex();
    bool find(int target);

    LinkList operator=(const LinkList &list);
    friend std::ostream operator<<(std::ostream &os, const LinkList &list);
};


#endif //PRACTICE_CODE_LINKLIST_HPP
