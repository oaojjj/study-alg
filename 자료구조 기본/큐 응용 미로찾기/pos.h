#pragma once

#include <stdbool.h>

extern int offset[4][2];

typedef struct pos{
	int x, y;
}Position;

Position move_to(Position pos, int dir);