#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// O(n*logn) time complexity
void quick_sort(int arr[], int lo, int hi) {
    if (lo < hi) {
        int pi = partition(arr, lo, hi);
        quick_sort(arr, lo, pi - 1);
        quick_sort(arr, pi + 1, hi);
    }
}

int main() {
    cout << "Enter the size of the array" << endl;
    int n;
    cin >> n;

    cout << "Enter the elements in the array" << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Before Sorting - ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    quick_sort(arr, 0, n - 1);

    cout << "After Quick Sort - ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    // solve();
}