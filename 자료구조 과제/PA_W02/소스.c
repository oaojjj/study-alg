#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD 1000 // 단어 저장 최대 개수
#define BUF_LEN 30 // 단어 최대 길이는 30이라고 가정한다.

#define TRUE 1
#define FALSE 0

void my_strlwr(char* str);
void removeCntrl(char* str, int length);

int word_cnt; // 전체 단어 개수 저장

int main() {
	char *word[MAX_WORD];
	int *word_count[MAX_WORD]; // 각 단어 개수 저장
	char buffer[BUF_LEN];
	int  buf_len, index;
	int ch;
	int flag; // 기호

	FILE*fp = fopen("pride_and_prejudice.txt", "r");
	if (fp == NULL) {
		printf("파일 불러오기 실패\n");
	}

	while (!feof(fp)) {
		index = 0;
		while (TRUE) {
			ch = fgetc(fp);
			if (isalpha(ch)) { // 알파벳
				buffer[index++] = ch;
				flag = TRUE;
			}
			else if (ispunct(ch)) { // 기호
				if (flag) {
					buffer[index++] = ch;
					flag = FALSE;
				}
				else {
					break;
				}
			}
			else { // 예외 문자(공백, 숫자)
				break;
			}
		}

		if (index >= 7) { // 단어로 인식
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

		// 완성된 단어
		for (int i = 0; i < word_cnt; i++) {

		}
		
		


	}
}

/*
fscanf(fp, "%s", buffer); // 공백 기준으로 읽는다.
buf_len = strlen(buffer);

if (buf_len < 7)
	continue;
else if (isalpha(buffer[0]) || isalpha(buffer[buf_len - 1])) { // 버퍼의 처음 또는 끝이 기호라면 제거한다.
	removeCntrl(buffer,buf_len);
}
*/


// 처음과 끝 기호 제거
void removeCntrl(char* str, int length) {
	char tmp[BUF_LEN]; // 기호 제거를 위한 임시저장
	char tmp2[BUF_LEN]; // 복사를 위한 임시저장
	int index = 0;
	int flag = TRUE;

	strcpy(tmp, str);

	while (TRUE) {
		if (!isalpha(tmp[index]) && flag) { // 앞의 기호 제거
			tmp[index++] = ' '; // 기호를 공백문자로 바꿔 준다.
			continue;
		}
		if (flag) {
			index = length - 1;
			flag = FALSE;
		}
		if (!isalpha(tmp[index]) && !flag) { // 뒤의 기호 제거
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

// 소문자 변환 함수
void my_strlwr(char*str) {
	int i = 0;
	while (str[i]) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
		i++;
	}
}

