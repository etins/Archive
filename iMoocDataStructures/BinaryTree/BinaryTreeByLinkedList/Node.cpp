//
// Created by etins on 17-11-24.
//

#include "Node.h"
#include <iostream>
using namespace std;

Node::Node() {
    index = 0;
    data = 0;
    pLChild = NULL;
    pRChild = NULL;
    pParent = NULL;
}

Node* Node::SearchNode(int nodeIndex) {
    cout << "对象是" <<this->index << endl;
    cout << "要找的是" << nodeIndex << endl;
    if (this->index == nodeIndex) {
        cout << "找到的对象是" << this->index << endl;
        return this;
    }
    if (this->pLChild != NULL) {
        Node *temp =  this->pLChild->SearchNode(nodeIndex);
        if (temp != NULL) {
            return temp;
        }
    }
    if (this->pRChild != NULL) {
        Node *temp = this->pRChild->SearchNode(nodeIndex);
        if (temp != NULL) {
            return  temp;
        }
    }
    return NULL;
}

void Node::DeleteNode() {
    if (this->pLChild != NULL) {
        this->pLChild->DeleteNode();
    }
    if (this->pRChild != NULL) {
        this->pRChild->DeleteNode();
    }
    if (this->pParent != NULL) {
        if (this->pParent->pLChild == this) {
            this->pParent->pLChild = NULL;
        }
        if (this->pParent->pRChild == this) {
            this->pParent->pRChild = NULL;
        }
    }
    delete this;
}

void Node::PreorderTraversal() {
    cout << this->index << "---" << this->data << endl;
    if (this->pLChild != NULL) {
        this->pLChild->PreorderTraversal();
    }
    if (this->pRChild != NULL) {
        this->pRChild->PreorderTraversal();
    }
}

void Node::InorderTraversal() {
    if (this->pLChild != NULL) {
        this->pLChild->InorderTraversal();
    }
    cout << this->index << "---" << this->data << endl;
    if (this->pRChild != NULL) {
        this->pRChild->InorderTraversal();
    }
}

void Node::PostorderTraversal() {
    if (this->pRChild != NULL) {
        this->pRChild->PostorderTraversal();
    }
    cout << this->index << "---" << this->data << endl;
    if (this->pLChild != NULL) {
        this->pLChild->PostorderTraversal();
    }
}














