#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 300

typedef struct {
	int year, month, day, hour, minute, second;
}MyDate;

MyDate *dates[MAX];
int g_count;

void date_to_int(char str[]);
int compartDate(MyDate *m1, MyDate *m2);

int main() {
	MyDate *key;
	int n;
	char buffer[MAX];
	scanf("%d", &n);
	getchar();
	
	for (int i = 0; i < n; i++) {
		fgets(buffer, sizeof(buffer), stdin);

		date_to_int(buffer);

	}


	for (int i = 0; i < n; i++) {
		key = (MyDate*)malloc(sizeof(MyDate));
		for (int j = 0; j < n - 1; j++) {
			if (compartDate(dates[j], dates[j + 1]) == 0) {
				key = dates[j];
				dates[j] = dates[j + 1];
				dates[j + 1] = key;
			}
		}
	}

	for (int i = 0; i < g_count; i++) {
		printf("%02d-%02d-%02d:%02d:%02d:%02d\n", dates[i]->year, dates[i]->month, dates[i]->day, dates[i]->hour, dates[i]->minute, dates[i]->second);
	}

	return 0;

}

void date_to_int(char str[]) {
	char tmp[MAX];
	char* token;
	int len, i;
	dates[g_count] = (MyDate*)malloc(sizeof(MyDate));
	strcpy(tmp, str);
	len = strlen(tmp);

	for (i = 0; i < len; i++) {
		tmp[i] = tmp[i + 1];
	}
	tmp[i - 2] = '\0';

	token = strtok(tmp, "/");
	int num = atoi(token);
	dates[g_count]->day= num;

	token = strtok(NULL, "/");
	if (strcmp(token, "Jan") == 0) {
		dates[g_count]->month = 1;
	}
	else if (strcmp(token, "Feb") == 0) {
		dates[g_count]->month = 2;
	}
	else if (strcmp(token, "Mar") == 0) {
		dates[g_count]->month = 3;
	}
	else if (strcmp(token, "Apr") == 0) {
		dates[g_count]->month = 4;
	}
	else if (strcmp(token, "May") == 0) {
		dates[g_count]->month = 5;
	}
	else if (strcmp(token, "Jun") == 0) {
		dates[g_count]->month = 6;
	}
	else if (strcmp(token, "Jul") == 0) {
		dates[g_count]->month = 7;
	}
	else if (strcmp(token, "Aug") == 0) {
		dates[g_count]->month = 8;
	}
	else if (strcmp(token, "Sep") == 0) {
		dates[g_count]->month = 9;
	}
	else if (strcmp(token, "Oct") == 0) {
		dates[g_count]->month = 10;
	}
	else if (strcmp(token, "Nov") == 0) {
		dates[g_count]->month = 11;
	}
	else if (strcmp(token, "Dec") == 0) {
		dates[g_count]->month = 12;
	}

	token = strtok(NULL, ":");
	dates[g_count]->year = atoi(token);

	token = strtok(NULL, ":");
	dates[g_count]->hour = atoi(token);

	token = strtok(NULL, ":");
	dates[g_count]->minute = atoi(token);

	token = strtok(NULL, ":");
	dates[g_count]->second = atoi(token);

	g_count++;

}

int compartDate(MyDate *m1, MyDate *m2)
{
	if (m1->year > m2->year) {
		return 0;
	}
	else if (m1->year < m2->year) {
		return 1;
	}

	if (m1->month > m2->month) {
		return 0;
	}
	else if (m1->month < m2->month) {
		return 1;
	}

	if (m1->day > m2->day) {
		return 0;
	}
	else if (m1->day < m2->day) {
		return 1;
	}

	if (m1->hour > m2->hour) {
		return 0;
	}
	else if (m1->hour < m2->hour) {
		return 1;
	}

	if (m1->minute > m2->minute) {
		return 0;
	}
	else if (m1->minute < m2->minute) {
		return 1;
	}

	if (m1->second > m2->second) {
		return 0;
	}
	else if (m1->second < m2->second) {
		return 1;
	}

	return 2;

}


