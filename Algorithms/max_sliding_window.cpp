#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> windowMax;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        // Remove elements not within the sliding window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove elements smaller than the current element from the back of the deque
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Add the current element index to the deque
        dq.push_back(i);

        // The front of the deque is the largest element in the current window
        if (i >= k - 1) {
            windowMax.push_back(nums[dq.front()]);
        }
    }

    return windowMax;
}

int main() {
    vector<int> arr = {1, 1, 5, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int k = 4;
    vector<int> max_arr = maxSlidingWindow(arr, k);
    for (auto e : max_arr) {
        cout << e << " ";
    }
}
