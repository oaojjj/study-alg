#include "pos.h"

offset[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

// За -> y ї­ -> x
Position move_to(Position pos, int dir) {
	Position next;
	next.x = pos.x + offset[dir][1];
	next.y = pos.y + offset[dir][0];
	return next;
}
