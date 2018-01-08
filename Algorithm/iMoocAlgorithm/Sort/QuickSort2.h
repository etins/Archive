/**
* ˫·���� version2
* ��ʹ�������������д������ظ�Ԫ�أ�Ҳ�������Ϊ��������
* �ֱ����ߺ��ұ߿�ʼ���������������С��ָ��ֵ��Ԫ�أ��ұ��������������ָ��ֵ��Ԫ�أ���ʱ����λ��

*/
// �Զ�������
template <typename T>
void uswap(T arr[], int i, int j) {
	T temp = arr[j];
	arr[j] = arr[i];
	arr[i] = temp;
}

// �� arr[l...r]���ֽ���partition����
// ����p,����arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
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

// �� arr[l...r]���ֽ��п�������
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