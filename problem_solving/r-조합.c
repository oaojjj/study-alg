#include <stdio.h>

void combination(int data[], int cdata[], int index, int n, int r, int target);

int main() {
	int r,n;
	int data[5];
	int cdata[5];

	printf("��� ���� �Է��Ͻʴϱ�?(5����)");
	scanf("%d", &n);

	printf("������ �Է��ϼ���: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}

	printf("��� �̾Ƽ� ������ ������ �Է��ϼ���: ");
	scanf("%d", &r);

	combination(data ,cdata, 0, n, r, 0);
}

void combination(int data[],int cdata[],int index, int n, int r, int target) {
	if (r == 0) {
		for (int i = 0; i < index; i++) {
			printf("%d ", cdata[i]);
		}
		printf("\n");
	}
	else if (target == n)
		return;
	else {
		cdata[index] = data[target];
		combination(data,cdata,index + 1, n, r - 1, target + 1);
		combination(data, cdata, index, n, r, target + 1);
	}
}