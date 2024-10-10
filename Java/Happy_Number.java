/*
https://leetcode.com/problems/happy-number/

 Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.
 */

class Happy_Number {
        public boolean isHappy(int n) {
           if(n == 1 || n ==7){
               return true;
           }
           String num = Integer.toString(n);
           while (num.length() >= 2) {
               int total = 0;
               for (int i = 0; i < num.length(); i++) {
                   char digit_Char = num.charAt(i);
   
                   int digit = Character.getNumericValue(digit_Char);
   
                   total =total+ (digit * digit);
               }
               if (total == 1 || total == 7) {
                   return true;
               } else {
                   String totalstr = Integer.toString(total);
                   num = totalstr;
               }
           }
           return false;
           
       }
   }

/*
 Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:

Input: n = 2
Output: false
 */