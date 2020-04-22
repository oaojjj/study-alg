package week2;

public class Prob4 {
	static int data[];

	static int getNearest(int begin, int end, int target) {
		// base case
		if (end < begin) {
			if (end > 0)
				return data[end];
			else
				return data[end + 1];
		} else {
			int middle = (begin + end) / 2;
			if (data[middle] == target)
				return target;
			// 찾는 값보다 클 때
			else if (data[middle] > target)
				return getNearest(begin, middle - 1, target);
			// 작을 때
			else
				return getNearest(middle + 1, end, target);
		}
	}
}