class Solution {
public:
    string longestPrefix(string s) {
        vector<int> res(s.size(), 0);
        int pre = 0;
        int suff = 1;
        while (suff < s.size()) {
            if (s[pre] == s[suff]) {
                res[suff] = pre + 1;
                suff++;
                pre++;
            } else {
                if (pre > 0) {
                    pre = res[pre - 1];
                } else {
                    pre = 0;
                    suff++;
                }
            }
        }
        int n = res[res.size() - 1];
        return s.substr(0, n);
    }
};