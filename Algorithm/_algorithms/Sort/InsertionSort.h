//
// Created by etins on 17-12-12.
//

#ifndef ALGORITHMS_INSERTIONSORT_H
#define ALGORITHMS_INSERTIONSORT_H

#include <iostream>
#include "SortTestHelper.h"

using namespace std;

//insertion Sort v1
template <typename T>
void insertionSort1(T arr[], int n) {
    for ( int i = 1; i < n; i++) {
        // 寻找元素 arr[i] 合适的插入位置
        for ( int j = i; j > 0 && arr[j] < arr[j-1];  j--) {
            swap(arr[j], arr[j - 1]);
        }
    }
}

/**
 * 插入排序 v2（一次 swap 要做三次赋值操作，优化后只要在内层循环只要一次）
 * 时间复杂度 O（n*n）
 * 但是在处理较为有序的序列时，其耗时很低，因为在内层循环有了一个提前退出的机制
 */
template <typename T>
void insertionSort2(T arr[], int n) {
    for ( int i = 1; i < n; i++) {
        // 寻找元素 arr[i] 合适的插入位置
        T e = arr[i];
        int j; // j保存元素e应该插入的位置
        for ( j = i; j > 0 && arr[j-1] > e;  j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

#endif //ALGORITHMS_INSERTIONSORT_H
