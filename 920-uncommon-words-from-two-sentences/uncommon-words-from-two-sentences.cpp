class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        string curr = "";
        for (auto& ch : s1) {
            if (ch == ' ') {
                mp[curr]++;
                curr = "";
                continue;
            }
            curr += ch;
        }
        mp[curr]++;
        curr = "";
        for (auto& ch : s2) {
            if (ch == ' ') {
                mp[curr]++;
                curr = "";
                continue;
            }
            curr += ch;
        }
        mp[curr]++;
        vector<string> ans;
        for (auto& ele : mp) {
            if (ele.second == 1)
                ans.push_back(ele.first);
        }
        return ans;
    }
};