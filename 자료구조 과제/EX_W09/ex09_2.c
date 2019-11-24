#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100
#define PATH 0 // 지나갈 수 있는 위치
#define WALL 1 // 벽

int maze[MAX][MAX];
int origin_maze[MAX][MAX];
int n; // 미로크기 파일에서 맨 처음에 제공 #if n=3,, 3x3미로
int offset[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

typedef struct pos {
	int x, y;
}Position;

typedef struct node {
	Position pos;
	struct node* next;
}Node;

struct queue_type {
	struct node*front;
	struct node*rear;
	int size;
};

typedef Position Item;
typedef struct queue_type *Queue;

Position move_to(Position pos, int dir);
Queue create();
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item peek(Queue q);
int get_size(Queue q);
void destory(Queue q);
void make_empty(Queue q);
bool is_empty(Queue q);
void read_maze();
void print_maze();
bool movealbe(Position cur, int dir);

int main() {
	read_maze();
	int min = 9999;
	int num;
	for (int i = 0; i < n; i++) {
		Queue queue = create();
		Position cur = {i,0 };
			memcpy(maze, origin_maze, sizeof(maze));
		if (maze[cur.y][cur.x] == 1)
			continue;
		maze[cur.y][cur.x] = -1;
		enqueue(queue, cur);
		while (!is_empty(queue)) {
			cur = dequeue(queue);
			for (int dir = 0; dir < 4; dir++) { // 북:0, 동:1, 남:2, 서:3
				if (movealbe(cur, dir)) {
					Position p = move_to(cur, dir);
					num = maze[cur.y][cur.x] - 1;
					maze[p.y][p.x] = num;
					if (p.y == n - 1) {
						if (min > (num*-1)) {
							min = num*-1;
							queue->size = 0;
							break;
						}
							
					}
					enqueue(queue, p);
				}
			}
		}
	}
	if (min != 9999) {
		printf("%d", min-1);
	}
	else
		printf("-1");
}

void read_maze() {
	int i, j;
	fscanf(stdin, "%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(stdin, "%d", &origin_maze[i][j]);
		}
	}
}

void print_maze() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d", maze[i][j]);
		}
		printf("\n");
	}
}


bool movealbe(Position cur, int dir) {
	cur.x += offset[dir][1];
	cur.y += offset[dir][0];
	if ((cur.x < 0 || cur.x >= n) || (cur.y < 0 || cur.y >= n)) // 이동할 위치가 미로를 벗어나면 안된다.
		return false;
	if (maze[cur.y][cur.x] == PATH) // 이동할 위치가 PATH라면 이동할 수 있다.
		return true;
	return false;
}

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
	return q->front->pos;
}

bool is_empty(Queue q) {
	return q->size == 0;
}

int get_size(Queue q) {
	return q->size;
}

Position move_to(Position pos, int dir) {
	Position next;
	next.x = pos.x + offset[dir][1];
	next.y = pos.y + offset[dir][0];
	return next;
}
