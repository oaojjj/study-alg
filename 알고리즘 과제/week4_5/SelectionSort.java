package week4_5;

public class SelectionSort extends SortingAlgorithm {
	// 선택 정렬
	// 가장 작은 수를 찾아(선택) 자리를 확정지음
	public void sort(int[] a) {
		mLength = a.length;
		for (int i = 0; i < mLength - 1; i++) {
			int min = i;
			for (int j = i + 1; j < mLength; j++) {
				if (a[min] > a[j])
					min = j;
			}
			swap(a, i, min);
		}
	}
}