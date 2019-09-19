#include <stdio.h>
#include <string.h>

#define MAX_WORD 100
#define MAX_LEN 21

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


int main() {
	char *str[MAX_WORD];
	char buffer[MAX_LEN];
	int cnt = 0;
	int flag=0;

	while (1) {
		scanf("%s", buffer);
		if (strcmp(buffer, "EOF") == 0) {
			break;
		}
		my_strlwr(buffer);
		// 단어 넣기
		if (cnt==0) {
			str[cnt++] = strdup(buffer);
		}
		else {
			flag = 0;
			for (int i = 0; i<cnt; i++) {
				if (strcmp(str[i], buffer) == 0) {
					flag++;
				}
			}
			if (flag==0) {
				str[cnt++] = strdup(buffer);
			}
		}
	}

	printf("%d\n", cnt);
}
