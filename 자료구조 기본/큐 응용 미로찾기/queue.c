#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node {
	Position pos;
	Node*next;
};

struct queue_type {
	struct node*front;
	struct node*rear;
	int size;
};

Queue create() {
	Queue q = (Queue)malloc(sizeof(struct queue_type));
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
	return q;
}

void destory(Queue q) {
	make_empty(q);
	free(q);
}

void make_empty(Queue q) {
	while (!is_empty(q)) {
		dequeue(q);
	}
	q->size = 0;
}

void enqueue(Queue q, Item i) {
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->pos = i;
	new_node->next = NULL;
	if (q->front == NULL) {
		q->front = new_node;
		q->rear = new_node;
	}
	else {
		q->rear->next = new_node;
		q->rear = new_node;
	}
	q->size++;
}

Item dequeue(Queue q) {
	if (is_empty(q)) {
		printf("error dequeue");
		return;
	}
	Node *old_front;
	Item i;
	old_front = q->front;
	i = old_front->pos;
	q->front = old_front->next;
	if (q->front == NULL)
		q->rear = NULL;
	free(old_front);
	q->size--;
	return i;
}

Item peek(Queue q) {
	if (is_empty(q)) {
		printf("error peek");
		return;
	}
	return q->front->pos;
}

bool is_empty(Queue q) {
	return q->size == 0;
}

int get_size(Queue q) {
	return q->size;
}