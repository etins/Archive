//
// Created by etins on 17-11-22.
//

#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    m_pList = new Node;
    m_pList->data = 0;
    m_pList->next = NULL;
    m_iLength = 0;
}

LinkedList::~LinkedList() {
    ClearList();
    delete m_pList;
    m_pList = NULL;
}

void LinkedList::ClearList() {
    Node *currentNode = m_pList->next;
    while (currentNode != NULL) {
        Node *temp = currentNode->next;
        delete currentNode;
        currentNode = temp;
    }
    m_pList->next = NULL;
}

bool LinkedList::ListEmpty() {
    return m_iLength == 0 ? true : false;
}

int LinkedList::ListLength() {
    return m_iLength;
}

bool LinkedList::ListInsertHead(Node *pNode) {
    Node *temp = m_pList->next;
    Node *newNode = new Node;
    if (newNode == NULL) {
        return false;
    }
    newNode->data = pNode->data;
    m_pList->next = newNode;
    newNode->next = temp;
    m_iLength++;
    return true;
}

bool LinkedList::ListInsertTail(Node *pNode) {
    Node *currentNode = m_pList;
    while(currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    Node *newNode = m_pList;
    if (newNode == NULL) {
        return false;
    }
    newNode->data = pNode->data;
    newNode->next = NULL;
    currentNode->next = newNode;
    m_iLength++;
    return true;
}

bool LinkedList::ListInsert(int i, Node *pNode) {
    if (i < 0 || i > m_iLength) {
        return false;
    }
    Node *currentNode = m_pList;
    for (int k = 0; k < i; k++) {
        currentNode = currentNode->next;
    }
    Node *newNode = m_pList;
    if (newNode == NULL) {
        return false;
    }
    newNode->data = pNode->data;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    return true;
}

bool LinkedList::ListDelete(int i, Node *pNode) {
    if (i < 0 || i >= m_iLength) {
        return false;
    }
    Node *currentNode = m_pList;
    Node *currentNodeBefore = NULL;
    for (int k = 0; k <= i; k++) {
        currentNodeBefore = currentNode;
        currentNode = currentNode->next;
    }
    currentNodeBefore->next = currentNode->next;
    pNode->data = currentNode->data;
    delete currentNode;
    currentNode = NULL;
    m_iLength--;
    return true;
}

bool LinkedList::GetElem(int i, Node *pNode) {
    if ( i < 0 || i >= m_iLength) {
        return false;
    }
    Node *currentNode = m_pList;
    if (currentNode == NULL) {
        return false;
    }
    for (int k = 0; k <= i; i++) {
        currentNode = currentNode->next;
    }
    pNode->data = currentNode->data;
    return true;
}

int LinkedList::LocateElem(Node *pNode) {
    Node *currentNode = m_pList;
    int count = 0;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
        if (currentNode->data == pNode->data) {
            return count;
        }
        count++;
    }
    return -1;
}

bool LinkedList::PriorElem(Node *pCurrentNode, Node *pPreNode) {
    Node *currentNode = m_pList;
    Node *tempNode = NULL;
    while (currentNode->next != NULL) {
        tempNode = currentNode;
        currentNode = currentNode->next;
        if (currentNode->data == pCurrentNode->data) {
            if (tempNode == m_pList) {
                return false;
            }
            pPreNode->data = tempNode->data;
            return true;
        }
    }
    return false;
}

bool LinkedList::NextElem(Node *pCurrentNode, Node *pNextElem) {
    Node *currentNode = m_pList;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
        if (currentNode->data == pCurrentNode->data) {
            if(currentNode == NULL) {
                return false;
            }
            pNextElem->data = currentNode->data;
            return true;
        }
    }
    return false;
}

void LinkedList::ListTraverse() {
    Node *currentNode = m_pList;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
        currentNode->printNode();
    }
}






















