//
// Created by etins on 17-12-12.
//

#ifndef ALGORITHMS_BUBBLESORT_H
#define ALGORITHMS_BUBBLESORT_H

#include <iostream>

using namespace std;

/**
 *  冒泡排序 v1
 */
template <typename T>
void bubbleSort1(T arr[], int n) {
    for (int i = n; i > 0; i--) {
        for (int j = 1; j < i; j++) {
            if (arr[j-1] > arr[j]) {
                swap(arr[j-1], arr[j]);
            }
        }
    }
}

/**
 * 冒泡排序 v2（如果比较完成之后没有交换，那么就说明是都已经排序，就无需再比较了）
 */
template<typename T>
void bubbleSort2( T arr[] , int n){
    bool swapped;
    do{
        swapped = false;
        for( int i = 1 ; i < n ; i ++ )
            if( arr[i-1] > arr[i] ) {
                swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        n --;
    }while(swapped);
}


#endif //ALGORITHMS_BUBBLESORT_H
