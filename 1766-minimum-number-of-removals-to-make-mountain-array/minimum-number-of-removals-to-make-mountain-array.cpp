class Solution {
public:
    void f(vector<int>& nums, vector<int>& dp) {
        vector<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            if (temp.size() == 0 || temp.back() < nums[i]) {
                temp.push_back(nums[i]);
                dp.push_back(temp.size());
            } else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) -
                          temp.begin();
                temp[ind] = nums[i];
                dp.push_back(ind + 1);
            }
        }
    }
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> dp1;
        vector<int> dp2;
        f(nums, dp1);
        reverse(nums.begin(), nums.end());
        f(nums, dp2);
        reverse(dp2.begin(), dp2.end());
        int ans = 0;
        for (int i = 0; i < dp1.size(); i++) {
            if (dp1[i] > 1 && dp2[i] > 1) {
                int r = dp1[i] + dp2[i] - 1;
                ans = max(ans, r);
            }
        }
        return nums.size() - ans;
    }
};