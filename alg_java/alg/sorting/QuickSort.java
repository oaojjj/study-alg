package alg.sorting;
import alg.Utils;


/**
 * 퀵 정렬
 * 하나의 값(pivot)을 기준으로 작은 값은 왼쪽으로 큰 값은 오른쪽으로 나누어 분할하고 정복(정렬)한다.
 * Best = n * log n
 * Avg = n * log n
 * Worst = n^2
 */
public class QuickSort {
    int[] data;
    int n;

    public QuickSort(int[] data) {
        this.data = data;
        n = data.length;
    }

    public void sort(int left, int right) {
        if (left < right) {
            int pivot = partition(left, right); // 분할 정렬
            sort(left, pivot - 1); // 왼쪽 파티션
            sort(pivot, right); // 오른쪽 파티션
        }
    }

    private int partition(int l, int r) {
        int m = (l + r) / 2;

        // median of left, middle, right
        int pivot = Math.min(data[l], data[m]) ^ Math.min(data[m], data[r]) ^ Math.min(data[r], data[l]);

        // 필요한가?
        // int pivotIndex = data[l] == pivot ? l : data[r] == pivot ? r : m;
        // Utils.swap(data, pivotIndex, m);

        while (l <= r) {
            while (data[l] < pivot) l++;
            while (data[r] > pivot) r--;
            if (l <= r) {
                Utils.swap(data, l, r);
                l++;
                r--;
            }
        }
        return l;
    }

    public void sortVerTwo(int left, int right) {
        if (left < right) {
            int start = left, end = right;
            int m = (start + end) / 2;
            // median of left, middle, right
            int pivot = Math.min(data[start], data[m]) ^ Math.min(data[m], data[end]) ^ Math.min(data[end], data[start]);

            while (start < end) {
                while (data[start] < pivot) start++;
                while (data[end] > pivot) end--;
                if (start < end) {
                    Utils.swap(data, start, end);
                }
            }
            sortVerTwo(left, start - 1); // 왼쪽 파티션
            sortVerTwo(start + 1, right); // 오른쪽 파티션

        }
    }
}