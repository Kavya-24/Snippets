package bogoSort;

public class BogoSort {
	void bogoSort(int[] a) {
		while (isSorted(a) == false)
			shuffle(a);
	}

	void shuffle(int[] a) {
		for (int i = 0; i < a.length; i++)
			swap(a, i, (int) (Math.random() * i));
	}

	boolean isSorted(int[] a) {
		for (int i = 1; i < a.length; i++)
			if (a[i] < a[i - 1])
				return false;
		return true;
	}

	void swap(int[] a, int i, int j) {
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	public static void main(String[] args) {
		int[] a = { 6, 22, 1, 7, 3, 2 };
		BogoSort ob = new BogoSort();
		ob.bogoSort(a);
		for (int i = 0; i < a.length; i++)
			System.out.print(a[i] + " ");
		System.out.println();
	}
}