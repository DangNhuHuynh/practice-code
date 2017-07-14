#include "LinkList.h"

/* =============== Method for Node =================== */
/**
 * Allocate Node, set data for Node and return
 *
 * @param target `int'
 * @return Node*
 */
Node *createNode(int target) {
    Node *result;
    result = (Node*) malloc(sizeof(Node));
    result->data = target;
    result->pNext = NULL;
    return result;
}

/* =============== Method for Link List ==================== */
/**
 * Init LinkList
 */
void LinkList(LinkList &List){
    List.pHead = List.pTail = NULL;
}

/**
 * Add Node to head of LinkList
 *
 * @param result `Node*'
 * @param key `int'
 */
void addHead(LinkList &List, Node *target) {
   if (List.pHead == NULL) {
       List.pHead =  List.pTail = target;
   } else {
       target.pNext = List.pHead;
       List.pHead = target;
   }
}

/**
 * Add Node to end of LinkList
 */
void addTail(LinkList &List, Node *target) {
    if (List.pHead == NULL) {
        List.pHead = List.pTail = target;
    } else {
        List.pTail->pNext = target;
        List.pTail = target;
    }
}



