#include <stdio.h>
#include <string.h>

#define MAX_LEN 500

int main() {
	char buffer[MAX_LEN];
	char* tmp[MAX_LEN];
	char* torken;
	int cnt = 0;

	fgets(buffer, MAX_LEN, stdin);
	buffer[strlen(buffer) - 1] = '\0';
	torken = strtok(buffer, ",");

	while (torken!=NULL) {
		tmp[cnt++] = strdup(torken);
		torken = strtok(NULL, ",");

	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%s\n", tmp[i]);
	}
}
