class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> uniquelist;
        return backtrack(s, uniquelist, 0);
    }

private:
    int backtrack(const string& s, unordered_set<string>& uniquelist,
                  int start) {
        if (start == s.length())
            return 0;
        int maxSplits = 0;
        string temp = "";
        for (int i = start; i < s.length(); i++) {
            temp += s[i];
            if (uniquelist.find(temp) == uniquelist.end()) {
                uniquelist.insert(temp);
                int splits = 1 + backtrack(s, uniquelist, i + 1);
                maxSplits = max(maxSplits, splits);
                uniquelist.erase(temp);
            }
        }
        return maxSplits;
    }
};