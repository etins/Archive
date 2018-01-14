#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "QuickSort1.h"
#include "QuickSort3.h"


using namespace std;


int main() {
    int n = 1000;
    int *arr = SortTestHelper::generateRandomArray(n ,0, 10);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
	int *arr3 = SortTestHelper::copyIntArray(arr, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);
	//SortTestHelper::testSort("Quick Sort3", quickSort3, arr3, n);

    delete[] arr;
	delete[] arr2;
	delete[] arr3;
	system("pause");
}