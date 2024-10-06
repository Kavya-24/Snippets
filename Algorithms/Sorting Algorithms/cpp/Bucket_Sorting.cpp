
#include <iostream>
#include <algorithm>

using namespace std;

// Function to sort an array using Bucket Sort
void bucketSort(int arr[], int n) {
    if (n <= 0) return;  // No need to sort if the array is empty

    // Find the maximum element to determine the range of buckets
    int max_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value)
            max_value = arr[i];
    }

    // Create n empty buckets (arrays)
    int buckets[n][n]; 
    int bucketSizes[n] = {0}; // To keep track of the number of elements in each bucket

    // Step 2: Put elements into different buckets
    for (int i = 0; i < n; ++i) {
        int bucketIndex = (arr[i] * n) / (max_value + 1);  // bucket index based on element value
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Step 3: Sort individual buckets
    for (int i = 0; i < n; ++i) {
        sort(buckets[i], buckets[i] + bucketSizes[i]);
    }

    // Step 4: Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < bucketSizes[i]; ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
	  cout<<"Enter the number of elements to be stored in array"<<endl; 
  	cin>>n;
  	int ar[n];
  	for(int i=0;i<n;i++)
  	{
	  	cin>>ar[i];
  	}
  	cout<<"Original array: \n"; 
  	printArray(ar, n);  
    bucketSort(ar, n);  
    cout<<"Sorted array: \n";  
    printArray(ar, n);  
    return 0;  
}
