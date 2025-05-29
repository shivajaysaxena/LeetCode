class Solution {
public:
    int numDecodings(const string& s) {
        int n = s.size(), dp = 0, dp1 = 1, dp2 = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != '0')
                dp += dp1;
            if (i + 1 < s.size() &&
                (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'))
                dp += dp2;
            dp2 = dp1;
            dp1 = dp;
            dp = 0;
        }
        return dp1;
    }
};