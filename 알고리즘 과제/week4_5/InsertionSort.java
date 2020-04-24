package week4_5;

public class InsertionSort extends SortingAlgorithm {
	// 삽입 정렬
	// 새로운 숫자(key)가 삽입되면 큰 수를 오른쪽으로 쉬프트해서 작은 수의 자리를 확정지음
	@Override
	public void sort(int[] a) {
		mLength = a.length;
		for (int i = 1; i < mLength; i++) {
			int key = a[i];
			int j = i - 1;
			while (j >= 0 && key < a[j]) {
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = key;
		}
	}
}
