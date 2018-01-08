/**
 * 待判断的数值每次都选择数组最左侧的值 version1
 * 所以优化的第一个思路：随机选取数组中的值，这样可以避免复杂度到 O(n*n)
 * 对于近乎有序的数组，可以提高一些
*/
// 自定义排序
template <typename T>
void uswap(T arr[], int i, int j) {
	T temp = arr[j];
	arr[j] = arr[i];
	arr[i] = temp;
}

// 对 arr[l...r]部分进行partition操作
// 返回p,并且arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r) {
	//swap( arr[l], arr[rand()%(r-l+1) + l]); 随机取值
	T v = arr[l];
	// arr[l+1...j] < v; arr[j+1...r) > v
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < v) {
			j++;
			uswap(arr, j, i);
		}
	}
	uswap(arr, l, j);
	return j;
}

// 对 arr[l...r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r) {
	if (l >= r) {
		return;
	}
	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

template <typename T>
void quickSort(T arr[], int n) {
	__quickSort(arr, 0, n - 1);
}