#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#define MAX_LEN 10

#define TRUE 1
#define FALSE 0

int main() {
	char buffer[MAX_LEN];
	int flag = FALSE;
	int  num, index = 0, sum = 0;
	int ch = 1;


	while (TRUE) {
		ch = getchar();
		if (isdigit(ch)) {
			buffer[index++] = ch;
			flag = TRUE;
		}
		if (flag && !isdigit(ch)) {
			buffer[index] = '\0';
			num = atoi(buffer);
			sum += num;
			index = 0;
			flag = FALSE;
		}
		if (ch == '\n')
			break;
	}
	printf("%d", sum);
}
