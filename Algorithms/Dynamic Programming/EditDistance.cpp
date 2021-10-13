/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

* Insert a character
* Delete a character
* Replace a character

*/
#include <bits/stdc++.h>

using namespace std;

int minEditDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[m][n];
    }

  int main(){

    string word1, word2;

    cout<<"Enter word1\n";
    cin>>word1;

    cout<<"Enter word2\n";
    cin>>word2;

    cout<<"minEditDistance = "<<minEditDistance(word1, word2);

    return 0;
  }
