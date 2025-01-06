class Solution {
    void func(int ind, vector<int>& arr, vector<int>& nums,
              vector<vector<int>>& ans) {
        // Base case: if index reaches the end of nums
        if (ind == nums.size()) {
            // Add the current subset (arr) to the result
            ans.push_back(arr);
            return;
        }

        // Include the current element in the subset
        arr.push_back(nums[ind]);
        // Recur for the next index
        func(ind + 1, arr, nums, ans);
        // Backtrack: remove the current element from the subset
        arr.pop_back();

        // Skip duplicates and recur for the next unique element
        for (int j = ind + 1; j < nums.size(); j++) {
            if (nums[j] != nums[ind]) {
                func(j, arr, nums, ans);
                return;
            }
        }

        // Ensure the function finishes when no more unique elements are left
        func(nums.size(), arr, nums, ans);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;        // Resulting list of subsets
        vector<int> arr;                // Current subset
        sort(nums.begin(), nums.end()); // Sort the array to handle duplicates
        func(0, arr, nums, ans);        // Start recursion
        return ans;
    }
};