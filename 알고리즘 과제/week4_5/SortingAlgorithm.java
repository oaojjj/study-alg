package week4_5;

public abstract class SortingAlgorithm {
	SortingAlgorithm sa;
	int mLength;
	int[] mTemp;

	public SortingAlgorithm() {
		sa = this;
	}

	public SortingAlgorithm(int n) {
		this();
		mTemp = new int[n];
	}

	public abstract void sort(int[] a);

	// swap
	protected void swap(int[] arr, int i, int j) {
		int temp = arr[j];
		arr[j] = arr[i];
		arr[i] = temp;
	}

	// get sort time
	double getSortTime(int[] data) {
		long startTime, endTime;

		startTime = System.currentTimeMillis();
		sa.sort(data);
		endTime = System.currentTimeMillis();

		return (endTime - startTime) / 1000.0;

	}

	public void setSize(int size) {
		mTemp = new int[size];
	}

}
