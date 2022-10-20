package com.company;

import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner sc = new Scanner(System.in);
        int My_Number = (int)(Math.random()*100);
        int Your_Number;
        do{
            System.out.println("Guess the Number : ");
            Your_Number = sc.nextInt();
            if(Your_Number==My_Number)
            {
                System.out.println("Hurrah... You Won");
                break;
            }
            else if(Your_Number>My_Number)
            {
                System.out.println("Your Number is larger");
            }
            else
            {
                System.out.println("Your Number is smaller");
            }
        }while(Your_Number>=0);

        System.out.println("My Number is : "+My_Number);
    }
}
