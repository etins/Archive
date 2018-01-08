//
// Created by etins on 17-11-26.
//

#ifndef DATASTRUCTURE_CMAP_H
#define DATASTRUCTURE_CMAP_H

#include <cstdlib>
#include "Mnode.h"
#include <vector>
#include "Edge.h"
using namespace std;


class CMap {
public:
    CMap(int capacity);
    ~CMap();
    bool addNode(MNode *pNode);
    void resetNode();
    bool setValueToMatrixForDirectGraph(int row, int col, int val=1);
    bool setValueToMatrixForUndirectedGraph(int row, int col, int val=1);

    void printMatrix();

    void depthFirstTraverse(int nodeIndex);
    void breadthFirstTraverse(int nodeIndex);

    void primTree(int nodeIndex); //普里姆算法

private:
    bool getValueFromMatrix(int row, int col, int &val);
    void breadthFirstTraverseImp(vector<int> preVec);

    int getMinEdge(vector<Edge> edgeVec);

private:
    int m_iCapacity;
    int m_iNodeCount;
    MNode *m_pNodeArray;
    int *m_pMatrix;
    Edge *m_pEdge;
};


#endif //DATASTRUCTURE_CMAP_H
