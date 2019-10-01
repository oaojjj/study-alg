#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define DATE_LEN 30
#define USER_INPUT_MAX_LEN 100
#define BUFFER_MAX_LEN 200
#define LOG_MAX_LEN 1500
#define IP_MAX_LEN 300

/* struct Log
 date[0] - day
 date[1] - year
 date[2] - time
 -----------------
*/
typedef struct Log {
	char* ip;
	char* date_url_status;
	char* date;
	char* date_time;
}Log;

typedef struct IP {
	char* ip;
	int count;
}IP;

typedef struct Logs {
	char* logs;
	char* date_time;
}Logs;

int read_line(char str[]);
void add_struct(Log log[], char str[]);
void add_ip(IP ip[], Log log[], int index);
void add_log(Log log[], Logs logs[], char* ip, int index);
char* date_to_int(char str[]);
void sort(IP ip[]);

int g_count;
int g_ip_count;
int g_logs_count;
//char* g_month[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

int main() {
	FILE* fp;
	Log log[LOG_MAX_LEN];
	IP ip[IP_MAX_LEN] = { NULL,0 };
	Logs logs[IP_MAX_LEN];

	char user_input[USER_INPUT_MAX_LEN];
	char buffer[BUFFER_MAX_LEN];
	char* token; // 사용자가 입력한 내용을 파악하기 위해 tokenize 위한 변수
	char* date_tmp;
	char* date1;
	char* date2;
	char* m_ip;
	char derim[] = " ";

	fp = fopen("webLog.txt", "r");
	if (fp == NULL) {
		printf("연결실패\n");
	}


	/*char* test1 = "2018/06:02:14]";
	char* test2 = "2017/11:02:14]";
	printf("%d\n", strcmp(test1, test2));*/

	// 처음 한줄 버리기
	fgets(buffer, BUFFER_MAX_LEN, fp);

	// csv파일 파싱
	while (TRUE) {
		fgets(buffer, BUFFER_MAX_LEN, fp);
		if (feof(fp)) {
			break;
		}
		//라인피드 지우기
		buffer[strlen(buffer) - 1] = '\0';

		add_struct(log, buffer);
	}
	fclose(fp);


	while (TRUE) {
		printf("$ ");
		read_line(user_input);

		token = strtok(user_input, derim);
		if (token == NULL) {
			continue;
		}
		else {
			if (strcmp(token, "search") == 0) {
				// 서치에 대한 기능 제공
				token = strtok(NULL, derim);
				if (token == NULL) {
					continue;
				}
				else {
					if (strcmp(token, "-date") == 0) {
						char* tmp1;
						char* tmp2;
						tmp1 = strtok(NULL, derim);
						tmp2 = strtok(NULL, derim);
						date1 = date_to_int(tmp1);
						date2 = date_to_int(tmp2);
						if (date1 != NULL && date2 != NULL) {
							// -date에 대한 기능 제공
							int cnt = 0;
							for (int i = 0; i < g_count; i++) {
								if (strcmp(log[i].date, date1) >= 0 && strcmp(log[i].date, date2) <= 0) {
									add_ip(ip, log, i);
								}
							}
							sort(ip);
							printf("%d ips found:\n", g_ip_count);
							for (int i = 0; i < g_ip_count; i++) {
								printf("%s: %d\n", ip[i].ip, ip[i].count);
							}
							g_ip_count = 0;
						}
					}
					else if (strcmp(token, "-ip") == 0) {
						m_ip = strtok(NULL, derim);
						if (m_ip != NULL) {
							// -ip에 대한 기능 제공
							for (int i = 0; i < g_count; i++) {
								if (strcmp(m_ip, log[i].ip) == 0) {
									add_log(log, logs, m_ip, i);
								}
							}
							printf("%d logs found\n", g_logs_count);
							for (int i = 0; i < g_logs_count; i++) {
								printf("%s\n", logs[i].logs);
							}
							g_logs_count = 0;
						}
					}
				}
			}
			else if (strcmp(token, "exit") == 0) {
				return 0;
			}
		} // else
	} //while
}

// 버퍼를 한줄씩 읽는 함수
int read_line(char str[]) {
	int ch;
	int index = 0;
	while ((ch = getchar()) != '\n' && index < USER_INPUT_MAX_LEN) {
		str[index++] = ch;
	}
	str[index] = '\0';
	return index - 1;
}

