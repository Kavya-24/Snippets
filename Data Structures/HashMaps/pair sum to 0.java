/*

QUESTION
-------------------------

Given a random integer array 'arr' of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array 'arr' can contain duplicate elements as well.

*/

import java.util.*;
import java.io.*;

public class Main {

	  public static int PairSum(int[] arr, int size) {
        HashMap<Integer, Integer> count= new HashMap<>();
        ArrayList<Integer> a= new ArrayList<>();
        
        int i, cnt= 0;
        
        for (i= 0; i < size; i++){
            if (count.containsKey(arr[i]))
                count.put(arr[i], count.get(arr[i]) + 1);
            else{
            	count.put(arr[i], 1);
                a.add(arr[i]);
            }
        }
        
        for (i= 0; i < a.size(); i++)
        {               
            if (a.get(i) == 0)
                cnt+= count.get(a.get(i))*(count.get(a.get(i))-1)/2;
            else if (count.containsKey(-a.get(i)) && count.get(a.get(i)) > 0 && count.get(-a.get(i)) > 0){
                cnt+= count.get(a.get(i)) * count.get(-a.get(i));
                count.put(a.get(i), 0);
                count.put(-a.get(i), 0);
            }
        }
        
        return cnt;
	  }
  
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static int[] takeInput() throws IOException {
        int size = Integer.parseInt(br.readLine().trim());
        int[] input = new int[size];

        if (size == 0) 
            return input;        
        
		    String[] strNums;
		    strNums = br.readLine().split("\\s");
		
        for (int i = 0; i < size; ++i) 
            input[i] = Integer.parseInt(strNums[i]);
        
        return input;
    }

    public static void printArray(int[] arr) {
        for (int element : arr) 
            System.out.print(element + " ");

        System.out.println();
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        int[] arr = takeInput();
        System.out.println("Count= " + PairSum(arr,arr.length));
    }    
}
