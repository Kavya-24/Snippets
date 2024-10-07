/*
Objective : An array consists of n elements. Find the majority element in the array in optimal time and space. 
A majority element is an element that appears more than n/2 times in the array.
Array is non-empty and the majority element always exists in the array.
*/

#include <iostream>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        /*
        This algorithm uses the fact that if you cancel out
        each occurence of majority element with all other elements
        then the majority element will be left in the end.
        */
        int count = 0;          
        int candidate = 0;      
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if(num == candidate) {
                count++;
            } 
            else {
                count--;
            }
        }
        return candidate;
    }
};

/*
//Example Use Case
int main() {
    Solution s;
    std::vector<int> nums = {2, 1, 1, 2, 2, 3, 2, 4, 2, 2, -1};
    std::cout << s.majorityElement(nums) << std::endl;
    return 0;
}
*/