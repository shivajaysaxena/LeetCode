class Solution {
public:
    unordered_map<int, bool> m;
    void generate(vector<vector<int>>& ans, vector<int> temp,
                  vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]])
                continue;
            m[nums[i]] = 1;
            temp.push_back(nums[i]);
            if (temp.size() == nums.size())
                ans.push_back(temp);
            else
                generate(ans, temp, nums);
            temp.pop_back();
            m[nums[i]] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        generate(ans, temp, nums);
        return ans;
    }
};