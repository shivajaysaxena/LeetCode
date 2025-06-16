class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int mx = 0;
        unordered_map<int, int> mp;
        int n = fruits.size();
        for (int i = 0, j = 0; i < n; i++) {
            mp[fruits[i]]++;
            while (mp.size() > 2) {
                mp[fruits[j]]--;
                if (mp[fruits[j]] == 0) {
                    mp.erase(fruits[j]);
                }
                j++;
            }
            mx = max(mx, i - j + 1);
        }
        return mx;
    }
};