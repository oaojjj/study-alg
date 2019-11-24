#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_type *Stack;
#define BUFFER_SIZE 100

typedef struct node {
	char *contents;
	struct node *next;
}Node;

struct stack_type
{
	Node * top;
	char *name;
};

Stack stack[100];
int count;

void create(char * name) {
	Stack s = (Stack)malloc(sizeof(struct stack_type));
	if (s == NULL)
		return;
	s->name = strdup(name);
	s->top = NULL;
	stack[count++] = s;
}

bool is_empty(Stack s) {
	return s->top == NULL;
}

void push(char * name, char* str) {
	int i;
	for (i = 0; i < count; i++) {
		if (strcmp(stack[i]->name, name) == 0)
			break;
	}
	if (i == count)
		return;
	Node *node = (Node*)malloc(sizeof(Node));
	node->contents = strdup(str);
	node->next = stack[i]->top;
	stack[i]->top = node;
}

void pop(char *name) {
	Node *old_top;
	char *item;
	int i;
	for (i = 0; i < count; i++) {
		if (strcmp(stack[i]->name, name) == 0)
			break;
	}
	if (is_empty(stack[i]))
		return;

	old_top = stack[i]->top;
	item = stack[i]->top->contents;
	printf("%s\n", item);
	stack[i]->top = old_top->next;
	free(old_top);
}

void list(char *name) {
	int i;
	for (i = 0; i < count; i++) {
		if (strcmp(stack[i]->name, name) == 0)
			break;
	}
	Node*node=stack[i]->top;
	while (node != NULL) {
		printf("%s\n", node->contents);
		node = node->next;
	}
}

int read_line(char *str) {
	int len;
	fgets(str, BUFFER_SIZE, stdin);
	len = strlen(str) - 1;
	str[len] = '\0';
	return len;
}

int main() {
	char command_line[BUFFER_SIZE];
	char * command, *str, *name;
	while (1) {
		if (read_line(command_line) <= 0)
			continue;
		command = strtok(command_line, " ");
		if (strcmp(command, "create") == 0) {
			name = strtok(NULL, " ");
			create(name);
		}
		else if (strcmp(command, "push") == 0) {
			name = strtok(NULL, " ");
			str = strtok(NULL, " ");
			push(name, str);
		}
		else if (strcmp(command, "pop") == 0) {
			name = strtok(NULL, " ");
			pop(name);
		}
		else if (strcmp(command, "list") == 0) {
			name = strtok(NULL, " ");
			list(name);
		}
		else if (strcmp(command, "exit") == 0) {
			break;
		}
	}
}






