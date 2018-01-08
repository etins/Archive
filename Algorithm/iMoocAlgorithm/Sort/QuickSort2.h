/**
* 双路快排 version2
* 即使在排序数组中有大量的重复元素，也将其均分为两个子树
* 分别从左边和右边开始，左边遇到不满足小于指定值的元素，右边遇到不满足大于指定值的元素，此时交换位置

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
	uswap(arr, l, rand()%(r-l+1) + l); 
	T v = arr[l];
	// arr[l+1...i) <= v; arr(j...r] > v
	int i = l + 1, j = r;
	while (true) {
		while (i <= r && arr[i] < v) i++;
		while (j >= l+1 && arr[j] > v) j--;
		if (i > j) break;
		uswap(arr, i, j);
		i++;
		j--;
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
void quickSort2(T arr[], int n) {
	__quickSort(arr, 0, n - 1);
}