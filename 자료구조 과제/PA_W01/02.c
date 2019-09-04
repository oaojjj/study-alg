#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 21 // �ܾ��� �ִ� ���̴� 20

int main() {
	int m, n; // m = ��, n = ��
	int ch, i=0;
	char *array[80]; // m=9, n=9�϶� �ʿ��� �迭�� ũ�� m x n=81
	char buffer[BUFFER_SIZE]; // �� �ܾ �ӽ÷� ������ �迭�̴�.
	int len[80];
	int maxlen[10];

	scanf("%d %d", &m, &n);
	getchar();// (����Ű)���ۺ���

	// �ԷµǴ� ���ڿ��� �и��ؼ� �����ϴ� ����
	while(i<m*n){
		int index = 0;

		while (1) { // ���ѷ����� ���鼭 ��� �������� ��Ȳ�� ó���Ѵ�.(���ڵ� ���� ����)
			ch = getchar();
			if (isalpha(ch)) { // �Է¹��� ���ڰ� ���ĺ��̶�� ���ۿ� �߰��Ѵ�.
				if (index < BUFFER_SIZE-1) {
					buffer[index++] = ch;
				}
			}
			else if (isspace(ch)) { // ��� ���鹮�ڸ� üũ�Ѵ�.
				break;
			}
		}
		if (index > 0) { // ������ ���� �Էµǰų� ������ �ԷµǾ��� ��� �ε����� üũ�Ͽ� ���ܷ� ó���Ѵ�.
			buffer[index] = '\0';
			array[i] = strdup(buffer);
			// ���ڿ� ����
			len[i] = strlen(array[i]);
			i++;
		}
	}
		
	// ���� ���ڿ� �ִ���� ���ϱ�
	for (int col = 0; col < n; col++) {
		int cnt = 1;
		maxlen[col] = len[col];
		for (int row = 0; row < m-1; row++) {
			if (maxlen[col] < len[n*cnt+col]) {
				maxlen[col] = len[n*cnt+col];
			}
			cnt++;
		}
	}

	i = 0;
	// ���̺� ���
	for (int j = 0; j < m; j++) {
		int space;
		for (int k = 0; k < n; k++) {
			printf("%s", array[i]);
			if (k == n - 1) {
				printf("\n");
				i++;
				break;
			}
			space = maxlen[k] - len[i];
			i++;
			for (int scnt = 0; scnt <= space; scnt++) {
				printf(" ");
			}
		}
	}
	return 0;
}
