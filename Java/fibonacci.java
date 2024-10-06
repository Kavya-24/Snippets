import java.util.Scanner;

class FibonacciSeries {
    static void Fibonacci(int N) {
        int num1 = 0, num2 = 1;

        for (int i = 0; i < N; i++) {

            System.out.print(num1 + " ");

            int num3 = num2 + num1;
            num1 = num2;
            num2 = num3;
        }
        System.out.println();
    }

    // Driver Code
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of terms for Fibonacci series: ");
        int N = sc.nextInt();

        Fibonacci(N);

        sc.close();
    }
}
