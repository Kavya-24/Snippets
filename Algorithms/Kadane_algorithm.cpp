class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int maxi=INT_MIN, prefix=0;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            prefix+=arr[i];
            maxi=max(prefix,maxi);
            if(prefix<0)
            prefix=0;
        }
        return maxi;
    }
};
