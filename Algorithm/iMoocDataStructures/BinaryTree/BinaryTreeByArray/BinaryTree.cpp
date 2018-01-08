//
// Created by etins on 17-11-23.
//

#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree(int size, int *pRoot) {
    m_iSize = size;
    m_pTree = new int[size];
    for (int i = 0; i < size; i++) {
        m_pTree[i] = 0;
    }
    m_pTree[0] = *pRoot;
}

BinaryTree::~BinaryTree() {
    delete []m_pTree;
    m_pTree = NULL;
}

int* BinaryTree::SearchNode(int nodeIndex) {
    if (nodeIndex < 0 || nodeIndex >= m_iSize) {
        return NULL;
    }
    if (m_pTree[nodeIndex] == 0) {
        return NULL;
    }
    return &m_pTree[nodeIndex];
}

bool BinaryTree::AddNode(int nodeIndex, int direction, int *pNode) {
    if (nodeIndex < 0 || nodeIndex >= m_iSize) {
        return false;
    }
    if (m_pTree[nodeIndex] == 0) {
        return false;
    }
    if (direction == 0) {
        if (nodeIndex * 2 + 1 >= m_iSize) {
            return false;
        }
        if (m_pTree[nodeIndex * 2 + 1] != 0) {
            return false;
        }
        m_pTree[nodeIndex * 2 + 1] = *pNode;
    } else {
        if (nodeIndex * 2 + 2 >= m_iSize) {
            return false;
        }
        if (m_pTree[nodeIndex * 2 + 2] != 0) {
            return false;
        }
        m_pTree[nodeIndex * 2 + 2] = *pNode;
    }
    return true;
}

bool BinaryTree::DeleteNode(int nodeIndex, int *pNode) {
    if (nodeIndex < 0 || nodeIndex >= m_iSize) {
        return false;
    }
    if (m_pTree[nodeIndex] == 0) {
        return false;
    }
    *pNode = m_pTree[nodeIndex];
    m_pTree[nodeIndex] = 0;
    return true;
}

void BinaryTree::TreeTraverse() {
    for (int i = 0; i < m_iSize; i++) {
        cout << m_pTree[i] << " ";
    }
}


















