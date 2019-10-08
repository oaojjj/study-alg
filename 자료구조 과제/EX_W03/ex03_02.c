#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// 1. 쉼표를 기준으로 문자열을 잘라서 저장
// 2. 쌍따옴표 사이에 있는 쉼표는 추가
// 3. 쌍따옴표가 없는 쉼표는 다음 문자가 쉼표이면 공백을 추가
// 4. 쌍따옴표는 버퍼에 추가하지 않는다

int main() {
	int ch, index = 0, cnt = 0;
	char buffer[MAX_LEN];
	char *tmp[100];
	int flag = -1; // 음수 false , 양수 true
	int flag_b = 1;

	while ((ch = getchar()) != '\n') {
		if (ch == 34) { // 34 쌍따옴표
			flag *= -1;
			continue;
		}

		if (ch == ',') {
			flag_b *= -1;
			if (flag > 0) {
				buffer[index++] = ch;
			}
			else if (flag_b > 0 && index==0) {
				buffer[index++] = '\n';
				buffer[index] = '\0';
				index = 0;
				tmp[cnt++] = strdup(buffer);
			}
			else {
				buffer[index] = '\0';
				index = 0;
				tmp[cnt++] = strdup(buffer);
			}
		}
		else {
			flag_b = 1;
			buffer[index++] = ch;
		}
	}
	buffer[index] = '\0';
	tmp[cnt++] = strdup(buffer);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		if (!strcmp(tmp[i], "\n")) {
			printf("%s",tmp[i]);
			continue;
		}
		printf("%s\n", tmp[i]);
	}

}
