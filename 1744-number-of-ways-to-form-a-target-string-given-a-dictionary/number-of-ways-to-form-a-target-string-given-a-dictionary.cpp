class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1000000007;
        int tlen = target.size();
        int wlen = words[0].size();
        if (tlen > wlen) return 0;

        vector<vector<int>> count(wlen, vector<int>(26, 0));
        for (const auto& w : words) {
            for (int i = 0; i < wlen; ++i) ++count[i][w[i] - 'a'];
        }

        vector<long> dp(wlen);
        int c = target[0] - 'a';
        dp[0] = count[0][c];
        for (int i = 1; i <= wlen - tlen; ++i) dp[i] = dp[i - 1] + count[i][c];

        long prev, temp;
        for (int i = 1; i < tlen; ++i) {
            int end = wlen - tlen + i;
            c = target[i] - 'a';
            prev = dp[i - 1];
            dp[i - 1] = 0;
            for (int j = i; j <= end; ++j) {
                temp = prev;
                prev = dp[j];
                dp[j] = (dp[j - 1] + temp * count[j][c]) % MOD;
            }
        }

        return static_cast<int>(dp[wlen - 1]);
    }
};