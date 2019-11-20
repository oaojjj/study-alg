#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pos.h"
#include "stackADT.h"

#define MAX 100
#define PATH 0 // ������ �� �ִ� ��ġ
#define WALL 1 // ��
#define VISITED 2 // �̹� �湮�� ��ġ
#define BACKTRACKED 3 // �湮�ߴ� ��ġ
#define EXIT 9 // �ⱸ

int maze[MAX][MAX];
int n; // �̷�ũ�� ���Ͽ��� �� ó���� ���� #if n=3,, 3x3�̷�
int offset[4][2];

void read_maze();
void print_maze();
bool movealbe(Position cur, int dir);

int main() {
	read_maze();

	Stack s = create(); 
	Position cur;
	cur.x = 0;
	cur.y = 0;

	int init_dir = 0; // � ��ġ�� �������� �� ó������ �õ��ϴ� �̵� ����
	while (1) {
		maze[cur.y][cur.x] = VISITED;
		print_maze();
		printf("\n\n");

		bool forwarded = false;
		for (int dir = init_dir; dir < 4; dir++) { // ��:0, ��:1, ��:2, ��:3
			if (movealbe(cur, dir)) {
				push(s, dir); // ���ÿ� ���� ��ġ ��� �̵��ϴ� ������ push
				cur = move_to(cur, dir);
				forwarded = true;
				init_dir = 0;
				break;
			}
		}

		if (!forwarded) { // ����� �湮���� ���� ���
			maze[cur.y][cur.x] = BACKTRACKED;
			if (is_empty(s)) {
				printf("no path exists\n");
				break;
			}

			int d = pop(s);
			cur = move_to(cur, (d + 2) % 4); // if top is 2 ,,,(2+2)%4=0
			
			init_dir = d + 1; // �ǵ��� �°����� �湮�ϴ� ���� ��ġ
		}

	}
	print_maze();
}

void read_maze() {
	FILE*fp = fopen("maze.txt","r");

	if (fp == NULL) {
		printf("error read maze\n");
		return;
	}
	int i, j;
	fscanf(fp, "%d", &n);
	for(int i=0;i<n;i++){
		for (int j = 0; j < n; j++) {
			fscanf(fp, "%d", &maze[i][j]);
		}
	}
	fclose(fp);
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
	if ((cur.x < 0 || cur.x >= n) || (cur.y<0 || cur.y>=n)) // �̵��� ��ġ�� �̷θ� ����� �ȵȴ�.
		return false;
	if (maze[cur.y][cur.x] == PATH) // �̵��� ��ġ�� PATH��� �̵��� �� �ִ�.
		return true;
	if (maze[cur.y][cur.x] == EXIT) {
		printf("found the exit\n");
		exit(0);
	}
		
	return false;
}
