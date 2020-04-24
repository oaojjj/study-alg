package week4_5;

import java.util.Arrays;
import java.util.Random;

public class Main {
	static final int TEST_SIZE[] = { 1000, 10000, 100000 };
	static final String SORT_NAME[] = { "Bubble", "Selection", "Insertion", "Merge", "Quick1", "Quick2", "Quick3",
			"Heap", "Library" };
	static SortingAlgorithm[] sortingAlgorithm = { new BubbleSort(), new SelectionSort(), new InsertionSort(),
			new MergeSort(), new QuickSort(0), new QuickSort(1), new QuickSort(2), new HeapSort() };

	static double[][] time = new double[9][6];

	public static void main(String[] args) {
		int[] randomArr = null;
		int[] reverseArr = null;

		startRandom(randomArr, 10);
		startReverse(reverseArr, 3);
		// 모든결과를 저장하고 출력을 한번에 하기때문에 3~4분정도 기다려야 출력 됩니다...
		printTable();
	}

	// random test
	static void startRandom(int[] random, int n) {
		for (int i = 0; i < 3; i++) {
			int size = TEST_SIZE[i];
			random = new int[size];

			for (int j = 0; j < n; j++) {
				int k;
				setArray(random, size, 0);
				for (k = 0; k < sortingAlgorithm.length; k++) {
					time[k][2 * i] += sortingAlgorithm[k].getSortTime(Arrays.copyOf(random, size));

					// 평균 계산
					if (j == n - 1)
						time[k][2 * i] /= 10;
				}
				// library
				time[k][2 * i] = getLibSortTime(Arrays.copyOf(random, size));
			}
		}
	}

	// reverse test
	static void startReverse(int[] reverseArr, int n) {
		for (int i = 0; i < n; i++) {
			int size = TEST_SIZE[i];
			int j;
			reverseArr = new int[size];
			setArray(reverseArr, size, 1);

			for (j = 0; j < sortingAlgorithm.length; j++) {
				// QuickSort는 10만부터(i==2) QuickSort(피봇이 마지막일 경우)뺴고는 다됌.
				// -1은 스택오버플로우 예외처리
				if (j == 4 && i == 2)
					time[j][2 * i + 1] = -1;
				else
					time[j][2 * i + 1] = sortingAlgorithm[j].getSortTime(Arrays.copyOf(reverseArr, size));
			}
			// library
			time[j][2 * i + 1] = getLibSortTime(Arrays.copyOf(reverseArr, size));
		}
	}

	// library sort
	static double getLibSortTime(int[] data) {
		long startTime = System.currentTimeMillis();
		Arrays.sort(data);
		long endTime = System.currentTimeMillis();
		return (endTime - startTime) / 1000.0;
	}

	// 테이블 출력 메소드
	static void printTable() {
		System.out
				.printf("\t  Random1,000\tReverse1,000\tRandom10,000\tReverse10,000\tRandom100,000\tReverse100,000\n");
		for (int i = 0; i < SORT_NAME.length; i++)
			System.out.printf("%-10s%10.3fs\t%11.3fs\t%11.3fs\t%12.3fs\t%12.3fs\t%13.3fs\n", SORT_NAME[i], time[i][0],
					time[i][1], time[i][2], time[i][3], time[i][4], time[i][5]);
	}

	// 배열 만들어 주는 메소드
	static void setArray(int[] arr, int n, int mode) {
		// reverse
		if (mode == 1) {
			for (int i = 0; i < n; i++)
				arr[i] = n - i;
		} else {
			// random
			for (int i = 0; i < n; i++) {
				arr[i] = new Random().nextInt(n) + 1;
			}
		}
	}

}
