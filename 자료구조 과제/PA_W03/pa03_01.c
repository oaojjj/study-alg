#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX_LEN 21
#define ALPHA_LEN 26
#define GROUP_MAX_SIZE 10
// �� ���� ���
// 1. �ܾ��� ���ĺ��� �������� �����ؼ� ������ �� �ܾ �Ȱ����� ���ĺ��� �󵵼��� ���ٴ� ���ϱ� sort�� �̿��� ��� -> �ִ�� ���� 20�� �ܾ 100���� �ԷµǸ� ������ *O(N^2)
// 2. �ܾ��� ���ĺ� �󵵼��� �̿��� ��� -> �Ȱ��� �������� �Էµǵ� �󵵼��� ���ϸ� �Ǵϱ� sort���ٴ� ������? *O(N)

typedef struct {
	char* group[GROUP_MAX_SIZE];
	int str_count;
	int alpha[ALPHA_LEN];
}Anagram;

int g_count; // ��ü �ܾ� ����
int g_word_count; // �Ƴ��׷� word ���ĺ� �󵵼� �ٸ� �ܾ� ����

void checkAlpha(char* str, int alpha[], int length);
int alphaCmp(Anagram word[], int alpha[]);
void addWord(Anagram word[], char*buffer, int alpha[], int index);
void my_strlwr(char*str);

int main() {
	Anagram word[100] = { NULL,0,0 };
	Anagram tmp;
	char buffer[MAX_LEN];
	int index = 0;
	int m_len;

	while (TRUE) {
		int m_alpha[ALPHA_LEN] = { 0, };

		scanf("%s", buffer);
		if (!strcmp(buffer, "EOF")) // strcmp(); true -> 0 ��ȯ
			break;
		my_strlwr(buffer);

		m_len = strlen(buffer);

		checkAlpha(buffer, m_alpha, m_len);

		// ù �ܾ� �ֱ�
		if (g_count == 0) {
			addWord(word, buffer, m_alpha, index);
		}
		else {
			index = alphaCmp(word, m_alpha);
			addWord(word, buffer, m_alpha, index);
		}
	}
	
	// �Ƴ��׷� ����
	char *key;
	int i, j;
	for (i = 1; i <= g_word_count; i++) {
		key = strdup(word[i].group[0]);
		tmp = word[i];
		j = i - 1;
		while (j >= 0 && strcmp(word[j].group[0], key) == 1) {
			word[j + 1] = word[j];
			j--;
		}
		word[j + 1] = tmp;
	}

	// ���
	for (i = 0; i <= g_word_count; i++) {
		for (j = 0; j < word[i].str_count; j++) {
			printf("%s ", word[i].group[j]);
		}
		printf("\n");
	}

}

// ���ĺ� �󵵼� üũ �Լ�
void checkAlpha(char* str, int alpha[], int length) {
	int len;
	int i, index;

	// �ҹ���a ASCII(97)
	for (i = 0; i < length; i++) {
		index = (*str) - 'a'; // 'a' or 97
		str++;
		alpha[index]++;
	}
}

/*	���ĺ� �󵵼� �� �Լ�

	#parameter - ���ĺ� �� ��

	�Ű������� �񱳰��� ��ġ - ��ġ�ϴ� �ε��� ��ȯ
	�Ű������� �񱳰��� ����ġ - ��ü �ܾ� ���� ��ȯ
*/
int alphaCmp(Anagram word[], int alpha[]) {
	int i, j;

	for (i = 0; i <= g_word_count; i++) {
		for (j = 0; j < ALPHA_LEN; j++) {
			if (word[i].alpha[j] != alpha[j]) {
				break;
			}
		}
		if (j == ALPHA_LEN) {
			return i;
		}
	}
	;
	return ++g_word_count;
}

// �ܾ� �߰� �Լ�
void addWord(Anagram word[], char*buffer, int alpha[], int index) {
	char *key;
	int i, j;
	int cnt = word[index].str_count; // group �ܾ� ����

	word[index].group[cnt] = strdup(buffer);

	// group �߰��� ��������
	for (i = 1; i < cnt + 1; i++) {
		key = strdup(word[index].group[i]);
		j = i - 1;
		while (j >= 0 && strcmp(word[index].group[j], key) == 1) {
			word[index].group[j + 1] = strdup(word[index].group[j]);
			j--;
		}
		word[index].group[j + 1] = strdup(key);
	}

	// ���ĺ� �󵵼� �߰�
	if (cnt == 0) {
		for (i = 0; i < ALPHA_LEN; i++)
			word[index].alpha[i] = alpha[i];
//		memcpy(word[index].alpha, alpha, ALPHA_LEN);
	}

	// group �ܾ� ����
	word[index].str_count++;

	// ��ü ���� �߰�
	g_count++;
}

// �ҹ��ڷ� ����� �Լ�
void my_strlwr(char*str) {
	int i = 0;
	while (str[i]) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
		i++;
	}
}
