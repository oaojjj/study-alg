#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pos.h"
#include "queueADT.h"

#define MAX 100
#define PATH 0 // 지나갈 수 있는 위치
#define WALL 1 // 벽
#define EXIT 2 // 출구

int maze[MAX][MAX];
int n; // 미로크기 파일에서 맨 처음에 제공 #if n=3,, 3x3미로
int offset[4][2];

void read_maze();
void print_maze();
bool movealbe(Position cur, int dir);

int main() {
	read_maze();

	Queue queue = create();
	Position cur = { 0,0 };
	enqueue(queue,cur);

	maze[0][0] = -1;
	while (!is_empty(queue)) {
		//print_maze();
		//printf("\n\n");
		Position cur = dequeue(queue);
		for (int dir = 0; dir < 4; dir++) { // 북:0, 동:1, 남:2, 서:3
			if (movealbe(cur, dir)) {
				Position p = move_to(cur, dir);
				maze[p.y][p.x] = maze[cur.y][cur.x] - 1;
				enqueue(queue, p);
			}
		}
	}
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
	if ((cur.x < 0 || cur.x >= n) || (cur.y<0 || cur.y>=n)) // 이동할 위치가 미로를 벗어나면 안된다.
		return false;
	if (maze[cur.y][cur.x] == PATH) // 이동할 위치가 PATH라면 이동할 수 있다.
		return true;
	if (maze[cur.y][cur.x] == EXIT) {
		print_maze();
		printf("found the exit\n");
		exit(0);
	}
		
	return false;
}
