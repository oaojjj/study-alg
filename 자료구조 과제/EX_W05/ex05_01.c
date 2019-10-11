#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT 30

typedef struct Node{
	struct Node *next;
	int data;
} Node;

Node *head;
int g_node_cnt;

int read_line(char* buffer);
void add_node(int index, int data);
void add_head(int data);
void add_after(int index, int data);
void delete_node(int data);
void delete_head();
void delete_after(Node * prev, Node * next);
int find(int data);
int count(int data);
void list();

int main() {
	char buffer[MAX_INPUT];
	char* token;
	int index, data;
	int flag=0;

	while (1) {
		printf("$ ");
		read_line(buffer);
		token = strtok(buffer, " ");
		printf("\n");
		// 명령어 뒤의 예외처리는 하지 않는다
		if (strcmp(token, "add") == 0) {
			index = atoi(strtok(NULL, " "));
			data = atoi(strtok(NULL, " "));
			add_node(index, data);
		}
		else if (strcmp(token, "delete") == 0) {
			data = atoi(strtok(NULL, " "));
			delete_node(data);
		}
		else if (strcmp(token, "find") == 0) {
			data = atoi(strtok(NULL, " "));
			printf("%d\n",find(data));
		}
		else if (strcmp(token, "count") == 0) {
			data = atoi(strtok(NULL, " "));
			printf("%d\n",count(data));
		}
		else if (strcmp(token, "list") == 0) {
			list();
		}
		else if (strcmp(token, "exit") == 0) {
			return 0;
		}
	}
}

// 헤드 노드를 만드는 함수
void add_head(int data) {
	head = (Node*)malloc(sizeof(Node));

	head->data = data;
	head->next = NULL;
	g_node_cnt++;
}

// 노드 삽입,기존 노드 변경 함수
void add_after(int index, int data) {
	Node* tmp = head;

	for (int i = 0; i < index-1; i++) {
		tmp = tmp->next;
	}

	if (index == g_node_cnt) { // 새로운 노드를 추가 할 경우
		Node* node = (Node*)malloc(sizeof(Node));

		tmp->next = node;
		node->data = data;
		node->next = NULL;
		
		g_node_cnt++;

	}
	else { // 기존 노드를 수정 할 경우
		tmp->data = data;
	}
}

void add_node(int index, int data) {
	if (index > g_node_cnt) {
		printf("invalid index\n");
	}
	else {
		if (head==NULL) {
			add_head(data);
		}
		else {
			add_after(index, data);
		}
	}

}

// 헤드 노드 삭제 함수
void delete_head() {
	Node* tmp = head;
	head = head->next;
	free(tmp);
	tmp = NULL;
	
	g_node_cnt--;
}

// next로 넘어오는 노드 삭제 함수
void delete_after(Node* prev,Node* next) {
	prev->next = next->next;
	free(next);
	next = NULL;

	g_node_cnt--;
}

void delete_node(int data) {

	if (head == NULL) {
		return;
	}

	Node* prev = head;
	Node* next = head;
	for (int i = 0; i < g_node_cnt; i++) {
		if (next->data == data) {
			if (i == 0) {
				delete_head();
				return;
			}
			else {
				delete_after(prev, next);
				return;
			}
		}
		prev = next;
		next = next->next;
	}
	printf("not exist\n");
}

int find(int data) {
	if (head == NULL) {
		return -1;
	}
	Node* tmp = head;

	for (int i = 0; i < g_node_cnt; i++) {
		if (tmp->data == data) {
			return i;
		}
		tmp = tmp->next;
	}
	return -1;
}

int count(int data) {

	if (head == NULL) {
		return 0;
	}

	Node*tmp = head;
	int count = 0;

	for (int i = 0; i < g_node_cnt; i++) {
		if (tmp->data == data) {
			count++;
		}
		tmp = tmp->next;
	}
	return count;
}

void list() {
	Node* tmp = head;
	for (int i = 0; i < g_node_cnt; i++) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	if(g_node_cnt>0)
		printf("\n");
}

int read_line(char* buffer) {
	int len;

	fgets(buffer, MAX_INPUT, stdin);
	len = strlen(buffer) - 1;

	buffer[len] = '\0';
	return len;
}
