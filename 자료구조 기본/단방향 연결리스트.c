#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 30

// 단방향 연결리스트 구현
// add 노드 추가
// remove 노드 삭제
// find 노드 찾기
// status 목록 출력
// exit 종료

typedef struct Node {
	struct Node* next;
	int data;
}Node;

int read_line(char str[]);
Node* add_first(Node* node, int data);
Node* add(Node* node, int data);
Node* add_after(Node* node, int data) 
Node* remove_first(Node* node) ;
Node* remove_node(Node* node, int data);
Node* remove_after(Node* node,int data) 
int find(Node* head, int data);
void status(Node* head);

int main() {
	Node* head = NULL;
	char buffer[MAX_LEN];
	char* c_data;
	char* token;
	int data;

	printf("add number, remove num, find num, status, exit\n");
	while (1) {
		read_line(buffer);
		token = strtok(buffer, " ");
		c_data = strtok(NULL, " ");

		if (c_data != NULL) {
			data = atoi(c_data);
			if (data==0 && strcmp(c_data, "0")) {
				continue;
			}
		}
		else {
			if (strcmp(token, "status") != 0 || strcmp(token, "exit") != 0) {
				continue;
			}
		}

		if (strcmp(token, "add") == 0) {
			/*token = strtok(NULL, " ");
			data = atoi(token);*/
			head = add(head, data);
		}
		else if (strcmp(token, "remove") == 0) {
			head = remove_node(head, data);
		}
		else if (strcmp(token, "find") == 0) {
			int index = find(head, data);
			if (index == 0) {
				printf("Not found\n");
			}
			else {
				printf("It is %02d Node\n", index);
			}
		}
		else if (strcmp(token, "status") == 0) {
			status(head);
		}
		else if (strcmp(token, "exit") == 0) {
			return 0;
		}

	}// while
}

Node* add_first(Node* node, int data) {
	node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

Node* add_after(Node* node, int data) {
	Node* head = node;
	Node* tmp = (Node*)malloc(sizeof(Node));
	while (node->next != NULL) {
		node = node->next;
	}
	node->next = tmp;
	tmp->data = data;
	tmp->next = NULL;
	return head;
}


Node* add(Node* node, int data) {
	if (node == NULL) {
		return add_first(node, data);
	}
	else {
		return add_after(node, data);
	}
}

Node* remove_first(Node* node) {
	if (node->next == NULL)
		return NULL;
	return node->next;
}

Node* remove_after(Node* node,int data) {
	Node* head = node;
	Node* tmp = (Node*)malloc(sizeof(Node));

	tmp = node;
	node = node->next;
	while (node != NULL) {
		if (node->data == data) {
			tmp->next = node->next;
			free(node);
			return head;
		}
		tmp = node;
		node = node->next;
	}

	printf("Not found\n");
	return node;
}


Node* remove_node(Node* node, int data) {
	if (node == NULL) {
		printf("Error : Node is NULL\n");
		return NULL;
	}

	if (node->data == data) {
		return remove_first(node);
	}
	else {
		return remove_after(node, data);
	}
}

int find(Node* head, int data) {
	int index = 1;
	if (head == NULL) {
		printf("Error : Node is NULL\n");
		return 0;
	}
	else {
		while (head != NULL) {
			if (head->data == data) {
				return index;
			}
			head = head->next;
			index++;
		}
	}
	return 0;
}

void status(Node* head) {
	int index = 1;

	if (head == NULL) {
		printf("Not found Node\n");
	}
	else {
		while (head != NULL) {
			printf("[Node %02d] %d\n", index++, head->data);
			head = head->next;
		}
	}
}


// 한줄씩 읽기
int read_line(char str[]) {
	int len;

	fgets(str, MAX_LEN, stdin);
	len = strlen(str) - 1;
	str[len] = '\0';
	return len;
}
