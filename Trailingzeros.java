import java.io.*;
import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
            long n=sc.nextLong();
            long s=0;
            long c=1;
            long count=0;
            while(s<n)
            {
                s=(long)Math.pow(5,c);
                count=count+n/s;
                c++;
            }
            System.out.println("Number of trailing zeros in "+ n +" are " + count);      
    }
}
