class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.length() + 1, 0);
        for (int i = 1; i <= s.length(); i++) {
            dp[i] = 1 + dp[i - 1];
            for (auto w : dictionary)
                if (i >= w.length() &&
                    s.substr(i - w.length(), w.length()) == w)
                    dp[i] = min(dp[i], dp[i - w.length()]);
        }
        return dp[s.length()];
    }
};