package week2;

import java.util.Scanner;

public class Main {
	private static final int PATHWAY_COLOUR = 0; // 갈수 있는 셀
	private static final int VISIT_COLOUR = 2; // 방문
	static int maze[][];
	static int N;
	static int dir = 0;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		maze = new int[N][N];
		readMaze(sc, N);

		findPath(0, 0);
		if (maze[N - 1][N - 1] == 3)
			System.out.println("Yes");
		else
			System.out.println("No");
		sc.close();
	}

	// #dir 동:0, 남:1, 서:2, 북:3
	public static boolean findPath(int x, int y) {
		if (x < 0 || y < 0 || x >= N || y >= N) {
			return true;
		} else if (maze[x][y] != PATHWAY_COLOUR) {
			return true;
		}
		// 출구
		else if (x == N - 1 && y == N - 1) {
			maze[x][y] = 3;
			return false;
		} else {
			maze[x][y] = VISIT_COLOUR;
			printMaze();
			if (dir == 0) { // 동
				if (findPath(x, y + 1))
					dir = 1;
				if (findPath(x + 1, y))
					dir = 3;
				else if (findPath(x - 1, y)) {
				}
			}
			if (dir == 1) { // 남
				if (findPath(x + 1, y))
					dir = 0;
				if (findPath(x, y + 1))
					dir = 2;
				else if (findPath(x, y - 1)) {
				}
			}
			if (dir == 2) { // 서
				if (findPath(x, y - 1))
					dir = 1;
				if (findPath(x + 1, y))
					dir = 3;
				else if (findPath(x - 1, y)) {
				}
			}
			if (dir == 3) { // 북
				if (findPath(x - 1, y))
					dir = 0;
				if (findPath(x, y + 1))
					dir = 2;
				else if (findPath(x, y - 1)) {
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
