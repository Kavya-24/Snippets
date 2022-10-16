import java.util.Scanner;
public class n_queens {
    static int[] x;
    public static boolean feasible(int k,int j){
        for (int i = 0; i <k ; i++) {
            if(x[i]==j || Math.abs(j-x[i])==Math.abs(k-i)){
                return false;
            }
        }
        return true;
    }
    public static void queens(int k, int n){
        for (x[k] = 0; x[k] <=n ; x[k]++) {
            if(feasible(k,x[k])==true){
                if(k==n){
                    for (int i = 0; i <x.length ; i++) {
                        System.out.print(x[i]+" ");
                    }
                    System.out.println();
                }
                else {
                    queens(k+1,n);
                }
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.println("enter the no. of Queens ");
        int n=sc.nextInt();
        x= new int[n];
        queens(0,n-1);
    }
}


/*
OUTPUT :

Enter the no. of Queens 
4
These are the ways in which we can put queen so that they can't attack on each other
1 3 0 2 
2 0 3 1 

*/
