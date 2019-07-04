#include <stdio.h>

int arr[] = { 3,2,5,4,10,4,-100 };

void selection_sort(int s[], int n) {
	int max = 0, tmp;

	if (n == 0)
		return;
	for (int i = 0; i <= n; i++) {
		if (s[max] < s[i]) {
			max = i;
		}
	}
	tmp = s[n];
	s[n] = s[max];
	s[max] = tmp;
	selection_sort(s, n - 1);
}
int main() {
	selection_sort(arr,6);

	for (int i = 0; i < 7; i++) {
		printf("%d ",arr[i]);
	}
}