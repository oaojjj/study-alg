package week2;

import java.util.Scanner;

//배열을 비교하는 메소드와 반복을 담당하는 메소드를 분리해도 되겠지만 하나의 메소드로 해보고 싶음
public class Prob2 {
	static Scanner sc = new Scanner(System.in);

	// i: index_size, j: 0, n: array_length
	static int getRankSize(int[] arr, int i, int j, int n) {
		// outer loop
		if (i >= 0) {
			// inner loop
			if (j < n) {
				int rank = 0;
				if (arr[i] > arr[j])
					rank++;
				rank += getRankSize(arr, i, j + 1, n);
				if (j == 0)
					System.out.print(rank + 1 + " ");
				return rank;
			}
			@SuppressWarnings("unused")
			int tmp = getRankSize(arr, i - 1, 0, n);
		}
		return 0;
	}

	// 배열 입력 재귀함수
	static void readArray(int[] arr, int n) {
		if (n == 0)
			return;
		else {
			readArray(arr, n - 1);
			arr[n - 1] = sc.nextInt();
		}
	}
}
