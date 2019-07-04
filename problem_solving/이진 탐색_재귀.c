#include <stdio.h>

int arr[13] = {3,5,6,8,10,14,16,17,20,30,35,37,40 };

int binary_search(int s[], int start, int end, int target) {
	int mid;

	if (start > end) { return -1; }

	mid = (start + end)/2;
	if(target==s[mid]){ return mid; }
	else if (target > s[mid]) { start = mid + 1; }
	else { end = mid - 1; }
	binary_search(s, start, end, target);
}

int main() {
	int index;

	index = binary_search(arr, 0, 12, 20);
	if (index >= 0) {
		printf("찾았습니다.\n배열의 %d째에 있습니다.\n",index+1);
	}
	else {
		printf("없습니다.\n");
	}
}