class Solution {
public:
    int longestSubsequence(string s, int k) {
        double d = log2(k);
        int res = count(s.begin(), s.end(), '0');
        reverse(s.begin(), s.end());
        int l = ceil(d);
        long long val = 0;
        for (int i = 0; i <= min((int)s.length(), l); i++) {
            if (s[i] == '1') {
                val += pow(2, i);
                if (val <= k) {
                    res++;
                }
            }
        }
        return res;
    }
};