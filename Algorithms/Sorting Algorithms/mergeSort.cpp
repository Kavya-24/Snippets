#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int lo, int mid, int hi) {
    int temp[hi-lo+1];
    int i = lo, j = mid+1, k = 0;

    while(i <= mid && j <= hi){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }

    while(j <= hi){
        temp[k++] = arr[j++];
    }

    for(int i=lo; i<=hi; i++){
        arr[i] = temp[i-lo];
    }
}

// O(n*logn) time complexity
void merge_sort(int arr[], int lo, int hi) {
    if(lo < hi){
        int mid = (lo + hi) / 2;
        merge_sort(arr, lo, mid);
        merge_sort(arr, mid+1, hi);
        merge(arr, lo, mid, hi);
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

    merge_sort(arr, 0, n-1);

    cout<<"After Merge Sort - ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    // solve();
}