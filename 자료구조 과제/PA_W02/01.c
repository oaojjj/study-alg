#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD 1000 // 단어 저장 최대 개수
#define BUF_LEN 30 // 단어 최대 길이는 30이라고 가정한다.

#define TRUE 1
#define FALSE 0

void my_strlwr(char* str);

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

