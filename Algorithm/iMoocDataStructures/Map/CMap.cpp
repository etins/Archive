//
// Created by etins on 17-11-26.
//

#include "CMap.h"
#include <iostream>
#include <cstring>

using namespace std;

CMap::CMap(int capacity) {
    m_iCapacity = capacity;
    m_iNodeCount = 0;
    m_pNodeArray = new MNode[m_iCapacity];
    m_pMatrix = new int[m_iCapacity * m_iCapacity];
    memset(m_pMatrix, 0, m_iCapacity * m_iCapacity * sizeof(int));

    m_pEdge = new Edge[m_iCapacity - 1];
}

CMap::~CMap() {
    delete []m_pNodeArray;
    delete []m_pMatrix;
}

bool CMap::addNode(MNode *pNode) {
    if (pNode == NULL) {
        return false;
    }
    m_pNodeArray[m_iNodeCount++].m_cData = pNode->m_cData;
    return true;
}

void CMap::resetNode() {
    for (int i = 0; i < m_iNodeCount; i++) {
        m_pNodeArray[i].m_bIsVisited = false;
    }
}

bool CMap::setValueToMatrixForDirectGraph(int row, int col, int val) {
    if (row < 0 || row >= m_iCapacity) {
        return false;
    }
    if (col < 0 || col >= m_iCapacity) {
        return  false;
    }
    m_pMatrix[row * m_iCapacity + col] = val;
    return true;
}

bool CMap::setValueToMatrixForUndirectedGraph(int row, int col, int val) {
    if (row < 0 || row >= m_iCapacity) {
        return false;
    }
    if (col < 0 || col >= m_iCapacity) {
        return  false;
    }
    m_pMatrix[row * m_iCapacity + col] = val;
    m_pMatrix[col * m_iCapacity + row] = val;
    return true;
}

void CMap::printMatrix() {
    for (int i = 0; i < m_iCapacity; i++) {
        for (int k = 0; k < m_iCapacity; k++) {
            cout << m_pMatrix[i * m_iCapacity + k] << " ";
        }
        cout << endl;
    }
}

bool CMap::getValueFromMatrix(int row, int col, int &val) {
    if (row < 0 || row >= m_iCapacity) {
        return false;
    }
    if (col < 0 || col >= m_iCapacity) {
        return  false;
    }
    val = m_pMatrix[row * m_iCapacity + col];
    return true;
}

void CMap::depthFirstTraverse(int nodeIndex) {
    int value = 0;
    cout << m_pNodeArray[nodeIndex].m_cData << " ";
    m_pNodeArray[nodeIndex].m_bIsVisited = true;

    for (int i = 0; i < m_iCapacity; i++) {
        getValueFromMatrix(nodeIndex, i, value);
        if (value == 1) {
            if (m_pNodeArray[i].m_bIsVisited) {
                continue;
            } else {
                depthFirstTraverse(i);
            }
        } else {
            continue;
        }
    }
}

void CMap::breadthFirstTraverse(int nodeIndex) {
    cout << m_pNodeArray[nodeIndex].m_cData << " ";
    m_pNodeArray[nodeIndex].m_bIsVisited = true;

    vector<int> curVec;
    curVec.push_back(nodeIndex);
    breadthFirstTraverseImp(curVec);

}

void CMap::breadthFirstTraverseImp(vector<int> preVec) {
    int value = 0;
    vector<int> curVec;
    for (int j = 0; j < (int)preVec.size(); j++) {
        for (int i = 0; i < m_iCapacity; i++) {
            getValueFromMatrix(preVec[j], i, value);
            if (value != 0) {
                if (m_pNodeArray[i].m_bIsVisited) {
                    continue;
                } else {
                    cout << m_pNodeArray[i].m_cData << " ";
                    m_pNodeArray[i].m_bIsVisited = true;

                    curVec.push_back(i);
                }
            }
        }
    }

    if (curVec.size() == 0) {
        return;
    } else {
        breadthFirstTraverseImp(curVec);
    }
}

// 生成最小生成树
void CMap::primTree(int nodeIndex) {
    int value = 0;
    int edgeCount = 0;
    vector<int> nodeVec;
    vector<Edge> edgeVec;

    cout << m_pNodeArray[nodeIndex].m_cData << endl;

    nodeVec.push_back(nodeIndex);
    m_pNodeArray[nodeIndex].m_bIsVisited = true;
    while (edgeCount < m_iCapacity - 1) {
        int temp = nodeVec.back();
        for (int i = 0; i < m_iCapacity; i++) {
            getValueFromMatrix(temp, i, value);
            if (value != 0) {
                if (m_pNodeArray[i].m_bIsVisited) {
                    continue;
                } else {
                    Edge edge(temp, i, value);
                    edgeVec.push_back(edge);
                }
            }
        }
        // 从柯选边集合中找出最小的边
        int edgeIndex = getMinEdge(edgeVec);
        edgeVec[edgeIndex].m_bSelected = true;

        cout << edgeVec[edgeIndex].m_iNodeIndexA << "----" << edgeVec[edgeIndex].m_iNodeIndexB;
        cout << "   " << edgeVec[edgeIndex].m_iWeightValue << endl;

        m_pEdge[edgeCount] = edgeVec[edgeIndex];
        edgeCount++;

        int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;
        nodeVec.push_back(nextNodeIndex);
        m_pNodeArray[nextNodeIndex].m_bIsVisited = true;
        cout << m_pNodeArray[nextNodeIndex].m_cData << endl;
    }
}

int CMap::getMinEdge(vector<Edge> edgeVec) {
    int minWeight = 0;
    int edgeIndex = 0;
    int i = 0;
    for (i = 0; i < edgeVec.size(); i++) {
        if (!edgeVec[i].m_bSelected) {
            minWeight = edgeVec[i].m_iWeightValue;
            edgeIndex = i;
            break;
        }
    }
    if (minWeight == 0) {
        return -1;
    }
    for (; i < edgeVec.size(); i++) {
        if (edgeVec[i].m_bSelected) {
            continue;
        } else {
            if (minWeight > edgeVec[i].m_iWeightValue) {
                minWeight = edgeVec[i].m_iWeightValue;
                edgeIndex = i;
            }
        }
    }

    return edgeIndex;
}







