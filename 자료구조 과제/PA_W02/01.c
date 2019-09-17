#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD 1000 // 단어 저장 최대 개수
#define BUF_LEN 30 // 단어 최대 길이는 30이라고 가정한다.

#define TRUE 1
#define FALSE 0

void my_strlwr(char* str);
int isFirstWord(char*str[], char*buffer);

int total_cnt; // 전체 단어 개수 저장

	int main() {
	char *word[MAX_WORD];
	int word_count[MAX_WORD]; // 각 단어 개수 저장
	char buffer[BUF_LEN];
	int index;
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
			else if (ch == '\'' || ch == '-') { // 기호 #ispunct(ch)
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

		if (total_cnt == 0) { //첫 단어
			word[0] = strdup(buffer);
			word_count[0]++;
			total_cnt++;
		}
		else { // 완성 단어 카운트
			if (isFirstWord(word, buffer)) { // 첫 단어 검사
				word_count[total_cnt]++;
				total_cnt++;
			}
			else { // 첫 단어 아닐 때
				for (int i = 0; i < total_cnt; i++) {
					if (!strcmp(word[i], buffer)) {
						word_count[i]++;
						total_cnt++;
						break;
					}
				}
			}
		}
	} // while
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

// 첫 단어 검사
int isFirstWord(char * str[], char buffer[])
{
	int flag = TRUE;
	for (int i = 0; i < total_cnt; i++) {
		if (strcmp(str[i], buffer)) {
			flag = FALSE;
		}
	}
	return flag;
}

