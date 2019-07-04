#include <stdio.h>

int s1[8] = { 3,5,6,8,11,14,16,17 };
int s2[10] = { 4,7,9,11,12,13,15,18,20,30 };
int c[30] = {0};

void merging(int arr1[], int arr2[], int result[],int arr1_size,int arr2_size,int rlt_size) {
	int i = 0, j = 0, k = 0;
	
	while (!(arr1_size == j && arr2_size == k)) {
		if (s1[j] < s2[k]) { c[i] = s1[j]; i++, j++;}
		else { c[i] = s2[k]; i++, k++; }

		if (arr1_size == j) {
			while (arr2_size != k) { c[i] = s2[k]; k++; }
		}
		if (arr2_size == k) {
			while (arr1_size != j) { c[i] = s1[j]; j++; }
		}
	}
}
int main() {
	merging(s1, s2, c, 8, 10, 18);
	for (int i = 0; c[i]!=0; i++) {
		printf("%d ", c[i]);
	}
}