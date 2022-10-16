
// Given an n x n 2D matrix, 
// rotate the matrix by 90 degrees(clockwise).

#include<bits/stdc++.h> 
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            // T-> Top, B->Bottom, L->Left , R->Right
            int temp = matrix[i][j];                             // Store current(TL) element in temp
            matrix[i][j] = matrix[n - j - 1][i];                 // Replace T-L element with B-L element
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1]; // Replace B-L element with B-R element
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1]; // Replace B->R element with T-R element
            matrix[j][n - i - 1] = temp;                         // Replace T-R element with temp
        }
    }
}

void showMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    vector<vector<int>> matrix = {{11, 13, 15, 17}, {10, 11, 16, 20}, {23, 30, 34, 60}, {23, 30, 34, 60}};
    cout<<"Before Rotation : "<<endl;
    showMatrix(matrix);
    rotate(matrix);
    cout << "After Rotation : " << endl;
    showMatrix(matrix);
}
