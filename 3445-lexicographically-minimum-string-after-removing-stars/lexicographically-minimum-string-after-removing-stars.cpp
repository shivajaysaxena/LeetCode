class Solution {
public:
    string clearStars(string s) {
        int n = s.length();
        vector<int> toDelete(n, 0);
        vector<vector<int>> mp(26);
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (!mp[c - 'a'].empty()) {
                        toDelete[mp[c - 'a'].back()] = 1;
                        mp[c - 'a'].pop_back();
                        break;
                    }
                }
            } else {
                mp[s[i] - 'a'].push_back(i);
            }
        }
        string res = "";
        for (int i = 0; i < n; i++) {
            if (!toDelete[i] && s[i] != '*')
                res += s[i];
        }
        return res;
    }
};