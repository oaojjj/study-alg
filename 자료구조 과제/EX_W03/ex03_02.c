#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// 1. ��ǥ�� �������� ���ڿ��� �߶� ����
// 2. �ֵ���ǥ ���̿� �ִ� ��ǥ�� �߰�
// 3. �ֵ���ǥ�� ���� ��ǥ�� ���� ���ڰ� ��ǥ�̸� ������ �߰�
// 4. �ֵ���ǥ�� ���ۿ� �߰����� �ʴ´�

int main() {
	int ch, index = 0, cnt = 0;
	char buffer[MAX_LEN];
	char *tmp[100];
	int flag = -1; // ���� false , ��� true
	int flag_b = 1;

	while ((ch = getchar()) != '\n') {
		if (ch == 34) { // 34 �ֵ���ǥ
			flag *= -1;
			continue;
		}

		if (ch == ',') {
			flag_b *= -1;
			if (flag > 0) {
				buffer[index++] = ch;
			}
			else if (flag_b > 0 && index==0) {
				buffer[index++] = '\n';
				buffer[index] = '\0';
				index = 0;
				tmp[cnt++] = strdup(buffer);
			}
			else {
				buffer[index] = '\0';
				index = 0;
				tmp[cnt++] = strdup(buffer);
			}
		}
		else {
			flag_b = 1;
			buffer[index++] = ch;
		}
	}
	buffer[index] = '\0';
	tmp[cnt++] = strdup(buffer);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		if (!strcmp(tmp[i], "\n")) {
			printf("%s",tmp[i]);
			continue;
		}
		printf("%s\n", tmp[i]);
	}

}
