package week3;

import java.util.Scanner;

public class Prob2 {
	private static final int PATHWAY_COLOUR = 0; // 갈수 있는 셀
	private static final int VISIT_COLOUR = 2; // 방문
	private static final int EXIT = -1; // 끝
	private static final int EAST = 0;
	private static final int SOUTH = 1;
	private static final int WEST = 2;
	private static final int NORTH = 3;
	static int maze[][];
	static int N;
	// static int dir = 0;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		maze = new int[N][N];
		readMaze(sc, N);

		findPath(0, 0, 0);
		if (maze[N - 1][N - 1] != 0)
			System.out.println("Yes");
		else
			System.out.println("No");
		sc.close();
	}

	// #dir 동:0, 남:1, 서:2, 북:3
	public static boolean findPath(int x, int y, int direction) {
		boolean flag = false;
		if (x < 0 || y < 0 || x >= N || y >= N) {
			return true;
		} else if (maze[x][y] != PATHWAY_COLOUR) {
			return true;
		} else if (x == N - 1 && y == N - 1) {
			maze[x][y] = EXIT;
		} else {
			maze[x][y] = VISIT_COLOUR;
			printMaze();
			if (direction == EAST || direction == WEST) {
				if (direction == EAST)
					flag = findPath(x, y + 1, EAST);
				else
					flag = findPath(x, y - 1, WEST);

				if (flag) {
					findPath(x + 1, y, SOUTH);
					findPath(x - 1, y, NORTH);
				}
			} else if (direction == SOUTH || direction == NORTH) {
				if (direction == SOUTH)
					flag = findPath(x + 1, y, SOUTH);
				else
					flag = findPath(x - 1, y, NORTH);

				if (flag) {
					findPath(x, y + 1, EAST);
					findPath(x, y - 1, WEST);
				}
			}
		}
		return false;
	}

	// 0:갈수 있는 셀, 1:벽, 2:방문
	public static void readMaze(Scanner in, int n) { // 미로 입력받기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				maze[i][j] = in.nextInt();
			}
		}
	}

	public static void printMaze() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				System.out.print(maze[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println();
	}

}
