#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100
#define PATH 0 // ������ �� �ִ� ��ġ
#define WALL 1 // ��
#define VISITED 2 // �̹� �湮�� ��ġ
#define BACKTRACKED 3 // �湮�ߴ� ��ġ

typedef struct pos {
	int x, y;
}Position;

struct node {
	struct node* next;
	Position contents;
};

struct stack_type {
	struct node* top;
	int size;
};

int maze[MAX][MAX];
Position start, end;
int offset[8][2] = { {-2, -1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2} };
int n; // �̷�ũ�� ���Ͽ��� �� ó���� ���� #if n=3,, 3x3�̷�

void read_maze();
void print_maze();
bool movealbe(Position cur, int dir);
typedef Position Item;
typedef struct node Node;
typedef struct stack_type *Stack;
Position move_to(Position pos, int dir);
Stack create();
void push(Stack s, Item i);
Item pop(Stack s);
Item peek(Stack s);
bool is_empty(Stack s);

int main(void) {
	read_maze();

	Stack s = create();
	Position cur;
	cur.x = start.x;
	cur.y = start.y;

	//maze[end.y][end.x] = 9;
	int i = 2;
	int init_dir = 0; // � ��ġ�� �������� �� ó������ �õ��ϴ� �̵� ����
	while (1) {
		maze[cur.y][cur.x] = VISITED;
		bool forwarded = false;
		if (cur.x == end.x && cur.y == end.y) {
			if (maze[end.y][end.x] == 1) {
				printf("No");
			}
			printf("Yes\n");
			break;
		}
		for (int dir = 0; dir < 8; dir++) {
			if (movealbe(cur, dir)) {
				push(s, cur);
				cur = move_to(cur, dir);
				forwarded = true;
				break;
			}
		}

		if (!forwarded) { // ����� �湮���� ���� ���
			maze[cur.y][cur.x] = BACKTRACKED;
			if (is_empty(s)) {
				printf("No\n");
				break;
			}
			cur = pop(s);
		}

	}
}

void read_maze() {
	int i, j;
	fscanf(stdin, "%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(stdin, "%d", &maze[i][j]);
		}
	}
	fscanf(stdin, "%d %d", &start.y, &start.x);
	fscanf(stdin, "%d %d", &end.y, &end.x);
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
	Position first;
	if (dir >= 0 && dir < 2) {
		first.x = cur.x;
		first.y = cur.y - 1;
	}
	else if (dir >= 2 && dir < 4) {
		first.x = cur.x + 1;
		first.y = cur.y;
	}
	else if (dir >= 4 && dir < 6) {
		first.x = cur.x;
		first.y = cur.y + 1;
	}
	else if (dir >= 6 && dir < 8) {
		first.x = cur.x - 1;
		first.y = cur.y;
	}
	cur.x += offset[dir][1];
	cur.y += offset[dir][0];
	if ((cur.x < 0 || cur.x >= n) || (cur.y < 0 || cur.y >= n) ||
		(first.x < 0 || first.x >= n) || (first.y < 0 || first.y >= n))// �̵��� ��ġ�� �̷θ� ����� �ȵȴ�.
		return false;
	if (maze[first.y][first.x] != WALL) {
		if (maze[cur.y][cur.x] == PATH) // �̵��� ��ġ�� PATH��� �̵��� �� �ִ�.
			return true;
	}
	return false;
}

Stack create() {
	Stack s = (Stack)malloc(sizeof(struct stack_type));
	s->top = (Node*)malloc(sizeof(Node));
	s->top = NULL;
	s->size = 0;
	return s;
}

void push(Stack s, Item i) {
	Node*n = (Node*)malloc(sizeof(Node));
	n->contents = i;
	n->next = s->top;
	s->size++;
	s->top = n;
}

Item peek(Stack s) {
	return s->top->contents;
}

Item pop(Stack s) {
	Item i;
	Node*old_top;
	old_top = s->top;
	i = old_top->contents;
	s->top = s->top->next;
	s->size--;
	free(old_top);
	return i;
}

bool is_empty(Stack s) {
	return s->top == NULL;
}

Position move_to(Position pos, int dir) {
	Position next;
	next.x = pos.x + offset[dir][1];
	next.y = pos.y + offset[dir][0];
	return next;
}
