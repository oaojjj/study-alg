#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD 1000 // �ܾ� ���� �ִ� ����
#define BUF_LEN 30 // �ܾ� �ִ� ���̴� 30�̶�� �����Ѵ�.

#define TRUE 1
#define FALSE 0

void my_strlwr(char* str);
int isFirstWord(char*str[], char*buffer);
void sort(char*str[], int count[]);

int total_cnt; // ��ü �ܾ� ���� ����
int in_idx; // ù �ܾ �ƴ� �� ���� �Ǿ��ִ� �ε�����(include index)

int main() {
	char *word[MAX_WORD];
	int word_count[MAX_WORD] = { 0, }; // �� �ܾ� ���� ����
	char buffer[BUF_LEN];
	int index;
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
			else if (ch == '\'' || ch == '-') { // ��ȣ #ispunct(ch)
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

		if (strlen(buffer) >= 7) {
			if (total_cnt == 0) { //ù �ܾ�
				word[total_cnt] = strdup(buffer);
				word_count[total_cnt]++;
				total_cnt++;
			}
			else { // �ϼ� �ܾ� ī��Ʈ
				if (isFirstWord(word, buffer)) { // ù �ܾ� �˻�
					word[total_cnt] = strdup(buffer);
					word_count[total_cnt]++;
					total_cnt++;
				}
				else { // ù �ܾ� �ƴ� ��
					word_count[in_idx]++;
				}
			}
		}
	} // while

	// ������ ����
	sort(word,word_count);


	// ���
	for (int i = 0; i < total_cnt; i+=10) {
		printf("%s %d\n", word[i], word_count[i]);
	}

	fclose(fp);

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

// ������ ����
void sort(char * str[],int count[]) {
	char *str_tmp;
	int cnt_tmp;
	int index;

	for (int i = 0; i < total_cnt - 1; i++) {
		index = i;
		for (int j = i + 1; j < total_cnt; j++) {
			if (strcmp(str[index], str[j]) > 0) {
				index = j;
			}

		}
		// �ܾ�
		str_tmp = str[i];
		str[i] = str[index];
		str[index] = str_tmp;

		// ī��Ʈ ����
		cnt_tmp = count[i];
		count[i] = count[index];
		count[index] = cnt_tmp;
	}
}

// ù �ܾ� �˻�
int isFirstWord(char * str[], char buffer[])
{
	int flag = TRUE;
	for (int i = 0; i < total_cnt; i++) {
		if (!strcmp(str[i], buffer)) {
			flag = FALSE;
			in_idx = i;
			break;
		}
	}
	return flag;
}


