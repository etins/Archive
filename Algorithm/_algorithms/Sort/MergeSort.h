//
// Created by etins on 17-12-14.
//

#ifndef ALGORITHMS_MERGESORT_H
#define ALGORITHMS_MERGESORT_H

#include "iostream"

using namespace std;

template <typename T>
// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
void __merge(T arr[], int l, int mid, int r) {
	// VS 不支持动态长度数组，要使用 new 的方式申请 aux 空间
    T *aux = new T[r-l+1];
    for (int i = l; i <= r; i++) {
        aux[i-l] = arr[i];
    }
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (i > mid) {
            arr[k] = aux[j-l];
            j++;
        } else if (j > r) {
            arr[k] = aux[i-l];
            i++;
        } else if (aux[i-l] < aux[j-l]) {
            arr[k] = aux[i-l];
            i++;
        } else {
            arr[k] = aux[j-l];
            j++;
        }
    }
}

/**
 * 优化： 1. 针对数组长度小于16的可以采用插入排序或者选择排序
 *       2. 如果比较的两个数组已经是有序的，那么就没必要再做一个排序的比较了
 */
template <typename T>
// 递归使用归并排序，对arr[1...r]的范围进行排序
void __mergeSort(T arr[], int l, int r) {

    if (l >= r)
        return;

    int mid = (l+r)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    if (arr[mid] > arr[mid+1]) {
        __merge(arr, l, mid, r);
    }
}

/**
 * 自底向上的归并排序
 * 严格意义上来说：要比递归版本的慢一些
 * 意义：排序过程中不需要对数据进行随机访问，所以这种思路可以对聊表进行O(nlogn)级别的排序
 */
template <typename  T>
void mergeSortBU(T arr[], int n) {
    for (int sz = 1; sz <= n; sz += sz) {
        for (int i = 0; i + sz <= n; i += sz + sz) {
            __merge(arr, i, i + sz - 1, min(i + sz + sz -1, n-1));
        }
    }
}


template <typename T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n-1);
}

#endif //ALGORITHMS_MERGESORT_H
