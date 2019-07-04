#include <stdio.h>

int main(void) {
	int sieve[100] = { 0 };

	for (int i = 2; i < 100; i++) { //수학공식을 이용하여 조건식을 루트(개수)로 할 수 도있다.
		if (sieve[i] == 1)
			continue;
		for (int j = i+i; j < 100; j +=j) {
			sieve[j] = 1;
		}
	}

	for (int i = 2; i < 100; i++) {
		if (sieve[i] != 1)
			printf("%3d ", i);
		if (!(i % 10))
			printf("\n");
	}
}
