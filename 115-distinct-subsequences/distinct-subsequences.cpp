class Solution {
public:
    int numDistinct(string s, string t) {
        const int prime = 1e9 + 7;
        int lt = s.size();
        int ls = t.size();
        vector<int> prev(ls + 1, 0);
        prev[0] = 1;

        for (int i = 1; i <= lt; i++) {
            vector<int> curr(ls + 1, 0);
            curr[0] = 1;

            for (int j = 1; j <= ls; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = (prev[j - 1] + prev[j]) % prime;
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[ls];
    }
};
