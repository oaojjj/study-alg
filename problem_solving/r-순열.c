#include <stdio.h>

//depth 0 - > 1xx�� ���������.
//depth 1 - > 12x,13x�� �����.
//depth 2 - > 123, 132�� �ϼ���Ų��.
//depth 3 - > ����Ѵ�.

void swap(int data[], int i, int depth);
int perm(int data[], int depth, int n);

int main() {
	int k,n;
	int data[100] = {0};

	printf("1~n������ ������ ����ϴ�.\nn�� �Է��ϼ���: ");
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		data[i] = i+1;
	}

	printf("��� �̾Ƽ� ������ ������ �Է��ϼ���: ");
	scanf("%d", &k);
	perm(data, 0, n, k);
}

int perm(int data[], int depth, int n, int k) { // ������, ���̰�(only 0), ���̰��̴�.
	if (depth == k) { //�ѹ��� Ž���� ������.
		for (int i = 0; i < k; i++) {
			printf("%d ", data[i]);
		}
		printf("\n");
		return;
	}
	for (int i = depth; i < n; i++) {
		swap(data, i, depth);
		perm(data, depth + 1, n, k); // ���̰��� ������Ű�� �ٽ� ȣ���Ѵ�.
		swap(data, i, depth); // �����Ѱ����� ���󺹱� ��Ų��.
	}
}

void swap(int data[],int i,int depth) {
	int tmp;
	tmp = data[i];
	data[i] = data[depth];
	data[depth] = tmp;
}