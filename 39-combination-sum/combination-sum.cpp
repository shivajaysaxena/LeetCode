class Solution {
public:
    void comb(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp,
              int idx, int target) {
        // BC
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        int l = nums.size();
        if (idx == l) {
            return;
        }
        temp.push_back(nums[idx]);
        comb(nums, res, temp, idx, target - nums[idx]);
        temp.pop_back();
        comb(nums, res, temp, idx + 1, target);

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        comb(candidates, res, temp, 0, target);
        return res;
    }
};