//
// Created by etins on 17-11-24.
//

#include "BinaryTreeL.h"
#include <iostream>
using namespace std;

BinaryTreeL::BinaryTreeL() {
    m_pRoot = new Node();
}

BinaryTreeL::~BinaryTreeL() {
    DeleteNode(0, NULL);
}

Node* BinaryTreeL::SearchNode(int nodeIndex) {
    return m_pRoot->SearchNode((nodeIndex));
}

bool BinaryTreeL::AddNode(int nodeIndex, int direction, Node *pNode) {

    Node *temp = SearchNode(nodeIndex);
    if (temp == NULL) {
        return false;
    }
    cout << "对 node 节点为" << temp->index << "添加节点" << endl;
    Node *node = new Node();
    node->index = pNode->index;
    node->data = pNode->data;

    if (direction == 0) {
        temp->pLChild = node;
    }
    if (direction == 1) {
        temp->pRChild = node;
    }
    return true;
}

bool BinaryTreeL::DeleteNode(int nodeINdex, Node *pNode) {
    Node *temp = SearchNode(nodeINdex);
    if (temp == NULL) {
        return false;
    }
    if (pNode != NULL) {
        pNode->data = temp->data;
    }
    temp->DeleteNode();
    return true;
}

void BinaryTreeL::PreordeTraversal() {
    m_pRoot->PreorderTraversal();
}

void BinaryTreeL::InorderTraversal() {
    m_pRoot->InorderTraversal();
}

void BinaryTreeL::PostorderTraversal() {
    m_pRoot->PostorderTraversal();
}
















