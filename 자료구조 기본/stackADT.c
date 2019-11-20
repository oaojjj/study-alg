/* stack.h
#pragma once

#include <stdbool.h>

typedef int Item;
typedef struct stack_type *Stack;

Stack create();
void push(Stack s, Item i);
Item pop(Stack s);
Item peek(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
*/

#include <stdio.h>
#include "stack.h"

#define INIT_CAPACITY 100

struct stack_type {
	Item* contents;
	int top;
	int size;
};

void reallocate(Stack s) {
	Item* tmp = (Item *)malloc(2 * s->size * sizeof(Item));
	for (int i = 0; i < s->top; i++)
		tmp[i] = s->contents[i];
	free(s->contents);
	s->contents = tmp;
	s->size *= 2;
}

Stack create() {
	Stack s = (Stack)malloc(sizeof(struct stack_type));
	s->contents = (Item)malloc(sizeof(Item)*INIT_CAPACITY);
	s->top = -1;
	s->size = INIT_CAPACITY;
	return s;
}

void push(Stack s, Item i) {
	if (is_full(s)) {
		reallocate(s);
	}
	s->top++;
	s->contents[s->top] = i;
}

Item peek(Stack s) {
	if (is_empty(s)) {
		printf("error peek");
		return 0;
	}
	return s->contents[s->top];
}

Item pop(Stack s) {
	if (is_empty(s)) {
		printf("error pop");
		return 0;
	}
	s->top--;
	return s->contents[s->top+1];
}

bool is_empty(Stack s) {
	return s->top == -1;
}

bool is_full(Stack s) {
	return s->size == s->top - 1;
}