// 구조체에 추가하는 함수
void add_struct(Log log[], char str[]) {
	char *tmp;
	char tmp2[DATE_LEN];
	int len;

	// ip 저장
	log[g_count].ip = strdup(strtok(str, ","));

	// date_url_status 모두 저장
	log[g_count].date_url_status = strdup(strtok(NULL, ""));

	tmp = strdup(log[g_count].date_url_status);

	// date 저장
	strcpy(tmp2, strtok(tmp, ":"));
	log[g_count].date_time = strdup(strtok(NULL, "]"));
	len = strlen(tmp2);
	for (int i = 0; i < len; i++) {
		tmp2[i] = tmp2[i + 1];
	}

	log[g_count].date = date_to_int(tmp2);

	g_count++;
}

void add_log(Log log[], Logs logs[], char* ip, int index) {
	char buffer[DATE_LEN];
	Logs key;
	int i, j;

	strcpy(buffer, log[index].date);
	strcat(buffer, log[index].date_time);


	logs[g_logs_count].logs = log[index].date_url_status;
	logs[g_logs_count++].date_time = strdup(buffer);


	if (g_logs_count >= 2) {
		// 삽입정렬
		for (i = 1; i < g_logs_count; i++) {
			key = logs[i];
			j = i - 1;
			while (j >= 0 && strcmp(logs[j].date_time, key.date_time) > 0) {
				logs[j + 1] = logs[j];
				j--;
			}
			logs[j + 1] = key;
		}
	}



}

// ip추가 하는 함수
void add_ip(IP ip[], Log log[], int index) {
	int i;

	if (g_ip_count == 0) {
		ip[g_ip_count].ip = log[index].ip;
		ip[g_ip_count++].count++;
	}
	else {
		for (i = 0; i < g_ip_count; i++) {
			if (strcmp(ip[i].ip, log[index].ip) == 0) {
				ip[i].count++;
				return;
			}
		}
		if (i <= g_ip_count) {
			ip[g_ip_count].ip = log[index].ip;
			ip[g_ip_count++].count++;
		}
	}
}

// 03/Jan/2017 -> 20170103 문자열로 변환 해준다
char* date_to_int(char str[]) {
	char *date_tmp = (char*)malloc(sizeof(char) * 30);
	char* day = strtok(str, "/");
	char* month = strtok(NULL, "/");
	char* year = strtok(NULL, "/");

	strcpy(date_tmp, year);
	// 과제 제출 사이트에서 안됨
	/*int len = strlen(date_tmp);
	for (int i = 0; i < 12; i++) {
		if (strcmp(month, g_month[i]) == 0) {
			switch (i + 1) {
			case 1: strcat(date_tmp, "01"); break;
			case 2: strcat(date_tmp, "02"); break;
			case 3: strcat(date_tmp, "03"); break;
			case 4: strcat(date_tmp, "04"); break;
			case 5: strcat(date_tmp, "05"); break;
			case 6: strcat(date_tmp, "06"); break;
			case 7: strcat(date_tmp, "07"); break;
			case 8: strcat(date_tmp, "08"); break;
			case 9: strcat(date_tmp, "09"); break;
			case 10: strcat(date_tmp, "10"); break;
			case 11: strcat(date_tmp, "11"); break;
			case 12: strcat(date_tmp, "12"); break;
			}
			break;
		}
	}*/
	strcpy(date_tmp, year);
	if (strcmp(month, "Jan") == 0) { strcat(date_tmp, "01"); }
	else if (strcmp(month, "Feb") == 0) { strcat(date_tmp, "02"); }
	else if (strcmp(month, "Mar") == 0) { strcat(date_tmp, "03"); }
	else if (strcmp(month, "Apr") == 0) { strcat(date_tmp, "04"); }
	else if (strcmp(month, "May") == 0) { strcat(date_tmp, "05"); }
	else if (strcmp(month, "Jun") == 0) { strcat(date_tmp, "06"); }
	else if (strcmp(month, "Jul") == 0) { strcat(date_tmp, "07"); }
	else if (strcmp(month, "Aug") == 0) { strcat(date_tmp, "08"); }
	else if (strcmp(month, "Sep") == 0) { strcat(date_tmp, "09"); }
	else if (strcmp(month, "Oct") == 0) { strcat(date_tmp, "10"); }
	else if (strcmp(month, "Nov") == 0) { strcat(date_tmp, "11"); }
	else if (strcmp(month, "Dec") == 0) { strcat(date_tmp, "12"); }
	strcat(date_tmp, day);
	return date_tmp;
}

// ip삽입정렬
void sort(IP ip[]) {
	IP key;
	int i, j;

	for (int i = 1; i < g_ip_count; i++) {
		key = ip[i];
		j = i - 1;
		while (j >= 0 && ip[j].count < key.count) {
			ip[j + 1] = ip[j];
			j--;
		}
		ip[j + 1] = key;
	}
}
