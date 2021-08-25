package algorithm.recursion;

/**
 * N-Queens 문제
 */
public class NQueens {
    int[] cols;
    int n;

    public NQueens(int n) {
        this.n = n;
        cols = new int[n];
    }

    public boolean solve(int depth) {
        if (depth == n) { // 1. 현재 자리에 놓을 수 있고 depth == n이라면 다 놓았다는 뜻
            for (int i = 0; i < n; i++) {
                System.out.println(cols[i] + 1 + "번 자리");
            }
            return true;
        } else {  // 2. depth == n은 아니고 놓을 자리를 찾음
            for (int i = 0; i < n; i++) {
                cols[depth] = i;
                if (checkCondition(depth)) // 3. 조건은 성립하는가?
                    if (solve(depth + 1)) {
                        return true;
                    }
            }
            return false;
        }
    }

    private boolean checkCondition(int d) {
        for (int i = 0; i < d; i++) {
            if (cols[d] == cols[i]) // 1. 같은 열 체크
                return false;
            else if (d - i == Math.abs(cols[d] - cols[i])) // 2. 대각선 체크
                return false;
        }
        return true;
    }

    public int getN() {
        return n;
    }
}



/*
// 권오흠 교수님 풀이
package alg.recursion;

public class NQueens {
    int[] cols;
    int n;

    public NQueens(int n) {
        this.n = n;
        cols = new int[n + 1];
    }

    public boolean solve(int depth) {
        if (!checkCondition(depth)) {  // 1. 현재 자리에 놓을 수 있는가?
            return false;
        } else if (depth == n) { // 2. 현재 자리에 놓을 수 있고 depth == n이라면 다 놓았다는 뜻
            for (int i = 1; i <= n; i++) {
                System.out.println(cols[i] + "번 자리");
            }
            return true;
        } else {  // 3. depth == n은 아니고 놓을 자리를 찾음
            for (int i = 1; i <= n; i++) {
                cols[depth + 1] = i;
                if (solve(depth + 1)) {
                    return true;
                }
            }
            return false;
        }
    }

    private boolean checkCondition(int d) {
        for (int i = 1; i < d; i++) {
            if (cols[d] == cols[i]) // 1. 같은 열 체크
                return false;
            else if (d - i == Math.abs(cols[d] - cols[i])) // 2. 대각선 체크
                return false;
        }
        return true;
    }

    public int getN() {
        return n;
    }
}
 */
