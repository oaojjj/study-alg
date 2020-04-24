package week4_5;

public class HeapSort extends SortingAlgorithm {

	public void heapSort(int[] arr) {

		// init max heap
		for (int i = mLength / 2; i >= 0; i--)
			maxHeapify(arr, mLength, i);

		for (int i = mLength - 1; i > 0; i--) {
			swap(arr, 0, i);
			maxHeapify(arr, i, 0);
		}

	}

	// p:부모노드, l:왼쪽자식노드, r:오른쪽자식노드
	private void maxHeapify(int[] arr, int n, int i) {
		int p = i;
		int l = i * 2 + 1;
		int r = i * 2 + 2;

		// root가 left보다 작다면
		if (l < n && arr[p] < arr[l])
			p = l;

		if (r < n && arr[p] < arr[r])
			p = r;

		if (i != p) {
			swap(arr, p, i);
			maxHeapify(arr, n, p);
		}

	}

	@Override
	public void sort(int[] a) {
		mLength = a.length;
		heapSort(a);
	}
}
