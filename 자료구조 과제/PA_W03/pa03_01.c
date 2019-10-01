#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX_LEN 21
#define ALPHA_LEN 26
#define GROUP_MAX_SIZE 10
// 두 가지 방법
// 1. 단어의 알파벳을 오름차순 정렬해서 비교했을 때 단어가 똑같으면 알파벳의 빈도수도 같다는 얘기니까 sort를 이용한 방법 -> 최대로 길이 20인 단어가 100개가 입력되면 느리다 *O(N^2)
// 2. 단어의 알파벳 빈도수를 이용한 방법 -> 똑같은 조건으로 입력되도 빈도수만 비교하면 되니까 sort보다는 빠르다? *O(N)

typedef struct {
	char* group[GROUP_MAX_SIZE];
	int str_count;
	int alpha[ALPHA_LEN];
}Anagram;

int g_count; // 전체 단어 개수
int g_word_count; // 아나그램 word 알파벳 빈도수 다른 단어 개수

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
		if (!strcmp(buffer, "EOF")) // strcmp(); true -> 0 반환
			break;
		my_strlwr(buffer);

		m_len = strlen(buffer);

		checkAlpha(buffer, m_alpha, m_len);

		// 첫 단어 넣기
		if (g_count == 0) {
			addWord(word, buffer, m_alpha, index);
		}
		else {
			index = alphaCmp(word, m_alpha);
			addWord(word, buffer, m_alpha, index);
		}
	}
	
	// 아나그램 정렬
	char *key;
	int i, j;
	for (i = 1; i <= g_word_count; i++) {
		key = strdup(word[i].group[0]);
		tmp = word[i];
		j = i - 1;
		while (j >= 0 && strcmp(word[j].group[0], key) >= 1) {
			word[j + 1] = word[j];
			j--;
		}
		word[j + 1] = tmp;
	}

	// 출력
	for (i = 0; i <= g_word_count; i++) {
		for (j = 0; j < word[i].str_count; j++) {
			printf("%s ", word[i].group[j]);
		}
		printf("\n");
	}

}

// 알파벳 빈도수 체크 함수
void checkAlpha(char* str, int alpha[], int length) {
	int len;
	int i, index;

	// 소문자a ASCII(97)
	for (i = 0; i < length; i++) {
		index = (*str) - 'a'; // 'a' or 97
		str++;
		alpha[index]++;
	}
}

/*	알파벳 빈도수 비교 함수

	#parameter - 알파벳 빈도 수

	매개변수의 비교값이 일치 - 일치하는 인덱스 반환
	매개변수의 비교값이 불일치 - 전체 단어 개수 반환
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

// 단어 추가 함수
void addWord(Anagram word[], char*buffer, int alpha[], int index) {
	char *key;
	int i, j;
	int cnt = word[index].str_count; // group 단어 개수

	word[index].group[cnt] = strdup(buffer);

	// group 추가시 삽입정렬
	for (i = 1; i < cnt + 1; i++) {
		key = strdup(word[index].group[i]);
		j = i - 1;
		while (j >= 0 && strcmp(word[index].group[j], key) >= 1) {
			word[index].group[j + 1] = strdup(word[index].group[j]);
			j--;
		}
		word[index].group[j + 1] = strdup(key);
	}

	// 알파벳 빈도수 추가
	if (cnt == 0) {
		for (i = 0; i < ALPHA_LEN; i++)
			word[index].alpha[i] = alpha[i];
//		memcpy(word[index].alpha, alpha, ALPHA_LEN);
	}

	// group 단어 개수
	word[index].str_count++;

	// 전체 개수 추가
	g_count++;
}

// 소문자로 만드는 함수
void my_strlwr(char*str) {
	int i = 0;
	while (str[i]) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
		i++;
	}
}
