class Solution {
public:
    char findTheDifference(string s, string t) {
        int x = 0;
        for (auto i : s) {
            x = x ^ i;
        }
        for (auto i : t) {
            x = x ^ i;
        }
        return x;
    }
};