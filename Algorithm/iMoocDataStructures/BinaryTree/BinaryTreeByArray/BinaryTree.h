//
// Created by etins on 17-11-23.
//

#ifndef DATASTRUCTURE_BinaryTreeL_H
#define DATASTRUCTURE_BinaryTreeL_H


class BinaryTree {
public:
    BinaryTree(int size, int *pRoot);
    ~BinaryTree();
    int *SearchNode(int nodeIndex);
    bool AddNode(int nodeIndex, int direction, int *pNode);
    bool DeleteNode(int nodeIndex, int *pNode);
    void TreeTraverse();

private:
    int *m_pTree;
    int m_iSize;

};


#endif //DATASTRUCTURE_BinaryTreeL_H
