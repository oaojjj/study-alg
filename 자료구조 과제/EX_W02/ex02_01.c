#include <stdio.h>
#include <string.h>

int main() {
	char buffer[21];
	char temp;
	int len;
	int i, j;

	scanf("%s", buffer);

	len = strlen(buffer);
	for (i = 0; i < len-1; i++) {
		int index = i;
		for (j = i + 1; j < len; j++) {
			if (buffer[index] >= buffer[j])
				index = j;
		}
		temp = buffer[index];
		buffer[index] = buffer[i];
		buffer[i] = temp;

	}

	printf("%s", buffer);
}
