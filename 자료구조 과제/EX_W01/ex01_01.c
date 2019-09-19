#include <stdio.h>

void sort_abc(int* n1, int* n2, int* n3);
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	sort_abc(&a, &b, &c);
	printf("%d %d %d\n", a, b, c);
}

void sort_abc(int* n1, int* n2, int* n3) {
	int a = *n1, b = *n2, c = *n3;
	int tmp;

	if (a > b) {
		if (a > c) {
			*n3 = a;
			if (c > b) {
				*n2 = c;
				*n1 = b;
			}
			else {
				*n2 = b;
				*n1 = c;
			}
		}
		else {
			*n3 = c;
			*n2 = a;
			*n1 = b;
		}
	}
	else if (b > a) {
		if (b > c) {
			*n3 = b;
			if (a > c) {
				*n2 = a;
				*n1 = c;
			}
			else {
				*n2 = c;
				*n1 = a;
			}
		}
		else {
			*n3 = c;
			*n2 = b;
			*n1 = a;
		}

	}

}
