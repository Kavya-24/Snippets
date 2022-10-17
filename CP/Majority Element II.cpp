
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> res;
void majorityElement(vector<int>& nums) {
        int n1=-1, n2=-1, n=nums.size();
        int c1=0, c2=0;

        for(auto ele:nums){
            if(n1==ele)
                c1++;
            else if(n2==ele)
                c2++;
            else if(c1==0){
                n1=ele;
                c1=1;
            }
            else if(c2==0){
                n2=ele;
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
  
        for(int i=0;i<n;i++){
            if(nums[i]==n1) c1++;
            else if(nums[i]==n2) c2++;
        }
  
        if(c1>n/3)
            res.push_back(n1);
        if(c2>n/3)
            res.push_back(n2);
    }

int main(){
    int n;
    cin >> n;
    vector<int> nums(n, 0);

    for(int i=0;i<n;i++)
        cin >> nums[i];

    majorityElement(nums);

    for(int i=0;i<res.size();i++)
        cout << res[i] << " ";
}
