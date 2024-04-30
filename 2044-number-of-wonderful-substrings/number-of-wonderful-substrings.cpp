class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        unordered_map<int, int> mp;
        int bit = 0;
        mp[0] = 1;
        for (int i = 0; i < word.length(); i++) {
            bit = bit ^ (1 << (word[i] - 'a'));
            ans += mp[bit];
            for (int j = 0; j < 10; j++) {
                ans += mp[bit ^ (1 << j)];
            }
            mp[bit]++;
        }
        return ans;
    }
};