class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> store;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            store[nums[i]]++;
        }
        for (auto& pair : store) {
            if (pair.second > n / 3) {
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};