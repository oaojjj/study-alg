package alg.sorting;

import alg.Utils;

/**
 * 버블 소트
 * 근접한 두 수를 비교해서 큰 값을 뒤로 보낸다
 * Best = n^2
 * Avg = n^2
 * Wort = n^2
 */
public class BubbleSort {
    int[] data;
    int n;

    public BubbleSort(int[] data) {
        this.data = data;
        this.n = data.length;
    }

    public void sort() {
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (data[j] > data[j + 1]) {
                    Utils.swap(data, j, j + 1);
                }
            }
        }
    }
}
