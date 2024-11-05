class Solution {
public:
    int minChanges(string s, int ret = 0) {
        for (int i = 0; i < s.size(); i++) {
            ret += s[i] != s[++i];
        }
        return ret;
    }
};