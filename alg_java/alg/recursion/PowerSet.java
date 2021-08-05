package alg.recursion;

import java.util.Arrays;

/**
 * 멱집합 출력 문제
 */
public class PowerSet {
    Character[] array;
    boolean[] include;

    public PowerSet(Character[] array) {
        this.array = array;
        include = new boolean[array.length];
        Arrays.fill(include, false);
    }

    public void solve(int depth) {
        if (depth == array.length) {  // 1. 리프노드인가?
            // 포함하는 문자 출력
            System.out.print("{ ");
            for (int i = 0; i < array.length; i++)
                if (include[i])
                    System.out.print(array[i] + " ");
            System.out.println("}");
            return;
        }
        include[depth] = true;  // 2. 이 문자를 포함하는가?
        solve(depth + 1);

        include[depth] = false; // 3. 이 문자를 포함하지 않는가?
        solve(depth + 1);
    }

}
