#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 21 // 단어의 최대 길이는 20

int main() {
	int m, n; // m = 행, n = 열
	int ch, i=0;
	char *array[80]; // m=9, n=9일때 필요한 배열의 크기 m x n=81
	char buffer[BUFFER_SIZE]; // 각 단어를 임시로 저장할 배열이다.
	int len[80];
	int maxlen[10];

	scanf("%d %d", &m, &n);
	getchar();// (엔터키)버퍼비우기

	// 입력되는 문자열을 분리해서 저장하는 과정
	while(i<m*n){
		int index = 0;

		while (1) { // 무한루프를 돌면서 모든 예외적인 상황을 처리한다.(숫자도 예외 포함)
			ch = getchar();
			if (isalpha(ch)) { // 입력받은 문자가 알파벳이라면 버퍼에 추가한다.
				if (index < BUFFER_SIZE-1) {
					buffer[index++] = ch;
				}
			}
			else if (isspace(ch)) { // 모든 공백문자를 체크한다.
				break;
			}
		}
		if (index > 0) { // 공백이 먼저 입력되거나 여러번 입력되었을 경우 인덱스를 체크하여 예외로 처리한다.
			buffer[index] = '\0';
			array[i] = strdup(buffer);
			// 문자열 길이
			len[i] = strlen(array[i]);
			i++;
		}
	}
		
	// 행의 문자열 최대길이 구하기
	for (int col = 0; col < n; col++) {
		int cnt = 1;
		maxlen[col] = len[col];
		for (int row = 0; row < m-1; row++) {
			if (maxlen[col] < len[n*cnt+col]) {
				maxlen[col] = len[n*cnt+col];
			}
			cnt++;
		}
	}

	i = 0;
	// 테이블 출력
	for (int j = 0; j < m; j++) {
		int space;
		for (int k = 0; k < n; k++) {
			printf("%s", array[i]);
			if (k == n - 1) {
				printf("\n");
				i++;
				break;
			}
			space = maxlen[k] - len[i];
			i++;
			for (int scnt = 0; scnt <= space; scnt++) {
				printf(" ");
			}
		}
	}
	return 0;
}
