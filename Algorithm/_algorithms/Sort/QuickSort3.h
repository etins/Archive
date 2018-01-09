/**
* 双路快排 version2
* 即使在排序数组中有大量的重复元素，也将其均分为两个子树
* 分别从左边和右边开始，左边遇到不满足小于指定值的元素，右边遇到不满足大于指定值的元素，此时交换位置

*/

template <typename T>
void __quickSort3Ways(T arr[], int l, int r) {

	// 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
	swap(arr[l], arr[rand() % (r - l + 1) + l]);

	T v = arr[l];

	int lt = l;     // arr[l+1...lt] < v
	int gt = r + 1; // arr[gt...r] > v
	int i = l + 1;    // arr[lt+1...i) == v
	while (i < gt) {
		if (arr[i] < v) {
			swap(arr[i], arr[lt + 1]);
			i++;
			lt++;
		}
		else if (arr[i] > v) {
			swap(arr[i], arr[gt - 1]);
			gt--;
		}
		else { // arr[i] == v
			i++;
		}
	}

	swap(arr[l], arr[lt]);

	__quickSort3Ways(arr, l, lt - 1);
	__quickSort3Ways(arr, gt, r);
}

template <typename T>
void quickSort3(T arr[], int n) {
	srand(time(NULL));
	__quickSort3Ways(arr, 0, n - 1);
}