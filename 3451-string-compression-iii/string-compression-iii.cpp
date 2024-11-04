class Solution {
public:
    string compressedString(string s) {
        int n = s.size();
        int i = 0;
        string ans = "";
        while (i < n) {
            char match = s[i];
            int cnt = 0;
            while (i < n && s[i] == match && cnt < 9) {
                i++, cnt++;
            }
            ans += char('0' + cnt);
            ans += match;
        }
        return ans;
    }
};