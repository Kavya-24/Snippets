import java.util.Arrays;
import java.util.Scanner;

public class multidimesionArr {
    public static void main(String[] args) {
        /*
         1 2 3
         4 5 6
         7 8 9
         */
        Scanner sc = new Scanner(System.in);
        // int[][] arr = new int[3][];

        // int[][] arr2D = {
        //     {1, 2, 3}, // 0th index
        //     {4, 5}, // 1st index
        //     {6, 7, 8, 9} // 2nd index
        // };
        System.out.print("Enter no. of rows: ");
        int a = sc.nextInt();
        System.out.print("Enter no. of coloum: ");
        int b = sc.nextInt();

        int[][] arr = new int[a][b];
        System.out.println("Total no. of rows and coloum is : " + a*b);
        System.out.println("Now enter the input value: ");

        // input
        for (int row = 0; row < arr.length; row++) {
            // for each coloum in every row
            for(int col = 0; col < arr[row].length; col++) {
                arr[row][col] = sc.nextInt();
            }
        }


        // output
        // for (int row = 0; row < arr.length; row++) {
        //     // for each coloum in every row
        //     for(int col = 0; col < arr[row].length; col++) {
        //         System.out.print(arr[row][col] + " ");
        //     }
        //     System.out.println();
        // }


        // output
        for (int row = 0; row < arr.length; row++) {
            System.out.println(Arrays.toString(arr[row]));
        }

        sc.close();

    }
    
}
