//
// Created by etins on 17-11-22.
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void ClearList();
    bool ListEmpty();
    int ListLength();
    bool GetElem(int i, Node *pNode);
    int LocateElem(Node *pNode);
    bool PriorElem(Node *pCurrentNode, Node *pPreNode);
    bool NextElem(Node *pCurrentNode, Node *pNextElem);
    void ListTraverse();
    bool ListInsert(int i, Node *pNode);
    bool ListDelete(int i, Node *pNode);
    bool ListInsertHead(Node *pNode);
    bool ListInsertTail(Node *pNode);


private:
    Node *m_pList;
    int m_iLength;
};


#endif //DATASTRUCTURE_LINKEDLIST_H
