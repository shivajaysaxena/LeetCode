class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 1, 0);
        int mx = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i + 1] = prices[i] + mx;
            dp[i + 1] = max(dp[i + 1], dp[i]);
            mx = max(mx, dp[i - 1] - prices[i]);
        }

        return dp[n];
    }
};