#include <iostream>
#include "Map/CMap.h"
using namespace std;

int main() {
    MNode *node1 = new MNode('A');
    MNode *node2 = new MNode('B');
    MNode *node3 = new MNode('C');
    MNode *node4 = new MNode('D');
    MNode *node5 = new MNode('E');
    MNode *node6 = new MNode('F');

    CMap *pMap = new CMap(6);
    pMap->addNode((node1));
    pMap->addNode((node2));
    pMap->addNode((node3));
    pMap->addNode((node4));
    pMap->addNode((node5));
    pMap->addNode((node6));

    pMap->setValueToMatrixForUndirectedGraph(0, 1, 6);
    pMap->setValueToMatrixForUndirectedGraph(0, 4, 5);
    pMap->setValueToMatrixForUndirectedGraph(0, 5, 1);
    pMap->setValueToMatrixForUndirectedGraph(1, 2, 3);
    pMap->setValueToMatrixForUndirectedGraph(1, 5, 2);
    pMap->setValueToMatrixForUndirectedGraph(2, 5, 8);
    pMap->setValueToMatrixForUndirectedGraph(2, 3, 7);
    pMap->setValueToMatrixForUndirectedGraph(3, 5, 4);
    pMap->setValueToMatrixForUndirectedGraph(3, 4, 2);
    pMap->setValueToMatrixForUndirectedGraph(4, 5, 9);
    pMap->primTree(0);
    return 0;
}