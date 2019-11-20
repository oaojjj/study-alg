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