#include stdio.h
#include string.h
#include ctype.h

#define BUFFER_SIZE 21  �ܾ��� �ִ� ���̴� 20

int main() {
	int n, m;
	int ch, i=0;
	char array[80]; // m=9, n=9�϶� �ʿ��� �迭�� ũ�� m x n=81
	char buffer[BUFFER_SIZE]; // �� �ܾ �ӽ÷� ������ �迭�̴�.

	scanf(%d %d, &m, &n);
	getchar(); // (����Ű)���ۺ���

	while(imn){ // �Էµ� �࿭�� �� ��ŭ �ݺ��Ѵ�.
		
		int index = 0;
		while (1) { // ���ѷ����� ���鼭 ��� �������� ��Ȳ�� ó���Ѵ�.(���ڵ� ���� ����)
			ch = getchar();
			if (isalpha(ch)) { // �Է¹��� ���ڰ� ���ĺ��̶�� ���ۿ� �߰��Ѵ�.
				if (index  BUFFER_SIZE-1) {
					buffer[index++] = ch;
				}
			}
			else if (isspace(ch)) { // ��� ���鹮�ڸ� üũ�Ѵ�.
				break;
			}
		}
		if (index  0) { // ������ ���� �Էµǰų� ������ �ԷµǾ��� ��� �ε����� üũ�Ͽ� ���ܷ� ó���Ѵ�.
			buffer[index] = '0';
			array[i++] = strdup(buffer);
		}
	}
	

	for (int j = 0; j  mn; j++) {
		printf(%s , array[j]);
	}
	return 0;
}
