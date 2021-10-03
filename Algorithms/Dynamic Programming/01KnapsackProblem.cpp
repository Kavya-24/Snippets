/* A Naive recursive implementation of 0-1 Knapsack problem */
#include <iostream>
using namespace std;

// A utility function that returns
// maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapsack(int wt[], int profit[], int W, int N) // N is the elements and W is its weight of each elements
{
    // Base Case
    if (N == 0 || W == 0)
        return 0;

    // Decision Tree

    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[N] > W) // Skip Case
        return knapsack(wt, profit, W, N - 1);
    else
        return max(knapsack(wt, profit, W, N - 1), profit[N] + knapsack(wt, profit, W - wt[N], N - 1)); // 1st Part is skip case and 2nd Part is include case
}

int main()
{
    int wt[] = {3, 2, 4};
    int profit[] = {6, 8, 7};
    int W = 8;
    int N = sizeof(profit) / sizeof(profit[0]);
    cout << knapsack(wt, profit, W, N);
    return 0;
}