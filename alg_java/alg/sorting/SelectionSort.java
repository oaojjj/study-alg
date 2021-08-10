package alg.sorting;

import alg.Utils;

/**
 * 선택 정렬
 * 최솟값 또는 최댓값을 찾아서 맨 끝으로 보낸다
 * Best = n^2
 * Avg = n^2
 * Worst = n^2
 */
public class SelectionSort {
    int[] data;
    int n;

    public SelectionSort(int[] data) {
        this.data = data;
        this.n = data.length;
    }

    public void sort() {
        int max;
        for (int i = n - 1; i > 0; i--) {
            max = i;
            for (int j = 0; j < i; j++) {
                if (data[max] < data[j])
                    max = j;
            }
            if (i != max)
                Utils.swap(data, i, max);
        }
    }
}
