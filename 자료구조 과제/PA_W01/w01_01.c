#include <stdio.h>
#include <string.h>
#include <ctype.h>

//#define WORD_COUNT 30
#define WORD_MAX_SIZE 20

#define WORD_MAX_COUNT 1000

#define TRUE 1
#define FALSE 0


/*프로그래밍 과제 W01_1
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

int inCount; // Word 구조체에 포함된 단어 개수
//char* sorted[WORD_MAX_COUNT];

int main() {
	Word word[WORD_MAX_COUNT] = { 0, };
	Word tmp;
	char buffer[WORD_MAX_SIZE];
	int i;
	int ch, index = 0;

	FILE*fp = fopen("pride_and_prejudice.txt", "r");

	if (fp == NULL) {
		printf("파일 읽기 실패\n");
		return -1;
	}

	/* test
	strcpy(word->word, "홍길동");
	strcpy(buffer, "홍길동");
	int test = strcmp(word->word, buffer);
	*/

	while (!feof(fp)) {
		index = 0;

		// 한 줄씩 읽는다
		while ((ch = fgetc(fp)) != '\n') {

			if (isalpha(ch) || ispunct(ch)) {
				buffer[index++] = ch;
			}
			else if (index < 7 && isspace(ch)) { // 문자수가 7미만 이고 공백문자를 만났을 때 단어로 인식하지 않는다.
				index = 0;
				continue;
			}
			else if (index >= 7 && isspace(ch)) { // 문자수가 7이상 이고 공백문자를 만났을 때 단어로 인식한다.
				break;
			}
			else { // EOF
				break;
			}
		}

		if (index > 0) {
			// 널문자를 마지막에 붙여주고 소문자로 만들어 준다.
			buffer[index] = '\0'; 
			my_strlwr(buffer);
			if (!(isalpha(buffer[0])) || !(isalpha(buffer[index - 1]))) { // 버퍼의 처음과 끝이 알파벳이 아니면 알파벳으로 만들어 준다.
				getWord(buffer);
			}

			if (isWord(buffer)) { // 문자 길이가 조건을 만족하고 단어가 만들어 지면 카운트 한다.
				wordCounter(word, buffer);
			}
		}
	}

	// 사전식 순서
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

	// 출력
	for (i = 0; i < inCount; i += 10) {
		printf("%s %d\n", word[i].word, word[i].count);
	}

	fclose(fp);
}

void getWord(char* str) {
	char tmp[WORD_MAX_SIZE]; // 임시저장
	char string[WORD_MAX_SIZE]; // 단어 완성
	int index = 0, cnt = 0;
	int len = my_strlen(str);
	int flag = TRUE;

	strcpy(tmp, str);
	while (TRUE) {
		if (!isalpha(tmp[index]) && flag) {
			tmp[index++] = ' '; // 기호를 공백문자로 바꿔 준다.
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
		// 첫 단어

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

