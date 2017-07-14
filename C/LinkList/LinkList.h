#ifndef PRACTICE_CODE_LINKLIST_H
#define PRACTICE_CODE_LINKLIST_H

/**
 * Struct Node used for LinkList
 */
struct Node {
    int data;
    Node *pNext;
};

/**
 * Struct Link List
 */
struct LinkList {
    Node *pHead;
    Node *pTail;
};



#endif //PRACTICE_CODE_LINKLIST_H
