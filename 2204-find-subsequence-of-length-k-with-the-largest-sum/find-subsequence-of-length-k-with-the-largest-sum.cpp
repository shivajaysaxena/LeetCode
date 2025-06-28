class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end(),
             [](auto& a, auto& b) { return a.first > b.first; });
        sort(arr.begin(), arr.begin() + k,
             [](auto& a, auto& b) { return a.second < b.second; });
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i].first);
        }
        return res;
    }
};