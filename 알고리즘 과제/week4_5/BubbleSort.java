package week4_5;

public class BubbleSort extends SortingAlgorithm {
	// 버블 정렬
	// 앞에서 부터 두 숫자씩 비교하면서 큰 수의 자리를 확정지음
	@Override
	public void sort(int[] a) {
		mLength = a.length;
		for (int i = 0; i < mLength - 1; i++) {
			for (int j = 0; j < mLength - i - 1; j++) {
				if (a[j] > a[j + 1])
					swap(a, j, j + 1);
			}
		}
	}
}