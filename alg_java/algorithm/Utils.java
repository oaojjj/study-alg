package algorithm;

public class Utils {
    public static void swap(int[] data, int n1, int n2) {
        int tmp = data[n1];
        data[n1] = data[n2];
        data[n2] = tmp;
    }
}
