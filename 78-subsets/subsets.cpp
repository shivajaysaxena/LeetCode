class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ans;
        recursion(nums, subset, ans, 0);
        return ans;
    }
    void recursion(const vector<int>& nums, vector<int>& subset,
                   vector<vector<int>>& ans, int i) {
        if (i >= nums.size()) {
            ans.push_back(subset);
            return;
        }
        recursion(nums, subset, ans, i + 1);
        subset.push_back(nums[i]);
        recursion(nums, subset, ans, i + 1);
        subset.pop_back();
        
    }
};