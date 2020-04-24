package week4_5;

import java.util.Random;

public class QuickSort extends SortingAlgorithm {
	private int mPivotMode;

	public QuickSort(int pivotMode) {
		mPivotMode = pivotMode;
	}

	// 퀵 정렬
	// 피봇을 기준으로 분할하고 정렬 합병
	private void quickSort(int arr[], int l, int r) {
		if (l < r) {
			// 분할
			int p = partition(arr, l, r, mPivotMode);

			quickSort(arr, l, p - 1);
			quickSort(arr, p, r);
		}
	}

	// #mode 0:마지막 값, 1:중간 값, 2:랜덤 값
	private int partition(int[] arr, int l, int r, int mode) {
		int mid = l + (r - l) / 2;
		int tmp = mid;
		int pivot;

		// 피봇값이 중간에 위치할 경우와 마지막에 위치할경우의 로직이 다르기 때문에 tmp에 저장후 mid위치와 스왑해준다.
		if (mode == 0) {
			pivot = arr[r];
			tmp = r;
		} else if (mode == 1) {
			pivot = Math.min(arr[l], arr[mid]) ^ Math.min(arr[mid], arr[r]) ^ Math.min(arr[r], arr[l]);
			if (pivot == arr[l])
				tmp = l;
			else if (pivot == arr[r])
				tmp = r;
		} else {
			tmp = new Random().nextInt(r - l + 1) + l;
			pivot = arr[tmp];
		}

		// pivot이 정해지면 tmp에 저장한후 중간에 있는 값과 스왑을 한다.
		if (mid != tmp)
			swap(arr, mid, tmp);

		// 실제 진행되는 정렬 부분
		while (l <= r) {
			while (arr[l] < pivot)
				l++;
			while (arr[r] > pivot)
				r--;
			if (l <= r) {
				swap(arr, l, r);
				l++;
				r--;
			}
		}
		return l;
	}

	@Override
	public void sort(int[] a) {
		mLength = a.length;
		quickSort(a, 0, mLength - 1);
	}
}
