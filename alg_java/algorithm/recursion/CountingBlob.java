package algorithm.recursion;

import static algorithm.PathSign.*;

/**
 * blob을 카운팅하는 문제
 * blob : 상하좌우 및 대각으로도 연결된 것
 */
public class CountingBlob {
    int[][] grid;
    int n;

    public CountingBlob(int[][] grid) {
        this.grid = grid;
        this.n = grid.length;
    }

    public int countBlob(int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= n) {  // out of grid size
            return 0;
        } else if (grid[x][y] != PATHWAY.ordinal()) {  // not pixel or already count
            return 0;
        } else { // exist pixel
            grid[x][y] = PATH.ordinal();
            Maze.printMaze(grid, n);
            return 1 + countBlob(x - 1, y) + countBlob(x - 1, y + 1) + countBlob(x, y + 1) +
                    countBlob(x + 1, y + 1) + countBlob(x + 1, y) + countBlob(x + 1, y - 1) +
                    countBlob(x, y - 1) + countBlob(x - 1, y - 1);
        }
    }
}
