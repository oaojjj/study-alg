package alg.sorting;

import alg.Utils;

import java.util.Arrays;

/**
 * 힙 정렬
 * heap-property 특성을 만족하는 이진 트리를 이용한 정렬 방법
 * Best = n * log n
 * Avg = n * log n
 * Worst = n * log n
 */
public class HeapSort {
    int[] data;
    int n;

    public HeapSort(int[] data) {
        this.data = data;
        n = data.length;
    }

    /*
     * 1. build heap(heapify)
     * 2. heap sort
     */
    public void sort() {
        if (n < 2) return;
        System.out.println(Arrays.toString(data));

        // (n-2) / 2 => 마지막 노드의 부모 노드부터 시작
        for (int i = (n - 2) / 2; i >= 0; i--) {
            maxHeapify(i, n);
        }
    }

    // recursive version
    private void maxHeapify(int parent, int n) {
        int leftChild = 2 * parent + 1; // 2i
        int rightChild = 2 * parent + 2; // 2i+1
        int largest = parent;

        // 1. 자식노드가 있는가?
        // 2. 자신(parent)보다 큰 자식(child)이 존재하는가?
        if (rightChild < n && data[largest] < data[rightChild])
            largest = rightChild;

        if (leftChild < n && data[largest] < data[leftChild])
            largest = leftChild;

        // 3. 위의 모든 조건을 성립한다면 두 값을 swap하고 다시 heapify
        if (largest != parent) {
            Utils.swap(data, parent, largest);
            maxHeapify(largest, n);
        }
    }
}
