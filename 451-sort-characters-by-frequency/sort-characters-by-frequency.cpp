class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for (char i : s)
            mp[i]++;
        vector<pair<char, int>> p;
        for (auto it : mp) {
            p.push_back({it.first, it.second});
        }
        sort(p.begin(), p.end(), cmp);
        string ans = "";
        for (auto it : p) {
            while (it.second > 0) {
                ans += it.first;
                it.second--;
            }
        }
        return ans;
    }
    static bool cmp(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }
};