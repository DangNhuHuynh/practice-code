#ifndef PRACTICE_CODE_LINKLIST_HPP
#define PRACTICE_CODE_LINKLIST_HPP

#include <iostream>

class Node {
private:
    int data;
    Node *pNext;

public:
    /**
     * Node default constructor
     */
    Node();

    /**
     * Node copy constructor
     *
     * @param node
     */
    Node(const Node &node);

    /**
     * Node constructor with param
     *
     * @param data
     */
    Node(int data);

    /**
     * Destructor
     *
     */
    ~Node();

    /**
     * Return data
     *
     * @return
     */
    int getData();

    /**
     * Set data
     *
     * @param data
     * @return Node
     */
    Node setData(int data);

    /**
     * Set pNext
     *
     * @return Node
     */
    Node setPNext(Node *);

    /**
     * get pNext
     *
     * @return Node
     */
    Node getPNext();
};

class LinkList {
private:
    Node *pHead;
    Node *pTail;
    int size;

public:
    /**
     * Link List default constructor
     *
     */
    LinkList();

    /**
     * LinkList copy constructor
     *
     * @param list
     */
    LinkList(const LinkList &list);

    /**
     * Destructor LinkList
     *
     */
    ~LinkList();

    /**
     * Return size of LinkList
     *
     * @return size
     */
    int getSize() const;

    /**
     * Return value at head of LinkList
     *
     * @return valueHead
     */
    int getValueHead() const;

    /**
     * Return value at the end of LinkList
     *
     * @return valueTail
     */
    int getValueTail() const;

    /**
     * Add Node in LinkList
     *
     * @param data
     * @return true or false
     */
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
