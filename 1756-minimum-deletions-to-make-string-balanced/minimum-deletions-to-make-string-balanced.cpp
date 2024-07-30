class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        int cnt_b = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'b') {
                cnt_b++;
            } else {
                ans = min(ans + 1, cnt_b);
            }
        }
        return ans;
    }
};