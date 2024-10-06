package java;

public class BinarySearch {git

    //  Pass in the array, the value to search for,
    //  the index of the start of the array, and the index of the end of the array
    //  The passing of index values will allow the same array to be utilised throughout each
    //  recursion, "filtering" out values that have been checked against by only looking between the indices
    public static int binarySearch(int[] arr, int searchFor, int startIndex, int endIndex) {
        //  Binary search: (Assumes array is sorted) Splits the array in half using the midpoint,
        //  halving the data to look at each time by ignoring values that are less than or larger than
        //  the value being searched for.
        //  Time Complexity: Best - O(1) Average - O(log(n)) Worst - O(log(n))

        //  Check that there is more than one value in the array (low != high)
        if (endIndex >= startIndex) {
            int mid = startIndex + (endIndex - startIndex) / 2;

            // Check if searchFor is in the middle, if it is then return the index
            if (arr[mid] == searchFor) {
                return mid;
            }

            //  Check if the value is less than that at the mid, if it is, only look at the values to the left
            //  If not, the value is either to the right or not present so look at the right half instead
            if (arr[mid] > searchFor) {
                return binarySearch(arr, searchFor, startIndex, mid - 1);
            } else {
                return binarySearch(arr, searchFor, mid + 1, endIndex);
            }
        }

        //  If the value is not found, return -1
        return -1;
    }
}