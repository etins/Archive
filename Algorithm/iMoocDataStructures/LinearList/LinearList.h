//
// Created by etins on 17-11-21.
//

#ifndef DATASTRUCTURE_LIST_H
#define DATASTRUCTURE_LIST_H


class LinearList {
public:
    LinearList(int size);
    ~LinearList();
    void ClearList();
    bool ListEmpty();
    int ListLength();
    bool GetElem(int i, int *e);
    int LocateElem(int *e);
    bool PriorElem(int *currentElem, int *preElem);
    bool NextElem(int *currentElem, int *nextElem);
    bool ListInsert(int i, int *e);
    bool ListDelete(int i, int *e);
    void ListTraverse();

private:
    int *m_pList;
    int m_iSize;
    int m_iLength;
};


#endif //DATASTRUCTURE_LIST_H
