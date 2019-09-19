#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 500
#define MAX_COUNT 500

struct Music {
	char music[MAX_LEN];
	char artist[MAX_LEN];
	char track_number[MAX_LEN];
};

int main(void) {
	Music music[MAX_COUNT];
	int i, j, k;
	int n, len;
	int index = 1;
	int cnt = 0;
	char buffer[MAX_LEN];
	char * torken;
	char temp[MAX_LEN];

	scanf("%d", &n);
	getchar(); // ���� ���� ����

	for (i = 0; i < n; i++) {
		fgets(buffer, MAX_LEN, stdin);
		torken = strtok(buffer, "-");

		strcpy(music[i].music, torken); // ��������
		len = strlen(music[i].music);
		music[i].music[len - 1] = '\0'; // ���� ���� �� �ι��� �߰�

		torken = strtok(NULL, "-");
		strcpy(music[i].artist, torken); // ��Ƽ��Ʈ
		for (k = 0; k < strlen(music[i].artist)-2; k++) {
			music[i].artist[k] = music[i].artist[k + 1];
		}
		music[i].artist[k] = '\0';

		torken = strtok(NULL, torken); // ������ ����
		strcpy(music[i].track_number, torken);

		// ������ ���ڿ��� ���ڸ� �̱�
		while (1) {

			if (isdigit(music[i].track_number[index])) {
				// # �ڿ� ���ڸ� ������ ��ĭ �ű��.
				music[i].track_number[cnt++] = music[i].track_number[index++];
			}
			else {
				music[i].track_number[cnt] = '\0';
				cnt = 0, index = 1;
				break;
			}
		} // ���� �ϼ�
	}

	// ������ ����
	for (i = 0; i < n - 1; i++) {
		int index = i;
		for (j = i + 1; j < n; j++) {
			if (atoi(music[index].track_number)>atoi(music[j].track_number))// buffer[index] >= buffer[j]
				index = j;
		}

		// ����
		strcpy(temp, music[index].music);
		strcpy(music[index].music, music[i].music);
		strcpy(music[i].music, temp);

		// ��Ƽ��Ʈ
		strcpy(temp, music[index].artist);
		strcpy(music[index].artist, music[i].artist);
		strcpy(music[i].artist, temp);

		// ����
		strcpy(temp, music[index].track_number);
		strcpy(music[index].track_number, music[i].track_number);
		strcpy(music[i].track_number, temp);

		// �׳� ����ü �迭 �ε����� �ٲ㵵 �ȴ�. 
	}

	for (int i = 0; i < n; i++) {
		if (strlen(music[i].track_number)==1) {
			printf("0%s-%s-%s.mp3\n", music[i].track_number, music[i].music, music[i].artist);
		}
		else {
			printf("%s-%s-%s.mp3\n", music[i].track_number, music[i].music, music[i].artist);
		}


	}
}
