import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Enter the size of array :");
        int size = scanner.nextInt();
        int[] array = new int[size];
        System.out.println("Enter " + size +" elements:");
        for (int j = 0; j < size; j++){
           array[j] = scanner.nextInt();
        }
        System.out.println("Enter the element to find in the array:");
        int number = scanner.nextInt();

        for(int i = 0; i<array.length; i++){
            if(array[i] == number){
                System.out.println("Element " + number + " found at position " + i);
            }

        }


    }


}