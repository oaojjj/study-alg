package alg.recursion;

import alg.Util.PathSign;

public class Maze {
    int[][] maze;
    int n;

    public Maze(int[][] maze, int n) {
        this.maze = maze;
        this.n = n;
    }

    public boolean findMazePath(int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= n) { // out of map size
            return false;
        } else if (maze[x][y] != PathSign.PATHWAY.ordinal()) { // no path
            return false;
        } else if (x == n - 1 && y == n - 1) { // found exit
            maze[x][y] = PathSign.EXIT.ordinal();
            return true;
        } else {
            maze[x][y] = PathSign.PATH.ordinal();
            if (findMazePath(x, y + 1) || findMazePath(x + 1, y) || findMazePath(x - 1, y) || findMazePath(x, y - 1))
                return true;
            maze[x][y] = PathSign.BLOCKED.ordinal();
            return false;
        }
    }

    public void printMaze() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(maze[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}