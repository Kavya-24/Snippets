package sleepSort;

class SlowSort {
	static void slowSort(int A[], int i, int j) {
		if (i >= j)
			return;
		int m = (i + j) / 2;
		slowSort(A, i, m);
		slowSort(A, m + 1, j);
		if (A[j] < A[m]) {
			int temp = A[j];
			A[j] = A[m];
			A[m] = temp;
		}
		slowSort(A, i, j - 1);
	}

	static void print(int arr[], int size) {
		int i;
		for (i = 0; i < size; i++)
			System.out.print(arr[i] + " ");
		System.out.print("\n");
	}

	public static void main(String[] args) {
		int arr[] = { 7, 9, 4, 3, 18, 1, 51 };
		int N = arr.length;
		slowSort(arr, 0, N - 1);
		print(arr, N);
	}
}

