#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 300

typedef struct node {
	int i;
	struct node *next;
}Node;

node *top;

int count;

bool is_empty() {
	return top == NULL;
}

void push(int i) {
	if (top == NULL) {
		top= (Node*)malloc(sizeof(Node));
		top->i = i;
		top->next=NULL;
	}
	else {
		Node *node = (Node*)malloc(sizeof(Node));
		node->i = i;
		node->next = top;
		top = node;
	}
	printf("%d ", i);
}

void pop() {
	int i;
	node *old_top;

	old_top = top;
	i = top->i;
	printf("%d ",i);
	top = old_top->next;
	free(old_top);
}

int read_line(char *str) {
	int len;
	fgets(str, BUFFER_SIZE, stdin);
	len = strlen(str) - 1;
	str[len] = '\0';
	return len;
}

int main() {
	int ch;
	int cnt = 1;
	while (1) {
		ch = getchar();
		if (ch == '\n')
			break;
		if (ch == '(') {
			push(cnt++);
		}
		else if (ch == ')') {
			pop();
		}
	}
}






