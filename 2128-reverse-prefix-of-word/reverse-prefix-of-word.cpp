class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = 0;
        string ans = "";
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == ch) {
                idx = i;
                break;
            }
        }
        int i = 0;
        while (i <= idx) {
            ans += word[i];
            i++;
        }
        reverse(ans.begin(), ans.end());
        while (i < word.length()) {
            ans += word[i];
            i++;
        }
        return ans;
    }
};