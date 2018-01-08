//
// Created by etins on 17-11-24.
//

#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H


#include "Node.h"

class BinaryTreeL {
public:
    BinaryTreeL();
    ~BinaryTreeL();
    Node *SearchNode(int nodeIndex);
    bool AddNode(int nodeIndex, int direction, Node *pNode);
    bool DeleteNode(int nodeINdex, Node *pNode);
    void PreordeTraversal();
    void InorderTraversal();
    void PostorderTraversal();

private:
    Node *m_pRoot;
};


#endif //DATASTRUCTURE_BINARYTREE_H
