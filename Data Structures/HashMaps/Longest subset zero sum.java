/*
QUESTION
---------------

Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.

*/

import java.util.*;
import java.io.*;

public class Main {     

	   public static int lengthOfLongestSubsetWithZeroSum(int arr[]) {
        HashMap<Integer, Integer> map= new LinkedHashMap<>();
        int i, maxlen= 0, sum= 0;
        
        for (i= 0; i < arr.length; i++)
        {
            sum+= arr[i];
            if (sum == 0)
                maxlen= i+1;
            if (map.containsKey(sum))
            {
                if (i-map.get(sum) > maxlen)
                    maxlen= i-map.get(sum);
            }
            else 
           		map.put(sum, i);
        }
        return maxlen;
	  }
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));;
	  static StringTokenizer st;

    public static void main(String[] args) throws NumberFormatException, IOException {
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int arr[] = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) 
          arr[i] = Integer.parseInt(st.nextToken());
        
        System.out.println(lengthOfLongestSubsetWithZeroSum(arr));
    }  
}
