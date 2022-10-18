//Count pairs with given sum

#include <bits/stdc++.h>
using namespace std;


class Solution{   
public:
    int getPairsCount(int a[], int n, int k) {
       unordered_map<int,int> m;
       int sum=0;
       for(int i=0;i<n;i++)
       {
           sum+=m[k-a[i]];
           m[a[i]]++;
       }
       return sum;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}