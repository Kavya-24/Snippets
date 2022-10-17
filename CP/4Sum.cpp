    #include <iostream>
    #include<bits/stdc++.h>
    using namespace std;

    vector<vector<int>> res;

    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n=nums.size();
        if(n==0)
            return res;

        sort(nums.begin(), nums.end());

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long t= (long)target-nums[i]-nums[j];

                int l=j+1, r=n-1;

                while(l<r){
                    long long s = (long)nums[l]+nums[r];
                    if(t==s){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[l]);
                        v.push_back(nums[r]);

                        res.push_back(v);

                        while(l<r && nums[l]==v[2]) l++;
                        while(l<r && nums[r]==v[3]) r--;
                    }

                    else if(t>s)
                        l++;
                    else
                        r--;

                }

                while(j+1<n && nums[j]==nums[j+1])
                    j++;
                while(i+1<n && nums[i]==nums[i+1])
                    i++;

            } 

        }

        return res;

    }

    int main(){

        vector<int>nums = {1,0,-1,0,-2,2};
        int t = 0;

        fourSum(nums, t);

        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[0].size();j++){
                cout << res[i][j] << " ";
            }
            cout << "\n";
        }

    }
