/* 

Question - Return Keypad Code

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.

Note : 1. The order of strings are not important.
       2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.

Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

Main Code: 

import java.util.Scanner;

public class runner {
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int input = s.nextInt();
		String output[] = solution.keypad(input);
		for(int i = 0; i < output.length; i++) {
			System.out.println(output[i]);
		}
	}
}

*/

// Solution: 

import java.util.*;
public class solution {

	// Return a string array that contains all the possible strings
    static String[] arr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    static ArrayList<String> res;
    
	public static String[] keypad(int n){
		// Write your code here
        res = new ArrayList<>();
        String s = String.valueOf(n);
        backtrack(0, s.length(), new StringBuilder(), s);
        
        String[] ans = new String[res.size()];
        for(int i = 0; i < res.size(); i++){
            ans[i] = res.get(i);
        }
        
        return ans;
	}
	public static void backtrack(int idx, int n, StringBuilder sb, String s){
        if(idx == n){
            res.add(sb.toString());
            return;
        }
        
        for(char c : arr[s.charAt(idx) - '0'].toCharArray()){
            //add a character
            sb.append(c);
            //recurse
            backtrack(idx+1, n, sb, s); 
            //remove last character
            sb.setLength(sb.length() - 1); 
        }
    }
}
