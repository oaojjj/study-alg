#include <stdio.h>
#define MAX 100
int find_max(int, int *);
int main()
{
	int N;
	int data[MAX];
	scanf("%d", &N);
	for (int i = 0; i<N; i++)
		scanf("%d", &data[i]);
	int mx = find_max(N, data);
	printf("%d\n", mx);
}

int find_max(int n, int *data) {
	int max;
	max = *data;
	for (int i = 0; i < n; i++) {
		if (*data > max) {
			max = *data;
			
		}
		data++;
	}
	return max;
}


