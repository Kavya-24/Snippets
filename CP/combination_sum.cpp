#include <bits/stdc++.h>

using namespace std;
//Leetcode problem 39
void combinationSum(vector<int> &arr,vector<vector<int>> &comb,  vector<int> seq, int sum, int currsum, int i)
{
    if(sum==currsum){
        comb.push_back(seq);
        return;
    }
    if(currsum>sum || i>=arr.size())
        return;
    // skip current index
    combinationSum(arr, comb, seq, sum, currsum, i + 1);  
    seq.push_back(arr[i]);
    // take current element and don't skip
    combinationSum(arr, comb, seq, sum, currsum + arr[i], i); 
}

int main()
{
    vector<int> arr = {3, 1, 1, 2};
    vector<int> temp = {};
    vector<vector<int>> combinations;
    int targetsum=8;
    combinationSum(arr,combinations, temp,targetsum,0,0);
    for(int i=0;i<combinations.size();i++){
        for(int j=0;j<combinations[i].size();j++){
            cout<<combinations[i][j]<<" ";

        }
        cout<<endl;
    }
}
