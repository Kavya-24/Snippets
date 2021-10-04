#include<bits/stdc++.h>
#include <iostream>

using namespace std;

// A peak element in an array is the one that is not smaller than its neighbours.
// Given an array arr[] of size N, find the index of any one of its peak elements.

int findPeakUtil(int arr[], int low, int high, int n)
{
    int mid = low + (high - low) / 2;
 
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        return mid;

    else if (mid > 0 && arr[mid - 1] > arr[mid])
        return findPeakUtil(arr, low, (mid - 1), n);
 
    else
        return findPeakUtil(arr, (mid + 1), high, n);
}


int peakElement(int arr[], int n)
{
    return findPeakUtil(arr, 0, n - 1, n);
      
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    
    cout<<peakElement(arr,n);

    return 0;
}
