#include <stdio.h>
#define MAX 100
int find_max(int, int *);
int main()
{
	int N;
	int data[MAX];
	int j, i;
	int tmp;
	int min, min_i=0;
	scanf("%d", &N);
	for (int i = 0; i<N; i++)
		scanf("%d", &data[i]);

	for (i = 0; i < N; i++) {
		min = *(data + i);
		for (j = i; j < N; j++) {
			if (min >= *(data + j)) {
				min = *(data + j);
				min_i=j;
			}
		}
		tmp = *(data + i);
		*(data + i) = min;
		*(data + min_i) = tmp;
	
	}

	for (i = 0; i < N; i++) {
		printf("%d\n", *(data + i));
	}
}
