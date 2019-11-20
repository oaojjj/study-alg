#pragma once

#include <stdbool.h>
#include "pos.h"

typedef Position Item;
typedef struct node Node;
typedef struct queue_type *Queue;

Queue create();
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item peek(Queue q);
int get_size(Queue q);
void destory(Queue q);
void make_empty(Queue q);
bool is_empty(Queue q);
