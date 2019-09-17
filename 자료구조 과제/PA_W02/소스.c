#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD 1000 // �ܾ� ���� �ִ� ����
#define BUF_LEN 30 // �ܾ� �ִ� ���̴� 30�̶�� �����Ѵ�.

#define TRUE 1
#define FALSE 0

void my_strlwr(char* str);
void removeCntrl(char* str, int length);

int word_cnt; // ��ü �ܾ� ���� ����

int main() {
	char *word[MAX_WORD];
	int *word_count[MAX_WORD]; // �� �ܾ� ���� ����
	char buffer[BUF_LEN];
	int  buf_len, index;
	int ch;
	int flag; // ��ȣ

	FILE*fp = fopen("pride_and_prejudice.txt", "r");
	if (fp == NULL) {
		printf("���� �ҷ����� ����\n");
	}

	while (!feof(fp)) {
		index = 0;
		while (TRUE) {
			ch = fgetc(fp);
			if (isalpha(ch)) { // ���ĺ�
				buffer[index++] = ch;
				flag = TRUE;
			}
			else if (ispunct(ch)) { // ��ȣ
				if (flag) {
					buffer[index++] = ch;
					flag = FALSE;
				}
				else {
					break;
				}
			}
			else { // ���� ����(����, ����)
				break;
			}
		}

		if (index >= 7) { // �ܾ�� �ν�
			if (isalpha(buffer[index - 1])) {
				buffer[index] = '\0';
				my_strlwr(buffer);
			}
			else {
				buffer[--index] = '\0';
				my_strlwr(buffer);
			}
		}
		else {
			continue;
		}

		// �ϼ��� �ܾ�
		for (int i = 0; i < word_cnt; i++) {

		}
		
		


	}
}

/*
fscanf(fp, "%s", buffer); // ���� �������� �д´�.
buf_len = strlen(buffer);

if (buf_len < 7)
	continue;
else if (isalpha(buffer[0]) || isalpha(buffer[buf_len - 1])) { // ������ ó�� �Ǵ� ���� ��ȣ��� �����Ѵ�.
	removeCntrl(buffer,buf_len);
}
*/


// ó���� �� ��ȣ ����
void removeCntrl(char* str, int length) {
	char tmp[BUF_LEN]; // ��ȣ ���Ÿ� ���� �ӽ�����
	char tmp2[BUF_LEN]; // ���縦 ���� �ӽ�����
	int index = 0;
	int flag = TRUE;

	strcpy(tmp, str);

	while (TRUE) {
		if (!isalpha(tmp[index]) && flag) { // ���� ��ȣ ����
			tmp[index++] = ' '; // ��ȣ�� ���鹮�ڷ� �ٲ� �ش�.
			continue;
		}
		if (flag) {
			index = length - 1;
			flag = FALSE;
		}
		if (!isalpha(tmp[index]) && !flag) { // ���� ��ȣ ����
			tmp[index--] = ' ';
			continue;
		}
		index = 0;
		break;
	}

	for (int i = 0; i < length; i++) {
		if (tmp[i] != ' ') {
			tmp2[index++] = tmp[i];
		}
	}
	tmp2[index] = '\0';
	strcpy(str, tmp2);
}

// �ҹ��� ��ȯ �Լ�
void my_strlwr(char*str) {
	int i = 0;
	while (str[i]) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
		i++;
	}
}

