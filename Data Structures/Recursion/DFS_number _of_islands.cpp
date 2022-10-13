// IT IS THE PROGRAM TO COUNT THE NUMBER OF ISLANDS 
// WHICH IS BASICALLY THE GROUP OF 1'S IN THE MATRICES
// SURROUNDED BY THE WATER RPRESENTED BY 0'S
//WE HAVE TO COUNT THOSE GROUPS OF ONES


#include<bits/stdc++.h>


using namespace std;

void solve(vector<vector<char>>&grid,int n,int m,int i,int j){
      if((i<n)&&(j<m)&&(i>=0)&&(j>=0)&&(grid[i][j]=='1')){
        grid[i][j] = '0';
        solve(grid,n,m,i+1,j);
        solve(grid,n,m,i-1,j);
        solve(grid,n,m,i,j+1);
        solve(grid,n,m,i,j-1);
      }
    }
  
  
  
  
  
  
  
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
      
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(grid[i][j]=='1'){
          solve(grid,n,m,i,j);
            count++;
          }
         
        }
      }
      
      return count;
    }