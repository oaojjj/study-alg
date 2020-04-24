package week4_5;

public class MergeSort extends SortingAlgorithm {

	// 병합 정렬
	// 모든 숫자를 독립적인 수로 분할하는 과정을 거치고 하나씩 정복(정렬)하고 합병함
	private void mergeSort(int[] arr, int l, int r) {
		if (r > l) {
			int m = l + (r - l) / 2;

			mergeSort(arr, l, m);
			mergeSort(arr, m + 1, r);

			merge(arr, l, m, r);
		}
	}

	private void merge(int[] arr, int l, int m, int r) {
		int p = l;
		int q = m + 1;
		int i = l;

		while (p <= m && q <= r) {
			if (arr[p] <= arr[q])
				mTemp[i++] = arr[p++];
			else
				mTemp[i++] = arr[q++];
		}

		while (p <= m)
			mTemp[i++] = arr[p++];
		while (q <= r)
			mTemp[i++] = arr[q++];

		for (int k = l; k <= r; k++) {
			arr[k] = mTemp[k];
		}

	}

	@Override
	public void sort(int[] a) {
		mLength = a.length;
		setSize(mLength);
		mergeSort(a, 0, mLength - 1);
	}
}
