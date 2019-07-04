#include <stdio.h>

//depth 0 - > 1xx가 만들어진다.
//depth 1 - > 12x,13x를 만든다.
//depth 2 - > 123, 132를 완성시킨다.
//depth 3 - > 출력한다.

void swap(int data[], int i, int depth);
int perm(int data[], int depth, int n);

int main() {
	int k,n;
	int data[100] = {0};

	printf("1~n까지의 순열을 만듭니다.\nn을 입력하세요: ");
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		data[i] = i+1;
	}

	printf("몇개를 뽑아서 순열을 만들지 입력하세요: ");
	scanf("%d", &k);
	perm(data, 0, n, k);
}

int perm(int data[], int depth, int n, int k) { // 데이터, 깊이값(only 0), 길이값이다.
	if (depth == k) { //한번의 탐색이 끝났다.
		for (int i = 0; i < k; i++) {
			printf("%d ", data[i]);
		}
		printf("\n");
		return;
	}
	for (int i = depth; i < n; i++) {
		swap(data, i, depth);
		perm(data, depth + 1, n, k); // 깊이값을 증가시키고 다시 호출한다.
		swap(data, i, depth); // 스왑한값들을 원상복구 시킨다.
	}
}

void swap(int data[],int i,int depth) {
	int tmp;
	tmp = data[i];
	data[i] = data[depth];
	data[depth] = tmp;
}