class Solution {
public:
    int memo(int indx, vector<int>& v, vector<int>& dp) {
        if (indx < 0)
            return 0;
        if (indx == 0)
            return v[indx];

        if (dp[indx] != -1)
            return dp[indx];
        int pick = v[indx] + memo(indx - 2, v, dp);
        int notPick = 0 + memo(indx - 1, v, dp);

        return dp[indx] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> v1, v2;
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                v1.push_back(nums[i]);
            }
            if (i != n - 1) {
                v2.push_back(nums[i]);
            }
        }
        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n - 1, -1);
        return max(memo(n - 2, v1, dp1), memo(n - 2, v2, dp2));
    }
};