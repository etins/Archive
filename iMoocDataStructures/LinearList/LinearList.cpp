//
// Created by etins on 17-11-21.
//

#include "LinearList.h"
#include <iostream>
using namespace std;

LinearList::LinearList(int size) {
    m_iSize = size;
    m_pList = new int[m_iSize];
    m_iLength = 0;
}

LinearList::~LinearList() {
    delete []m_pList;
    m_pList = NULL;
}

void LinearList::ClearList() {
    m_iLength = 0;
}

bool LinearList::ListEmpty() {
    return m_iLength == 0 ? true : false;
}

int LinearList::ListLength() {
    return m_iLength;
}

bool LinearList::GetElem(int i, int *e) {
    if (i < 0 || i >= m_iLength) {
        return false;
    } else {
        *e = m_pList[i];
        return true;
    }
}

int LinearList::LocateElem(int *e) {
    for (int i = 0; i < m_iLength; i++) {
        if (m_pList[i] == *e) {
            return i;
        }
    }
    return -1;
}

bool LinearList::PriorElem(int *currentElem, int *preElem) {
    int temp = LocateElem(currentElem);
    if (temp == 0 || temp == -1) {
        return false;
    } else {
        *preElem = m_pList[--temp];
        return true;
    }
}

bool LinearList::NextElem(int *currentElem, int *nextElem) {
    int temp = LocateElem(currentElem);
    if (temp == m_iLength || temp == -1) {
        return false;
    } else {
        *nextElem = m_pList[++temp];
        return true;
    }
}

void LinearList::ListTraverse() {
    for (int i = 0; i < m_iLength; i++) {
        cout << m_pList[i] << endl;
    }
}

bool LinearList::ListInsert(int i, int *e) {
    if (i < 0 || i > m_iLength) {
        return false;
    }
    for (int k = m_iLength - 1; k >= i; k--) {
        m_pList[k+1] = m_pList[k];
    }
    m_pList[i] = *e;
    m_iLength++;
    return true;
}

bool LinearList::ListDelete(int i, int *e) {
    if (i < 0 || i >= m_iLength) {
        return false;
    }
    *e = m_pList[i];
    for (int k = i + 1; i < m_iLength; i++) {
        m_pList[k-1] = m_pList[k];

    }
    m_iLength--;
    return true;
}




















