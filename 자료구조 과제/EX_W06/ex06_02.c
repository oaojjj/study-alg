#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
	int coef;
	int expo_x, expo_y;
} Term;

Term* recognize(char* str);

int main() {
	char expr[30];
	int coef, exp_x, exp_y;
	scanf("%s", expr);
	Term *t = recognize(expr);
	printf("%d %d %d\n", t->coef, t->expo_x, t->expo_y);
	return 0;
}

Term* recognize(char* body) {
	Term *term = (Term*)malloc(sizeof(Term));
	int begin = 0, i = 0, len = strlen(body);
	int sign = 1, coef = 0, expo_x = 0, expo_y = 0;
	int flag = 0;

	if (body[i] == '-') {
		i++;
		begin++;
		sign *= -1;
	}

	while (i < len && isdigit(body[i])) {
		i++;
	}

	if (begin == i) { // 계수가 1 or -1
		coef = 1;
	}

	if (body[i] == 'x' && body[i + 1] == '^') {
		flag = 1;
	}
	else if (body[i] == 'x' && body[i + 1] != '^') {
		flag = 0;
		expo_x = 1;
	}

	while (begin < i && body[begin] >= '0' && body[begin] <= '9') { // 계수 문자열을 숫자로 변환 
		coef = coef * 10 + (int)(body[begin] - '0');
		begin++;
	}

	if (coef == 0) {
		coef = sign;
	}
	else {
		coef *= sign;
	}

	if (body[i] != 'y' && body[i] != 'x') { // 상수항
		term->expo_x = 0;
		term->expo_y = 0;
		term->coef = coef;
		return term;
	}

	// ------------------------------------------------

	while (!isdigit(body[i]) && flag) {
		i++;
	}

	begin = i;

	while (i < len && isdigit(body[i]) && flag) {
		i++;
	}

	while (begin < i && body[begin] >= '0' && body[begin] <= '9' && flag) { // 계수 문자열을 숫자로 변환 
		expo_x = expo_x * 10 + (int)(body[begin] - '0');
		begin++;
	}

	while (!isdigit(body[i]) && i < len) {
		i++;
	}

	begin = i;

	while (i < len && isdigit(body[i]) && i < len) {
		i++;
	}
	if (body[i - 1] == 'y') {
		expo_y = 1;
	}
	while (begin < i && body[begin] >= '0' && body[begin] <= '9') { // 계수 문자열을 숫자로 변환 
		expo_y = expo_y * 10 + (int)(body[begin] - '0');
		begin++;
	}

	term->expo_x = expo_x;
	term->expo_y = expo_y;
	term->coef = coef;
	return term;
}
