/*

Matrix Search
Given a two-dimensional integer matrix, where every row and column is sorted in ascending order,
find the kth (0-indexed) smallest number.

*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& matrix, int k) {
    set<vector<int>> s;
    int m = matrix[0].size();
    int n = matrix.size();
    int ii = 0;

    //Put all the elements of the first row into the set.
    for (auto& elem : matrix[0]) {
        s.insert({elem, 0, ii});
        ii++;
    }

    k++;
    int ans = INT_MAX;

    //Run a loop k times. Pop the top element (minimum),
    //and insert the next element from the same column into the set.
    while (k--) {
        auto tp = *(s.begin());
        s.erase(s.begin());
        //Every time update answer as the top of the set.
        ans = (tp[0]);
        if (tp[1] + 1 < n) s.insert({matrix[tp[1] + 1][tp[2]], tp[1] + 1, tp[2]});
    }

    return ans;
}

/*
Time : O(klog(n))
Space : O(m)

Where:
n = number of rows
m = number of columns
*/

int main(){
  int n,m;
  cout<<"Enter value of n and m: ";
  cin>>n>>m;

  vector <vector <int>> matrix(n,vector <int>(m));
  cout<<"Enter elements of the matrix:\n";
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>matrix[i][j];
    }
  }

  int k;
  cout<<"Enter value of k: ";
  cin>>k;

  cout<<"kth smallest element = "<<solve(matrix,k);
}
