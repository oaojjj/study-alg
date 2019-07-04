#include <stdio.h>

#define SIZE 10

int sorted[SIZE];

void mergeSort(int arr[], int s, int e); // conquer
void merge(int arr[], int s, int m, int e); // divide

int main() {
	int data[SIZE] = { 3,5,7,8,1,2,4,6,9,10 };

	mergeSort(data, 0, SIZE - 1);

	for (int i = 0; i < SIZE; i++) {
		printf("%d ", data[i]);
	}
}

void mergeSort(int arr[], int s, int e) { // s_start, e_end, m_middle
	if (s < e) {
		int m = (s + e) / 2;

		mergeSort(arr, s, m); // left
		mergeSort(arr, m + 1, e); // right

		merge(arr, s, m, e); // sort
	}
}

void merge(int arr[], int s, int m, int e) {
	int i = s, j = m + 1, k = s;

	while (i <= m && j <= e) {
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}

	while (i <= m)
		sorted[k++] = arr[i++];
	while (j <= e)
		sorted[k++] = arr[j++];
	for (i = s; i <= e; i++)
		arr[i] = sorted[i];

}
