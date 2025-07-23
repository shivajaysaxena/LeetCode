class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> tar;
        unordered_map<char, int> freq;
        for (auto i : target) {
            tar[i]++;
        }
        for (auto i : s) {
            freq[i]++;
        }

        int maxnum = INT_MAX;
        for (const auto& it : tar) {
            char c = it.first;
            int requried = it.second;
            maxnum = min(maxnum, freq[c] / requried);
        }
        return maxnum;
    }
};
