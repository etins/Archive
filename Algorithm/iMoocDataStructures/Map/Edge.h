//
// Created by etins on 17-11-29.
//

#ifndef DATASTRUCTURE_EDGE_H
#define DATASTRUCTURE_EDGE_H


class Edge {
public:
    Edge(int nodeIndexA = 0, int nodeIndexB = 0, int weightValue = 0);
    int m_iNodeIndexA; // 起始点
    int m_iNodeIndexB; // 末尾点
    int m_iWeightValue; // 值
    bool m_bSelected; // 是否被选中
};


#endif //DATASTRUCTURE_EDGE_H
