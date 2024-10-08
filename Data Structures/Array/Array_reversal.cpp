
// Here are several ways to reverse an array in C++


// 1. ------------Two-Pointer Approach

void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        swap(arr[start], arr[end]); // Swap elements
        start++;
        end--;
    }
}
// Time Complexity: O(n)
// Space Complexity: O(1) (in-place)


// 2. --------------Using a Temporary Array
// create a new array and copying the elements in reverse order

void reverseArray(int arr[], int n) {
    int temp[n];

    for (int i = 0; i < n; i++) {
        temp[i] = arr[n - i - 1]; // Copy elements in reverse
    }

    // Copy the reversed array back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}
// Time Complexity: O(n)
// Space Complexity: O(n) (extra array used)


// 3. ---------------------Using Recursion
// Recursively swap the first and last elements until you reach the middle.

void reverseArrayRecursively(int arr[], int start, int end) {
    if (start >= end) return;  // Base case pointers have crossed

    swap(arr[start], arr[end]); // Swap elements
    reverseArrayRecursively(arr, start + 1, end - 1); // Recur for the next pair
}
// Time Complexity: O(n)
// Space Complexity: O(n) (due to recursion stack)


// 4. -----------------Using C++ STL (reverse function)
// You can use the built-in reverse function from the C++ Standard Template Library (STL).

#include <algorithm>

void reverseArray(int arr[], int n) {
    reverse(arr, arr + n);  // STL reverse function
}
// Time Complexity: O(n)
// Space Complexity: O(1) (in-place)



// 5. -----------------------Using Stack
// Push all the elements into a stack then pop them back to get the array reversed

#include <stack>

void reverseArray(int arr[], int n) {
    stack<int> s;

    // Push all elements to the stack
    for (int i = 0; i < n; i++) {
        s.push(arr[i]);
    }

    // Pop them back to the array in reverse order
    for (int i = 0; i < n; i++) {
        arr[i] = s.top();
        s.pop();
    }
}
// Time Complexity: O(n)
// Space Complexity: O(n) (extra stack used)


// 6. -----------------Using XOR Swap (Without Temp Variable)
// This is elements are swapped without using a temporary variable by using XOR

void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        arr[start] ^= arr[end]; // XOR swap
        arr[end] ^= arr[start];
        arr[start] ^= arr[end];
        start++;
        end--;
    }
}
// Time Complexity: O(n)
// Space Complexity: O(1)