package algorithm.recursion;

import static algorithm.PathSign.*;

/**
 * 미로 문제
 */
public class Maze {
    int[][] maze;
    int n;

    public Maze(int[][] maze) {
        this.maze = maze;
        this.n = maze.length;
    }

    public boolean findMazePath(int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= n) { // out of map size
            return false;
        } else if (maze[x][y] != PATHWAY.ordinal()) { // no path
            return false;
        } else if (x == n - 1 && y == n - 1) { // found exit
            maze[x][y] = EXIT.ordinal();
            System.out.println("found exit");
            return true;
        } else {
            maze[x][y] = PATH.ordinal();
            if (findMazePath(x, y + 1) || findMazePath(x + 1, y) || findMazePath(x - 1, y) || findMazePath(x, y - 1))
                return true;
            maze[x][y] = BLOCKED.ordinal();
            return false;
        }
    }

    public static void printMaze(int[][] maze, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(maze[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}