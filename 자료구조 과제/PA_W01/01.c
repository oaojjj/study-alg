#include <stdio.h>
#include <string.h>
#include <ctype.h>

//#define WORD_COUNT 30
#define WORD_MAX_SIZE 20

#define WORD_MAX_COUNT 1000

#define TRUE 1
#define FALSE 0


/*���α׷��� ���� W01_1
https://www.dropbox.com/s/4tlzlxrw6nlmrms/pa01.pdf?dl=0
*/

typedef struct
{
	char word[WORD_MAX_SIZE];
	int count;
}Word;

//int isFirstWord(Word[], char*);
void my_strlwr(char*);
int my_strlen(char*);
void wordCounter(Word[], char *);
void getWord(char*);
int isWord(char*);

int inCount; // Word ����ü�� ���Ե� �ܾ� ����
//char* sorted[WORD_MAX_COUNT];

int main() {
	Word word[WORD_MAX_COUNT] = { 0, };
	Word tmp;
	char buffer[WORD_MAX_SIZE];
	int i;
	int ch, index = 0;

	FILE*fp = fopen("pride_and_prejudice.txt", "r");

	if (fp == NULL) {
		printf("���� �б� ����\n");
		return -1;
	}

	/* test
	strcpy(word->word, "ȫ�浿");
	strcpy(buffer, "ȫ�浿");
	int test = strcmp(word->word, buffer);
	*/

	while (!feof(fp)) {
		index = 0;

		// �� �پ� �д´�
		while ((ch = fgetc(fp)) != '\n') {

			if (isalpha(ch) || ispunct(ch)) {
				buffer[index++] = ch;
			}
			else if (index < 7 && isspace(ch)) { // ���ڼ��� 7�̸� �̰� ���鹮�ڸ� ������ �� �ܾ�� �ν����� �ʴ´�.
				index = 0;
				continue;
			}
			else if (index >= 7 && isspace(ch)) { // ���ڼ��� 7�̻� �̰� ���鹮�ڸ� ������ �� �ܾ�� �ν��Ѵ�.
				break;
			}
			else { // EOF
				break;
			}
		}

		if (index > 0) {
			buffer[index] = '\0';
			my_strlwr(buffer);
			if (!(isalpha(buffer[0])) || !(isalpha(buffer[index - 1]))) {
				getWord(buffer);
			}

			if (isWord(buffer)) {
				wordCounter(word, buffer);
			}
		}
	}

	// ������ ����
	for (i = 0; i < inCount - 1; i++) {
		index = i;
		for (int j = i + 1; j < inCount; j++) {
			if (strcmp(word[index].word, word[j].word) > 0) {
				index = j;
			}

		}
		tmp = word[i];
		word[i] = word[index];
		word[index] = tmp;
	}

	// ���
	for (i = 0; i < inCount; i += 10) {
		printf("%s %d\n", word[i].word, word[i].count);
	}

	fclose(fp);
}

void getWord(char* str) {
	char tmp[WORD_MAX_SIZE]; // �ӽ�����
	char string[WORD_MAX_SIZE]; // �ܾ� �ϼ�
	int index = 0, cnt = 0;
	int len = my_strlen(str);
	int flag = TRUE;

	strcpy(tmp, str);
	while (TRUE) {
		if (!isalpha(tmp[index]) && flag) {
			tmp[index++] = ' '; // FALSE��� 0�� ���
			continue;
		}
		if (flag) {
			index = len - 1;
			flag = FALSE;
		}
		if (!isalpha(tmp[index]) && !flag) {
			tmp[index--] = ' ';
			continue;
		}
		index = 0;
		break;
	}

	while (tmp[cnt] != '\0') {
		if (tmp[cnt] != ' ') {
			string[index++] = tmp[cnt];
		}
		cnt++;
	}
	string[index] = '\0';
	strcpy(str, string);
}

int isWord(char* str) {
	if (my_strlen(str) >= 7) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void wordCounter(Word word[], char * str) {
	for (int i = 0; i <= inCount; i++) {
		// ù �ܾ�

		if (strcmp(word[i].word, str) != 0) {
			if (word[i].count == 0) {
				strcpy(word[i].word, str);
				word[i].count++;
				inCount++;
				return;
			}
			else {
				continue;
			}
		}
		else {
			word[i].count++;
			return;
		}
	}
	return;
}

// strlwr
void my_strlwr(char*str) {
	int i = 0;
	while (str[i]) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
		i++;
	}
}

// strlen
int my_strlen(char*string) {
	int cnt = 0;
	while (string[cnt] != '\0') {
		++cnt;
	}
	return cnt;
}

