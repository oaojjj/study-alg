package alg.sorting;

public class MergeSort {
    int[] data;
    int n;

    public MergeSort(int[] data) {
        this.data = data;
        n = data.length;
    }

    public void sort(int start, int end) {
        if (start < end) {
            int middle = (end + start) / 2;
            sort(start, middle); // left
            sort(middle + 1, end); // right
            merge(start, middle, end);
        }
    }

    private void merge(int s, int m, int e) {
        int k = s, i = s, j = m + 1;
        int[] temp = new int[n];

        // 왼쪽 루트와 오른쪽 루트중 한쪽의 값이 다 떨어질 때 까지 루프를 돌며 값 비교후 합병
        while (i <= m && j <= e) {
            if (data[i] <= data[j]) temp[k++] = data[i++];
            else temp[k++] = data[j++];
        }

        // 한쪽의 값이 다 삽입 됬다면 다른 쪽의 남은 값도 삽입
        while (i <= m) temp[k++] = data[i++];
        while (j <= e) temp[k++] = data[j++];
        
        for (int index = s; index <= e; index++) {
            data[index] = temp[index];
        }
    }
}
