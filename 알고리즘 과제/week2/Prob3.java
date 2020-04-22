package week2;

public class Prob3 {
	static int data[];
	static int N=0,K=0;
	
	// ver1
	static int getCountSum(int i, int j, int k) {
		int count = 0;
		
		if (i >= N - 2) {
			return 0;
		} else {
			if (j >= N - 1) {
				return getCountSum(i + 1, i + 2, i + 3);
			} else {
				if (k >= N) {
					return getCountSum(i, j + 1, j + 2);
				} else {
					if (data[i] + data[j] + data[k] == K)
						count++;
					return count + getCountSum(i, j, k + 1);
				}
			}

		}
	}
	
	static int getCountSumVer2(int i, int j, int k) {
		int count = 0;

		if (i + 2 < N) {
			if (j + 1 < N) {
				if (k < N) {
					count += getCountSum(i, j, k + 1);
					if (data[i] + data[j] + data[k] == K)
						return ++count;
					else
						return count;
				} else
					return getCountSum(i, j + 1, j + 2);
			} else
				return getCountSum(i + 1, i + 2, i + 3);
		}
		return count;
	}
}
