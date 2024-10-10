//The task is to find all unique subsets of a given set of integers. The set may contain duplicate elements, and any repeated subset should be considered only once. The subsets must be displayed in lexicographical order, meaning that smaller elements should appear before larger ones in each subset.

#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

// Recursive function to find all unique subsets
void findSubsets(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ansList) { 
    // Add current subset (ds) to the answer list
    ansList.push_back(ds); 
    
    // Traverse through the array starting from index 'ind'
    for (int i = ind; i < nums.size(); i++) { 
        // If the current element is the same as the previous one, skip it to avoid duplicates
        if (i != ind && nums[i] == nums[i - 1]) 
            continue; 

        // Include the current element in the subset
        ds.push_back(nums[i]); 

        // Recursive call to generate all subsets starting from the next element
        findSubsets(i + 1, nums, ds, ansList); 

        // Backtrack and remove the last element from the current subset
        ds.pop_back(); 
    } 
} 

// Function to initiate the subset generation
vector<vector<int>> AllSubsets(int arr[], int n) { 
    vector<int> nums(arr, arr + n);  // Convert array to vector
    vector<int> ds;  // Temporary vector to store current subset
    sort(nums.begin(), nums.end());  // Sort the input array to handle duplicates
    vector<vector<int>> ansList;  // List to store all subsets
    findSubsets(0, nums, ds, ansList);  // Start generating subsets
    return ansList; 
} 

// Main function to test the above code
int main() { 
    int set[] = { 10, 12, 12 };  // Input set with duplicates
    vector<vector<int>> subsets = AllSubsets(set, 3);  // Get all unique subsets

    // Print the resulting subsets
    for (auto subset : subsets) { 
        cout << "["; 
        for (int i = 0; i < subset.size(); i++) { 
            cout << subset[i]; 
            if (i < subset.size() - 1) { 
                cout << ", "; 
            } 
        } 
        cout << "], "; 
    } 

    return 0; 
}
