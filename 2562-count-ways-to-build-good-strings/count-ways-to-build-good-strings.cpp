class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<int, int> dp;

    int solve(int low, int high, int zero, int one, int len) {
        if (high < len)
            return 0;

        if (dp.count(len) != 0)
            return dp[len];

        int add0s = solve(low, high, zero, one, len + zero) % mod;
        int add1s = solve(low, high, zero, one, len + one) % mod;
        int valid = (int)(low <= len && len <= high);

        return dp[len] = (valid + add0s + add1s) % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {

        return solve(low, high, zero, one, 0);
    }
};