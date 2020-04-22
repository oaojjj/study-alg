package week3;

import java.util.Scanner;

public class Prob1 {
	public static final int PATHWAY_COLOUR = 0; // 방문 가능
	public static final int VISIT_COLOUR = 2; // 방문
	static int N, K;
	static int[][] maze;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		maze = new int[N][N];
		readMaze(sc);
		K = sc.nextInt();

		System.out.println(findPath(0, 0, 0));
		sc.close();
	}

	public static void readMaze(Scanner sc) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				maze[i][j] = sc.nextInt();
			}
		}
	}

	public static int findPath(int x, int y, int len) {
		int count = 0;
		if (x < 0 || y < 0 || x >= N || y >= N)
			return 0;
		else if (maze[x][y] != PATHWAY_COLOUR)
			return 0;
		else if (x == N - 1 && y == N - 1) {
			if (len <= K)
				return ++count;
			else
				return 0;
		} else {
			maze[x][y] = VISIT_COLOUR;
			count += findPath(x, y + 1, len + 1) + findPath(x + 1, y, len + 1) + findPath(x, y - 1, len + 1)
					+ findPath(x - 1, y, len + 1);
			maze[x][y] = 0;
		}
		return count;
	}
}