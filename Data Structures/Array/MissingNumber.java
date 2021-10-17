/* Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element. */

class Solution {
    int MissingNumber(int array[], int n) {
        int Sum = (n*(n+1))/2;
        int i,sumObtain=0;
        for(i=0;i<n-1;i++)
        {
            sumObtain += array[i];
        }
        return Sum-sumObtain;
    }
}
