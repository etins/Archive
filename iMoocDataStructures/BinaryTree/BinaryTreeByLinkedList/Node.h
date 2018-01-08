//
// Created by etins on 17-11-24.
//

#ifndef DATASTRUCTURE_NODE_H
#define DATASTRUCTURE_NODE_H


class Node {
public:
    Node();
    Node *SearchNode(int nodeIndex);
    void DeleteNode();
    void PreorderTraversal();
    void InorderTraversal();
    void PostorderTraversal();
    int index;
    int data;
    Node *pLChild;
    Node *pRChild;
    Node *pParent;
};


#endif //DATASTRUCTURE_NODE_H
