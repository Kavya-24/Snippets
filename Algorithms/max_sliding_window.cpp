// Program for max sliding window
#include <bits/stdc++.h>
using namespace std;
// Comparator to sort the vector of pair with increasing first and decreasing second values
bool comparator(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}
// k-> size of the window
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    // Create a priority queue with comparator
    priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int>, pair<int, int>)>> pq(comparator);

    int n = nums.size();
    vector<int> windowMax;
    // Insert first K elements in priority queue
    for (int i = 0; i < k; i++)
    {
        pq.push({nums[i], i});
    }
    windowMax.push_back(pq.top().first);
    // Now slide over remaining elements
    for (int i = k; i < n; i++)
    {

        pq.push({nums[i], i});
        // Loop until priority queue top element index comes undes the range
        while (pq.top().second <= i - k)
        {
            pq.pop();
        }
        windowMax.push_back(pq.top().first);
    }
    return windowMax;
}

int main()
{
    vector<int> arr = {1, 1, 5, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int k=4;
    vector<int> max_arr =  maxSlidingWindow(arr,k);
    for(auto e : max_arr){
        cout<<e<<" ";
    }
}
