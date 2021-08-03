package alg.recursion;

import static alg.PathSign.*;

/*
CountingBlob countingBlob = new CountingBlob(new int[][]{
                {0, 0, 1, 1, 1},
                {0, 0, 0, 1, 0},
                {1, 1, 0, 0, 1},
                {0, 1, 1, 0, 0},
                {0, 0, 1, 0, 1},
        }, 5);

        int result = countingBlob.countBlob(0, 2);
        System.out.println(result);
 */
public class CountingBlob {
    int[][] grid;
    int n;

    public CountingBlob(int[][] grid, int n) {
        this.grid = grid;
        this.n = n;
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
