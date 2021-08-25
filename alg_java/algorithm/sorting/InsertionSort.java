package algorithm.sorting;

/**
 * 삽입 정렬
 * 앞에서 부터 차례로 비교해 자신의 자리를 찾기전까지 시프트하고 찾으면 삽입하는 것
 * Best = n
 * Avg = n^2
 * Worst = n^2
 */
public class InsertionSort {
    int[] data;
    int n;

    public InsertionSort(int[] data) {
        this.data = data;
        n = data.length;
    }

    public void sort() {
        int key, j;
        for (int i = 1; i < n; i++) {
            key = data[i];
            j = i - 1;
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = key;
        }
    }
}
