class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        map<int, int> mp;

        for (auto x : arr) {
            mp[x]++;
        }
        vector<int> v;
        for (auto x : mp) {
            v.push_back(x.second);
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] == v[i + 1])
                return false;
        }

        return true;
    }
};