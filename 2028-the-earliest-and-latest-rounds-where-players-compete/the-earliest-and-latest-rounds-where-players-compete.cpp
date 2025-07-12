class Solution {
    bool dp[7][28][28] = {};
    int mini = INT_MAX;
    int maxi = INT_MIN;
    void recursive(int round, int l, int r, int n) {
        if (dp[round][l][r])
            return;
        dp[round][l][r] = 1;

        if (l > r)
            return recursive(round, r, l, n);
        if (l == r) {
            mini = min(mini, round);
            maxi = max(maxi, round);
            return;
        }
        int half = (n + 1) / 2;
        int lefty = min(l, half);
        for (int i = 1; i <= lefty; i++) {
            for (int j = (l - i + 1); j <= (min(half, r) - i); j++) {
                if (l + r - (i + j) <= n / 2)
                    recursive(round + 1, i, j, half);
            }
        }
        return;
    }

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        recursive(1, firstPlayer, n - secondPlayer + 1, n);

        return {mini, maxi};
    }
};