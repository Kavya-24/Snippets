#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i; 
    int left_idx = 2 * i + 1; 
    int right_idx = 2 * i + 2; 

    if (left_idx < n && arr[left_idx] > arr[largest])
        largest = left_idx;
 
    if (right_idx < n && arr[right_idx] > arr[largest])
        largest = right_idx;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// O(n*logn) time complexity
void heap_sort(int arr[], int n) {
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }

    for(int i=n-1; i>0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main() {
    cout << "Enter the size of the array" << endl;
    int n; cin>>n; 

    cout << "Enter the elements in the array" << endl;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<"Before Sorting - ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;

    heap_sort(arr, n);

    cout<<"After Heap Sort - ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    // solve();
}