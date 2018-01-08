/**
 * ���жϵ���ֵÿ�ζ�ѡ������������ֵ version1
 * �����Ż��ĵ�һ��˼·�����ѡȡ�����е�ֵ���������Ա��⸴�Ӷȵ� O(n*n)
 * ���ڽ�����������飬�������һЩ
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
	//swap( arr[l], arr[rand()%(r-l+1) + l]); ���ȡֵ
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
void quickSort(T arr[], int n) {
	__quickSort(arr, 0, n - 1);
}