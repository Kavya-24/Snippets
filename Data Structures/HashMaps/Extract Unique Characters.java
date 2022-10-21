/*
QUESTION
--------------

Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. 
The respective order of characters should remain same, as in the input string.
*/

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static String takeInput() throws IOException {
        String str = br.readLine(); 
        return str;
    }
    
    public static String uniqueChar(String str){
          LinkedHashMap<Character, Boolean> count= new LinkedHashMap<>();

          for (int i= 0; i < str.length(); i++)
              if (!count.containsKey(str.charAt(i)))
                  count.put(str.charAt(i), true);

          Set<Character> c= count.keySet();
          String s= "";

          for (Character n: c)             
              s+= n;        

          return s;
    }
  
    public static void main(String[] args) throws NumberFormatException, IOException {
        String str = takeInput();
        System.out.println(uniqueChar(str));
    }
}
