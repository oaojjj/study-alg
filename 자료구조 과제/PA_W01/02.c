#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 21 // 단어의 최대 길이는 20

int main() {
	int n, m;
	int ch, i=0;
	char *array[80]; // m=9, n=9일때 필요한 배열의 크기 m x n=81
	char buffer[BUFFER_SIZE]; // 각 단어를 임시로 저장할 배열이다.

	scanf("%d %d", &m, &n);
	getchar();// (엔터키)버퍼비우기

	while(i<m*n){ // 입력된 행열의 수 만큼 반복한다.
		
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
			array[i++] = strdup(buffer);
		}
	}
	

	for (int j = 0; j < m*n; j++) {
		printf("%s ", array[j]);
	}
	return 0;
}
