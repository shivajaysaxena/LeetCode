class Solution {
public:
    int dp[2000][2000];
    bool f(int ind, int k, unordered_map<int, int>& mp, int target,
           vector<int>& stones) {

        if (ind == target)
            return true;
        if (dp[ind][k] != -1)
            return dp[ind][k];

        bool res = false;
        if (k > 1 && mp[stones[ind] + k - 1]) {
            res |= f(mp[stones[ind] + k - 1], k - 1, mp, target, stones);
        }
        if (k && mp[stones[ind] + k]) {
            res |= f(mp[stones[ind] + k], k, mp, target, stones);
        }
        if (mp[stones[ind] + k + 1]) {
            res |= f(mp[stones[ind] + k + 1], k + 1, mp, target, stones);
        }
        return dp[ind][k] = res;
    }

    bool canCross(vector<int>& stones) {
        unordered_map<int, int> mp;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < stones.size(); i++) {
            mp[stones[i]] = i;
        }
        return f(0, 0, mp, stones.size() - 1, stones);
    }
};