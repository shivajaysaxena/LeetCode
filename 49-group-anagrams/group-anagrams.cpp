class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto& s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            hash[t].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& [k, v] : hash)
            result.push_back(v);
        return result;
    }
};