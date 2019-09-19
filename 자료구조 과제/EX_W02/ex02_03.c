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
	getchar(); // 버퍼 엔터 비우기

	for (i = 0; i < n; i++) {
		fgets(buffer, MAX_LEN, stdin);
		torken = strtok(buffer, "-");

		strcpy(music[i].music, torken); // 음악제목
		len = strlen(music[i].music);
		music[i].music[len - 1] = '\0'; // 공백 제거 후 널문자 추가

		torken = strtok(NULL, "-");
		strcpy(music[i].artist, torken); // 아티스트
		for (k = 0; k < strlen(music[i].artist)-2; k++) {
			music[i].artist[k] = music[i].artist[k + 1];
		}
		music[i].artist[k] = '\0';

		torken = strtok(NULL, torken); // 나머지 숫자
		strcpy(music[i].track_number, torken);

		// 나머지 문자에서 숫자만 뽑기
		while (1) {

			if (isdigit(music[i].track_number[index])) {
				// # 뒤에 숫자만 앞으로 한칸 옮긴다.
				music[i].track_number[cnt++] = music[i].track_number[index++];
			}
			else {
				music[i].track_number[cnt] = '\0';
				cnt = 0, index = 1;
				break;
			}
		} // 숫자 완성
	}

	// 사전식 정렬
	for (i = 0; i < n - 1; i++) {
		int index = i;
		for (j = i + 1; j < n; j++) {
			if (atoi(music[index].track_number)>atoi(music[j].track_number))// buffer[index] >= buffer[j]
				index = j;
		}

		// 제목
		strcpy(temp, music[index].music);
		strcpy(music[index].music, music[i].music);
		strcpy(music[i].music, temp);

		// 아티스트
		strcpy(temp, music[index].artist);
		strcpy(music[index].artist, music[i].artist);
		strcpy(music[i].artist, temp);

		// 숫자
		strcpy(temp, music[index].track_number);
		strcpy(music[index].track_number, music[i].track_number);
		strcpy(music[i].track_number, temp);

		// 그냥 구조체 배열 인덱스만 바꿔도 된다. 
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
