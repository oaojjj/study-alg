package alg.recursion;

public class CountingBlob {
    int[][] grid;
    int n;

    public CountingBlob(int[][] grid, int n) {
        this.grid = grid;
        this.n = n;
    }

    int countBlob(int x, int y) {

        if (x < 0 || y < 0 || x >= n || y >= n) {  // out of grid size
            return 0;
        } else if (grid[x][y] != 0) {  // not pixel or already count
            return 0;
        }
        return 0;
    }
}
