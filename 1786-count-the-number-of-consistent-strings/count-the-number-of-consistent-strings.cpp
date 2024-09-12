class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mp;
        for (char i : allowed)
            mp[i]++;
        int count = 0;
        for (string str : words) {
            for (char x : str) {
                if (mp.find(x) != mp.end())
                    continue;
                count++;
                break;
            }
        }
        return words.size() - count;
    }
};